#line 2 "perlapi.c"
#include "EXTERN.h"
#include "perl.h"
#include "perlapi.h"
#if defined (MULTIPLICITY) && defined (PERL_GLOBAL_STRUCT)
#undef PERLVARI
#define PERLVARI(p,v,t,i) PERLVAR(p,v,t)
#undef PERLVAR
#undef PERLVARA
#define PERLVAR(p,v,t)		t* Perl_##p##v##_ptr(pTHX)		 			{ dVAR; PERL_UNUSED_CONTEXT; return &(PL_##v); }
#define PERLVARA(p,v,n,t)	PL_##v##_t* Perl_##p##v##_ptr(pTHX)	 			{ dVAR; PERL_UNUSED_CONTEXT; return &(PL_##v); }
#undef PERLVARIC
#define PERLVARIC(p,v,t,i)	 			const t* Perl_##p##v##_ptr(pTHX)		 			{ PERL_UNUSED_CONTEXT; return (const t *)&(PL_##v); }
#include "perlvars.h"
#undef PERLVAR
#undef PERLVARA
#undef PERLVARI
#undef PERLVARIC
#endif 
