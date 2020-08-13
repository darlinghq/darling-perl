#line 2 "perlio.c"
#ifdef PERL_IMPLICIT_SYS
#define dSYS dTHX
#else
#define dSYS dNOOP
#endif
#define VOIDUSED 1
#ifdef PERL_MICRO
#   include "uconfig.h"
#else
#   ifndef USE_CROSS_COMPILE
#       include "config.h"
#   else
#       include "xconfig.h"
#   endif
#endif
#define PERLIO_NOT_STDIO 0
#if !defined(PERLIO_IS_STDIO) && !defined(USE_SFIO)
#endif
#include "EXTERN.h"
#define PERL_IN_PERLIO_C
#include "perl.h"
#ifdef PERL_IMPLICIT_CONTEXT
#undef dSYS
#define dSYS dTHX
#endif
#include "XSUB.h"
#ifdef __Lynx__
#endif
#ifdef VMS
#include <rms.h>
#endif
#define PerlIO_lockcnt(f) (((PerlIOl*)(f))->head->flags)
#define Perl_PerlIO_or_Base(f, callback, base, failure, args) 	 	if (PerlIOValid(f)) {					 		const PerlIO_funcs * const tab = PerlIOBase(f)->tab; 		if (tab && tab->callback)			 			return (*tab->callback) args;		 		else						 			return PerlIOBase_ ## base args;	 	}							 	else							 		SETERRNO(EBADF, SS_IVCHAN);			 	return failure
#define Perl_PerlIO_or_fail(f, callback, failure, args) 	 	if (PerlIOValid(f)) {					 		const PerlIO_funcs * const tab = PerlIOBase(f)->tab; 		if (tab && tab->callback)			 			return (*tab->callback) args;		 		SETERRNO(EINVAL, LIB_INVARG);			 	}							 	else							 		SETERRNO(EBADF, SS_IVCHAN);			 	return failure
#define Perl_PerlIO_or_Base_void(f, callback, base, args) 	 	if (PerlIOValid(f)) {					 		const PerlIO_funcs * const tab = PerlIOBase(f)->tab; 		if (tab && tab->callback)			 			(*tab->callback) args;			 		else						 			PerlIOBase_ ## base args;		 	}							 	else							 		SETERRNO(EBADF, SS_IVCHAN)
#define Perl_PerlIO_or_fail_void(f, callback, args) 		 	if (PerlIOValid(f)) {					 		const PerlIO_funcs * const tab = PerlIOBase(f)->tab; 		if (tab && tab->callback)			 			(*tab->callback) args;			 		else						 			SETERRNO(EINVAL, LIB_INVARG);		 	}							 	else							 		SETERRNO(EBADF, SS_IVCHAN)
#if defined(__osf__) && _XOPEN_SOURCE < 500
#endif
#ifndef USE_SFIO
#ifdef DOSISH
#ifdef NETWARE
#else
#endif
#else
#  if defined(USEMYBINMODE)
#    if defined(__CYGWIN__)
#    endif
#  else
#  endif
#endif
#endif 
#ifndef O_ACCMODE
#define O_ACCMODE 3             
#endif
#ifdef O_APPEND
#endif
#ifndef PERLIO_LAYERS
#ifdef USE_SFIO
#else
#endif
#if defined(PERL_MICRO) || defined(__SYMBIAN32__)
#else
#ifdef PERL_IMPLICIT_SYS
#else
#ifdef WIN32
#else
#ifdef DJGPP
#else
#endif
#endif
#endif
#endif
#endif
#ifdef PERLIO_IS_STDIO
#undef PerlIO_tmpfile
#else                           
#ifdef USE_SFIO
#undef HAS_FSETPOS
#undef HAS_FGETPOS
#undef PerlIO_tmpfile
#else                           
#include "perliol.h"
#ifdef USE_ITHREADS
#else
#endif
#ifdef DEBUGGING
#  define VERIFY_HEAD(f) PerlIO_verify_head(aTHX_ f)
#else
#  define VERIFY_HEAD(f)
#endif
#define PERLIO_TABLE_SIZE 64
#undef PerlIO_fdupopen
#ifdef sv_dup
#else
#endif
#ifdef USE_ITHREADS
#else
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ATTRIBUTES_FOR_PERLIO
#endif                          
#ifdef PERLIO_USING_CRLF
#else
#endif
#if defined(WIN32)
#if 0
#endif
#endif
#ifdef USE_ATTRIBUTES_FOR_PERLIO
#endif
#define PerlIO_default_top() PerlIO_default_layer(aTHX_ -1)
#define PerlIO_default_btm() PerlIO_default_layer(aTHX_ 0)
#ifdef PERLIO_USING_CRLF
#endif
#ifdef PERLIO_USING_CRLF
#endif
#if 0
#endif
#ifdef sv_dup
#else
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#else
#endif
#if 0
#ifdef DEBUGGING
#define PERLIO_TEARDOWN_MESSAGE_BUF_SIZE 64
#define PERLIO_TEARDOWN_MESSAGE_FD 2
#endif
#endif
#ifdef PERLIO_USING_CRLF
#endif
#if defined(WIN32)
#endif
#ifdef  ESPIPE
#else
#endif
#ifdef VMS
#else
#endif
#ifdef PERLIO_STD_SPECIAL
#endif
#ifdef PERLIO_STD_SPECIAL
#endif
#if defined(VMS) && !defined(STDIO_BUFFER_WRITABLE)
#define STDIO_BUFFER_WRITABLE
#endif
#if defined(PERLIO_USING_CRLF) || defined(__CYGWIN__)
#endif
#ifdef __CYGWIN__
#endif
#  if defined(__UCLIBC__)
#  elif defined(__GLIBC__)
#  elif defined(__sun__)
#  elif defined(__hpux)
#  elif defined(_AIX) || defined(__osf__) || defined(__irix__)
#  elif defined(__FreeBSD__)
#  elif defined(__OpenBSD__)
#  elif defined(__EMX__)
#  elif defined(__CYGWIN__)
#  elif defined(WIN32)
#    if defined(UNDER_CE)
#    else
#    endif
#  else
#if 0
#    error "Don't know how to set FILE.fileno on your platform"
#endif
#  endif
#ifdef USE_ITHREADS
#endif
#ifdef SOCKS5_VERSION_NAME
#endif
#ifdef USE_ITHREADS
#endif
#ifdef USE_ITHREADS
#endif
#ifdef SOCKS5_VERSION_NAME
#endif
#ifdef USE_ITHREADS
#endif
#ifdef STDIO_BUFFER_WRITABLE
#endif
#if 0
#endif
#ifdef HAS_SETLINEBUF
#else
#endif
#ifdef FILE_base
#endif
#ifdef USE_STDIO_PTR
#ifdef STDIO_PTR_LVALUE
#ifdef STDIO_PTR_LVAL_SETS_CNT
#endif
#if (!defined(STDIO_PTR_LVAL_NOCHANGE_CNT))
#endif
#else                           
#endif                          
#ifdef STDIO_CNT_LVALUE
#else                           
#if (defined(STDIO_PTR_LVALUE) && defined(STDIO_PTR_LVAL_SETS_CNT))
#else                           
#endif                          
#endif                          
#endif
#if (defined(STDIO_PTR_LVALUE) && (defined(STDIO_CNT_LVALUE) || defined(STDIO_PTR_LVAL_SETS_CNT)))
#ifdef STDIO_BUFFER_WRITABLE
#endif
#endif
#if defined(VMS)
#else
#endif
#ifdef FILE_base
#else
#endif
#ifdef USE_STDIO_PTR
#   if defined(HAS_FAST_STDIO) && defined(USE_FAST_STDIO)
#   else
#   endif 
#else
#endif 
#ifdef PERLIO_USING_CRLF
#  ifdef PERLIO_IS_BINMODE_FD
#  endif
#endif
#ifdef VMS
#endif
#if 1
#else	
#endif
#ifndef DEBUGGING
#endif
#if 0
#endif
#if 0
#endif
#ifndef PERLIO_USING_CRLF
#endif
#ifdef VMS
#else
#endif
#undef PerlIO_fdopen
#undef PerlIO_open
#undef Perlio_reopen
#undef PerlIO_getc
#undef PerlIO_ungetc
#undef PerlIO_putc
#undef PerlIO_puts
#undef PerlIO_rewind
#undef PerlIO_vprintf
#ifdef NEED_VA_COPY
#else
#endif
#undef PerlIO_printf
#undef PerlIO_stdoutf
#undef PerlIO_tmpfile
#ifndef WIN32
#endif
#ifdef WIN32
#else 
#    if defined(HAS_MKSTEMP) && ! defined(VMS) && ! defined(OS2)
#    else	
#    endif 
#endif 
#undef HAS_FSETPOS
#undef HAS_FGETPOS
#endif                          
#endif                          
#ifndef HAS_FSETPOS
#undef PerlIO_setpos
#else
#undef PerlIO_setpos
#if defined(USE_64_BIT_STDIO) && defined(USE_FSETPOS64)
#else
#endif
#endif
#ifndef HAS_FGETPOS
#undef PerlIO_getpos
#else
#undef PerlIO_getpos
#if defined(USE_64_BIT_STDIO) && defined(USE_FSETPOS64)
#else
#endif
#endif
#if (defined(PERLIO_IS_STDIO) || !defined(USE_SFIO)) && !defined(HAS_VPRINTF)
#endif
#ifndef PerlIO_vsprintf
#ifndef PERL_MY_VSNPRINTF_GUARDED
#endif
#endif
#ifndef PerlIO_sprintf
#endif
