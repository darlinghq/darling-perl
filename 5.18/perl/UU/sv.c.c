#line 2 "sv.c"
#include "EXTERN.h"
#define PERL_IN_SV_C
#include "perl.h"
#include "regcomp.h"
#ifndef HAS_C99
# if __STDC_VERSION__ >= 199901L && !defined(VMS)
#  define HAS_C99 1
# endif
#endif
#if HAS_C99
# include <stdint.h>
#endif
#define FCALL *f
#ifdef __Lynx__
#endif
#ifdef PERL_UTF8_CACHE_ASSERT
#   define ASSERT_UTF8_CACHE(cache)      STMT_START { if (cache) { assert((cache)[0] <= (cache)[1]);  			      assert((cache)[2] <= (cache)[3]);  			      assert((cache)[3] <= (cache)[1]);}  			      } STMT_END
#else
#   define ASSERT_UTF8_CACHE(cache) NOOP
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#define SV_COW_NEXT_SV(sv)	INT2PTR(SV *,SvUVX(sv))
#define SV_COW_NEXT_SV_SET(current,next)	SvUV_set(current, PTR2UV(next))
#endif
#ifdef PERL_MEM_LOG
#  define MEM_LOG_NEW_SV(sv, file, line, func)	 	    Perl_mem_log_new_sv(sv, file, line, func)
#  define MEM_LOG_DEL_SV(sv, file, line, func)	 	    Perl_mem_log_del_sv(sv, file, line, func)
#else
#  define MEM_LOG_NEW_SV(sv, file, line, func)	NOOP
#  define MEM_LOG_DEL_SV(sv, file, line, func)	NOOP
#endif
#ifdef DEBUG_LEAKING_SCALARS
#  define FREE_SV_DEBUG_FILE(sv) STMT_START {  	if ((sv)->sv_debug_file) PerlMemShared_free((sv)->sv_debug_file);      } STMT_END
#  define DEBUG_SV_SERIAL(sv)						         DEBUG_m(PerlIO_printf(Perl_debug_log, "0x%"UVxf": (%05ld) del_SV\n",     	    PTR2UV(sv), (long)(sv)->sv_debug_serial))
#else
#  define FREE_SV_DEBUG_FILE(sv)
#  define DEBUG_SV_SERIAL(sv)	NOOP
#endif
#ifdef PERL_POISON
#  define SvARENA_CHAIN(sv)	((sv)->sv_u.svu_rv)
#  define SvARENA_CHAIN_SET(sv,val)	(sv)->sv_u.svu_rv = MUTABLE_SV((val))
#  define POSION_SV_HEAD(sv)	PoisonNew(sv, 1, struct STRUCT_SV)
#  define POSION_SV_HEAD(sv)	PoisonNew(&SvANY(sv), 1, void *),  				PoisonNew(&SvREFCNT(sv), 1, U32)
#else
#  define SvARENA_CHAIN(sv)	SvANY(sv)
#  define SvARENA_CHAIN_SET(sv,val)	SvANY(sv) = (void *)(val)
#  define POSION_SV_HEAD(sv)
#endif
#define plant_SV(p)      STMT_START {					 	const U32 old_flags = SvFLAGS(p);			 	MEM_LOG_DEL_SV(p, __FILE__, __LINE__, FUNCTION__);   	DEBUG_SV_SERIAL(p);				 	FREE_SV_DEBUG_FILE(p);				 	POSION_SV_HEAD(p);				 	SvFLAGS(p) = SVTYPEMASK;			 	if (!(old_flags & SVf_BREAK)) {		 	    SvARENA_CHAIN_SET(p, PL_sv_root);	 	    PL_sv_root = (p);				 	}						 	--PL_sv_count;					     } STMT_END
#define uproot_SV(p)      STMT_START {					 	(p) = PL_sv_root;				 	PL_sv_root = MUTABLE_SV(SvARENA_CHAIN(p));		 	++PL_sv_count;					     } STMT_END
#ifdef DEBUG_LEAKING_SCALARS
#  define new_SV(p) (p)=S_new_SV(aTHX_ __FILE__, __LINE__, FUNCTION__)
#else
#  define new_SV(p)      STMT_START {					 	if (PL_sv_root)					 	    uproot_SV(p);				 	else						 	    (p) = S_more_sv(aTHX);			 	SvANY(p) = 0;					 	SvREFCNT(p) = 1;				 	SvFLAGS(p) = 0;					 	MEM_LOG_NEW_SV(p, __FILE__, __LINE__, FUNCTION__);       } STMT_END
#endif
#ifdef DEBUGGING
#define del_SV(p)      STMT_START {					 	if (DEBUG_D_TEST)				 	    del_sv(p);					 	else						 	    plant_SV(p);				     } STMT_END
#else 
#define del_SV(p)   plant_SV(p)
#endif 
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#else
#endif
#define ARENAS_PER_SET  ((PERL_ARENA_SIZE - sizeof(struct arena_set*)  			  - 2 * sizeof(int)) / sizeof (struct arena_desc))
#define HADNV FALSE
#define NONV TRUE
#ifdef PURIFY
#define HASARENA FALSE
#else
#define HASARENA TRUE
#endif
#define NOARENA FALSE
#define FIT_ARENA0(body_size)				     ((size_t)(PERL_ARENA_SIZE / body_size) * body_size)
#define FIT_ARENAn(count,body_size)			     ( count * body_size <= PERL_ARENA_SIZE)		     ? count * body_size					     : FIT_ARENA0 (body_size)
#define FIT_ARENA(count,body_size)			     count 						     ? FIT_ARENAn (count, body_size)			     : FIT_ARENA0 (body_size)
#define copy_length(type, last_member)  	STRUCT_OFFSET(type, last_member)  	+ sizeof (((type*)SvANY((const SV *)0))->last_member)
#define new_body_allocated(sv_type)		     (void *)((char *)S_new_body(aTHX_ sv_type)	 	     - bodies_by_type[sv_type].offset)
#define del_body(thing, root)				     STMT_START {					 	void ** const thing_copy = (void **)thing;	 	*thing_copy = *root;				 	*root = (void*)thing_copy;			     } STMT_END
#ifdef PURIFY
#define new_XNV()	safemalloc(sizeof(XPVNV))
#define new_XPVNV()	safemalloc(sizeof(XPVNV))
#define new_XPVMG()	safemalloc(sizeof(XPVMG))
#define del_XPVGV(p)	safefree(p)
#else 
#define new_XNV()	new_body_allocated(SVt_NV)
#define new_XPVNV()	new_body_allocated(SVt_PVNV)
#define new_XPVMG()	new_body_allocated(SVt_PVMG)
#define del_XPVGV(p)	del_body(p + bodies_by_type[SVt_PVGV].offset,	 				 &PL_body_roots[SVt_PVGV])
#endif 
#define new_NOARENA(details)  	safemalloc((details)->body_size + (details)->offset)
#define new_NOARENAZ(details)  	safecalloc((details)->body_size + (details)->offset, 1)
#if defined(DEBUGGING) && !defined(PERL_GLOBAL_STRUCT_PRIVATE)
#endif
#if defined(MYMALLOC) || defined(HAS_MALLOC_GOOD_SIZE)
#else
#endif
#define new_body_inline(xpv, sv_type)      STMT_START {  	void ** const r3wt = &PL_body_roots[sv_type];  	xpv = (PTR_TBL_ENT_t*) (*((void **)(r3wt))       	  ? *((void **)(r3wt)) : Perl_more_bodies(aTHX_ sv_type,  					     bodies_by_type[sv_type].body_size, 					     bodies_by_type[sv_type].arena_size));  	*(r3wt) = *(void**)(xpv);      } STMT_END
#ifndef PURIFY
#endif
#ifndef PURIFY	
#else
#endif
#ifndef NODEFAULT_SHAREKEYS
#endif
#ifndef NV_ZERO_IS_ALLBITS_ZERO
#endif
#ifdef PURIFY
#else
#endif
#ifdef HAS_64K_LIMIT
#endif 
#ifdef HAS_64K_LIMIT
#endif
#ifndef Perl_safesysmalloc_size
#endif
#ifdef Perl_safesysmalloc_size
#else
#endif
   ####################################################################
   ####################################################################
#ifndef NV_PRESERVES_UV
#  define IS_NUMBER_UNDERFLOW_IV 1
#  define IS_NUMBER_UNDERFLOW_UV 2
#  define IS_NUMBER_IV_AND_UV    2
#  define IS_NUMBER_OVERFLOW_IV  4
#  define IS_NUMBER_OVERFLOW_UV  5
#  ifdef DEBUGGING
#  endif
#endif 
#if defined(NAN_COMPARE_BROKEN) && defined(Perl_isnan)
#endif
#ifndef NV_PRESERVES_UV
#endif
#ifndef  NV_PRESERVES_UV
#endif
#ifdef NV_PRESERVES_UV
#endif
#if defined(USE_LONG_DOUBLE)
#else
#endif
#ifdef NV_PRESERVES_UV
#else 
#  ifdef DEBUGGING
#  else
#  endif
#endif 
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef USE_LONG_DOUBLE
#else
#endif
#ifdef NV_PRESERVES_UV
#else
#endif
#ifdef NV_PRESERVES_UV
#else
#endif 
#if defined(USE_LONG_DOUBLE)
#else
#endif
#ifdef hcx
#endif
#if SV_COW_THRESHOLD
# define GE_COW_THRESHOLD(len)		((len) >= SV_COW_THRESHOLD)
#else
# define GE_COW_THRESHOLD(len)		1
#endif
#if SV_COWBUF_THRESHOLD
# define GE_COWBUF_THRESHOLD(len)	((len) >= SV_COWBUF_THRESHOLD)
#else
# define GE_COWBUF_THRESHOLD(len)	1
#endif
#ifdef PERL_NEW_COPY_ON_WRITE
#endif
#ifndef PERL_ANY_COW
#endif
#ifdef PERL_NEW_COPY_ON_WRITE
#else
#endif
#ifdef PERL_ANY_COW
# ifdef PERL_OLD_COPY_ON_WRITE
# else
# endif
#endif
#ifdef PERL_ANY_COW
# ifdef PERL_OLD_COPY_ON_WRITE
# else
# endif
#endif
#ifdef PERL_ANY_COW
# ifdef PERL_OLD_COPY_ON_WRITE
# else
# endif
#endif
#ifdef PERL_ANY_COW
# ifdef PERL_OLD_COPY_ON_WRITE
#  define SVt_COW SVt_PVIV
# else
#  define SVt_COW SVt_PV
# endif
# ifdef PERL_OLD_COPY_ON_WRITE
# endif
# ifdef PERL_OLD_COPY_ON_WRITE
# else
# endif
# ifdef PERL_OLD_COPY_ON_WRITE
# else
# endif
# ifdef PERL_OLD_COPY_ON_WRITE
# else
# endif
#endif
#ifdef DEBUGGING
#endif
#ifdef Perl_safesysmalloc_size
#else 
#endif
#ifdef DEBUGGING
#else
#endif
#ifdef Perl_safesysmalloc_size
#else
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_ANY_COW
# ifdef PERL_OLD_COPY_ON_WRITE
# endif
# ifdef PERL_NEW_COPY_ON_WRITE
# endif
# ifdef PERL_NEW_COPY_ON_WRITE
# endif
# ifdef PERL_OLD_COPY_ON_WRITE
# endif
#else
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#else
#endif
#ifdef DEBUG_LEAKING_SCALARS
#else
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_ANY_COW
# ifdef PERL_OLD_COPY_ON_WRITE
# else
# endif
# ifdef PERL_OLD_COPY_ON_WRITE
# endif
#else
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUG_LEAKING_SCALARS_FORK_DUMP
#else
    #ifdef DEBUG_LEAKING_SCALARS
    #endif
#ifdef DEBUG_LEAKING_SCALARS_ABORT
#endif
#endif
#ifdef DEBUG_LEAKING_SCALARS_ABORT
#endif
#define THREEWAY_SQUARE(a,b,c,d)  	    ((float)((d) - (c))) * ((float)((d) - (c)))  	    + ((float)((c) - (b))) * ((float)((c) - (b)))  	       + ((float)((b) - (a))) * ((float)((b) - (a)))
#ifdef USE_LOCALE_COLLATE
#endif 
#ifdef USE_LOCALE_COLLATE
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#endif 
#ifdef VMS
#include <rms.h>
#endif
#if defined(VMS) && defined(PERLIO_IS_STDIO)
#endif
#ifdef USE_HEAP_INSTEAD_OF_STACK	
#else
#endif
#ifdef USE_HEAP_INSTEAD_OF_STACK
#endif
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef PERL_PRESERVE_IVUV
#if defined(USE_LONG_DOUBLE)
#else
#endif
#endif 
#ifdef EBCDIC
#else
#endif
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef PERL_PRESERVE_IVUV
#if defined(USE_LONG_DOUBLE)
#else
#endif
#endif 
#define PUSH_EXTEND_MORTAL__SV_C(AnSv)      STMT_START {       	EXTEND_MORTAL(1);  	PL_tmps_stack[++PL_tmps_ix] = (AnSv);      } STMT_END
    #define newSVpvn_utf8(s, len, u)			 	newSVpvn_flags((s), (len), (u) ? SVf_UTF8 : 0)
#if defined(PERL_IMPLICIT_CONTEXT)
#endif
#ifdef USE_ITHREADS
#else
#endif
#if defined(VMS)
#else 
#  if defined(USE_ENVIRON_ARRAY)
#  endif 
#endif 
#if defined(PERL_IMPLICIT_CONTEXT)
#endif
#if defined(PERL_IMPLICIT_CONTEXT)
#endif
#define WARN_MISSING WARN_UNINITIALIZED 
#define VECTORIZE_ARGS	vecsv = va_arg(*args, SV*); 			vecstr = (U8*)SvPV_const(vecsv,veclen); 			vec_utf8 = DO_UTF8(vecsv);
#ifndef USE_LONG_DOUBLE
#endif 
#ifdef HAS_LDBL_SPRINTF_BUG
#endif
#if defined(HAS_LONG_DOUBLE) && LONG_DOUBLESIZE > DOUBLESIZE
#else
#endif
#ifdef WIN32
#  ifdef USE_64_BIT_INT
#  endif
#  ifdef USE_64_BIT_INT
#  endif
#endif
#if defined(HAS_QUAD) || defined(HAS_LONG_DOUBLE)
#ifdef HAS_QUAD
#endif
#endif
#if defined(HAS_QUAD) || defined(HAS_LONG_DOUBLE)
#endif
#if HAS_C99
#endif
#ifdef IV_IS_QUAD
#else
#endif
#if vdNUMBER
#endif
#if HAS_C99
#endif
#ifdef HAS_QUAD
#else
#endif
#ifdef HAS_QUAD
#else
#endif
#ifdef IV_IS_QUAD
#else
#endif
#ifdef IV_IS_QUAD
#else
#endif
#if HAS_C99
#endif
#ifdef HAS_QUAD
#else
#endif
#ifdef HAS_QUAD
#else
#endif
#if defined(USE_LONG_DOUBLE)
#endif
#if defined(USE_LONG_DOUBLE)
#endif
#if defined(HAS_LONG_DOUBLE)
#else
#endif
#if LONG_DOUBLESIZE > DOUBLESIZE
#else
#endif
#ifdef HAS_LDBL_SPRINTF_BUG
#  ifdef DBL_MAX
#    define MY_DBL_MAX DBL_MAX
#  else 
#    if DOUBLESIZE >= 8
#      define MY_DBL_MAX 1.7976931348623157E+308L
#    else
#      define MY_DBL_MAX 3.40282347E+38L
#    endif
#  endif
#  ifdef HAS_LDBL_SPRINTF_BUG_LESS1 
#    define MY_DBL_MAX_BUG 1L
#  else
#    define MY_DBL_MAX_BUG MY_DBL_MAX
#  endif
#  ifdef DBL_MIN
#    define MY_DBL_MIN DBL_MIN
#  else  
#    if DOUBLESIZE >= 8
#      define MY_DBL_MIN 2.2250738585072014E-308L
#    else
#      define MY_DBL_MIN 1.17549435E-38L
#    endif
#  endif
#if defined(DBL_MAX) && !defined(DBL_MIN)
#endif
#  undef MY_DBL_MAX
#  undef MY_DBL_MAX_BUG
#  undef MY_DBL_MIN
#endif 
#if defined(HAS_LONG_DOUBLE) && defined(PERL_PRIfldbl)
#endif
#if defined(HAS_LONG_DOUBLE)
#else
#endif
#if HAS_C99
#endif
#ifdef HAS_QUAD
#else
#endif
#if defined(USE_ITHREADS)
#ifndef GpREFCNT_inc
#  define GpREFCNT_inc(gp)	((gp) ? (++(gp)->gp_refcnt, (gp)) : (GP*)NULL)
#endif
#define sv_dup_inc_NN(s,t)	SvREFCNT_inc_NN(sv_dup_inc(s,t))
#define av_dup(s,t)	MUTABLE_AV(sv_dup((const SV *)s,t))
#define av_dup_inc(s,t)	MUTABLE_AV(sv_dup_inc((const SV *)s,t))
#define hv_dup(s,t)	MUTABLE_HV(sv_dup((const SV *)s,t))
#define hv_dup_inc(s,t)	MUTABLE_HV(sv_dup_inc((const SV *)s,t))
#define cv_dup(s,t)	MUTABLE_CV(sv_dup((const SV *)s,t))
#define cv_dup_inc(s,t)	MUTABLE_CV(sv_dup_inc((const SV *)s,t))
#define io_dup(s,t)	MUTABLE_IO(sv_dup((const SV *)s,t))
#define io_dup_inc(s,t)	MUTABLE_IO(sv_dup_inc((const SV *)s,t))
#define gv_dup(s,t)	MUTABLE_GV(sv_dup((const SV *)s,t))
#define gv_dup_inc(s,t)	MUTABLE_GV(sv_dup_inc((const SV *)s,t))
#define SAVEPV(p)	((p) ? savepv(p) : NULL)
#define SAVEPVN(p,n)	((p) ? savepvn(p,n) : NULL)
#ifdef PERL_MAD
#else
#endif
#ifdef HAS_FCHDIR
#endif
#ifdef HAS_FCHDIR
#ifdef DIRNAMLEN
# define d_namlen(d) (d)->d_namlen
#else
# define d_namlen(d) strlen((d)->d_name)
#endif
#undef d_namlen
#endif
#ifdef WIN32
#endif
#endif 
#define PTR_TABLE_HASH(ptr)    ((PTR2UV(ptr) >> 3) ^ (PTR2UV(ptr) >> (3 + 7)) ^ (PTR2UV(ptr) >> (3 + 17)))
#if defined(USE_ITHREADS)
#ifdef DEBUG_LEAKING_SCALARS_ABORT
#endif
#ifdef DEBUG_LEAKING_SCALARS
#endif
#ifdef DEBUGGING
#endif
#ifndef PURIFY
#else
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#define POPINT(ss,ix)	((ss)[--(ix)].any_i32)
#define TOPINT(ss,ix)	((ss)[ix].any_i32)
#define POPLONG(ss,ix)	((ss)[--(ix)].any_long)
#define TOPLONG(ss,ix)	((ss)[ix].any_long)
#define POPIV(ss,ix)	((ss)[--(ix)].any_iv)
#define TOPIV(ss,ix)	((ss)[ix].any_iv)
#define POPUV(ss,ix)	((ss)[--(ix)].any_uv)
#define TOPUV(ss,ix)	((ss)[ix].any_uv)
#define POPBOOL(ss,ix)	((ss)[--(ix)].any_bool)
#define TOPBOOL(ss,ix)	((ss)[ix].any_bool)
#define POPPTR(ss,ix)	((ss)[--(ix)].any_ptr)
#define TOPPTR(ss,ix)	((ss)[ix].any_ptr)
#define POPDPTR(ss,ix)	((ss)[--(ix)].any_dptr)
#define TOPDPTR(ss,ix)	((ss)[ix].any_dptr)
#define POPDXPTR(ss,ix)	((ss)[--(ix)].any_dxptr)
#define TOPDXPTR(ss,ix)	((ss)[ix].any_dxptr)
#define pv_dup_inc(p)	SAVEPV(p)
#define pv_dup(p)	SAVEPV(p)
#define svp_dup_inc(p,pp)	any_dup(p,pp)
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_IMPLICIT_SYS
#else		
#endif		
#ifdef DEBUGGING
#  ifdef DEBUG_LEAKING_SCALARS
#  endif
#else	
#endif	
#ifdef PERL_IMPLICIT_SYS
#endif		
#if !NO_TAINT_SUPPORT
#else
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#ifdef VMS
#else
#endif
#ifdef FCRYPT
#endif
#ifdef USE_LOCALE_COLLATE
#endif 
#ifdef USE_LOCALE_NUMERIC
#endif 
#ifdef HAS_TIMES
#endif
#if !NO_TAINT_SUPPORT
#else
#endif
#ifdef USE_REENTRANT_API
#endif
#ifdef PERLIO_LAYERS
#endif
#ifdef PERL_GLOBAL_STRUCT_PRIVATE
#endif
#ifdef PERL_GLOBAL_STRUCT_PRIVATE
#endif
#ifdef HAVE_INTERP_INTERN
#endif
#ifdef PERL_USES_PL_PIDSTATUS
#endif
#ifdef USE_LOCALE_COLLATE
#endif 
#ifdef USE_LOCALE_NUMERIC
#endif 
#ifdef DEBUGGING
#endif
#endif 
#define FUV_MAX_SEARCH_SIZE 1000
#define FUV_SUBSCRIPT_NONE	1	
#define FUV_SUBSCRIPT_ARRAY	2	
#define FUV_SUBSCRIPT_HASH	3	
#define FUV_SUBSCRIPT_WITHIN	4	
