// The file was executed by Mikhail Kozlov

#include "../include/DrbAdditionalInfo_Handler.h"

DrbAdditionalInfo_Handler::DrbAdditionalInfo_Handler(const vran::rrc_du::DrbAdditionalInfo& message)
    :message_(message)
{
}

void DrbAdditionalInfo_Handler::serialize(rapidjson::Document& config) const {
    rapidjson::Document::AllocatorType& allocator = config.GetAllocator();


    rapidjson::Value drb_additional_info_object(rapidjson::kObjectType);

    drb_additional_info_object.AddMember("drb_id", message_.drb_id, allocator);

    rapidjson::Value erab_qos_parameter_object(rapidjson::kObjectType);
    erab_qos_parameter_object.AddMember("qci", message_.qos_parameters.qci, allocator);

    rapidjson::Value allocation_retention_priority_object(rapidjson::kObjectType);
    allocation_retention_priority_object.AddMember("priority_level", message_.qos_parameters.allocation_retention_priority.priority_level, allocator);
    allocation_retention_priority_object.AddMember("pre_emption_vulnerability", message_.qos_parameters.allocation_retention_priority.pre_emption_vulnerability, allocator);
    allocation_retention_priority_object.AddMember("pre_emption_capability", message_.qos_parameters.allocation_retention_priority.pre_emption_capability, allocator);
    erab_qos_parameter_object.AddMember("allocation_retention_priority", allocation_retention_priority_object, allocator);

    if (message_.qos_parameters.gbr_qos_information.hasValue()) {
        rapidjson::Value gbr_qos_information_object(rapidjson::kObjectType);
        gbr_qos_information_object.AddMember("mbr_dl", message_.qos_parameters.gbr_qos_information->mbr_dl, allocator);
        gbr_qos_information_object.AddMember("mbr_ul", message_.qos_parameters.gbr_qos_information->mbr_ul, allocator);
        gbr_qos_information_object.AddMember("gbr_dl", message_.qos_parameters.gbr_qos_information->gbr_dl, allocator);
        gbr_qos_information_object.AddMember("gbr_ul", message_.qos_parameters.gbr_qos_information->gbr_ul, allocator);
        erab_qos_parameter_object.AddMember("gbr_qos_information", gbr_qos_information_object, allocator);
    }

    drb_additional_info_object.AddMember("qos_parameters", erab_qos_parameter_object, allocator);

    rapidjson::Value e_radio_access_bearer_parameter_object(rapidjson::kObjectType);
    rapidjson::Value transport_layer_address_object(rapidjson::kObjectType);
    transport_layer_address_object.AddMember("length", message_.param_gtp_cu.address.length, allocator);
    rapidjson::Value address_buffer(rapidjson::kArrayType);

    for (int i = 0; i < message_.param_gtp_cu.address.length; i++) {
        address_buffer.PushBack(message_.param_gtp_cu.address.buffer[i], allocator);
    }

    transport_layer_address_object.AddMember("buffer", address_buffer, allocator);
    e_radio_access_bearer_parameter_object.AddMember("address", transport_layer_address_object, allocator);
    e_radio_access_bearer_parameter_object.AddMember("teid", message_.param_gtp_cu.teid, allocator);
    drb_additional_info_object.AddMember("param_gtp_cu", e_radio_access_bearer_parameter_object, allocator);

    config.SetObject();
    config.AddMember("drb_additional_info", drb_additional_info_object, allocator);
}

void DrbAdditionalInfo_Handler::deserialize(const rapidjson::Document& config) {
    if (config.HasMember("drb_additional_info") && config["drb_additional_info"].IsObject()) {
        const rapidjson::Value& drb_additional_info_object = config["drb_additional_info"];

        if (drb_additional_info_object.HasMember("drb_id") && drb_additional_info_object["drb_id"].IsUint()) {
            message_.drb_id = drb_additional_info_object["drb_id"].GetUint();
        }

        if (drb_additional_info_object.HasMember("qos_parameters") && drb_additional_info_object["qos_parameters"].IsObject()) {
            const rapidjson::Value& erab_qos_parameter_object = drb_additional_info_object["qos_parameters"];

            if (erab_qos_parameter_object.HasMember("qci") && erab_qos_parameter_object["qci"].IsUint()) {
                message_.qos_parameters.qci = erab_qos_parameter_object["qci"].GetUint();
            }

            if (erab_qos_parameter_object.HasMember("allocation_retention_priority") &&
                erab_qos_parameter_object["allocation_retention_priority"].IsObject()) {
                const rapidjson::Value& allocation_retention_priority_object = erab_qos_parameter_object["allocation_retention_priority"];

                if (allocation_retention_priority_object.HasMember("priority_level") &&
                    allocation_retention_priority_object["priority_level"].IsUint()) {
                    message_.qos_parameters.allocation_retention_priority.priority_level =
                        allocation_retention_priority_object["priority_level"].GetUint();
                }

                if (allocation_retention_priority_object.HasMember("pre_emption_vulnerability") &&
                    allocation_retention_priority_object["pre_emption_vulnerability"].IsUint()) {
                    message_.qos_parameters.allocation_retention_priority.pre_emption_vulnerability =
                        static_cast<vran::cplane::common::PreEmptionVulnerability>(
                            allocation_retention_priority_object["pre_emption_vulnerability"].GetUint());
                }

                if (allocation_retention_priority_object.HasMember("pre_emption_capability") &&
                    allocation_retention_priority_object["pre_emption_capability"].IsUint()) {
                    message_.qos_parameters.allocation_retention_priority.pre_emption_capability =
                        static_cast<vran::cplane::common::PreEmptionCapability>(
                            allocation_retention_priority_object["pre_emption_capability"].GetUint());
                }
            }

            if (erab_qos_parameter_object.HasMember("gbr_qos_information") &&
                erab_qos_parameter_object["gbr_qos_information"].IsObject()) {
                const rapidjson::Value& gbr_qos_information_object = erab_qos_parameter_object["gbr_qos_information"];
                message_.qos_parameters.gbr_qos_information = vran::cplane::common::GbrQosInformation();
                if (gbr_qos_information_object.HasMember("mbr_dl") &&
                    gbr_qos_information_object["mbr_dl"].IsUint64()) {
                    message_.qos_parameters.gbr_qos_information->mbr_dl = gbr_qos_information_object["mbr_dl"].GetUint64();
                }

                if (gbr_qos_information_object.HasMember("mbr_ul") &&
                    gbr_qos_information_object["mbr_ul"].IsUint64()) {
                    message_.qos_parameters.gbr_qos_information->mbr_ul = gbr_qos_information_object["mbr_ul"].GetUint64();
                }

                if (gbr_qos_information_object.HasMember("gbr_dl") &&
                    gbr_qos_information_object["gbr_dl"].IsUint64()) {
                    message_.qos_parameters.gbr_qos_information->gbr_dl = gbr_qos_information_object["gbr_dl"].GetUint64();
                }

                if (gbr_qos_information_object.HasMember("gbr_ul") &&
                    gbr_qos_information_object["gbr_ul"].IsUint64()) {
                    message_.qos_parameters.gbr_qos_information->gbr_ul = gbr_qos_information_object["gbr_ul"].GetUint64();
                }
            }
        }

        if (drb_additional_info_object.HasMember("param_gtp_cu") &&
            drb_additional_info_object["param_gtp_cu"].IsObject()) {
            const rapidjson::Value& e_radio_access_bearer_parameter_object = drb_additional_info_object["param_gtp_cu"];

            if (e_radio_access_bearer_parameter_object.HasMember("address") &&
                e_radio_access_bearer_parameter_object["address"].IsObject()) {
                const rapidjson::Value& transport_layer_address_object = e_radio_access_bearer_parameter_object["address"];

                if (transport_layer_address_object.HasMember("length") &&
                    transport_layer_address_object["length"].IsUint()) {
                    message_.param_gtp_cu.address.length = transport_layer_address_object["length"].GetUint();
                }

                if (transport_layer_address_object.HasMember("buffer") &&
                    transport_layer_address_object["buffer"].IsArray() &&
                    transport_layer_address_object["buffer"].Size() == message_.param_gtp_cu.address.length) {
                    for (rapidjson::SizeType i = 0; i < message_.param_gtp_cu.address.length; ++i) {
                        if (transport_layer_address_object["buffer"][i].IsUint()) {
                            message_.param_gtp_cu.address.buffer[i] = transport_layer_address_object["buffer"][i].GetUint();
                        }
                    }
                }
            }

            if (e_radio_access_bearer_parameter_object.HasMember("teid") &&
                e_radio_access_bearer_parameter_object["teid"].IsUint()) {
                message_.param_gtp_cu.teid = e_radio_access_bearer_parameter_object["teid"].GetUint();
            }
        }
    }
}

std::unique_ptr<DrbAdditionalInfo_Handler> GetFilledDrbAdditionalInfo_Handler() {
    using namespace vran::cplane::common;
    vran::rrc_du::DrbAdditionalInfo message;
    message.drb_id = 23u;

    message.qos_parameters.qci = 200u;

    message.qos_parameters.allocation_retention_priority.priority_level = 3u;
    message.qos_parameters.allocation_retention_priority.pre_emption_vulnerability = PreEmptionVulnerability::PRE_EMPTION_VULNERABILITY_ENABLED;
    message.qos_parameters.allocation_retention_priority.pre_emption_capability = PreEmptionCapability::PRE_EMPTION_CAPABILITY_ENABLED;

    GbrQosInformation gbr_qos_information;
    gbr_qos_information.mbr_dl = 1234u;
    gbr_qos_information.mbr_ul = 56789u;
    gbr_qos_information.gbr_dl = 5000u;
    gbr_qos_information.gbr_ul = 9000000u;

    message.qos_parameters.gbr_qos_information = gbr_qos_information;

    message.param_gtp_cu.address.length = 5u;
    for (uint8_t i = 0; i < message.param_gtp_cu.address.length; ++i) {
        message.param_gtp_cu.address.buffer[i] = i * i;
    }
    message.param_gtp_cu.teid = 32u;

    return std::make_unique<DrbAdditionalInfo_Handler>(message);
}