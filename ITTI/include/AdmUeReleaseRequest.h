#pragma once

#include "types.hpp"
#include "structure_interface.h"

class AdmUeReleaseRequest_Handler : public StructureInterface {
public:
    AdmUeReleaseRequest_Handler() = default;
    AdmUeReleaseRequest_Handler(const vran::rrc_cu::lte::AdmUeReleaseRequest& message);

    void serialize(rapidjson::Document& config) const override;
    void deserialize(const rapidjson::Document& config) override;

    const vran::rrc_cu::lte::AdmUeReleaseRequest& getMessage() const { return message_; }

private:
    vran::rrc_cu::lte::AdmUeReleaseRequest message_;
};

std::unique_ptr<AdmUeReleaseRequest_Handler> GetFilledAdmUeReleaseRequest_Handler();
