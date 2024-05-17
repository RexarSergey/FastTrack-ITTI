/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "UE-EUTRA-Capability-v1250-IEs.h"

static int
memb_ue_CategoryDL_r12_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 14)) {
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
memb_ue_CategoryUL_r12_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 13)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_memb_ue_CategoryDL_r12_constr_6 CC_NOTUSED = {
	{ 1, 1 }	/* (0..14) */,
	-1};
static asn_per_constraints_t asn_PER_memb_ue_CategoryDL_r12_constr_6 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  14 }	/* (0..14) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_ue_CategoryUL_r12_constr_7 CC_NOTUSED = {
	{ 1, 1 }	/* (0..13) */,
	-1};
static asn_per_constraints_t asn_PER_memb_ue_CategoryUL_r12_constr_7 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 4,  4,  0,  13 }	/* (0..13) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_UE_EUTRA_Capability_v1250_IEs_1[] = {
	{ ATF_POINTER, 15, offsetof(struct UE_EUTRA_Capability_v1250_IEs, phyLayerParameters_v1250),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PhyLayerParameters_v1250,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"phyLayerParameters-v1250"
		},
	{ ATF_POINTER, 14, offsetof(struct UE_EUTRA_Capability_v1250_IEs, rf_Parameters_v1250),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RF_Parameters_v1250,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"rf-Parameters-v1250"
		},
	{ ATF_POINTER, 13, offsetof(struct UE_EUTRA_Capability_v1250_IEs, rlc_Parameters_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RLC_Parameters_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"rlc-Parameters-r12"
		},
	{ ATF_POINTER, 12, offsetof(struct UE_EUTRA_Capability_v1250_IEs, ue_BasedNetwPerfMeasParameters_v1250),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UE_BasedNetwPerfMeasParameters_v1250,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ue-BasedNetwPerfMeasParameters-v1250"
		},
	{ ATF_POINTER, 11, offsetof(struct UE_EUTRA_Capability_v1250_IEs, ue_CategoryDL_r12),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_ue_CategoryDL_r12_constr_6, &asn_PER_memb_ue_CategoryDL_r12_constr_6,  memb_ue_CategoryDL_r12_constraint_1 },
		0, 0, /* No default value */
		"ue-CategoryDL-r12"
		},
	{ ATF_POINTER, 10, offsetof(struct UE_EUTRA_Capability_v1250_IEs, ue_CategoryUL_r12),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_ue_CategoryUL_r12_constr_7, &asn_PER_memb_ue_CategoryUL_r12_constr_7,  memb_ue_CategoryUL_r12_constraint_1 },
		0, 0, /* No default value */
		"ue-CategoryUL-r12"
		},
	{ ATF_POINTER, 9, offsetof(struct UE_EUTRA_Capability_v1250_IEs, wlan_IW_Parameters_r12),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_WLAN_IW_Parameters_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"wlan-IW-Parameters-r12"
		},
	{ ATF_POINTER, 8, offsetof(struct UE_EUTRA_Capability_v1250_IEs, measParameters_v1250),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasParameters_v1250,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measParameters-v1250"
		},
	{ ATF_POINTER, 7, offsetof(struct UE_EUTRA_Capability_v1250_IEs, dc_Parameters_r12),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DC_Parameters_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"dc-Parameters-r12"
		},
	{ ATF_POINTER, 6, offsetof(struct UE_EUTRA_Capability_v1250_IEs, mbms_Parameters_v1250),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MBMS_Parameters_v1250,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"mbms-Parameters-v1250"
		},
	{ ATF_POINTER, 5, offsetof(struct UE_EUTRA_Capability_v1250_IEs, mac_Parameters_r12),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MAC_Parameters_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"mac-Parameters-r12"
		},
	{ ATF_POINTER, 4, offsetof(struct UE_EUTRA_Capability_v1250_IEs, fdd_Add_UE_EUTRA_Capabilities_v1250),
		(ASN_TAG_CLASS_CONTEXT | (11 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UE_EUTRA_CapabilityAddXDD_Mode_v1250,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"fdd-Add-UE-EUTRA-Capabilities-v1250"
		},
	{ ATF_POINTER, 3, offsetof(struct UE_EUTRA_Capability_v1250_IEs, tdd_Add_UE_EUTRA_Capabilities_v1250),
		(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UE_EUTRA_CapabilityAddXDD_Mode_v1250,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"tdd-Add-UE-EUTRA-Capabilities-v1250"
		},
	{ ATF_POINTER, 2, offsetof(struct UE_EUTRA_Capability_v1250_IEs, sl_Parameters_r12),
		(ASN_TAG_CLASS_CONTEXT | (13 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SL_Parameters_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sl-Parameters-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct UE_EUTRA_Capability_v1250_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (14 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UE_EUTRA_Capability_v1260_IEs,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nonCriticalExtension"
		},
};
static const int asn_MAP_UE_EUTRA_Capability_v1250_IEs_oms_1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
static const ber_tlv_tag_t asn_DEF_UE_EUTRA_Capability_v1250_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_UE_EUTRA_Capability_v1250_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* phyLayerParameters-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* rf-Parameters-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* rlc-Parameters-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* ue-BasedNetwPerfMeasParameters-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* ue-CategoryDL-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* ue-CategoryUL-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* wlan-IW-Parameters-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* measParameters-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* dc-Parameters-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* mbms-Parameters-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* mac-Parameters-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* fdd-Add-UE-EUTRA-Capabilities-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 }, /* tdd-Add-UE-EUTRA-Capabilities-v1250 */
    { (ASN_TAG_CLASS_CONTEXT | (13 << 2)), 13, 0, 0 }, /* sl-Parameters-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (14 << 2)), 14, 0, 0 } /* nonCriticalExtension */
};
asn_SEQUENCE_specifics_t asn_SPC_UE_EUTRA_Capability_v1250_IEs_specs_1 = {
	sizeof(struct UE_EUTRA_Capability_v1250_IEs),
	offsetof(struct UE_EUTRA_Capability_v1250_IEs, _asn_ctx),
	asn_MAP_UE_EUTRA_Capability_v1250_IEs_tag2el_1,
	15,	/* Count of tags in the map */
	asn_MAP_UE_EUTRA_Capability_v1250_IEs_oms_1,	/* Optional members */
	15, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_UE_EUTRA_Capability_v1250_IEs = {
	"UE-EUTRA-Capability-v1250-IEs",
	"UE-EUTRA-Capability-v1250-IEs",
	&asn_OP_SEQUENCE,
	asn_DEF_UE_EUTRA_Capability_v1250_IEs_tags_1,
	sizeof(asn_DEF_UE_EUTRA_Capability_v1250_IEs_tags_1)
		/sizeof(asn_DEF_UE_EUTRA_Capability_v1250_IEs_tags_1[0]), /* 1 */
	asn_DEF_UE_EUTRA_Capability_v1250_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_UE_EUTRA_Capability_v1250_IEs_tags_1)
		/sizeof(asn_DEF_UE_EUTRA_Capability_v1250_IEs_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_UE_EUTRA_Capability_v1250_IEs_1,
	15,	/* Elements count */
	&asn_SPC_UE_EUTRA_Capability_v1250_IEs_specs_1	/* Additional specs */
};

