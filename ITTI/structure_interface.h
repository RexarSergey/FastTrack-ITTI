#pragma once

#include "rapidjson\document.h"

class StructureInterface {
public:
    virtual void serialize(rapidjson::Document& config) const = 0;
    virtual void deserialize(const rapidjson::Document& config) = 0;

    int GetId() const {
        return id_;
    }

    void SetId(int id) {
        id_ = id;
    }

private:
    int id_ = -1;
};
