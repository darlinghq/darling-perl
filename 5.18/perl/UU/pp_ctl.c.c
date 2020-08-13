#line 2 "pp_ctl.c"
#include "EXTERN.h"
#define PERL_IN_PP_CTL_C
#include "perl.h"
#define DOCATCH(o) ((CATCH_GET == TRUE) ? docatch(o) : (o))
#define dopoptosub(plop)	dopoptosub_at(cxstack, (plop))
#if defined(USE_ITHREADS)
#endif
#if NO_TAINT_SUPPORT
#endif
#ifndef INCOMPLETE_TAINTS
#endif
#if !defined(USE_ITHREADS)
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_ANY_COW
#else
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_POISON
#ifdef PERL_ANY_COW
#else
#endif
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_POISON
#endif
#define FORM_NUM_BLANK (1<<30)
#define FORM_NUM_POINT (1<<29)
#ifdef EBCDIC
#else
#endif
#if defined(USE_LONG_DOUBLE)
#else
#endif
#if defined(USE_LONG_DOUBLE)
#else
#endif
#define RANGE_IS_NUMERIC(left,right) (  	SvNIOKp(left)  || (SvOK(left)  && !SvPOKp(left))  ||  	SvNIOKp(right) || (SvOK(right) && !SvPOKp(right)) ||  	(((!SvOK(left) && SvOK(right)) || ((!SvOK(left) ||            looks_like_number(left)) && SvPOKp(left) && *SvPVX_const(left) != '0'))           && (!SvOK(right) || looks_like_number(right))))
#ifdef USE_ITHREADS
#else
#endif
#ifdef NV_PRESERVES_UV
#else
#endif
#ifdef DEBUGGING
#endif
#define GOTO_DEPTH 64
#ifdef VMS
#endif
#ifdef VMS
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_MAD
#endif
#if !defined(PERLIO_IS_STDIO) && !defined(USE_SFIO)
#else
#endif
#ifndef PERL_DISABLE_PMC
#else
#  define doopen_pm(name) check_type_and_open(name)
#endif 
#ifdef VMS
#endif
#ifdef VMS
#endif
#ifdef VMS
#endif
#ifdef VMS
#else
#  ifdef __SYMBIAN32__
#  else
#  endif
#endif
#ifdef DEBUGGING
#endif
#ifdef WIN32
#else
#endif
