/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "F1AP"
 * 	found in "f1ap.asn"
 * 	`asn1c -gen-PER -fcompound-names`
 */

#include "F1SetupFailure.h"

static int
cause_3_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
cause_3_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
cause_3_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	cause_3_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
cause_3_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	cause_3_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
cause_3_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	cause_3_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
cause_3_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	cause_3_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
cause_3_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	cause_3_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
cause_3_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	cause_3_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
cause_3_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	cause_3_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
cause_3_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	cause_3_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
timeToWait_7_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
timeToWait_7_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
timeToWait_7_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
timeToWait_7_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
timeToWait_7_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
timeToWait_7_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
timeToWait_7_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
timeToWait_7_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
timeToWait_7_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
timeToWait_7_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	timeToWait_7_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_cause_constr_3 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  2 }	/* (0..2) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_timeToWait_constr_7 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 2,  2,  0,  3 }	/* (0..3) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_cause_value2enum_3[] = {
	{ 0,	11,	"unspecified" },
	{ 1,	8,	"overload" },
	{ 2,	9,	"invalidID" }
};
static const unsigned int asn_MAP_cause_enum2value_3[] = {
	2,	/* invalidID(2) */
	1,	/* overload(1) */
	0	/* unspecified(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_cause_specs_3 = {
	asn_MAP_cause_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_cause_enum2value_3,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_cause_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_cause_3 = {
	"cause",
	"cause",
	cause_3_free,
	cause_3_print,
	cause_3_constraint,
	cause_3_decode_ber,
	cause_3_encode_der,
	cause_3_decode_xer,
	cause_3_encode_xer,
	cause_3_decode_uper,
	cause_3_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_cause_tags_3,
	sizeof(asn_DEF_cause_tags_3)
		/sizeof(asn_DEF_cause_tags_3[0]) - 1, /* 1 */
	asn_DEF_cause_tags_3,	/* Same as above */
	sizeof(asn_DEF_cause_tags_3)
		/sizeof(asn_DEF_cause_tags_3[0]), /* 2 */
	&asn_PER_type_cause_constr_3,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_cause_specs_3	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_timeToWait_value2enum_7[] = {
	{ 0,	6,	"vshort" },
	{ 1,	5,	"short" },
	{ 2,	6,	"medium" },
	{ 3,	4,	"long" }
};
static const unsigned int asn_MAP_timeToWait_enum2value_7[] = {
	3,	/* long(3) */
	2,	/* medium(2) */
	1,	/* short(1) */
	0	/* vshort(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_timeToWait_specs_7 = {
	asn_MAP_timeToWait_value2enum_7,	/* "tag" => N; sorted by tag */
	asn_MAP_timeToWait_enum2value_7,	/* N => "tag"; sorted by N */
	4,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_timeToWait_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_timeToWait_7 = {
	"timeToWait",
	"timeToWait",
	timeToWait_7_free,
	timeToWait_7_print,
	timeToWait_7_constraint,
	timeToWait_7_decode_ber,
	timeToWait_7_encode_der,
	timeToWait_7_decode_xer,
	timeToWait_7_encode_xer,
	timeToWait_7_decode_uper,
	timeToWait_7_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_timeToWait_tags_7,
	sizeof(asn_DEF_timeToWait_tags_7)
		/sizeof(asn_DEF_timeToWait_tags_7[0]) - 1, /* 1 */
	asn_DEF_timeToWait_tags_7,	/* Same as above */
	sizeof(asn_DEF_timeToWait_tags_7)
		/sizeof(asn_DEF_timeToWait_tags_7[0]), /* 2 */
	&asn_PER_type_timeToWait_constr_7,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_timeToWait_specs_7	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_F1SetupFailure_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct F1SetupFailure, transactionID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"transactionID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct F1SetupFailure, cause),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_cause_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cause"
		},
	{ ATF_POINTER, 1, offsetof(struct F1SetupFailure, timeToWait),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_timeToWait_7,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"timeToWait"
		},
};
static const int asn_MAP_F1SetupFailure_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_F1SetupFailure_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_F1SetupFailure_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* transactionID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* cause */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* timeToWait */
};
static asn_SEQUENCE_specifics_t asn_SPC_F1SetupFailure_specs_1 = {
	sizeof(struct F1SetupFailure),
	offsetof(struct F1SetupFailure, _asn_ctx),
	asn_MAP_F1SetupFailure_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_F1SetupFailure_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_F1SetupFailure = {
	"F1SetupFailure",
	"F1SetupFailure",
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
	asn_DEF_F1SetupFailure_tags_1,
	sizeof(asn_DEF_F1SetupFailure_tags_1)
		/sizeof(asn_DEF_F1SetupFailure_tags_1[0]), /* 1 */
	asn_DEF_F1SetupFailure_tags_1,	/* Same as above */
	sizeof(asn_DEF_F1SetupFailure_tags_1)
		/sizeof(asn_DEF_F1SetupFailure_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_F1SetupFailure_1,
	3,	/* Elements count */
	&asn_SPC_F1SetupFailure_specs_1	/* Additional specs */
};

