/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "TransferDone.h"

static int
datexTransferDone_Publication_nbr_2_constraint(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	/* Constraint check succeeded */
	return 0;
}

/*
 * This type is implemented using NativeInteger,
 * so here we adjust the DEF accordingly.
 */
static int
memb_datexTransferDone_Publication_nbr_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	/* Constraint check succeeded */
	return 0;
}

static int
memb_datexTransferDone_FileName_txt_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
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
	
	if((size <= 2000)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_datexTransferDone_Publication_nbr_constr_2 CC_NOTUSED = {
	{ 4, 1 }	/* (0..4294967295) */,
	-1};
static asn_per_constraints_t asn_PER_type_datexTransferDone_Publication_nbr_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 32, -1,  0,  4294967295 }	/* (0..4294967295) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_datexTransferDone_Publication_nbr_constr_2 CC_NOTUSED = {
	{ 4, 1 }	/* (0..4294967295) */,
	-1};
static asn_per_constraints_t asn_PER_memb_datexTransferDone_Publication_nbr_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 32, -1,  0,  4294967295 }	/* (0..4294967295) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_datexTransferDone_FileName_txt_constr_3 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..MAX)) */};
static asn_per_constraints_t asn_PER_memb_datexTransferDone_FileName_txt_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_specifics_t asn_SPC_datexTransferDone_Publication_nbr_specs_2 = {
	0,	0,	0,	0,	0,
	0,	/* Native long size */
	1	/* Unsigned representation */
};
static const ber_tlv_tag_t asn_DEF_datexTransferDone_Publication_nbr_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_datexTransferDone_Publication_nbr_2 = {
	"datexTransferDone-Publication-nbr",
	"datexTransferDone-Publication-nbr",
	&asn_OP_NativeInteger,
	asn_DEF_datexTransferDone_Publication_nbr_tags_2,
	sizeof(asn_DEF_datexTransferDone_Publication_nbr_tags_2)
		/sizeof(asn_DEF_datexTransferDone_Publication_nbr_tags_2[0]) - 1, /* 1 */
	asn_DEF_datexTransferDone_Publication_nbr_tags_2,	/* Same as above */
	sizeof(asn_DEF_datexTransferDone_Publication_nbr_tags_2)
		/sizeof(asn_DEF_datexTransferDone_Publication_nbr_tags_2[0]), /* 2 */
	{ &asn_OER_type_datexTransferDone_Publication_nbr_constr_2, &asn_PER_type_datexTransferDone_Publication_nbr_constr_2, datexTransferDone_Publication_nbr_2_constraint },
	0, 0,	/* No members */
	&asn_SPC_datexTransferDone_Publication_nbr_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_TransferDone_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct TransferDone, datexTransferDone_Publication_nbr),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_datexTransferDone_Publication_nbr_2,
		0,
		{ &asn_OER_memb_datexTransferDone_Publication_nbr_constr_2, &asn_PER_memb_datexTransferDone_Publication_nbr_constr_2,  memb_datexTransferDone_Publication_nbr_constraint_1 },
		0, 0, /* No default value */
		"datexTransferDone-Publication-nbr"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TransferDone, datexTransferDone_FileName_txt),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		0,
		{ &asn_OER_memb_datexTransferDone_FileName_txt_constr_3, &asn_PER_memb_datexTransferDone_FileName_txt_constr_3,  memb_datexTransferDone_FileName_txt_constraint_1 },
		0, 0, /* No default value */
		"datexTransferDone-FileName-txt"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct TransferDone, datexTransferDone_Success_bool),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"datexTransferDone-Success-bool"
		},
};
static const ber_tlv_tag_t asn_DEF_TransferDone_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_TransferDone_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* datexTransferDone-Publication-nbr */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* datexTransferDone-FileName-txt */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* datexTransferDone-Success-bool */
};
asn_SEQUENCE_specifics_t asn_SPC_TransferDone_specs_1 = {
	sizeof(struct TransferDone),
	offsetof(struct TransferDone, _asn_ctx),
	asn_MAP_TransferDone_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_TransferDone = {
	"TransferDone",
	"TransferDone",
	&asn_OP_SEQUENCE,
	asn_DEF_TransferDone_tags_1,
	sizeof(asn_DEF_TransferDone_tags_1)
		/sizeof(asn_DEF_TransferDone_tags_1[0]), /* 1 */
	asn_DEF_TransferDone_tags_1,	/* Same as above */
	sizeof(asn_DEF_TransferDone_tags_1)
		/sizeof(asn_DEF_TransferDone_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_TransferDone_1,
	3,	/* Elements count */
	&asn_SPC_TransferDone_specs_1	/* Additional specs */
};

