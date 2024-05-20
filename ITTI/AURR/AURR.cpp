// Pudovkin Dmitriy
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "AdmUeReleaseRequest.h"
#include <cstring>

using namespace rapidjson;

struct AURR {
    explicit AURR(const AdmUeReleaseRequest_t& inMessage) : message(inMessage) {}

    void serialize(Document& config) {
        auto& allocator = config.GetAllocator();
        config.SetObject();

        config.AddMember("rrccause", static_cast<uint64_t>(message.rrccause), allocator);
        config.AddMember("rrc_cause_value_t", static_cast<int64_t>(message.rrc_cause_value_t), allocator);

        config.AddMember("redirectedCarrierInfo", Value(reinterpret_cast<const char*>(message.redirectedCarrierInfo.buf), message.redirectedCarrierInfo.size, allocator), allocator);
        config.AddMember("idleModeMobilityControlInfo", Value(reinterpret_cast<const char*>(message.idleModeMobilityControlInfo.buf), message.idleModeMobilityControlInfo.size, allocator), allocator);

        Value _asn_ctx(kObjectType);
        _asn_ctx.AddMember("phase", message._asn_ctx.phase, allocator);
        _asn_ctx.AddMember("step", message._asn_ctx.step, allocator);
        _asn_ctx.AddMember("context", message._asn_ctx.context, allocator);
        _asn_ctx.AddMember("left", message._asn_ctx.left, allocator);
        config.AddMember("_asn_ctx", _asn_ctx, allocator);
    }

private:
    const AdmUeReleaseRequest_t& message;
};

int main() {
    AdmUeReleaseRequest_t request;
    request.rrccause = 123;
    request.rrc_cause_value_t = 456;

    const char* redirectedCarrierInfoData = "123 456";
    request.redirectedCarrierInfo.size = strlen(redirectedCarrierInfoData);
    request.redirectedCarrierInfo.buf = new uint8_t[request.redirectedCarrierInfo.size];
    memcpy(request.redirectedCarrierInfo.buf, redirectedCarrierInfoData, request.redirectedCarrierInfo.size);

    const char* idleModeMobilityControlInfoData = "789 012";
    request.idleModeMobilityControlInfo.size = strlen(idleModeMobilityControlInfoData);
    request.idleModeMobilityControlInfo.buf = new uint8_t[request.idleModeMobilityControlInfo.size];
    memcpy(request.idleModeMobilityControlInfo.buf, idleModeMobilityControlInfoData, request.idleModeMobilityControlInfo.size);

    request._asn_ctx.phase = 1;
    request._asn_ctx.step = 2;
    request._asn_ctx.context = 3;
    request._asn_ctx.left = 4;

    AURR aurr(request);

    Document doc;
    aurr.serialize(doc);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    doc.Accept(writer);

    std::cout << "Serialized AdmUeReleaseRequest:\n" << buffer.GetString() << std::endl;

    delete[] request.redirectedCarrierInfo.buf;
    delete[] request.idleModeMobilityControlInfo.buf;

    return 0;
}
