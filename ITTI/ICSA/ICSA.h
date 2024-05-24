#pragma once
// Neugodnikov Sergey

#include <memory>
#include <document.h>
#include <types.hpp>

#include "../structure_interface.h"

using namespace rapidjson;
using namespace vran::rrc_cu::lte;


struct ICSA : public StructureInterface
{
	ICSA() = default;
	ICSA(const InitialContextSetupAcknowledgement& inMessage) : message(inMessage) {}

	void serialize(Document& config) const override;
	void deserialize(const Document& config) override;

private:
	void asn_ctx_serialize(Value& _asn_ctx, asn_struct_ctx_t& root, Document::AllocatorType& allocator) const;
	void asn_ctx_deserialize(asn_struct_ctx_t& asn_ctx, Value::ConstObject& obj);


	void mc_serialize(Value& measConfig, Document::AllocatorType& allocator) const;
	void mc_deserialize(Value::ConstObject& icsa);

	void ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator) const;
	void ssp_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);

	void msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator) const;
	void msf_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc);


	void cdrxc_serialize(Value& cdrxConfig, Document::AllocatorType& allocator) const;
	void cdrxc_deserialize(Value::ConstObject& icsa);

	void ldrx_serialize(Value& longDRX_CycleStartOffset, DRX_Config__setup__longDRX_CycleStartOffset_PR present, Document::AllocatorType& allocator) const;
	void ldrx_deserialize(DRX_Config::DRX_Config_u::DRX_Config__setup& setup, Value::ConstObject& obj_longdrx);

private:
	InitialContextSetupAcknowledgement message;
};

std::unique_ptr<ICSA> GetFilledICSA();
