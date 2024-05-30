/**
 * @file DrbAdditionalInfo.h
 * @author Mikhail Dmitrievich Kozlov
 * @brief Class handler of "vran::rrc_du::DrbAdditionalInfo" struct
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "bearer_types.hpp"
#include "structure_interface.h"

#include <memory>

class DrbAdditionalInfo_Handler: public StructureInterface{
public:
    /**
     * @brief Construct a new DrbAdditionalInfo_Handler object
     * 
     */
    DrbAdditionalInfo_Handler() = default;
    /**
     * @brief Copy construct of a DrbAdditionalInfo_Handler object
     * 
     * @param message Message ref typeof "DrbAdditionalInfo"
     */
    DrbAdditionalInfo_Handler(const vran::rrc_du::DrbAdditionalInfo& message);

    /**
     * @brief Overrided serialize functoin for the message typeof "DrbAdditionalInfo"
     * 
     * @param config Parameter in which serializable information will be stored
     */
    void serialize(rapidjson::Document& config) const override;
    /**
     * @brief Overrided deserialize functoin for the message typeof "DrbAdditionalInfo"
     * 
     * @param config Parameter from which information is stored into the message
     */
    void deserialize(const rapidjson::Document &config) override;

private:
    /**
     * @brief Message typeof "DrbAdditionalInfo"
     * 
     */
    vran::rrc_du::DrbAdditionalInfo message_;
};

/**
 * @brief Fill message typeof "DrbAdditionalInfo"
 * 
 * @return std::unique_ptr<DrbAdditionalInfo_Handler> 
 */
std::unique_ptr<DrbAdditionalInfo_Handler> GetFilledDrbAdditionalInfo_Handler();