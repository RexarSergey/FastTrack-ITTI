/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_AntennaInfoDedicated_r10_H_
#define	_AntennaInfoDedicated_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <BIT_STRING.h>
#include <NULL.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum AntennaInfoDedicated_r10__transmissionMode_r10 {
	AntennaInfoDedicated_r10__transmissionMode_r10_tm1	= 0,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm2	= 1,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm3	= 2,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm4	= 3,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm5	= 4,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm6	= 5,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm7	= 6,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm8_v920	= 7,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm9_v1020	= 8,
	AntennaInfoDedicated_r10__transmissionMode_r10_tm10_v1130	= 9,
	AntennaInfoDedicated_r10__transmissionMode_r10_spare6	= 10,
	AntennaInfoDedicated_r10__transmissionMode_r10_spare5	= 11,
	AntennaInfoDedicated_r10__transmissionMode_r10_spare4	= 12,
	AntennaInfoDedicated_r10__transmissionMode_r10_spare3	= 13,
	AntennaInfoDedicated_r10__transmissionMode_r10_spare2	= 14,
	AntennaInfoDedicated_r10__transmissionMode_r10_spare1	= 15
} e_AntennaInfoDedicated_r10__transmissionMode_r10;
typedef enum AntennaInfoDedicated_r10__ue_TransmitAntennaSelection_PR {
	AntennaInfoDedicated_r10__ue_TransmitAntennaSelection_PR_NOTHING,	/* No components present */
	AntennaInfoDedicated_r10__ue_TransmitAntennaSelection_PR_release,
	AntennaInfoDedicated_r10__ue_TransmitAntennaSelection_PR_setup
} AntennaInfoDedicated_r10__ue_TransmitAntennaSelection_PR;
typedef enum AntennaInfoDedicated_r10__ue_TransmitAntennaSelection__setup {
	AntennaInfoDedicated_r10__ue_TransmitAntennaSelection__setup_closedLoop	= 0,
	AntennaInfoDedicated_r10__ue_TransmitAntennaSelection__setup_openLoop	= 1
} e_AntennaInfoDedicated_r10__ue_TransmitAntennaSelection__setup;

/* AntennaInfoDedicated-r10 */
typedef struct AntennaInfoDedicated_r10 {
	long	 transmissionMode_r10;
	BIT_STRING_t	*codebookSubsetRestriction_r10	/* OPTIONAL */;
	struct AntennaInfoDedicated_r10__ue_TransmitAntennaSelection {
		AntennaInfoDedicated_r10__ue_TransmitAntennaSelection_PR present;
		union AntennaInfoDedicated_r10__ue_TransmitAntennaSelection_u {
			NULL_t	 release;
			long	 setup;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} ue_TransmitAntennaSelection;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AntennaInfoDedicated_r10_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_transmissionMode_r10_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_setup_22;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_AntennaInfoDedicated_r10;
extern asn_SEQUENCE_specifics_t asn_SPC_AntennaInfoDedicated_r10_specs_1;
extern asn_TYPE_member_t asn_MBR_AntennaInfoDedicated_r10_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _AntennaInfoDedicated_r10_H_ */
#include <asn_internal.h>
