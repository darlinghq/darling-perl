#line 2 "pad.c"
#include "EXTERN.h"
#define PERL_IN_PAD_C
#include "perl.h"
#include "keywords.h"
#define COP_SEQ_RANGE_LOW_set(sv,val)		   STMT_START { ((XPVNV*)SvANY(sv))->xnv_u.xpad_cop_seq.xlow = (val); } STMT_END
#define COP_SEQ_RANGE_HIGH_set(sv,val)		   STMT_START { ((XPVNV*)SvANY(sv))->xnv_u.xpad_cop_seq.xhigh = (val); } STMT_END
#define PARENT_PAD_INDEX_set(sv,val)		   STMT_START { ((XPVNV*)SvANY(sv))->xnv_u.xpad_cop_seq.xlow = (val); } STMT_END
#define PARENT_FAKELEX_FLAGS_set(sv,val)	   STMT_START { ((XPVNV*)SvANY(sv))->xnv_u.xpad_cop_seq.xhigh = (val); } STMT_END
#ifdef PERL_MAD
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef DEBUG_LEAKING_SCALARS
#endif
#define CvCOMPILED(cv)	CvROOT(cv)
#define CvLATE(cv) (CvANON(cv) || CvCLONE(cv) || SvTYPE(cv) == SVt_PVFM)
#ifdef DEBUGGING
#endif 
#ifdef USE_BROKEN_PAD_RESET
#else
#endif
#ifdef USE_BROKEN_PAD_RESET
#endif
#ifdef DEBUGGING
#endif 
#if defined(USE_ITHREADS)
#  define av_dup_inc(s,t)	MUTABLE_AV(sv_dup_inc((const SV *)s,t))
#endif 
