// The file was executed by Mikhail Kozlov

#include "DAI.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/writer.h"

#include <deque>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

std::deque<std::unique_ptr<StructureInterface>> message_deque;

void CreateJson(std::unique_ptr<StructureInterface> message, std::string file_name){
    rapidjson::Document doc;
    message->serialize(doc);
    rapidjson::StringBuffer buf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
    doc.Accept(writer);
    std::ofstream output(file_name);
    output << buf.GetString();
}

rapidjson::Document ReadJson(const std::string& file_name) {
    std::ifstream file(file_name);
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();
    rapidjson::Document doc;
    doc.Parse(content.c_str());
    return doc;
}

void AddToMessageDeque(const rapidjson::Document& doc) {
    if (doc.HasMember("drb_additional_info")) {
        using namespace vran::cplane::common;
        vran::rrc_du::DrbAdditionalInfo message;
        std::unique_ptr<DAI> mes = std::make_unique<DAI>(message);
        mes->deserialize(doc);
        message_deque.push_back(std::move(mes));
    }
}

void Worker() {
    if (!message_deque.empty()) {
        std::unique_ptr<StructureInterface> mes = std::move(message_deque.front());
        message_deque.pop_front();
        CreateJson(std::move(mes), "final.json");

        std::ifstream stream1("original.json", std::ios::binary);
        std::ifstream stream2("final.json", std::ios::binary);

        if (std::equal(std::istreambuf_iterator<char>(stream1.rdbuf()),
                        std::istreambuf_iterator<char>(),
                        std::istreambuf_iterator<char>(stream2.rdbuf()))) {
            std::cout << "Pas\n";
        }
        else {
            std::cout << "Fail\n";
        }
    }
}

int main(){
    CreateJson(GetFilledDai(), "original.json");
    rapidjson::Document doc = ReadJson("original.json");
    AddToMessageDeque(doc);
    Worker();
}