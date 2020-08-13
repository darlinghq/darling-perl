#line 2 "numeric.c"
#include "EXTERN.h"
#define PERL_IN_NUMERIC_C
#include "perl.h"
#if CASTFLAGS & 2
#else
#endif
#if CASTFLAGS & 2
#else
#endif
#if CASTFLAGS & 2
#else
#endif
#if CASTFLAGS & 2
#else
#endif
#if UVSIZE > 4
#endif
#if UVSIZE > 4
#endif
#if UVSIZE > 4
#endif
#ifdef USE_LOCALE_NUMERIC
#endif
#if ((defined(VMS) && !defined(_IEEE_FP)) || defined(_UNICOS)) && defined(NV_MAX_10_EXP)
#endif
#ifdef USE_LOCALE_NUMERIC
#else
#endif
#ifdef USE_PERL_ATOF
#ifdef MAX_SIG_DIG_PLUS
# define MAX_SIG_DIGITS (NV_DIG+MAX_SIG_DIG_PLUS)
#else
# define MAX_SIG_DIGITS (NV_DIG+2)
#endif
#define MAX_ACCUMULATE ( (UV) ((UV_MAX - 9)/10))
#ifdef HAS_STRTOD
#endif
#endif 
#if ! defined(HAS_MODFL) && defined(HAS_AINTL) && defined(HAS_COPYSIGNL)
#endif
#if ! defined(HAS_FREXPL) && defined(HAS_ILOGBL) && defined(HAS_SCALBNL)
#endif
#if !defined(HAS_SIGNBIT)
#endif
