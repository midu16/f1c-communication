/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP"
 * 	found in "f1ap.asn"
 * 	`asn1c -gen-PER -fcompound-names`
 */

#include "F1SetupRequest.h"

static int
memb_gNB_ID_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 22)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_gNB_Name_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 150)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_gNB_ID_constr_3 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  22,  22 }	/* (SIZE(22..22)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_gNB_Name_constr_4 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  1,  150 }	/* (SIZE(1..150)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_F1SetupRequest_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct F1SetupRequest, transactionID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"transactionID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct F1SetupRequest, gNB_ID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		memb_gNB_ID_constraint_1,
		&asn_PER_memb_gNB_ID_constr_3,
		0,
		"gNB-ID"
		},
	{ ATF_POINTER, 2, offsetof(struct F1SetupRequest, gNB_Name),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		memb_gNB_Name_constraint_1,
		&asn_PER_memb_gNB_Name_constr_4,
		0,
		"gNB-Name"
		},
	{ ATF_POINTER, 1, offsetof(struct F1SetupRequest, cells_to_be_activated),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_Container,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cells-to-be-activated"
		},
};
static const int asn_MAP_F1SetupRequest_oms_1[] = { 2, 3 };
static const ber_tlv_tag_t asn_DEF_F1SetupRequest_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_F1SetupRequest_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* transactionID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* gNB-ID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* gNB-Name */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* cells-to-be-activated */
};
static asn_SEQUENCE_specifics_t asn_SPC_F1SetupRequest_specs_1 = {
	sizeof(struct F1SetupRequest),
	offsetof(struct F1SetupRequest, _asn_ctx),
	asn_MAP_F1SetupRequest_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_F1SetupRequest_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_F1SetupRequest = {
	"F1SetupRequest",
	"F1SetupRequest",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_F1SetupRequest_tags_1,
	sizeof(asn_DEF_F1SetupRequest_tags_1)
		/sizeof(asn_DEF_F1SetupRequest_tags_1[0]), /* 1 */
	asn_DEF_F1SetupRequest_tags_1,	/* Same as above */
	sizeof(asn_DEF_F1SetupRequest_tags_1)
		/sizeof(asn_DEF_F1SetupRequest_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_F1SetupRequest_1,
	4,	/* Elements count */
	&asn_SPC_F1SetupRequest_specs_1	/* Additional specs */
};

