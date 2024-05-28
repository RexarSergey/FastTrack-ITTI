#pragma once
// Neugodnikov Sergey

#include <memory>
#include <document.h>
#include <types.hpp>

#include "../structure_interface.h"

using namespace rapidjson;
using namespace vran::rrc_cu::lte;

// InitialContextSetupAcknowledgement struct handler
struct InitialContextSetupAcknowledgement_Handler : public StructureInterface
{
	InitialContextSetupAcknowledgement_Handler() = default;
	InitialContextSetupAcknowledgement_Handler(const InitialContextSetupAcknowledgement& inMessage) : message(inMessage) {}

	// InitialContextSetupAcknowledgement serializer
	void serialize(Document& config) const override;
	// InitialContextSetupAcknowledgement deserializer
	void deserialize(const Document& config) override;

	// InitialContextSetupAcknowledgement print in json format
	void print_json();

private:
	// asn_struct_ctx_t struct serializer/deserializer
	void asn_ctx_serialize(Value& _asn_ctx, asn_struct_ctx_t& root, Document::AllocatorType& allocator) const;
	void asn_ctx_deserialize(asn_struct_ctx_t& asn_ctx, Value::ConstObject& obj);

	// MeasConfig struct serializer/deserializer
	void mc_serialize(Value& measConfig, Document::AllocatorType& allocator) const;
	void mc_deserialize(Value::ConstObject& icsa);

	// MeasConfig__speedStatePars struct serializer/deserializer
	void ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator) const;
	void ssp_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);

	// MeasConfig__measScaleFactor_r12 struct serializer/deserializer
	void msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator) const;
	void msf_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);

	// DRX_Config struct serializer/deserializer
	void cdrxc_serialize(Value& cdrxConfig, Document::AllocatorType& allocator) const;
	void cdrxc_deserialize(Value::ConstObject& icsa);

	// DRX_Config__setup__longDRX_CycleStartOffset struct serializer/deserializer
	void ldrx_serialize(Value& longDRX_CycleStartOffset, DRX_Config__setup__longDRX_CycleStartOffset_PR present, Document::AllocatorType& allocator) const;
	void ldrx_deserialize(DRX_Config::DRX_Config_u::DRX_Config__setup& setup, Value::ConstObject& obj_longdrx);

private:
	InitialContextSetupAcknowledgement message;
};

// fill InitialContextSetupAcknowledgement struct and return unique_ptr
std::unique_ptr<InitialContextSetupAcknowledgement_Handler> GetFilledICSA();
