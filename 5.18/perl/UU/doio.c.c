#line 2 "doio.c"
#include "EXTERN.h"
#define PERL_IN_DOIO_C
#include "perl.h"
#if defined(HAS_MSG) || defined(HAS_SEM) || defined(HAS_SHM)
#ifndef HAS_SEM
#include <sys/ipc.h>
#endif
#ifdef HAS_MSG
#include <sys/msg.h>
#endif
#ifdef HAS_SHM
#include <sys/shm.h>
# ifndef HAS_SHMAT_PROTOTYPE
# endif
#endif
#endif
#ifdef I_UTIME
#  if defined(_MSC_VER) || defined(__MINGW32__)
#    include <sys/utime.h>
#  else
#    include <utime.h>
#  endif
#endif
#ifdef O_EXCL
#  define OPEN_EXCL O_EXCL
#else
#  define OPEN_EXCL 0
#endif
#define PERL_MODE_MAX 8
#define PERL_FLAGS_MAX 10
#include <signal.h>
#ifdef O_APPEND	
#endif
#ifdef O_TRUNC	
#endif
#if defined(USE_64_BIT_RAWIO) && defined(O_LARGEFILE)
#endif
#ifdef USE_STDIO
#endif 
#ifdef EINVAL
#endif
#ifdef USE_SFIO
#endif
#ifndef PERL_MICRO
#ifdef HAS_SOCKET
#ifdef S_IFMT
#else
#endif
#endif 
#endif 
#ifdef VMS
#endif
#if !defined(WIN32)
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#ifndef FLEXFILENAMES
#endif
#ifdef HAS_FCHMOD
#else
#endif
#ifndef FLEXFILENAMES
#endif
#ifndef FLEXFILENAMES
#ifdef DJGPP
#endif
#endif
#ifdef HAS_RENAME
#if !defined(DOSISH) && !defined(__CYGWIN__)
#else
#endif 
#else
#endif
#if !defined(DOSISH) && !defined(AMIGAOS)
#  ifndef VMS  
#  endif
#else
#endif
#ifdef VMS
#else
#endif
#ifdef HAS_FCHMOD
#else
#endif
#ifdef HAS_FCHOWN
#else
#ifdef HAS_CHOWN
#endif
#endif
#ifdef ULTRIX_STDIO_BOTCH
#endif
#ifdef ULTRIX_STDIO_BOTCH
#endif
#ifndef PERLIO_LAYERS
#else
#endif
#if !defined(HAS_TRUNCATE) && !defined(HAS_CHSIZE)
#ifdef F_FREESP
#define HAS_CHSIZE
#else
#endif 
#endif 
#if defined(__SYMBIAN32__) || defined(__LIBCATAMOUNT__)
#else
#endif
#ifdef PERL_DEFAULT_DO_EXEC3_IMPLEMENTATION
#ifdef CSH
#endif 
#endif 
#ifdef VMS
#include <starlet.h> 
#endif
#ifndef HAS_KILL
#endif
#ifndef HAS_CHOWN
#endif
#define APPLY_TAINT_PROPER()      STMT_START {							 	if (TAINT_get) { TAINT_PROPER(what); }				     } STMT_END
#ifdef HAS_FCHMOD
#else
#endif
#ifdef HAS_CHOWN
#ifdef HAS_FCHOWN
#else
#endif
#endif
#ifdef HAS_KILL
#ifdef VMS
#endif
#endif
#if defined(HAS_UTIME) || defined(HAS_FUTIMES)
#if defined(HAS_FUTIMES)
#elif defined(I_UTIME) || defined(VMS)
#else
#endif
#ifdef HAS_FUTIMES
#elif defined(BIG_TIME)
#else
#endif
#ifdef HAS_FUTIMES
#else
#endif
#ifdef HAS_FUTIMES
#else
#endif
#endif
#undef APPLY_TAINT_PROPER
#ifndef VMS 
#ifdef DOSISH
#else 
# ifdef __CYGWIN__
# else
# endif
#endif 
#endif 
#ifdef HAS_GETGROUPS
#else
#endif
#if defined(HAS_MSG) || defined(HAS_SEM) || defined(HAS_SHM)
#ifdef HAS_MSG
#endif
#ifdef HAS_SEM
#endif
#ifdef HAS_SHM
#endif
#if !defined(HAS_MSG) || !defined(HAS_SEM) || !defined(HAS_SHM)
#endif
#ifdef Semctl
#endif
#ifdef HAS_MSG
#endif
#ifdef HAS_SHM
#endif
#ifdef HAS_SEM
#ifdef Semctl
#ifdef EXTRA_F_IN_SEMUN_BUF
#else
#endif
#else
#endif
#endif
#if !defined(HAS_MSG) || !defined(HAS_SEM) || !defined(HAS_SHM)
#endif
#ifdef HAS_MSG
#endif
#ifdef HAS_SEM
#ifdef Semctl
#ifdef EXTRA_F_IN_SEMUN_BUF
#else
#endif
#else
#endif
#endif
#ifdef HAS_SHM
#endif
#ifdef HAS_MSG
#else
#endif
#ifdef HAS_MSG
#ifndef INCOMPLETE_TAINTS
#endif
#else
#endif
#ifdef HAS_SEM
#else
#endif
#ifdef HAS_SHM
#ifndef INCOMPLETE_TAINTS
#endif
#else
#endif
#endif 
#ifdef VMS 
#else 
#ifdef DOSISH
#ifdef OS2
#else
#ifdef DJGPP
#else
#endif 
#endif 
#else 
#if defined(CSH)
#else
#if 'z' - 'a' == 25
#else
#endif
#endif 
#endif 
#endif 
