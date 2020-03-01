/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_PublicationData_H_
#define	_PublicationData_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <BOOLEAN.h>
#include "PublicationType.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PublicationData */
typedef struct PublicationData {
	unsigned long	 datexPublish_SubscribeSerial_nbr;
	unsigned long	 datexPublish_Serial_nbr;
	BOOLEAN_t	 datexPublish_LatePublicationFlag;
	PublicationType_t	 datexPublish_Type;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PublicationData_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_datexPublish_SubscribeSerial_nbr_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_datexPublish_Serial_nbr_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_PublicationData;
extern asn_SEQUENCE_specifics_t asn_SPC_PublicationData_specs_1;
extern asn_TYPE_member_t asn_MBR_PublicationData_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _PublicationData_H_ */
#include <asn_internal.h>
