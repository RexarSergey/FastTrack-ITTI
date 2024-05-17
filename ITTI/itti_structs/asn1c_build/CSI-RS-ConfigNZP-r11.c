/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "CSI-RS-ConfigNZP-r11.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_qcl_ScramblingIdentity_r11_constraint_11(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 503)) {
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
memb_resourceConfig_r11_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 31)) {
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
memb_subframeConfig_r11_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 154)) {
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
memb_scramblingIdentity_r11_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 503)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_antennaPortsCount_r11_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_antennaPortsCount_r11_constr_3 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_crs_PortsCount_r11_constr_13 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_crs_PortsCount_r11_constr_13 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_mbsfn_SubframeConfigList_r11_constr_18 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_mbsfn_SubframeConfigList_r11_constr_18 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_qcl_ScramblingIdentity_r11_constr_12 CC_NOTUSED = {
	{ 2, 1 }	/* (0..503) */,
	-1};
static asn_per_constraints_t asn_PER_memb_qcl_ScramblingIdentity_r11_constr_12 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 9,  9,  0,  503 }	/* (0..503) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_mbsfn_SubframeConfigList_v1430_constr_26 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_mbsfn_SubframeConfigList_v1430_constr_26 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_resourceConfig_r11_constr_8 CC_NOTUSED = {
	{ 1, 1 }	/* (0..31) */,
	-1};
static asn_per_constraints_t asn_PER_memb_resourceConfig_r11_constr_8 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 5,  5,  0,  31 }	/* (0..31) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_subframeConfig_r11_constr_9 CC_NOTUSED = {
	{ 1, 1 }	/* (0..154) */,
	-1};
static asn_per_constraints_t asn_PER_memb_subframeConfig_r11_constr_9 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  154 }	/* (0..154) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_scramblingIdentity_r11_constr_10 CC_NOTUSED = {
	{ 2, 1 }	/* (0..503) */,
	-1};
static asn_per_constraints_t asn_PER_memb_scramblingIdentity_r11_constr_10 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 9,  9,  0,  503 }	/* (0..503) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_antennaPortsCount_r11_value2enum_3[] = {
	{ 0,	3,	"an1" },
	{ 1,	3,	"an2" },
	{ 2,	3,	"an4" },
	{ 3,	3,	"an8" }
};
static const unsigned int asn_MAP_antennaPortsCount_r11_enum2value_3[] = {
	0,	/* an1(0) */
	1,	/* an2(1) */
	2,	/* an4(2) */
	3	/* an8(3) */
};
static const asn_INTEGER_specifics_t asn_SPC_antennaPortsCount_r11_specs_3 = {
	asn_MAP_antennaPortsCount_r11_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_antennaPortsCount_r11_enum2value_3,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_antennaPortsCount_r11_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_antennaPortsCount_r11_3 = {
	"antennaPortsCount-r11",
	"antennaPortsCount-r11",
	&asn_OP_NativeEnumerated,
	asn_DEF_antennaPortsCount_r11_tags_3,
	sizeof(asn_DEF_antennaPortsCount_r11_tags_3)
		/sizeof(asn_DEF_antennaPortsCount_r11_tags_3[0]) - 1, /* 1 */
	asn_DEF_antennaPortsCount_r11_tags_3,	/* Same as above */
	sizeof(asn_DEF_antennaPortsCount_r11_tags_3)
		/sizeof(asn_DEF_antennaPortsCount_r11_tags_3[0]), /* 2 */
	{ &asn_OER_type_antennaPortsCount_r11_constr_3, &asn_PER_type_antennaPortsCount_r11_constr_3, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_antennaPortsCount_r11_specs_3	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_crs_PortsCount_r11_value2enum_13[] = {
	{ 0,	2,	"n1" },
	{ 1,	2,	"n2" },
	{ 2,	2,	"n4" },
	{ 3,	6,	"spare1" }
};
static const unsigned int asn_MAP_crs_PortsCount_r11_enum2value_13[] = {
	0,	/* n1(0) */
	1,	/* n2(1) */
	2,	/* n4(2) */
	3	/* spare1(3) */
};
static const asn_INTEGER_specifics_t asn_SPC_crs_PortsCount_r11_specs_13 = {
	asn_MAP_crs_PortsCount_r11_value2enum_13,	/* "tag" => N; sorted by tag */
	asn_MAP_crs_PortsCount_r11_enum2value_13,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_crs_PortsCount_r11_tags_13[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_crs_PortsCount_r11_13 = {
	"crs-PortsCount-r11",
	"crs-PortsCount-r11",
	&asn_OP_NativeEnumerated,
	asn_DEF_crs_PortsCount_r11_tags_13,
	sizeof(asn_DEF_crs_PortsCount_r11_tags_13)
		/sizeof(asn_DEF_crs_PortsCount_r11_tags_13[0]) - 1, /* 1 */
	asn_DEF_crs_PortsCount_r11_tags_13,	/* Same as above */
	sizeof(asn_DEF_crs_PortsCount_r11_tags_13)
		/sizeof(asn_DEF_crs_PortsCount_r11_tags_13[0]), /* 2 */
	{ &asn_OER_type_crs_PortsCount_r11_constr_13, &asn_PER_type_crs_PortsCount_r11_constr_13, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_crs_PortsCount_r11_specs_13	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_setup_20[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11__setup, subframeConfigList),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MBSFN_SubframeConfigList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"subframeConfigList"
		},
};
static const ber_tlv_tag_t asn_DEF_setup_tags_20[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_setup_tag2el_20[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* subframeConfigList */
};
static asn_SEQUENCE_specifics_t asn_SPC_setup_specs_20 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11__setup),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11__setup, _asn_ctx),
	asn_MAP_setup_tag2el_20,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_setup_20 = {
	"setup",
	"setup",
	&asn_OP_SEQUENCE,
	asn_DEF_setup_tags_20,
	sizeof(asn_DEF_setup_tags_20)
		/sizeof(asn_DEF_setup_tags_20[0]) - 1, /* 1 */
	asn_DEF_setup_tags_20,	/* Same as above */
	sizeof(asn_DEF_setup_tags_20)
		/sizeof(asn_DEF_setup_tags_20[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_setup_20,
	1,	/* Elements count */
	&asn_SPC_setup_specs_20	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_mbsfn_SubframeConfigList_r11_18[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_setup_20,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"setup"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_mbsfn_SubframeConfigList_r11_tag2el_18[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup */
};
static asn_CHOICE_specifics_t asn_SPC_mbsfn_SubframeConfigList_r11_specs_18 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, _asn_ctx),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11, present),
	sizeof(((struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11__mbsfn_SubframeConfigList_r11 *)0)->present),
	asn_MAP_mbsfn_SubframeConfigList_r11_tag2el_18,
	2,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mbsfn_SubframeConfigList_r11_18 = {
	"mbsfn-SubframeConfigList-r11",
	"mbsfn-SubframeConfigList-r11",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_mbsfn_SubframeConfigList_r11_constr_18, &asn_PER_type_mbsfn_SubframeConfigList_r11_constr_18, CHOICE_constraint },
	asn_MBR_mbsfn_SubframeConfigList_r11_18,
	2,	/* Elements count */
	&asn_SPC_mbsfn_SubframeConfigList_r11_specs_18	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_qcl_CRS_Info_r11_11[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, qcl_ScramblingIdentity_r11),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_qcl_ScramblingIdentity_r11_constr_12, &asn_PER_memb_qcl_ScramblingIdentity_r11_constr_12,  memb_qcl_ScramblingIdentity_r11_constraint_11 },
		0, 0, /* No default value */
		"qcl-ScramblingIdentity-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, crs_PortsCount_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_crs_PortsCount_r11_13,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"crs-PortsCount-r11"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, mbsfn_SubframeConfigList_r11),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_mbsfn_SubframeConfigList_r11_18,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"mbsfn-SubframeConfigList-r11"
		},
};
static const int asn_MAP_qcl_CRS_Info_r11_oms_11[] = { 2 };
static const ber_tlv_tag_t asn_DEF_qcl_CRS_Info_r11_tags_11[] = {
	(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_qcl_CRS_Info_r11_tag2el_11[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* qcl-ScramblingIdentity-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* crs-PortsCount-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* mbsfn-SubframeConfigList-r11 */
};
static asn_SEQUENCE_specifics_t asn_SPC_qcl_CRS_Info_r11_specs_11 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11),
	offsetof(struct CSI_RS_ConfigNZP_r11__qcl_CRS_Info_r11, _asn_ctx),
	asn_MAP_qcl_CRS_Info_r11_tag2el_11,
	3,	/* Count of tags in the map */
	asn_MAP_qcl_CRS_Info_r11_oms_11,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_qcl_CRS_Info_r11_11 = {
	"qcl-CRS-Info-r11",
	"qcl-CRS-Info-r11",
	&asn_OP_SEQUENCE,
	asn_DEF_qcl_CRS_Info_r11_tags_11,
	sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11)
		/sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11[0]) - 1, /* 1 */
	asn_DEF_qcl_CRS_Info_r11_tags_11,	/* Same as above */
	sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11)
		/sizeof(asn_DEF_qcl_CRS_Info_r11_tags_11[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_qcl_CRS_Info_r11_11,
	3,	/* Elements count */
	&asn_SPC_qcl_CRS_Info_r11_specs_11	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_setup_28[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430__setup, subframeConfigList_v1430),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MBSFN_SubframeConfigList_v1430,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"subframeConfigList-v1430"
		},
};
static const ber_tlv_tag_t asn_DEF_setup_tags_28[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_setup_tag2el_28[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* subframeConfigList-v1430 */
};
static asn_SEQUENCE_specifics_t asn_SPC_setup_specs_28 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430__setup),
	offsetof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430__setup, _asn_ctx),
	asn_MAP_setup_tag2el_28,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_setup_28 = {
	"setup",
	"setup",
	&asn_OP_SEQUENCE,
	asn_DEF_setup_tags_28,
	sizeof(asn_DEF_setup_tags_28)
		/sizeof(asn_DEF_setup_tags_28[0]) - 1, /* 1 */
	asn_DEF_setup_tags_28,	/* Same as above */
	sizeof(asn_DEF_setup_tags_28)
		/sizeof(asn_DEF_setup_tags_28[0]), /* 2 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_setup_28,
	1,	/* Elements count */
	&asn_SPC_setup_specs_28	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_mbsfn_SubframeConfigList_v1430_26[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430, choice.release),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NULL,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"release"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430, choice.setup),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_setup_28,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"setup"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_mbsfn_SubframeConfigList_v1430_tag2el_26[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* release */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* setup */
};
static asn_CHOICE_specifics_t asn_SPC_mbsfn_SubframeConfigList_v1430_specs_26 = {
	sizeof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430),
	offsetof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430, _asn_ctx),
	offsetof(struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430, present),
	sizeof(((struct CSI_RS_ConfigNZP_r11__mbsfn_SubframeConfigList_v1430 *)0)->present),
	asn_MAP_mbsfn_SubframeConfigList_v1430_tag2el_26,
	2,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mbsfn_SubframeConfigList_v1430_26 = {
	"mbsfn-SubframeConfigList-v1430",
	"mbsfn-SubframeConfigList-v1430",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_mbsfn_SubframeConfigList_v1430_constr_26, &asn_PER_type_mbsfn_SubframeConfigList_v1430_constr_26, CHOICE_constraint },
	asn_MBR_mbsfn_SubframeConfigList_v1430_26,
	2,	/* Elements count */
	&asn_SPC_mbsfn_SubframeConfigList_v1430_specs_26	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_CSI_RS_ConfigNZP_r11_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, csi_RS_ConfigNZPId_r11),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigNZPId_r11,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"csi-RS-ConfigNZPId-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, antennaPortsCount_r11),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_antennaPortsCount_r11_3,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"antennaPortsCount-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, resourceConfig_r11),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_resourceConfig_r11_constr_8, &asn_PER_memb_resourceConfig_r11_constr_8,  memb_resourceConfig_r11_constraint_1 },
		0, 0, /* No default value */
		"resourceConfig-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, subframeConfig_r11),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_subframeConfig_r11_constr_9, &asn_PER_memb_subframeConfig_r11_constr_9,  memb_subframeConfig_r11_constraint_1 },
		0, 0, /* No default value */
		"subframeConfig-r11"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct CSI_RS_ConfigNZP_r11, scramblingIdentity_r11),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_scramblingIdentity_r11_constr_10, &asn_PER_memb_scramblingIdentity_r11_constr_10,  memb_scramblingIdentity_r11_constraint_1 },
		0, 0, /* No default value */
		"scramblingIdentity-r11"
		},
	{ ATF_POINTER, 5, offsetof(struct CSI_RS_ConfigNZP_r11, qcl_CRS_Info_r11),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		0,
		&asn_DEF_qcl_CRS_Info_r11_11,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"qcl-CRS-Info-r11"
		},
	{ ATF_POINTER, 4, offsetof(struct CSI_RS_ConfigNZP_r11, csi_RS_ConfigNZPId_v1310),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CSI_RS_ConfigNZPId_v1310,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"csi-RS-ConfigNZPId-v1310"
		},
	{ ATF_POINTER, 3, offsetof(struct CSI_RS_ConfigNZP_r11, transmissionComb_r14),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NZP_TransmissionComb_r14,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"transmissionComb-r14"
		},
	{ ATF_POINTER, 2, offsetof(struct CSI_RS_ConfigNZP_r11, frequencyDensity_r14),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NZP_FrequencyDensity_r14,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"frequencyDensity-r14"
		},
	{ ATF_POINTER, 1, offsetof(struct CSI_RS_ConfigNZP_r11, mbsfn_SubframeConfigList_v1430),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_mbsfn_SubframeConfigList_v1430_26,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"mbsfn-SubframeConfigList-v1430"
		},
};
static const int asn_MAP_CSI_RS_ConfigNZP_r11_oms_1[] = { 5, 6, 7, 8, 9 };
static const ber_tlv_tag_t asn_DEF_CSI_RS_ConfigNZP_r11_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CSI_RS_ConfigNZP_r11_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* csi-RS-ConfigNZPId-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* antennaPortsCount-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* resourceConfig-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* subframeConfig-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* scramblingIdentity-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* qcl-CRS-Info-r11 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* csi-RS-ConfigNZPId-v1310 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* transmissionComb-r14 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* frequencyDensity-r14 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* mbsfn-SubframeConfigList-v1430 */
};
asn_SEQUENCE_specifics_t asn_SPC_CSI_RS_ConfigNZP_r11_specs_1 = {
	sizeof(struct CSI_RS_ConfigNZP_r11),
	offsetof(struct CSI_RS_ConfigNZP_r11, _asn_ctx),
	asn_MAP_CSI_RS_ConfigNZP_r11_tag2el_1,
	10,	/* Count of tags in the map */
	asn_MAP_CSI_RS_ConfigNZP_r11_oms_1,	/* Optional members */
	1, 4,	/* Root/Additions */
	6,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_CSI_RS_ConfigNZP_r11 = {
	"CSI-RS-ConfigNZP-r11",
	"CSI-RS-ConfigNZP-r11",
	&asn_OP_SEQUENCE,
	asn_DEF_CSI_RS_ConfigNZP_r11_tags_1,
	sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1)
		/sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1[0]), /* 1 */
	asn_DEF_CSI_RS_ConfigNZP_r11_tags_1,	/* Same as above */
	sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1)
		/sizeof(asn_DEF_CSI_RS_ConfigNZP_r11_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_CSI_RS_ConfigNZP_r11_1,
	10,	/* Elements count */
	&asn_SPC_CSI_RS_ConfigNZP_r11_specs_1	/* Additional specs */
};

