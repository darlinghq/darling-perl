#line 2 "hv.c"
#include "EXTERN.h"
#define PERL_IN_HV_C
#define PERL_HASH_INTERNAL_ACCESS
#include "perl.h"
#define DO_HSPLIT(xhv) ((xhv)->xhv_keys > (xhv)->xhv_max) 
#ifdef PURIFY
#define new_HE() (HE*)safemalloc(sizeof(HE))
#define del_HE(p) safefree((char*)p)
#else
#define new_HE() new_he()
#define del_HE(p)      STMT_START {  	HeNEXT(p) = (HE*)(PL_body_roots[HE_SVSLOT]);	 	PL_body_roots[HE_SVSLOT] = p;      } STMT_END
#endif
#if defined(USE_ITHREADS)
#endif	
#ifdef ENV_IS_CASELESS
#endif
#ifdef ENV_IS_CASELESS
#endif
#ifdef NO_TAINT_SUPPORT
#endif
#ifdef ENV_IS_CASELESS
#endif
#ifdef DYNAMIC_ENV_FETCH  
#endif
#ifdef DYNAMIC_ENV_FETCH
#endif
#ifdef DYNAMIC_ENV_FETCH
#endif
#ifdef DYNAMIC_ENV_FETCH  
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef ENV_IS_CASELESS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#define HV_SET_MAX_ADJUSTED_FOR_KEYS(hv,hv_max,hv_keys) STMT_START {                  if (hv_max < PERL_HASH_DEFAULT_HvMAX) {                                  hv_max = PERL_HASH_DEFAULT_HvMAX;                                } else {                                                                 while (hv_max > PERL_HASH_DEFAULT_HvMAX && hv_max + 1 >= hv_keys * 2)              hv_max = hv_max / 2;                                         }                                                                    HvMAX(hv) = hv_max;                                              } STMT_END
#undef HV_SET_MAX_ADJUSTED_FOR_KEYS
#ifdef DEBUGGING
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#if PTRSIZE == 8
#else
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#else
#endif
#if defined(DYNAMIC_ENV_FETCH) && !defined(__riscos__)  
#ifdef VMS
#endif
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#ifdef PERL_HASH_RANDOMIZE_KEYS
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
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifndef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef DEBUGGING
#endif
