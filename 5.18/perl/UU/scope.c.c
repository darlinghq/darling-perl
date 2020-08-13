#line 2 "scope.c"
#include "EXTERN.h"
#define PERL_IN_SCOPE_C
#include "perl.h"
#ifndef STRESS_REALLOC
#else
#endif
#ifndef STRESS_REALLOC
#define GROW(old) ((old) * 3 / 2)
#else
#define GROW(old) ((old) + 1)
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#undef GROW
#ifndef STRESS_REALLOC
#endif
#ifdef PERL_POISON
#endif
#define ARG0_SV  MUTABLE_SV(arg0.any_ptr)
#define ARG0_AV  MUTABLE_AV(arg0.any_ptr)
#define ARG0_HV  MUTABLE_HV(arg0.any_ptr)
#define ARG0_PTR arg0.any_ptr
#define ARG0_PV  (char*)(arg0.any_ptr)
#define ARG0_PVP (char**)(arg0.any_ptr)
#define ARG0_I32 (arg0.any_i32)
#define ARG1_SV  MUTABLE_SV(arg1.any_ptr)
#define ARG1_AV  MUTABLE_AV(arg1.any_ptr)
#define ARG1_GV  MUTABLE_GV(arg1.any_ptr)
#define ARG1_SVP (SV**)(arg1.any_ptr)
#define ARG1_PVP (char**)(arg1.any_ptr)
#define ARG1_PTR arg1.any_ptr
#define ARG1_PV  (char*)(arg1.any_ptr)
#define ARG1_I32 (arg1.any_i32)
#define ARG2_SV  MUTABLE_SV(arg2.any_ptr)
#define ARG2_AV  MUTABLE_AV(arg2.any_ptr)
#define ARG2_HV  MUTABLE_HV(arg2.any_ptr)
#define ARG2_GV  MUTABLE_GV(arg2.any_ptr)
#define ARG2_PV  (char*)(arg2.any_ptr)
#ifdef NETWARE
#else
#endif
#ifdef NO_TAINT_SUPPORT
#else
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef DEBUGGING
#else
#endif	
