// The file was executed by Mikhail Kozlov

#pragma once

#include "bearer_types.hpp"
#include "structure_interface.h"

#include <memory>

class InitialContextSetupResponse_Handler : public StructureInterface {
public:
    InitialContextSetupResponse_Handler() = default;
    InitialContextSetupResponse_Handler(const vran::s1ap::lte::InitialContextSetupResponse& message);

    void SerializeERadioAccessBearerParameter(const vran::s1ap::lte::ERadioAccessBearerParameter& erabp, rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const;
    void SerializeERadioAccessBearerCause(const vran::s1ap::lte::ERadioAccessBearerCause& erabc, rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const;

    void deserializeTransportLayerAddress(const rapidjson::Value& tsJson, vran::cplane::common::TransportLayerAddress& ts);
    void deserializeERadioAccessBearerParameter(const rapidjson::Value& eaJson, vran::s1ap::lte::ERadioAccessBearerParameter& erabp);
    void deserializeERadioAccessBearerCause(const rapidjson::Value& erJson, vran::s1ap::lte::ERadioAccessBearerCause& erabc);

    void serialize(rapidjson::Document& config) const override;
    void deserialize(const rapidjson::Document& config) override;

private:
    vran::s1ap::lte::InitialContextSetupResponse message_;
};

std::unique_ptr<InitialContextSetupResponse_Handler> GetFilledDai();