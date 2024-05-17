/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-InterNodeDefinitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "SCG-ConfigInfo-r12-IEs.h"

static int
memb_eutra_CapabilityInfo_r12_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		(void)st; /* Unused variable */
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

static int
memb_mbmsInterestIndication_r12_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		(void)st; /* Unused variable */
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

static asn_oer_constraints_t asn_OER_memb_eutra_CapabilityInfo_r12_constr_7 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..MAX)) */};
static asn_per_constraints_t asn_PER_memb_eutra_CapabilityInfo_r12_constr_7 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_SEMI_CONSTRAINED,	-1, -1,  0,  0 }	/* (SIZE(0..MAX)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_mbmsInterestIndication_r12_constr_9 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..MAX)) */};
static asn_per_constraints_t asn_PER_memb_mbmsInterestIndication_r12_constr_9 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_SEMI_CONSTRAINED,	-1, -1,  0,  0 }	/* (SIZE(0..MAX)) */,
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_SCG_ConfigInfo_r12_IEs_1[] = {
	{ ATF_POINTER, 15, offsetof(struct SCG_ConfigInfo_r12_IEs, radioResourceConfigDedMCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RadioResourceConfigDedicated,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"radioResourceConfigDedMCG-r12"
		},
	{ ATF_POINTER, 14, offsetof(struct SCG_ConfigInfo_r12_IEs, sCellToAddModListMCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SCellToAddModList_r10,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sCellToAddModListMCG-r12"
		},
	{ ATF_POINTER, 13, offsetof(struct SCG_ConfigInfo_r12_IEs, measGapConfig_r12),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_MeasGapConfig,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measGapConfig-r12"
		},
	{ ATF_POINTER, 12, offsetof(struct SCG_ConfigInfo_r12_IEs, powerCoordinationInfo_r12),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PowerCoordinationInfo_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"powerCoordinationInfo-r12"
		},
	{ ATF_POINTER, 11, offsetof(struct SCG_ConfigInfo_r12_IEs, scg_RadioConfig_r12),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SCG_ConfigPartSCG_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"scg-RadioConfig-r12"
		},
	{ ATF_POINTER, 10, offsetof(struct SCG_ConfigInfo_r12_IEs, eutra_CapabilityInfo_r12),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{ &asn_OER_memb_eutra_CapabilityInfo_r12_constr_7, &asn_PER_memb_eutra_CapabilityInfo_r12_constr_7,  memb_eutra_CapabilityInfo_r12_constraint_1 },
		0, 0, /* No default value */
		"eutra-CapabilityInfo-r12"
		},
	{ ATF_POINTER, 9, offsetof(struct SCG_ConfigInfo_r12_IEs, scg_ConfigRestrictInfo_r12),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SCG_ConfigRestrictInfo_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"scg-ConfigRestrictInfo-r12"
		},
	{ ATF_POINTER, 8, offsetof(struct SCG_ConfigInfo_r12_IEs, mbmsInterestIndication_r12),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{ &asn_OER_memb_mbmsInterestIndication_r12_constr_9, &asn_PER_memb_mbmsInterestIndication_r12_constr_9,  memb_mbmsInterestIndication_r12_constraint_1 },
		0, 0, /* No default value */
		"mbmsInterestIndication-r12"
		},
	{ ATF_POINTER, 7, offsetof(struct SCG_ConfigInfo_r12_IEs, measResultServCellListSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MeasResultServCellListSCG_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"measResultServCellListSCG-r12"
		},
	{ ATF_POINTER, 6, offsetof(struct SCG_ConfigInfo_r12_IEs, drb_ToAddModListSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DRB_InfoListSCG_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"drb-ToAddModListSCG-r12"
		},
	{ ATF_POINTER, 5, offsetof(struct SCG_ConfigInfo_r12_IEs, drb_ToReleaseListSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (10 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DRB_ToReleaseList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"drb-ToReleaseListSCG-r12"
		},
	{ ATF_POINTER, 4, offsetof(struct SCG_ConfigInfo_r12_IEs, sCellToAddModListSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (11 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SCellToAddModListSCG_r12,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sCellToAddModListSCG-r12"
		},
	{ ATF_POINTER, 3, offsetof(struct SCG_ConfigInfo_r12_IEs, sCellToReleaseListSCG_r12),
		(ASN_TAG_CLASS_CONTEXT | (12 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SCellToReleaseList_r10,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"sCellToReleaseListSCG-r12"
		},
	{ ATF_POINTER, 2, offsetof(struct SCG_ConfigInfo_r12_IEs, p_Max_r12),
		(ASN_TAG_CLASS_CONTEXT | (13 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_P_Max,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"p-Max-r12"
		},
	{ ATF_POINTER, 1, offsetof(struct SCG_ConfigInfo_r12_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (14 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SCG_ConfigInfo_v1310_IEs,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nonCriticalExtension"
		},
};
static const int asn_MAP_SCG_ConfigInfo_r12_IEs_oms_1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
static const ber_tlv_tag_t asn_DEF_SCG_ConfigInfo_r12_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SCG_ConfigInfo_r12_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* radioResourceConfigDedMCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* sCellToAddModListMCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* measGapConfig-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* powerCoordinationInfo-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* scg-RadioConfig-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* eutra-CapabilityInfo-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* scg-ConfigRestrictInfo-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* mbmsInterestIndication-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* measResultServCellListSCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 }, /* drb-ToAddModListSCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (10 << 2)), 10, 0, 0 }, /* drb-ToReleaseListSCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (11 << 2)), 11, 0, 0 }, /* sCellToAddModListSCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (12 << 2)), 12, 0, 0 }, /* sCellToReleaseListSCG-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (13 << 2)), 13, 0, 0 }, /* p-Max-r12 */
    { (ASN_TAG_CLASS_CONTEXT | (14 << 2)), 14, 0, 0 } /* nonCriticalExtension */
};
asn_SEQUENCE_specifics_t asn_SPC_SCG_ConfigInfo_r12_IEs_specs_1 = {
	sizeof(struct SCG_ConfigInfo_r12_IEs),
	offsetof(struct SCG_ConfigInfo_r12_IEs, _asn_ctx),
	asn_MAP_SCG_ConfigInfo_r12_IEs_tag2el_1,
	15,	/* Count of tags in the map */
	asn_MAP_SCG_ConfigInfo_r12_IEs_oms_1,	/* Optional members */
	15, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_SCG_ConfigInfo_r12_IEs = {
	"SCG-ConfigInfo-r12-IEs",
	"SCG-ConfigInfo-r12-IEs",
	&asn_OP_SEQUENCE,
	asn_DEF_SCG_ConfigInfo_r12_IEs_tags_1,
	sizeof(asn_DEF_SCG_ConfigInfo_r12_IEs_tags_1)
		/sizeof(asn_DEF_SCG_ConfigInfo_r12_IEs_tags_1[0]), /* 1 */
	asn_DEF_SCG_ConfigInfo_r12_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_SCG_ConfigInfo_r12_IEs_tags_1)
		/sizeof(asn_DEF_SCG_ConfigInfo_r12_IEs_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_SCG_ConfigInfo_r12_IEs_1,
	15,	/* Elements count */
	&asn_SPC_SCG_ConfigInfo_r12_IEs_specs_1	/* Additional specs */
};

