#ifndef TYPES_HPP
#define TYPES_HPP

#include "optional.hpp"

#include "asn1c_build/EstablishmentCause.h"
#include "asn1c_build/MeasConfig.h"
#include "asn1c_build/RedirectedCarrierInfo.h"
#include "asn1c_build/IdleModeMobilityControlInfo.h"
#include "asn1c_build/DRX-Config.h"

#include <cstdint>
#include <cstddef>
#include <array>
#include <vector>
#include <unordered_map>

namespace vran
{
    using srb_id_t   = uint8_t; // SRB Identity [0-2], mapping one by one to lcid for SRB

    using enb_id_t      = uint32_t;
    using cell_id_t     = uint8_t;
    using du_id_t       = uint64_t; // ng-eNB-DU ID INTEGER(0 .. 2^36-1)
    using phy_cell_id_t = uint16_t;
    using mme_code_t    = uint8_t;
    // PHY Identities
    using band_t        = uint8_t;
    using bandwidth_t   = uint8_t;
    using earfcn_t      = uint32_t;

    //UE Identities
    //!\todo ue_id_t to remove! depricated type
    using ue_id_t        = uint32_t; /// 16 rrc, 32 w1, 24 s1, 12 x2, 32 e1

    using cu_ue_id_t     = uint32_t; //!< UE ID type for RRC_CU, UPLANE, ADM and others
    using du_ue_id_t     = uint32_t; //!< UE ID type for RRC_DU, GTP_DU and others
    using s1_ue_id_t     = uint32_t; //!< UE ID type for S1AP layer, 0-2^24-1
    using w1_ue_id_t     = uint32_t; //!< UE ID type for W1AP layer 0-2^32-1;
    using e1_ue_id_t     = uint32_t; //!< UE ID type for E1AP layer 0-2^32-1;
    using x2_ue_id_t     = uint16_t; //!< UE ID type for E1AP layer 0-2^12-1;

    using rnti_t         = uint16_t;
    using tac_t          = uint16_t;
    using m_tmsi_t       = uint32_t;
    using random_value_t = uint64_t;

    //Radio Bearers Identities
    using lcid_t     = uint8_t; // Logical channel ID [0-10] (SRB0=0, SRB1=1, SRB2=2, DRB1=3 ... , DRB8=10 : may be remapped!)

    using srb_id_t   = uint8_t; // SRB Identity [0-2], mapping one by one to lcid for SRB

    using e_rab_id_t = uint8_t; // E-RAB ID from S1AP[0-15] mapping on EPS Bearer Identity on UE
    using drb_id_t   = uint8_t; // DRB-ID[1-32], DRB-Identity (MAIN identity for other levels!!), mapping on E-RAB ID, Logical Channel ID
    using qci_t      = uint8_t; // QoS Class Identifier[0-255]
    using teid_t     = uint32_t;// Tunnel Endpoint Identifier

//    using eps_bearer_id_t     = uint8_t;  //eps bearer id

    // TTI
    using frame_t    = uint16_t; // Frame Number [0-1023]
    using subframe_t = uint8_t;  // Subframe number [0-9]

    using sdu_size_t = size_t;
    using mui_t      = uint32_t;
    using ncc_t      = uint8_t;

    struct gummei_t
    {
        uint16_t mcc;
        uint16_t mnc;
        uint8_t  mnc_len;
        uint8_t  mme_code;
        uint16_t mme_group_id;
    };
    
    struct imsi_t
    {
        static const uint8_t vIMSI_LENGTH = 16;
        uint8_t  buffer[vIMSI_LENGTH];
        uint8_t  length;
    };

    struct s_tmsi_t
    {
        mme_code_t  mme_code;
        m_tmsi_t    m_tmsi;
    };

    enum class ue_identities_presence_mask_t
    {
        random_value   = 0x00,
        s_tmsi         = 0x01,
        gummei         = 0x02
    } ;

    struct ue_identity_t
    {
        uint8_t presence_mask;
        union
        {
            random_value_t random_value;
            s_tmsi_t s_tmsi;
        };
        gummei_t gummei;
    };

    struct plmn_identity_t
    {
        uint16_t mcc;
        uint16_t mnc;
        uint8_t  mnc_digit_length;
    };
    struct tracking_area_identity_t
    {
        plmn_identity_t plmn;
        tac_t           tac;
    };

    struct phy_common_values_t
    {
        phy_cell_id_t phy_cell_id;
        uint8_t       eutra_band;
        int           dl_cp;
        int           ul_cp;
        int           tx_prots;
        int           rx_ports;
        int           dl_bandwidth;
        uint64_t      dl_carrier_freq;
        uint64_t      ul_carrier_freq; //???
    };

    enum pdcp_transmission_mode_t
    {
        PDCP_TRANSMISSION_MODE_UNKNOWN     = 0,
        PDCP_TRANSMISSION_MODE_CONTROL     = 1,
        PDCP_TRANSMISSION_MODE_DATA        = 2,
        PDCP_TRANSMISSION_MODE_TRANSPARENT = 3
    };

    enum pdcp_confirm_mode_t
    {
        PDCP_CONFIRM_NO,
        PDCP_CONFIRM_YES
    };

    static const uint16_t vMAX_NUM_ENB_CELLS               = 256;
    static const uint8_t  vMAX_NUM_INTEGRITY_PRIORITY_LIST = 3;
    static const uint8_t  vMAX_NUM_CIPHERING_PRIORITY_LIST = 3;


} // end namespace vran

namespace vran
{
namespace cplane
{
namespace common
{

using vran::common::common::optional;

using DrbIdList = std::vector<drb_id_t>;
using SrbIdList = std::vector<srb_id_t>;

// using SecurityKey = std::array<uint8_t, vran::lte::vSECURITY_KEY_LENGTH>;

/*! \enum ProtocolType
 *  \brief Enumerates types of protocols in trace messages
 */
enum class ProtocolType : std::uint8_t
{
    NONE,
    RRC,
    S1AP,
    W1AP,
};

/*! \enum RrcCellType
 *  \brief Enumerates context types
 */
enum class RrcCellType
{
    LTE,  //!< LTE cell
    NBIOT, //!< NB-IoT cell
    LTE_TEST,
};

/*! \enum CsfbType
 *  \brief Enumerates CSFB types
 */
enum class CsfbType
{
    NONE,         //!< No CSFB required
    REQUIRED,     //!< CSFB required
    HIGH_PRIORITY //!< High priority CSFB required
};

enum class HandoverType : uint8_t
{
    INTRA_LTE,
    LTE_TO_UTRAN,
    LTE_TO_GERAN,
    UTRAN_TO_LTE,
    GRAN_TO_LTE
};

enum class DirectForwardingPathAvailability : uint8_t
{
    AVAILABLE,
    NOT_AVAILABLE
};

template <typename TimerControlElement>
struct TimerControl
{
    std::size_t         _id;
    TimerControlElement _arg; 
};

/*! \struct SecurityCapabilities
 *  \brief Define configuration of encryption and integrity algorithms
 */
struct SecurityCapabilities
{
    uint16_t encryption_algorithms; //!< Encryption algorithms configuration
    uint16_t integrity_algorithms;  //!< Integrity algorithms configuration
};

struct custom_pdu_t
{
    uint8_t    *payload;
    sdu_size_t size;
};

struct RrcMessageTransfer
{
    srb_id_t     srb_id;
    custom_pdu_t pdu;
};

using bitrate_t        = uint64_t;
using priority_level_t = uint8_t;
using vran::common::common::optional;

/*! \enum PreEmptionCapability
 *  \brief Enumerates available capabilities triggers
 */
enum PreEmptionCapability
{
    PRE_EMPTION_CAPABILITY_ENABLED  = 0, //!< Preemtion is enabled
    PRE_EMPTION_CAPABILITY_DISABLED = 1, //!< Preemtion is disabled
    PRE_EMPTION_CAPABILITY_MAX,          //!< Maximum preemtion is allowed
};

/*! \enum PreEmptionVulnerability
 *  \brief Enumerates available vulnaraibilities triggers
 */
enum PreEmptionVulnerability
{
    PRE_EMPTION_VULNERABILITY_ENABLED  = 0, //!< Preemtion is enabled
    PRE_EMPTION_VULNERABILITY_DISABLED = 1, //!< Preemtion is disabled
    PRE_EMPTION_VULNERABILITY_MAX,          //!< Maximum preemtion is allowed
};

/*! \struct AllocationRetentionPriority
 *  \brief Keeps values for allocation retention priorities
 */
struct AllocationRetentionPriority
{
    priority_level_t        priority_level;            //!< Allocation priority level
    PreEmptionVulnerability pre_emption_vulnerability; //!< Trigger for vulnarabilities preemtion
    PreEmptionCapability    pre_emption_capability;    //!< Trigger for capabilities preemtion
};

struct GbrQosInformation
{
    bitrate_t mbr_dl;
    bitrate_t mbr_ul;
    bitrate_t gbr_dl;
    bitrate_t gbr_ul;
};

/*! \struct ErabQosParameter
 *  \brief Contains E-RAB Quility of Service parameter values
 */
struct ErabQosParameter
{
    qci_t qci; //!< QoS class identifiers

    AllocationRetentionPriority allocation_retention_priority; //!< Keeps values for allocation retention priorities
    optional<GbrQosInformation> gbr_qos_information;           //!< Keeps QoS information for GBR qci, for non-GBR should be nullptr
};

struct AggregateMaxBitrate
{
    bitrate_t br_ul;
    bitrate_t br_dl;
};

namespace lte
{
    static const uint8_t  vCCCH_PAYLOAD_SIZE_MAX = 128;
    static const uint16_t vDCH_PAYLOAD_SIZE_MAX  = 4096;
    static const uint8_t  vSRB_MAX_NUM           = 2;
    static const uint16_t vNB_MAX_QCI            = 256;

    //------------------------

    //!  \brief CCCH payload for LTE
    struct ccch_pdu_t
    {
        uint8_t    payload[vCCCH_PAYLOAD_SIZE_MAX];
        sdu_size_t size;
    };

    using dcch_pdu_t         = custom_pdu_t;
    using nas_pdu_t          = custom_pdu_t;
    using ue_radio_cap_pdu_t = custom_pdu_t;
} // end namespace lte

} // namespace common
} // namespace cplane
} // namespace vran

namespace vran
{
namespace lte
{
    static const uint8_t  vPCCH_PAYLOAD_SIZE_MAX = 128;

    static const uint8_t   vNB_RB_MAX            = 14;//LTE_maxDRB+3; see in TS 36.331
    static const uint8_t   vNB_DRB_MAX           = 8; // Only 8 LCIDs for DRB in LTE
    static const uint8_t   vGTPV1U_MAX_BEARERS_PER_UE = 32;//max_val_LTE_DRB_Identity; see in TS 36.331
    static const uint8_t   vSECURITY_KEY_LENGTH           = 32;
    static const uint8_t   vTRUNCATED_SECURITY_KEY_LENGTH = 16;
    //------------------------

    //!  \brief MIB payload for LTE
    struct mib_pdu_t
    {
        uint8_t payload[3];
    };

    //! \brief PCCH payload for LTE
    struct pcch_pdu_t
    {
        uint8_t    payload[vPCCH_PAYLOAD_SIZE_MAX];
        sdu_size_t size;
    };

    struct eutra_band_info_t
    {
        uint8_t  band;
        uint16_t dl_freq_low_100khz; // Frequency in hundreds of kHz
        earfcn_t dl_min_earfcn;
        earfcn_t dl_max_earfcn;
        uint16_t ul_freq_low_100khz; // Frequency in hundreds of kHz
        earfcn_t ul_min_earfcn;
        earfcn_t ul_max_earfcn;
    };

    // Table 5.7.3-1: E-UTRA channel numbers. TS 136.101
    // band, UL low freq, UL min EARFCN, UL max EARFCN, DL low freq, DL min EARFCN, DL max EARFCN
    static const eutra_band_info_t eutra_bands_info_table[] = {
        { 1, 21100,     0,   599, 19200,  18000,  18599},
        { 2, 19300,   600,  1199, 18500,  18600,  19199},
        { 3, 18050,  1200,  1949, 17100,  19200,  19949},
        { 4, 21100,  1950,  2399, 17100,  19950,  20399},
        { 5,  8690,  2400,  2649,  8240,  20400,  20649},
        { 6,  8750,  2650,  2749,  8300,  20650,  20749},
        { 7, 26200,  2750,  3449, 25000,  20750,  21449},
        { 8,  9250,  3450,  3799,  8800,  21450,  21799},
        { 9, 18449,  3800,  4149, 17499,  21800,  22149},
        {10, 21100,  4150,  4749, 17100,  22150,  22749},
        {11, 14759,  4750,  4949, 14279,  22750,  22949},
        {12,  7290,  5010,  5179,  6990,  23010,  23179},
        {13,  7460,  5180,  5279,  7770,  23180,  23279},
        {14,  7580,  5280,  5379,  7880,  23280,  23379},
        {17,  7340,  5730,  5849,  7040,  23730,  23849},
        {18,  8600,  5850,  5999,  8150,  23850,  23999},
        {19,  8750,  6000,  6149,  8300,  24000,  24149},
        {20,  7910,  6150,  6449,  8320,  24150,  24449},
        {21, 14959,  6450,  6599, 14479,  24450,  24599},
        {22, 35100,  6600,  7399, 34100,  24600,  25399},
        {23, 21800,  7500,  7699, 20000,  25500,  25699},
        {24, 15250,  7700,  8039, 16265,  25700,  26039},
        {25, 19300,  8040,  8689, 18500,  26040,  26689},
        {26,  8590,  8690,  9039,  8140,  26690,  27039},
        {27,  8520,  9040,  9209,  8070,  27040,  27209},
        {28,  7580,  9210,  9659,  7030,  27210,  27659},
        {29,  7170,  9660,  9769,     0,      0,      0},
        {30, 23500,  9770,  9869, 23050,  27660,  27759},
        {31,  4625,  9870,  9919,  4525,  27760,  27809},
        {32, 14520,  9920, 10359,     0,      0,      0},
        {33, 19000, 36000, 36199, 19000,  36000,  36199},
        {34, 20100, 36200, 36349, 20100,  36200,  36349},
        {35, 18500, 36350, 36949, 18500,  36350,  36949},
        {36, 19300, 36950, 37549, 19300,  36950,  37549},
        {37, 19100, 37550, 37749, 19100,  37550,  37749},
        {38, 25700, 37750, 38249, 25700,  37750,  38249},
        {39, 18800, 38250, 38649, 18800,  38250,  38649},
        {40, 23000, 38650, 39649, 23000,  38650,  39649},
        {41, 24960, 39650, 41589, 24960,  39650,  41589},
        {42, 34000, 41590, 43589, 34000,  41590,  43589},
        {43, 36000, 43590, 45589, 36000,  43590,  45589},
        {44,  7030, 45590, 46589,  7030,  45590,  46589},
        {45, 14470, 46590, 46789, 14470,  46590,  46789},
        {46, 51500, 46790, 54539, 51500,  46790,  54539},
        {65, 21100, 65536, 67835, 19200, 131072, 131971},
        {66, 21100, 66436, 67335, 17100, 131972, 132671},
        {67,  7380, 67336, 67535,     0,      0,      0},
        {68,  7530, 67536, 67835,  6980, 132672, 132971}
    };
    static const uint8_t EUTRA_BANDS_INFO_TABLE_SIZE = sizeof(eutra_bands_info_table) / sizeof(eutra_band_info_t);

}//end namespace lte
}//end namespace vran

namespace vran
{
namespace cplane
{
namespace common
{

using rrc_cause_value_t = uint8_t;

enum class RrcCause
{
    CAUSE_NOTHING, /* No components present */
    CAUSE_RADIO_NETWORK,
    CAUSE_TRANSPORT,
    CAUSE_NAS,
    CAUSE_PROTOCOL,
    CAUSE_MISC,
    CAUSE_EXTENTION,
};

enum class RrcCauseRadioNetwork
{
    UNSPECIFIED                                                     = 0,
    TX2RELOCOVERALL_EXPIRY                                          = 1,
    SUCCESSFUL_HANDOVER                                             = 2,
    RELEASE_DUE_TO_EUTRAN_GENERATED_REASON                          = 3,
    HANDOVER_CANCELLED                                              = 4,
    PARTIAL_HANDOVER                                                = 5,
    HO_FAILURE_IN_TARGET_EPC_ENB_OR_TARGET_SYSTEM                   = 6,
    HO_TARGET_NOT_ALLOWED                                           = 7,
    TS1RELOCOVERALL_EXPIRY                                          = 8,
    TS1RELOCPREP_EXPIRY                                             = 9,
    CELL_NOT_AVAILABLE                                              = 10,
    UNKNOWN_TARGETID                                                = 11,
    NO_RADIO_RESOURCES_AVAILABLE_IN_TARGET_CELL                     = 12,
    UNKNOWN_MME_UE_S1AP_ID                                          = 13,
    UNKNOWN_ENB_UE_S1AP_ID                                          = 14,
    UNKNOWN_PAIR_UE_S1AP_ID                                         = 15,
    HANDOVER_DESIRABLE_FOR_RADIO_REASON                             = 16,
    TIME_CRITICAL_HANDOVER                                          = 17,
    RESOURCE_OPTIMISATION_HANDOVER                                  = 18,
    REDUCE_LOAD_IN_SERVING_CELL                                     = 19,
    USER_INACTIVITY                                                 = 20,
    RADIO_CONNECTION_WITH_UE_LOST                                   = 21,
    LOAD_BALANCING_TAU_REQUIRED                                     = 22,
    CS_FALLBACK_TRIGGERED                                           = 23,
    UE_NOT_AVAILABLE_FOR_PS_SERVICE                                 = 24,
    RADIO_RESOURCES_NOT_AVAILABLE                                   = 25,
    FAILURE_IN_RADIO_INTERFACE_PROCEDURE                            = 26,
    INVALID_QOS_COMBINATION                                         = 27,
    INTERRAT_REDIRECTION                                            = 28,
    INTERACTION_WITH_OTHER_PROCEDURE                                = 29,
    UNKNOWN_E_RAB_ID                                                = 30,
    MULTIPLE_E_RAB_ID_INSTANCES                                     = 31,
    ENCRYPTION_AND_OR_INTEGRITY_PROTECTION_ALGORITHMS_NOT_SUPPORTED = 32,
    S1_INTRA_SYSTEM_HANDOVER_TRIGGERED                              = 33,
    S1_INTER_SYSTEM_HANDOVER_TRIGGERED                              = 34,
    X2_HANDOVER_TRIGGERED                                           = 35,
    /*
     * ENUMERATION IS EXTENSIBLE
     */
    REDIRECTION_TOWARDS_1XRTT  = 36,
    NOT_SUPPORTED_QCI_VALUE    = 37,
    INVALID_CSG_ID             = 38,
    RELEASE_DUE_TO_PRE_EMPTION = 39
};

enum class RrcCauseTransport
{
    TRANSPORT_RESOURCE_UNAVAILABLE = 0,
    UNSPECIFIED                    = 1
    /*
     * ENUMERATION IS EXTENSIBLE
     */
};

enum class RrcCauseNas
{
    NORMAL_RELEASE         = 0,
    AUTHENTICATION_FAILURE = 1,
    DETACH                 = 2,
    UNSPECIFIED            = 3,
    /*
     * ENUMERATION IS EXTENSIBLE
     */
    CSG_SUBSCRIPTION_EXPIRY = 4
};

enum class RrcCauseProtocol
{
    TRANSFER_SYNTAX_ERROR                             = 0,
    ABSTRACT_SYNTAX_ERROR_REJECT                      = 1,
    ABSTRACT_SYNTAX_ERROR_IGNORE_AND_NOTIFY           = 2,
    MESSAGE_NOT_COMPATIBLE_WITH_RECEIVER_STATE        = 3,
    SEMANTIC_ERROR                                    = 4,
    ABSTRACT_SYNTAX_ERROR_FALSELY_CONSTRUCTED_MESSAGE = 5,
    UNSPECIFIED                                       = 6
    /*
     * Enumeration is extensible
     */
};

enum class RrcCauseMisc
{
    CONTROL_PROCESSING_OVERLOAD                = 0,
    NOT_ENOUGH_USER_PLANE_PROCESSING_RESOURCES = 1,
    HARDWARE_FAILURE                           = 2,
    OM_INTERVENTION                            = 3,
    UNSPECIFIED                                = 4,
    UNKNOWN_PLMN                               = 5
    /*
     * ENUMERATION IS EXTENSIBLE
     */
};

// FIXME: SYNC_WITH_ASN LTE_EstablishmentCause

/* Provides the establishment cause for the RRC connection request as provided
 * by the upper layers. W.r.t. the cause value names: highPriorityAccess
 * concerns AC11..AC15, ‘mt’ stands for ‘Mobile Terminating’ and ‘mo’ for
 * 'Mobile Originating'. Defined in TS 36.331.
 */
enum class RrcEstablishmentCause {
  RRC_CAUSE_EMERGENCY             = 0x0,
  RRC_CAUSE_HIGH_PRIO_ACCESS      = 0x1,
  RRC_CAUSE_MT_ACCESS             = 0x2,
  RRC_CAUSE_MO_SIGNALLING         = 0x3,
  RRC_CAUSE_MO_DATA               = 0x4,
  RRC_CAUSE_DELAY_TOLERANT_ACCESS = 0x5,
  RRC_CAUSE_LAST
};

struct DrbIdentity
{
    static const e_rab_id_t UNUSED_ERAB_ID = 0xff;
    static const drb_id_t   UNUSED_DRB_ID  = 0xff;
    static const lcid_t     UNUSED_LC_ID   = 0xff;

    drb_id_t    drb_id;  //!< DRB-Identity [0-32]
    lcid_t      lcid;    //!< Logical channel id

    e_rab_id_t  erab_id; //!< E-RAB ID ak GTP Evolved Packet System Bearer Identifier
};

enum DrbActivity
{
    ACTIVE,
    NOT_ACTIVE
};

/*! \struct TransportLayerAddress
 *  \brief Length of the transport layer address buffer in bytes.
 * S1AP layer received a bit string<1..160> containing one of the following addresses:
 * ipv4, ipv6, or ipv4 and ipv6.
 * The layer doesn't interpret the buffer but silently forward it to S1-U.
 */
struct TransportLayerAddress // moved cplane
{
    uint8_t length;     //!< Address length
    uint8_t buffer[20]; //!< Buffer containing the addres in network byte order
};

/*! \struct ERadioAccessBearerParameter
 *  \brief Contains values for E-RAB parameter
 */
struct ERadioAccessBearerParameter
{
    TransportLayerAddress address; //!< The transport layer address for the IP packets
    teid_t                teid;    //!< Tunnel endpoint identifier
};
using ErabsToSetup    = std::unordered_map<e_rab_id_t, ERadioAccessBearerParameter>;
using ErabsToModify   = ErabsToSetup;
using ErabsToNoModify = ErabsToSetup;
using ErabsId         = std::vector<e_rab_id_t>;

/*! \struct ERadioAccessBearerFailed
 *  \brief Contains values for failed E-RAB
 */
struct ERadioAccessBearerCause
{
    e_rab_id_t e_rab_id; //!< Unique e_rab_id for the UE

    RrcCause          cause;       //!< E-RAB fail cause group
    rrc_cause_value_t cause_value; //!< E-RAB fail specific cause value belongs this group
};
using ErabsToFail    = std::vector<ERadioAccessBearerCause>;
using ErabsToRelease = ErabsToFail;

/*! \enum GtpuRequestStatus
 *  \brief Enumerates GTPU request status
 */
enum GtpuRequestStatus
{
    REQUEST_STATUS_SUCCESS = 0x0, //!< GTPU success request status
    REQUEST_STATUS_FAILED  = 0xFF //!< GTPU failed request status
};

struct DrbActivityInfo
{
    e_rab_id_t  id;
    DrbActivity activity;
};
using DrbActivityInfoList = std::vector<DrbActivityInfo>;

struct PdcpCount
{
    uint32_t sn;
    uint32_t hfn;
};

struct PdcpSnStatusInformation
{
    drb_id_t  rb_id;
    PdcpCount ul_count_value;
    PdcpCount dl_count_value;
};

struct PdcpSnStatusList
{
    uint8_t drb_to_update_num;
    PdcpSnStatusInformation drb_pdcp_sn_status[vran::lte::vNB_DRB_MAX];
};

struct UPSecurityInformation
{
    uint8_t  security_algorithm; //Security Algorithm
    uint8_t  kUPenc[vran::lte::vTRUNCATED_SECURITY_KEY_LENGTH]; // User Plane Security Keys
};

/*! \struct ERadioAccessBearerSwitchParameter
 *  \brief Contains values E-RAB switch parameters
 */
struct ERadioAccessBearerSwitchParameter
{
    e_rab_id_t            e_rab_id; //!< Unique e_rab_id for the UE
    TransportLayerAddress sgw_addr; //!< The transport layer address for the IP packets
    teid_t                sgw_teid; //!< S-GW Tunnel endpoint identifier
};
using ErabsSwitchParameters = std::vector<ERadioAccessBearerSwitchParameter>;

enum class PdcpSnSize
{
    LEN_12_BITS = 0,
    LEN_7_BITS
};

enum class RlcMode
{
    UM_BIDIRECTIONAL = 0,
    UM_UNIDIRECTIONAL_DL,
    UM_UNIDIRECTIONAL_UL,
    AM
};

} // namespace common
} // namespace cplane
} // namespace vran

namespace vran
{
    namespace rrc_cu
    {
        namespace lte
        {
            struct InitialContextSetupAcknowledgement
            {
                bool           is_accepted; //!< ADM response value allowing/disallowing the requested actions
                MeasConfig* measConfig;
                DRX_Config* cdrxConfig;
            };

            /*! \struct ERABSetupAcknowledgement
            *  \brief ADM message with acknoledgement status of initial Context setup message
            */
            struct ERABSetupAcknowledgement
            {
                bool           is_accepted; //!< ADM response value allowing/disallowing the requested actions
                MeasConfig* measConfig;
            };

            /*! \struct ERABModifyAcknowledgement
            *  \brief ADM message with acknoledgement status of initial Context setup message
            */
            struct ERABModifyAcknowledgement
            {
                bool           is_accepted; //!< ADM response value allowing/disallowing the requested actions
                MeasConfig* measConfig;
            };

            /*! \struct UeBlindRequest
            *  \brief ADM message requesting Blind intra eNB HO
            */
            struct UeBlindRequest
            {
                cell_id_t       target_cell_id; //!< TBD
                MeasConfig* measConfig;
            };

            /*! \struct AdmUeReleaseRequest
            *  \brief ADM message requesting UE release
            */
            struct AdmUeReleaseRequest
            {
                vran::cplane::common::RrcCause          cause;
                vran::cplane::common::rrc_cause_value_t cause_value;

                RedirectedCarrierInfo_t       *redirectedCarrierInfo;
                IdleModeMobilityControlInfo_t *idleModeMobilityControlInfo;
            };

            struct AdmUeCsfbRequest
            {
                vran::cplane::common::RrcCause          cause;
                vran::cplane::common::rrc_cause_value_t cause_value;

                RedirectedCarrierInfo_t       *redirectedCarrierInfo;
                IdleModeMobilityControlInfo_t *idleModeMobilityControlInfo;
            };
        }
    }
}

namespace vran
{
namespace s1ap
{

struct RrcResetCommand
{
    // identity NONE
    std::vector<s1_ue_id_t> ue_id_list;
};

struct RrcResetAck
{
    // identity mme_local_id
    std::vector<s1_ue_id_t> ue_id_list;
};

struct S1apConfigurationUpdateAck
{
    // identity mme_local_id
    std::vector<s1_ue_id_t> ue_id_list;
};

} // namespace s1ap
} // namespace vran

namespace vran
{
namespace s1ap
{
namespace lte // lte including NB-IoT
{

using namespace vran::cplane::common;
using namespace vran::cplane::common::lte;

//  <- E-RAB SETUP REQUEST.
struct ErabSetupResponse
{
    cu_ue_id_t   cp_ue_id;
    ErabsToSetup erab_setup_list;
    ErabsToFail  erab_failed_list;
};

struct ErabModifyResponse
{
    cu_ue_id_t  cp_ue_id;
    ErabsId     erab_modify_id_list;
    ErabsToFail erab_failed_list;
};

struct ErabReleaseResponse
{
    cu_ue_id_t  cp_ue_id;
    ErabsId     erab_release_id_list;
    ErabsToFail erab_failed_list;
};

struct ErabReleaseIndication
{
    cu_ue_id_t  cp_ue_id;
    ErabsToFail erab_release_list;
};

struct ErabModificationIndication
{
    cu_ue_id_t      cp_ue_id;
    ErabsToModify   erab_modify_list;
    ErabsToNoModify erab_no_modify_list;
};

struct InitialContextSetupFail
{
    cu_ue_id_t        cp_ue_id;
    RrcCause          cause;
    rrc_cause_value_t cause_value;
};

struct UeContextReleaseComplete
{
    cu_ue_id_t cp_ue_id;
    bool detached_from_mme;
};

struct UeContextReleaseRequest
{
    cu_ue_id_t        cp_ue_id;
    RrcCause          cause;
    rrc_cause_value_t cause_value;
};

struct UeContextModifyResponse
{
    //!\todo need to fill
    cu_ue_id_t cp_ue_id;
};

struct UeContextModifyFail
{
    cu_ue_id_t        cp_ue_id;
    RrcCause          cause;
    rrc_cause_value_t cause_value;
};

struct UeContextModificationIndication
{
    //!\todo fill  CSG Membership Info TS 136 413, 9.1.4.13
    cu_ue_id_t cp_ue_id;
};

struct UeContextSuspendRequest
{
    //!\todo fill : TS 136 413, 9.1.4.15
    cu_ue_id_t cp_ue_id;
};

struct UeContextResumeRequest
{
    //!\todo fill : TS 136 413, 9.1.4.17
    cu_ue_id_t cp_ue_id;
};

struct HandoverRequired
{
    cu_ue_id_t cp_ue_id;
    cell_id_t source_cell_id;

    enb_id_t                         target_enb_id;
    tracking_area_identity_t         target_enb_tai;
    cell_id_t                        target_cell_id;
    HandoverType                     handover_type;
    DirectForwardingPathAvailability dfpa;
    RrcCause                         cause;
    rrc_cause_value_t                cause_value;

    custom_pdu_t container;
    ErabsId      erab_setup_id_list;
};

struct HandoverRequestAck
{
    cu_ue_id_t               cp_ue_id;
    cell_id_t                cell_id;
    tracking_area_identity_t tai;

    ErabsToSetup erab_admitted_list;
    ErabsToFail  erab_failed_list;

    custom_pdu_t container;
};

struct HandoverFailure
{
    cu_ue_id_t cp_ue_id;
    s1_ue_id_t mme_ue_s1ap_id;

    RrcCause          cause;
    rrc_cause_value_t cause_value;
};

struct HandoverNotify
{
    //!\todo fill TS 136 413, 9.1.5.7
    cu_ue_id_t cp_ue_id;
};

struct PathSwitchRequest
{
    cu_ue_id_t            cp_ue_id;
    uint32_t              src_mme_ue_s1ap_id;
    ErabsSwitchParameters erab_switch_list;
    SecurityCapabilities  security_capabilities;
};

struct HandoverCancel
{
    cu_ue_id_t cp_ue_id;

    RrcCause          cause;
    rrc_cause_value_t cause_value;
};

struct InitialUeMessage
{
    cu_ue_id_t               cp_ue_id;
    tracking_area_identity_t tai;
    cell_id_t                cell_id;
    EstablishmentCause_t establishment_cause; ///< Establishment cause as sent by UE
    ue_identity_t            ue_identity;

    nas_pdu_t nas_pdu;

    // void serialize(rapidjson::Document &config);
    // void deserialize(const rapidjson::Document &config);
};

struct UplinkNasTransport
{
    cu_ue_id_t cp_ue_id;
    nas_pdu_t nas_pdu;
};

struct NasNonDeliveryIndication
{
    cu_ue_id_t        cp_ue_id;
    RrcCause          cause;
    rrc_cause_value_t cause_value;
    nas_pdu_t         nas_pdu;
};

struct NasDeliveryIndication
{
    //!\todo need to fill ?
    cu_ue_id_t cp_ue_id;
};

struct UeCapabilityInfoIndication
{
    cu_ue_id_t         cp_ue_id;
    ue_radio_cap_pdu_t ue_radio_cap;
    // for paging?
};

struct LocationReportFailureIndication
{
    cu_ue_id_t        cp_ue_id;
    RrcCause          cause;
    rrc_cause_value_t cause_value;
};

struct LocationReport
{
    cu_ue_id_t               cp_ue_id;
    cell_id_t                cell_id;
    tracking_area_identity_t tai;
    uint8_t                  event_type;
    uint8_t                  report_area;
};

struct EnbStatusTransfer
{
    cu_ue_id_t cp_ue_id;
    struct SnStatus
    {
        e_rab_id_t erab_id;
        PdcpCount  ul_count_value;
        PdcpCount  dl_count_value;
    };
    std::vector<SnStatus> sn_status_list;
};

struct InitialContextSetupResponse
{
    cu_ue_id_t   cp_ue_id;
    ErabsToSetup erab_setup_list;
    ErabsToFail  erab_failed_list;
};

struct RrcS1apErrorIndication
{
    optional<cu_ue_id_t>       cp_ue_id;
    optional<s1_ue_id_t>       mme_ue_s1ap_id;
    optional<s1_ue_id_t>       enb_ue_s1ap_id;
    RrcCause                   cause;
    rrc_cause_value_t          cause_value;
};

} // end namespace lte
} // end namespace s1ap
} // end namespace vran

namespace vran
{
namespace cplane
{
namespace common
{

enum class DuplexDivision
{
    FREQUENCY = 0, // FDD
    TIME           // TDD
};

enum class Bandwidth
{
    NRB_1,
    NRB_6,
    NRB_15,
    NRB_25,
    NRB_50,
    NRB_75,
    NRB_100
};

enum class CyclicPrefix
{
    NORMAL,
    EXTENDED
};

struct EutraBandInfo
{
    uint8_t  band;
    uint16_t dl_freq_low_100khz; // Frequency in hundreds of kHz
    earfcn_t dl_min_earfcn;
    earfcn_t dl_max_earfcn;
    uint16_t ul_freq_low_100khz; // Frequency in hundreds of kHz
    earfcn_t ul_min_earfcn;
    earfcn_t ul_max_earfcn;
};

// Table 5.7.3-1: E-UTRA channel numbers. TS 136.101
// band, UL low freq, UL min EARFCN, UL max EARFCN, DL low freq, DL min EARFCN, DL max EARFCN
static const EutraBandInfo eutra_bands_info_table[] = {
    { 1, 21100,     0,   599, 19200,  18000,  18599},
    { 2, 19300,   600,  1199, 18500,  18600,  19199},
    { 3, 18050,  1200,  1949, 17100,  19200,  19949},
    { 4, 21100,  1950,  2399, 17100,  19950,  20399},
    { 5,  8690,  2400,  2649,  8240,  20400,  20649},
    { 6,  8750,  2650,  2749,  8300,  20650,  20749},
    { 7, 26200,  2750,  3449, 25000,  20750,  21449},
    { 8,  9250,  3450,  3799,  8800,  21450,  21799},
    { 9, 18449,  3800,  4149, 17499,  21800,  22149},
    {10, 21100,  4150,  4749, 17100,  22150,  22749},
    {11, 14759,  4750,  4949, 14279,  22750,  22949},
    {12,  7290,  5010,  5179,  6990,  23010,  23179},
    {13,  7460,  5180,  5279,  7770,  23180,  23279},
    {14,  7580,  5280,  5379,  7880,  23280,  23379},
    {17,  7340,  5730,  5849,  7040,  23730,  23849},
    {18,  8600,  5850,  5999,  8150,  23850,  23999},
    {19,  8750,  6000,  6149,  8300,  24000,  24149},
    {20,  7910,  6150,  6449,  8320,  24150,  24449},
    {21, 14959,  6450,  6599, 14479,  24450,  24599},
    {22, 35100,  6600,  7399, 34100,  24600,  25399},
    {23, 21800,  7500,  7699, 20000,  25500,  25699},
    {24, 15250,  7700,  8039, 16265,  25700,  26039},
    {25, 19300,  8040,  8689, 18500,  26040,  26689},
    {26,  8590,  8690,  9039,  8140,  26690,  27039},
    {27,  8520,  9040,  9209,  8070,  27040,  27209},
    {28,  7580,  9210,  9659,  7030,  27210,  27659},
    {29,  7170,  9660,  9769,     0,      0,      0},
    {30, 23500,  9770,  9869, 23050,  27660,  27759},
    {31,  4625,  9870,  9919,  4525,  27760,  27809},
    {32, 14520,  9920, 10359,     0,      0,      0},
    {33, 19000, 36000, 36199, 19000,  36000,  36199},
    {34, 20100, 36200, 36349, 20100,  36200,  36349},
    {35, 18500, 36350, 36949, 18500,  36350,  36949},
    {36, 19300, 36950, 37549, 19300,  36950,  37549},
    {37, 19100, 37550, 37749, 19100,  37550,  37749},
    {38, 25700, 37750, 38249, 25700,  37750,  38249},
    {39, 18800, 38250, 38649, 18800,  38250,  38649},
    {40, 23000, 38650, 39649, 23000,  38650,  39649},
    {41, 24960, 39650, 41589, 24960,  39650,  41589},
    {42, 34000, 41590, 43589, 34000,  41590,  43589},
    {43, 36000, 43590, 45589, 36000,  43590,  45589},
    {44,  7030, 45590, 46589,  7030,  45590,  46589},
    {45, 14470, 46590, 46789, 14470,  46590,  46789},
    {46, 51500, 46790, 54539, 51500,  46790,  54539},
    {65, 21100, 65536, 67835, 19200, 131072, 131971},
    {66, 21100, 66436, 67335, 17100, 131972, 132671},
    {67,  7380, 67336, 67535,     0,      0,      0},
    {68,  7530, 67536, 67835,  6980, 132672, 132971}
};

static const uint8_t EUTRA_BANDS_INFO_TABLE_SIZE = sizeof(eutra_bands_info_table) / sizeof(EutraBandInfo);

struct FrequencyInfo
{
    static const EutraBandInfo getBandInfo(band_t eutra_band)
    {
        for (uint8_t i = 0; i < EUTRA_BANDS_INFO_TABLE_SIZE; ++i)
        {
            if (eutra_bands_info_table[i].band == eutra_band)
                return eutra_bands_info_table[i];
        }

        return EutraBandInfo();
    }

    earfcn_t earfcn;
    band_t   band;

    void setUlFrequencyHz(band_t eutra_band, uint64_t ul_freq_val)
    {
        earfcn = 0;

        const EutraBandInfo &info = FrequencyInfo::getBandInfo(eutra_band);

        if(info.band == 0)
            return;

        uint32_t ul_freq_100khz = ul_freq_val / 100'000;

        band   = info.band;
        earfcn = info.ul_min_earfcn + ul_freq_100khz - info.ul_freq_low_100khz;
    }
    uint64_t getUlFrequencyHz() const
    {
        const EutraBandInfo &info = FrequencyInfo::getBandInfo(band);

        if (info.band == 0)
            return 0;

        return (earfcn - info.ul_min_earfcn + info.ul_freq_low_100khz) * 100'000;
    }
    void setDlFrequencyHz(band_t eutra_band, uint64_t dl_freq_val)
    {
        earfcn = 0;

        const EutraBandInfo &info = FrequencyInfo::getBandInfo(eutra_band);

        if (info.band == 0)
            return;

        uint32_t dl_freq_100khz = dl_freq_val / 100'000;

        band   = info.band;
        earfcn = info.dl_min_earfcn + dl_freq_100khz - info.dl_freq_low_100khz;
    }
    uint64_t getDlFrequencyHz() const
    {
        const EutraBandInfo &info = FrequencyInfo::getBandInfo(band);

        if(info.band == 0)
            return 0;

        return (earfcn - info.dl_min_earfcn + info.dl_freq_low_100khz) * 100'000;
    }
};

struct PhyValuesTDD
{
    FrequencyInfo freq_info; // E-UTRAN ARFCN
    Bandwidth     bandwidth;
};

struct PhyValuesFDD
{
    Bandwidth     dl_bandwidth;
    FrequencyInfo dl_freq_info; // E-UTRAN ARFCN

    Bandwidth     ul_bandwidth;
    FrequencyInfo ul_freq_info; // E-UTRAN ARFCN
};

struct PhyValues
{
    phy_cell_id_t  phy_cell_id;

    CyclicPrefix dl_cycle_prefix;
    CyclicPrefix ul_cycle_prefix;

    uint8_t rx_antenna_ports; // remove?
    uint8_t tx_antenna_ports; // remove?

    DuplexDivision duplex_division;
    union
    {
        PhyValuesTDD tdd;
        PhyValuesFDD fdd;
    };


};

using vran::common::common::optional;

enum class LongDrxCycleStartOffset
{
    SF_10 = 0,
    SF_20,
    SF_32,
    SF_40,
    SF_64,
    SF_80,
    SF_128,
    SF_160,
    SF_256,
    SF_320,
    SF_512,
    SF_640,
    SF_1024,
    SF_1280,
    SF_2048,
    SF_2560
};

struct CuToDuRrcInformation
{
    optional<custom_pdu_t> radioResourceConfigDedicated;      // TS_36.331 RadioResourceConfigDedicated
    optional<custom_pdu_t> handoverPreparationInformation_r8; // TS_36.331 HandoverPreparationInformation
    optional<custom_pdu_t> measConfig;                        // TS_36.331 MeasConfig
    //!\todo EUTRA-Capability
    optional<custom_pdu_t> ueCapabilityRatContainerList; // TS_36.331 UE-CapabilityRAT-ContainerList
};

struct DuToCuRrcInformation
{
    optional<custom_pdu_t>            radioResourceConfigDedicated; // TS_36.331 RadioResourceConfigDedicated
    optional<custom_pdu_t>            measGapConfig;                // TS_36.331 MeasGapConfig
    optional<LongDrxCycleStartOffset> longCdrxCycleStartOffset;     // TS_36.331 longDRX-CycleStartOffset
    optional<custom_pdu_t>            cdrxConfig;                   // TS_36.331 DRX-Config
};

struct DuCellInfromation
{
    cell_id_t cell_id;

    PhyValues phy_values;

    // ng-eNB-DU System Information
    optional<custom_pdu_t> mib_pdu;   //!< Master information block data
    optional<custom_pdu_t> sib1_pdu;  //!< System information block type 1 data
    optional<custom_pdu_t> sib2_pdu;  //!< System information block type 2 data
    optional<custom_pdu_t> sib3_pdu;  //!< System information block type 3 data
    optional<custom_pdu_t> sib8_pdu;  //!< System information block type 8 data
    optional<custom_pdu_t> sib16_pdu; //!< System information block type 16 data
};
using DuCellInformationVector = std::vector<DuCellInfromation>;
using DuCellInformationMap    = std::unordered_map<cell_id_t, DuCellInfromation>;

struct CuCellInfromation
{
    cell_id_t cell_id;

    optional<custom_pdu_t> sib4_pdu;  //!< ng-eNB-CU System Information Block type 4 data
    optional<custom_pdu_t> sib5_pdu;  //!< ng-eNB-CU System Information Block type 5 data
    optional<custom_pdu_t> sib6_pdu;  //!< ng-eNB-CU System Information Block type 6 data
    optional<custom_pdu_t> sib7_pdu;  //!< ng-eNB-CU System Information Block type 7 data
    optional<custom_pdu_t> sib9_pdu;  //!< ng-eNB-CU System Information Block type 9 data
    optional<custom_pdu_t> sib10_pdu; //!< ng-eNB-CU System Information Block type 10 data
    optional<custom_pdu_t> sib11_pdu; //!< ng-eNB-CU System Information Block type 11 data
    optional<custom_pdu_t> sib12_pdu; //!< ng-eNB-CU System Information Block type 12 data
    optional<custom_pdu_t> sib13_pdu; //!< ng-eNB-CU System Information Block type 13 data
    optional<custom_pdu_t> sib14_pdu; //!< ng-eNB-CU System Information Block type 14 data
    optional<custom_pdu_t> sib15_pdu; //!< ng-eNB-CU System Information Block type 15 data
    optional<custom_pdu_t> sib17_pdu; //!< ng-eNB-CU System Information Block type 17 data
    optional<custom_pdu_t> sib18_pdu; //!< ng-eNB-CU System Information Block type 18 data
    optional<custom_pdu_t> sib19_pdu; //!< ng-eNB-CU System Information Block type 19 data
    optional<custom_pdu_t> sib20_pdu; //!< ng-eNB-CU System Information Block type 20 data
    optional<custom_pdu_t> sib21_pdu; //!< ng-eNB-CU System Information Block type 21 data
};
using CuCellInformationVector = std::vector<CuCellInfromation>;
using CuCellInformationMap    = std::unordered_map<cell_id_t, CuCellInfromation>;

struct CellFailedToBeActivated
{
    cell_id_t         cell_id;
    RrcCause          cause;
    rrc_cause_value_t cause_value;
};
using CellsFailedToBeActivated = std::vector<CellFailedToBeActivated>;

} // namespace common
} // namespace cplane
} // namespace vran

#endif