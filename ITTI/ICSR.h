//Prusakov Aleksey
#pragma once

#include "types.hpp"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <sstream>
#include <vector>
#include <unordered_map>


using namespace rapidjson;
using cu_ue_id_t = uint32_t;
using teid_t = uint32_t;
using e_rab_id_t = uint8_t;
using rrc_cause_value_t = uint8_t;
using ErabsToSetup = std::unordered_map<e_rab_id_t, ERadioAccessBearerParameter>;
using ErabsToFail = std::vector<ERadioAccessBearerCause>;

enum class RrcCause
{
    CAUSE_NOTHING,
    CAUSE_RADIO_NETWORK,
    CAUSE_TRANSPORT,
    CAUSE_NAS,
    CAUSE_PROTOCOL,
    CAUSE_MISC,
    CAUSE_EXTENSION,
};

struct TransportLayerAddress
{
    uint8_t length;
    uint8_t buffer[20];
};

struct ERadioAccessBearerParameter
{
    TransportLayerAddress address;
    teid_t teid;

    void serialize(Document& config) {
        Value obj(kObjectType);

        obj.AddMember("teid", teid, config.GetAllocator());

        Value addressArray(kArrayType);
        for (int i = 0; i < address.length; ++i) {
            addressArray.PushBack(address.buffer[i], config.GetAllocator());
        }
        obj.AddMember("address", addressArray, config.GetAllocator());

        config.AddMember("ERadioAccessBearerParameter", obj, config.GetAllocator());
    }

    void deserialize(const Document& config) {
        teid = config["teid"].GetUint();

        const Value& addressArray = config["address"];
        for (int i = 0; i < addressArray.Size(); i++) {
            address.buffer[i] = addressArray[i].GetUint();
        }
        address.length = addressArray.Size();
    }
};

struct ERadioAccessBearerCause
{
    e_rab_id_t e_rab_id;
    RrcCause cause;
    rrc_cause_value_t cause_value;

    void serialize(Document& config) {
        Value obj(kObjectType);

        obj.AddMember("e_rab_id", e_rab_id, config.GetAllocator());
        obj.AddMember("cause", static_cast<int>(cause), config.GetAllocator());
        obj.AddMember("cause_value", cause_value, config.GetAllocator());

        config.AddMember("ERadioAccessBearerCause", obj, config.GetAllocator());
    }

    void deserialize(const Document& config) {
        e_rab_id = config["e_rab_id"].GetUint();
        cause = static_cast<RrcCause>(config["cause"].GetInt());
        cause_value = config["cause_value"].GetUint();
    }
};

struct InitialContextSetupResponse
{
    cu_ue_id_t cp_ue_id;
    ErabsToSetup erab_setup_list;
    ErabsToFail erab_failed_list;

    void serialize(Document& config) {
        Value obj(kObjectType);

        obj.AddMember("cp_ue_id", cp_ue_id, config.GetAllocator());

        Value setupArray(kArrayType);
        for (const auto& entry : erab_setup_list) {
            Value erabObj(kObjectType);
            erabObj.SetObject();

            erabObj.AddMember("e_rab_id", entry.first, config.GetAllocator());
            erabObj.AddMember("erab_params", Value(kObjectType).Move(), config.GetAllocator());
            entry.second.serialize(config);

            setupArray.PushBack(erabObj, config.GetAllocator());
        }
        obj.AddMember("erab_setup_list", setupArray, config.GetAllocator());

        Value failedArray(kArrayType);
        for (const auto& entry : erab_failed_list) {
            Value erabObj(kObjectType);

            erabObj.AddMember("e_rab_id", entry.e_rab_id, config.GetAllocator());
            erabObj.AddMember("cause", static_cast<int>(entry.cause), config.GetAllocator());
            erabObj.AddMember("cause_value", entry.cause_value, config.GetAllocator());

            failedArray.PushBack(erabObj, config.GetAllocator());
        }
        obj.AddMember("erab_failed_list", failedArray, config.GetAllocator());

        config.AddMember("InitialContextSetupResponse", obj, config.GetAllocator());
    }

    void deserialize(const Document& config) {
        cp_ue_id = config["cp_ue_id"].GetUint();

        const Value& setupArray = config["erab_setup_list"];
        for (int i = 0; i < setupArray.Size(); i++) {
            auto& erabObj = setupArray[i];
            e_rab_id_t e_rab_id = erabObj["e_rab_id"].GetUint();
            ERadioAccessBearerParameter erabParams;
            erabParams.deserialize(erabObj["erab_params"]);
            erab_setup_list[e_rab_id] = erabParams;
        }

        const Value& failedArray = config["erab_failed_list"];
        for (int i = 0; i < failedArray.Size(); i++) {
            const auto& erabObj = failedArray[i];
            ERadioAccessBearerCause cause;
            cause.e_rab_id = erabObj["e_rab_id"].GetUint();
            cause.cause = static_cast<RrcCause>(erabObj["cause"].GetInt());
            cause.cause_value = erabObj["cause_value"].GetUint();
            erab_failed_list.push_back(cause);
        }
    }
};