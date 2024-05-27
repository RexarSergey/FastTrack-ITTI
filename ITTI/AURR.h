#pragma once

#include "types.hpp"
#include "structure_interface.h"

class AURR : public StructureInterface {
public:
    AURR() = default;
    AURR(const vran::rrc_cu::lte::AdmUeReleaseRequest& message);

    void serialize(rapidjson::Document& config) const override;
    void deserialize(const rapidjson::Document& config) override;

    const vran::rrc_cu::lte::AdmUeReleaseRequest& getMessage() const { return message_; }

private:
    vran::rrc_cu::lte::AdmUeReleaseRequest message_;
};

std::unique_ptr<AURR> GetFilledAurr();