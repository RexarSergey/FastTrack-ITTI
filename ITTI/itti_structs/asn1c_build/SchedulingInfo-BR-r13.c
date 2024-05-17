/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "SchedulingInfo-BR-r13.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_si_Narrowband_r13_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 1 && value <= 16)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_si_TBS_r13_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_si_TBS_r13_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  9 }	/* (0..9) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_si_Narrowband_r13_constr_2 CC_NOTUSED = {
	{ 1, 1 }	/* (1..16) */,
	-1};
static asn_per_constraints_t asn_PER_memb_si_Narrowband_r13_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  1,  16 }	/* (1..16) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_si_TBS_r13_value2enum_3[] = {
	{ 0,	4,	"b152" },
	{ 1,	4,	"b208" },
	{ 2,	4,	"b256" },
	{ 3,	4,	"b328" },
	{ 4,	4,	"b408" },
	{ 5,	4,	"b504" },
	{ 6,	4,	"b600" },
	{ 7,	4,	"b712" },
	{ 8,	4,	"b808" },
	{ 9,	4,	"b936" }
};
static const unsigned int asn_MAP_si_TBS_r13_enum2value_3[] = {
	0,	/* b152(0) */
	1,	/* b208(1) */
	2,	/* b256(2) */
	3,	/* b328(3) */
	4,	/* b408(4) */
	5,	/* b504(5) */
	6,	/* b600(6) */
	7,	/* b712(7) */
	8,	/* b808(8) */
	9	/* b936(9) */
};
static const asn_INTEGER_specifics_t asn_SPC_si_TBS_r13_specs_3 = {
	asn_MAP_si_TBS_r13_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_si_TBS_r13_enum2value_3,	/* N => "tag"; sorted by N */
	10,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_si_TBS_r13_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_si_TBS_r13_3 = {
	"si-TBS-r13",
	"si-TBS-r13",
	&asn_OP_NativeEnumerated,
	asn_DEF_si_TBS_r13_tags_3,
	sizeof(asn_DEF_si_TBS_r13_tags_3)
		/sizeof(asn_DEF_si_TBS_r13_tags_3[0]) - 1, /* 1 */
	asn_DEF_si_TBS_r13_tags_3,	/* Same as above */
	sizeof(asn_DEF_si_TBS_r13_tags_3)
		/sizeof(asn_DEF_si_TBS_r13_tags_3[0]), /* 2 */
	{ &asn_OER_type_si_TBS_r13_constr_3, &asn_PER_type_si_TBS_r13_constr_3, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_si_TBS_r13_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_SchedulingInfo_BR_r13_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SchedulingInfo_BR_r13, si_Narrowband_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_si_Narrowband_r13_constr_2, &asn_PER_memb_si_Narrowband_r13_constr_2,  memb_si_Narrowband_r13_constraint_1 },
		0, 0, /* No default value */
		"si-Narrowband-r13"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SchedulingInfo_BR_r13, si_TBS_r13),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_si_TBS_r13_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"si-TBS-r13"
		},
};
static const ber_tlv_tag_t asn_DEF_SchedulingInfo_BR_r13_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SchedulingInfo_BR_r13_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* si-Narrowband-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* si-TBS-r13 */
};
asn_SEQUENCE_specifics_t asn_SPC_SchedulingInfo_BR_r13_specs_1 = {
	sizeof(struct SchedulingInfo_BR_r13),
	offsetof(struct SchedulingInfo_BR_r13, _asn_ctx),
	asn_MAP_SchedulingInfo_BR_r13_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_SchedulingInfo_BR_r13 = {
	"SchedulingInfo-BR-r13",
	"SchedulingInfo-BR-r13",
	&asn_OP_SEQUENCE,
	asn_DEF_SchedulingInfo_BR_r13_tags_1,
	sizeof(asn_DEF_SchedulingInfo_BR_r13_tags_1)
		/sizeof(asn_DEF_SchedulingInfo_BR_r13_tags_1[0]), /* 1 */
	asn_DEF_SchedulingInfo_BR_r13_tags_1,	/* Same as above */
	sizeof(asn_DEF_SchedulingInfo_BR_r13_tags_1)
		/sizeof(asn_DEF_SchedulingInfo_BR_r13_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_SchedulingInfo_BR_r13_1,
	2,	/* Elements count */
	&asn_SPC_SchedulingInfo_BR_r13_specs_1	/* Additional specs */
};

