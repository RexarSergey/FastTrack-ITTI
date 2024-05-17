#ifndef CU_IFACE_TYPES_HPP
#define CU_IFACE_TYPES_HPP

#include <algorithm>
#include <vector>

#include "types.hpp"
#include "optional.hpp"
#include "bearer_types.hpp"

#include "asn1c_build/PCCH-Config.h"
#include "asn1c_build/RadioResourceConfigDedicated.h"
#include "asn1c_build/UE-EUTRA-Capability.h"
#include "asn1c_build/Paging.h"

namespace vran
{
namespace rrc_du
{
namespace lte
{
using vran::cplane::common::CuToDuRrcInformation;

/*! \struct PagingRequest
 *  \brief Contains W1 Paging request message data
 */
struct PagingRequest
{
    uint16_t                        ue_index_value;     //!< UE Identity Index value
    PagingUE_Identity               ue_paging_identity; //!< RAN UE Paging identity
    PagingRecord__cn_Domain         cn_domain;          //!< RAN UE Paging identity
    PCCH_Config__defaultPagingCycle paging_drx;         //!< Paging DRX
};

/*! \struct DlMessageTransfer
 *  \brief Contains W1 DL RRC message transfer message data
 */
struct DlMessageTransfer
{
    cu_ue_id_t cu_ue_id;
    du_ue_id_t old_du_ue_id; //!< rnti from ng-eNB-DU UE W1AP ID (in case identifier == cell_id)

    vran::cplane::common::RrcMessageTransfer transfer;
};

using DrbConfigurationList = std::vector<DrbAdditionalInfo>;

using vran::common::common::optional;
using vran::cplane::common::AggregateMaxBitrate;

/*! \struct UeContextSetupRequest
 *  \brief Contains W1 UE context setup request message data
 */
struct UeContextSetupRequest
{
    // identifier ng-eNB-DU UE W1AP ID optional || cell_id
    cu_ue_id_t cu_ue_id; //!< ng-eNB-CU UE W1AP ID

    CuToDuRrcInformation cu_to_du_information; //!< CU to DU RRC Information contains RadioResourceConfigDedicated
                                               //!< including SRB to Be Setup List (SRB_ToAddModList)

    optional<DrbConfigurationList> drb_add_info; //!< DRBs cfg to be setup (ASN part comes with drb_ToAddModList)
    optional<AggregateMaxBitrate> aggregate_max_bitrate; //!< ng-eNB-DU UE Aggregate Maximum Bit Rate Uplink ++ OPTIONAL (добавить)
};

/*! \struct UeContextModificationRequest
 *  \brief Contains W1 UE context modification request message data
 */
struct UeContextModificationRequest
{
    cu_ue_id_t cu_ue_id; //!< ng-eNB-CU UE W1AP ID

    CuToDuRrcInformation cu_to_du_information; //!< CU to DU RRC Information contains RadioResourceConfigDedicated

    optional<DrbConfigurationList> drb_add_info; //!< DRBs cfg to be setup (ASN part comes with drb_ToAddModList)
    optional<DrbConfigurationList> drb_mod_info; //!< DRBs cfg to be modified (ASN part comes with drb_ToAddModList)
    optional<DrbIdList>            drb_rel_info; //!< DRBs cfg to be released

    optional<AggregateMaxBitrate> aggregate_max_bitrate; //!< ng-eNB-DU UE Aggregate Maximum Bit Rate Uplink ++ OPTIONAL (добавить)
};

/*! \struct UeContextReleaseCommand
 *  \brief Contains W1 UE context release command message data
 */
struct UeContextReleaseCommand
{
    cu_ue_id_t        cu_ue_id;    //!< ng-eNB-CU UE W1AP ID
    RrcCause          cause;       //!< FROM W1 Cause to RRC cause
    rrc_cause_value_t cause_value; //!< FROM W1 Cause to RRC cause value

    optional<RrcMessageTransfer> transfer;
};

} // namespace lte
} // namespace rrc_du
} // namespace vran

#endif