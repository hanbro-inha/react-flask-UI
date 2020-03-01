/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "IntersectionGeometry.h"

static int
memb_regional_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size >= 1 && size <= 4)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_regional_constr_10 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
static asn_per_constraints_t asn_PER_type_regional_constr_10 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_regional_constr_10 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..4)) */};
static asn_per_constraints_t asn_PER_memb_regional_constr_10 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  4 }	/* (SIZE(1..4)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_regional_10[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_RegionalExtension_124P0,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_regional_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_regional_specs_10 = {
	sizeof(struct IntersectionGeometry__regional),
	offsetof(struct IntersectionGeometry__regional, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_regional_10 = {
	"regional",
	"regional",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_regional_tags_10,
	sizeof(asn_DEF_regional_tags_10)
		/sizeof(asn_DEF_regional_tags_10[0]) - 1, /* 1 */
	asn_DEF_regional_tags_10,	/* Same as above */
	sizeof(asn_DEF_regional_tags_10)
		/sizeof(asn_DEF_regional_tags_10[0]), /* 2 */
	{ &asn_OER_type_regional_constr_10, &asn_PER_type_regional_constr_10, SEQUENCE_OF_constraint },
	asn_MBR_regional_10,
	1,	/* Single element */
	&asn_SPC_regional_specs_10	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_IntersectionGeometry_1[] = {
	{ ATF_POINTER, 1, offsetof(struct IntersectionGeometry, name),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DescriptiveName,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"name"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IntersectionGeometry, id),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IntersectionReferenceID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"id"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IntersectionGeometry, revision),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DSRC_MsgCount,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"revision"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IntersectionGeometry, refPoint),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Position3D,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"refPoint"
		},
	{ ATF_POINTER, 2, offsetof(struct IntersectionGeometry, laneWidth),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LaneWidth,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"laneWidth"
		},
	{ ATF_POINTER, 1, offsetof(struct IntersectionGeometry, speedLimits),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SpeedLimitList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"speedLimits"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct IntersectionGeometry, laneSet),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LaneList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"laneSet"
		},
	{ ATF_POINTER, 2, offsetof(struct IntersectionGeometry, preemptPriorityData),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_PreemptPriorityList,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"preemptPriorityData"
		},
	{ ATF_POINTER, 1, offsetof(struct IntersectionGeometry, regional),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		0,
		&asn_DEF_regional_10,
		0,
		{ &asn_OER_memb_regional_constr_10, &asn_PER_memb_regional_constr_10,  memb_regional_constraint_1 },
		0, 0, /* No default value */
		"regional"
		},
};
static const int asn_MAP_IntersectionGeometry_oms_1[] = { 0, 4, 5, 7, 8 };
static const ber_tlv_tag_t asn_DEF_IntersectionGeometry_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_IntersectionGeometry_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* name */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* id */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* revision */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* refPoint */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* laneWidth */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* speedLimits */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* laneSet */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* preemptPriorityData */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 } /* regional */
};
asn_SEQUENCE_specifics_t asn_SPC_IntersectionGeometry_specs_1 = {
	sizeof(struct IntersectionGeometry),
	offsetof(struct IntersectionGeometry, _asn_ctx),
	asn_MAP_IntersectionGeometry_tag2el_1,
	9,	/* Count of tags in the map */
	asn_MAP_IntersectionGeometry_oms_1,	/* Optional members */
	5, 0,	/* Root/Additions */
	9,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_IntersectionGeometry = {
	"IntersectionGeometry",
	"IntersectionGeometry",
	&asn_OP_SEQUENCE,
	asn_DEF_IntersectionGeometry_tags_1,
	sizeof(asn_DEF_IntersectionGeometry_tags_1)
		/sizeof(asn_DEF_IntersectionGeometry_tags_1[0]), /* 1 */
	asn_DEF_IntersectionGeometry_tags_1,	/* Same as above */
	sizeof(asn_DEF_IntersectionGeometry_tags_1)
		/sizeof(asn_DEF_IntersectionGeometry_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_IntersectionGeometry_1,
	9,	/* Elements count */
	&asn_SPC_IntersectionGeometry_specs_1	/* Additional specs */
};

