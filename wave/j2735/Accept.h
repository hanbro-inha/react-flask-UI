/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_Accept_H_
#define	_Accept_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <OBJECT_IDENTIFIER.h>
#include <NULL.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Accept__datexAccept_Type_PR {
	Accept__datexAccept_Type_PR_NOTHING,	/* No components present */
	Accept__datexAccept_Type_PR_logIn,
	Accept__datexAccept_Type_PR_single_subscription,
	Accept__datexAccept_Type_PR_registered_subscription,
	Accept__datexAccept_Type_PR_publication
} Accept__datexAccept_Type_PR;

/* Accept */
typedef struct Accept {
	unsigned long	 datexAccept_Packet_nbr;
	struct Accept__datexAccept_Type {
		Accept__datexAccept_Type_PR present;
		union {
			OBJECT_IDENTIFIER_t	 logIn;
			NULL_t	 single_subscription;
			unsigned long	 registered_subscription;
			NULL_t	 publication;
		};
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} datexAccept_Type;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Accept_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_datexAccept_Packet_nbr_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_registered_subscription_6;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_Accept;
extern asn_SEQUENCE_specifics_t asn_SPC_Accept_specs_1;
extern asn_TYPE_member_t asn_MBR_Accept_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _Accept_H_ */
#include <asn_internal.h>
