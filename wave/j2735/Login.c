/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "Login.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static int
memb_datex_Sender_txt_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const UTF8String_t *st = (const UTF8String_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = UTF8String_length(st);
	if((ssize_t)size < 0) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: UTF-8: broken encoding (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if((size <= 40)) {
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
memb_datex_Destination_txt_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const UTF8String_t *st = (const UTF8String_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = UTF8String_length(st);
	if((ssize_t)size < 0) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: UTF-8: broken encoding (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if((size <= 40)) {
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
memb_datexLogin_HeartbeatDurationMax_qty_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 65535)) {
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
memb_datexLogin_ResponseTimeOut_qty_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 255)) {
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
memb_datexLogin_DatagramSize_qty_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 65535)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_datexLogin_Initiator_cd_constr_10 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_datexLogin_Initiator_cd_constr_10 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_datex_Sender_txt_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..MAX)) */};
static asn_per_constraints_t asn_PER_memb_datex_Sender_txt_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_datex_Destination_txt_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..MAX)) */};
static asn_per_constraints_t asn_PER_memb_datex_Destination_txt_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_datexLogin_HeartbeatDurationMax_qty_constr_8 CC_NOTUSED = {
	{ 2, 1 }	/* (0..65535) */,
	-1};
static asn_per_constraints_t asn_PER_memb_datexLogin_HeartbeatDurationMax_qty_constr_8 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 16,  16,  0,  65535 }	/* (0..65535) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_datexLogin_ResponseTimeOut_qty_constr_9 CC_NOTUSED = {
	{ 1, 1 }	/* (0..255) */,
	-1};
static asn_per_constraints_t asn_PER_memb_datexLogin_ResponseTimeOut_qty_constr_9 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 8,  8,  0,  255 }	/* (0..255) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_datexLogin_DatagramSize_qty_constr_14 CC_NOTUSED = {
	{ 2, 1 }	/* (0..65535) */,
	-1};
static asn_per_constraints_t asn_PER_memb_datexLogin_DatagramSize_qty_constr_14 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 16,  16,  0,  65535 }	/* (0..65535) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_datexLogin_EncodingRules_id_6[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
		0,
		&asn_DEF_OBJECT_IDENTIFIER,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_datexLogin_EncodingRules_id_tags_6[] = {
	(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_datexLogin_EncodingRules_id_specs_6 = {
	sizeof(struct Login__datexLogin_EncodingRules_id),
	offsetof(struct Login__datexLogin_EncodingRules_id, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_datexLogin_EncodingRules_id_6 = {
	"datexLogin-EncodingRules-id",
	"datexLogin-EncodingRules-id",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_datexLogin_EncodingRules_id_tags_6,
	sizeof(asn_DEF_datexLogin_EncodingRules_id_tags_6)
		/sizeof(asn_DEF_datexLogin_EncodingRules_id_tags_6[0]) - 1, /* 1 */
	asn_DEF_datexLogin_EncodingRules_id_tags_6,	/* Same as above */
	sizeof(asn_DEF_datexLogin_EncodingRules_id_tags_6)
		/sizeof(asn_DEF_datexLogin_EncodingRules_id_tags_6[0]), /* 2 */
	{ 0, 0, SEQUENCE_OF_constraint },
	asn_MBR_datexLogin_EncodingRules_id_6,
	1,	/* Single element */
	&asn_SPC_datexLogin_EncodingRules_id_specs_6	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_datexLogin_Initiator_cd_value2enum_10[] = {
	{ 0,	15,	"serverInitiated" },
	{ 1,	15,	"clientInitiated" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_datexLogin_Initiator_cd_enum2value_10[] = {
	1,	/* clientInitiated(1) */
	0	/* serverInitiated(0) */
	/* This list is extensible */
};
static const asn_INTEGER_specifics_t asn_SPC_datexLogin_Initiator_cd_specs_10 = {
	asn_MAP_datexLogin_Initiator_cd_value2enum_10,	/* "tag" => N; sorted by tag */
	asn_MAP_datexLogin_Initiator_cd_enum2value_10,	/* N => "tag"; sorted by N */
	2,	/* Number of elements in the maps */
	3,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_datexLogin_Initiator_cd_tags_10[] = {
	(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_datexLogin_Initiator_cd_10 = {
	"datexLogin-Initiator-cd",
	"datexLogin-Initiator-cd",
	&asn_OP_NativeEnumerated,
	asn_DEF_datexLogin_Initiator_cd_tags_10,
	sizeof(asn_DEF_datexLogin_Initiator_cd_tags_10)
		/sizeof(asn_DEF_datexLogin_Initiator_cd_tags_10[0]) - 1, /* 1 */
	asn_DEF_datexLogin_Initiator_cd_tags_10,	/* Same as above */
	sizeof(asn_DEF_datexLogin_Initiator_cd_tags_10)
		/sizeof(asn_DEF_datexLogin_Initiator_cd_tags_10[0]), /* 2 */
	{ &asn_OER_type_datexLogin_Initiator_cd_constr_10, &asn_PER_type_datexLogin_Initiator_cd_constr_10, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_datexLogin_Initiator_cd_specs_10	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_Login_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datex_Sender_txt),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,
		{ &asn_OER_memb_datex_Sender_txt_constr_2, &asn_PER_memb_datex_Sender_txt_constr_2,  memb_datex_Sender_txt_constraint_1 },
		0, 0, /* No default value */
		"datex-Sender-txt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datex_Destination_txt),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,
		{ &asn_OER_memb_datex_Destination_txt_constr_3, &asn_PER_memb_datex_Destination_txt_constr_3,  memb_datex_Destination_txt_constraint_1 },
		0, 0, /* No default value */
		"datex-Destination-txt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datexLogin_UserName_txt),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"datexLogin-UserName-txt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datexLogin_Password_txt),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"datexLogin-Password-txt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datexLogin_EncodingRules_id),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		0,
		&asn_DEF_datexLogin_EncodingRules_id_6,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"datexLogin-EncodingRules-id"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datexLogin_HeartbeatDurationMax_qty),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_datexLogin_HeartbeatDurationMax_qty_constr_8, &asn_PER_memb_datexLogin_HeartbeatDurationMax_qty_constr_8,  memb_datexLogin_HeartbeatDurationMax_qty_constraint_1 },
		0, 0, /* No default value */
		"datexLogin-HeartbeatDurationMax-qty"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datexLogin_ResponseTimeOut_qty),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_datexLogin_ResponseTimeOut_qty_constr_9, &asn_PER_memb_datexLogin_ResponseTimeOut_qty_constr_9,  memb_datexLogin_ResponseTimeOut_qty_constraint_1 },
		0, 0, /* No default value */
		"datexLogin-ResponseTimeOut-qty"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datexLogin_Initiator_cd),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_datexLogin_Initiator_cd_10,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"datexLogin-Initiator-cd"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct Login, datexLogin_DatagramSize_qty),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,
		{ &asn_OER_memb_datexLogin_DatagramSize_qty_constr_14, &asn_PER_memb_datexLogin_DatagramSize_qty_constr_14,  memb_datexLogin_DatagramSize_qty_constraint_1 },
		0, 0, /* No default value */
		"datexLogin-DatagramSize-qty"
		},
};
static const ber_tlv_tag_t asn_DEF_Login_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Login_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* datex-Sender-txt */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* datex-Destination-txt */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* datexLogin-UserName-txt */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* datexLogin-Password-txt */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* datexLogin-EncodingRules-id */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* datexLogin-HeartbeatDurationMax-qty */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* datexLogin-ResponseTimeOut-qty */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* datexLogin-Initiator-cd */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 } /* datexLogin-DatagramSize-qty */
};
asn_SEQUENCE_specifics_t asn_SPC_Login_specs_1 = {
	sizeof(struct Login),
	offsetof(struct Login, _asn_ctx),
	asn_MAP_Login_tag2el_1,
	9,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_Login = {
	"Login",
	"Login",
	&asn_OP_SEQUENCE,
	asn_DEF_Login_tags_1,
	sizeof(asn_DEF_Login_tags_1)
		/sizeof(asn_DEF_Login_tags_1[0]), /* 1 */
	asn_DEF_Login_tags_1,	/* Same as above */
	sizeof(asn_DEF_Login_tags_1)
		/sizeof(asn_DEF_Login_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_Login_1,
	9,	/* Elements count */
	&asn_SPC_Login_specs_1	/* Additional specs */
};

