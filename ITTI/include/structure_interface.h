/**
 * @file structure_interface.h
 * @author Mikhail Dmitrievich Kozlov
 * @brief Interface of serializable structures
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <document.h>

class StructureInterface {
public:
    /**
     * @brief Serialize functoin for the messages
     * 
     * @param config Parameter in which serializable information is stored
     */
    virtual void serialize(rapidjson::Document& config) const = 0;

    /**
     * @brief Deserialize functoin for the message
     * 
     * @param config Parameter from which information is stored to the message
     */
    virtual void deserialize(const rapidjson::Document& config) = 0;

    /**
     * @brief Get the Id parameter
     * 
     * @return Message id
     */
    int GetId() const {
        return id_;
    }

    /**
     * @brief Set the id parameter
     * 
     * @param id Message id
     */
    void SetId(int id) {
        id_ = id;
    }

private:
    /**
     * @brief message id
     * 
     */
    int id_ = -1;
};
