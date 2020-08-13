#line 2 "mg.c"
#include "EXTERN.h"
#define PERL_IN_MG_C
#include "perl.h"
#if defined(HAS_GETGROUPS) || defined(HAS_SETGROUPS)
#  ifdef I_GRP
#    include <grp.h>
#  endif
#endif
#if defined(HAS_SETGROUPS)
#  ifndef NGROUPS
#    define NGROUPS 32
#  endif
#endif
#ifdef __hpux
#  include <sys/pstat.h>
#endif
#ifdef HAS_PRCTL_SET_NAME
#  include <sys/prctl.h>
#endif
#if defined(HAS_SIGACTION) && defined(SA_SIGINFO)
#else
#endif
#ifdef __Lynx__
#endif
#define mg_free_struct(sv, mg) S_mg_free_struct(aTHX_ sv, mg)
#include <signal.h>
#define SvRTRIM(sv) STMT_START {      if (SvPOK(sv)) {          STRLEN len = SvCUR(sv);          char * const p = SvPVX(sv);  	while (len > 0 && isSPACE(p[len-1]))  	   --len;  	SvCUR_set(sv, len);  	p[len] = '\0';      }  } STMT_END
#ifdef VMS
#include <descrip.h>
#include <starlet.h>
#endif
#if defined(VMS)
#elif defined(OS2)
#elif defined(WIN32)
#else
#endif
#ifdef BIG_TIME
#else
#endif
#ifdef COMPLEX_STATUS
#endif
#ifdef VMS
#else
#endif
#ifdef OS2
#endif
#ifdef HAS_GETGROUPS
#endif
#ifdef DYNAMIC_ENV_FETCH
#endif
#if !defined(OS2) && !defined(AMIGAOS) && !defined(WIN32) && !defined(MSDOS)
#ifdef VMS
#endif 
#ifdef VMS  
#else
#endif
#ifdef VMS
#else
#endif
#endif 
#if defined(VMS)
#else
#endif
#if defined(VMS)
#else
#endif
#ifndef PERL_MICRO
#ifdef HAS_SIGPROCMASK
#endif
#ifdef FAKE_PERSISTENT_SIGNAL_HANDLERS
#endif
#ifdef FAKE_DEFAULT_SIGNAL_HANDLERS
#endif
#if defined(HAS_SIGACTION) && defined(SA_SIGINFO)
#else
#endif
#ifdef PERL_GET_SIG_CONTEXT
#else
#endif
#ifdef FAKE_PERSISTENT_SIGNAL_HANDLERS
#endif
#ifdef FAKE_DEFAULT_SIGNAL_HANDLERS
#ifdef KILL_BY_SIGPRC
#else
#endif
#endif
#ifdef SIGILL
#endif
#ifdef SIGBUS
#endif
#ifdef SIGSEGV
#endif
#if defined(HAS_SIGACTION) && defined(SA_SIGINFO)
#else
#endif
#ifndef SIG_PENDING_DIE_COUNT
#  define SIG_PENDING_DIE_COUNT 120
#endif
#if defined(FAKE_PERSISTENT_SIGNAL_HANDLERS) || defined(FAKE_DEFAULT_SIGNAL_HANDLERS)
#ifdef FAKE_DEFAULT_SIGNAL_HANDLERS
#endif
#ifdef FAKE_PERSISTENT_SIGNAL_HANDLERS
#endif
#endif
#if defined HAS_SIGPROCMASK
#endif
#ifdef HAS_SIGPROCMASK
#endif
#if defined(HAS_SIGACTION) && defined(SA_SIGINFO)
#else
#endif
#ifdef HAS_SIGPROCMASK
#endif
#ifdef HAS_SIGPROCMASK
#endif
#ifdef HAS_SIGPROCMASK
#endif
#if defined(FAKE_PERSISTENT_SIGNAL_HANDLERS) || defined(FAKE_DEFAULT_SIGNAL_HANDLERS)
#endif
#ifdef FAKE_PERSISTENT_SIGNAL_HANDLERS
#endif
#ifdef FAKE_DEFAULT_SIGNAL_HANDLERS
#endif
#ifdef FAKE_PERSISTENT_SIGNAL_HANDLERS
#else
#endif
#ifdef FAKE_DEFAULT_SIGNAL_HANDLERS
#else
#endif
#ifdef HAS_SIGPROCMASK
#endif
#endif 
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#if IVSIZE == I32SIZE
#else
#endif
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef NO_TAINT_SUPPORT
#endif
#ifdef USE_LOCALE_COLLATE
#endif 
#ifdef DEBUGGING
#else
#endif
#ifdef VMS
#else
#  ifdef WIN32
#  else
#    ifdef OS2
#    else
#    endif
#  endif
#endif
#ifdef BIG_TIME
#else
#endif
#ifdef COMPLEX_STATUS
#endif
#ifdef VMSISH_STATUS
#endif
#ifdef VMS
#   define PERL_VMS_BANG vaxc$errno
#else
#   define PERL_VMS_BANG 0
#endif
#ifdef HAS_SETRUID
#else
#ifdef HAS_SETREUID
#else
#ifdef HAS_SETRESUID
#else
#ifdef PERL_DARWIN
#endif
#endif
#endif
#endif
#ifdef HAS_SETEUID
#else
#ifdef HAS_SETREUID
#else
#ifdef HAS_SETRESUID
#else
#endif
#endif
#endif
#ifdef HAS_SETRGID
#else
#ifdef HAS_SETREGID
#else
#ifdef HAS_SETRESGID
#else
#endif
#endif
#endif
#ifdef HAS_SETGROUPS
#ifdef _SC_NGROUPS_MAX
#else
#endif
#else  
#endif 
#ifdef HAS_SETEGID
#else
#ifdef HAS_SETREGID
#else
#ifdef HAS_SETRESGID
#else
#endif
#endif
#endif
#ifdef HAS_SETPROCTITLE
#   if __FreeBSD_version > 410001
#   else	
#   endif
#elif defined(__hpux) && defined(PSTAT_SETCMD)
#else
#ifdef PERL_DARWIN
#else
#endif
#ifdef HAS_PRCTL_SET_NAME
#endif
#endif
#ifdef SIGCLD
#endif
#ifdef SIGCHLD
#endif
#if defined(HAS_SIGACTION) && defined(SA_SIGINFO)
#else
#endif
#ifdef PERL_GET_SIG_CONTEXT
#else
#endif
#if defined(HAS_SIGACTION) && defined(SA_SIGINFO)
#if 0 
#endif
#endif
#ifndef PERL_MICRO
#ifdef HAS_SIGPROCMASK
#if defined(HAS_SIGACTION) && defined(SA_SIGINFO)
#endif
#else
#endif
#endif 
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
