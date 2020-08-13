#line 2 "reentr.c"
#include "EXTERN.h"
#define PERL_IN_REENTR_C
#include "perl.h"
#include "reentr.h"
#ifdef USE_REENTRANT_API
#define REENTRANTSMALLSIZE	 256	
#define REENTRANTUSUALSIZE	4096	
#ifdef HAS_ASCTIME_R
#endif 
#ifdef HAS_CRYPT_R
#endif 
#ifdef HAS_CTIME_R
#endif 
#ifdef HAS_DRAND48_R
#endif 
#ifdef HAS_GETGRNAM_R
#   if defined(HAS_SYSCONF) && defined(_SC_GETGR_R_SIZE_MAX) && !defined(__GLIBC__)
#   else
#       if defined(__osf__) && defined(__alpha) && defined(SIABUFSIZ)
#       else
#           ifdef __sgi
#           else
#           endif
#       endif
#   endif 
#endif 
#ifdef HAS_GETHOSTBYNAME_R
#if   !(GETHOSTBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETLOGIN_R
#endif 
#ifdef HAS_GETNETBYNAME_R
#if   !(GETNETBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETPROTOBYNAME_R
#if   !(GETPROTOBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETPWNAM_R
#   if defined(HAS_SYSCONF) && defined(_SC_GETPW_R_SIZE_MAX) && !defined(__GLIBC__)
#   else
#       if defined(__osf__) && defined(__alpha) && defined(SIABUFSIZ)
#       else
#           ifdef __sgi
#           else
#           endif
#       endif
#   endif 
#endif 
#ifdef HAS_GETSERVBYNAME_R
#if   !(GETSERVBYNAME_R_PROTO == REENTRANT_PROTO_I_CCSD)
#endif
#endif 
#ifdef HAS_GETSPNAM_R
#   if defined(HAS_SYSCONF) && defined(_SC_GETPW_R_SIZE_MAX) && !defined(__GLIBC__)
#   else
#       if defined(__osf__) && defined(__alpha) && defined(SIABUFSIZ)
#       else
#           ifdef __sgi
#           else
#           endif
#       endif
#   endif 
#endif 
#ifdef HAS_RANDOM_R
#endif 
#ifdef HAS_READDIR_R
#endif 
#ifdef HAS_READDIR64_R
#endif 
#ifdef HAS_SETLOCALE_R
#endif 
#ifdef HAS_SRANDOM_R
#endif 
#ifdef HAS_STRERROR_R
#endif 
#ifdef HAS_TTYNAME_R
#endif 
#endif 
#ifdef USE_REENTRANT_API
#ifdef HAS_ASCTIME_R
#endif 
#ifdef HAS_CRYPT_R
#if CRYPT_R_PROTO != REENTRANT_PROTO_B_CCD
#endif
#endif 
#ifdef HAS_CTIME_R
#endif 
#ifdef HAS_DRAND48_R
#endif 
#ifdef HAS_GETGRNAM_R
#   ifdef USE_GRENT_FPTR
#   endif
#endif 
#ifdef HAS_GETHOSTBYNAME_R
#if   !(GETHOSTBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETLOGIN_R
#endif 
#ifdef HAS_GETNETBYNAME_R
#if   !(GETNETBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETPROTOBYNAME_R
#if   !(GETPROTOBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETPWNAM_R
#   ifdef USE_PWENT_FPTR
#   endif
#endif 
#ifdef HAS_GETSERVBYNAME_R
#if   !(GETSERVBYNAME_R_PROTO == REENTRANT_PROTO_I_CCSD)
#endif
#endif 
#ifdef HAS_GETSPNAM_R
#   ifdef USE_SPENT_FPTR
#   endif
#endif 
#ifdef HAS_RANDOM_R
#endif 
#ifdef HAS_READDIR_R
#endif 
#ifdef HAS_READDIR64_R
#endif 
#ifdef HAS_SETLOCALE_R
#endif 
#ifdef HAS_SRANDOM_R
#endif 
#ifdef HAS_STRERROR_R
#endif 
#ifdef HAS_TTYNAME_R
#endif 
#endif 
#ifdef USE_REENTRANT_API
#ifdef HAS_ASCTIME_R
#endif 
#ifdef HAS_CRYPT_R
#if CRYPT_R_PROTO != REENTRANT_PROTO_B_CCD
#endif
#endif 
#ifdef HAS_CTIME_R
#endif 
#ifdef HAS_DRAND48_R
#endif 
#ifdef HAS_GETGRNAM_R
#endif 
#ifdef HAS_GETHOSTBYNAME_R
#if   !(GETHOSTBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETLOGIN_R
#endif 
#ifdef HAS_GETNETBYNAME_R
#if   !(GETNETBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETPROTOBYNAME_R
#if   !(GETPROTOBYNAME_R_PROTO == REENTRANT_PROTO_I_CSD)
#endif
#endif 
#ifdef HAS_GETPWNAM_R
#endif 
#ifdef HAS_GETSERVBYNAME_R
#if   !(GETSERVBYNAME_R_PROTO == REENTRANT_PROTO_I_CCSD)
#endif
#endif 
#ifdef HAS_GETSPNAM_R
#endif 
#ifdef HAS_RANDOM_R
#endif 
#ifdef HAS_READDIR_R
#endif 
#ifdef HAS_READDIR64_R
#endif 
#ifdef HAS_SETLOCALE_R
#endif 
#ifdef HAS_SRANDOM_R
#endif 
#ifdef HAS_STRERROR_R
#endif 
#ifdef HAS_TTYNAME_R
#endif 
#endif 
#ifdef USE_REENTRANT_API
#endif
#ifdef USE_REENTRANT_API
#  if defined(USE_HOSTENT_BUFFER) || defined(USE_GRENT_BUFFER) || defined(USE_NETENT_BUFFER) || defined(USE_PWENT_BUFFER) || defined(USE_PROTOENT_BUFFER) || defined(USE_SERVENT_BUFFER)
#  endif
#  if defined(USE_SERVENT_BUFFER)
#  endif
#  if defined(USE_HOSTENT_BUFFER)
#  endif
#  if defined(USE_HOSTENT_BUFFER) || defined(USE_NETENT_BUFFER) || defined(USE_PROTOENT_BUFFER) || defined(USE_SERVENT_BUFFER)
#  endif
#ifdef USE_HOSTENT_BUFFER
#ifdef PERL_REENTRANT_MAXSIZE
#endif
#endif
#ifdef USE_GRENT_BUFFER
#ifdef PERL_REENTRANT_MAXSIZE
#endif
#if Gid_t_size < INTSIZE
#else
#endif
#endif
#ifdef USE_NETENT_BUFFER
#ifdef PERL_REENTRANT_MAXSIZE
#endif
#endif
#ifdef USE_PWENT_BUFFER
#ifdef PERL_REENTRANT_MAXSIZE
#endif
#if Uid_t_size < INTSIZE
#else
#endif
#endif
#ifdef USE_PROTOENT_BUFFER
#ifdef PERL_REENTRANT_MAXSIZE
#endif
#endif
#ifdef USE_SERVENT_BUFFER
#ifdef PERL_REENTRANT_MAXSIZE
#endif
#endif
#else
#endif
