/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "NAICS-Capability-Entry-r12.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_numberOfNAICS_CapableCC_r12_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 5)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_numberOfAggregatedPRB_r12_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_numberOfAggregatedPRB_r12_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_numberOfNAICS_CapableCC_r12_constr_2 CC_NOTUSED = {
	{ 1, 1 }	/* (1..5) */,
	-1};
static asn_per_constraints_t asn_PER_memb_numberOfNAICS_CapableCC_r12_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  1,  5 }	/* (1..5) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_numberOfAggregatedPRB_r12_value2enum_3[] = {
	{ 0,	3,	"n50" },
	{ 1,	3,	"n75" },
	{ 2,	4,	"n100" },
	{ 3,	4,	"n125" },
	{ 4,	4,	"n150" },
	{ 5,	4,	"n175" },
	{ 6,	4,	"n200" },
	{ 7,	4,	"n225" },
	{ 8,	4,	"n250" },
	{ 9,	4,	"n275" },
	{ 10,	4,	"n300" },
	{ 11,	4,	"n350" },
	{ 12,	4,	"n400" },
	{ 13,	4,	"n450" },
	{ 14,	4,	"n500" },
	{ 15,	5,	"spare" }
};
static const unsigned int asn_MAP_numberOfAggregatedPRB_r12_enum2value_3[] = {
	2,	/* n100(2) */
	3,	/* n125(3) */
	4,	/* n150(4) */
	5,	/* n175(5) */
	6,	/* n200(6) */
	7,	/* n225(7) */
	8,	/* n250(8) */
	9,	/* n275(9) */
	10,	/* n300(10) */
	11,	/* n350(11) */
	12,	/* n400(12) */
	13,	/* n450(13) */
	0,	/* n50(0) */
	14,	/* n500(14) */
	1,	/* n75(1) */
	15	/* spare(15) */
};
static const asn_INTEGER_specifics_t asn_SPC_numberOfAggregatedPRB_r12_specs_3 = {
	asn_MAP_numberOfAggregatedPRB_r12_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_numberOfAggregatedPRB_r12_enum2value_3,	/* N => "tag"; sorted by N */
	16,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_numberOfAggregatedPRB_r12_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_numberOfAggregatedPRB_r12_3 = {
	"numberOfAggregatedPRB-r12",
	"numberOfAggregatedPRB-r12",
	&asn_OP_NativeEnumerated,
	asn_DEF_numberOfAggregatedPRB_r12_tags_3,
	sizeof(asn_DEF_numberOfAggregatedPRB_r12_tags_3)
		/sizeof(asn_DEF_numberOfAggregatedPRB_r12_tags_3[0]) - 1, /* 1 */
	asn_DEF_numberOfAggregatedPRB_r12_tags_3,	/* Same as above */
	sizeof(asn_DEF_numberOfAggregatedPRB_r12_tags_3)
		/sizeof(asn_DEF_numberOfAggregatedPRB_r12_tags_3[0]), /* 2 */
	{ &asn_OER_type_numberOfAggregatedPRB_r12_constr_3, &asn_PER_type_numberOfAggregatedPRB_r12_constr_3, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_numberOfAggregatedPRB_r12_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NAICS_Capability_Entry_r12_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NAICS_Capability_Entry_r12, numberOfNAICS_CapableCC_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_numberOfNAICS_CapableCC_r12_constr_2, &asn_PER_memb_numberOfNAICS_CapableCC_r12_constr_2,  memb_numberOfNAICS_CapableCC_r12_constraint_1 },
		0, 0, /* No default value */
		"numberOfNAICS-CapableCC-r12"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NAICS_Capability_Entry_r12, numberOfAggregatedPRB_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_numberOfAggregatedPRB_r12_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"numberOfAggregatedPRB-r12"
		},
};
static const ber_tlv_tag_t asn_DEF_NAICS_Capability_Entry_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NAICS_Capability_Entry_r12_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* numberOfNAICS-CapableCC-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* numberOfAggregatedPRB-r12 */
};
asn_SEQUENCE_specifics_t asn_SPC_NAICS_Capability_Entry_r12_specs_1 = {
	sizeof(struct NAICS_Capability_Entry_r12),
	offsetof(struct NAICS_Capability_Entry_r12, _asn_ctx),
	asn_MAP_NAICS_Capability_Entry_r12_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NAICS_Capability_Entry_r12 = {
	"NAICS-Capability-Entry-r12",
	"NAICS-Capability-Entry-r12",
	&asn_OP_SEQUENCE,
	asn_DEF_NAICS_Capability_Entry_r12_tags_1,
	sizeof(asn_DEF_NAICS_Capability_Entry_r12_tags_1)
		/sizeof(asn_DEF_NAICS_Capability_Entry_r12_tags_1[0]), /* 1 */
	asn_DEF_NAICS_Capability_Entry_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_NAICS_Capability_Entry_r12_tags_1)
		/sizeof(asn_DEF_NAICS_Capability_Entry_r12_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NAICS_Capability_Entry_r12_1,
	2,	/* Elements count */
	&asn_SPC_NAICS_Capability_Entry_r12_specs_1	/* Additional specs */
};

