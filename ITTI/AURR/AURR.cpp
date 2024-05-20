// Pudovkin Dmitriy
#include <iostream>
#include <memory>
#include <cstring>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>
#include "AdmUeReleaseRequest.h"

using namespace rapidjson;

struct AdmUeReleaseRequest_Deleter {
    void operator()(AdmUeReleaseRequest_t* p) const {
        delete[] p->redirectedCarrierInfo.buf;
        delete[] p->idleModeMobilityControlInfo.buf;
        delete p;
    }
};

struct AURR {
    explicit AURR(AdmUeReleaseRequest_t& inMessage) : message(inMessage) {}

    void serialize(Document& config) {
        auto& allocator = config.GetAllocator();
        config.SetObject();

        config.AddMember("rrccause", Value().SetUint64(message.rrccause), allocator);
        config.AddMember("rrc_cause_value_t", Value().SetInt64(message.rrc_cause_value_t), allocator);

        config.AddMember("redirectedCarrierInfo",
            message.redirectedCarrierInfo.size ? Value(reinterpret_cast<const char*>(message.redirectedCarrierInfo.buf), static_cast<rapidjson::SizeType>(message.redirectedCarrierInfo.size), allocator) : Value("", allocator),
            allocator);

        config.AddMember("idleModeMobilityControlInfo",
            message.idleModeMobilityControlInfo.size ? Value(reinterpret_cast<const char*>(message.idleModeMobilityControlInfo.buf), static_cast<rapidjson::SizeType>(message.idleModeMobilityControlInfo.size), allocator) : Value("", allocator),
            allocator);

        Value _asn_ctx(kObjectType);
        _asn_ctx.AddMember("phase", Value().SetUint(message._asn_ctx.phase), allocator);
        _asn_ctx.AddMember("step", Value().SetUint(message._asn_ctx.step), allocator);
        _asn_ctx.AddMember("context", Value().SetUint(message._asn_ctx.context), allocator);
        _asn_ctx.AddMember("left", Value().SetUint(message._asn_ctx.left), allocator);
        config.AddMember("_asn_ctx", _asn_ctx, allocator);
    }

    void deserialize(const Document& config) {
        if (config.HasMember("rrccause") && config["rrccause"].IsUint64()) {
            message.rrccause = config["rrccause"].GetUint64();
        }
        else {
            std::cerr << "Error: Missing or invalid 'rrccause'." << std::endl;
        }

        if (config.HasMember("rrc_cause_value_t") && config["rrc_cause_value_t"].IsInt64()) {
            message.rrc_cause_value_t = config["rrc_cause_value_t"].GetInt64();
        }
        else {
            std::cerr << "Error: Missing or invalid 'rrc_cause_value_t'." << std::endl;
        }

        if (config.HasMember("redirectedCarrierInfo") && config["redirectedCarrierInfo"].IsString()) {
            const std::string& redirectedCarrierInfoStr = config["redirectedCarrierInfo"].GetString();
            setBuffer(message.redirectedCarrierInfo, redirectedCarrierInfoStr);
        }
        else {
            std::cerr << "Error: Missing or invalid 'redirectedCarrierInfo'." << std::endl;
        }

        if (config.HasMember("idleModeMobilityControlInfo") && config["idleModeMobilityControlInfo"].IsString()) {
            const std::string& idleModeMobilityControlInfoStr = config["idleModeMobilityControlInfo"].GetString();
            setBuffer(message.idleModeMobilityControlInfo, idleModeMobilityControlInfoStr);
        }
        else {
            std::cerr << "Error: Missing or invalid 'idleModeMobilityControlInfo'." << std::endl;
        }

        if (config.HasMember("_asn_ctx") && config["_asn_ctx"].IsObject()) {
            const Value& asnCtxObj = config["_asn_ctx"];
            message._asn_ctx.phase = asnCtxObj["phase"].GetUint();
            message._asn_ctx.step = asnCtxObj["step"].GetUint();
            message._asn_ctx.context = asnCtxObj["context"].GetUint();
            message._asn_ctx.left = asnCtxObj["left"].GetUint();
        }
        else {
            std::cerr << "Error: Missing or invalid '_asn_ctx'." << std::endl;
        }
    }

    void setBuffer(OCTET_STRING_t& buffer, const std::string& data) {
        delete[] buffer.buf;
        buffer.size = data.size();
        buffer.buf = new uint8_t[buffer.size];
        memcpy(buffer.buf, data.data(), buffer.size);
    }

private:
    AdmUeReleaseRequest_t& message;
};

int main() {
    std::unique_ptr<AdmUeReleaseRequest_t, AdmUeReleaseRequest_Deleter> request1(new AdmUeReleaseRequest_t);
    request1->rrccause = 123;
    request1->rrc_cause_value_t = 456;

    const char* redirectedCarrierInfoData = "123456";
    const char* idleModeMobilityControlInfoData = "789012";

    AURR aurr1(*request1);
    aurr1.setBuffer(request1->redirectedCarrierInfo, redirectedCarrierInfoData);
    aurr1.setBuffer(request1->idleModeMobilityControlInfo, idleModeMobilityControlInfoData);

    request1->_asn_ctx.phase = 1;
    request1->_asn_ctx.step = 2;
    request1->_asn_ctx.context = 3;
    request1->_asn_ctx.left = 4;

    Document doc1;
    aurr1.serialize(doc1);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc1.Accept(writer);

    std::cout << "Serialized AdmUeReleaseRequest:\n" << buffer.GetString() << std::endl;

    AdmUeReleaseRequest_t request2 = {};
    AURR aurr2(request2);

    const char* json = R"({
        "rrccause": 123,
        "rrc_cause_value_t": 456,
        "redirectedCarrierInfo": "123456",
        "idleModeMobilityControlInfo": "789012",
        "_asn_ctx": {
            "phase": 1,
            "step": 2,
            "context": 3,
            "left": 4
        }
    })";

    Document doc2;
    doc2.Parse(json);
    if (doc2.HasParseError()) {
        std::cerr << "Error parsing JSON: " << GetParseError_En(doc2.GetParseError()) << " at offset " << doc2.GetErrorOffset() << std::endl;
        return 1;
    }

    aurr2.deserialize(doc2);

    bool isValid = true;

    if (request2.rrccause != 123) {
        std::cerr << "Error: rrccause mismatch. Expected 123, got " << request2.rrccause << std::endl;
        isValid = false;
    }

    if (request2.rrc_cause_value_t != 456) {
        std::cerr << "Error: rrc_cause_value_t mismatch. Expected 456, got " << request2.rrc_cause_value_t << std::endl;
        isValid = false;
    }

    if (request2.redirectedCarrierInfo.size != strlen(redirectedCarrierInfoData) ||
        memcmp(request2.redirectedCarrierInfo.buf, redirectedCarrierInfoData, request2.redirectedCarrierInfo.size) != 0) {
        std::cerr << "Error: redirectedCarrierInfo mismatch. Expected " << redirectedCarrierInfoData << ", got "
            << std::string(reinterpret_cast<char*>(request2.redirectedCarrierInfo.buf), request2.redirectedCarrierInfo.size) << std::endl;
        isValid = false;
    }

    if (request2.idleModeMobilityControlInfo.size != strlen(idleModeMobilityControlInfoData) ||
        memcmp(request2.idleModeMobilityControlInfo.buf, idleModeMobilityControlInfoData, request2.idleModeMobilityControlInfo.size) != 0) {
        std::cerr << "Error: idleModeMobilityControlInfo mismatch. Expected " << idleModeMobilityControlInfoData << ", got "
            << std::string(reinterpret_cast<char*>(request2.idleModeMobilityControlInfo.buf), request2.idleModeMobilityControlInfo.size) << std::endl;
        isValid = false;
    }

    if (request2._asn_ctx.phase != 1 || request2._asn_ctx.step != 2 ||
        request2._asn_ctx.context != 3 || request2._asn_ctx.left != 4) {
        std::cerr << "Error: _asn_ctx mismatch. Expected {1, 2, 3, 4}, got {"
            << request2._asn_ctx.phase << ", " << request2._asn_ctx.step << ", "
            << request2._asn_ctx.context << ", " << request2._asn_ctx.left << "}" << std::endl;
        isValid = false;
    }

    if (isValid) {
        std::cout << "Deserialization successful!" << std::endl;
    }
    else {
        std::cerr << "Deserialization failed!" << std::endl;
    }

    delete[] request2.redirectedCarrierInfo.buf;
    delete[] request2.idleModeMobilityControlInfo.buf;

    return 0;
}
