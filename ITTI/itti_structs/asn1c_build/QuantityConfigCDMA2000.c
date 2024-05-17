/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "QuantityConfigCDMA2000.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_measQuantityCDMA2000_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_measQuantityCDMA2000_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_measQuantityCDMA2000_value2enum_2[] = {
	{ 0,	13,	"pilotStrength" },
	{ 1,	28,	"pilotPnPhaseAndPilotStrength" }
};
static const unsigned int asn_MAP_measQuantityCDMA2000_enum2value_2[] = {
	1,	/* pilotPnPhaseAndPilotStrength(1) */
	0	/* pilotStrength(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_measQuantityCDMA2000_specs_2 = {
	asn_MAP_measQuantityCDMA2000_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_measQuantityCDMA2000_enum2value_2,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_measQuantityCDMA2000_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_measQuantityCDMA2000_2 = {
	"measQuantityCDMA2000",
	"measQuantityCDMA2000",
	&asn_OP_NativeEnumerated,
	asn_DEF_measQuantityCDMA2000_tags_2,
	sizeof(asn_DEF_measQuantityCDMA2000_tags_2)
		/sizeof(asn_DEF_measQuantityCDMA2000_tags_2[0]) - 1, /* 1 */
	asn_DEF_measQuantityCDMA2000_tags_2,	/* Same as above */
	sizeof(asn_DEF_measQuantityCDMA2000_tags_2)
		/sizeof(asn_DEF_measQuantityCDMA2000_tags_2[0]), /* 2 */
	{ &asn_OER_type_measQuantityCDMA2000_constr_2, &asn_PER_type_measQuantityCDMA2000_constr_2, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_measQuantityCDMA2000_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_QuantityConfigCDMA2000_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct QuantityConfigCDMA2000, measQuantityCDMA2000),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_measQuantityCDMA2000_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measQuantityCDMA2000"
		},
};
static const ber_tlv_tag_t asn_DEF_QuantityConfigCDMA2000_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_QuantityConfigCDMA2000_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* measQuantityCDMA2000 */
};
asn_SEQUENCE_specifics_t asn_SPC_QuantityConfigCDMA2000_specs_1 = {
	sizeof(struct QuantityConfigCDMA2000),
	offsetof(struct QuantityConfigCDMA2000, _asn_ctx),
	asn_MAP_QuantityConfigCDMA2000_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_QuantityConfigCDMA2000 = {
	"QuantityConfigCDMA2000",
	"QuantityConfigCDMA2000",
	&asn_OP_SEQUENCE,
	asn_DEF_QuantityConfigCDMA2000_tags_1,
	sizeof(asn_DEF_QuantityConfigCDMA2000_tags_1)
		/sizeof(asn_DEF_QuantityConfigCDMA2000_tags_1[0]), /* 1 */
	asn_DEF_QuantityConfigCDMA2000_tags_1,	/* Same as above */
	sizeof(asn_DEF_QuantityConfigCDMA2000_tags_1)
		/sizeof(asn_DEF_QuantityConfigCDMA2000_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_QuantityConfigCDMA2000_1,
	1,	/* Elements count */
	&asn_SPC_QuantityConfigCDMA2000_specs_1	/* Additional specs */
};

