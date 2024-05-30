/**
 * @file InitialContextSetupResponse.h
 * @author Alexey Andreyevich Prusakov
 * @brief Class handler of "vran::s1ap::lte::InitialContextSetupResponse" struct
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "bearer_types.hpp"
#include "structure_interface.h"

#include <memory>

class InitialContextSetupResponse_Handler : public StructureInterface {
public:
    /**
     * @brief Construct a new InitialContextSetupResponse_Handler object
     * 
     */
    InitialContextSetupResponse_Handler() = default;
    /**
     * @brief Copy construct of a InitialContextSetupResponse_Handler object
     * 
     * @param message Message ref typeof "InitialContextSetupResponse"
     */
    InitialContextSetupResponse_Handler(const vran::s1ap::lte::InitialContextSetupResponse& message);

    /**
     * @brief Serialize "ERadioAccessBearerParameter" struct
     * 
     * @param erabp Ref of the "ERadioAccessBearerParameter" for reading
     * @param value JSON-type object storage of "ERadioAccessBearerParameter" struct
     * @param allocator Allocator for information storage in JSON-type object
     */
    void SerializeERadioAccessBearerParameter(const vran::s1ap::lte::ERadioAccessBearerParameter& erabp, rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const;
    /**
     * @brief Serialize "ERadioAccessBearerCause" struct
     * 
     * @param erabc Ref of the "ERadioAccessBearerCause" for reading
     * @param value JSON-type object storage of "ERadioAccessBearerCause" struct
     * @param allocator Allocator for information storage in JSON-type object
     */
    void SerializeERadioAccessBearerCause(const vran::s1ap::lte::ERadioAccessBearerCause& erabc, rapidjson::Value& value, rapidjson::Document::AllocatorType& allocator) const;

    /**
     * @brief Deserialize "TransportLayerAddress" struct
     * 
     * @param tsJson JSON-type object storage of "TransportLayerAddress" struct
     * @param ts Ref of the "TransportLayerAddress" for writing
     */
    void deserializeTransportLayerAddress(const rapidjson::Value& tsJson, vran::cplane::common::TransportLayerAddress& ts);
    /**
     * @brief Deserialize "ERadioAccessBearerParameter" struct
     * 
     * @param eaJson JSON-type object storage of "ERadioAccessBearerParameter" struct
     * @param erabp Ref of the "ERadioAccessBearerParameter" for writing
     */
    void deserializeERadioAccessBearerParameter(const rapidjson::Value& eaJson, vran::s1ap::lte::ERadioAccessBearerParameter& erabp);
    /**
     * @brief Deserialize "ERadioAccessBearerCause" struct
     * 
     * @param erJson JSON-type object storage of "ERadioAccessBearerCause" struct
     * @param erabc Ref of the "ERadioAccessBearerCause" for writing
     */
    void deserializeERadioAccessBearerCause(const rapidjson::Value& erJson, vran::s1ap::lte::ERadioAccessBearerCause& erabc);

    /**
     * @brief Overrided serialize functoin for the message typeof "InitialContextSetupResponse"
     * 
     * @param config Parameter in which serializable information will be stored
     */
    void serialize(rapidjson::Document& config) const override;
    /**
     * @brief Overrided deserialize functoin for the message typeof "InitialContextSetupResponse"
     * 
     * @param config Parameter from which information is stored into the message
     */
    void deserialize(const rapidjson::Document& config) override;

private:
    /**
     * @brief Message typeof "InitialContextSetupResponse"
     * 
     */
    vran::s1ap::lte::InitialContextSetupResponse message_;
};

/**
 * @brief Fill message typeof "InitialContextSetupResponse"
 * 
 * @return std::unique_ptr<InitialContextSetupResponse_Handler> 
 */
std::unique_ptr<InitialContextSetupResponse_Handler> GetFilledInitialContextSetupResponse();