//Prusakov Aleksey

#include "../include/InitialContextSetupResponse.h"
#include <iostream>
#include <document.h>
#include <writer.h>
#include <stringbuffer.h>
#include <string>

InitialContextSetupResponse_Handler::InitialContextSetupResponse_Handler(const vran::s1ap::lte::InitialContextSetupResponse& message)
    :message_(message)
{}

void InitialContextSetupResponse_Handler::SerializeERadioAccessBearerParameter(const vran::s1ap::lte::ERadioAccessBearerParameter& erabp, rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const{
    rapidjson::Value obj(rapidjson::kObjectType);
    rapidjson::Value addr(rapidjson::kObjectType);

    addr.AddMember("length", erabp.address.length, allocator);

    rapidjson::Value buf(rapidjson::kArrayType);
    for (int i = 0; i < erabp.address.length; ++i) {
        buf.PushBack(erabp.address.buffer[i], allocator);
    }
    addr.AddMember("buffer", buf, allocator);

    obj.AddMember("address", addr, allocator);
    obj.AddMember("teid", erabp.teid, allocator);

    value = obj;
}

void InitialContextSetupResponse_Handler::SerializeERadioAccessBearerCause(const vran::s1ap::lte::ERadioAccessBearerCause& erabc, rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const{
    rapidjson::Value obj(rapidjson::kObjectType);
    obj.AddMember("e_rab_id", erabc.e_rab_id, allocator);
    obj.AddMember("cause", static_cast<int>(erabc.cause), allocator);
    obj.AddMember("cause_value", erabc.cause_value, allocator);

    value = obj;
}


void InitialContextSetupResponse_Handler::serialize(rapidjson::Document& config) const {
    auto& allocator = config.GetAllocator();

    rapidjson::Value response(rapidjson::kObjectType);
    response.AddMember("cp_ue_id", message_.cp_ue_id, allocator);

    rapidjson::Value setupList(rapidjson::kArrayType);
    for (const auto& pair : message_.erab_setup_list) {
        rapidjson::Value key(rapidjson::kNumberType);
        key.SetUint(pair.first);

        rapidjson::Value value;
        this->SerializeERadioAccessBearerParameter(pair.second, value, allocator);
        rapidjson::Value obj(rapidjson::kObjectType);
        obj.AddMember("key", key, allocator);
        obj.AddMember("value", value, allocator);
        setupList.PushBack(obj,allocator);
        
    }
    response.AddMember("erab_setup_list", setupList, allocator);

    rapidjson::Value failedList(rapidjson::kArrayType);
    for (const auto& er : message_.erab_failed_list) {
        rapidjson::Value value;
        this->SerializeERadioAccessBearerCause(er, value, allocator);

        failedList.PushBack(value, allocator);
    }
    response.AddMember("erab_failed_list", failedList, allocator);

    config.SetObject();
    config.AddMember("initial_context_setup_response", response, allocator);

}

void InitialContextSetupResponse_Handler::deserialize(const rapidjson::Document& config) {
    if (!config.IsObject()) {
        throw std::runtime_error("Invalid JSON format");
    }

    // Десериализация cp_ue_id
    if (config.HasMember("cp_ue_id") && config["cp_ue_id"].IsInt()) {
        message_.cp_ue_id = config["cp_ue_id"].GetInt();
    }

    // Десериализация erab_setup_list
    if (config.HasMember("erab_setup_list") && config["erab_setup_list"].IsObject()) {
        const rapidjson::Value& erabSetupListJson = config["erab_setup_list"];
        for (auto it = erabSetupListJson.MemberBegin(); it != erabSetupListJson.MemberEnd(); ++it) {
            int key = std::stoi(it->name.GetString());
            vran::s1ap::lte::ERadioAccessBearerParameter erabp;

            this->deserializeERadioAccessBearerParameter(it->value, erabp);

            message_.erab_setup_list[key] = erabp;
        }
    }

    // Десериализация erab_failed_list
    if (config.HasMember("erab_failed_list") && config["erab_failed_list"].IsArray()) {
        const rapidjson::Value& erabFailedListJson = config["erab_failed_list"];
        for (rapidjson::SizeType i = 0; i < erabFailedListJson.Size(); ++i) {
            vran::s1ap::lte::ERadioAccessBearerCause erabc;

            
            this->deserializeERadioAccessBearerCause(erabFailedListJson[i], erabc);

            message_.erab_failed_list.push_back(erabc);
        }
    }
}

void InitialContextSetupResponse_Handler::deserializeERadioAccessBearerParameter(const rapidjson::Value& eaJson, vran::s1ap::lte::ERadioAccessBearerParameter& erabp) {
    if (eaJson.HasMember("address") && eaJson["address"].IsObject()) {
        this->deserializeTransportLayerAddress(eaJson["address"], erabp.address);
    }

    if (eaJson.HasMember("teid") && eaJson["teid"].IsInt()) {
        erabp.teid = eaJson["teid"].GetInt();
    }
}

void InitialContextSetupResponse_Handler::deserializeERadioAccessBearerCause(const rapidjson::Value& erJson, vran::s1ap::lte::ERadioAccessBearerCause& erabc) {
    if (erJson.HasMember("e_rab_id") && erJson["e_rab_id"].IsUint()) {
        erabc.e_rab_id = erJson["e_rab_id"].GetUint();
    }

    if (erJson.HasMember("cause") && erJson["cause"].IsInt()) {
        int causeValue = erJson["cause"].GetInt();
        erabc.cause = static_cast<vran::cplane::common::RrcCause>(causeValue);
    }

    if (erJson.HasMember("cause_value") && erJson["cause_value"].IsUint()) {
        erabc.cause_value = erJson["cause_value"].GetUint();
    }
}

void InitialContextSetupResponse_Handler::deserializeTransportLayerAddress(const rapidjson::Value& tsJson, vran::cplane::common::TransportLayerAddress& ts) {
    if (tsJson.HasMember("length") && tsJson["length"].IsUint()) {
        ts.length = tsJson["length"].GetUint();
    }

    if (tsJson.HasMember("buffer") && tsJson["buffer"].IsArray()) {
        const rapidjson::Value& bufferJson = tsJson["buffer"];
        for (rapidjson::SizeType i = 0; i < bufferJson.Size() && i < 20; ++i) {
            ts.buffer[i] = bufferJson[i].GetUint();
        }
    }
}

std::unique_ptr<InitialContextSetupResponse_Handler> GetFilledDai() {
    using namespace vran::cplane::common;
    using namespace vran::s1ap::lte;
    InitialContextSetupResponse message;
    message.cp_ue_id = 1;

    ERadioAccessBearerParameter e1;
    ERadioAccessBearerParameter e2;
    TransportLayerAddress t1;
    TransportLayerAddress t2;

    t1.length = 2;
    for (int i = 0; i < 20; ++i) {
        t1.buffer[i] = i;

    }
    t2.length = 3;
    for (int i = 0; i < 20; ++i) {
        t2.buffer[i] = i+1;
    }

    e1.address = t1;
    e2.address = t2;
    e1.teid = 4;
    e2.teid = 6;

    message.erab_setup_list.insert({ 2, e1 });
    message.erab_setup_list.insert({ 3, e2 });

    ERadioAccessBearerCause ec1;
    ERadioAccessBearerCause ec2;
    ec1.cause = RrcCause::CAUSE_NOTHING;
    ec2.cause = RrcCause::CAUSE_NAS;
    ec1.cause_value = 0;
    ec2.cause_value = 3;
    ec1.e_rab_id = 0;
    ec2.e_rab_id = 3;

    message.erab_failed_list.push_back(ec1);
    message.erab_failed_list.push_back(ec2);

    return std::make_unique<InitialContextSetupResponse_Handler>(message);
};
