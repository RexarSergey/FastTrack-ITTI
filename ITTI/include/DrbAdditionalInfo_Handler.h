// The file was executed by Mikhail Kozlov

#pragma once

#include "bearer_types.hpp"
#include "structure_interface.h"

#include <memory>

class DrbAdditionalInfo_Handler: public StructureInterface{
public:
    DrbAdditionalInfo_Handler() = default;
    DrbAdditionalInfo_Handler(const vran::rrc_du::DrbAdditionalInfo& message);

    void serialize(rapidjson::Document& config) const override;
    void deserialize(const rapidjson::Document &config) override;

private:
    vran::rrc_du::DrbAdditionalInfo message_;
};

std::unique_ptr<DrbAdditionalInfo_Handler> GetFilledDrbAdditionalInfo_Handler();