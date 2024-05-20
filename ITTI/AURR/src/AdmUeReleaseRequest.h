/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "AdmUeReleaseRequestTest"
 * 	found in "AdmUeReleaseRequest.asn1"
 * 	`asn1c -D src -pdu=AdmUeReleaseRequest -no-gen-OER -fcompound-names -no-gen-example -fno-include-deps`
 */

#ifndef	_AdmUeReleaseRequest_H_
#define	_AdmUeReleaseRequest_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* AdmUeReleaseRequest */
typedef struct AdmUeReleaseRequest {
	unsigned long	 rrccause;
	long	 rrc_cause_value_t;
	OCTET_STRING_t	 redirectedCarrierInfo;
	OCTET_STRING_t	 idleModeMobilityControlInfo;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AdmUeReleaseRequest_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_rrccause_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_AdmUeReleaseRequest;

#ifdef __cplusplus
}
#endif

#endif	/* _AdmUeReleaseRequest_H_ */
#include <asn_internal.h>
