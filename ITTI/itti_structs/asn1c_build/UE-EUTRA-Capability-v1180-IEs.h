/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_UE_EUTRA_Capability_v1180_IEs_H_
#define	_UE_EUTRA_Capability_v1180_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RF_Parameters_v1180;
struct MBMS_Parameters_r11;
struct UE_EUTRA_CapabilityAddXDD_Mode_v1180;
struct UE_EUTRA_Capability_v11a0_IEs;

/* UE-EUTRA-Capability-v1180-IEs */
typedef struct UE_EUTRA_Capability_v1180_IEs {
	struct RF_Parameters_v1180	*rf_Parameters_v1180	/* OPTIONAL */;
	struct MBMS_Parameters_r11	*mbms_Parameters_r11	/* OPTIONAL */;
	struct UE_EUTRA_CapabilityAddXDD_Mode_v1180	*fdd_Add_UE_EUTRA_Capabilities_v1180	/* OPTIONAL */;
	struct UE_EUTRA_CapabilityAddXDD_Mode_v1180	*tdd_Add_UE_EUTRA_Capabilities_v1180	/* OPTIONAL */;
	struct UE_EUTRA_Capability_v11a0_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UE_EUTRA_Capability_v1180_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UE_EUTRA_Capability_v1180_IEs;
extern asn_SEQUENCE_specifics_t asn_SPC_UE_EUTRA_Capability_v1180_IEs_specs_1;
extern asn_TYPE_member_t asn_MBR_UE_EUTRA_Capability_v1180_IEs_1[5];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RF-Parameters-v1180.h"
#include "MBMS-Parameters-r11.h"
#include "UE-EUTRA-CapabilityAddXDD-Mode-v1180.h"
#include "UE-EUTRA-Capability-v11a0-IEs.h"

#endif	/* _UE_EUTRA_Capability_v1180_IEs_H_ */
#include <asn_internal.h>
