/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_SupportedBandListHRPD_H_
#define	_SupportedBandListHRPD_H_


#include <asn_application.h>

/* Including external dependencies */
#include "BandclassCDMA2000.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* SupportedBandListHRPD */
typedef struct SupportedBandListHRPD {
	A_SEQUENCE_OF(BandclassCDMA2000_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedBandListHRPD_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupportedBandListHRPD;
extern asn_SET_OF_specifics_t asn_SPC_SupportedBandListHRPD_specs_1;
extern asn_TYPE_member_t asn_MBR_SupportedBandListHRPD_1[1];
extern asn_per_constraints_t asn_PER_type_SupportedBandListHRPD_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _SupportedBandListHRPD_H_ */
#include <asn_internal.h>
