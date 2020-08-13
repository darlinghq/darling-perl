#line 2 "taint.c"
#include "EXTERN.h"
#define PERL_IN_TAINT_C
#include "perl.h"
#if defined(HAS_SETEUID) && defined(DEBUGGING)
#   if Uid_t_size == 1
#   else
#   endif
#endif
#ifdef WIN32
#endif
#ifdef NO_TAINT_SUPPORT
#endif
#ifdef VMS
#endif 
#ifndef VMS
#ifdef NO_TAINT_SUPPORT
#endif
#endif 
