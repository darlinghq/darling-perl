#line 2 "op.c"
#include "EXTERN.h"
#define PERL_IN_OP_C
#include "perl.h"
#include "keywords.h"
#include "feature.h"
#include "regcomp.h"
#define CALL_PEEP(o) PL_peepp(aTHX_ o)
#define CALL_RPEEP(o) PL_rpeepp(aTHX_ o)
#define CALL_OPFREEHOOK(o) if (PL_opfreehook) PL_opfreehook(aTHX_ o)
#ifdef PERL_DEBUG_READONLY_OPS
#  define PERL_SLAB_SIZE 128
#  define PERL_MAX_SLAB_SIZE 4096
#  include <sys/mman.h>
#endif
#ifndef PERL_SLAB_SIZE
#  define PERL_SLAB_SIZE 64
#endif
#ifndef PERL_MAX_SLAB_SIZE
#  define PERL_MAX_SLAB_SIZE 2048
#endif
#define SIZE_TO_PSIZE(x)	(((x) + sizeof(I32 *) - 1)/sizeof(I32 *))
#define DIFF(o,p)		((size_t)((I32 **)(p) - (I32**)(o)))
#ifdef PERL_DEBUG_READONLY_OPS
#else
#endif
#define DEBUG_S_warn(args)					            DEBUG_S( 								 	PerlIO_printf(Perl_debug_log, "%s", SvPVx_nolen(Perl_mess args))      )
#if defined(USE_ITHREADS) && IVSIZE > U32SIZE && IVSIZE > PTRSIZE
#endif
#define INIT_OPSLOT  	    slot->opslot_slab = slab;			 	    slot->opslot_next = slab2->opslab_first;	 	    slab2->opslab_first = slot;			 	    o = &slot->opslot_op;			 	    o->op_slabbed = 1
#undef INIT_OPSLOT
#ifdef PERL_DEBUG_READONLY_OPS
#else
#  define Slab_to_rw(op)
#endif
#ifdef NETWARE
#    define PerlMemShared PerlMem
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#else
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#define CHECKOP(type,o)      ((PL_op_mask && PL_op_mask[type])				      ? ( op_free((OP*)o),					 	 Perl_croak(aTHX_ "'%s' trapped by operation mask", PL_op_desc[type]),	 	 (OP*)0 )						      : PL_check[type](aTHX_ (OP*)o))
#define RETURN_UNLIMITED_NUMBER (PERL_INT_MAX / 2)
#define CHANGE_TYPE(o,type)      STMT_START {				 	o->op_type = (OPCODE)type;		 	o->op_ppaddr = PL_ppaddr[type];		     } STMT_END
#ifdef USE_ITHREADS
#endif
#ifdef DEBUG_LEAKING_SCALARS
#endif
#ifdef PERL_MAD
#endif    
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#if defined(PERL_MAD) && defined(USE_ITHREADS)
#endif
#ifdef USE_ITHREADS
#endif
#ifdef PERL_MAD
#endif
#define ATTRSMODULE "attributes"
#define ATTRSMODULE_PM "attributes.pm"
#if 0
#else
#endif
#if 0
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifndef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef USE_ITHREADS
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef USE_ITHREADS
#endif 
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifndef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_IMPLICIT_CONTEXT
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef NATIVE_HINTS
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef VMS
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifndef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef VMS
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#if !defined(PERL_EXTERNAL_GLOB)
#endif 
#ifdef NO_TAINT_SUPPORT
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifndef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#define MAX_DEFERRED 4
#define DEFER(o)    STMT_START {      if (defer_ix == (MAX_DEFERRED-1)) {  	CALL_RPEEP(defer_queue[defer_base]);  	defer_base = (defer_base + 1) % MAX_DEFERRED;  	defer_ix--;      }      defer_queue[(defer_base + ++defer_ix) % MAX_DEFERRED] = o;    } STMT_END
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#define HV_OR_SCALARHV(op)                                        (  (op)->op_type == OP_PADHV || (op)->op_type == OP_RV2HV         ? (op)                                                          : (op)->op_type == OP_SCALAR && (op)->op_flags & OPf_KIDS         && (  cUNOPx(op)->op_first->op_type == OP_PADHV                     || cUNOPx(op)->op_first->op_type == OP_RV2HV)                    ? cUNOPx(op)->op_first                                             : NULL)
#undef HV_OR_SCALARHV
#define MAX_ARGS_OP ((sizeof(I32) - 1) * 2)
#define retsetpvs(x,y) sv_setpvs(sv, x); if(opnum) *opnum=(y); return sv
#undef retsetpvs
#include "XSUB.h"
#if 0
#endif
