/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-Sidelink-Preconf"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_SL_V2X_Preconfiguration_r14_H_
#define	_SL_V2X_Preconfiguration_r14_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SL-V2X-PreconfigFreqList-r14.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct SL_AnchorCarrierFreqList_V2X_r14;
struct SL_CBR_PreconfigTxConfigList_r14;

/* SL-V2X-Preconfiguration-r14 */
typedef struct SL_V2X_Preconfiguration_r14 {
	SL_V2X_PreconfigFreqList_r14_t	 v2x_PreconfigFreqList_r14;
	struct SL_AnchorCarrierFreqList_V2X_r14	*anchorCarrierFreqList_r14	/* OPTIONAL */;
	struct SL_CBR_PreconfigTxConfigList_r14	*cbr_PreconfigList_r14	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SL_V2X_Preconfiguration_r14_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SL_V2X_Preconfiguration_r14;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SL-AnchorCarrierFreqList-V2X-r14.h"
#include "SL-CBR-PreconfigTxConfigList-r14.h"

#endif	/* _SL_V2X_Preconfiguration_r14_H_ */
#include <asn_internal.h>
