/**
 * @file PathSwitchRequest.h
 * @author Korsakova Yulia Dmitrievna
 * @brief Class handler of "vran::s1ap::lte::PathSwitchRequest" struct
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "types.hpp"
#include "structure_interface.h"


class PathSwitchRequest_Handler: public StructureInterface {
public:
    /**
     * @brief Construct a new PathSwitchRequest_Handler object
     * 
     */
    PathSwitchRequest_Handler() = default;
    /**
     * @brief Copy construction of a PathSwitchRequest_Handler object
     * 
     * @param message Message ref typeof "PathSwitchRequest"
     */
    PathSwitchRequest_Handler(const vran::s1ap::lte::PathSwitchRequest& message);

    /**
     * @brief Overrided serialize functoin for the message typeof "PathSwitchRequest"
     * 
     * @param config Parameter in which serializable information will be stored
     */
    void serialize(rapidjson::Document& config) const override;
    /**
     * @brief Overrided deserialize functoin for the message typeof "PathSwitchRequest"
     * 
     * @param config Parameter from which information is stored into the message
     */
    void deserialize(const rapidjson::Document& config) override;

private:
    /**
     * @brief Message typeof "PathSwitchRequest"
     * 
     */
    vran::s1ap::lte::PathSwitchRequest message_;
};

/**
 * @brief Fill message typeof "PathSwitchRequest"
 * 
 * @return std::unique_ptr<PathSwitchRequest_Handler> 
 */
std::unique_ptr<PathSwitchRequest_Handler> GetFilledPathSwitchRequest_Handler();