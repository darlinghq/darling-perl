#line 2 "perl.c"
#if defined(PERL_IS_MINIPERL) && !defined(USE_SITECUSTOMIZE)
#  define USE_SITECUSTOMIZE
#endif
#include "EXTERN.h"
#define PERL_IN_PERL_C
#include "perl.h"
#include "patchlevel.h"			
#include "XSUB.h"
#ifdef NETWARE
#include "nwutil.h"	
#endif
#ifdef USE_KERN_PROC_PATHNAME
#  include <sys/sysctl.h>
#endif
#ifdef USE_NSGETEXECUTABLEPATH
#  include <mach-o/dyld.h>
#endif
#ifdef DEBUG_LEAKING_SCALARS_FORK_DUMP
#  ifdef I_SYSUIO
#    include <sys/uio.h>
#  endif
#endif
#ifndef HZ
#  ifdef CLK_TCK
#    define HZ CLK_TCK
#  else
#    define HZ 60
#  endif
#endif
#if !defined(STANDARD_C) && !defined(HAS_GETENV_PROTOTYPE) && !defined(PERL_MICRO)
#endif
#ifndef OPEN_SOURCE
#ifdef __APPLE__
#include <rootless.h>
#endif
#endif
#ifdef SETUID_SCRIPTS_ARE_SECURE_NOW
#  define validate_suid(rsfp) NOOP
#else
#  define validate_suid(rsfp) S_validate_suid(aTHX_ rsfp)
#endif
#define CALL_BODY_SUB(myop)      if (PL_op == (myop))  	PL_op = PL_ppaddr[OP_ENTERSUB](aTHX);      if (PL_op)  	CALLRUNOPS(aTHX);
#define CALL_LIST_BODY(cv)      PUSHMARK(PL_stack_sp);      call_sv(MUTABLE_SV((cv)), G_EVAL|G_DISCARD|G_VOID);
#if defined(USE_ITHREADS)
#  endif
#if defined(USE_ITHREADS)
#else
#endif
#ifdef PERL_IMPLICIT_SYS
#else
#ifndef PERL_TRACK_MEMPOOL
#else
#endif
#endif 
#ifdef MULTIPLICITY
#else
#endif
#ifdef PERL_USES_PL_PIDSTATUS
#endif
#if defined(LOCAL_PATCH_COUNT)
#endif
#ifdef HAVE_INTERP_INTERN
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_REENTRANT_API
#endif
#if defined(USE_HASH_SEED) || defined(USE_HASH_SEED_EXPLICIT)
#endif 
#if defined(__DYNAMIC__) && (defined(NeXT) || defined(__NeXT__))
#endif 
#ifndef PERL_MICRO
#   ifdef  USE_ENVIRON_ARRAY
#   endif
#endif
#if defined(HAS_SYSCONF) && defined(_SC_CLK_TCK)
#endif
#ifdef HAS_MMAP
#if defined(HAS_SYSCONF) && (defined(_SC_PAGESIZE) || defined(_SC_MMAP_PAGE_SIZE))
#   ifdef _SC_PAGESIZE
#   else
#   endif
#else
#   ifdef HAS_GETPAGESIZE
#   else
#       if defined(I_SYS_PARAM) && defined(PAGESIZE)
#       endif
#   endif
#endif
#endif 
#if defined(HAS_TIMES) && defined(PERL_NEED_TIMESBASE)
#endif
#ifdef DEBUG_LEAKING_SCALARS_FORK_DUMP
#endif
#ifdef DEBUG_LEAKING_SCALARS_FORK_DUMP
#endif
#ifndef MULTIPLICITY
#endif
#if defined(DEBUGGING) || defined(PERL_TRACK_MEMPOOL)
#ifdef DEBUGGING
#endif
#ifdef PERL_TRACK_MEMPOOL
#endif
#endif
#ifdef DEBUG_LEAKING_SCALARS_FORK_DUMP
#endif
#ifndef PERL_MICRO
#if defined(USE_ENVIRON_ARRAY) && !defined(PERL_USE_SAFE_PUTENV)
#ifdef USE_ITHREADS
#endif
#endif
#endif 
#if defined(PERLIO_LAYERS)
#endif
#ifdef USE_ITHREADS
#endif
#ifdef PERL_SAWAMPERSAND
#endif
#ifdef PERL_USES_PL_PIDSTATUS
#endif
#ifdef USE_LOCALE_COLLATE
#endif
#ifdef USE_LOCALE_NUMERIC
#endif
#ifdef USE_ITHREADS
#endif
#ifdef PERL_IMPLICIT_CONTEXT
#endif
#ifdef USE_ITHREADS
#endif
#ifdef HAVE_INTERP_INTERN
#endif
#ifdef USE_ITHREADS
#endif
#ifdef DEBUG_LEAKING_SCALARS
#ifdef DEBUG_LEAKING_SCALARS_FORK_DUMP
#endif
#ifdef DEBUG_LEAKING_SCALARS_FORK_DUMP
#endif
#endif
#ifdef DEBUG_LEAKING_SCALARS_ABORT
#endif
#if defined(PERLIO_LAYERS)
#endif
#ifdef USE_REENTRANT_API
#endif
#ifdef PERL_TRACK_MEMPOOL
#endif
#if defined(WIN32) || defined(NETWARE)
#  if defined(PERL_IMPLICIT_SYS)
#    ifdef NETWARE
#    else
#    endif
#    ifdef NETWARE
#    else
#    endif
#  else
#  endif
#else
#endif
#if defined(USE_ITHREADS)
#ifndef WIN32 
#if defined(__hpux) && !(defined(__ux_version) && __ux_version <= 1020) && !defined(__GNUC__)
#pragma fini "perl_fini"
#elif defined(__sun) && !defined(__GNUC__)
#pragma fini (perl_fini)
#endif
#if defined(__GNUC__)
#endif
#endif 
#endif 
#if defined(OS2)
#else
#  ifdef USE_KERN_PROC_PATHNAME
#  elif defined(USE_NSGETEXECUTABLEPATH)
#  elif defined(HAS_PROCSELFEXE)
#  endif
#endif
#define SET_CURSTASH(newstash)                        	if (PL_curstash != newstash) {                 	    SvREFCNT_dec(PL_curstash);                  	    PL_curstash = (HV *)SvREFCNT_inc(newstash);  	}
#ifndef MULTIPLICITY
#endif
#if defined(USE_HASH_SEED) || defined(USE_HASH_SEED_EXPLICIT) || defined(USE_HASH_SEED_DEBUG)
#ifdef PERL_HASH_RANDOMIZE_KEYS
#endif
#endif 
#ifdef OS2
#endif 
#ifndef PERL_USE_SAFE_PUTENV
#ifndef OS2		
#endif
#endif 
#ifdef LOCAL_PATCH_COUNT
#else
#endif
#  ifdef DEBUGGING
#  endif
#  ifdef NO_MATHOMS
#  endif
#  ifdef NO_HASH_SEED
#  endif
#  ifdef PERL_DISABLE_PMC
#  endif
#  ifdef PERL_DONT_CREATE_GVSV
#  endif
#  ifdef PERL_EXTERNAL_GLOB
#  endif
#  ifdef PERL_HASH_FUNC_SIPHASH
#  endif
#  ifdef PERL_HASH_FUNC_SDBM
#  endif
#  ifdef PERL_HASH_FUNC_DJB2
#  endif
#  ifdef PERL_HASH_FUNC_SUPERFAST
#  endif
#  ifdef PERL_HASH_FUNC_MURMUR3
#  endif
#  ifdef PERL_HASH_FUNC_ONE_AT_A_TIME
#  endif
#  ifdef PERL_HASH_FUNC_ONE_AT_A_TIME_HARD
#  endif
#  ifdef PERL_HASH_FUNC_ONE_AT_A_TIME_OLD
#  endif
#  ifdef PERL_IS_MINIPERL
#  endif
#  ifdef PERL_MALLOC_WRAP
#  endif
#  ifdef PERL_MEM_LOG
#  endif
#  ifdef PERL_MEM_LOG_NOIMPL
#  endif
#  ifdef PERL_NEW_COPY_ON_WRITE
#  endif
#  ifdef PERL_PERTURB_KEYS_DETERMINISTIC
#  endif
#  ifdef PERL_PERTURB_KEYS_DISABLED
#  endif
#  ifdef PERL_PERTURB_KEYS_RANDOM
#  endif
#  ifdef PERL_PRESERVE_IVUV
#  endif
#  ifdef PERL_RELOCATABLE_INCPUSH
#  endif
#  ifdef PERL_USE_DEVEL
#  endif
#  ifdef PERL_USE_SAFE_PUTENV
#  endif
#  ifdef UNLINK_ALL_VERSIONS
#  endif
#  ifdef USE_ATTRIBUTES_FOR_PERLIO
#  endif
#  ifdef USE_FAST_STDIO
#  endif	       
#  ifdef USE_HASH_SEED_EXPLICIT
#  endif
#  ifdef USE_LOCALE
#  endif
#  ifdef USE_LOCALE_CTYPE
#  endif
#  ifdef USE_PERL_ATOF
#  endif	       
#  ifdef USE_SITECUSTOMIZE
#  endif	       
#ifdef __DATE__
#  ifdef __TIME__
#  else
#  endif
#else
#endif
#define INCPUSH_UNSHIFT			0x01
#define INCPUSH_ADD_OLD_VERS		0x02
#define INCPUSH_ADD_VERSIONED_SUB_DIRS	0x04
#define INCPUSH_ADD_ARCHONLY_SUB_DIRS	0x08
#define INCPUSH_NOT_BASEDIR		0x10
#define INCPUSH_CAN_RELOCATE		0x20
#define INCPUSH_ADD_SUB_DIRS	     (INCPUSH_ADD_VERSIONED_SUB_DIRS|INCPUSH_ADD_ARCHONLY_SUB_DIRS)
#ifdef USE_SITECUSTOMIZE
#endif
#ifndef PERL_STRICT_CR
#endif
#if SILENT_NO_TAINT_SUPPORT
#elif NO_TAINT_SUPPORT
#else
#endif
#if SILENT_NO_TAINT_SUPPORT
#elif NO_TAINT_SUPPORT
#else
#endif
#ifdef USE_SITECUSTOMIZE
#endif
#ifndef SECURE_INTERNAL_GETENV
#endif
#if SILENT_NO_TAINT_SUPPORT
#elif NO_TAINT_SUPPORT
#else
#endif
#if SILENT_NO_TAINT_SUPPORT
#elif NO_TAINT_SUPPORT
#else
#endif
#if defined(USE_SITECUSTOMIZE)
#  ifdef PERL_IS_MINIPERL
#  else
#  endif
#endif
#ifdef MSDOS
#endif
#ifndef PERL_MICRO
#  if defined(SIGCHLD) || defined(SIGCLD)
#  ifndef SIGCHLD
#    define SIGCHLD SIGCLD
#  endif
#  endif
#endif
#ifndef PERL_MICRO
#if defined(VMS) || defined(WIN32) || defined(DJGPP) || defined(__CYGWIN__) || defined(SYMBIAN)
#endif
#endif
#ifdef USE_SOCKS
#   ifdef HAS_SOCKS5_INIT
#   else
#   endif
#endif
#if defined(__SYMBIAN32__)
#endif
#  ifndef PERL_IS_MINIPERL
#endif
#ifdef PERL_MAD
#endif
#ifdef MYMALLOC
#endif
#ifndef MULTIPLICITY
#endif
#ifdef VMS
#endif
#ifdef MYMALLOC
#endif
#ifdef PERL_MAD
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_DEBUG_READONLY_OPS
#endif
#ifdef DEBUGGING
#  ifdef EBCDIC
#  endif
#endif
#ifdef DEBUGGING
#else 
#endif
#if defined(__CYGWIN__) 
#endif 
#if SILENT_NO_TAINT_SUPPORT
#elif NO_TAINT_SUPPORT
#else
#endif
#if defined(WIN32) || !defined(PERL_STRICT_CR)
#endif
#ifdef ALTERNATE_SHEBANG
#endif
#ifndef ALTERNATE_SHEBANG
#endif
#if !defined(DGUX)
#ifdef PERL_PATCHNUM
#  ifdef PERL_GIT_UNCOMMITTED_CHANGES
#  else
#  endif
 #endif
#else 
#endif 
#if defined(LOCAL_PATCH_COUNT)
#endif
#ifdef MSDOS
#endif
#ifdef DJGPP
#endif
#ifdef OS2
#endif
#ifdef OEMVS
#endif
#ifdef __VOS__
#endif
#ifdef POSIX_BC
#endif
#ifdef UNDER_CE
#endif
#ifdef __SYMBIAN32__
#endif
#ifdef BINARY_BUILD_NOTICE
#endif
#ifdef VMS
#include <lib$routines.h>
#endif
#ifdef UNEXEC
#else
#  ifdef VMS
#  elif defined(WIN32) || defined(__CYGWIN__)
#  else
#  endif
#endif
#ifdef MULTIPLICITY
#  define PERLVAR(prefix,var,type)
#  define PERLVARA(prefix,var,n,type)
#  if defined(PERL_IMPLICIT_CONTEXT)
#    define PERLVARI(prefix,var,type,init)	aTHX->prefix##var = init;
#    define PERLVARIC(prefix,var,type,init)	aTHX->prefix##var = init;
#  else
#    define PERLVARI(prefix,var,type,init)	PERL_GET_INTERP->var = init;
#    define PERLVARIC(prefix,var,type,init)	PERL_GET_INTERP->var = init;
#  endif
#  include "intrpvar.h"
#  undef PERLVAR
#  undef PERLVARA
#  undef PERLVARI
#  undef PERLVARIC
#else
#  define PERLVAR(prefix,var,type)
#  define PERLVARA(prefix,var,n,type)
#  define PERLVARI(prefix,var,type,init)	PL_##var = init;
#  define PERLVARIC(prefix,var,type,init)	PL_##var = init;
#  include "intrpvar.h"
#  undef PERLVAR
#  undef PERLVARA
#  undef PERLVARI
#  undef PERLVARIC
#endif
#ifdef PERL_DONT_CREATE_GVSV
#endif
#ifdef FAKE_BIT_BUCKET
#define FAKE_BIT_BUCKET_PREFIX "/tmp/perlnull-"
#define FAKE_BIT_BUCKET_SUFFIX "XXXXXXXX"
#define FAKE_BIT_BUCKET_TEMPLATE FAKE_BIT_BUCKET_PREFIX FAKE_BIT_BUCKET_SUFFIX
#ifdef HAS_MKSTEMP 
#else
#  ifdef HAS_MKTEMP
#  endif
#endif
#endif
#ifdef FAKE_BIT_BUCKET
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#ifdef SETUID_SCRIPTS_ARE_SECURE_NOW
#else
#endif 
#if !NO_TAINT_SUPPORT
#endif
#ifndef PERL_IMPLICIT_SYS
#ifdef VMS
#endif
#endif 
#ifdef SETUID_SCRIPTS_ARE_SECURE_NOW
#endif 
#ifndef STRESS_REALLOC
#define REASONABLE(size) (size)
#else
#define REASONABLE(size) (1) 
#endif
#ifdef DEBUGGING
#endif
#undef REASONABLE
#ifdef DEBUGGING
#endif
#ifndef PERL_MICRO
#ifdef USE_ENVIRON_ARRAY
#  ifdef USE_ITHREADS
#  endif
#if defined(MSDOS) && !defined(DJGPP)
#endif
#endif 
#endif 
#if defined(PERL_PREPENDTOPATH) || defined(PERL_APPENDTOPATH)
#define	_incpushfile(path)					 {								     PerlIO *fp;							     char *e = getenv("NO_"#path);				 								     if (!(e && *e) && (fp = PerlIO_open(path, "r")) != NULL) {	 	char buf[1024];						 	char *cp;						 	int res;						 	SV *sv = newSVpvn("", 0);				 								 	while ((res = PerlIO_read(fp, buf, sizeof(buf))) > 0)	 	    sv_catpvn(sv, buf, res);				 	PerlIO_close(fp);					 	if (res == 0 && SvCUR(sv) > 0) {			 	    STRLEN len;						 	    cp = SvPV_nolen(sv);				 	    while ((cp = strchr(cp, '\n')) != NULL)		 		*cp = ':';					 	    cp = SvPV(sv, len);					 	    incpush_use_sep(cp, len, INCPUSH_ADD_ARCHONLY_SUB_DIRS);	 	}							 	SvREFCNT_dec(sv);					     }								 }
#endif 
#ifndef VMS
#endif
#if defined(WIN32) && !defined(PERL_IS_MINIPERL)
#endif
#ifndef VMS
#if defined(PERL_USE_SAFE_PUTENV) && ! defined(HAS_UNSETENV)
#else
#endif
#else 
#endif 
#ifndef PERL_IS_MINIPERL
#ifdef PERL_PREPENDTOPATH
#endif 
#ifdef APPLLIB_EXP
#endif
#ifdef SITEARCH_EXP
#  if !defined(WIN32)
#  endif
#endif
#ifdef SITELIB_EXP
#  if defined(WIN32)
#  else
#  endif
#endif
#if defined(NO_NETWORK_LIBRARY_PERL_FILE) && (defined(PERL_VENDORARCH_EXP) || defined(PERL_VENDORLIB_EXP))
#endif 
#ifdef PERL_VENDORARCH_EXP
#  if !defined(WIN32)
#  endif
#endif
#ifdef PERL_VENDORLIB_EXP
#  if defined(WIN32)
#  else
#  endif
#endif
#if defined(NO_NETWORK_LIBRARY_PERL_FILE) && (defined(PERL_VENDORARCH_EXP) || defined(PERL_VENDORLIB_EXP))
#endif 
#ifdef UPDATESLIB
#endif 
#ifdef ARCHLIB_EXP
#endif
#ifndef PRIVLIB_EXP
#  define PRIVLIB_EXP "/usr/local/lib/perl5:/usr/local/lib/perl"
#endif
#if defined(WIN32)
#else
#  ifdef NETWARE
#  else
#  endif
#endif
#ifdef PERL_OTHERLIBDIRS
#endif
#ifndef VMS
#if defined(PERL_USE_SAFE_PUTENV) && ! defined(HAS_UNSETENV)
#else
#endif
#else 
#endif 
#ifdef APPLLIB_EXP
#endif
#if defined(SITELIB_STEM) && defined(PERL_INC_VERSION_LIST)
#endif
#if defined(PERL_VENDORLIB_STEM) && defined(PERL_INC_VERSION_LIST)
#endif
#ifdef PERL_OTHERLIBDIRS
#endif
#ifdef PERL_APPENDTOPATH
#endif 
#endif 
#if defined(DOSISH) || defined(__SYMBIAN32__)
#    define PERLLIB_SEP ';'
#else
#  if defined(VMS)
#    define PERLLIB_SEP '|'
#  else
#    define PERLLIB_SEP ':'
#  endif
#endif
#ifndef PERLLIB_MANGLE
#  define PERLLIB_MANGLE(s,n) (s)
#endif
#ifndef PERL_IS_MINIPERL
#endif
#ifdef VMS
#endif
#ifdef PERL_RELOCATABLE_INC
#endif
#ifndef PERL_IS_MINIPERL
#ifdef PERL_INC_VERSION_LIST
#endif
#endif
#ifndef OPEN_SOURCE
#ifdef __APPLE__
#endif
#endif
#ifndef PERL_IS_MINIPERL
#ifdef PERL_INC_VERSION_LIST
#endif
#ifdef PERL_INC_VERSION_LIST
#endif
#endif 
#ifdef PERL_IS_MINIPERL
#else
#endif
#ifndef PERL_IS_MINIPERL
#endif
#ifndef PERL_RELOCATABLE_INCPUSH
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef VMS
#else
#endif
