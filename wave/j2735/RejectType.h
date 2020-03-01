/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_RejectType_H_
#define	_RejectType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RejectType_PR {
	RejectType_PR_NOTHING,	/* No components present */
	RejectType_PR_datexReject_Login_cd,
	RejectType_PR_datexReject_Subscription_cd,
	RejectType_PR_datexReject_Publication_cd
} RejectType_PR;
typedef enum RejectType__datexReject_Login_cd {
	RejectType__datexReject_Login_cd_other	= 0,
	RejectType__datexReject_Login_cd_unknownDomainName	= 1,
	RejectType__datexReject_Login_cd_accessDenied	= 2,
	RejectType__datexReject_Login_cd_invalidNamePassword	= 3,
	RejectType__datexReject_Login_cd_timeoutTooSmall	= 4,
	RejectType__datexReject_Login_cd_timeoutTooLarge	= 5,
	RejectType__datexReject_Login_cd_heartbeatTooSmall	= 6,
	RejectType__datexReject_Login_cd_heartbeatTooLarge	= 7,
	RejectType__datexReject_Login_cd_sessionExists	= 8,
	RejectType__datexReject_Login_cd_maxSessionsReached	= 9
	/*
	 * Enumeration is extensible
	 */
} e_RejectType__datexReject_Login_cd;
typedef enum RejectType__datexReject_Subscription_cd {
	RejectType__datexReject_Subscription_cd_other	= 0,
	RejectType__datexReject_Subscription_cd_unknownSubscriptionNbr	= 1,
	RejectType__datexReject_Subscription_cd_invalidTimes	= 2,
	RejectType__datexReject_Subscription_cd_frequencyTooSmall	= 3,
	RejectType__datexReject_Subscription_cd_frequencyTooLarge	= 4,
	RejectType__datexReject_Subscription_cd_invalid_mode	= 5,
	RejectType__datexReject_Subscription_cd_publishFormatNotSupported	= 6,
	RejectType__datexReject_Subscription_cd_unknowSubscriptionMsgId	= 7,
	RejectType__datexReject_Subscription_cd_invalidSubscriptionMsgId	= 8,
	RejectType__datexReject_Subscription_cd_invalidSubscriptionContent	= 9
	/*
	 * Enumeration is extensible
	 */
} e_RejectType__datexReject_Subscription_cd;
typedef enum RejectType__datexReject_Publication_cd {
	RejectType__datexReject_Publication_cd_other	= 0,
	RejectType__datexReject_Publication_cd_unknownSubscription	= 1,
	RejectType__datexReject_Publication_cd_unknownPublicationNbr	= 2,
	RejectType__datexReject_Publication_cd_invalidPublishFormat	= 3,
	RejectType__datexReject_Publication_cd_unknownPublicationMsgId	= 4,
	RejectType__datexReject_Publication_cd_invalidPublicationMsgId	= 5,
	RejectType__datexReject_Publication_cd_invalidPublicationMsgContent	= 6,
	RejectType__datexReject_Publication_cd_repeatedPublicationNbr	= 7
	/*
	 * Enumeration is extensible
	 */
} e_RejectType__datexReject_Publication_cd;

/* RejectType */
typedef struct RejectType {
	RejectType_PR present;
	union {
		long	 datexReject_Login_cd;
		long	 datexReject_Subscription_cd;
		long	 datexReject_Publication_cd;
	};
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RejectType_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_datexReject_Login_cd_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_datexReject_Subscription_cd_14;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_datexReject_Publication_cd_26;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_RejectType;
extern asn_CHOICE_specifics_t asn_SPC_RejectType_specs_1;
extern asn_TYPE_member_t asn_MBR_RejectType_1[3];
extern asn_per_constraints_t asn_PER_type_RejectType_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _RejectType_H_ */
#include <asn_internal.h>