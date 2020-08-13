#line 2 "pp.c"
#include "EXTERN.h"
#define PERL_IN_PP_C
#include "perl.h"
#include "keywords.h"
#include "reentr.h"
#include "regcharclass.h"
#ifdef NEED_GETPID_PROTO
#endif
#if defined(LIBM_LIB_VERSION)
#endif
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef PERL_PRESERVE_IVUV
#endif    
#if defined(USE_LONG_DOUBLE) && defined(HAS_AIX_POWL_NEG_BASE_BUG)
#else
#endif  
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef SLOPPYDIVIDE
#  define PERL_TRY_UV_DIVIDE
#else
#  ifdef PERL_PRESERVE_IVUV
#    ifndef NV_PRESERVES_UV
#      define PERL_TRY_UV_DIVIDE
#    endif
#  endif
#endif
#ifdef PERL_TRY_UV_DIVIDE
#ifdef SLOPPYDIVIDE
#else
#endif
#endif 
#if defined(NAN_COMPARE_BROKEN) && defined(Perl_isnan)
#else
#endif
#if 0
#else
#endif
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef PERL_PRESERVE_IVUV
#endif
#if defined(NAN_COMPARE_BROKEN) && defined(Perl_isnan)
#else
#endif
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef LIBERAL
#endif
#if defined(__GLIBC__) && IVSIZE == 8 && !defined(PERL_DEBUG_READONLY_OPS)
#else
#endif
#if defined(__GLIBC__) && IVSIZE == 8 && !defined(PERL_DEBUG_READONLY_OPS)
#endif
#ifndef HAS_DRAND48_PROTO
#endif
#ifdef USE_LOCALE_COLLATE
#endif
#ifdef HAS_CRYPT
#   ifdef USE_ITHREADS
#     ifdef HAS_CRYPT_R
#if defined(__GLIBC__) || defined(__EMX__)
#endif
#     endif 
#   endif 
#   ifdef FCRYPT
#   else
#   endif
#else
#endif
#define CAT_UNI_TO_UTF8_TWO_BYTE(p, c)					         STMT_START {							     	*(p)++ = UTF8_TWO_BYTE_HI(c);					     	*((p)++) = UTF8_TWO_BYTE_LO(c);					         } STMT_END
#define GREEK_CAPITAL_LETTER_IOTA 0x0399
#define COMBINING_GREEK_YPOGEGRAMMENI 0x0345
#if defined(__GNUC__) && !defined(PERL_GCC_BRACE_GROUPS_FORBIDDEN)
# define DEREF_PLAIN_ARRAY(ary)           ({                                        AV *aRrRay = ary;                        SvTYPE(aRrRay) == SVt_PVAV                 ? aRrRay                                   : S_deref_plain_array(aTHX_ aRrRay);     })
#else
# define DEREF_PLAIN_ARRAY(ary)                (                                              PL_Sv = (SV *)(ary),                          SvTYPE(PL_Sv) == SVt_PVAV                       ? (AV *)PL_Sv                                   : S_deref_plain_array(aTHX_ (AV *)PL_Sv)      )
#endif
#ifdef DEBUGGING
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
