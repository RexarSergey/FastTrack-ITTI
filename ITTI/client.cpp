// The file was executed by Mikhail Kozlov

#include "include/AdmUeReleaseRequest.h"
#include "include/DrbAdditionalInfo.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include "include/PathSwitchRequest.h"
#include "include/InitialContextSetupAcknowledgement.h"
#include "include/InitialContextSetupResponse.h"

#include <deque>
#include <fstream>
#include <iostream>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <direct.h>
#include <chrono>

#pragma comment(lib, "Ws2_32.lib")

std::mutex deque_mtx;
std::condition_variable deque_cv;
std::mutex cout_mtx;
std::deque<std::unique_ptr<StructureInterface>> message_deque;

void CreateJson(std::unique_ptr<StructureInterface> message, std::string file_name){
    if (!message) {
        throw std::invalid_argument("Nullptr was passed");
    }
    rapidjson::Document doc;
    message->serialize(doc);
    rapidjson::StringBuffer buf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
    doc.Accept(writer);
    std::ofstream output(file_name);
    if (!output) {
        throw std::runtime_error("Can't open output file: " + file_name);
    }
    output << buf.GetString();
}

rapidjson::Document ReadJson(const std::string& file_name) {
    std::ifstream file(file_name);
    if (!file) {
        throw std::runtime_error("Can't open input file: " + file_name);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    rapidjson::Document doc;
    doc.Parse(content.c_str());
    return doc;
}

void AddToMessageDeque(const std::vector<rapidjson::Document>& documents) {
    using namespace vran::cplane::common;
    for (const auto& document: documents) {
        std::unique_ptr<StructureInterface> mes;
        if (document.HasMember("drb_additional_info")) {
            mes = std::make_unique<DrbAdditionalInfo_Handler>();
        }
        else if (document.HasMember("path_switch_request")) {
            mes = std::make_unique<PathSwitchRequest_Handler>();
        }
        else if (document.HasMember("InitialContextSetupAcknowledgement")) {
            mes = std::make_unique<InitialContextSetupAcknowledgement_Handler>();
        }
        else if (document.HasMember("AdmUeReleaseRequest")) {
            mes = std::make_unique<AdmUeReleaseRequest_Handler>();
        }
        else if (document.HasMember("initial_context_setup_response")) {
            mes = std::make_unique<InitialContextSetupResponse_Handler>();
        }
        else {
            throw std::invalid_argument("Unknown structure name");
        }
        mes->deserialize(document);
        std::lock_guard<std::mutex> lock(deque_mtx);
        message_deque.push_back(std::move(mes));
        deque_cv.notify_one();
    }
}

SOCKET CreateSocket() {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        throw std::runtime_error("Socket creation failed: " + std::to_string(WSAGetLastError()));
    }
    return sock;
}

void ConnectSocket(SOCKET sock, const std::string& address, int port) {
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &addr.sin_addr);
    addr.sin_port = htons(port);

    if (connect(sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == SOCKET_ERROR) {
        throw std::runtime_error("Socket connect failed: " + std::to_string(WSAGetLastError()));
    }
}

void Worker(const std::string& address, int port) {
    try {
        SOCKET sock = CreateSocket();
        ConnectSocket(sock, address, port);

        while (true) {
            std::unique_lock<std::mutex> lock(deque_mtx);
            deque_cv.wait(lock, [] { return !message_deque.empty(); });
            std::unique_ptr<StructureInterface> mes = std::move(message_deque.front());
            message_deque.pop_front();
            lock.unlock();
            rapidjson::Document doc;
            mes->serialize(doc);

            rapidjson::StringBuffer buffer;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
            doc.Accept(writer);

            std::string message = buffer.GetString();
            {
                std::lock_guard<std::mutex> lock(cout_mtx);
                std::cout << "Received message: " << message << "\n\n";
            }
            send(sock, message.c_str(), static_cast<int>(message.size()), 0);
            send(sock, "\n", 1, 0);
        }

        closesocket(sock);
    }
    catch (const std::exception& e) {
        std::cerr << "Error in AddToMessageDeque: " << e.what() << std::endl;
    }
}

void InitializeWinsock() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        throw std::runtime_error("WSAStartup failed: " + std::to_string(result));
    }
}

int main(){
    try {
        _mkdir("Received");
        _mkdir("Accepted");

        InitializeWinsock();
        int structures_count = 0;
        int count_threads = 3;
        for (int i = 0; i < count_threads; ++i) {
            CreateJson(GetFilledDrbAdditionalInfo_Handler(), "Received/" + std::to_string(structures_count++) + ".json");
            CreateJson(GetFilledPathSwitchRequest_Handler(), "Received/" + std::to_string(structures_count++) + ".json");
            CreateJson(GetFilledInitialContextSetupAcknowledgement(), "Received/" + std::to_string(structures_count++) + ".json");
            CreateJson(GetFilledAdmUeReleaseRequest_Handler(), "Received/" + std::to_string(structures_count++) + ".json");
            CreateJson(GetFilledInitialContextSetupResponse(), "Received/" + std::to_string(structures_count++) + ".json");
        }


        std::vector<std::vector<rapidjson::Document>> documents_packets(count_threads);
        int count_documents_in_packet = structures_count / count_threads;
        for (int id = 0; id < count_documents_in_packet; ++id) {
            for (int i = 0; i < count_threads; ++i) {
                documents_packets[i].push_back(ReadJson("Received/" + std::to_string(id) + ".json"));
            }
        }

        std::vector<std::thread> threads;
        threads.reserve(count_threads);
        for (int i = 0; i < count_threads; ++i) {
            threads.emplace_back(AddToMessageDeque, std::ref(documents_packets[i]));
        }
        std::thread worker(Worker, "127.0.0.1", 8081);
        worker.join();
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error in main: " << e.what() << std::endl;
    }
}
