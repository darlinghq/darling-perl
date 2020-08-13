#line 2 "utf8.c"
#include "EXTERN.h"
#define PERL_IN_UTF8_C
#include "perl.h"
#include "inline_invlist.c"
#ifndef EBCDIC
#endif
#if defined(EBCDIC)
#else 
#ifdef HAS_QUAD
#endif
#ifdef HAS_QUAD
#endif
#endif 
#ifdef IS_UTF8_CHAR
#endif 
#ifdef EBCDIC
#endif
#ifndef EBCDIC	
#endif
#ifndef EBCDIC	
#endif
#ifdef EBCDIC
#else
#endif
#define CALL_UPPER_CASE(INP, OUTP, LENP) Perl_to_utf8_case(aTHX_ INP, OUTP, LENP, &PL_utf8_toupper, "ToUc", "utf8::ToSpecUc")
#define CALL_TITLE_CASE(INP, OUTP, LENP) Perl_to_utf8_case(aTHX_ INP, OUTP, LENP, &PL_utf8_totitle, "ToTc", "utf8::ToSpecTc")
#define CALL_LOWER_CASE(INP, OUTP, LENP) Perl_to_utf8_case(aTHX_ INP, OUTP, LENP, &PL_utf8_tolower, "ToLc", "utf8::ToSpecLc")
#define CALL_FOLD_CASE(INP, OUTP, LENP, SPECIALS) Perl_to_utf8_case(aTHX_ INP, OUTP, LENP, &PL_utf8_tofold, "ToCf", (SPECIALS) ? "utf8::ToSpecCf" : NULL)
#ifdef EBCDIC
#else
#endif
#ifndef NO_TAINT_SUPPORT
#endif
