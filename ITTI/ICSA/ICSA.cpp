#include "ICSA.h"

void ICSA::serialize(Document& config)
{
	Document::AllocatorType& allocator = config.GetAllocator();
	config.SetObject();

	Value icsa(kObjectType);

	icsa.AddMember("is_accepted", message.is_accepted, allocator);

	if (message.measConfig != nullptr)
	{
		Value measConfig(kObjectType);
		mc_serialize(measConfig, allocator);
		icsa.AddMember("measConfig", measConfig, allocator);
	}
	else
	{
		icsa.AddMember("measConfig", kNullType, allocator);
	}

	if (message.cdrxConfig != nullptr)
	{
		Value cdrxConfig(kObjectType);
		cdrxc_serialize(cdrxConfig, allocator);
		icsa.AddMember("cdrxConfig", cdrxConfig, allocator);
	}
	else
	{
		icsa.AddMember("cdrxConfig", kNullType, allocator);
	}

	config.AddMember("InitialContextSetupAcknowledgement", icsa, allocator);
	//strdup(config.GetString());
}

void ICSA::deserialize(const Document& config)
{
	if (!(config.HasMember("InitialContextSetupAcknowledgement") && config["InitialContextSetupAcknowledgement"].IsObject()))
		return;
	auto icsa = config["InitialContextSetupAcknowledgement"].GetObj();

	if (icsa.HasMember("is_accepted") && icsa["is_accepted"].IsBool())
	{
		message.is_accepted = icsa["is_accepted"].GetBool();
	}

	mc_deserialize(icsa);
	cdrxc_deserialize(icsa);
}

void ICSA::asn_ctx_serialize(Value& _asn_ctx, asn_struct_ctx_t& root, Document::AllocatorType& allocator)
{
	_asn_ctx.AddMember("phase", root.phase, allocator);
	_asn_ctx.AddMember("step", root.step, allocator);
	_asn_ctx.AddMember("context", root.context, allocator);

	// TODO // _asn_ctx.AddMember("ptr", root.ptr, allocator);
	_asn_ctx.AddMember("ptr", kNullType, allocator);

	_asn_ctx.AddMember("left", root.left, allocator);
}

void ICSA::asn_ctx_deserialize(asn_struct_ctx_t& asn_ctx, Value::ConstObject& obj)
{
	asn_ctx.phase = obj["phase"].GetInt();
	asn_ctx.step = obj["step"].GetInt();
	asn_ctx.context = obj["context"].GetInt();
	asn_ctx.ptr = nullptr;
	asn_ctx.left = obj["left"].GetUint();
}

void ICSA::mc_serialize(Value& measConfig, Document::AllocatorType& allocator)
{
	// measConfig params without OPTIONAL
	Value speedStatePars_ptr(kObjectType);
	Value measScaleFactor_r12_ptr(kObjectType);
	Value _asn_ctx_mc(kObjectType);

	if (message.measConfig->speedStatePars != nullptr)
	{
		ssp_serialize(speedStatePars_ptr, allocator);
		measConfig.AddMember("speedStatePars", speedStatePars_ptr, allocator);
	}
	else
	{
		measConfig.AddMember("speedStatePars", kNullType, allocator);
	}

	if (message.measConfig->measScaleFactor_r12 != nullptr)
	{
		msf_serialize(measScaleFactor_r12_ptr, allocator);
		measConfig.AddMember("measScaleFactor_r12", measScaleFactor_r12_ptr, allocator);
	}
	else
	{
		measConfig.AddMember("measScaleFactor_r12", kNullType, allocator);
	}

	asn_ctx_serialize(_asn_ctx_mc, message.measConfig->_asn_ctx, allocator);
	measConfig.AddMember("_asn_ctx", _asn_ctx_mc, allocator);
}

void ICSA::mc_deserialize(Value::ConstObject& icsa)
{
	if (icsa.HasMember("measConfig") && icsa["measConfig"].IsObject())
	{
		MeasConfig measConfig;
		auto obj_mc = icsa["measConfig"].GetObj();

		ssp_deserialize(measConfig, obj_mc);
		msf_deserialize(measConfig, obj_mc);

		auto asn_ctx = obj_mc["_asn_ctx"].GetObj();
		asn_ctx_deserialize(measConfig._asn_ctx, asn_ctx);

		message.measConfig = &measConfig;
	}
	else
	{
		message.measConfig = nullptr;
	}
}

void ICSA::ssp_serialize(Value& speedStatePars_ptr, Document::AllocatorType& allocator)
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
		asn_ctx_serialize(_asn_ctx_msp, msp._asn_ctx, allocator);
		mobilityStateParameters.AddMember("_asn_ctx", _asn_ctx_msp, allocator);


		// timeToTrigger_SF params
		auto ttt_sf = mc_ssp_s.timeToTrigger_SF;

		timeToTrigger_SF.AddMember("sf_Medium", static_cast<int64_t>(ttt_sf.sf_Medium), allocator);
		timeToTrigger_SF.AddMember("sf_High", static_cast<int64_t>(ttt_sf.sf_High), allocator);

		Value _asn_ctx_sssf(kObjectType);
		asn_ctx_serialize(_asn_ctx_sssf, ttt_sf._asn_ctx, allocator);
		timeToTrigger_SF.AddMember("_asn_ctx", _asn_ctx_sssf, allocator);


		// _asn_ctx params
		asn_ctx_serialize(_asn_ctx_s, mc_ssp_s._asn_ctx, allocator);
		mobilityStateParameters.AddMember("_asn_ctx", _asn_ctx_s, allocator);


		setup.AddMember("mobilityStateParameters", mobilityStateParameters, allocator);
		setup.AddMember("timeToTrigger_SF", timeToTrigger_SF, allocator);
		setup.AddMember("_asn_ctx", _asn_ctx_s, allocator);


		speedStatePars_ptr.AddMember("choice", setup, allocator);
	}

	Value _asn_ctx_mc_ssp(kObjectType);
	asn_ctx_serialize(_asn_ctx_mc_ssp, ssp->_asn_ctx, allocator);
	speedStatePars_ptr.AddMember("_asn_ctx", _asn_ctx_mc_ssp, allocator);
}

void ICSA::ssp_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc)
{
	if (obj_mc.HasMember("speedStatePars") && obj_mc["speedStatePars"].IsObject())
	{
		auto obj_ssp = obj_mc["speedStatePars"].GetObj();

		MeasConfig::MeasConfig__speedStatePars ssp;

		ssp.present = static_cast<MeasConfig__speedStatePars_PR>(obj_ssp["present"].GetInt());

		if (ssp.present == MeasConfig__speedStatePars_PR_NOTHING
			|| ssp.present == MeasConfig__speedStatePars_PR_release)
		{
			ssp.choice.release = obj_ssp["choice"].GetInt();
		}
		else
		{
			MeasConfig::MeasConfig__speedStatePars::MeasConfig__speedStatePars_u::MeasConfig__speedStatePars__setup setup;
			auto obj_choice_setup = obj_ssp["choice"].GetObj();

			{
				auto obj_msp = obj_choice_setup["mobilityStateParameters"].GetObj();
				MobilityStateParameters_t msp;
				msp.t_Evaluation = obj_msp["t_Evaluation"].GetInt64();
				msp.t_HystNormal = obj_msp["t_HystNormal"].GetInt64();
				msp.n_CellChangeMedium = obj_msp["n_CellChangeMedium"].GetInt64();
				msp.n_CellChangeHigh = obj_msp["n_CellChangeHigh"].GetInt64();
				auto asn_ctx = obj_msp["_asn_ctx"].GetObj();
				asn_ctx_deserialize(msp._asn_ctx, asn_ctx);
				setup.mobilityStateParameters = msp;
			}

			{
				auto obj_sssf = obj_choice_setup["timeToTrigger_SF"].GetObj();
				SpeedStateScaleFactors_t sssf;
				sssf.sf_Medium = obj_sssf["sf_Medium"].GetInt64();
				sssf.sf_High = obj_sssf["sf_High"].GetInt64();
				auto asn_ctx = obj_sssf["_asn_ctx"].GetObj();
				asn_ctx_deserialize(sssf._asn_ctx, asn_ctx);
				setup.timeToTrigger_SF = sssf;
			}

			{
				auto asn_ctx = obj_choice_setup["_asn_ctx"].GetObj();
				asn_ctx_deserialize(setup._asn_ctx, asn_ctx);
			}

			ssp.choice.setup = setup;
		}

		auto asn_ctx = obj_ssp["_asn_ctx"].GetObj();
		asn_ctx_deserialize(ssp._asn_ctx, asn_ctx);
	}
	else
	{
		measConfig.speedStatePars = nullptr;
	}
}

void ICSA::msf_serialize(Value& measScaleFactor_r12_ptr, Document::AllocatorType& allocator)
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
	asn_ctx_serialize(_asn_ctx_mc_msf, msf->_asn_ctx, allocator);
	measScaleFactor_r12_ptr.AddMember("_asn_ctx", _asn_ctx_mc_msf, allocator);
}

void ICSA::msf_deserialize(MeasConfig& measConfig, Value::ConstObject& obj_mc)
{
	if (obj_mc.HasMember("measScaleFactor_r12") && obj_mc["measScaleFactor_r12"].IsObject())
	{
		auto obj_msf = obj_mc["measScaleFactor_r12"].GetObj();

		MeasConfig::MeasConfig__measScaleFactor_r12 msf;

		msf.present = static_cast<MeasConfig__measScaleFactor_r12_PR>(obj_msf["present"].GetInt());

		if (msf.present == MeasConfig__measScaleFactor_r12_PR_NOTHING
			|| msf.present == MeasConfig__measScaleFactor_r12_PR_release)
		{
			msf.choice.release = obj_msf["choice"].GetInt();
		}
		else
		{
			msf.choice.setup = obj_msf["choice"].GetInt64();
		}

		auto asn_ctx = obj_msf["_asn_ctx"].GetObj();
		asn_ctx_deserialize(msf._asn_ctx, asn_ctx);
	}
	else
	{
		measConfig.measScaleFactor_r12 = nullptr;
	}
}

void ICSA::cdrxc_serialize(Value& cdrxConfig, Document::AllocatorType& allocator)
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
		asn_ctx_serialize(_asn_ctx_s, cdrxc_s.longDRX_CycleStartOffset._asn_ctx, allocator);
		longDRX_CycleStartOffset.AddMember("_asn_ctx", _asn_ctx_s, allocator);

		setup.AddMember("longDRX_CycleStartOffset", longDRX_CycleStartOffset, allocator);


		Value shortDRX(kObjectType);
		shortDRX.AddMember("shortDRX_Cycle", static_cast<int64_t>(cdrxc_s.shortDRX->shortDRX_Cycle), allocator);
		shortDRX.AddMember("drxShortCycleTimer", static_cast<int64_t>(cdrxc_s.shortDRX->drxShortCycleTimer), allocator);

		Value _asn_ctx_sdrx(kObjectType);
		asn_ctx_serialize(_asn_ctx_sdrx, cdrxc_s.shortDRX->_asn_ctx, allocator);
		longDRX_CycleStartOffset.AddMember("_asn_ctx", _asn_ctx_sdrx, allocator);

		setup.AddMember("shortDRX", shortDRX, allocator);

		Value _asn_ctx(kObjectType);
		asn_ctx_serialize(_asn_ctx, cdrxc_s._asn_ctx, allocator);
		setup.AddMember("_asn_ctx", _asn_ctx, allocator);

		cdrxConfig.AddMember("choice", setup, allocator);
	}

	Value _asn_ctx_drxc(kObjectType);
	asn_ctx_serialize(_asn_ctx_drxc, message.cdrxConfig->_asn_ctx, allocator);
	cdrxConfig.AddMember("_asn_ctx", _asn_ctx_drxc, allocator);
}

void ICSA::cdrxc_deserialize(Value::ConstObject& icsa)
{
	if (icsa.HasMember("cdrxConfig") && icsa["cdrxConfig"].IsObject())
	{
		DRX_Config cdrxConfig;
		auto obj_cdrxc = icsa["cdrxConfig"].GetObj();

		cdrxConfig.present = static_cast<DRX_Config_PR>(obj_cdrxc["present"].GetInt());

		if (cdrxConfig.present == DRX_Config_PR_NOTHING
			|| cdrxConfig.present == DRX_Config_PR_release)
		{
			cdrxConfig.choice.release = obj_cdrxc["choice"].GetInt();
		}
		else
		{
			DRX_Config::DRX_Config_u::DRX_Config__setup setup;
			auto obj_choice_setup = obj_cdrxc["choice"].GetObj();

			setup.onDurationTimer = obj_choice_setup["onDurationTimer"].GetInt64();
			setup.drx_InactivityTimer = obj_choice_setup["drx_InactivityTimer"].GetInt64();
			setup.drx_RetransmissionTimer = obj_choice_setup["drx_RetransmissionTimer"].GetInt64();

			auto obj_longdrx = obj_choice_setup["longDRX_CycleStartOffset"].GetObj();
			ldrx_deserialize(setup, obj_longdrx);

			if (obj_choice_setup.HasMember("shortDRX") || obj_choice_setup["shortDRX"].IsObject())
			{
				DRX_Config::DRX_Config_u::DRX_Config__setup::DRX_Config__setup__shortDRX shortdrx;
				auto obj_shortdrx = obj_choice_setup["shortDRX"].GetObj();

				shortdrx.shortDRX_Cycle = obj_shortdrx["shortDRX_Cycle"].GetInt64();
				shortdrx.drxShortCycleTimer = obj_shortdrx["drxShortCycleTimer"].GetInt64();

				auto asn_ctx = obj_shortdrx["_asn_ctx"].GetObj();
				asn_ctx_deserialize(shortdrx._asn_ctx, asn_ctx);

				setup.shortDRX = &shortdrx;
			}
			else
			{
				setup.shortDRX = nullptr;
			}

			auto asn_ctx = obj_choice_setup["_asn_ctx"].GetObj();
			asn_ctx_deserialize(setup._asn_ctx, asn_ctx);
		}

		auto asn_ctx = obj_cdrxc["_asn_ctx"].GetObj();
		asn_ctx_deserialize(cdrxConfig._asn_ctx, asn_ctx);

		message.cdrxConfig = &cdrxConfig;
	}
	else
	{
		message.cdrxConfig = nullptr;
	}
}

void ICSA::ldrx_serialize(Value& longDRX_CycleStartOffset, DRX_Config__setup__longDRX_CycleStartOffset_PR present, Document::AllocatorType& allocator)
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

void ICSA::ldrx_deserialize(DRX_Config::DRX_Config_u::DRX_Config__setup& setup, Value::ConstObject& obj_longdrx)
{
	setup.longDRX_CycleStartOffset.present = static_cast<DRX_Config__setup__longDRX_CycleStartOffset_PR>(obj_longdrx["present"].GetInt());

	switch (setup.longDRX_CycleStartOffset.present)
	{
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_NOTHING:
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf10:
		setup.longDRX_CycleStartOffset.choice.sf10 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf20:
		setup.longDRX_CycleStartOffset.choice.sf20 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf32:
		setup.longDRX_CycleStartOffset.choice.sf32 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf40:
		setup.longDRX_CycleStartOffset.choice.sf40 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf64:
		setup.longDRX_CycleStartOffset.choice.sf64 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf80:
		setup.longDRX_CycleStartOffset.choice.sf80 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf128:
		setup.longDRX_CycleStartOffset.choice.sf128 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf160:
		setup.longDRX_CycleStartOffset.choice.sf160 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf256:
		setup.longDRX_CycleStartOffset.choice.sf256 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf320:
		setup.longDRX_CycleStartOffset.choice.sf320 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf512:
		setup.longDRX_CycleStartOffset.choice.sf512 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf640:
		setup.longDRX_CycleStartOffset.choice.sf640 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf1024:
		setup.longDRX_CycleStartOffset.choice.sf1024 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf1280:
		setup.longDRX_CycleStartOffset.choice.sf1280 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf2048:
		setup.longDRX_CycleStartOffset.choice.sf2048 = obj_longdrx["choice"].GetInt64();
		break;
	case DRX_Config__setup__longDRX_CycleStartOffset_PR_sf2560:
		setup.longDRX_CycleStartOffset.choice.sf2560 = obj_longdrx["choice"].GetInt64();
		break;
	default:
		break;
	}
	
	auto asn_ctx = obj_longdrx["_asn_ctx"].GetObj();
	asn_ctx_deserialize(setup.longDRX_CycleStartOffset._asn_ctx, asn_ctx);
}
