//Korsakova Yulia
#pragma once

#include "types.hpp"
#include "structure_interface.h"


class PathSwitchRequest_Handler: public StructureInterface {
public:
    PathSwitchRequest_Handler() = default;
    PathSwitchRequest_Handler(const vran::s1ap::lte::PathSwitchRequest& message);

    void serialize(rapidjson::Document& config) const override;
    void deserialize(const rapidjson::Document& config) override;

private:
    vran::s1ap::lte::PathSwitchRequest message_;
};

std::unique_ptr<PathSwitchRequest_Handler> GetFilledPathSwitchRequest_Handler();