/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_PDUs_H_
#define	_PDUs_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Initiate.h"
#include "Login.h"
#include "FrED.h"
#include "Terminate.h"
#include "Logout.h"
#include "Subscription.h"
#include "Publication.h"
#include "TransferDone.h"
#include "Accept.h"
#include "Reject.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum PDUs_PR {
	PDUs_PR_NOTHING,	/* No components present */
	PDUs_PR_datex_Initiate_null,
	PDUs_PR_login,
	PDUs_PR_fred,
	PDUs_PR_terminate,
	PDUs_PR_logout,
	PDUs_PR_subscription,
	PDUs_PR_publication,
	PDUs_PR_transfer_done,
	PDUs_PR_accept,
	PDUs_PR_reject
} PDUs_PR;

/* PDUs */
typedef struct PDUs {
	PDUs_PR present;
	union {
		Initiate_t	 datex_Initiate_null;
		Login_t	 login;
		FrED_t	 fred;
		Terminate_t	 terminate;
		Logout_t	 logout;
		Subscription_t	 subscription;
		Publication_t	 publication;
		TransferDone_t	 transfer_done;
		Accept_t	 accept;
		Reject_t	 reject;
	};
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PDUs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PDUs;
extern asn_CHOICE_specifics_t asn_SPC_PDUs_specs_1;
extern asn_TYPE_member_t asn_MBR_PDUs_1[10];
extern asn_per_constraints_t asn_PER_type_PDUs_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _PDUs_H_ */
#include <asn_internal.h>
