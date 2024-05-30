/**
 * @file server.cpp
 * @author Mikhail Dmitrievich Kozlov and Dmitry Sergeevich Pudovkin
 * @brief Server part
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "include/AdmUeReleaseRequest.h"
#include "include/DrbAdditionalInfo.h"
#include "include/InitialContextSetupAcknowledgement.h"
#include "include/InitialContextSetupResponse.h"
#include "include/PathSwitchRequest.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"

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

/**
 * @brief Initialize Winsocket and check if it was initialized
 * 
 */
void InitializeWinsock() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        throw std::runtime_error("WSAStartup failed: " + std::to_string(result));
    }
}

/**
 * @brief Create a Socket and check if it was created
 * 
 * @return SOCKET 
 */
SOCKET CreateSocket() {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET) {
        throw std::runtime_error("Socket creation failed: " + std::to_string(WSAGetLastError()));
    }
    return sock;
}

/**
 * @brief Bind client socket and check if operation finished successfully
 * 
 * @param sock Socket to bind
 * @param address Addres to bind
 * @param port Port to bind
 */
void BindSocket(SOCKET sock, const std::string& address, int port) {
    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, address.c_str(), &addr.sin_addr);
    addr.sin_port = htons(port);

    if (bind(sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == SOCKET_ERROR) {
        throw std::runtime_error("Socket bind failed: " + std::to_string(WSAGetLastError()));
    }
}

/**
 * @brief Create a Json object from "StructureInterface" message
 * 
 * @param message "StructureInterface" message
 * @param file_name File name to save Json string
 */
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

/**
 * @brief Read message fron deque, save it into file and check accepted message with originally created file
 * 
 */
void Worker() {
    try {
        int message_id = 0;
        while (true) {
            /**
             * @brief Whait until message deque is not empty
             * 
             */
            std::unique_lock<std::mutex> lock(deque_mtx);
            deque_cv.wait(lock, [] { return !message_deque.empty(); });
            std::unique_ptr<StructureInterface> mes = std::move(message_deque.front());
            message_deque.pop_front();
            lock.unlock();
            rapidjson::Document doc_accepted;
            mes->serialize(doc_accepted);

            rapidjson::StringBuffer buffer;
            rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
            doc_accepted.Accept(writer);

            std::string message = buffer.GetString();

            std::string file_name = "Accepted/" + std::to_string(message_id) + ".json";
            std::ofstream output(file_name);
            if (!output) {
                throw std::runtime_error("Can't open output file: " + file_name);
            }
            output << message;
            output.close();
            {
                std::lock_guard<std::mutex> lock(cout_mtx);
                std::cout << "Accepted message: " << message << "\n\n";
            }

            /**
             * @brief Specifies the type of message
             * 
             */
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
                std::cerr << "Unknown structure name: " << message << std::endl;
                message_id++;
                continue;
            }
            std::ifstream original("Files_for_check/" + std::to_string(message_id) + ".json", std::ios::binary);
            if (!original) {
                throw std::runtime_error("Can't open input file: Files_for_check/" + std::to_string(message_id) + ".json");
            }
            std::ifstream final(file_name);
            if (!final) {
                throw std::runtime_error("Can't open input file: Accepted/" + std::to_string(message_id) + ".json");
            }

            /**
             * @brief Check file equality
             * 
             */
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
    catch (const std::exception& e) {
        std::cerr << "Error in Worker: " << e.what() << std::endl;
    }
}

/**
 * @brief Recieve messages from clients, deserealize messages and put them into deque
 * 
 * @param address Server address for binding client socket
 * @param port Server port for binding client socket
 */
void RecieveMessages(const std::string& address, int port) {
    try {
        SOCKET sock = CreateSocket();
        BindSocket(sock, address, port);
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
                /**
                 * @brief Read message until end
                 * 
                 */
                while ((pos = message.find('\n')) != std::string::npos) {
                    std::string complete_message = message.substr(0, pos);
                    message.erase(0, pos + 1);
                    rapidjson::Document doc_accepted;
                    doc_accepted.Parse(complete_message.c_str());
                    std::unique_ptr<StructureInterface> mes;
                    /**
                     * @brief Specifies the type of message
                     * 
                     */
                    if (doc_accepted.HasMember("drb_additional_info")) {
                        mes = std::make_unique<DrbAdditionalInfo_Handler>();
                    }
                    else if (doc_accepted.HasMember("path_switch_request")) {
                        mes = std::make_unique<PathSwitchRequest_Handler>();
                    }
                    else if (doc_accepted.HasMember("InitialContextSetupAcknowledgement")) {
                        mes = std::make_unique<InitialContextSetupAcknowledgement_Handler>();
                    }
                    else if (doc_accepted.HasMember("AdmUeReleaseRequest")) {
                        mes = std::make_unique<AdmUeReleaseRequest_Handler>();
                    }
                    else if (doc_accepted.HasMember("initial_context_setup_response")) {
                        mes = std::make_unique<InitialContextSetupResponse_Handler>();
                    }
                    else {
                        std::cerr << "Unknown structure name: " << complete_message << std::endl;
                        message_id++;
                        continue;
                    }
                    mes->deserialize(doc_accepted);
                    std::lock_guard<std::mutex> lock(deque_mtx);
                    message_deque.push_back(std::move(mes));
                    deque_cv.notify_one();

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

/**
 * @brief main programm entery
 * 
 * @return int 
 */
int main() {
    try {
        _mkdir("Files_for_check");
        _mkdir("Accepted");

        InitializeWinsock();
        
        std::thread client1(RecieveMessages, "127.0.0.1", 8081);
        std::thread client2(RecieveMessages, "127.0.0.1", 8082);
        std::thread worker(Worker);
        client1.join();
        client2.join();
        worker.join();
        WSACleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error in main: " << e.what() << std::endl;
    }
}