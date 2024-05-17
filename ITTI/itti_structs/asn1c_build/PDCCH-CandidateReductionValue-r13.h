/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_PDCCH_CandidateReductionValue_r13_H_
#define	_PDCCH_CandidateReductionValue_r13_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PDCCH_CandidateReductionValue_r13 {
	PDCCH_CandidateReductionValue_r13_n0	= 0,
	PDCCH_CandidateReductionValue_r13_n33	= 1,
	PDCCH_CandidateReductionValue_r13_n66	= 2,
	PDCCH_CandidateReductionValue_r13_n100	= 3
} e_PDCCH_CandidateReductionValue_r13;

/* PDCCH-CandidateReductionValue-r13 */
typedef long	 PDCCH_CandidateReductionValue_r13_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_PDCCH_CandidateReductionValue_r13_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_PDCCH_CandidateReductionValue_r13;
extern const asn_INTEGER_specifics_t asn_SPC_PDCCH_CandidateReductionValue_r13_specs_1;
asn_struct_free_f PDCCH_CandidateReductionValue_r13_free;
asn_struct_print_f PDCCH_CandidateReductionValue_r13_print;
asn_constr_check_f PDCCH_CandidateReductionValue_r13_constraint;
ber_type_decoder_f PDCCH_CandidateReductionValue_r13_decode_ber;
der_type_encoder_f PDCCH_CandidateReductionValue_r13_encode_der;
xer_type_decoder_f PDCCH_CandidateReductionValue_r13_decode_xer;
xer_type_encoder_f PDCCH_CandidateReductionValue_r13_encode_xer;
oer_type_decoder_f PDCCH_CandidateReductionValue_r13_decode_oer;
oer_type_encoder_f PDCCH_CandidateReductionValue_r13_encode_oer;
per_type_decoder_f PDCCH_CandidateReductionValue_r13_decode_uper;
per_type_encoder_f PDCCH_CandidateReductionValue_r13_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _PDCCH_CandidateReductionValue_r13_H_ */
#include <asn_internal.h>
