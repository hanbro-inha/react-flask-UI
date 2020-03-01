/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DSRC"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_PrivilegedEvents_H_
#define	_PrivilegedEvents_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SSPindex.h"
#include "PrivilegedEventFlags.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PrivilegedEvents */
typedef struct PrivilegedEvents {
	SSPindex_t	 sspRights;
	PrivilegedEventFlags_t	 event;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PrivilegedEvents_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PrivilegedEvents;
extern asn_SEQUENCE_specifics_t asn_SPC_PrivilegedEvents_specs_1;
extern asn_TYPE_member_t asn_MBR_PrivilegedEvents_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _PrivilegedEvents_H_ */
#include <asn_internal.h>
