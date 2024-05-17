/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "NPDCCH-ConfigDedicated-NB-r13.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_npdcch_NumRepetitions_r13_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_npdcch_NumRepetitions_r13_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  15 }	/* (0..15) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_npdcch_StartSF_USS_r13_constr_19 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_npdcch_StartSF_USS_r13_constr_19 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  7 }	/* (0..7) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_npdcch_Offset_USS_r13_constr_28 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_npdcch_Offset_USS_r13_constr_28 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_npdcch_NumRepetitions_r13_value2enum_2[] = {
	{ 0,	2,	"r1" },
	{ 1,	2,	"r2" },
	{ 2,	2,	"r4" },
	{ 3,	2,	"r8" },
	{ 4,	3,	"r16" },
	{ 5,	3,	"r32" },
	{ 6,	3,	"r64" },
	{ 7,	4,	"r128" },
	{ 8,	4,	"r256" },
	{ 9,	4,	"r512" },
	{ 10,	5,	"r1024" },
	{ 11,	5,	"r2048" },
	{ 12,	6,	"spare4" },
	{ 13,	6,	"spare3" },
	{ 14,	6,	"spare2" },
	{ 15,	6,	"spare1" }
};
static const unsigned int asn_MAP_npdcch_NumRepetitions_r13_enum2value_2[] = {
	0,	/* r1(0) */
	10,	/* r1024(10) */
	7,	/* r128(7) */
	4,	/* r16(4) */
	1,	/* r2(1) */
	11,	/* r2048(11) */
	8,	/* r256(8) */
	5,	/* r32(5) */
	2,	/* r4(2) */
	9,	/* r512(9) */
	6,	/* r64(6) */
	3,	/* r8(3) */
	15,	/* spare1(15) */
	14,	/* spare2(14) */
	13,	/* spare3(13) */
	12	/* spare4(12) */
};
static const asn_INTEGER_specifics_t asn_SPC_npdcch_NumRepetitions_r13_specs_2 = {
	asn_MAP_npdcch_NumRepetitions_r13_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_npdcch_NumRepetitions_r13_enum2value_2,	/* N => "tag"; sorted by N */
	16,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_npdcch_NumRepetitions_r13_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_npdcch_NumRepetitions_r13_2 = {
	"npdcch-NumRepetitions-r13",
	"npdcch-NumRepetitions-r13",
	&asn_OP_NativeEnumerated,
	asn_DEF_npdcch_NumRepetitions_r13_tags_2,
	sizeof(asn_DEF_npdcch_NumRepetitions_r13_tags_2)
		/sizeof(asn_DEF_npdcch_NumRepetitions_r13_tags_2[0]) - 1, /* 1 */
	asn_DEF_npdcch_NumRepetitions_r13_tags_2,	/* Same as above */
	sizeof(asn_DEF_npdcch_NumRepetitions_r13_tags_2)
		/sizeof(asn_DEF_npdcch_NumRepetitions_r13_tags_2[0]), /* 2 */
	{ &asn_OER_type_npdcch_NumRepetitions_r13_constr_2, &asn_PER_type_npdcch_NumRepetitions_r13_constr_2, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_npdcch_NumRepetitions_r13_specs_2	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_npdcch_StartSF_USS_r13_value2enum_19[] = {
	{ 0,	6,	"v1dot5" },
	{ 1,	2,	"v2" },
	{ 2,	2,	"v4" },
	{ 3,	2,	"v8" },
	{ 4,	3,	"v16" },
	{ 5,	3,	"v32" },
	{ 6,	3,	"v48" },
	{ 7,	3,	"v64" }
};
static const unsigned int asn_MAP_npdcch_StartSF_USS_r13_enum2value_19[] = {
	4,	/* v16(4) */
	0,	/* v1dot5(0) */
	1,	/* v2(1) */
	5,	/* v32(5) */
	2,	/* v4(2) */
	6,	/* v48(6) */
	7,	/* v64(7) */
	3	/* v8(3) */
};
static const asn_INTEGER_specifics_t asn_SPC_npdcch_StartSF_USS_r13_specs_19 = {
	asn_MAP_npdcch_StartSF_USS_r13_value2enum_19,	/* "tag" => N; sorted by tag */
	asn_MAP_npdcch_StartSF_USS_r13_enum2value_19,	/* N => "tag"; sorted by N */
	8,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_npdcch_StartSF_USS_r13_tags_19[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_npdcch_StartSF_USS_r13_19 = {
	"npdcch-StartSF-USS-r13",
	"npdcch-StartSF-USS-r13",
	&asn_OP_NativeEnumerated,
	asn_DEF_npdcch_StartSF_USS_r13_tags_19,
	sizeof(asn_DEF_npdcch_StartSF_USS_r13_tags_19)
		/sizeof(asn_DEF_npdcch_StartSF_USS_r13_tags_19[0]) - 1, /* 1 */
	asn_DEF_npdcch_StartSF_USS_r13_tags_19,	/* Same as above */
	sizeof(asn_DEF_npdcch_StartSF_USS_r13_tags_19)
		/sizeof(asn_DEF_npdcch_StartSF_USS_r13_tags_19[0]), /* 2 */
	{ &asn_OER_type_npdcch_StartSF_USS_r13_constr_19, &asn_PER_type_npdcch_StartSF_USS_r13_constr_19, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_npdcch_StartSF_USS_r13_specs_19	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_npdcch_Offset_USS_r13_value2enum_28[] = {
	{ 0,	4,	"zero" },
	{ 1,	9,	"oneEighth" },
	{ 2,	9,	"oneFourth" },
	{ 3,	11,	"threeEighth" }
};
static const unsigned int asn_MAP_npdcch_Offset_USS_r13_enum2value_28[] = {
	1,	/* oneEighth(1) */
	2,	/* oneFourth(2) */
	3,	/* threeEighth(3) */
	0	/* zero(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_npdcch_Offset_USS_r13_specs_28 = {
	asn_MAP_npdcch_Offset_USS_r13_value2enum_28,	/* "tag" => N; sorted by tag */
	asn_MAP_npdcch_Offset_USS_r13_enum2value_28,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_npdcch_Offset_USS_r13_tags_28[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_npdcch_Offset_USS_r13_28 = {
	"npdcch-Offset-USS-r13",
	"npdcch-Offset-USS-r13",
	&asn_OP_NativeEnumerated,
	asn_DEF_npdcch_Offset_USS_r13_tags_28,
	sizeof(asn_DEF_npdcch_Offset_USS_r13_tags_28)
		/sizeof(asn_DEF_npdcch_Offset_USS_r13_tags_28[0]) - 1, /* 1 */
	asn_DEF_npdcch_Offset_USS_r13_tags_28,	/* Same as above */
	sizeof(asn_DEF_npdcch_Offset_USS_r13_tags_28)
		/sizeof(asn_DEF_npdcch_Offset_USS_r13_tags_28[0]), /* 2 */
	{ &asn_OER_type_npdcch_Offset_USS_r13_constr_28, &asn_PER_type_npdcch_Offset_USS_r13_constr_28, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_npdcch_Offset_USS_r13_specs_28	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NPDCCH_ConfigDedicated_NB_r13_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NPDCCH_ConfigDedicated_NB_r13, npdcch_NumRepetitions_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_npdcch_NumRepetitions_r13_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"npdcch-NumRepetitions-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NPDCCH_ConfigDedicated_NB_r13, npdcch_StartSF_USS_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_npdcch_StartSF_USS_r13_19,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"npdcch-StartSF-USS-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NPDCCH_ConfigDedicated_NB_r13, npdcch_Offset_USS_r13),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_npdcch_Offset_USS_r13_28,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"npdcch-Offset-USS-r13"
		},
};
static const ber_tlv_tag_t asn_DEF_NPDCCH_ConfigDedicated_NB_r13_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NPDCCH_ConfigDedicated_NB_r13_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* npdcch-NumRepetitions-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* npdcch-StartSF-USS-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* npdcch-Offset-USS-r13 */
};
asn_SEQUENCE_specifics_t asn_SPC_NPDCCH_ConfigDedicated_NB_r13_specs_1 = {
	sizeof(struct NPDCCH_ConfigDedicated_NB_r13),
	offsetof(struct NPDCCH_ConfigDedicated_NB_r13, _asn_ctx),
	asn_MAP_NPDCCH_ConfigDedicated_NB_r13_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NPDCCH_ConfigDedicated_NB_r13 = {
	"NPDCCH-ConfigDedicated-NB-r13",
	"NPDCCH-ConfigDedicated-NB-r13",
	&asn_OP_SEQUENCE,
	asn_DEF_NPDCCH_ConfigDedicated_NB_r13_tags_1,
	sizeof(asn_DEF_NPDCCH_ConfigDedicated_NB_r13_tags_1)
		/sizeof(asn_DEF_NPDCCH_ConfigDedicated_NB_r13_tags_1[0]), /* 1 */
	asn_DEF_NPDCCH_ConfigDedicated_NB_r13_tags_1,	/* Same as above */
	sizeof(asn_DEF_NPDCCH_ConfigDedicated_NB_r13_tags_1)
		/sizeof(asn_DEF_NPDCCH_ConfigDedicated_NB_r13_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NPDCCH_ConfigDedicated_NB_r13_1,
	3,	/* Elements count */
	&asn_SPC_NPDCCH_ConfigDedicated_NB_r13_specs_1	/* Additional specs */
};

