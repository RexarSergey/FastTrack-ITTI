#pragma once
// Neugodnikov Sergey

#include <document.h>
#include <types.hpp>


using namespace rapidjson;
using namespace vran::rrc_cu::lte;


struct ICSA
{
	ICSA() = default;
	ICSA(InitialContextSetupAcknowledgement inMessage) : message(inMessage) {}

	void serialize(Document& config);
	void deserialize(const Document& config);

private:
	void asn_ctx_serialize(Value& _asn_ctx, asn_struct_ctx_t& root, Document::AllocatorType& allocator);
	void asn_ctx_deserialize(asn_struct_ctx_t& asn_ctx, Value::ConstObject& obj);


	void mc_serialize(Value& measConfig, Document::AllocatorType& allocator);
	void mc_deserialize(Value::ConstObject& icsa);

	void ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator);
	void ssp_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);

	void msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator);
	void msf_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);


	void cdrxc_serialize(Value& cdrxConfig, Document::AllocatorType& allocator);
	void cdrxc_deserialize(Value::ConstObject& icsa);

	void ldrx_serialize(Value& longDRX_CycleStartOffset, DRX_Config__setup__longDRX_CycleStartOffset_PR present, Document::AllocatorType& allocator);
	void ldrx_deserialize(DRX_Config::DRX_Config_u::DRX_Config__setup& setup, Value::ConstObject& obj_longdrx);

private:
	InitialContextSetupAcknowledgement message;
};


