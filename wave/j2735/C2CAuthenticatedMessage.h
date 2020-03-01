/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_C2CAuthenticatedMessage_H_
#define	_C2CAuthenticatedMessage_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include <NativeInteger.h>
#include "HeaderOptions.h"
#include "PDUs.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* C2CAuthenticatedMessage */
typedef struct C2CAuthenticatedMessage {
	OCTET_STRING_t	 datex_AuthenticationInfo_text;
	unsigned long	 datex_DataPacket_number;
	long	 datex_DataPacketPriority_number;
	HeaderOptions_t	 options;
	PDUs_t	 pdu;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} C2CAuthenticatedMessage_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_datex_DataPacket_number_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_C2CAuthenticatedMessage;

#ifdef __cplusplus
}
#endif

#endif	/* _C2CAuthenticatedMessage_H_ */
#include <asn_internal.h>
