#pragma once
// Neugodnikov Sergey

#include "rapidjson/document.h"
#include "itti_structs/types.hpp"

using namespace rapidjson;
using namespace vran::rrc_cu::lte;


struct ICSA
{
	ICSA() = default;
	ICSA(InitialContextSetupAcknowledgement inMessage) : message(inMessage) {}

	void serialize(Document& config);
	void deserialize(const Document& config);

private:
	void asn_ctx_serializer(Value& _asn_ctx, asn_struct_ctx_t& root, Document::AllocatorType& allocator);


	void mc_serialize(Value& measConfig, Document::AllocatorType& allocator);

	void ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator);
	void msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator);


	void cdrxc_serialize(Value& cdrxConfig, Document::AllocatorType& allocator);
	void ldrx_serialize(Value& longDRX_CycleStartOffset, DRX_Config__setup__longDRX_CycleStartOffset_PR present, Document::AllocatorType& allocator);

private:
	InitialContextSetupAcknowledgement message;
};

void ICSA::serialize(Document& config)
{
	Document::AllocatorType& allocator = config.GetAllocator();
	config.SetObject();

	config.AddMember("is_accepted", message.is_accepted, allocator);

	if (message.measConfig != nullptr)
	{
		Value measConfig(kObjectType);
		mc_serialize(measConfig, allocator);
		config.AddMember("measConfig", measConfig, allocator);
	}
	else
	{
		//config.AddMember("measConfig", kNullType, allocator);
	}

	if (message.cdrxConfig != nullptr)
	{
		Value cdrxConfig(kObjectType);
		cdrxc_serialize(cdrxConfig, allocator);
		config.AddMember("cdrxConfig", cdrxConfig, allocator);
	}
	else
	{
		//config.AddMember("cdrxConfig", kNullType, allocator);
	}

	//strdup(config.GetString());
}

inline void ICSA::asn_ctx_serializer(Value& _asn_ctx, asn_struct_ctx_t& root, Document::AllocatorType& allocator)
{
	_asn_ctx.AddMember("phase", root.phase, allocator);
	_asn_ctx.AddMember("step", root.step, allocator);
	_asn_ctx.AddMember("context", root.context, allocator);
	// TODO // _asn_ctx.AddMember("ptr", root.ptr, allocator);
	_asn_ctx.AddMember("left", root.left, allocator);
}

inline void ICSA::mc_serialize(Value& measConfig, Document::AllocatorType& allocator)
{
	//auto mc = message.measConfig;
	/*if (!mc->speedStatePars)
	{
		int x = 0;
	}*/

	// measConfig params without OPTIONAL
	Value speedStatePars_ptr(kObjectType);
	Value measScaleFactor_r12_ptr(kObjectType);
	Value _asn_ctx_mc(kObjectType);

	ssp_serialize(speedStatePars_ptr, allocator);
	msf_serialize(measScaleFactor_r12_ptr, allocator);
	asn_ctx_serializer(_asn_ctx_mc, message.measConfig->_asn_ctx, allocator);


	measConfig.AddMember("speedStatePars", speedStatePars_ptr, allocator);
	measConfig.AddMember("measScaleFactor_r12", measScaleFactor_r12_ptr, allocator);
	measConfig.AddMember("_asn_ctx", _asn_ctx_mc, allocator);
}

inline void ICSA::ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator)
{
	// speedStatePars_ptr prams
	auto ssp = message.measConfig->speedStatePars;

	speedStatePars_ptr.AddMember("present", static_cast<unsigned>(ssp->present), allocator);
	if (ssp->present == MeasConfig__speedStatePars_PR_NOTHING
		|| ssp->present == MeasConfig__speedStatePars_PR_release)
	{
		speedStatePars_ptr.AddMember("choice", static_cast<int>(ssp->choice.release), allocator);
	}
	else
	{
		auto mc_ssp_s = ssp->choice.setup;
		Value setup(kObjectType);

		// setup params
		Value mobilityStateParameters(kObjectType);
		Value timeToTrigger_SF(kObjectType);
		Value _asn_ctx_s(kObjectType);

		// mobilityStateParameters params
		auto msp = mc_ssp_s.mobilityStateParameters;

		mobilityStateParameters.AddMember("t_Evaluation", static_cast<int64_t>(msp.t_Evaluation), allocator);
		mobilityStateParameters.AddMember("t_HystNormal", static_cast<int64_t>(msp.t_HystNormal), allocator);
		mobilityStateParameters.AddMember("n_CellChangeMedium", static_cast<int64_t>(msp.n_CellChangeMedium), allocator);
		mobilityStateParameters.AddMember("n_CellChangeHigh", static_cast<int64_t>(msp.n_CellChangeHigh), allocator);

		Value _asn_ctx_msp(kObjectType);
		asn_ctx_serializer(_asn_ctx_msp, msp._asn_ctx, allocator);
		mobilityStateParameters.AddMember("_asn_ctx", _asn_ctx_msp, allocator);


		// timeToTrigger_SF params
		auto ttt_sf = mc_ssp_s.timeToTrigger_SF;

		timeToTrigger_SF.AddMember("sf_Medium", static_cast<int64_t>(ttt_sf.sf_Medium), allocator);
		timeToTrigger_SF.AddMember("sf_High", static_cast<int64_t>(ttt_sf.sf_High), allocator);

		Value _asn_ctx_sssf(kObjectType);
		asn_ctx_serializer(_asn_ctx_sssf, ttt_sf._asn_ctx, allocator);
		timeToTrigger_SF.AddMember("_asn_ctx", _asn_ctx_sssf, allocator);


		// _asn_ctx params
		asn_ctx_serializer(_asn_ctx_s, mc_ssp_s._asn_ctx, allocator);
		mobilityStateParameters.AddMember("_asn_ctx", _asn_ctx_s, allocator);


		setup.AddMember("mobilityStateParameters", mobilityStateParameters, allocator);
		setup.AddMember("timeToTrigger_SF", timeToTrigger_SF, allocator);
		setup.AddMember("_asn_ctx", _asn_ctx_s, allocator);


		speedStatePars_ptr.AddMember("choice", setup, allocator);
	}

	Value _asn_ctx_mc_ssp(kObjectType);
	asn_ctx_serializer(_asn_ctx_mc_ssp, ssp->_asn_ctx, allocator);
	speedStatePars_ptr.AddMember("_asn_ctx", _asn_ctx_mc_ssp, allocator);
}

inline void ICSA::msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator)
{
	// measScaleFactor_r12_ptr prams
	auto msf = message.measConfig->measScaleFactor_r12;

	measScaleFactor_r12_ptr.AddMember("present", static_cast<unsigned>(msf->present), allocator);
	if (msf->present == MeasConfig__measScaleFactor_r12_PR_NOTHING
		|| msf->present == MeasConfig__measScaleFactor_r12_PR_release)
	{
		measScaleFactor_r12_ptr.AddMember("choice", static_cast<int>(msf->choice.release), allocator);
	}
	else
	{
		measScaleFactor_r12_ptr.AddMember("choice", static_cast<int64_t>(msf->choice.setup), allocator);
	}

	Value _asn_ctx_mc_msf(kObjectType);
	asn_ctx_serializer(_asn_ctx_mc_msf, msf->_asn_ctx, allocator);
	measScaleFactor_r12_ptr.AddMember("_asn_ctx", _asn_ctx_mc_msf, allocator);
}

inline void ICSA::cdrxc_serialize(Value& cdrxConfig, Document::AllocatorType& allocator)
{
	Value choice(kObjectType);
	cdrxConfig.AddMember("present", static_cast<unsigned>(message.cdrxConfig->present), allocator);


	auto cdrxc = message.cdrxConfig;
	if (cdrxc->present == DRX_Config_PR_NOTHING
		|| cdrxc->present == DRX_Config_PR_release)
	{
		cdrxConfig.AddMember("choice", static_cast<int>(cdrxc->choice.release), allocator);
	}
	else
	{
		auto cdrxc_s = cdrxc->choice.setup;
		Value setup(kObjectType);

		setup.AddMember("onDurationTimer", static_cast<int64_t>(cdrxc_s.onDurationTimer), allocator);
		setup.AddMember("drx_InactivityTimer", static_cast<int64_t>(cdrxc_s.drx_InactivityTimer), allocator);
		setup.AddMember("drx_RetransmissionTimer", static_cast<int64_t>(cdrxc_s.drx_RetransmissionTimer), allocator);

		Value longDRX_CycleStartOffset(kObjectType);

		longDRX_CycleStartOffset.AddMember("present", static_cast<unsigned>(cdrxc_s.longDRX_CycleStartOffset.present), allocator);
		ldrx_serialize(longDRX_CycleStartOffset, cdrxc_s.longDRX_CycleStartOffset.present, allocator);
		
		Value _asn_ctx_s(kObjectType);
		asn_ctx_serializer(_asn_ctx_s, cdrxc_s.longDRX_CycleStartOffset._asn_ctx, allocator);
		longDRX_CycleStartOffset.AddMember("_asn_ctx", _asn_ctx_s, allocator);
		
		setup.AddMember("longDRX_CycleStartOffset", longDRX_CycleStartOffset, allocator);


		Value shortDRX(kObjectType);
		shortDRX.AddMember("shortDRX_Cycle", static_cast<int64_t>(cdrxc_s.shortDRX->shortDRX_Cycle), allocator);
		shortDRX.AddMember("drxShortCycleTimer", static_cast<int64_t>(cdrxc_s.shortDRX->drxShortCycleTimer), allocator);

		Value _asn_ctx_sdrx(kObjectType);
		asn_ctx_serializer(_asn_ctx_sdrx, cdrxc_s.shortDRX->_asn_ctx, allocator);
		longDRX_CycleStartOffset.AddMember("_asn_ctx", _asn_ctx_sdrx, allocator);

		setup.AddMember("shortDRX", shortDRX, allocator);

		Value _asn_ctx(kObjectType);
		asn_ctx_serializer(_asn_ctx, cdrxc_s._asn_ctx, allocator);
		setup.AddMember("_asn_ctx", _asn_ctx, allocator);

		cdrxConfig.AddMember("choice", setup, allocator);
	}

	Value _asn_ctx_drxc(kObjectType);
	asn_ctx_serializer(_asn_ctx_drxc, message.cdrxConfig->_asn_ctx, allocator);
	cdrxConfig.AddMember("_asn_ctx", _asn_ctx_drxc, allocator);
}

inline void ICSA::ldrx_serialize(Value& longDRX_CycleStartOffset, DRX_Config__setup__longDRX_CycleStartOffset_PR present, Document::AllocatorType& allocator)
{
	auto ch = message.cdrxConfig->choice.setup.longDRX_CycleStartOffset.choice;

	switch (present)
	{
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_NOTHING:
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf10:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf10), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf20:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf20), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf32:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf32), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf40:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf40), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf64:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf64), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf80:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf80), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf128:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf128), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf160:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf160), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf256:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf256), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf320:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf320), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf512:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf512), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf640:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf640), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf1024:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf1024), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf1280:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf1280), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf2048:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf2048), allocator);
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf2560:
		longDRX_CycleStartOffset.AddMember("choice", static_cast<int64_t>(ch.sf2560), allocator);
		break;
	default:
		break;
	}
}
