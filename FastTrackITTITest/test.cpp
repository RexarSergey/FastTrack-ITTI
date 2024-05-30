#include "pch.h"
#include "../ITTI/rapidjson/document.h"
#include "../ITTI/rapidjson/writer.h"
#include "../ITTI/rapidjson/stringbuffer.h"
//#include "../ITTI/include/PathSwitchRequest.h"
#include "../ITTI/src/PathSwitchRequest.cpp"
#include "../ITTI/src/AdmUeReleaseRequest.cpp"
#include "../ITTI/src/DrbAdditionalInfo.cpp"
#include "../ITTI/src/InitialContextSetupAcknowledgement.cpp"
#include "../ITTI/src/InitialContextSetupResponse.cpp"

TEST(PathSwitchRequestSerializeTest, TrueDocument) {
    //creating structure PathSwitchRequest
    using namespace vran::cplane::common;
    vran::s1ap::lte::PathSwitchRequest message;
    message.cp_ue_id = 1234;
    message.src_mme_ue_s1ap_id = 5678;

    ERadioAccessBearerSwitchParameter erab1;
    erab1.e_rab_id = 1;
    erab1.sgw_teid = 111;
    erab1.sgw_addr.length = 4;
    erab1.sgw_addr.buffer[0] = 192;
    erab1.sgw_addr.buffer[1] = 168;
    erab1.sgw_addr.buffer[2] = 1;
    erab1.sgw_addr.buffer[3] = 1;

    message.erab_switch_list.push_back(erab1);

    message.security_capabilities.encryption_algorithms = 0b1010;
    message.security_capabilities.integrity_algorithms = 0b1100;

    //documnet getting by serialize
    rapidjson::Document serialize_document;

    std::unique_ptr<StructureInterface> ptr = std::make_unique<PathSwitchRequest_Handler>(message);
    ptr->serialize(serialize_document);

    //expected document
    rapidjson::Document expected_document;

    expected_document.SetObject();

    rapidjson::Document::AllocatorType& allocator = expected_document.GetAllocator();
    rapidjson::Value path_switch_request_object(rapidjson::kObjectType);

    path_switch_request_object.AddMember("cp_ue_id", 1234, allocator);
    path_switch_request_object.AddMember("src_mme_ue_s1ap_id", 5678, allocator);

    rapidjson::Value erabArray(rapidjson::kArrayType);

    rapidjson::Value erabObj(rapidjson::kObjectType);
    erabObj.AddMember("e_rab_id", 1, allocator);

    rapidjson::Value sgwAddrObj(rapidjson::kObjectType);
    sgwAddrObj.AddMember("length", 4, allocator);
    rapidjson::Value sgwBufferArray(rapidjson::kArrayType);

    sgwBufferArray.PushBack(192, allocator);
    sgwBufferArray.PushBack(168, allocator);
    sgwBufferArray.PushBack(1, allocator);
    sgwBufferArray.PushBack(1, allocator);

    sgwAddrObj.AddMember("buffer", sgwBufferArray, allocator);
    erabObj.AddMember("sgw_addr", sgwAddrObj, allocator);

    erabObj.AddMember("sgw_teid", 111, allocator);
    erabArray.PushBack(erabObj, allocator);

    path_switch_request_object.AddMember("erab_switch_list", erabArray, allocator);

    rapidjson::Value securityObj(rapidjson::kObjectType);
    securityObj.AddMember("encryption_algorithms", 0b1010, allocator);
    securityObj.AddMember("integrity_algorithms", 0b1100, allocator);
    path_switch_request_object.AddMember("security_capabilities", securityObj, allocator);

    expected_document.AddMember("path_switch_request", path_switch_request_object, allocator);

    //documents to string
    rapidjson::StringBuffer buffer1, buffer2;
    rapidjson::Writer<rapidjson::StringBuffer> writer1(buffer1);
    rapidjson::Writer<rapidjson::StringBuffer> writer2(buffer2);
    expected_document.Accept(writer1);
    serialize_document.Accept(writer2);

    //test
    ASSERT_TRUE(strcmp(buffer1.GetString(), buffer2.GetString()) == 0);
}

TEST(AdmUeReleaseRequestSerializeTest, TrueDocument) {
    //creating structure AdmUeReleaseRequest
    using namespace vran::cplane::common;
    AdmUeReleaseRequest message;

    message.cause = RrcCause::CAUSE_NAS;

    message.redirectedCarrierInfo = (RedirectedCarrierInfo_t*)calloc(1, sizeof(RedirectedCarrierInfo_t));

    if (message.redirectedCarrierInfo == nullptr) {
        std::cerr << "Memory allocation failed for redirectedCarrierInfo" << std::endl;
        exit(EXIT_FAILURE);
    }

    message.redirectedCarrierInfo->present = RedirectedCarrierInfo_PR_geran;

    CarrierFreqsGERAN_t& targetGeran = message.redirectedCarrierInfo->choice.geran;

    targetGeran.startingARFCN = 128;
    targetGeran.bandIndicator = 3;
    targetGeran.followingARFCNs.present = CarrierFreqsGERAN__followingARFCNs_PR_explicitListOfARFCNs;

    targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.count = 3;
    targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array = (ARFCN_ValueGERAN_t**)calloc(3, sizeof(ARFCN_ValueGERAN_t*));

    if (targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array == nullptr) {
        std::cerr << "Memory allocation failed for targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < 3; i++) {
        targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[i] = (ARFCN_ValueGERAN_t*)calloc(1, sizeof(ARFCN_ValueGERAN_t));
        if (targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[i] == nullptr) {
            std::cerr << "Memory allocation failed for targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[" << i << "]" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    *(targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[0]) = 129;
    *(targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[1]) = 130;
    *(targetGeran.followingARFCNs.choice.explicitListOfARFCNs.list.array[2]) = 131;

    //documnet getting by serialize
    rapidjson::Document serialize_document;

    std::unique_ptr<StructureInterface> ptr = std::make_unique<AdmUeReleaseRequest_Handler>(message);
    ptr->serialize(serialize_document);

    //expected document
    rapidjson::Document expected_document;
    expected_document.SetObject();

    rapidjson::Document::AllocatorType& allocator = expected_document.GetAllocator();

    rapidjson::Value admUeReleaseRequest(rapidjson::kObjectType);

    rapidjson::Value cause(rapidjson::kObjectType);
    cause.AddMember("cause", "CAUSE_NAS", allocator);
    admUeReleaseRequest.AddMember("cause", cause, allocator);

    rapidjson::Value redirectedCarrierInfo(rapidjson::kObjectType);
    redirectedCarrierInfo.AddMember("present", 2, allocator);

    rapidjson::Value geran(rapidjson::kObjectType);
    geran.AddMember("startingARFCN", 128, allocator);
    geran.AddMember("bandIndicator", 3, allocator);

    rapidjson::Value followingARFCNs(rapidjson::kObjectType);
    followingARFCNs.AddMember("present", 1, allocator);

    rapidjson::Value explicitListOfARFCNs(rapidjson::kArrayType);
    explicitListOfARFCNs.PushBack(129, allocator);
    explicitListOfARFCNs.PushBack(130, allocator);
    explicitListOfARFCNs.PushBack(131, allocator);

    followingARFCNs.AddMember("explicitListOfARFCNs", explicitListOfARFCNs, allocator);

    geran.AddMember("followingARFCNs", followingARFCNs, allocator);
    redirectedCarrierInfo.AddMember("geran", geran, allocator);

    admUeReleaseRequest.AddMember("redirectedCarrierInfo", redirectedCarrierInfo, allocator);

    expected_document.AddMember("AdmUeReleaseRequest", admUeReleaseRequest, allocator);

    //documents to string
    rapidjson::StringBuffer buffer1, buffer2;
    rapidjson::Writer<rapidjson::StringBuffer> writer1(buffer1);
    rapidjson::Writer<rapidjson::StringBuffer> writer2(buffer2);
    expected_document.Accept(writer1);
    serialize_document.Accept(writer2);

    //test
    ASSERT_TRUE(strcmp(buffer1.GetString(), buffer2.GetString()) == 0);
}

TEST(DrbAdditionalInfoSerializeTest, TrueDocument) {
    //creating structure DrbAdditionalInfo
    using namespace vran::cplane::common;
    vran::rrc_du::DrbAdditionalInfo message;
    message.drb_id = 23u;

    message.qos_parameters.qci = 200u;

    message.qos_parameters.allocation_retention_priority.priority_level = 3u;
    message.qos_parameters.allocation_retention_priority.pre_emption_vulnerability = PreEmptionVulnerability::PRE_EMPTION_VULNERABILITY_ENABLED;
    message.qos_parameters.allocation_retention_priority.pre_emption_capability = PreEmptionCapability::PRE_EMPTION_CAPABILITY_ENABLED;

    GbrQosInformation gbr_qos_information;
    gbr_qos_information.mbr_dl = 1234u;
    gbr_qos_information.mbr_ul = 56789u;
    gbr_qos_information.gbr_dl = 5000u;
    gbr_qos_information.gbr_ul = 9000000u;

    message.qos_parameters.gbr_qos_information = gbr_qos_information;

    message.param_gtp_cu.address.length = 5u;
    for (uint8_t i = 0; i < message.param_gtp_cu.address.length; ++i) {
        message.param_gtp_cu.address.buffer[i] = i * i;
    }
    message.param_gtp_cu.teid = 32u;

    //documnet getting by serialize
    rapidjson::Document serialize_document;

    std::unique_ptr<StructureInterface> ptr = std::make_unique<DrbAdditionalInfo_Handler>(message);
    ptr->serialize(serialize_document);

    //expected document
    rapidjson::Document expected_document;
    expected_document.SetObject();

    rapidjson::Document::AllocatorType& allocator = expected_document.GetAllocator();

    rapidjson::Value drb_additional_info(rapidjson::kObjectType);
    drb_additional_info.AddMember("drb_id", 23, allocator);

    rapidjson::Value qos_parameters(rapidjson::kObjectType);
    qos_parameters.AddMember("qci", 200, allocator);

    rapidjson::Value allocation_retention_priority(rapidjson::kObjectType);
    allocation_retention_priority.AddMember("priority_level", 3, allocator);
    allocation_retention_priority.AddMember("pre_emption_vulnerability", 0, allocator);
    allocation_retention_priority.AddMember("pre_emption_capability", 0, allocator);

    qos_parameters.AddMember("allocation_retention_priority", allocation_retention_priority, allocator);

    rapidjson::Value gbr_qos_information1(rapidjson::kObjectType);
    gbr_qos_information1.AddMember("mbr_dl", 1234, allocator);
    gbr_qos_information1.AddMember("mbr_ul", 56789, allocator);
    gbr_qos_information1.AddMember("gbr_dl", 5000, allocator);
    gbr_qos_information1.AddMember("gbr_ul", 9000000, allocator);

    qos_parameters.AddMember("gbr_qos_information", gbr_qos_information1, allocator);

    drb_additional_info.AddMember("qos_parameters", qos_parameters, allocator);

    rapidjson::Value param_gtp_cu(rapidjson::kObjectType);

    rapidjson::Value address(rapidjson::kObjectType);
    address.AddMember("length", 5, allocator);

    rapidjson::Value buffer(rapidjson::kArrayType);
    buffer.PushBack(0, allocator);
    buffer.PushBack(1, allocator);
    buffer.PushBack(4, allocator);
    buffer.PushBack(9, allocator);
    buffer.PushBack(16, allocator);

    address.AddMember("buffer", buffer, allocator);

    param_gtp_cu.AddMember("address", address, allocator);
    param_gtp_cu.AddMember("teid", 32, allocator);

    drb_additional_info.AddMember("param_gtp_cu", param_gtp_cu, allocator);

    expected_document.AddMember("drb_additional_info", drb_additional_info, allocator);

    //documents to string
    rapidjson::StringBuffer buffer1, buffer2;
    rapidjson::Writer<rapidjson::StringBuffer> writer1(buffer1);
    rapidjson::Writer<rapidjson::StringBuffer> writer2(buffer2);
    expected_document.Accept(writer1);
    serialize_document.Accept(writer2);

    //test
    ASSERT_TRUE(strcmp(buffer1.GetString(), buffer2.GetString()) == 0);
}

TEST(InitialContextSetupAcknowledgementSerializeTest, TrueDocument) {
    //creating structure InitialContextSetupAcknowledgement
    asn_struct_ctx_t asn_ctx;
    asn_ctx.phase = 100;
    asn_ctx.step = -100;
    asn_ctx.context = 200;
    asn_ctx.ptr = nullptr;
    asn_ctx.left = 5;

    InitialContextSetupAcknowledgement message;
    message.is_accepted = true;

    MeasConfig mc;


    MeasConfig::MeasConfig__speedStatePars ssp;

    ssp.present = MeasConfig__speedStatePars_PR_setup;

    ssp.choice.setup.mobilityStateParameters.t_Evaluation = 1000;
    ssp.choice.setup.mobilityStateParameters.t_HystNormal = -1000;
    ssp.choice.setup.mobilityStateParameters.n_CellChangeMedium = 1000;
    ssp.choice.setup.mobilityStateParameters.n_CellChangeHigh = -1000;
    ssp.choice.setup.mobilityStateParameters._asn_ctx = asn_ctx;

    ssp.choice.setup.timeToTrigger_SF.sf_Medium = 1000;
    ssp.choice.setup.timeToTrigger_SF.sf_High = -1000;
    ssp.choice.setup.timeToTrigger_SF._asn_ctx = asn_ctx;

    ssp.choice.setup._asn_ctx = asn_ctx;
    ssp._asn_ctx = asn_ctx;
    mc.speedStatePars = new MeasConfig::MeasConfig__speedStatePars(ssp);


    MeasConfig::MeasConfig__measScaleFactor_r12 msf;

    msf.present = MeasConfig__measScaleFactor_r12_PR_release;

    msf.choice.release = 1;
    msf._asn_ctx = asn_ctx;

    mc.measScaleFactor_r12 = new MeasConfig::MeasConfig__measScaleFactor_r12(msf);


    mc._asn_ctx = asn_ctx;


    message.measConfig = new MeasConfig(mc);



    DRX_Config cdrx;

    cdrx.present = DRX_Config_PR_setup;

    cdrx.choice.setup.onDurationTimer = 1000;
    cdrx.choice.setup.drx_InactivityTimer = -1000;
    cdrx.choice.setup.drx_RetransmissionTimer = 1000;

    cdrx.choice.setup.longDRX_CycleStartOffset.present = DRX_Config__setup__longDRX_CycleStartOffset_PR_sf64;
    cdrx.choice.setup.longDRX_CycleStartOffset.choice.sf64 = 228;
    cdrx.choice.setup.longDRX_CycleStartOffset._asn_ctx = asn_ctx;

    DRX_Config_t::DRX_Config_u::DRX_Config__setup::DRX_Config__setup__shortDRX sdrx;

    sdrx.shortDRX_Cycle = 1000;
    sdrx.drxShortCycleTimer = -1000;
    sdrx._asn_ctx = asn_ctx;

    cdrx.choice.setup.shortDRX = new DRX_Config_t::DRX_Config_u::DRX_Config__setup::DRX_Config__setup__shortDRX(sdrx);


    cdrx.choice.setup._asn_ctx = asn_ctx;

    cdrx._asn_ctx = asn_ctx;

    message.cdrxConfig = new DRX_Config(cdrx);


    //documnet getting by serialize
    rapidjson::Document serialize_document;

    std::unique_ptr<StructureInterface> ptr = std::make_unique<InitialContextSetupAcknowledgement_Handler>(message);
    ptr->serialize(serialize_document);

    //expected document
    rapidjson::Document expected_document;
    expected_document.SetObject();

    rapidjson::Document::AllocatorType& allocator = expected_document.GetAllocator();

    rapidjson::Value initialContextSetupAcknowledgement(rapidjson::kObjectType);
    initialContextSetupAcknowledgement.AddMember("is_accepted", true, allocator);

    rapidjson::Value measConfig(rapidjson::kObjectType);
    rapidjson::Value speedStatePars(rapidjson::kObjectType);
    speedStatePars.AddMember("present", 2, allocator);

    rapidjson::Value choice(rapidjson::kObjectType);
    rapidjson::Value mobilityStateParameters(rapidjson::kObjectType);
    mobilityStateParameters.AddMember("t_Evaluation", 1000, allocator);
    mobilityStateParameters.AddMember("t_HystNormal", -1000, allocator);
    mobilityStateParameters.AddMember("n_CellChangeMedium", 1000, allocator);
    mobilityStateParameters.AddMember("n_CellChangeHigh", -1000, allocator);

    rapidjson::Value null;
    null.SetNull();

    rapidjson::Value _asn_ctx1(rapidjson::kObjectType);
    _asn_ctx1.AddMember("phase", 100, allocator);
    _asn_ctx1.AddMember("step", -100, allocator);
    _asn_ctx1.AddMember("context", 200, allocator);
    _asn_ctx1.AddMember("ptr", null, allocator);
    _asn_ctx1.AddMember("left", 5, allocator);
    mobilityStateParameters.AddMember("_asn_ctx", _asn_ctx1, allocator);

    choice.AddMember("mobilityStateParameters", mobilityStateParameters, allocator);

    rapidjson::Value timeToTrigger_SF(rapidjson::kObjectType);
    timeToTrigger_SF.AddMember("sf_Medium", 1000, allocator);
    timeToTrigger_SF.AddMember("sf_High", -1000, allocator);

    rapidjson::Value _asn_ctx2(rapidjson::kObjectType);
    _asn_ctx2.AddMember("phase", 100, allocator);
    _asn_ctx2.AddMember("step", -100, allocator);
    _asn_ctx2.AddMember("context", 200, allocator);
    _asn_ctx2.AddMember("ptr", null, allocator);
    _asn_ctx2.AddMember("left", 5, allocator);
    timeToTrigger_SF.AddMember("_asn_ctx", _asn_ctx2, allocator);

    choice.AddMember("timeToTrigger_SF", timeToTrigger_SF, allocator);

    rapidjson::Value _asn_ctx3(rapidjson::kObjectType);
    _asn_ctx3.AddMember("phase", 100, allocator);
    _asn_ctx3.AddMember("step", -100, allocator);
    _asn_ctx3.AddMember("context", 200, allocator);
    _asn_ctx3.AddMember("ptr", null, allocator);
    _asn_ctx3.AddMember("left", 5, allocator);
    choice.AddMember("_asn_ctx", _asn_ctx3, allocator);

    speedStatePars.AddMember("choice", choice, allocator);

    rapidjson::Value _asn_ctx4(rapidjson::kObjectType);
    _asn_ctx4.AddMember("phase", 100, allocator);
    _asn_ctx4.AddMember("step", -100, allocator);
    _asn_ctx4.AddMember("context", 200, allocator);
    _asn_ctx4.AddMember("ptr", null, allocator);
    _asn_ctx4.AddMember("left", 5, allocator);
    speedStatePars.AddMember("_asn_ctx", _asn_ctx4, allocator);

    measConfig.AddMember("speedStatePars", speedStatePars, allocator);

    //initialContextSetupAcknowledgement.AddMember("measConfig", measConfig, allocator);

    rapidjson::Value measScaleFactor_r12(rapidjson::kObjectType);
    measScaleFactor_r12.AddMember("present", 1, allocator);
    measScaleFactor_r12.AddMember("choice", 1, allocator);

    rapidjson::Value _asn_ctx5(rapidjson::kObjectType);
    _asn_ctx5.AddMember("phase", 100, allocator);
    _asn_ctx5.AddMember("step", -100, allocator);
    _asn_ctx5.AddMember("context", 200, allocator);
    _asn_ctx5.AddMember("ptr", null, allocator);
    _asn_ctx5.AddMember("left", 5, allocator);
    measScaleFactor_r12.AddMember("_asn_ctx", _asn_ctx5, allocator);

    measConfig.AddMember("measScaleFactor_r12", measScaleFactor_r12, allocator);

    rapidjson::Value _asn_ctx6(rapidjson::kObjectType);
    _asn_ctx6.AddMember("phase", 100, allocator);
    _asn_ctx6.AddMember("step", -100, allocator);
    _asn_ctx6.AddMember("context", 200, allocator);
    _asn_ctx6.AddMember("ptr", null, allocator);
    _asn_ctx6.AddMember("left", 5, allocator);
    measConfig.AddMember("_asn_ctx", _asn_ctx6, allocator);

    initialContextSetupAcknowledgement.AddMember("measConfig", measConfig, allocator);

    //initialContextSetupAcknowledgement.AddMember("_asn_ctx", _asn_ctx1, allocator);

    rapidjson::Value cdrxConfig(rapidjson::kObjectType);
    cdrxConfig.AddMember("present", 2, allocator);

    rapidjson::Value cdrxConfigChoice(rapidjson::kObjectType);
    cdrxConfigChoice.AddMember("onDurationTimer", 1000, allocator);
    cdrxConfigChoice.AddMember("drx_InactivityTimer", -1000, allocator);
    cdrxConfigChoice.AddMember("drx_RetransmissionTimer", 1000, allocator);

    rapidjson::Value longDRX_CycleStartOffset(rapidjson::kObjectType);
    longDRX_CycleStartOffset.AddMember("present", 5, allocator);
    longDRX_CycleStartOffset.AddMember("choice", 228, allocator);

    rapidjson::Value _asn_ctx7(rapidjson::kObjectType);
    _asn_ctx7.AddMember("phase", 100, allocator);
    _asn_ctx7.AddMember("step", -100, allocator);
    _asn_ctx7.AddMember("context", 200, allocator);
    _asn_ctx7.AddMember("ptr", null, allocator);
    _asn_ctx7.AddMember("left", 5, allocator);
    longDRX_CycleStartOffset.AddMember("_asn_ctx", _asn_ctx7, allocator);

    cdrxConfigChoice.AddMember("longDRX_CycleStartOffset", longDRX_CycleStartOffset, allocator);

    rapidjson::Value shortDRX(rapidjson::kObjectType);
    shortDRX.AddMember("shortDRX_Cycle", 1000, allocator);
    shortDRX.AddMember("drxShortCycleTimer", -1000, allocator);

    rapidjson::Value _asn_ctx8(rapidjson::kObjectType);
    _asn_ctx8.AddMember("phase", 100, allocator);
    _asn_ctx8.AddMember("step", -100, allocator);
    _asn_ctx8.AddMember("context", 200, allocator);
    _asn_ctx8.AddMember("ptr", null, allocator);
    _asn_ctx8.AddMember("left", 5, allocator);
    shortDRX.AddMember("_asn_ctx", _asn_ctx8, allocator);

    cdrxConfigChoice.AddMember("shortDRX", shortDRX, allocator);

    rapidjson::Value _asn_ctx9(rapidjson::kObjectType);
    _asn_ctx9.AddMember("phase", 100, allocator);
    _asn_ctx9.AddMember("step", -100, allocator);
    _asn_ctx9.AddMember("context", 200, allocator);
    _asn_ctx9.AddMember("ptr", null, allocator);
    _asn_ctx9.AddMember("left", 5, allocator);
    cdrxConfigChoice.AddMember("_asn_ctx", _asn_ctx9, allocator);

    cdrxConfig.AddMember("choice", cdrxConfigChoice, allocator);

    rapidjson::Value _asn_ctx10(rapidjson::kObjectType);
    _asn_ctx10.AddMember("phase", 100, allocator);
    _asn_ctx10.AddMember("step", -100, allocator);
    _asn_ctx10.AddMember("context", 200, allocator);
    _asn_ctx10.AddMember("ptr", null, allocator);
    _asn_ctx10.AddMember("left", 5, allocator);
    cdrxConfig.AddMember("_asn_ctx", _asn_ctx10, allocator);

    initialContextSetupAcknowledgement.AddMember("cdrxConfig", cdrxConfig, allocator);

    expected_document.AddMember("InitialContextSetupAcknowledgement", initialContextSetupAcknowledgement, allocator);


    //documents to string
    rapidjson::StringBuffer buffer1, buffer2;
    rapidjson::Writer<rapidjson::StringBuffer> writer1(buffer1);
    rapidjson::Writer<rapidjson::StringBuffer> writer2(buffer2);
    expected_document.Accept(writer1);
    serialize_document.Accept(writer2);
    std::cout << buffer1.GetString();
    //std::cout << buffer2.GetString();
    //test
    ASSERT_TRUE(strcmp(buffer1.GetString(), buffer2.GetString()) == 0);
}


TEST(InitialContextSetupResponseSerializeTest, TrueDocument) {
    //creating structure InitialContextSetupResponse
    using namespace vran::cplane::common;
    using namespace vran::s1ap::lte;
    InitialContextSetupResponse message;
    message.cp_ue_id = 1;

    ERadioAccessBearerParameter e1;
    ERadioAccessBearerParameter e2;
    TransportLayerAddress t1;
    TransportLayerAddress t2;

    t1.length = 2;
    for (int i = 0; i < 20; ++i) {
        t1.buffer[i] = i;

    }
    t2.length = 3;
    for (int i = 0; i < 20; ++i) {
        t2.buffer[i] = i + 1;
    }

    e1.address = t1;
    e2.address = t2;
    e1.teid = 4;
    e2.teid = 6;

    message.erab_setup_list.insert({ 2, e1 });
    message.erab_setup_list.insert({ 3, e2 });

    ERadioAccessBearerCause ec1;
    ERadioAccessBearerCause ec2;
    ec1.cause = RrcCause::CAUSE_NOTHING;
    ec2.cause = RrcCause::CAUSE_NAS;
    ec1.cause_value = 0;
    ec2.cause_value = 3;
    ec1.e_rab_id = 0;
    ec2.e_rab_id = 3;

    message.erab_failed_list.push_back(ec1);
    message.erab_failed_list.push_back(ec2);

    //documnet getting by serialize
    rapidjson::Document serialize_document;

    std::unique_ptr<StructureInterface> ptr = std::make_unique<InitialContextSetupResponse_Handler>(message);
    ptr->serialize(serialize_document);

    //expected document
    rapidjson::Document expected_document;
    expected_document.SetObject();

    rapidjson::Document::AllocatorType& allocator = expected_document.GetAllocator();

    rapidjson::Value initialContextSetupResponse(rapidjson::kObjectType);
    initialContextSetupResponse.AddMember("cp_ue_id", 1, allocator);

    rapidjson::Value erabSetupList(rapidjson::kArrayType);

    rapidjson::Value erab1(rapidjson::kObjectType);
    erab1.AddMember("key", 2, allocator);

    rapidjson::Value value1(rapidjson::kObjectType);
    value1.AddMember("address", rapidjson::Value(rapidjson::kObjectType).AddMember("length", 2, allocator)
        .AddMember("buffer", rapidjson::Value(rapidjson::kArrayType).PushBack(0, allocator).PushBack(1, allocator), allocator), allocator);
    value1.AddMember("teid", 4, allocator);

    erab1.AddMember("value", value1, allocator);

    rapidjson::Value erab2(rapidjson::kObjectType);
    erab2.AddMember("key", 3, allocator);

    rapidjson::Value value2(rapidjson::kObjectType);
    value2.AddMember("address", rapidjson::Value(rapidjson::kObjectType).AddMember("length", 3, allocator)
        .AddMember("buffer", rapidjson::Value(rapidjson::kArrayType).PushBack(1, allocator).PushBack(2, allocator).PushBack(3, allocator), allocator), allocator);
    value2.AddMember("teid", 6, allocator);

    erab2.AddMember("value", value2, allocator);

    erabSetupList.PushBack(erab1, allocator);
    erabSetupList.PushBack(erab2, allocator);

    rapidjson::Value erabFailedList(rapidjson::kArrayType);

    rapidjson::Value erabFailed1(rapidjson::kObjectType);
    erabFailed1.AddMember("e_rab_id", 0, allocator);
    erabFailed1.AddMember("cause", 0, allocator);
    erabFailed1.AddMember("cause_value", 0, allocator);

    rapidjson::Value erabFailed2(rapidjson::kObjectType);
    erabFailed2.AddMember("e_rab_id", 3, allocator);
    erabFailed2.AddMember("cause", 3, allocator);
    erabFailed2.AddMember("cause_value", 3, allocator);

    erabFailedList.PushBack(erabFailed1, allocator);
    erabFailedList.PushBack(erabFailed2, allocator);

    initialContextSetupResponse.AddMember("erab_setup_list", erabSetupList, allocator);
    initialContextSetupResponse.AddMember("erab_failed_list", erabFailedList, allocator);

    expected_document.AddMember("initial_context_setup_response", initialContextSetupResponse, allocator);

    //documents to string
    rapidjson::StringBuffer buffer1, buffer2;
    rapidjson::Writer<rapidjson::StringBuffer> writer1(buffer1);
    rapidjson::Writer<rapidjson::StringBuffer> writer2(buffer2);
    expected_document.Accept(writer1);
    serialize_document.Accept(writer2);

    //test
    std::cout << buffer1.GetString();
    ASSERT_TRUE(strcmp(buffer1.GetString(), buffer2.GetString()) == 0);
}
