/**
 * @file PathSwitchRequest.cpp
 * @author Korsakova Yulia Dmitrievna
 * @brief Realization of "vran::s1ap::lte::PathSwitchRequest" class handler
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/PathSwitchRequest.h"
#include <stdexcept>

PathSwitchRequest_Handler::PathSwitchRequest_Handler(const vran::s1ap::lte::PathSwitchRequest& message)
    :message_(message)
{
}

void PathSwitchRequest_Handler::serialize(rapidjson::Document& config) const {
    rapidjson::Document::AllocatorType& allocator = config.GetAllocator();

    rapidjson::Value path_switch_request_object(rapidjson::kObjectType);

    path_switch_request_object.AddMember("cp_ue_id", message_.cp_ue_id, allocator);
    path_switch_request_object.AddMember("src_mme_ue_s1ap_id", message_.src_mme_ue_s1ap_id, allocator);

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
    path_switch_request_object.AddMember("erab_switch_list", erabArray, allocator);

    rapidjson::Value securityObj(rapidjson::kObjectType);
    securityObj.AddMember("encryption_algorithms", message_.security_capabilities.encryption_algorithms, allocator);
    securityObj.AddMember("integrity_algorithms", message_.security_capabilities.integrity_algorithms, allocator);
    path_switch_request_object.AddMember("security_capabilities", securityObj, allocator);

    config.SetObject();
    config.AddMember("path_switch_request", path_switch_request_object, allocator);
}

void PathSwitchRequest_Handler::deserialize(const rapidjson::Document& config) {
    if (config.HasMember("path_switch_request") && config["path_switch_request"].IsObject()) {

        const rapidjson::Value& path_switch_request_object = config["path_switch_request"];

        if (path_switch_request_object.HasMember("cp_ue_id") && path_switch_request_object["cp_ue_id"].IsUint()) {
            message_.cp_ue_id = path_switch_request_object["cp_ue_id"].GetUint();
        }

        if (path_switch_request_object.HasMember("src_mme_ue_s1ap_id") && path_switch_request_object["src_mme_ue_s1ap_id"].IsUint()) {
            message_.src_mme_ue_s1ap_id = path_switch_request_object["src_mme_ue_s1ap_id"].GetUint();
        }

        if (path_switch_request_object.HasMember("erab_switch_list") && path_switch_request_object["erab_switch_list"].IsArray()) {
            const rapidjson::Value& erabArray = path_switch_request_object["erab_switch_list"];
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

        if (path_switch_request_object.HasMember("security_capabilities") && path_switch_request_object["security_capabilities"].IsObject()) {
            const rapidjson::Value& securityObj = path_switch_request_object["security_capabilities"];
            if (securityObj.HasMember("encryption_algorithms") && securityObj["encryption_algorithms"].IsUint()) {
                message_.security_capabilities.encryption_algorithms = securityObj["encryption_algorithms"].GetUint();
            }

            if (securityObj.HasMember("integrity_algorithms") && securityObj["integrity_algorithms"].IsUint()) {
                message_.security_capabilities.integrity_algorithms = securityObj["integrity_algorithms"].GetUint();
            }
        }
    }
}

std::unique_ptr<PathSwitchRequest_Handler> GetFilledPathSwitchRequest_Handler() {
    using namespace vran::cplane::common;
    vran::s1ap::lte::PathSwitchRequest message;
    message.cp_ue_id = 1234;
    message.src_mme_ue_s1ap_id = 5678;

    ERadioAccessBearerSwitchParameter erab1;
    erab1.e_rab_id = 1;
    erab1.sgw_teid = 111;
    erab1.sgw_addr.length = 4;
    erab1.sgw_addr.buffer[0] = 192;
    erab1.sgw_addr.buffer[1] = 168;
    erab1.sgw_addr.buffer[2] = 1;
    erab1.sgw_addr.buffer[3] = 1;

    ERadioAccessBearerSwitchParameter erab2;
    erab2.e_rab_id = 2;
    erab2.sgw_teid = 222;
    erab2.sgw_addr.length = 4;
    erab2.sgw_addr.buffer[0] = 192;
    erab2.sgw_addr.buffer[1] = 168;
    erab2.sgw_addr.buffer[2] = 1;
    erab2.sgw_addr.buffer[3] = 2;

    message.erab_switch_list.push_back(erab1);
    message.erab_switch_list.push_back(erab2);

    message.security_capabilities.encryption_algorithms = 0b1010;
    message.security_capabilities.integrity_algorithms = 0b1100;

    return std::make_unique<PathSwitchRequest_Handler>(message);
}