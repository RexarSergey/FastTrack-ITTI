/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_UE_EUTRA_CapabilityAddXDD_Mode_v1370_H_
#define	_UE_EUTRA_CapabilityAddXDD_Mode_v1370_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CE_Parameters_v1370;

/* UE-EUTRA-CapabilityAddXDD-Mode-v1370 */
typedef struct UE_EUTRA_CapabilityAddXDD_Mode_v1370 {
	struct CE_Parameters_v1370	*ce_Parameters_v1370	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UE_EUTRA_CapabilityAddXDD_Mode_v1370_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UE_EUTRA_CapabilityAddXDD_Mode_v1370;
extern asn_SEQUENCE_specifics_t asn_SPC_UE_EUTRA_CapabilityAddXDD_Mode_v1370_specs_1;
extern asn_TYPE_member_t asn_MBR_UE_EUTRA_CapabilityAddXDD_Mode_v1370_1[1];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CE-Parameters-v1370.h"

#endif	/* _UE_EUTRA_CapabilityAddXDD_Mode_v1370_H_ */
#include <asn_internal.h>
