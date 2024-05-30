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

void InitializeWinsock() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        throw std::runtime_error("WSAStartup failed: " + std::to_string(result));
    }
}
SOCKET CreateSocket() {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        throw std::runtime_error("Socket creation failed: " + std::to_string(WSAGetLastError()));
    }
    return sock;
}

void BindSocket(SOCKET sock, const std::string& address, int port) {
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &addr.sin_addr);
    addr.sin_port = htons(port);

    if (bind(sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == SOCKET_ERROR) {
        throw std::runtime_error("Socket bind failed: " + std::to_string(WSAGetLastError()));
    }
}

void ListenSocket(SOCKET sock, int backlog) {
    if (listen(sock, backlog) == SOCKET_ERROR) {
        throw std::runtime_error("Socket listen failed: " + std::to_string(WSAGetLastError()));
    }
}

SOCKET AcceptConnection(SOCKET sock) {
    SOCKET client = accept(sock, nullptr, nullptr);
    std::cout << "Connection accepted\n";
    if (client == INVALID_SOCKET) {
        throw std::runtime_error("Socket accept failed: " + std::to_string(WSAGetLastError()));
    }
    return client;
}

std::string ReceiveMessage(SOCKET sock) {
    const int bufSize = 4096;
    char buf[bufSize];
    std::string message;

    int bytesReceived = 0;
    do {
        bytesReceived = recv(sock, buf, bufSize, 0);
        if (bytesReceived > 0) {
            message.append(buf, bytesReceived);
        }
        else if (bytesReceived == 0) {
            break;
        }
        else {
            throw std::runtime_error("Receive failed: " + std::to_string(WSAGetLastError()));
        }
    } while (bytesReceived > 0);

    return message;
}

void SendMessage(SOCKET sock, const std::string& message) {
    int sent = send(sock, message.c_str(), static_cast<int>(message.length()), 0);
    if (sent == SOCKET_ERROR) {
        throw std::runtime_error("Send failed: " + std::to_string(WSAGetLastError()));
    }
}

void HandleClient(SOCKET client) {
    try {
        std::string receivedMessage = ReceiveMessage(client);

        rapidjson::Document doc;
        doc.Parse(receivedMessage.c_str());

        std::unique_ptr<StructureInterface> mes;
        if (doc.HasMember("drb_additional_info")) {
            mes = std::make_unique<DrbAdditionalInfo_Handler>();
        }
        else if (doc.HasMember("path_switch_request")) {
            mes = std::make_unique<PathSwitchRequest_Handler>();
        }
        else if (doc.HasMember("InitialContextSetupAcknowledgement")) {
            mes = std::make_unique<InitialContextSetupAcknowledgement_Handler>();
        }
        else if (doc.HasMember("AdmUeReleaseRequest")) {
            mes = std::make_unique<AdmUeReleaseRequest_Handler>();
        }
        else {
            std::cerr << "Unknown structure name: " << receivedMessage << std::endl;
        }
        if (mes) {
            mes->deserialize(doc);

            rapidjson::Document responseDoc;
            mes->serialize(responseDoc);
            rapidjson::StringBuffer buf;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
            responseDoc.Accept(writer);
            std::string responseMessage = buf.GetString();

            SendMessage(client, responseMessage);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    closesocket(client);
}

void CreateJson(std::unique_ptr<StructureInterface> message, std::string file_name) {
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

void Worker(const std::string& address, int port) {
    try {
        SOCKET sock = CreateSocket();
        BindSocket(sock, "127.0.0.1", port);
        listen(sock, 5);

        while (true) {
            SOCKET client_sock = accept(sock, nullptr, nullptr);
            if (client_sock == INVALID_SOCKET) {
                throw std::runtime_error("Socket accept failed: " + std::to_string(WSAGetLastError()));
            }

            char buffer[1024];
            std::string message;
            int message_id = 0;

            while (true) {
                int bytes_read = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
                if (bytes_read == SOCKET_ERROR) {
                    throw std::runtime_error("Socket read failed: " + std::to_string(WSAGetLastError()));
                }

                if (bytes_read == 0) {
                    break;
                }

                buffer[bytes_read] = '\0';
                message.append(buffer, bytes_read);

                size_t pos;
                while ((pos = message.find('\n')) != std::string::npos) {
                    std::string complete_message = message.substr(0, pos);
                    message.erase(0, pos + 1);

                    std::string file_name = "Accepted/" + std::to_string(message_id) + ".json";
                    std::ofstream output(file_name);
                    if (!output) {
                        throw std::runtime_error("Can't open output file: " + file_name);
                    }
                    output << complete_message;
                    output.close();
                    {
                        std::lock_guard<std::mutex> lock(cout_mtx);
                        std::cout << "Accepted message: " << complete_message << "\n\n";
                    }

                    rapidjson::Document doc_accepted;
                    doc_accepted.Parse(complete_message.c_str());
                    if (doc_accepted.HasMember("drb_additional_info")) {
                        CreateJson(GetFilledDrbAdditionalInfo_Handler(), "Files_for_check/" + std::to_string(message_id) + ".json");
                    }
                    else if (doc_accepted.HasMember("path_switch_request")) {
                        CreateJson(GetFilledPathSwitchRequest_Handler(), "Files_for_check/" + std::to_string(message_id) + ".json");
                    }
                    else if (doc_accepted.HasMember("InitialContextSetupAcknowledgement")) {
                        CreateJson(GetFilledInitialContextSetupAcknowledgement(), "Files_for_check/" + std::to_string(message_id) + ".json");
                    }
                    else if (doc_accepted.HasMember("AdmUeReleaseRequest")) {
                        CreateJson(GetFilledAdmUeReleaseRequest_Handler(), "Files_for_check/" + std::to_string(message_id) + ".json");
                    }
                    else if (doc_accepted.HasMember("initial_context_setup_response")) {
                        CreateJson(GetFilledInitialContextSetupResponse(), "Files_for_check/" + std::to_string(message_id) + ".json");
                    }
                    else {
                        throw std::invalid_argument("Unknown structure name");
                    }
                    std::ifstream original("Files_for_check/" + std::to_string(message_id) + ".json", std::ios::binary);
                    if (!original) {
                        throw std::runtime_error("Can't open input file: Files_for_check/" + std::to_string(message_id) + ".json");
                    }
                    std::ifstream final(file_name);
                    if (!final) {
                        throw std::runtime_error("Can't open input file: Accepted/" + std::to_string(message_id) + ".json");
                    }

                    if (std::equal(std::istreambuf_iterator<char>(original.rdbuf()),
                        std::istreambuf_iterator<char>(),
                        std::istreambuf_iterator<char>(final.rdbuf()))) {
                        {
                            std::lock_guard<std::mutex> lock(cout_mtx);
                            std::cout << "Pass message id: " << message_id << "\n\n";
                        }
                    }
                    else {
                        std::lock_guard<std::mutex> lock(cout_mtx);
                        std::cout << "Fail message id: " << message_id << "\n\n";
                    }

                    message_id++;
                }
            }

            closesocket(client_sock);
        }

        closesocket(sock);
    }
    catch (const std::exception& e) {
        std::cerr << "Error in Worker: " << e.what() << std::endl;
    }
}

int main() {
    try {
        _mkdir("Files_for_check");
        _mkdir("Accepted");

        InitializeWinsock();
        std::thread worker(Worker, "127.0.0.1", 8081);

        worker.join();
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error in main: " << e.what() << std::endl;
    }
}