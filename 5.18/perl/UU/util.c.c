#line 2 "util.c"
#include "EXTERN.h"
#define PERL_IN_UTIL_C
#include "perl.h"
#include "reentr.h"
#ifdef USE_PERLIO
#include "perliol.h" 
#endif
#ifndef PERL_MICRO
#include <signal.h>
#ifndef SIG_ERR
# define SIG_ERR ((Sighandler_t) -1)
#endif
#endif
#ifdef __Lynx__
#endif
#ifdef HAS_SELECT
# ifdef I_SYS_SELECT
#  include <sys/select.h>
# endif
#endif
#define FLUSH
#if defined(HAS_FCNTL) && defined(F_SETFD) && !defined(FD_CLOEXEC)
#  define FD_CLOEXEC 1			
#endif
#if defined (DEBUGGING) || defined(PERL_IMPLICIT_SYS) || defined (PERL_TRACK_MEMPOOL)
#  define ALWAYS_NEED_THX
#endif
#ifdef ALWAYS_NEED_THX
#endif
#ifdef HAS_64K_LIMIT
#endif 
#ifdef PERL_TRACK_MEMPOOL
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_TRACK_MEMPOOL
#endif
#ifdef PERL_POISON
#endif
#ifdef PERL_TRACK_MEMPOOL
#  ifdef PERL_POISON
#  endif
#endif
#ifndef ALWAYS_NEED_THX
#endif
#ifdef ALWAYS_NEED_THX
#endif
#if !defined(STANDARD_C) && !defined(HAS_REALLOC_PROTOTYPE) && !defined(PERL_MICRO)
#endif 
#ifdef HAS_64K_LIMIT
#endif 
#ifdef PERL_TRACK_MEMPOOL
#  ifdef PERL_POISON
#  endif
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_TRACK_MEMPOOL
#  ifdef PERL_POISON
#  endif
#endif
#ifndef ALWAYS_NEED_THX
#endif
#ifdef ALWAYS_NEED_THX
#else
#endif
#ifdef PERL_TRACK_MEMPOOL
#  ifdef PERL_POISON
#  endif
#endif
#ifdef ALWAYS_NEED_THX
#endif
#if defined(PERL_TRACK_MEMPOOL) || defined(HAS_64K_LIMIT) || defined(DEBUGGING)
#endif
#if defined(PERL_TRACK_MEMPOOL) || defined(HAS_64K_LIMIT) || defined(DEBUGGING)
#endif
#ifdef PERL_TRACK_MEMPOOL
#endif
#ifdef HAS_64K_LIMIT
#endif 
#ifdef DEBUGGING
#endif
#ifdef PERL_TRACK_MEMPOOL
#else
#endif
#ifdef PERL_TRACK_MEMPOOL
#  ifdef PERL_POISON
#  endif
#endif
#ifndef ALWAYS_NEED_THX
#endif
#ifndef MYMALLOC
#endif
#if defined(PERL_IMPLICIT_CONTEXT)
#endif 
#if defined(PERL_IMPLICIT_CONTEXT)
#endif 
#ifdef USE_SFIO
#endif
#ifdef USE_SFIO
#endif
#if defined(PERL_IMPLICIT_CONTEXT)
#endif 
#if defined(PERL_IMPLICIT_CONTEXT)
#endif 
#if defined(PERL_IMPLICIT_CONTEXT)
#endif 
#if defined(PERL_IMPLICIT_CONTEXT)
#endif 
#define my_setenv_format(s, nam, nlen, val, vlen)     Copy(nam, s, nlen, char);     *(s+nlen) = '=';     Copy(val, s+(nlen+1), vlen, char);     *(s+(nlen+1+vlen)) = '\0'
#ifdef USE_ENVIRON_ARRAY
#if !defined(WIN32) && !defined(NETWARE)
#ifdef USE_ITHREADS
#endif
#ifndef PERL_USE_SAFE_PUTENV
# endif
#   if defined(__CYGWIN__)|| defined(__SYMBIAN32__) || defined(__riscos__)
#       if defined(HAS_UNSETENV)
#       else 
#       endif 
#   else
#       if defined(HAS_UNSETENV)
#       else 
#       endif 
#   endif 
#ifndef PERL_USE_SAFE_PUTENV
#endif
#else 
#endif 
#endif 
#ifdef UNLINK_ALL_VERSIONS
#endif
#if (!defined(HAS_MEMCPY) && !defined(HAS_BCOPY)) || (!defined(HAS_MEMMOVE) && !defined(HAS_SAFE_MEMCPY) && !defined(HAS_SAFE_BCOPY))
#endif
#ifndef HAS_MEMSET
#endif
#if !defined(HAS_BZERO) && !defined(HAS_MEMSET)
#endif
#if !defined(HAS_MEMCMP) || !defined(HAS_SANE_MEMCMP)
#endif 
#ifndef HAS_VPRINTF
#ifdef USE_CHAR_VSPRINTF
#else
#endif
#if defined(STDIO_PTR_LVALUE) && defined(STDIO_CNT_LVALUE)
#else
#endif
#ifndef _IOSTRG
#define _IOSTRG 0
#endif
#if defined(STDIO_PTR_LVALUE)
#else
#  ifdef fputc
#    undef fputc  
#  endif
#endif
#ifdef USE_CHAR_VSPRINTF
#else
#endif
#endif 
#ifdef MYSWAP
#if BYTEORDER != 0x4321
#if (BYTEORDER & 1) == 0
#else
#endif
#if BYTEORDER == 0x1234 || BYTEORDER == 0x12345678
#if BYTEORDER == 0x12345678
#endif 
#else
#if ((BYTEORDER - 0x1111) & 0x444) || !(BYTEORDER & 0xf)
#else
#endif
#endif
#if BYTEORDER == 0x1234
#else
#if ((BYTEORDER - 0x1111) & 0x444) || !(BYTEORDER & 0xf)
#else
#endif
#endif
#endif 
#endif 
#define HTOLE(name,type)					 	type							 	name (type n)					         	{							 	    union {						 		type value;					 		char c[sizeof(type)];				 	    } u;						 	    U32 i;					         	    U32 s = 0;					         	    for (i = 0; i < sizeof(u.c); i++, s += 8) {		 		u.c[i] = (n >> s) & 0xFF;			 	    }							 	    return u.value;					 	}
#define LETOH(name,type)					 	type							 	name (type n)					         	{							 	    union {						 		type value;					 		char c[sizeof(type)];				 	    } u;						 	    U32 i;					         	    U32 s = 0;					         	    u.value = n;					 	    n = 0;						 	    for (i = 0; i < sizeof(u.c); i++, s += 8) {		 		n |= ((type)(u.c[i] & 0xFF)) << s;		 	    }							 	    return n;						 	}
#define HTOBE(name,type)					 	type							 	name (type n)					         	{							 	    union {						 		type value;					 		char c[sizeof(type)];				 	    } u;						 	    U32 i;					         	    U32 s = 8*(sizeof(u.c)-1);			         	    for (i = 0; i < sizeof(u.c); i++, s -= 8) {		 		u.c[i] = (n >> s) & 0xFF;			 	    }							 	    return u.value;					 	}
#define BETOH(name,type)					 	type							 	name (type n)					         	{							 	    union {						 		type value;					 		char c[sizeof(type)];				 	    } u;						 	    U32 i;					         	    U32 s = 8*(sizeof(u.c)-1);			         	    u.value = n;					 	    n = 0;						 	    for (i = 0; i < sizeof(u.c); i++, s -= 8) {		 		n |= ((type)(u.c[i] & 0xFF)) << s;		 	    }							 	    return n;						 	}
#define NOT_AVAIL(name,type)                                             type                                                             name (type n)                                                    {                                                                    Perl_croak_nocontext(#name "() not available");                  return n;                                   }
#if defined(HAS_HTOVS) && !defined(htovs)
#endif
#if defined(HAS_HTOVL) && !defined(htovl)
#endif
#if defined(HAS_VTOHS) && !defined(vtohs)
#endif
#if defined(HAS_VTOHL) && !defined(vtohl)
#endif
#ifdef PERL_NEED_MY_HTOLE16
# if U16SIZE == 2
# else
# endif
#endif
#ifdef PERL_NEED_MY_LETOH16
# if U16SIZE == 2
# else
# endif
#endif
#ifdef PERL_NEED_MY_HTOBE16
# if U16SIZE == 2
# else
# endif
#endif
#ifdef PERL_NEED_MY_BETOH16
# if U16SIZE == 2
# else
# endif
#endif
#ifdef PERL_NEED_MY_HTOLE32
# if U32SIZE == 4
# else
# endif
#endif
#ifdef PERL_NEED_MY_LETOH32
# if U32SIZE == 4
# else
# endif
#endif
#ifdef PERL_NEED_MY_HTOBE32
# if U32SIZE == 4
# else
# endif
#endif
#ifdef PERL_NEED_MY_BETOH32
# if U32SIZE == 4
# else
# endif
#endif
#ifdef PERL_NEED_MY_HTOLE64
# if U64SIZE == 8
# else
# endif
#endif
#ifdef PERL_NEED_MY_LETOH64
# if U64SIZE == 8
# else
# endif
#endif
#ifdef PERL_NEED_MY_HTOBE64
# if U64SIZE == 8
# else
# endif
#endif
#ifdef PERL_NEED_MY_BETOH64
# if U64SIZE == 8
# else
# endif
#endif
#ifdef PERL_NEED_MY_HTOLES
#endif
#ifdef PERL_NEED_MY_LETOHS
#endif
#ifdef PERL_NEED_MY_HTOBES
#endif
#ifdef PERL_NEED_MY_BETOHS
#endif
#ifdef PERL_NEED_MY_HTOLEI
#endif
#ifdef PERL_NEED_MY_LETOHI
#endif
#ifdef PERL_NEED_MY_HTOBEI
#endif
#ifdef PERL_NEED_MY_BETOHI
#endif
#ifdef PERL_NEED_MY_HTOLEL
#endif
#ifdef PERL_NEED_MY_LETOHL
#endif
#ifdef PERL_NEED_MY_HTOBEL
#endif
#ifdef PERL_NEED_MY_BETOHL
#endif
#if (!defined(DOSISH) || defined(HAS_FORK) || defined(AMIGAOS)) && !defined(OS2) && !defined(VMS) && !defined(NETWARE) && !defined(__LIBCATAMOUNT__)
#undef THIS
#undef THAT
#define THIS that
#define THAT This
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#if !defined(HAS_FCNTL) || !defined(F_SETFD)
#  ifndef NOFILE
#  define NOFILE 20
#  endif
#endif
#undef THIS
#undef THAT
#else
#  ifdef OS2	
#  else
#  endif
#endif
#if (!defined(DOSISH) || defined(HAS_FORK) || defined(AMIGAOS)) && !defined(VMS) && !defined(__LIBCATAMOUNT__)
#ifdef OS2
#endif
#undef THIS
#undef THAT
#define THIS that
#define THAT This
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#ifndef OS2
#if !defined(HAS_FCNTL) || !defined(F_SETFD)
#ifndef NOFILE
#define NOFILE 20
#endif
#endif
#endif	
#ifdef PERLIO_USING_CRLF
#endif 
#ifdef PERL_USES_PL_PIDSTATUS
#endif
#undef THIS
#undef THAT
#else
#if defined(DJGPP)
#else
#if defined(__LIBCATAMOUNT__)
#endif
#endif
#endif 
#if defined(USE_ITHREADS)
#  ifdef USE_PERLIO
#  endif
#  ifdef MYMALLOC
#  endif
#endif
#if defined(USE_ITHREADS)
#  ifdef USE_PERLIO
#  endif
#  ifdef MYMALLOC
#  endif
#endif
#if defined(HAS_FORK)
#if defined(USE_ITHREADS) && !defined(HAS_PTHREAD_ATFORK)
#else
#endif
#else
#endif 
#ifdef DUMP_FDS
#endif	
#ifndef HAS_DUP2
#if defined(HAS_FCNTL) && defined(F_DUPFD)
#else
#define DUP2_MAX_FDS 256
#endif
#endif
#ifndef PERL_MICRO
#ifdef HAS_SIGACTION
#ifdef USE_ITHREADS
#endif
#ifdef SA_RESTART
#endif
#if defined(SA_NOCLDWAIT) && !defined(BSDish) 
#endif
#ifdef USE_ITHREADS
#endif
#ifdef SA_RESTART
#endif
#if defined(SA_NOCLDWAIT) && !defined(BSDish) 
#endif
#ifdef USE_ITHREADS
#endif
#else 
#if defined(USE_ITHREADS) && !defined(WIN32)
#endif
#if defined(USE_ITHREADS) && !defined(WIN32)
#endif
#if defined(USE_ITHREADS) && !defined(WIN32)
#endif
#if defined(USE_ITHREADS) && !defined(WIN32)
#endif
#endif 
#endif 
#if (!defined(DOSISH) || defined(HAS_FORK) || defined(AMIGAOS)) && !defined(VMS) && !defined(__LIBCATAMOUNT__)
#ifdef USE_PERLIO
#else
#endif
#ifdef OS2
#endif
#ifndef PERL_MICRO
#endif
#ifndef PERL_MICRO
#endif
#else
#if defined(__LIBCATAMOUNT__)
#endif
#endif 
#if  (!defined(DOSISH) || defined(OS2) || defined(WIN32) || defined(NETWARE)) && !defined(__LIBCATAMOUNT__)
#ifdef PERL_USES_PL_PIDSTATUS
#endif
#ifdef HAS_WAITPID
#  ifdef HAS_WAITPID_RUNTIME
#  endif
#endif
#if !defined(HAS_WAITPID) && defined(HAS_WAIT4)
#endif
#ifdef PERL_USES_PL_PIDSTATUS
#if defined(HAS_WAITPID) && defined(HAS_WAITPID_RUNTIME)
#endif
#endif
#if defined(HAS_WAITPID) || defined(HAS_WAIT4)
#endif
#endif 
#ifdef PERL_USES_PL_PIDSTATUS
#endif
#if defined(OS2)
#ifdef HAS_FORK
#else
#endif
#endif
#if defined(DJGPP)
#endif
#define PERL_REPEATCPY_LINEAR 4
#ifndef HAS_RENAME
#endif 
#if defined(DOSISH) && !defined(OS2)
#  define SEARCH_EXTS ".bat", ".cmd", NULL
#  define MAX_EXT_LEN 4
#endif
#ifdef OS2
#  define SEARCH_EXTS ".cmd", ".btm", ".bat", ".pl", NULL
#  define MAX_EXT_LEN 4
#endif
#ifdef VMS
#  define SEARCH_EXTS ".pl", ".com", NULL
#  define MAX_EXT_LEN 4
#endif
#ifdef SEARCH_EXTS
#else
#  define MAX_EXT_LEN 0
#endif
#ifdef VMS
#  ifdef ALWAYS_DEFTYPES
#  else
#  endif
#else  
#ifdef DOSISH
#ifdef SEARCH_EXTS
#endif
#ifdef SEARCH_EXTS
#endif
#ifdef SEARCH_EXTS
#endif
#endif
#ifdef DOSISH
#endif
#  ifdef DOSISH
#  else
#  endif
#  ifdef DOSISH
#  endif
#endif  
#ifdef SEARCH_EXTS
#endif
#ifdef SEARCH_EXTS
#endif
#if !defined(DOSISH)
#endif
#ifndef DOSISH
#endif
#ifndef PERL_GET_CONTEXT_DEFINED
#if defined(USE_ITHREADS)
#  ifdef OLD_PTHREADS_API
#  else
#    ifdef I_MACH_CTHREADS
#    else
#    endif
#  endif
#else
#endif
#if defined(USE_ITHREADS)
#  ifdef I_MACH_CTHREADS
#  else
#  endif
#else
#endif
#endif 
#if defined(PERL_GLOBAL_STRUCT) && !defined(PERL_GLOBAL_STRUCT_PRIVATE)
#endif
#ifndef HAS_GETENV_LEN
#endif
#if defined(USE_PERLIO) || defined(FFLUSH_NULL) || defined(USE_SFIO)
#else
# if defined(HAS__FWALK)
# else
#  if defined(FFLUSH_ALL) && defined(HAS_STDIO_STREAM_ARRAY)
#   ifdef PERL_FFLUSH_ALL_FOPEN_MAX
#   else
#    if defined(HAS_SYSCONF) && defined(_SC_OPEN_MAX)
#     else
#      ifdef FOPEN_MAX
#      else
#       ifdef OPEN_MAX
#       else
#        ifdef _NFILE
#        endif
#       endif
#      endif
#     endif
#    endif
#  endif
# endif
#endif
#ifdef HAS_GNULIBC
# ifndef STRUCT_TM_HASZONE
#    define STRUCT_TM_HASZONE
# endif
#endif
#ifdef STRUCT_TM_HASZONE 
# ifndef HAS_TM_TM_ZONE
#    define HAS_TM_TM_ZONE
# endif
#endif
#ifdef HAS_TM_TM_ZONE
#else
#endif
#define	DAYS_PER_YEAR	365
#define	DAYS_PER_QYEAR	(4*DAYS_PER_YEAR+1)
#define	DAYS_PER_CENT	(25*DAYS_PER_QYEAR-1)
#define	DAYS_PER_QCENT	(4*DAYS_PER_CENT+1)
#define	SECS_PER_HOUR	(60*60)
#define	SECS_PER_DAY	(24*SECS_PER_HOUR)
#define	MONTH_TO_DAYS	153/5
#define	DAYS_TO_MONTH	5/153
#define	YEAR_ADJUST	(4*MONTH_TO_DAYS+1)
#define	WEEKDAY_BIAS	6	
#ifdef HAS_STRFTIME
#if defined(HAS_MKTIME) && (defined(HAS_TM_TM_GMTOFF) || defined(HAS_TM_TM_ZONE))
#ifdef HAS_TM_TM_GMTOFF
#endif
#ifdef HAS_TM_TM_ZONE
#endif
#endif
#else
#endif
#define SV_CWD_RETURN_UNDEF  sv_setsv(sv, &PL_sv_undef);  return FALSE
#define SV_CWD_ISDOT(dp)      (dp->d_name[0] == '.' && (dp->d_name[1] == '\0' ||  	(dp->d_name[1] == '.' && dp->d_name[2] == '\0')))
#ifndef PERL_MICRO
#ifndef INCOMPLETE_TAINTS
#endif
#ifdef HAS_GETCWD
#else
#ifdef DIRNAMLEN
#else
#endif
#ifdef VOID_CLOSEDIR
#else
#endif
#endif
#else
#endif
#define VERSION_MAX 0x7FFFFFFF
#ifndef NODEFAULT_SHAREKEYS
#endif
#ifndef NODEFAULT_SHAREKEYS
#endif
#ifdef SvVOK
#endif
#ifdef SvVOK
#endif
#ifdef SvVOK
#endif
#ifdef USE_LOCALE_NUMERIC
#endif
#ifdef USE_LOCALE_NUMERIC
#endif
#ifdef SvVOK
#endif
#ifndef SvVOK
#  if PERL_VERSION > 5
#  endif
#endif
#if !defined(HAS_SOCKETPAIR) && defined(HAS_SOCKET) && defined(AF_INET) && defined(PF_INET) && defined(SOCK_DGRAM) && defined(HAS_SELECT)
#   define EMULATE_SOCKETPAIR_UDP
#endif
#ifdef EMULATE_SOCKETPAIR_UDP
#ifdef MSG_DONTWAIT
#else
#endif
#endif 
#if !defined(HAS_SOCKETPAIR) && defined(HAS_SOCKET) && defined(AF_INET) && defined(PF_INET)
#ifdef AF_UNIX
#endif
#ifdef EMULATE_SOCKETPAIR_UDP
#endif
#ifdef ECONNABORTED
#else
#  ifdef ECONNREFUSED
#  else
#  endif
#endif
#else
#ifdef HAS_SOCKETPAIR
#else
#endif
#endif
#ifdef VMS
#  include <starlet.h>
#endif
#if RANDBITS > 16
#  define SEED_C1	1000003
#define   SEED_C4	73819
#else
#  define SEED_C1	25747
#define   SEED_C4	20639
#endif
#define   SEED_C2	3
#define   SEED_C3	269
#define   SEED_C5	26107
#ifndef PERL_NO_DEV_RANDOM
#endif
#ifdef VMS
#else
#  ifdef HAS_GETTIMEOFDAY
#  else
#  endif
#endif
#ifndef PERL_NO_DEV_RANDOM
#ifndef PERL_RANDOM_DEVICE
#  define PERL_RANDOM_DEVICE "/dev/urandom"
#endif
#endif
#ifdef VMS
#else
#  ifdef HAS_GETTIMEOFDAY
#  else
#  endif
#endif
#ifndef PLAN9           
#endif
#ifndef USE_HASH_SEED_EXPLICIT
#ifdef USE_PERL_PERTURB_KEYS
#endif
#endif
#ifdef USE_PERL_PERTURB_KEYS
#endif
#ifdef PERL_GLOBAL_STRUCT
#define PERL_GLOBAL_STRUCT_INIT
#include "opcode.h" 
# ifdef PERL_GLOBAL_STRUCT
#  ifdef PERL_GLOBAL_STRUCT_PRIVATE
#  else
#  endif 
#  undef PERLVAR
#  undef PERLVARA
#  undef PERLVARI
#  undef PERLVARIC
#  define PERLVAR(prefix,var,type) 
#  define PERLVARA(prefix,var,n,type) 
#  define PERLVARI(prefix,var,type,init) plvarsp->prefix##var = init;
#  define PERLVARIC(prefix,var,type,init) plvarsp->prefix##var = init;
#  include "perlvars.h"
#  undef PERLVAR
#  undef PERLVARA
#  undef PERLVARI
#  undef PERLVARIC
#  ifdef PERL_GLOBAL_STRUCT
#  endif
#  ifdef PERL_SET_VARS
#  endif
# undef PERL_GLOBAL_STRUCT_INIT
# endif
#endif 
#ifdef PERL_GLOBAL_STRUCT
# ifdef PERL_GLOBAL_STRUCT
#  ifdef PERL_UNSET_VARS
#  endif
#  ifdef PERL_GLOBAL_STRUCT_PRIVATE
#  endif
# endif
#endif 
#ifdef PERL_MEM_LOG
#define PERL_MEM_LOG_SPRINTF_BUF_SIZE 128
#ifndef PERL_MEM_LOG_FD
#  define PERL_MEM_LOG_FD 2 
#endif
#ifndef PERL_MEM_LOG_NOIMPL
# ifdef DEBUG_LEAKING_SCALARS
#   define SV_LOG_SERIAL_FMT	    " [%lu]"
#   define _SV_LOG_SERIAL_ARG(sv)   , (unsigned long) (sv)->sv_debug_serial
# else
#   define SV_LOG_SERIAL_FMT
#   define _SV_LOG_SERIAL_ARG(sv)
# endif
#   ifdef HAS_GETTIMEOFDAY
#     define MEM_LOG_TIME_FMT	"%10d.%06d: "
#     define MEM_LOG_TIME_ARG	(int)tv.tv_sec, (int)tv.tv_usec
#   else
#     define MEM_LOG_TIME_FMT	"%10d: "
#     define MEM_LOG_TIME_ARG	(int)when
#   endif
#endif 
#ifndef PERL_MEM_LOG_NOIMPL
# define      mem_log_common_if(alty, num, tysz, tynm, sv, oal, nal, flnm, ln, fnnm)      mem_log_common   (alty, num, tysz, tynm, sv, oal, nal, flnm, ln, fnnm)
#else
# define      mem_log_common_if(alty, num, tysz, tynm, u, oal, nal, flnm, ln, fnnm)      
#endif
#endif 
#ifndef SPRINTF_RETURNS_STRLEN
#endif
#ifdef HAS_VSNPRINTF
#else
#endif
#ifdef HAS_VSNPRINTF
#endif
#ifdef NEED_VA_COPY
# ifdef HAS_VSNPRINTF
# else
# endif
#else
# ifdef HAS_VSNPRINTF
# else
# endif
#endif 
#ifdef HAS_VSNPRINTF
#endif
#if ! defined(PERL_MICRO)
#  if defined(PERL_IMPLICIT_SYS) || defined(WIN32)
#  else 
#    if defined(USE_ENVIRON_ARRAY)
#      if defined(USE_ITHREADS)
#      endif 
#      if ! defined(PERL_USE_SAFE_PUTENV)
#      else 
#        if defined(HAS_CLEARENV)
#        elif defined(HAS_UNSETENV)
#        else 
#        endif 
#      endif 
#    endif 
#  endif 
#endif 
#ifdef PERL_IMPLICIT_CONTEXT
#ifndef PERL_GLOBAL_STRUCT_PRIVATE
#if defined(USE_ITHREADS)
#endif
#if defined(USE_ITHREADS)
#endif
#else 
#if defined(USE_ITHREADS)
#endif
#if defined(USE_ITHREADS)
#endif
#endif 
#endif 
#ifndef HAS_STRLCAT
#endif
#ifndef HAS_STRLCPY
#endif
#if defined(_MSC_VER) && (_MSC_VER >= 1300) && (_MSC_VER < 1400) && (WINVER < 0x0500)
#endif
#ifdef NO_TAINT_SUPPORT
#endif
#ifdef HAS_DIRFD
#elif defined(HAS_DIR_DD_FD)
#else
#endif 
