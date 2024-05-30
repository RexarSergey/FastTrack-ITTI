/**
 * @file AdmUeReleaseRequest.h
 * @author Dmitry Sergeevich Pudovkin
 * @brief Class handler of "vran::rrc_cu::lte::AdmUeReleaseRequest" struct
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "types.hpp"
#include "structure_interface.h"

class AdmUeReleaseRequest_Handler : public StructureInterface {
public:
    /**
     * @brief Construct a new AdmUeReleaseRequest_Handler object
     * 
     */
    AdmUeReleaseRequest_Handler() = default;
    /**
     * @brief Copy construction of a AdmUeReleaseRequest_Handler object
     * 
     * @param message Message ref typeof "AdmUeReleaseRequest"
     */
    AdmUeReleaseRequest_Handler(const vran::rrc_cu::lte::AdmUeReleaseRequest& message);

    /**
     * @brief Overrided serialize functoin for the message typeof "AdmUeReleaseRequest"
     * 
     * @param config Parameter in which serializable information will be stored
     */
    void serialize(rapidjson::Document& config) const override;

    /**
     * @brief Overrided deserialize functoin for the message typeof "AdmUeReleaseRequest"
     * 
     * @param config Parameter from which information is stored into the message
     */
    void deserialize(const rapidjson::Document& config) override;

    /**
     * @brief Get the message typeof AdmUeReleaseRequest
     * 
     * @return const vran::rrc_cu::lte::AdmUeReleaseRequest& 
     */
    const vran::rrc_cu::lte::AdmUeReleaseRequest& getMessage() const { return message_; }

private:
/**
 * @brief Message typeof "AdmUeReleaseRequest"
 * 
 */
    vran::rrc_cu::lte::AdmUeReleaseRequest message_;
};

/**
 * @brief Fill message typeof "AdmUeReleaseRequest"
 * 
 * @return std::unique_ptr<AdmUeReleaseRequest_Handler> 
 */
std::unique_ptr<AdmUeReleaseRequest_Handler> GetFilledAdmUeReleaseRequest_Handler();
