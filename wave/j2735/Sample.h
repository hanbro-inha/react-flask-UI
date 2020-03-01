/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_Sample_H_
#define	_Sample_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Sample */
typedef struct Sample {
	long	 sampleStart;
	long	 sampleEnd;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Sample_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Sample;
extern asn_SEQUENCE_specifics_t asn_SPC_Sample_specs_1;
extern asn_TYPE_member_t asn_MBR_Sample_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _Sample_H_ */
#include <asn_internal.h>
