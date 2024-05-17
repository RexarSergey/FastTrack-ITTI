/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_UplinkPowerControlDedicated_H_
#define	_UplinkPowerControlDedicated_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <NativeEnumerated.h>
#include <BOOLEAN.h>
#include "FilterCoefficient.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UplinkPowerControlDedicated__deltaMCS_Enabled {
	UplinkPowerControlDedicated__deltaMCS_Enabled_en0	= 0,
	UplinkPowerControlDedicated__deltaMCS_Enabled_en1	= 1
} e_UplinkPowerControlDedicated__deltaMCS_Enabled;

/* UplinkPowerControlDedicated */
typedef struct UplinkPowerControlDedicated {
	long	 p0_UE_PUSCH;
	long	 deltaMCS_Enabled;
	BOOLEAN_t	 accumulationEnabled;
	long	 p0_UE_PUCCH;
	long	 pSRS_Offset;
	FilterCoefficient_t	*filterCoefficient	/* DEFAULT 4 */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UplinkPowerControlDedicated_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_deltaMCS_Enabled_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_UplinkPowerControlDedicated;
extern asn_SEQUENCE_specifics_t asn_SPC_UplinkPowerControlDedicated_specs_1;
extern asn_TYPE_member_t asn_MBR_UplinkPowerControlDedicated_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _UplinkPowerControlDedicated_H_ */
#include <asn_internal.h>
