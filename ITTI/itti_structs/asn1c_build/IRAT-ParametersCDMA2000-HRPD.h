/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_IRAT_ParametersCDMA2000_HRPD_H_
#define	_IRAT_ParametersCDMA2000_HRPD_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SupportedBandListHRPD.h"
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum IRAT_ParametersCDMA2000_HRPD__tx_ConfigHRPD {
	IRAT_ParametersCDMA2000_HRPD__tx_ConfigHRPD_single	= 0,
	IRAT_ParametersCDMA2000_HRPD__tx_ConfigHRPD_dual	= 1
} e_IRAT_ParametersCDMA2000_HRPD__tx_ConfigHRPD;
typedef enum IRAT_ParametersCDMA2000_HRPD__rx_ConfigHRPD {
	IRAT_ParametersCDMA2000_HRPD__rx_ConfigHRPD_single	= 0,
	IRAT_ParametersCDMA2000_HRPD__rx_ConfigHRPD_dual	= 1
} e_IRAT_ParametersCDMA2000_HRPD__rx_ConfigHRPD;

/* IRAT-ParametersCDMA2000-HRPD */
typedef struct IRAT_ParametersCDMA2000_HRPD {
	SupportedBandListHRPD_t	 supportedBandListHRPD;
	long	 tx_ConfigHRPD;
	long	 rx_ConfigHRPD;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IRAT_ParametersCDMA2000_HRPD_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_tx_ConfigHRPD_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_rx_ConfigHRPD_6;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_IRAT_ParametersCDMA2000_HRPD;
extern asn_SEQUENCE_specifics_t asn_SPC_IRAT_ParametersCDMA2000_HRPD_specs_1;
extern asn_TYPE_member_t asn_MBR_IRAT_ParametersCDMA2000_HRPD_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _IRAT_ParametersCDMA2000_HRPD_H_ */
#include <asn_internal.h>
