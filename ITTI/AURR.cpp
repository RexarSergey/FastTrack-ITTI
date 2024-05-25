#include <iostream>
#include "types.hpp"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>


using namespace rapidjson;
using namespace vran::rrc_cu::lte;

void serializeCarrierFreqsGERAN(const CarrierFreqsGERAN_t* carrierFreqs, StringBuffer& buffer) {
    Writer<StringBuffer> writer(buffer);

    writer.StartObject();
    writer.Key("startingARFCN");
    writer.Int64(carrierFreqs->startingARFCN);

    writer.Key("bandIndicator");
    writer.Uint(carrierFreqs->bandIndicator);

    writer.Key("followingARFCNs");
    writer.StartObject();
    writer.Key("present");
    writer.Uint(carrierFreqs->followingARFCNs.present);

    switch (carrierFreqs->followingARFCNs.present) {
    case CarrierFreqsGERAN__followingARFCNs_PR_explicitListOfARFCNs:
        writer.Key("explicitListOfARFCNs");
        writer.StartArray();
        for (size_t i = 0; i < carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.count; i++) {
            writer.Int64(static_cast<int64_t>(carrierFreqs->startingARFCN));
        }
        writer.EndArray();
        break;
    case CarrierFreqsGERAN__followingARFCNs_PR_equallySpacedARFCNs:
        writer.Key("arfcn_Spacing");
        writer.Int64(carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.arfcn_Spacing);
        writer.Key("numberOfFollowingARFCNs");
        writer.Int64(carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.numberOfFollowingARFCNs);
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

void deserializeCarrierFreqsGERAN(const Value& doc, CarrierFreqsGERAN_t* carrierFreqs) {
    carrierFreqs->startingARFCN = doc["startingARFCN"].GetUint();
    carrierFreqs->bandIndicator = doc["bandIndicator"].GetUint();

    const Value& followingARFCNs = doc["followingARFCNs"];
    carrierFreqs->followingARFCNs.present = static_cast<CarrierFreqsGERAN__followingARFCNs_PR>(followingARFCNs["present"].GetUint());

    switch (carrierFreqs->followingARFCNs.present) {
    case CarrierFreqsGERAN__followingARFCNs_PR_explicitListOfARFCNs:
    {
        const Value& explicitListOfARFCNs = followingARFCNs["explicitListOfARFCNs"];
        carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.count = explicitListOfARFCNs.Size();
        carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array = (ARFCN_ValueGERAN_t**)calloc(explicitListOfARFCNs.Size(), sizeof(ARFCN_ValueGERAN_t*));
        for (SizeType i = 0; i < explicitListOfARFCNs.Size(); i++) {
            carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array[i] = (ARFCN_ValueGERAN_t*)calloc(1, sizeof(ARFCN_ValueGERAN_t));
            *carrierFreqs->followingARFCNs.choice.explicitListOfARFCNs.list.array[i] = explicitListOfARFCNs[i].GetUint();
        }
    }
    break;
    case CarrierFreqsGERAN__followingARFCNs_PR_equallySpacedARFCNs:
    {
        const Value& explicitListOfARFCNs = followingARFCNs["equallySpacedARFCNs"];
        carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.arfcn_Spacing = explicitListOfARFCNs["arfcn_Spacing"].GetInt();
        carrierFreqs->followingARFCNs.choice.equallySpacedARFCNs.numberOfFollowingARFCNs = explicitListOfARFCNs["numberOfFollowingARFCNs"].GetInt();
    }
    break;
    case CarrierFreqsGERAN__followingARFCNs_PR_variableBitMapOfARFCNs:
    {
        const Value& variableBitMapOfARFCNs = followingARFCNs["variableBitMapOfARFCNs"];
        carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.size = variableBitMapOfARFCNs.GetStringLength();
        memcpy(carrierFreqs->followingARFCNs.choice.variableBitMapOfARFCNs.buf, variableBitMapOfARFCNs.GetString(), variableBitMapOfARFCNs.GetStringLength());
    }
    break;

    default:
        break;
    }
}



void serializeCarrierFreqCDMA2000(const CarrierFreqCDMA2000_t* carrierFreq, StringBuffer& buffer) {
    Writer<StringBuffer> writer(buffer);

    writer.StartObject();
    writer.Key("bandClass");
    writer.Int64(carrierFreq->bandClass);

    writer.Key("arfcn");
    writer.Int64(carrierFreq->arfcn);

    writer.EndObject();
}

void deserializeCarrierFreqCDMA2000(const Value& json, CarrierFreqCDMA2000_t& carrierFreq) {
    if (json.HasMember("bandClass") && json["bandClass"].IsInt64()) {
        carrierFreq.bandClass = static_cast<BandclassCDMA2000_t>(json["bandClass"].GetInt64());
    }

    if (json.HasMember("arfcn") && json["arfcn"].IsInt64()) {
        carrierFreq.arfcn = json["arfcn"].GetInt64();
    }
}

void serializeCarrierFreqListUTRA_TDD_r10(const CarrierFreqListUTRA_TDD_r10_t* carrierFreqList, StringBuffer& buffer) {
    Writer<StringBuffer> writer(buffer);

    writer.StartArray();
    for (size_t i = 0; i < carrierFreqList->list.count; i++) {
        writer.Int64(static_cast<int64_t>(*carrierFreqList->list.array[i]));
    }
    writer.EndArray();
}

void deserializeCarrierFreqListUTRA_TDD_r10(const Value& json, CarrierFreqListUTRA_TDD_r10_t* carrierFreqList) {
    const Value& list = json;
    carrierFreqList->list.count = list.Size();
    carrierFreqList->list.array = (ARFCN_ValueUTRA_t**)calloc(list.Size(), sizeof(ARFCN_ValueUTRA_t*));
    for (SizeType i = 0; i < list.Size(); i++) {
        carrierFreqList->list.array[i] = (ARFCN_ValueUTRA_t*)calloc(1, sizeof(ARFCN_ValueUTRA_t));
        *carrierFreqList->list.array[i] = list[i].GetUint();
    }
}

void serializeRedirectedCarrierInfo(const RedirectedCarrierInfo_t* carrierInfo, StringBuffer& buffer) {
    Writer<StringBuffer> writer(buffer);

    writer.StartObject();
    writer.Key("present");
    writer.Uint(carrierInfo->present);

    switch (carrierInfo->present) {
    case RedirectedCarrierInfo_PR_eutra:
        writer.Key("eutra");
        writer.Int64(carrierInfo->choice.eutra);
        break;
    case RedirectedCarrierInfo_PR_geran:
        writer.Key("geran");
        serializeCarrierFreqsGERAN(&(carrierInfo->choice.geran), buffer);
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
        serializeCarrierFreqCDMA2000(&(carrierInfo->choice.cdma2000_HRPD), buffer);
        break;
    case RedirectedCarrierInfo_PR_cdma2000_1xRTT:
        writer.Key("cdma2000_1xRTT");
        serializeCarrierFreqCDMA2000(&(carrierInfo->choice.cdma2000_1xRTT), buffer);
        break;
    case RedirectedCarrierInfo_PR_utra_TDD_r10:
        writer.Key("utra_TDD_r10");
        serializeCarrierFreqListUTRA_TDD_r10(&(carrierInfo->choice.utra_TDD_r10), buffer);
        break;
    default:
        break;
    }

    writer.EndObject();
}

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
            //deserializeCarrierFreqListUTRA_TDD_r10(json["utra_TDD_r10"], carrierInfo.choice.utra_TDD_r10);
        }
        break;
    default:
        break;
    }
}

void serializeAdmUeReleaseRequest(const AdmUeReleaseRequest& request, StringBuffer& buffer) {
    Writer<StringBuffer> writer(buffer);

    writer.StartObject();

    writer.Key("cause");
    writer.Int(static_cast<int>(request.cause));

    writer.Key("cause_value");
    writer.Uint(request.cause_value);

    if (request.redirectedCarrierInfo) {
        writer.Key("redirectedCarrierInfo");
        serializeRedirectedCarrierInfo(request.redirectedCarrierInfo, buffer);
    }

    if (request.idleModeMobilityControlInfo) {
        writer.Key("idleModeMobilityControlInfo");
        // Сериализация IdleModeMobilityControlInfo_t
    }

    writer.EndObject();
}

void deserializeAdmUeReleaseRequest(const Value& json, AdmUeReleaseRequest& request) {
    if (json.HasMember("cause") && json["cause"].IsInt()) {
        request.cause = static_cast<RrcCause>(json["cause"].GetInt());
    }

    if (json.HasMember("cause_value") && json["cause_value"].IsUint()) {
        request.cause_value = json["cause_value"].GetUint();
    }

    if (json.HasMember("redirectedCarrierInfo") && json["redirectedCarrierInfo"].IsObject()) {
        request.redirectedCarrierInfo = new RedirectedCarrierInfo_t;
        deserializeRedirectedCarrierInfo(json["redirectedCarrierInfo"], *request.redirectedCarrierInfo);
    }

    if (json.HasMember("idleModeMobilityControlInfo") && json["idleModeMobilityControlInfo"].IsObject()) {
        request.idleModeMobilityControlInfo = new IdleModeMobilityControlInfo_t;
        // Десериализация IdleModeMobilityControlInfo_t
    }
}

int main() {


    return 0;
}