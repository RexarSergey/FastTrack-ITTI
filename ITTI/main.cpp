// The file was executed by Mikhail Kozlov

#include "AURR.h"
#include "DAI.h"
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

std::mutex deque_mtx;
std::condition_variable deque_cv;

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
    for (int id = 0; id < documents.size(); ++id) {
        std::unique_ptr<StructureInterface> mes;
        if (documents[id].HasMember("drb_additional_info")) {
            mes = std::make_unique<DAI>();
        }
        else if (documents[id].HasMember("path_switch_request")) {
            mes = std::make_unique<PSR>();
        }
        else if (documents[id].HasMember("InitialContextSetupAcknowledgement")) {
            mes = std::make_unique<ICSA>();
        }
        else if (documents[id].HasMember("AdmUeReleaseRequest")) {
            mes = std::make_unique<AURR>();
        }
        else {
            throw std::invalid_argument("Unknown structure name");
        }
        mes->deserialize(documents[id]);
        mes->SetId(id);
        std::lock_guard<std::mutex> lock(deque_mtx);
        message_deque.push_back(std::move(mes));
        deque_cv.notify_one();
    }
}

void Worker() {
    while (true) {
        std::unique_lock<std::mutex> lock(deque_mtx);
        deque_cv.wait(lock, [] { return !message_deque.empty(); });

        std::unique_ptr<StructureInterface> mes = std::move(message_deque.front());
        message_deque.pop_front();
        const std::string id = std::to_string(mes->GetId());
        lock.unlock();

        CreateJson(std::move(mes), id + "_final.json");

        std::ifstream original(id + "_original.json", std::ios::binary);
        if (!original) {
            throw std::runtime_error("Can't open input file: " + id + "_original.json");
        }
        std::ifstream final(id + "_final.json", std::ios::binary);
        if (!final) {
            throw std::runtime_error("Can't open input file: " + id + "_final.json");
        }

        if (std::equal(std::istreambuf_iterator<char>(original.rdbuf()),
            std::istreambuf_iterator<char>(),
            std::istreambuf_iterator<char>(final.rdbuf()))) {
            std::cout << "Pas\n";
        }
        else {
            std::cout << "Fail\n";
        }
    }
}

int main(){
    int structures_count = 0;
    CreateJson(GetFilledDai(), std::to_string(structures_count++) + "_original.json");
    CreateJson(GetFilledPsr(), std::to_string(structures_count++) + "_original.json");
    CreateJson(GetFilledICSA(), std::to_string(structures_count++) + "_original.json");
    CreateJson(GetFilledAurr(), std::to_string(structures_count++) + "_original.json");

    std::vector<rapidjson::Document> documents;
    documents.reserve(structures_count);
    for (int id = 0; id < structures_count; ++id) {
        documents.push_back(ReadJson(std::to_string(id) + "_original.json"));
    }
    std::thread send_messages(AddToMessageDeque, std::ref(documents));
    std::thread worker(Worker);

    send_messages.join();
    worker.join();
}
