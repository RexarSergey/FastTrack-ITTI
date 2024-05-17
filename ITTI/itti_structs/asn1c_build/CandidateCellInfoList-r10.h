/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_CandidateCellInfoList_r10_H_
#define	_CandidateCellInfoList_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CandidateCellInfo_r10;

/* CandidateCellInfoList-r10 */
typedef struct CandidateCellInfoList_r10 {
	A_SEQUENCE_OF(struct CandidateCellInfo_r10) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CandidateCellInfoList_r10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CandidateCellInfoList_r10;
extern asn_SET_OF_specifics_t asn_SPC_CandidateCellInfoList_r10_specs_1;
extern asn_TYPE_member_t asn_MBR_CandidateCellInfoList_r10_1[1];
extern asn_per_constraints_t asn_PER_type_CandidateCellInfoList_r10_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CandidateCellInfo-r10.h"

#endif	/* _CandidateCellInfoList_r10_H_ */
#include <asn_internal.h>
