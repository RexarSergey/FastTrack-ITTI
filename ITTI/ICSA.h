#pragma once
// Neugodnikov Sergey

#include "rapidjson/document.h"
#include "itti_structs/types.hpp"

using namespace rapidjson;
using namespace vran::rrc_cu::lte;


struct ICSA
{
	ICSA(InitialContextSetupAcknowledgement inMessage) : message(inMessage) {}

	void serialize(Document& config);
	void deserialize(const Document& config);

private:
	void ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator);
	void msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator);

	InitialContextSetupAcknowledgement message;
};

void ICSA::serialize(Document& config)
{
	Document::AllocatorType& allocator = config.GetAllocator();
	config.SetObject();

	config.AddMember("is_accepted", message.is_accepted, allocator);

	Value measConfig(kObjectType);

	// measConfig params without OPTIONAL
	Value speedStatePars_ptr(kObjectType);
	Value measScaleFactor_r12_ptr(kObjectType);
	Value _asn_ctx_mc(kObjectType);
	
	ssp_serialize(speedStatePars_ptr, allocator);
	msf_serialize(measScaleFactor_r12_ptr, allocator);

	_asn_ctx_mc.AddMember("phase", message.measConfig->_asn_ctx.phase, allocator);
	_asn_ctx_mc.AddMember("step", message.measConfig->_asn_ctx.step, allocator);
	_asn_ctx_mc.AddMember("context", message.measConfig->_asn_ctx.context, allocator);
	// TODO // _asn_ctx_mc.AddMember("ptr", message.measConfig->_asn_ctx.ptr, allocator);
	_asn_ctx_mc.AddMember("left", message.measConfig->_asn_ctx.left, allocator);


	measConfig.AddMember("speedStatePars", speedStatePars_ptr, allocator);
	measConfig.AddMember("measScaleFactor_r12", measScaleFactor_r12_ptr, allocator);
	measConfig.AddMember("_asn_ctx", _asn_ctx_mc, allocator);


	// cdrxConfig params
}

inline void ICSA::ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator)
{
	// speedStatePars_ptr prams
	auto ssp = message.measConfig->speedStatePars;

	speedStatePars_ptr.AddMember("present", ssp->present, allocator);
	if (ssp->present == MeasConfig__speedStatePars_PR_NOTHING
		|| ssp->present == MeasConfig__speedStatePars_PR_release)
	{
		speedStatePars_ptr.AddMember("choice", ssp->choice.release, allocator);
	}
	else
	{
		auto mc_ssp_s = ssp->choice.setup;

		Value setup(kObjectType);


		// setup params
		Value mobilityStateParameters(kObjectType);
		Value timeToTrigger_SF(kObjectType);
		Value _asn_ctx_s(kObjectType);


		auto msp = ssp->choice.setup.mobilityStateParameters;
		// mobilityStateParameters params
		mobilityStateParameters.AddMember("t_Evaluation", msp.t_Evaluation, allocator);
		mobilityStateParameters.AddMember("t_HystNormal", msp.t_HystNormal, allocator);
		mobilityStateParameters.AddMember("n_CellChangeMedium", msp.n_CellChangeMedium, allocator);
		mobilityStateParameters.AddMember("n_CellChangeHigh", msp.n_CellChangeHigh, allocator);
		Value _asn_ctx_msp(kObjectType);
		_asn_ctx_msp.AddMember("phase", msp._asn_ctx.phase, allocator);
		_asn_ctx_msp.AddMember("step", msp._asn_ctx.step, allocator);
		_asn_ctx_msp.AddMember("context", msp._asn_ctx.context, allocator);
		// TODO // _asn_ctx_msp.AddMember("ptr", msp._asn_ctx.phase, allocator);
		_asn_ctx_msp.AddMember("left", msp._asn_ctx.left, allocator);
		mobilityStateParameters.AddMember("_asn_ctx", _asn_ctx_msp, allocator);



		setup.AddMember("mobilityStateParameters", mobilityStateParameters, allocator);
		setup.AddMember("timeToTrigger_SF", timeToTrigger_SF, allocator);
		setup.AddMember("_asn_ctx", _asn_ctx_s, allocator);


		speedStatePars_ptr.AddMember("choice", setup, allocator);
	}

	Value _asn_ctx_mc_ssp(kObjectType);
	_asn_ctx_mc_ssp.AddMember("phase", ssp->_asn_ctx.phase, allocator);
	_asn_ctx_mc_ssp.AddMember("step", ssp->_asn_ctx.step, allocator);
	_asn_ctx_mc_ssp.AddMember("context", ssp->_asn_ctx.context, allocator);
	// TODO // _asn_ctx_mc_ssp.AddMember("ptr", ssp._asn_ctx.phase, allocator);
	_asn_ctx_mc_ssp.AddMember("left", ssp->_asn_ctx.left, allocator);
}

inline void ICSA::msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator)
{
	// measScaleFactor_r12_ptr prams
	auto msf = message.measConfig->measScaleFactor_r12;

	measScaleFactor_r12_ptr.AddMember("present", msf->present, allocator);
	if (msf->present == MeasConfig__measScaleFactor_r12_PR_NOTHING
		|| msf->present == MeasConfig__measScaleFactor_r12_PR_release)
	{
		measScaleFactor_r12_ptr.AddMember("choice", msf->choice.release, allocator);
	}
	else
	{
		measScaleFactor_r12_ptr.AddMember("choice", msf->choice.setup, allocator);
	}

	Value _asn_ctx_mc_msf(kObjectType);
	_asn_ctx_mc_msf.AddMember("phase", msf->_asn_ctx.phase, allocator);
	_asn_ctx_mc_msf.AddMember("step", msf->_asn_ctx.step, allocator);
	_asn_ctx_mc_msf.AddMember("context", msf->_asn_ctx.context, allocator);
	// TODO // _asn_ctx_mc_msf.AddMember("ptr", msf._asn_ctx.phase, allocator);
	_asn_ctx_mc_msf.AddMember("left", msf->_asn_ctx.left, allocator);
}
