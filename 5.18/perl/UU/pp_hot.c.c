#line 2 "pp_hot.c"
#include "EXTERN.h"
#define PERL_IN_PP_HOT_C
#include "perl.h"
#ifdef PERL_PRESERVE_IVUV
#endif
#ifdef DEBUGGING
#else
#endif
#ifdef HAS_SETRESUID
#else
#  ifdef HAS_SETREUID
#  else
#    ifdef HAS_SETRUID
#    endif 
#    ifdef HAS_SETEUID
#    endif 
#  endif 
#endif 
#ifdef HAS_SETRESGID
#else
#  ifdef HAS_SETREGID
#  else
#    ifdef HAS_SETRGID
#    endif 
#    ifdef HAS_SETEGID
#    endif 
#  endif 
#endif 
#ifdef NO_TAINT_SUPPORT
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#define MAYBE_TAINT_LINE(io, sv)      if (!(IoFLAGS(io) & IOf_UNTAINT)) {  	TAINT;				 	SvTAINTED_on(sv);		     }
#define SNARF_EOF(gimme,rs,io,sv)      (gimme != G_SCALAR || SvCUR(sv)					      || (IoFLAGS(io) & IOf_NOLINE) || !RsSNARF(rs))
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_ANY_COW
#else
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_SAWAMPERSAND
#else
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_MALLOC_WRAP
#endif
