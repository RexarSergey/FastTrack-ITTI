/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_MultiBandInfo_NB_r13_H_
#define	_MultiBandInfo_NB_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include "FreqBandIndicator-NB-r13.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NS_PmaxList_NB_r13;

/* MultiBandInfo-NB-r13 */
typedef struct MultiBandInfo_NB_r13 {
	FreqBandIndicator_NB_r13_t	*freqBandIndicator_r13	/* OPTIONAL */;
	struct NS_PmaxList_NB_r13	*freqBandInfo_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MultiBandInfo_NB_r13_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MultiBandInfo_NB_r13;
extern asn_SEQUENCE_specifics_t asn_SPC_MultiBandInfo_NB_r13_specs_1;
extern asn_TYPE_member_t asn_MBR_MultiBandInfo_NB_r13_1[2];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NS-PmaxList-NB-r13.h"

#endif	/* _MultiBandInfo_NB_r13_H_ */
#include <asn_internal.h>
