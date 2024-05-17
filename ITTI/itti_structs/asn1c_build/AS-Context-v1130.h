/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_AS_Context_v1130_H_
#define	_AS_Context_v1130_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* AS-Context-v1130 */
typedef struct AS_Context_v1130 {
	OCTET_STRING_t	*idc_Indication_r11	/* OPTIONAL */;
	OCTET_STRING_t	*mbmsInterestIndication_r11	/* OPTIONAL */;
	OCTET_STRING_t	*powerPrefIndication_r11	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	OCTET_STRING_t	*sidelinkUEInformation_r12	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AS_Context_v1130_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AS_Context_v1130;
extern asn_SEQUENCE_specifics_t asn_SPC_AS_Context_v1130_specs_1;
extern asn_TYPE_member_t asn_MBR_AS_Context_v1130_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _AS_Context_v1130_H_ */
#include <asn_internal.h>
