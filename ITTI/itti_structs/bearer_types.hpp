#ifndef VRAN_RRC_DU_BEARER_TYPES_HPP
#define VRAN_RRC_DU_BEARER_TYPES_HPP

#include "types.hpp"
namespace vran
{
namespace rrc_du
{
using namespace vran::cplane::common;

/*! \struct ERadioAccessBearer
 *  \brief Contains values for E-RAB configuration
 */
struct ERadioAccessBearer
{
    drb_id_t drb_id;
    lcid_t   lcid;

    ERadioAccessBearerParameter param_w1u_cu; //!< S-GW Tunnel endpoint parameters
    ERadioAccessBearerParameter param_w1u_du; //!< GTP Tunnel endpoint parameters
    ErabQosParameter            qos;          //!< Quality of service for this e_rab

    RrcCause          cause;       //!< E-RAB fail cause group
    rrc_cause_value_t cause_value; //!< E-RAB fail specific cause value belongs this group
};

struct DrbAdditionalInfo
{
    drb_id_t                    drb_id;
    ErabQosParameter            qos_parameters;
    ERadioAccessBearerParameter param_gtp_cu;
};

} // namespace rrc_du
} // namespace vran
#endif // BEARER_TYPES_HPP
