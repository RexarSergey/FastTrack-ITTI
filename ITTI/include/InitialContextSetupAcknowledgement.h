/**
 * @file InitialContextSetupAcknowledgement.h
 * @author Sergey Igorevich Neugodnikov
 * @brief Struct handler of "vran::rrc_cu::lte::InitialContextSetupAcknowledgement" struct
 * @date 2024-05-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <memory>
#include <document.h>
#include <types.hpp>

#include "structure_interface.h"

using namespace rapidjson;
using namespace vran::rrc_cu::lte;


struct InitialContextSetupAcknowledgement_Handler : public StructureInterface
{
	/**
	 * @brief Construct a new InitialContextSetupAcknowledgement_Handler object
	 * 
	 */
	InitialContextSetupAcknowledgement_Handler() = default;
	/**
	 * @brief Copy construction of a InitialContextSetupAcknowledgement_Handler object
	 * 
	 * @param message Message ref typeof "InitialContextSetupAcknowledgement"
	 */
	InitialContextSetupAcknowledgement_Handler(const InitialContextSetupAcknowledgement& message) : message_(message) {}

	/**
	 * @brief Overrided serialize functoin for the message typeof "InitialContextSetupAcknowledgement"
	 * 
	 * @param config Parameter in which serializable information will be stored
	 */
	void serialize(Document& config) const override;
	/**
	 * @brief Overrided deserialize functoin for the message typeof "InitialContextSetupAcknowledgement"
	 * 
	 * @param config Parameter from which information is stored into the message
	 */
	void deserialize(const Document& config) override;

	/**
	 * @brief Print message in json format
	 * 
	 */
	void print_json();

private:
	/**
	 * @brief Serialize "asn_struct_ctx_s" struct
	 * 
	 * @param _asn_ctx JSON-type object storage of "asn_struct_ctx_t" struct
	 * @param root Path to the "asn_struct_ctx_t" structure type parameter
	 * @param allocator Allocator for information storage in JSON-type object
	 */
	void asn_ctx_serialize(Value& _asn_ctx, asn_struct_ctx_t& root, Document::AllocatorType& allocator) const;
	/**
	 * @brief Deserialize "asn_struct_ctx_s" struct
	 * 
	 * @param asn_ctx Path to the "asn_struct_ctx_t" structure type parameter
	 * @param obj JSON-type object storage of "asn_struct_ctx_t" struct
	 */
	void asn_ctx_deserialize(asn_struct_ctx_t& asn_ctx, Value::ConstObject& obj);

	/**
	 * @brief Serialize "MeasConfig" struct
	 * 
	 * @param measConfig JSON-type object storage of "MeasConfig" struct
	 * @param allocator Allocator for information storage in JSON-type object
	 */
	void mc_serialize(Value& measConfig, Document::AllocatorType& allocator) const;
	/**
	 * @brief Deserialize "MeasConfig" struct
	 * 
	 * @param icsa JSON-type object storage of "InitialContextSetupAcknowledgement" struct
	 */
	void mc_deserialize(Value::ConstObject& icsa);

	/**
	 * @brief Serialize "MeasConfig::MeasConfig__speedStatePars" struct
	 * 
	 * @param speedStatePars_ptr JSON-type object storage of "MeasConfig::MeasConfig__speedStatePars" struct
	 * @param allocator Allocator for information storage in JSON-type object
	 */
	void ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator) const;
	/**
	 * @brief Deserialize "MeasConfig::MeasConfig__speedStatePars" struct
	 * 
	 * @param measConfig Ref of the "MeasConfig" for writing "MeasConfig::MeasConfig__speedStatePars" struct
	 * @param obj_mc JSON-type object storage of "MeasConfig" struct
	 */
	void ssp_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);

	/**
	 * @brief Serialize "MeasConfig::MeasConfig__measScaleFactor_r12" struct
	 * 
	 * @param measScaleFactor_r12_ptr JSON-type object storage of "MeasConfig::MeasConfig__measScaleFactor_r12" struct
	 * @param allocator Allocator for information storage in JSON-type object
	 */
	void msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator) const;
	/**
	 * @brief Deserialize "MeasConfig::MeasConfig__measScaleFactor_r12" struct
	 * 
	 * @param measConfig Ref of the "MeasConfig" for writing "MeasConfig::MeasConfig__measScaleFactor_r12" struct
	 * @param obj_mc JSON-type object storage of "MeasConfig" struct
	 */
	void msf_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);

	/**
	 * @brief Serialize "DRX_Config" struct
	 * 
	 * @param cdrxConfig JSON-type object storage of "DRX_Config" struct
	 * @param allocator Allocator for information storage in JSON-type object
	 */
	void cdrxc_serialize(Value& cdrxConfig, Document::AllocatorType& allocator) const;
	/**
	 * @brief Deserialize "DRX_Config" struct
	 * 
	 * @param icsa JSON-type object storage of "InitialContextSetupAcknowledgement" struct
	 */
	void cdrxc_deserialize(Value::ConstObject& icsa);

	/**
	 * @brief Serialize "DRX_Config::<..>::DRX_Config__setup__longDRX_CycleStartOffset" struct
	 * 
	 * @param longDRX_CycleStartOffset JSON-type object storage of "DRX_Config::<..>::DRX_Config__setup__longDRX_CycleStartOffset" struct
	 * @param present Selection from "DRX_Config__setup__longDRX_CycleStartOffset_PR" enum
	 * @param allocator Allocator for information storage in JSON-type object
	 */
	void ldrx_serialize(Value& longDRX_CycleStartOffset, DRX_Config__setup__longDRX_CycleStartOffset_PR present, Document::AllocatorType& allocator) const;
	/**
	 * @brief Deserialize "DRX_Config::<..>::DRX_Config__setup__longDRX_CycleStartOffset" struct
	 * 
	 * @param setup Ref of the "DRX_Config::DRX_Config_u::DRX_Config__setup" for writing
	 * @param obj_longdrx JSON-type object storage of "DRX_Config::<..>::DRX_Config__setup__longDRX_CycleStartOffset" struct
	 */
	void ldrx_deserialize(DRX_Config::DRX_Config_u::DRX_Config__setup& setup, Value::ConstObject& obj_longdrx);

private:
	/**
	 * @brief Message typeof "InitialContextSetupAcknowledgement"
	 * 
	 */
	InitialContextSetupAcknowledgement message_;
};

// fill InitialContextSetupAcknowledgement struct and return unique_ptr
/**
 * @brief Fill message typeof "InitialContextSetupAcknowledgement"
 * 
 * @return std::unique_ptr<InitialContextSetupAcknowledgement_Handler> 
 */
std::unique_ptr<InitialContextSetupAcknowledgement_Handler> GetFilledInitialContextSetupAcknowledgement();
