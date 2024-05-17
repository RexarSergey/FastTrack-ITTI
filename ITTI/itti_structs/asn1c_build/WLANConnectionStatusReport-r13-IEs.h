/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_WLANConnectionStatusReport_r13_IEs_H_
#define	_WLANConnectionStatusReport_r13_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include "WLAN-Status-r13.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct WLANConnectionStatusReport_v1430_IEs;

/* WLANConnectionStatusReport-r13-IEs */
typedef struct WLANConnectionStatusReport_r13_IEs {
	WLAN_Status_r13_t	 wlan_Status_r13;
	OCTET_STRING_t	*lateNonCriticalExtension	/* OPTIONAL */;
	struct WLANConnectionStatusReport_v1430_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} WLANConnectionStatusReport_r13_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_WLANConnectionStatusReport_r13_IEs;
extern asn_SEQUENCE_specifics_t asn_SPC_WLANConnectionStatusReport_r13_IEs_specs_1;
extern asn_TYPE_member_t asn_MBR_WLANConnectionStatusReport_r13_IEs_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "WLANConnectionStatusReport-v1430-IEs.h"

#endif	/* _WLANConnectionStatusReport_r13_IEs_H_ */
#include <asn_internal.h>
