/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ITIS"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#include "IncidentResponseEquipment.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_IncidentResponseEquipment_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_IncidentResponseEquipment_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  7,  7,  0,  71 }	/* (0..71,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_IncidentResponseEquipment_value2enum_1[] = {
	{ 9985,	23,	"ground-fire-suppression" },
	{ 9986,	22,	"heavy-ground-equipment" },
	{ 9988,	8,	"aircraft" },
	{ 9989,	16,	"marine-equipment" },
	{ 9990,	17,	"support-equipment" },
	{ 9991,	19,	"medical-rescue-unit" },
	{ 9993,	5,	"other" },
	{ 9994,	29,	"ground-fire-suppression-other" },
	{ 9995,	6,	"engine" },
	{ 9996,	15,	"truck-or-aerial" },
	{ 9997,	5,	"quint" },
	{ 9998,	25,	"tanker-pumper-combination" },
	{ 10000,	11,	"brush-truck" },
	{ 10001,	28,	"aircraft-rescue-firefighting" },
	{ 10004,	28,	"heavy-ground-equipment-other" },
	{ 10005,	13,	"dozer-or-plow" },
	{ 10006,	7,	"tractor" },
	{ 10008,	16,	"tanker-or-tender" },
	{ 10024,	14,	"aircraft-other" },
	{ 10025,	26,	"aircraft-fixed-wing-tanker" },
	{ 10026,	10,	"helitanker" },
	{ 10027,	10,	"helicopter" },
	{ 10034,	22,	"marine-equipment-other" },
	{ 10035,	19,	"fire-boat-with-pump" },
	{ 10036,	12,	"boat-no-pump" },
	{ 10044,	23,	"support-apparatus-other" },
	{ 10045,	27,	"breathing-apparatus-support" },
	{ 10046,	18,	"light-and-air-unit" },
	{ 10054,	25,	"medical-rescue-unit-other" },
	{ 10055,	11,	"rescue-unit" },
	{ 10056,	24,	"urban-search-rescue-unit" },
	{ 10057,	17,	"high-angle-rescue" },
	{ 10058,	17,	"crash-fire-rescue" },
	{ 10059,	8,	"bLS-unit" },
	{ 10060,	8,	"aLS-unit" },
	{ 10075,	19,	"mobile-command-post" },
	{ 10076,	17,	"chief-officer-car" },
	{ 10077,	11,	"hAZMAT-unit" },
	{ 10078,	16,	"type-i-hand-crew" },
	{ 10079,	17,	"type-ii-hand-crew" },
	{ 10083,	23,	"privately-owned-vehicle" },
	{ 10084,	24,	"other-apparatus-resource" },
	{ 10085,	9,	"ambulance" },
	{ 10086,	14,	"bomb-squad-van" },
	{ 10087,	17,	"combine-harvester" },
	{ 10088,	20,	"construction-vehicle" },
	{ 10089,	12,	"farm-tractor" },
	{ 10090,	22,	"grass-cutting-machines" },
	{ 10091,	22,	"hAZMAT-containment-tow" },
	{ 10092,	9,	"heavy-tow" },
	{ 10093,	22,	"hedge-cutting-machines" },
	{ 10094,	9,	"light-tow" },
	{ 10095,	12,	"mobile-crane" },
	{ 10096,	25,	"refuse-collection-vehicle" },
	{ 10097,	19,	"resurfacing-vehicle" },
	{ 10098,	12,	"road-sweeper" },
	{ 10099,	32,	"roadside-litter-collection-crews" },
	{ 10100,	15,	"salvage-vehicle" },
	{ 10101,	10,	"sand-truck" },
	{ 10102,	8,	"snowplow" },
	{ 10103,	12,	"steam-roller" },
	{ 10104,	13,	"swat-team-van" },
	{ 10105,	20,	"track-laying-vehicle" },
	{ 10106,	15,	"unknown-vehicle" },
	{ 10107,	20,	"white-lining-vehicle" },
	{ 10108,	10,	"dump-truck" },
	{ 10109,	18,	"supervisor-vehicle" },
	{ 10110,	11,	"snow-blower" },
	{ 10111,	18,	"rotary-snow-blower" },
	{ 10112,	11,	"road-grader" },
	{ 10113,	11,	"steam-truck" },
	{ 10114,	11,	"flatbed-tow" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_IncidentResponseEquipment_enum2value_1[] = {
	34,	/* aLS-unit(10060) */
	2,	/* aircraft(9988) */
	19,	/* aircraft-fixed-wing-tanker(10025) */
	18,	/* aircraft-other(10024) */
	13,	/* aircraft-rescue-firefighting(10001) */
	42,	/* ambulance(10085) */
	33,	/* bLS-unit(10059) */
	24,	/* boat-no-pump(10036) */
	43,	/* bomb-squad-van(10086) */
	26,	/* breathing-apparatus-support(10045) */
	12,	/* brush-truck(10000) */
	36,	/* chief-officer-car(10076) */
	44,	/* combine-harvester(10087) */
	45,	/* construction-vehicle(10088) */
	32,	/* crash-fire-rescue(10058) */
	15,	/* dozer-or-plow(10005) */
	65,	/* dump-truck(10108) */
	8,	/* engine(9995) */
	46,	/* farm-tractor(10089) */
	23,	/* fire-boat-with-pump(10035) */
	71,	/* flatbed-tow(10114) */
	47,	/* grass-cutting-machines(10090) */
	0,	/* ground-fire-suppression(9985) */
	7,	/* ground-fire-suppression-other(9994) */
	48,	/* hAZMAT-containment-tow(10091) */
	37,	/* hAZMAT-unit(10077) */
	1,	/* heavy-ground-equipment(9986) */
	14,	/* heavy-ground-equipment-other(10004) */
	49,	/* heavy-tow(10092) */
	50,	/* hedge-cutting-machines(10093) */
	21,	/* helicopter(10027) */
	20,	/* helitanker(10026) */
	31,	/* high-angle-rescue(10057) */
	27,	/* light-and-air-unit(10046) */
	51,	/* light-tow(10094) */
	3,	/* marine-equipment(9989) */
	22,	/* marine-equipment-other(10034) */
	5,	/* medical-rescue-unit(9991) */
	28,	/* medical-rescue-unit-other(10054) */
	35,	/* mobile-command-post(10075) */
	52,	/* mobile-crane(10095) */
	6,	/* other(9993) */
	41,	/* other-apparatus-resource(10084) */
	40,	/* privately-owned-vehicle(10083) */
	10,	/* quint(9997) */
	53,	/* refuse-collection-vehicle(10096) */
	29,	/* rescue-unit(10055) */
	54,	/* resurfacing-vehicle(10097) */
	69,	/* road-grader(10112) */
	55,	/* road-sweeper(10098) */
	56,	/* roadside-litter-collection-crews(10099) */
	68,	/* rotary-snow-blower(10111) */
	57,	/* salvage-vehicle(10100) */
	58,	/* sand-truck(10101) */
	67,	/* snow-blower(10110) */
	59,	/* snowplow(10102) */
	60,	/* steam-roller(10103) */
	70,	/* steam-truck(10113) */
	66,	/* supervisor-vehicle(10109) */
	25,	/* support-apparatus-other(10044) */
	4,	/* support-equipment(9990) */
	61,	/* swat-team-van(10104) */
	17,	/* tanker-or-tender(10008) */
	11,	/* tanker-pumper-combination(9998) */
	62,	/* track-laying-vehicle(10105) */
	16,	/* tractor(10006) */
	9,	/* truck-or-aerial(9996) */
	38,	/* type-i-hand-crew(10078) */
	39,	/* type-ii-hand-crew(10079) */
	63,	/* unknown-vehicle(10106) */
	30,	/* urban-search-rescue-unit(10056) */
	64	/* white-lining-vehicle(10107) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_IncidentResponseEquipment_specs_1 = {
	asn_MAP_IncidentResponseEquipment_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_IncidentResponseEquipment_enum2value_1,	/* N => "tag"; sorted by N */
	72,	/* Number of elements in the maps */
	73,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_IncidentResponseEquipment_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_IncidentResponseEquipment = {
	"IncidentResponseEquipment",
	"IncidentResponseEquipment",
	&asn_OP_NativeEnumerated,
	asn_DEF_IncidentResponseEquipment_tags_1,
	sizeof(asn_DEF_IncidentResponseEquipment_tags_1)
		/sizeof(asn_DEF_IncidentResponseEquipment_tags_1[0]), /* 1 */
	asn_DEF_IncidentResponseEquipment_tags_1,	/* Same as above */
	sizeof(asn_DEF_IncidentResponseEquipment_tags_1)
		/sizeof(asn_DEF_IncidentResponseEquipment_tags_1[0]), /* 1 */
	{ &asn_OER_type_IncidentResponseEquipment_constr_1, &asn_PER_type_IncidentResponseEquipment_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_IncidentResponseEquipment_specs_1	/* Additional specs */
};

