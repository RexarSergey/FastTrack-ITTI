/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "PhyLayerParameters.h"

asn_TYPE_member_t asn_MBR_PhyLayerParameters_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PhyLayerParameters, ue_TxAntennaSelectionSupported),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ue-TxAntennaSelectionSupported"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PhyLayerParameters, ue_SpecificRefSigsSupported),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ue-SpecificRefSigsSupported"
		},
};
static const ber_tlv_tag_t asn_DEF_PhyLayerParameters_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_PhyLayerParameters_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ue-TxAntennaSelectionSupported */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* ue-SpecificRefSigsSupported */
};
asn_SEQUENCE_specifics_t asn_SPC_PhyLayerParameters_specs_1 = {
	sizeof(struct PhyLayerParameters),
	offsetof(struct PhyLayerParameters, _asn_ctx),
	asn_MAP_PhyLayerParameters_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_PhyLayerParameters = {
	"PhyLayerParameters",
	"PhyLayerParameters",
	&asn_OP_SEQUENCE,
	asn_DEF_PhyLayerParameters_tags_1,
	sizeof(asn_DEF_PhyLayerParameters_tags_1)
		/sizeof(asn_DEF_PhyLayerParameters_tags_1[0]), /* 1 */
	asn_DEF_PhyLayerParameters_tags_1,	/* Same as above */
	sizeof(asn_DEF_PhyLayerParameters_tags_1)
		/sizeof(asn_DEF_PhyLayerParameters_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_PhyLayerParameters_1,
	2,	/* Elements count */
	&asn_SPC_PhyLayerParameters_specs_1	/* Additional specs */
};

