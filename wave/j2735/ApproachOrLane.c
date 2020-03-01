/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "ApproachOrLane.h"

static asn_oer_constraints_t asn_OER_type_ApproachOrLane_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_ApproachOrLane_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 1,  1,  0,  1 }	/* (0..1) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_ApproachOrLane_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ApproachOrLane, approach),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ApproachID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"approach"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ApproachOrLane, lane),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LaneID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"lane"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_ApproachOrLane_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* approach */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* lane */
};
asn_CHOICE_specifics_t asn_SPC_ApproachOrLane_specs_1 = {
	sizeof(struct ApproachOrLane),
	offsetof(struct ApproachOrLane, _asn_ctx),
	offsetof(struct ApproachOrLane, present),
	sizeof(((struct ApproachOrLane *)0)->present),
	asn_MAP_ApproachOrLane_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_ApproachOrLane = {
	"ApproachOrLane",
	"ApproachOrLane",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_ApproachOrLane_constr_1, &asn_PER_type_ApproachOrLane_constr_1, CHOICE_constraint },
	asn_MBR_ApproachOrLane_1,
	2,	/* Elements count */
	&asn_SPC_ApproachOrLane_specs_1	/* Additional specs */
};

