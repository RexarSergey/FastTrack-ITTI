/**
 * @file AdmUeReleaseRequest.cpp
 * @author Dmitry Sergeevich Pudovkin
 * @brief Realization of "vran::rrc_cu::lte::AdmUeReleaseRequest" class handler
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/AdmUeReleaseRequest.h"
#include <iostream>
#include <document.h>
#include <writer.h>
#include <stringbuffer.h>

using namespace rapidjson;
using namespace vran::rrc_cu::lte;

/**
 * @brief Serialize "CarrierFreqsGERAN" struct
 * 
 * @param carrierFreqs Ptr of the "CarrierFreqsGERAN_t" for reading
 * @param writer Handler for generation JSON text
 */
void serializeCarrierFreqsGERAN(const CarrierFreqsGERAN_t* carrierFreqs, Writer<StringBuffer>& writer) {
    writer.StartObject();
    writer.Key("startingARFCN");
    writer.Int64(carrierFreqs->startingARFCN);

    writer.Key("bandIndicator");
    writer.Uint(carrierFreqs->bandIndicator);

    writer.Key("followingARFCNs");
    writer.StartObject();
    writer.Key("present");
    writer.Uint(static_cast<unsigned>(carrierFreqs->followingARFCNs.present));

    switch (carrierFreqs->followingARFCNs.present) {
    case CarrierFreqsGERAN__followingARFCNs_PR_explicitListOfARFCNs:
        writer.Key("explicitListOfARFCNs");
        writer.StartArray();
        for (size_t i = 0; i < carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.count; i++) {
            writer.Uint(*carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array[i]);
        }
        writer.EndArray();
        break;
    case CarrierFreqsGERAN__followingARFCNs_PR_equallySpacedARFCNs:
        writer.Key("equallySpacedARFCNs");
        writer.StartObject();
        writer.Key("arfcn_Spacing");
        writer.Int64(carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.arfcn_Spacing);
        writer.Key("numberOfFollowingARFCNs");
        writer.Int64(carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.numberOfFollowingARFCNs);
        writer.EndObject();
        break;
    case CarrierFreqsGERAN__followingARFCNs_PR_variableBitMapOfARFCNs:
        writer.Key("variableBitMapOfARFCNs");
        writer.String((const char*)carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.buf,
            static_cast<rapidjson::SizeType>(carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.size));
        break;
    default:
        break;
    }

    writer.EndObject();
    writer.EndObject();
}

/**
 * @brief Deserialize "CarrierFreqsGERAN" struct
 * 
 * @param doc JSON-type object storage of "CarrierFreqsGERAN_t" struct
 * @param carrierFreqs Ptr of the "CarrierFreqsGERAN_t" for writing
 */
void deserializeCarrierFreqsGERAN(const Value& doc, CarrierFreqsGERAN_t* carrierFreqs) {
    carrierFreqs->startingARFCN = doc["startingARFCN"].GetUint();
    carrierFreqs->bandIndicator = doc["bandIndicator"].GetUint();

    const Value& followingARFCNs = doc["followingARFCNs"];
    carrierFreqs->followingARFCNs.present = static_cast<CarrierFreqsGERAN__followingARFCNs_PR>(followingARFCNs["present"].GetUint());

    switch (carrierFreqs->followingARFCNs.present) {
    case CarrierFreqsGERAN__followingARFCNs_PR_explicitListOfARFCNs: {
        const Value& explicitListOfARFCNs = followingARFCNs["explicitListOfARFCNs"];
        carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.count = explicitListOfARFCNs.Size();
        carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array = (ARFCN_ValueGERAN_t**)calloc(explicitListOfARFCNs.Size(), sizeof(ARFCN_ValueGERAN_t*));

        if (carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array == nullptr) {
            std::cerr << "Memory allocation failed for explicitListOfARFCNs.list.array" << std::endl;
            exit(EXIT_FAILURE);
        }

        for (SizeType i = 0; i < explicitListOfARFCNs.Size(); i++) {
            carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array[i] = (ARFCN_ValueGERAN_t*)calloc(1, sizeof(ARFCN_ValueGERAN_t));
            if (carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array[i] == nullptr) {
                std::cerr << "Memory allocation failed for explicitListOfARFCNs.list.array[" << i << "]" << std::endl;
                exit(EXIT_FAILURE);
            }
            *(carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array[i]) = explicitListOfARFCNs[i].GetUint();
        }
        break;
    }
    case CarrierFreqsGERAN__followingARFCNs_PR_equallySpacedARFCNs: {
        const Value& equallySpacedARFCNs = followingARFCNs["equallySpacedARFCNs"];
        carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.arfcn_Spacing = equallySpacedARFCNs["arfcn_Spacing"].GetUint();
        carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.numberOfFollowingARFCNs = equallySpacedARFCNs["numberOfFollowingARFCNs"].GetUint();
        break;
    }
    case CarrierFreqsGERAN__followingARFCNs_PR_variableBitMapOfARFCNs: {
        const Value& variableBitMapOfARFCNs = followingARFCNs["variableBitMapOfARFCNs"];
        carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.size = variableBitMapOfARFCNs.GetStringLength();
        carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.buf = (uint8_t*)calloc(variableBitMapOfARFCNs.GetStringLength(), sizeof(uint8_t));

        if (carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.buf == nullptr) {
            std::cerr << "Memory allocation failed for variableBitMapOfARFCNs.buf" << std::endl;
            exit(EXIT_FAILURE);
        }

        memcpy(carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.buf, variableBitMapOfARFCNs.GetString(), variableBitMapOfARFCNs.GetStringLength());
        break;
    }
    default:
        break;
    }
}

/**
 * @brief Serialize "CarrierFreqCDMA2000" struct
 * 
 * @param carrierFreq Ptr of the "CarrierFreqCDMA2000_t" for reading
 * @param writer Handler for generation JSON text
 */
void serializeCarrierFreqCDMA2000(const CarrierFreqCDMA2000_t* carrierFreq, Writer<StringBuffer>& writer) {
    writer.StartObject();
    writer.Key("bandClass");
    writer.Int64(carrierFreq->bandClass);

    writer.Key("arfcn");
    writer.Int64(carrierFreq->arfcn);

    writer.EndObject();
}

/**
 * @brief Deserialize "CarrierFreqCDMA2000" struct
 * 
 * @param json JSON-type object storage of "CarrierFreqCDMA2000_t" struct
 * @param carrierFreq Ref of the "CarrierFreqCDMA2000_t" for writing
 */
void deserializeCarrierFreqCDMA2000(const Value& json, CarrierFreqCDMA2000_t& carrierFreq) {
    if (json.HasMember("bandClass") && json["bandClass"].IsInt64()) {
        carrierFreq.bandClass = static_cast<BandclassCDMA2000_t>(json["bandClass"].GetInt64());
    }

    if (json.HasMember("arfcn") && json["arfcn"].IsInt64()) {
        carrierFreq.arfcn = json["arfcn"].GetInt64();
    }
}

/**
 * @brief Serialize "CarrierFreqListUTRA_TDD_r10" struct
 * 
 * @param carrierFreqList Ptr of the "CarrierFreqListUTRA_TDD_r10_t" for reading
 * @param writer Handler for generation JSON text
 */
void serializeCarrierFreqListUTRA_TDD_r10(const CarrierFreqListUTRA_TDD_r10_t* carrierFreqList, Writer<StringBuffer>& writer) {
    writer.StartArray();
    for (size_t i = 0; i < carrierFreqList->list.count; i++) {
        writer.Int64(static_cast<int64_t>(*carrierFreqList->list.array[i]));
    }
    writer.EndArray();
}

/**
 * @brief Deserialize "CarrierFreqListUTRA_TDD_r10" struct
 * 
 * @param json JSON-type object storage of "CarrierFreqListUTRA_TDD_r10_t" struct
 * @param carrierFreqList Ptr of the "CarrierFreqListUTRA_TDD_r10_t" for writing
 */
void deserializeCarrierFreqListUTRA_TDD_r10(const Value& json, CarrierFreqListUTRA_TDD_r10_t* carrierFreqList) {
    const Value& list = json;
    carrierFreqList->list.count = list.Size();
    carrierFreqList->list.array = (ARFCN_ValueUTRA_t**)calloc(list.Size(), sizeof(ARFCN_ValueUTRA_t*));

    if (carrierFreqList->list.array == nullptr) {
        std::cerr << "Memory allocation failed for carrierFreqList->list.array" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (SizeType i = 0; i < list.Size(); i++) {
        carrierFreqList->list.array[i] = (ARFCN_ValueUTRA_t*)calloc(1, sizeof(ARFCN_ValueUTRA_t));
        if (carrierFreqList->list.array[i] == nullptr) {
            std::cerr << "Memory allocation failed for carrierFreqList->list.array[" << i << "]" << std::endl;
            exit(EXIT_FAILURE);
        }
        *carrierFreqList->list.array[i] = static_cast<ARFCN_ValueUTRA_t>(list[i].GetUint());
    }
}

/**
 * @brief Serialize "RedirectedCarrierInfo" struct
 * 
 * @param carrierInfo Ptr of the "RedirectedCarrierInfo_t" for reading
 * @param writer Handler for generation JSON text
 */
void serializeRedirectedCarrierInfo(const RedirectedCarrierInfo_t* carrierInfo, Writer<StringBuffer>& writer) {
    writer.StartObject();
    writer.Key("present");
    writer.Int(static_cast<int>(carrierInfo->present));

    switch (carrierInfo->present) {
    case RedirectedCarrierInfo_PR_eutra:
        writer.Key("eutra");
        writer.Int64(carrierInfo->choice.eutra);
        break;
    case RedirectedCarrierInfo_PR_geran:
        writer.Key("geran");
        serializeCarrierFreqsGERAN(&(carrierInfo->choice.geran), writer);
        break;
    case RedirectedCarrierInfo_PR_utra_FDD:
        writer.Key("utra_FDD");
        writer.Int64(carrierInfo->choice.utra_FDD);
        break;
    case RedirectedCarrierInfo_PR_utra_TDD:
        writer.Key("utra_TDD");
        writer.Int64(carrierInfo->choice.utra_TDD);
        break;
    case RedirectedCarrierInfo_PR_cdma2000_HRPD:
        writer.Key("cdma2000_HRPD");
        serializeCarrierFreqCDMA2000(&(carrierInfo->choice.cdma2000_HRPD), writer);
        break;
    case RedirectedCarrierInfo_PR_cdma2000_1xRTT:
        writer.Key("cdma2000_1xRTT");
        serializeCarrierFreqCDMA2000(&(carrierInfo->choice.cdma2000_1xRTT), writer);
        break;
    case RedirectedCarrierInfo_PR_utra_TDD_r10:
        writer.Key("utra_TDD_r10");
        serializeCarrierFreqListUTRA_TDD_r10(&(carrierInfo->choice.utra_TDD_r10), writer);
        break;
    default:
        break;
    }

    writer.EndObject();
}

/**
 * @brief Deserialize "RedirectedCarrierInfo" struct
 * 
 * @param json JSON-type object storage of "RedirectedCarrierInfo_t" struct
 * @param carrierInfo Ref of the "RedirectedCarrierInfo_t" for writing
 */
void deserializeRedirectedCarrierInfo(const Value& json, RedirectedCarrierInfo_t& carrierInfo) {
    if (json.HasMember("present") && json["present"].IsUint()) {
        carrierInfo.present = static_cast<RedirectedCarrierInfo_PR>(json["present"].GetUint());
    }

    switch (carrierInfo.present) {
    case RedirectedCarrierInfo_PR_eutra:
        if (json.HasMember("eutra") && json["eutra"].IsInt64()) {
            carrierInfo.choice.eutra = json["eutra"].GetInt64();
        }
        break;
    case RedirectedCarrierInfo_PR_geran:
        if (json.HasMember("geran") && json["geran"].IsObject()) {
            deserializeCarrierFreqsGERAN(json["geran"], &carrierInfo.choice.geran);
        }
        break;
    case RedirectedCarrierInfo_PR_utra_FDD:
        if (json.HasMember("utra_FDD") && json["utra_FDD"].IsInt64()) {
            carrierInfo.choice.utra_FDD = json["utra_FDD"].GetInt64();
        }
        break;
    case RedirectedCarrierInfo_PR_utra_TDD:
        if (json.HasMember("utra_TDD") && json["utra_TDD"].IsInt64()) {
            carrierInfo.choice.utra_TDD = json["utra_TDD"].GetInt64();
        }
        break;
    case RedirectedCarrierInfo_PR_cdma2000_HRPD:
        if (json.HasMember("cdma2000_HRPD") && json["cdma2000_HRPD"].IsObject()) {
            deserializeCarrierFreqCDMA2000(json["cdma2000_HRPD"], carrierInfo.choice.cdma2000_HRPD);
        }
        break;
    case RedirectedCarrierInfo_PR_cdma2000_1xRTT:
        if (json.HasMember("cdma2000_1xRTT") && json["cdma2000_1xRTT"].IsObject()) {
            deserializeCarrierFreqCDMA2000(json["cdma2000_1xRTT"], carrierInfo.choice.cdma2000_1xRTT);
        }
        break;
    case RedirectedCarrierInfo_PR_utra_TDD_r10:
        if (json.HasMember("utra_TDD_r10") && json["utra_TDD_r10"].IsArray()) {
            deserializeCarrierFreqListUTRA_TDD_r10(json["utra_TDD_r10"], &carrierInfo.choice.utra_TDD_r10);
        }
        break;
    default:
        break;
    }
}

/**
 * @brief Serialize "RrcCause" struct
 * 
 * @param rrcCause Ref of the "RrcCause" for reading
 * @param writer Handler for generation JSON text
 */
void serializeRrcCause(const vran::cplane::common::RrcCause& rrcCause, Writer<StringBuffer>& writer) {
    writer.StartObject();

    switch (rrcCause) {
    case vran::cplane::common::RrcCause::CAUSE_NOTHING:
        writer.Key("cause");
        writer.String("CAUSE_NOTHING");
        break;
    case vran::cplane::common::RrcCause::CAUSE_RADIO_NETWORK:
        writer.Key("cause");
        writer.String("CAUSE_RADIO_NETWORK");
        break;
    case vran::cplane::common::RrcCause::CAUSE_TRANSPORT:
        writer.Key("cause");
        writer.String("CAUSE_TRANSPORT");
        break;
    case vran::cplane::common::RrcCause::CAUSE_NAS:
        writer.Key("cause");
        writer.String("CAUSE_NAS");
        break;
    case vran::cplane::common::RrcCause::CAUSE_PROTOCOL:
        writer.Key("cause");
        writer.String("CAUSE_PROTOCOL");
        break;
    case vran::cplane::common::RrcCause::CAUSE_MISC:
        writer.Key("cause");
        writer.String("CAUSE_MISC");
        break;
    case vran::cplane::common::RrcCause::CAUSE_EXTENTION:
        writer.Key("cause");
        writer.String("CAUSE_EXTENTION");
        break;
    }

    writer.EndObject();
}

/**
 * @brief Deserialize "RrcCause" struct
 * 
 * @param json JSON-type object storage of "RrcCause" struct
 * @param rrcCause Ref of the "RrcCause" for writing
 */
void deserializeRrcCause(const Value& json, vran::cplane::common::RrcCause& rrcCause) {
    if (json.HasMember("cause") && json["cause"].IsString()) {
        const char* causeStr = json["cause"].GetString();
        if (strcmp(causeStr, "CAUSE_NOTHING") == 0) {
            rrcCause = vran::cplane::common::RrcCause::CAUSE_NOTHING;
        }
        else if (strcmp(causeStr, "CAUSE_RADIO_NETWORK") == 0) {
            rrcCause = vran::cplane::common::RrcCause::CAUSE_RADIO_NETWORK;
        }
        else if (strcmp(causeStr, "CAUSE_TRANSPORT") == 0) {
            rrcCause = vran::cplane::common::RrcCause::CAUSE_TRANSPORT;
        }
        else if (strcmp(causeStr, "CAUSE_NAS") == 0) {
            rrcCause = vran::cplane::common::RrcCause::CAUSE_NAS;
        }
        else if (strcmp(causeStr, "CAUSE_PROTOCOL") == 0) {
            rrcCause = vran::cplane::common::RrcCause::CAUSE_PROTOCOL;
        }
        else if (strcmp(causeStr, "CAUSE_MISC") == 0) {
            rrcCause = vran::cplane::common::RrcCause::CAUSE_MISC;
        }
        else if (strcmp(causeStr, "CAUSE_EXTENTION") == 0) {
            rrcCause = vran::cplane::common::RrcCause::CAUSE_EXTENTION;
        }
    }
}

/**
 * @brief Serialize "AdmUeReleaseRequest" struct
 * 
 * @param request Ref of the "AdmUeReleaseRequest" for reading
 * @param buffer Buffer for generation JSON text handler
 */
void serializeAdmUeReleaseRequest(const AdmUeReleaseRequest& request, StringBuffer& buffer) {
    Writer<StringBuffer> writer(buffer);
    writer.StartObject();

    writer.Key("AdmUeReleaseRequest");
    writer.StartObject();

    writer.Key("cause");
    serializeRrcCause(request.cause, writer);

    if (request.redirectedCarrierInfo) {
        writer.Key("redirectedCarrierInfo");
        serializeRedirectedCarrierInfo(request.redirectedCarrierInfo, writer);
    }

    writer.EndObject();
    writer.EndObject();
}

/**
 * @brief Deserialize "AdmUeReleaseRequest" struct
 * 
 * @param json JSON-type object storage of "AdmUeReleaseRequest" struct
 * @param request Ref of the "AdmUeReleaseRequest" for writing
 */
void deserializeAdmUeReleaseRequest(const Value& json, AdmUeReleaseRequest& request) {
    if (json.HasMember("AdmUeReleaseRequest") && json["AdmUeReleaseRequest"].IsObject()) {
        const Value& admUeReleaseRequest = json["AdmUeReleaseRequest"];

        if (admUeReleaseRequest.HasMember("cause") && admUeReleaseRequest["cause"].IsObject()) {
            deserializeRrcCause(admUeReleaseRequest["cause"], request.cause);
        }

        if (admUeReleaseRequest.HasMember("redirectedCarrierInfo") && admUeReleaseRequest["redirectedCarrierInfo"].IsObject()) {
            request.redirectedCarrierInfo = (RedirectedCarrierInfo_t*)calloc(1, sizeof(RedirectedCarrierInfo_t));

            if (request.redirectedCarrierInfo == nullptr) {
                std::cerr << "Memory allocation failed for redirectedCarrierInfo" << std::endl;
                exit(EXIT_FAILURE);
            }

            deserializeRedirectedCarrierInfo(admUeReleaseRequest["redirectedCarrierInfo"], *request.redirectedCarrierInfo);
        }
        else {
            request.redirectedCarrierInfo = nullptr;
        }
    }
}

AdmUeReleaseRequest_Handler::AdmUeReleaseRequest_Handler(const vran::rrc_cu::lte::AdmUeReleaseRequest& message) : message_(message) {}

void AdmUeReleaseRequest_Handler::serialize(rapidjson::Document& config) const {
    StringBuffer buffer;
    serializeAdmUeReleaseRequest(message_, buffer);
    config.Parse(buffer.GetString());
}

void AdmUeReleaseRequest_Handler::deserialize(const rapidjson::Document& config) {
    deserializeAdmUeReleaseRequest(config, message_);
}

std::unique_ptr<AdmUeReleaseRequest_Handler> GetFilledAdmUeReleaseRequest_Handler() {
    using namespace vran::cplane::common;
    AdmUeReleaseRequest message;

    message.cause = RrcCause::CAUSE_NAS;

    message.redirectedCarrierInfo = (RedirectedCarrierInfo_t*)calloc(1, sizeof(RedirectedCarrierInfo_t));

    if (message.redirectedCarrierInfo == nullptr) {
        std::cerr << "Memory allocation failed for redirectedCarrierInfo" << std::endl;
        exit(EXIT_FAILURE);
    }

    message.redirectedCarrierInfo->present = RedirectedCarrierInfo_PR_geran;

    CarrierFreqsGERAN_t& targetGeran = message.redirectedCarrierInfo->choice.geran;

    targetGeran.startingARFCN = 128;
    targetGeran.bandIndicator = 3;
    targetGeran.followingARFCNs.present = CarrierFreqsGERAN__followingARFCNs_PR_explicitListOfARFCNs;

    targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.count = 3;
    targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array = (ARFCN_ValueGERAN_t**)calloc(3, sizeof(ARFCN_ValueGERAN_t*));

    if (targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array == nullptr) {
        std::cerr << "Memory allocation failed for targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < 3; i++) {
        targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[i] = (ARFCN_ValueGERAN_t*)calloc(1, sizeof(ARFCN_ValueGERAN_t));
        if (targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[i] == nullptr) {
            std::cerr << "Memory allocation failed for targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[" << i << "]" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    *(targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[0]) = 129;
    *(targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[1]) = 130;
    *(targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[2]) = 131;

    return std::make_unique<AdmUeReleaseRequest_Handler>(message);
}
