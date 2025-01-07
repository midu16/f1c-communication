/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP"
 * 	found in "f1ap.asn"
 * 	`asn1c -gen-PER -fcompound-names`
 */

#ifndef	_F1HandoverFailure_H_
#define	_F1HandoverFailure_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum F1HandoverFailure__cause {
	F1HandoverFailure__cause_resource_unavailable	= 0,
	F1HandoverFailure__cause_time_out	= 1,
	F1HandoverFailure__cause_unknown	= 2,
	F1HandoverFailure__cause_other	= 3
} e_F1HandoverFailure__cause;

/* F1HandoverFailure */
typedef struct F1HandoverFailure {
	long	 transactionID;
	long	 cause;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} F1HandoverFailure_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_cause_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_F1HandoverFailure;

#ifdef __cplusplus
}
#endif

#endif	/* _F1HandoverFailure_H_ */
#include <asn_internal.h>
