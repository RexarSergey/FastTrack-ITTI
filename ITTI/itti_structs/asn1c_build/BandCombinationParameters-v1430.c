/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "BandCombinationParameters-v1430.h"

static int
memb_bandParameterList_v1430_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 64)) {
		/* Perform validation of the inner elements */
		return SEQUENCE_OF_constraint(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_v2x_SupportedTxBandCombListPerBC_r14_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size >= 1 && size <= 384)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_v2x_SupportedRxBandCombListPerBC_r14_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size >= 1 && size <= 384)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_bandParameterList_v1430_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..64)) */};
static asn_per_constraints_t asn_PER_type_bandParameterList_v1430_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 6,  6,  1,  64 }	/* (SIZE(1..64)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_bandParameterList_v1430_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..64)) */};
static asn_per_constraints_t asn_PER_memb_bandParameterList_v1430_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 6,  6,  1,  64 }	/* (SIZE(1..64)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_v2x_SupportedTxBandCombListPerBC_r14_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..384)) */};
static asn_per_constraints_t asn_PER_memb_v2x_SupportedTxBandCombListPerBC_r14_constr_4 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 9,  9,  1,  384 }	/* (SIZE(1..384)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_v2x_SupportedRxBandCombListPerBC_r14_constr_5 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..384)) */};
static asn_per_constraints_t asn_PER_memb_v2x_SupportedRxBandCombListPerBC_r14_constr_5 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 9,  9,  1,  384 }	/* (SIZE(1..384)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_bandParameterList_v1430_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_BandParameters_v1430,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_bandParameterList_v1430_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_bandParameterList_v1430_specs_2 = {
	sizeof(struct BandCombinationParameters_v1430__bandParameterList_v1430),
	offsetof(struct BandCombinationParameters_v1430__bandParameterList_v1430, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_bandParameterList_v1430_2 = {
	"bandParameterList-v1430",
	"bandParameterList-v1430",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_bandParameterList_v1430_tags_2,
	sizeof(asn_DEF_bandParameterList_v1430_tags_2)
		/sizeof(asn_DEF_bandParameterList_v1430_tags_2[0]) - 1, /* 1 */
	asn_DEF_bandParameterList_v1430_tags_2,	/* Same as above */
	sizeof(asn_DEF_bandParameterList_v1430_tags_2)
		/sizeof(asn_DEF_bandParameterList_v1430_tags_2[0]), /* 2 */
	{ &asn_OER_type_bandParameterList_v1430_constr_2, &asn_PER_type_bandParameterList_v1430_constr_2, SEQUENCE_OF_constraint },
	asn_MBR_bandParameterList_v1430_2,
	1,	/* Single element */
	&asn_SPC_bandParameterList_v1430_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_BandCombinationParameters_v1430_1[] = {
	{ ATF_POINTER, 3, offsetof(struct BandCombinationParameters_v1430, bandParameterList_v1430),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_bandParameterList_v1430_2,
		0,
		{ &asn_OER_memb_bandParameterList_v1430_constr_2, &asn_PER_memb_bandParameterList_v1430_constr_2,  memb_bandParameterList_v1430_constraint_1 },
		0, 0, /* No default value */
		"bandParameterList-v1430"
		},
	{ ATF_POINTER, 2, offsetof(struct BandCombinationParameters_v1430, v2x_SupportedTxBandCombListPerBC_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{ &asn_OER_memb_v2x_SupportedTxBandCombListPerBC_r14_constr_4, &asn_PER_memb_v2x_SupportedTxBandCombListPerBC_r14_constr_4,  memb_v2x_SupportedTxBandCombListPerBC_r14_constraint_1 },
		0, 0, /* No default value */
		"v2x-SupportedTxBandCombListPerBC-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct BandCombinationParameters_v1430, v2x_SupportedRxBandCombListPerBC_r14),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		0,
		{ &asn_OER_memb_v2x_SupportedRxBandCombListPerBC_r14_constr_5, &asn_PER_memb_v2x_SupportedRxBandCombListPerBC_r14_constr_5,  memb_v2x_SupportedRxBandCombListPerBC_r14_constraint_1 },
		0, 0, /* No default value */
		"v2x-SupportedRxBandCombListPerBC-r14"
		},
};
static const int asn_MAP_BandCombinationParameters_v1430_oms_1[] = { 0, 1, 2 };
static const ber_tlv_tag_t asn_DEF_BandCombinationParameters_v1430_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_BandCombinationParameters_v1430_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* bandParameterList-v1430 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* v2x-SupportedTxBandCombListPerBC-r14 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* v2x-SupportedRxBandCombListPerBC-r14 */
};
asn_SEQUENCE_specifics_t asn_SPC_BandCombinationParameters_v1430_specs_1 = {
	sizeof(struct BandCombinationParameters_v1430),
	offsetof(struct BandCombinationParameters_v1430, _asn_ctx),
	asn_MAP_BandCombinationParameters_v1430_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_BandCombinationParameters_v1430_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_BandCombinationParameters_v1430 = {
	"BandCombinationParameters-v1430",
	"BandCombinationParameters-v1430",
	&asn_OP_SEQUENCE,
	asn_DEF_BandCombinationParameters_v1430_tags_1,
	sizeof(asn_DEF_BandCombinationParameters_v1430_tags_1)
		/sizeof(asn_DEF_BandCombinationParameters_v1430_tags_1[0]), /* 1 */
	asn_DEF_BandCombinationParameters_v1430_tags_1,	/* Same as above */
	sizeof(asn_DEF_BandCombinationParameters_v1430_tags_1)
		/sizeof(asn_DEF_BandCombinationParameters_v1430_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_BandCombinationParameters_v1430_1,
	3,	/* Elements count */
	&asn_SPC_BandCombinationParameters_v1430_specs_1	/* Additional specs */
};

