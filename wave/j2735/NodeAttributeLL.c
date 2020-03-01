/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "NodeAttributeLL.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_NodeAttributeLL_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_NodeAttributeLL_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  4,  4,  0,  11 }	/* (0..11,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_NodeAttributeLL_value2enum_1[] = {
	{ 0,	8,	"reserved" },
	{ 1,	8,	"stopLine" },
	{ 2,	16,	"roundedCapStyleA" },
	{ 3,	16,	"roundedCapStyleB" },
	{ 4,	10,	"mergePoint" },
	{ 5,	12,	"divergePoint" },
	{ 6,	18,	"downstreamStopLine" },
	{ 7,	19,	"downstreamStartNode" },
	{ 8,	15,	"closedToTraffic" },
	{ 9,	10,	"safeIsland" },
	{ 10,	20,	"curbPresentAtStepOff" },
	{ 11,	14,	"hydrantPresent" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_NodeAttributeLL_enum2value_1[] = {
	8,	/* closedToTraffic(8) */
	10,	/* curbPresentAtStepOff(10) */
	5,	/* divergePoint(5) */
	7,	/* downstreamStartNode(7) */
	6,	/* downstreamStopLine(6) */
	11,	/* hydrantPresent(11) */
	4,	/* mergePoint(4) */
	0,	/* reserved(0) */
	2,	/* roundedCapStyleA(2) */
	3,	/* roundedCapStyleB(3) */
	9,	/* safeIsland(9) */
	1	/* stopLine(1) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_NodeAttributeLL_specs_1 = {
	asn_MAP_NodeAttributeLL_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_NodeAttributeLL_enum2value_1,	/* N => "tag"; sorted by N */
	12,	/* Number of elements in the maps */
	13,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_NodeAttributeLL_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_NodeAttributeLL = {
	"NodeAttributeLL",
	"NodeAttributeLL",
	&asn_OP_NativeEnumerated,
	asn_DEF_NodeAttributeLL_tags_1,
	sizeof(asn_DEF_NodeAttributeLL_tags_1)
		/sizeof(asn_DEF_NodeAttributeLL_tags_1[0]), /* 1 */
	asn_DEF_NodeAttributeLL_tags_1,	/* Same as above */
	sizeof(asn_DEF_NodeAttributeLL_tags_1)
		/sizeof(asn_DEF_NodeAttributeLL_tags_1[0]), /* 1 */
	{ &asn_OER_type_NodeAttributeLL_constr_1, &asn_PER_type_NodeAttributeLL_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_NodeAttributeLL_specs_1	/* Additional specs */
};

