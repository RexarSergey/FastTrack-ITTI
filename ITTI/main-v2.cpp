#include "AURR.h"
#include "include/DrbAdditionalInfo_Handler.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"
#include "PSR.h"
#include "ICSA/ICSA.h"

#include <deque>
#include <fstream>
#include <iostream>
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

void ConnectSocket(SOCKET sock, const std::string& address, int port) {
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &addr.sin_addr);
    addr.sin_port = htons(port);

    if (connect(sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == SOCKET_ERROR) {
        throw std::runtime_error("Socket connect failed: " + std::to_string(WSAGetLastError()));
    }
}

void CreateJson(std::unique_ptr<StructureInterface> message, const std::string& file_name) {
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
    rapidjson::Document doc;
    doc.Parse(buffer.str().c_str());
    return doc;
}

void AddToMessageDeque(const std::vector<rapidjson::Document>& documents, const std::string& address, int port) {
    try {
        SOCKET sock = CreateSocket();
        ConnectSocket(sock, address, port);

        for (const auto& doc : documents) {
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

void Worker(int port) {
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

                    {
                        std::lock_guard<std::mutex> lock(cout_mtx);
                        std::cout << "Accepted message: " << complete_message << "\n\n";
                    }

                    rapidjson::Document doc_received = ReadJson("Received/" + std::to_string(message_id) + ".json");
                    rapidjson::Document doc_accepted;
                    doc_accepted.Parse(complete_message.c_str());

                    {
                        std::lock_guard<std::mutex> lock(cout_mtx);
                        if (doc_received == doc_accepted) {
                            std::cout << "Pass message id: " << message_id << "\n\n";
                        }
                        else {
                            std::cout << "Fail message id: " << message_id << "\n\n";
                        }
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
        _mkdir("Received");
        _mkdir("Accepted");

        InitializeWinsock();

        int structures_count = 0;
        CreateJson(GetFilledDrbAdditionalInfo_Handler(), "Received/" + std::to_string(structures_count++) + ".json");
        CreateJson(GetFilledPsr(), "Received/" + std::to_string(structures_count++) + ".json");
        CreateJson(GetFilledICSA(), "Received/" + std::to_string(structures_count++) + ".json");
        CreateJson(GetFilledAurr(), "Received/" + std::to_string(structures_count++) + ".json");

        std::vector<rapidjson::Document> documents;
        documents.reserve(structures_count);
        for (int id = 0; id < structures_count; ++id) {
            documents.push_back(ReadJson("Received/" + std::to_string(id) + ".json"));
        }

        std::thread send_messages(AddToMessageDeque, std::ref(documents), "127.0.0.1", 8080);
        std::thread worker(Worker, 8080);

        send_messages.join();
        worker.join();

        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error in main: " << e.what() << std::endl;
    }
}