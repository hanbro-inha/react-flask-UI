/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_AxleWeightList_H_
#define	_AxleWeightList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct AxleWeightSet;

/* AxleWeightList */
typedef struct AxleWeightList {
	A_SEQUENCE_OF(struct AxleWeightSet) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AxleWeightList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AxleWeightList;
extern asn_SET_OF_specifics_t asn_SPC_AxleWeightList_specs_1;
extern asn_TYPE_member_t asn_MBR_AxleWeightList_1[1];
extern asn_per_constraints_t asn_PER_type_AxleWeightList_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "AxleWeightSet.h"

#endif	/* _AxleWeightList_H_ */
#include <asn_internal.h>
