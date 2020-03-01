/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "RequestedItem.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_RequestedItem_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_RequestedItem_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  5,  5,  0,  16 }	/* (0..16,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_RequestedItem_value2enum_1[] = {
	{ 0,	8,	"reserved" },
	{ 1,	5,	"itemA" },
	{ 2,	5,	"itemB" },
	{ 3,	5,	"itemC" },
	{ 4,	5,	"itemD" },
	{ 5,	5,	"itemE" },
	{ 6,	5,	"itemF" },
	{ 7,	5,	"itemG" },
	{ 8,	5,	"itemI" },
	{ 9,	5,	"itemJ" },
	{ 10,	5,	"itemK" },
	{ 11,	5,	"itemL" },
	{ 12,	5,	"itemM" },
	{ 13,	5,	"itemN" },
	{ 14,	5,	"itemO" },
	{ 15,	5,	"itemP" },
	{ 16,	5,	"itemQ" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_RequestedItem_enum2value_1[] = {
	1,	/* itemA(1) */
	2,	/* itemB(2) */
	3,	/* itemC(3) */
	4,	/* itemD(4) */
	5,	/* itemE(5) */
	6,	/* itemF(6) */
	7,	/* itemG(7) */
	8,	/* itemI(8) */
	9,	/* itemJ(9) */
	10,	/* itemK(10) */
	11,	/* itemL(11) */
	12,	/* itemM(12) */
	13,	/* itemN(13) */
	14,	/* itemO(14) */
	15,	/* itemP(15) */
	16,	/* itemQ(16) */
	0	/* reserved(0) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_RequestedItem_specs_1 = {
	asn_MAP_RequestedItem_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_RequestedItem_enum2value_1,	/* N => "tag"; sorted by N */
	17,	/* Number of elements in the maps */
	18,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_RequestedItem_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_RequestedItem = {
	"RequestedItem",
	"RequestedItem",
	&asn_OP_NativeEnumerated,
	asn_DEF_RequestedItem_tags_1,
	sizeof(asn_DEF_RequestedItem_tags_1)
		/sizeof(asn_DEF_RequestedItem_tags_1[0]), /* 1 */
	asn_DEF_RequestedItem_tags_1,	/* Same as above */
	sizeof(asn_DEF_RequestedItem_tags_1)
		/sizeof(asn_DEF_RequestedItem_tags_1[0]), /* 1 */
	{ &asn_OER_type_RequestedItem_constr_1, &asn_PER_type_RequestedItem_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_RequestedItem_specs_1	/* Additional specs */
};

