#line 2 "mro.c"
#include "EXTERN.h"
#define PERL_IN_MRO_C
#include "perl.h"
#if defined(USE_ITHREADS)
#endif 
#define CLEAR_LINEAR(mEta)                                          if (mEta->mro_linear_all) {                                  	SvREFCNT_dec(MUTABLE_SV(mEta->mro_linear_all));           	mEta->mro_linear_all = NULL;                               	           	mEta->mro_linear_current = NULL;                                 } else if (mEta->mro_linear_current) {                            	  	SvREFCNT_dec(mEta->mro_linear_current);                         	mEta->mro_linear_current = NULL;                                     }
#include "XSUB.h"
