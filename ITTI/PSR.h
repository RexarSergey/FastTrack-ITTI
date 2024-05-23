//Korsakova Yulia
#pragma once

#include "types.hpp"
#include "structure_interface.h"


class PSR: public StructureInterface {
public:
    PSR(const vran::s1ap::lte::PathSwitchRequest& message);

    void serialize(rapidjson::Document& config) const override;
    void deserialize(const rapidjson::Document& config) override;

private:
    vran::s1ap::lte::PathSwitchRequest message_;
};

std::unique_ptr<PSR> GetFilledDai();


