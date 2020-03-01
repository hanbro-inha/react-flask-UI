/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "ISO14827-2"
 * 	found in "../asn1c/J2735_201603DA+ITSK4-0.4_new.asn"
 * 	`asn1c -no-gen-example -fcompound-names -funnamed-unions -pdu=MessageFrame`
 */

#ifndef	_Time_H_
#define	_Time_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Time__time_SecondFractions_PR {
	Time__time_SecondFractions_PR_NOTHING,	/* No components present */
	Time__time_SecondFractions_PR_deci_seconds,
	Time__time_SecondFractions_PR_centi_seconds,
	Time__time_SecondFractions_PR_milliseconds
	/* Extensions may appear below */
	
} Time__time_SecondFractions_PR;

/* Time */
typedef struct Time {
	long	*time_Year_qty	/* OPTIONAL */;
	long	*time_Month_qty	/* OPTIONAL */;
	long	*time_Day_qty	/* OPTIONAL */;
	long	 time_Hour_qty	/* DEFAULT 0 */;
	long	 time_Minute_qty	/* DEFAULT 0 */;
	long	 time_Second_qty	/* DEFAULT 0 */;
	struct Time__time_SecondFractions {
		Time__time_SecondFractions_PR present;
		union {
			long	 deci_seconds;
			long	 centi_seconds;
			long	 milliseconds;
			/*
			 * This type is extensible,
			 * possible extensions are below.
			 */
		};
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} time_SecondFractions;
	struct Time__time_Timezone {
		long	 timezone_Hour_qty	/* DEFAULT 0 */;
		long	 time_Minute_qty	/* DEFAULT 0 */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *time_Timezone;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Time_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Time;
extern asn_SEQUENCE_specifics_t asn_SPC_Time_specs_1;
extern asn_TYPE_member_t asn_MBR_Time_1[8];

#ifdef __cplusplus
}
#endif

#endif	/* _Time_H_ */
#include <asn_internal.h>
