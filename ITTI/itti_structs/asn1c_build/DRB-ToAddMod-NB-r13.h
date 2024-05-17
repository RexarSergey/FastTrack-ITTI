/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_DRB_ToAddMod_NB_r13_H_
#define	_DRB_ToAddMod_NB_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "DRB-Identity.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PDCP_Config_NB_r13;
struct RLC_Config_NB_r13;
struct LogicalChannelConfig_NB_r13;
struct RLC_Config_NB_v1430;

/* DRB-ToAddMod-NB-r13 */
typedef struct DRB_ToAddMod_NB_r13 {
	long	*eps_BearerIdentity_r13	/* OPTIONAL */;
	DRB_Identity_t	 drb_Identity_r13;
	struct PDCP_Config_NB_r13	*pdcp_Config_r13	/* OPTIONAL */;
	struct RLC_Config_NB_r13	*rlc_Config_r13	/* OPTIONAL */;
	long	*logicalChannelIdentity_r13	/* OPTIONAL */;
	struct LogicalChannelConfig_NB_r13	*logicalChannelConfig_r13	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct RLC_Config_NB_v1430	*rlc_Config_v1430	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DRB_ToAddMod_NB_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DRB_ToAddMod_NB_r13;
extern asn_SEQUENCE_specifics_t asn_SPC_DRB_ToAddMod_NB_r13_specs_1;
extern asn_TYPE_member_t asn_MBR_DRB_ToAddMod_NB_r13_1[7];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PDCP-Config-NB-r13.h"
#include "RLC-Config-NB-r13.h"
#include "LogicalChannelConfig-NB-r13.h"
#include "RLC-Config-NB-v1430.h"

#endif	/* _DRB_ToAddMod_NB_r13_H_ */
#include <asn_internal.h>
