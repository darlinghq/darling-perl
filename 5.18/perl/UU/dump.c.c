#line 2 "dump.c"
#include "EXTERN.h"
#define PERL_IN_DUMP_C
#include "perl.h"
#include "regcomp.h"
#define append_flags(sv, f, flags)      S_append_flags(aTHX_ (sv), (f), (flags), C_ARRAY_END(flags))
#define PV_ESCAPE_OCTBUFSIZE 32
#ifdef USE_ITHREADS
#else
#endif
#define OP_PRIVATE_ONCE(op, flag, name)      const struct flag_to_name CAT2(op, _names)[] = {	 	{(flag), (name)}      }
#define DUMP_OP_FLAGS(o,xml,level,file)                                      if (o->op_flags || o->op_slabbed || o->op_savefree || o->op_static) {          SV * const tmpsv = newSVpvs("");                                         switch (o->op_flags & OPf_WANT) {                                        case OPf_WANT_VOID:                                                          sv_catpv(tmpsv, ",VOID");                                                break;                                                               case OPf_WANT_SCALAR:                                                        sv_catpv(tmpsv, ",SCALAR");                                              break;                                                               case OPf_WANT_LIST:                                                          sv_catpv(tmpsv, ",LIST");                                                break;                                                               default:                                                                     sv_catpv(tmpsv, ",UNKNOWN");                                             break;                                                               }                                                                        append_flags(tmpsv, o->op_flags, op_flags_names);                        if (o->op_slabbed)  sv_catpvs(tmpsv, ",SLABBED");                        if (o->op_savefree) sv_catpvs(tmpsv, ",SAVEFREE");                       if (o->op_static)   sv_catpvs(tmpsv, ",STATIC");                         if (!xml)                                                                     Perl_dump_indent(aTHX_ level, file, "FLAGS = (%s)\n",                                    SvCUR(tmpsv) ? SvPVX_const(tmpsv) + 1 : "");         else                                                                         PerlIO_printf(file, " flags=\"%s\"",                                                   SvCUR(tmpsv) ? SvPVX(tmpsv) + 1 : "");                 SvREFCNT_dec_NN(tmpsv);                                                 }
#if !defined(PERL_MAD)
# define xmldump_attr1(level, file, pat, arg)
#else
# define xmldump_attr1(level, file, pat, arg)  	S_xmldump_attr(aTHX_ level, file, pat, arg)
#endif
#define DUMP_OP_PRIVATE(o,xml,level,file)                                    if (o->op_private) {                                                         U32 optype = o->op_type;                                                 U32 oppriv = o->op_private;                                              SV * const tmpsv = newSVpvs("");                                 	if (PL_opargs[optype] & OA_TARGLEX) {                            	    if (oppriv & OPpTARGET_MY)                                   		sv_catpv(tmpsv, ",TARGET_MY");                           	}                                                                	else if (optype == OP_ENTERSUB ||                                                 optype == OP_RV2SV ||                                                    optype == OP_GVSV ||                                                     optype == OP_RV2AV ||                                                    optype == OP_RV2HV ||                                                    optype == OP_RV2GV ||                                                    optype == OP_AELEM ||                                                    optype == OP_HELEM )                                            {                                                                            if (optype == OP_ENTERSUB) {                                                 append_flags(tmpsv, oppriv, op_entersub_names);                      }                                                                        else {                                                                       switch (oppriv & OPpDEREF) {                                             case OPpDEREF_SV:                                                            sv_catpv(tmpsv, ",SV");                                                  break;                                                               case OPpDEREF_AV:                                                            sv_catpv(tmpsv, ",AV");                                                  break;                                                               case OPpDEREF_HV:                                                            sv_catpv(tmpsv, ",HV");                                                  break;                                                               }                                                                        if (oppriv & OPpMAYBE_LVSUB)                                                 sv_catpv(tmpsv, ",MAYBE_LVSUB");                                 }                                                                        if (optype == OP_AELEM || optype == OP_HELEM) {                              if (oppriv & OPpLVAL_DEFER)                                                  sv_catpv(tmpsv, ",LVAL_DEFER");                                  }                                                                        else if (optype == OP_RV2HV || optype == OP_PADHV) {                         if (oppriv & OPpMAYBE_TRUEBOOL)                                              sv_catpvs(tmpsv, ",OPpMAYBE_TRUEBOOL");                              if (oppriv & OPpTRUEBOOL)                                                    sv_catpvs(tmpsv, ",OPpTRUEBOOL");                                }                                                                        else {                                                                       if (oppriv & HINT_STRICT_REFS)                                               sv_catpv(tmpsv, ",STRICT_REFS");                                     if (oppriv & OPpOUR_INTRO)                                                   sv_catpv(tmpsv, ",OUR_INTRO");                                   }                                                                    }                                                                	else if (S_op_private_to_names(aTHX_ tmpsv, optype, oppriv)) {   	}                                                                	else if (OP_IS_FILETEST(o->op_type)) {                                       if (oppriv & OPpFT_ACCESS)                                                   sv_catpv(tmpsv, ",FT_ACCESS");                                       if (oppriv & OPpFT_STACKED)                                                  sv_catpv(tmpsv, ",FT_STACKED");                                      if (oppriv & OPpFT_STACKING)                                                 sv_catpv(tmpsv, ",FT_STACKING");                                     if (oppriv & OPpFT_AFTER_t)                                                  sv_catpv(tmpsv, ",AFTER_t");                             	}                                                                	else if (o->op_type == OP_AASSIGN) {                             	    if (oppriv & OPpASSIGN_COMMON)                               		sv_catpvs(tmpsv, ",COMMON");                             	    if (oppriv & OPpMAYBE_LVSUB)                                 		sv_catpvs(tmpsv, ",MAYBE_LVSUB");                        	}                                                                	if (o->op_flags & OPf_MOD && oppriv & OPpLVAL_INTRO)             	    sv_catpv(tmpsv, ",INTRO");                                   	if (o->op_type == OP_PADRANGE)                                   	    Perl_sv_catpvf(aTHX_ tmpsv, ",COUNT=%"UVuf,                                             (UV)(oppriv & OPpPADRANGE_COUNTMASK));        	if (SvCUR(tmpsv)) {                                                          if (xml)                                                                     xmldump_attr1(level+1, file, "private=\"%s\"", SvPVX(tmpsv)+1);              else                                                                         Perl_dump_indent(aTHX_ level, file, "PRIVATE = (%s)\n", SvPVX_const(tmpsv) + 1);  	} else if (!xml)                                                             Perl_dump_indent(aTHX_ level, file, "PRIVATE = (0x%"UVxf")\n",                               (UV)oppriv);                                	SvREFCNT_dec_NN(tmpsv);                                              }
#ifdef DUMPADDR
#endif
#ifdef PERL_MAD
#endif
#ifdef USE_ITHREADS
#else
#ifdef PERL_MAD
#endif
#endif
#ifndef USE_ITHREADS
#endif
#include "mg_names.c"
#ifdef DEBUG_LEAKING_SCALARS
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef USE_LONG_DOUBLE
#else
#endif
#ifdef PERL_NEW_COPY_ON_WRITE
#endif
#define FREQ_MAX ((int)(sizeof freq / sizeof freq[0] - 1))
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#define SV_SET_STRINGIFY_REGEXP_FLAGS(d,flags) STMT_START {              sv_setpv(d,"");                                              append_flags(d, flags, regexp_flags_names);                  if (SvCUR(d) > 0 && *(SvEND(d) - 1) == ',') {                        SvCUR_set(d, SvCUR(d) - 1);                                  SvPVX(d)[SvCUR(d)] = '\0';                               }                                                } STMT_END
#undef SV_SET_STRINGIFY_REGEXP_FLAGS
#ifdef PERL_ANY_COW
#endif
#ifdef USE_ITHREADS
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#ifdef DUMPADDR
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifndef USE_ITHREADS
#endif
#endif
