//Корсакова Юлия
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

class PSR {
public:
    PSR(const vran::s1ap::lte::PathSwitchRequest& message)
        :message_(message)
    {
    }

    void serialize(rapidjson::Document& config) const;
    void deserialize(const rapidjson::Document& config);

private:
    vran::s1ap::lte::PathSwitchRequest message_;
};

void PSR::serialize(rapidjson::Document& config) const {
    rapidjson::Document::AllocatorType& allocator = config.GetAllocator();
    config.SetObject();

    config.AddMember("cp_ue_id", message_.cp_ue_id, allocator);
    config.AddMember("src_mme_ue_s1ap_id", message_.src_mme_ue_s1ap_id, allocator);

    rapidjson::Value erabArray(rapidjson::kArrayType);
    for (const auto& erab : message_.erab_switch_list) {
        rapidjson::Value erabObj(rapidjson::kObjectType);
        erabObj.AddMember("e_rab_id", erab.e_rab_id, allocator);

        rapidjson::Value sgwAddrObj(rapidjson::kObjectType);
        sgwAddrObj.AddMember("length", erab.sgw_addr.length, allocator);
        rapidjson::Value sgwBufferArray(rapidjson::kArrayType);
        for (size_t i = 0; i < erab.sgw_addr.length; ++i) {
            sgwBufferArray.PushBack(erab.sgw_addr.buffer[i], allocator);
        }
        sgwAddrObj.AddMember("buffer", sgwBufferArray, allocator);
        erabObj.AddMember("sgw_addr", sgwAddrObj, allocator);

        erabObj.AddMember("sgw_teid", erab.sgw_teid, allocator);
        erabArray.PushBack(erabObj, allocator);
    }
    config.AddMember("erab_switch_list", erabArray, allocator);

    rapidjson::Value securityObj(rapidjson::kObjectType);
    securityObj.AddMember("encryption_algorithms", message_.security_capabilities.encryption_algorithms, allocator);
    securityObj.AddMember("integrity_algorithms", message_.security_capabilities.integrity_algorithms, allocator);
    config.AddMember("security_capabilities", securityObj, allocator);
}

void PSR::deserialize(const rapidjson::Document& config) {
    if (!config.IsObject()) {
        throw std::invalid_argument("Invalid JSON document");
    }

    if (config.HasMember("cp_ue_id") && config["cp_ue_id"].IsUint()) {
        message_.cp_ue_id = config["cp_ue_id"].GetUint();
    }

    if (config.HasMember("src_mme_ue_s1ap_id") && config["src_mme_ue_s1ap_id"].IsUint()) {
        message_.src_mme_ue_s1ap_id = config["src_mme_ue_s1ap_id"].GetUint();
    }

    if (config.HasMember("erab_switch_list") && config["erab_switch_list"].IsArray()) {
        const rapidjson::Value& erabArray = config["erab_switch_list"];
        for (rapidjson::SizeType i = 0; i < erabArray.Size(); ++i) {
            const rapidjson::Value& erabObj = erabArray[i];
            if (!erabObj.IsObject()) {
                throw std::invalid_argument("Invalid JSON document");
            }

            vran::cplane::common::ERadioAccessBearerSwitchParameter erab;
            if (erabObj.HasMember("e_rab_id") && erabObj["e_rab_id"].IsUint()) {
                erab.e_rab_id = erabObj["e_rab_id"].GetUint();
            }

            if (erabObj.HasMember("sgw_addr") && erabObj["sgw_addr"].IsObject()) {
                const rapidjson::Value& sgwAddrObj = erabObj["sgw_addr"];
                if (sgwAddrObj.HasMember("length") && sgwAddrObj["length"].IsUint()) {
                    erab.sgw_addr.length = sgwAddrObj["length"].GetUint();
                }

                if (sgwAddrObj.HasMember("buffer") && sgwAddrObj["buffer"].IsArray()) {
                    const rapidjson::Value& sgwBufferArray = sgwAddrObj["buffer"];
                    for (rapidjson::SizeType j = 0; j < sgwBufferArray.Size(); ++j) {
                        if (!sgwBufferArray[j].IsUint()) {
                            throw std::invalid_argument("Invalid JSON document");
                        }
                        erab.sgw_addr.buffer[j] = sgwBufferArray[j].GetUint();
                    }
                }
            }

            if (erabObj.HasMember("sgw_teid") && erabObj["sgw_teid"].IsUint()) {
                erab.sgw_teid = erabObj["sgw_teid"].GetUint();
            }

            message_.erab_switch_list.push_back(erab);
        }
    }

    if (config.HasMember("security_capabilities") && config["security_capabilities"].IsObject()) {
        const rapidjson::Value& securityObj = config["security_capabilities"];
        if (securityObj.HasMember("encryption_algorithms") && securityObj["encryption_algorithms"].IsUint()) {
            message_.security_capabilities.encryption_algorithms = securityObj["encryption_algorithms"].GetUint();
        }

        if (securityObj.HasMember("integrity_algorithms") && securityObj["integrity_algorithms"].IsUint()) {
            message_.security_capabilities.integrity_algorithms = securityObj["integrity_algorithms"].GetUint();
        }
    }
}