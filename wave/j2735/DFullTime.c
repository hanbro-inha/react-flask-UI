/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "DFullTime.h"

static asn_TYPE_member_t asn_MBR_DFullTime_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DFullTime, year),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DYear,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"year"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DFullTime, month),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DMonth,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"month"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DFullTime, day),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DDay,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"day"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DFullTime, hour),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DHour,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"hour"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DFullTime, minute),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DMinute,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"minute"
		},
};
static const ber_tlv_tag_t asn_DEF_DFullTime_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_DFullTime_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* year */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* month */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* day */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* hour */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* minute */
};
static asn_SEQUENCE_specifics_t asn_SPC_DFullTime_specs_1 = {
	sizeof(struct DFullTime),
	offsetof(struct DFullTime, _asn_ctx),
	asn_MAP_DFullTime_tag2el_1,
	5,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_DFullTime = {
	"DFullTime",
	"DFullTime",
	&asn_OP_SEQUENCE,
	asn_DEF_DFullTime_tags_1,
	sizeof(asn_DEF_DFullTime_tags_1)
		/sizeof(asn_DEF_DFullTime_tags_1[0]), /* 1 */
	asn_DEF_DFullTime_tags_1,	/* Same as above */
	sizeof(asn_DEF_DFullTime_tags_1)
		/sizeof(asn_DEF_DFullTime_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_DFullTime_1,
	5,	/* Elements count */
	&asn_SPC_DFullTime_specs_1	/* Additional specs */
};

