#line 2 "pp_sys.c"
#include "EXTERN.h"
#define PERL_IN_PP_SYS_C
#include "perl.h"
#include "time64.h"
#include "time64.c"
#ifdef I_SHADOW
#   ifdef __hpux__
#       undef MAXINT
#   endif
#   include <shadow.h>
#endif
#ifdef I_SYS_RESOURCE
# include <sys/resource.h>
#endif
#ifdef NETWARE
#endif
#ifdef HAS_SELECT
# ifdef I_SYS_SELECT
#  include <sys/select.h>
# endif
#endif
#if defined(HOST_NOT_FOUND) && !defined(h_errno) && !defined(__CYGWIN__)
#endif
#ifdef HAS_PASSWD
# ifdef I_PWD
#  include <pwd.h>
# else
#  if !defined(VMS)
#  endif
# endif
# ifdef HAS_GETPWENT
#ifndef getpwent
#elif defined (VMS) && defined (my_getpwent)
#endif
# endif
#endif
#ifdef HAS_GROUP
# ifdef I_GRP
#  include <grp.h>
# else
# endif
# ifdef HAS_GETGRENT
#ifndef getgrent
#endif
# endif
#endif
#ifdef I_UTIME
#  if defined(_MSC_VER) || defined(__MINGW32__)
#    include <sys/utime.h>
#  else
#    include <utime.h>
#  endif
#endif
#ifdef HAS_CHSIZE
# ifdef my_chsize  
#   undef my_chsize
# endif
# define my_chsize PerlLIO_chsize
#else
# ifdef HAS_TRUNCATE
#   define my_chsize PerlLIO_chsize
# else
# endif
#endif
#ifdef HAS_FLOCK
#  define FLOCK flock
#else 
#  if defined(HAS_FCNTL) && !defined(I_FCNTL)
#    include <fcntl.h>
#  endif
#  if defined(HAS_FCNTL) && defined(FCNTL_CAN_LOCK)
#    define FLOCK fcntl_emulate_flock
#    define FCNTL_EMULATE_FLOCK
#  else 
#    ifdef HAS_LOCKF
#      define FLOCK lockf_emulate_flock
#      define LOCKF_EMULATE_FLOCK
#    endif 
#  endif 
#  ifdef FLOCK
#    ifndef LOCK_SH
#      define LOCK_SH 1
#    endif
#    ifndef LOCK_EX
#      define LOCK_EX 2
#    endif
#    ifndef LOCK_NB
#      define LOCK_NB 4
#    endif
#    ifndef LOCK_UN
#      define LOCK_UN 8
#    endif
#  endif 
#endif 
#define ZBTLEN 10
#if defined(I_SYS_ACCESS) && !defined(R_OK)
#  include <sys/access.h>
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD) && !defined(FD_CLOEXEC)
#  define FD_CLOEXEC 1		
#endif
#include "reentr.h"
#ifdef __Lynx__
#endif
#undef PERL_EFF_ACCESS	
#if !defined(PERL_EFF_ACCESS) && defined(HAS_ACCESS) && defined(EFF_ONLY_OK) && !defined(NO_EFF_ONLY_OK)
#   define PERL_EFF_ACCESS(p,f) (access((p), (f) | EFF_ONLY_OK))
#endif
#if !defined(PERL_EFF_ACCESS) && defined(HAS_EACCESS)
#   ifdef I_SYS_SECURITY
#       include <sys/security.h>
#   endif
#   ifdef ACC_SELF
#       define PERL_EFF_ACCESS(p,f) (eaccess((p), (f), ACC_SELF))
#   else
#       define PERL_EFF_ACCESS(p,f) (eaccess((p), (f)))
#   endif
#endif
#if !defined(PERL_EFF_ACCESS) && defined(HAS_ACCESSX) && defined(ACC_SELF)
#   define PERL_EFF_ACCESS(p,f) (accessx((p), (f), ACC_SELF))
#endif
#if !defined(PERL_EFF_ACCESS) && defined(HAS_ACCESS)	     && (defined(HAS_SETREUID) || defined(HAS_SETRESUID)		 	|| defined(HAS_SETREGID) || defined(HAS_SETRESGID))
#if !defined(HAS_SETREUID) && !defined(HAS_SETRESUID)
#else
#ifdef HAS_SETREUID
#else
#ifdef HAS_SETRESUID
#endif
#endif
#endif
#if !defined(HAS_SETREGID) && !defined(HAS_SETRESGID)
#else
#ifdef HAS_SETREGID
#else
#ifdef HAS_SETRESGID
#endif
#endif
#endif
#ifdef HAS_SETREUID
#else
#ifdef HAS_SETRESUID
#endif
#endif
#ifdef HAS_SETREGID
#else
#ifdef HAS_SETRESGID
#endif
#endif
#   define PERL_EFF_ACCESS(p,f) (S_emulate_eaccess(aTHX_ (p), (f)))
#endif
#ifndef VMS
#endif 
#ifndef DOSISH
#ifndef CSH
#endif	
#endif	
#ifdef VMS
#endif
#define tied_method0(a,b,c,d)		     Perl_tied_method(aTHX_ a,b,c,d,G_SCALAR,0)
#define tied_method1(a,b,c,d,e)		     Perl_tied_method(aTHX_ a,b,c,d,G_SCALAR,1,e)
#define tied_method2(a,b,c,d,e,f)	     Perl_tied_method(aTHX_ a,b,c,d,G_SCALAR,2,e,f)
#ifdef HAS_PIPE
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#else
#endif
#ifdef HAS_UMASK
#else
#endif
#ifdef HAS_SELECT
#if BYTEORDER != 0x1234 && BYTEORDER != 0x12345678
#   if BYTEORDER & 0xf0000
#	define ORDERBYTE (0x88888888 - BYTEORDER)
#   else
#	define ORDERBYTE (0x4444 - BYTEORDER)
#   endif
#endif
#if BYTEORDER != 0x1234 && BYTEORDER != 0x12345678
#  ifdef NFDBITS
#    ifndef NBBY
#     define NBBY 8
#    endif
#  else
#  endif
#endif
#  if SELECT_MIN_BITS == 1
#  else
#   if defined(__GLIBC__) && defined(__FD_SETSIZE)
#      undef SELECT_MIN_BITS
#      define SELECT_MIN_BITS __FD_SETSIZE
#   endif
#  endif
#if BYTEORDER != 0x1234 && BYTEORDER != 0x12345678
#else
#endif
#ifdef PERL_IRIX5_SELECT_TIMEVAL_VOID_CAST
#else
#endif
#if BYTEORDER != 0x1234 && BYTEORDER != 0x12345678
#endif
#else
#endif
#ifdef HAS_SOCKET
#if (defined(VMS_DO_SOCKETS) && defined(DECCRTL_SOCKETS)) || defined(__QNXNTO__)
#else
#endif
#ifdef OS2	
#endif
#endif
#ifdef PERL_SOCK_SYSREAD_IS_RECV
#endif
#ifdef HAS_SOCKET__bad_code_maybe
#if defined(VMS_DO_SOCKETS) && defined(DECCRTL_SOCKETS)
#else
#endif
#endif
#ifdef HAS_SOCKET
#endif
#if Size_t_size > IVSIZE
#else
#endif
#ifdef PERL_SOCK_SYSWRITE_IS_SEND
#endif
#if Size_t_size > IVSIZE
#else
#endif
#if LSEEKSIZE > IVSIZE
#else
#endif
#if LSEEKSIZE > IVSIZE
#else
#endif
#if LSEEKSIZE > IVSIZE
#else
#endif
#if LSEEKSIZE > IVSIZE
#else
#endif
#if Off_t_size > IVSIZE
#else
#endif
#ifdef HAS_TRUNCATE
#else
#endif
#ifdef HAS_TRUNCATE
#else
#endif
#ifdef HAS_IOCTL
#else
#endif
#ifndef HAS_FCNTL
#else
#if defined(OS2) && defined(__EMX__)
#else
#endif
#endif
#if defined(HAS_IOCTL) || defined(HAS_FCNTL)
#endif
#ifdef FLOCK
#else
#endif
#ifdef HAS_SOCKET
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#endif
#if defined (HAS_SOCKETPAIR) || (defined (HAS_SOCKET) && defined(SOCK_DGRAM) && defined(AF_INET) && defined(PF_INET))
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#else
#endif
#ifdef HAS_SOCKET
#if (defined(VMS_DO_SOCKETS) && defined(DECCRTL_SOCKETS)) || defined(__QNXNTO__)
#else
#endif
#if defined(OEMVS)
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#ifdef __SCO_VERSION__
#endif
#if defined(__SYMBIAN32__)
# define SETSOCKOPT_OPTION_VALUE_T void *
#else
# define SETSOCKOPT_OPTION_VALUE_T const char *
#endif
#if defined(VMS_DO_SOCKETS) && defined (DECCRTL_SOCKETS)
#endif
#ifdef BOGUS_GETNAME_RETURN
#endif
#endif
#if ST_INO_SIZE > IVSIZE
#else
#   if ST_INO_SIGN <= 0
#   else
#   endif
#endif
#if Uid_t_size > IVSIZE
#else
#   if Uid_t_sign <= 0
#   else
#   endif
#endif
#if Gid_t_size > IVSIZE
#else
#   if Gid_t_sign <= 0
#   else
#   endif
#endif
#ifdef USE_STAT_RDEV
#else
#endif
#if Off_t_size > IVSIZE
#else
#endif
#ifdef BIG_TIME
#else
#endif
#ifdef USE_STAT_BLOCKS
#else
#endif
#define FT_RETURNNO	return S_ft_return_false(aTHX_ &PL_sv_no)
#define FT_RETURNUNDEF	return S_ft_return_false(aTHX_ &PL_sv_undef)
#define FT_RETURNYES	return S_ft_return_true(aTHX_ &PL_sv_yes)
#define tryAMAGICftest_MG(chr) STMT_START {  	if ( (SvFLAGS(*PL_stack_sp) & (SVf_ROK|SVs_GMG))  		&& PL_op->op_flags & OPf_KIDS) {      	    OP *next = S_try_amagic_ftest(aTHX_ chr);	 	    if (next) return next;			   	}						        } STMT_END
#if defined(HAS_ACCESS) || defined (PERL_EFF_ACCESS)
#  ifdef R_OK
#  else
#  endif
#else
#endif
#if !(defined(HAS_ACCESS) && defined(R_OK))
#endif
#if defined(HAS_ACCESS) && defined(W_OK)
#else
#endif
#if defined(HAS_ACCESS) && defined(X_OK)
#else
#endif
#ifdef PERL_EFF_ACCESS
#endif
#ifndef PERL_EFF_ACCESS
#endif
#ifdef PERL_EFF_ACCESS
#else
#endif
#if defined(HAS_ACCESS) || defined (PERL_EFF_ACCESS)
#  ifdef PERL_EFF_ACCESS
#  else
#  endif
#  ifdef HAS_ACCESS
#  else
#  endif
#endif
#if Off_t_size > IVSIZE
#else
#endif
#ifndef S_ISUID
#endif
#ifndef S_ISGID
#endif
#ifndef S_ISVTX
#endif
#ifdef S_ISUID
#endif
#ifdef S_ISGID
#endif
#ifdef S_ISVTX
#endif
#if defined(DOSISH) || defined(USEMYBINMODE)
#endif
#ifdef EBCDIC
#else
#ifdef USE_LOCALE
#endif
#endif
#ifdef VMS
#endif
#ifdef HAS_FCHDIR
#else
#endif
#ifdef VMS
#endif
#ifdef HAS_CHROOT
#else
#endif
#ifdef HAS_RENAME
#else
#endif
#if defined(HAS_LINK) || defined(HAS_SYMLINK)
#  ifndef HAS_LINK
#  endif
#  ifndef HAS_SYMLINK
#  endif
#  if defined(HAS_LINK)
#    if defined(HAS_SYMLINK)
#    else
#    endif
#  else
#    if defined(HAS_SYMLINK)
#    endif
#  endif
#else
#endif
#ifdef HAS_SYMLINK
#ifndef INCOMPLETE_TAINTS
#endif
#else
#endif
#if !defined(HAS_MKDIR) || !defined(HAS_RMDIR)
#ifdef HAS_SYS_ERRLIST
#endif
#ifdef HAS_SYS_ERRLIST
#else
#endif
#ifndef EACCES
#define EACCES EPERM
#endif
#endif
#define TRIMSLASHES(tmps,len,copy) (tmps) = SvPV_const(TOPs, (len));      if ((len) > 1 && (tmps)[(len)-1] == '/') {  	do {  	    (len)--;  	} while ((len) > 1 && (tmps)[(len)-1] == '/');  	(tmps) = savepvn((tmps), (len));  	(copy) = TRUE;      }
#ifdef HAS_MKDIR
#else
#endif
#ifdef HAS_RMDIR
#else
#endif
#if defined(Direntry_t) && defined(HAS_READDIR)
#else
#endif
#if !defined(Direntry_t) || !defined(HAS_READDIR)
#else
#if !defined(I_DIRENT) && !defined(VMS)
#endif
#ifdef DIRNAMLEN
#else
#endif
#ifndef INCOMPLETE_TAINTS
#endif
#endif
#if defined(HAS_TELLDIR) || defined(telldir)
# if !defined(HAS_TELLDIR_PROTO) || defined(NEED_TELLDIR_PROTO)
# endif
#else
#endif
#if defined(HAS_SEEKDIR) || defined(seekdir)
#else
#endif
#if defined(HAS_REWINDDIR) || defined(rewinddir)
#else
#endif
#if defined(Direntry_t) && defined(HAS_READDIR)
#ifdef VOID_CLOSEDIR
#else
#endif
#else
#endif
#ifdef HAS_FORK
#if defined(HAS_SIGPROCMASK) && !defined(PERL_MICRO)
#endif
#if defined(HAS_SIGPROCMASK) && !defined(PERL_MICRO)
#endif
#if defined(HAS_SIGPROCMASK) && !defined(PERL_MICRO)
#endif
#ifdef PERL_USES_PL_PIDSTATUS
#endif
#else
#  if defined(USE_ITHREADS) && defined(PERL_IMPLICIT_SYS)
#  else
#  endif
#endif
#if (!defined(DOSISH) || defined(OS2) || defined(WIN32)) && !defined(__LIBCATAMOUNT__)
#  if defined(USE_ITHREADS) && defined(PERL_IMPLICIT_SYS)
#  else
#  endif
#else
#endif
#if (!defined(DOSISH) || defined(OS2) || defined(WIN32)) && !defined(__LIBCATAMOUNT__)
#  if defined(USE_ITHREADS) && defined(PERL_IMPLICIT_SYS)
#  else
#  endif
#else
#endif
#if defined(__LIBCATAMOUNT__)
#else
#if (defined(HAS_FORK) || defined(AMIGAOS)) && !defined(VMS) && !defined(OS2) || defined(PERL_MICRO)
#if (defined(HAS_SIGPROCMASK) && !defined(PERL_MICRO))
#endif
#if (defined(HAS_SIGPROCMASK) && !defined(PERL_MICRO))
#endif
#if (defined(HAS_SIGPROCMASK) && !defined(PERL_MICRO))
#endif
#ifndef PERL_MICRO
#endif
#ifndef PERL_MICRO
#ifdef HAS_SIGPROCMASK
#endif
#endif
#if (defined(HAS_SIGPROCMASK) && !defined(PERL_MICRO))
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#else 
#  if defined(WIN32) || defined(OS2) || defined(__SYMBIAN32__) || defined(__VMS)
#  else
#  endif
#  if defined(WIN32) || defined(OS2) || defined(__SYMBIAN32__) || defined(__VMS)
#  else
#  endif
#endif 
#endif
#ifdef VMS
#else
#endif
#ifdef VMS
#else
#endif
#ifdef HAS_GETPPID
#else
#endif
#ifdef HAS_GETPGRP
#ifdef BSD_GETPGRP
#else
#endif
#else
#endif
#ifdef HAS_SETPGRP
#ifdef BSD_SETPGRP
#else
#endif 
#else
#endif
#if defined(__GLIBC__) && ((__GLIBC__ == 2 && __GLIBC_MINOR__ >= 3) || (__GLIBC__ > 2))
#  define PRIORITY_WHICH_T(which) (__priority_which_t)which
#else
#  define PRIORITY_WHICH_T(which) which
#endif
#ifdef HAS_GETPRIORITY
#else
#endif
#ifdef HAS_SETPRIORITY
#else
#endif
#undef PRIORITY_WHICH_T
#ifdef BIG_TIME
#else
#endif
#ifdef HAS_TIMES
#ifndef VMS
#else
#endif
#else
#   ifdef PERL_MICRO
#   else
#   endif
#endif 
#define TIME_LOWER_BOUND -67768100567755200.0
#define TIME_UPPER_BOUND  67767976233316800.0
#ifdef HAS_ALARM
#else
#endif
#if defined(HAS_MSG) || defined(HAS_SEM) || defined(HAS_SHM)
#else
#endif
#if defined(HAS_MSG) || defined(HAS_SEM) || defined(HAS_SHM)
#else
#endif
#if defined(HAS_MSG) || defined(HAS_SEM) || defined(HAS_SHM)
#else
#endif
#if defined(HAS_GETHOSTBYNAME) || defined(HAS_GETHOSTBYADDR) || defined(HAS_GETHOSTENT)
#ifndef HAS_GETHOST_PROTOS 
#endif
#ifdef HAS_GETHOSTBYNAME
#else
#endif
#ifdef HAS_GETHOSTBYADDR
#else
#endif
#ifdef HAS_GETHOSTENT
#else
#endif
#ifdef HOST_NOT_FOUND
#ifdef USE_REENTRANT_API
#   ifdef USE_GETHOSTENT_ERRNO
#   endif
#endif
#endif
#ifdef h_addr
#else
#endif 
#else
#endif
#if defined(HAS_GETNETBYNAME) || defined(HAS_GETNETBYADDR) || defined(HAS_GETNETENT)
#ifndef HAS_GETNET_PROTOS 
#endif
#ifdef HAS_GETNETBYNAME
#else
#endif
#ifdef HAS_GETNETBYADDR
#else
#endif
#ifdef HAS_GETNETENT
#else
#endif
#ifdef HOST_NOT_FOUND
#ifdef USE_REENTRANT_API
#   ifdef USE_GETNETENT_ERRNO
#   endif
#endif
#endif
#else
#endif
#if defined(HAS_GETPROTOBYNAME) || defined(HAS_GETPROTOBYNUMBER) || defined(HAS_GETPROTOENT)
#ifndef HAS_GETPROTO_PROTOS 
#endif
#ifdef HAS_GETPROTOBYNAME
#else
#endif
#ifdef HAS_GETPROTOBYNUMBER
#else
#endif
#ifdef HAS_GETPROTOENT
#else
#endif
#else
#endif
#if defined(HAS_GETSERVBYNAME) || defined(HAS_GETSERVBYPORT) || defined(HAS_GETSERVENT)
#ifndef HAS_GETSERV_PROTOS 
#endif
#ifdef HAS_GETSERVBYNAME
#else
#endif
#ifdef HAS_GETSERVBYPORT
#ifdef HAS_HTONS
#endif
#else
#endif
#ifdef HAS_GETSERVENT
#else
#endif
#ifdef HAS_NTOHS
#else
#endif
#ifdef HAS_NTOHS
#else
#endif
#else
#endif
#ifdef HAS_SETHOSTENT
#else
#endif
#ifdef HAS_SETNETENT
#else
#endif
#ifdef HAS_SETPROTOENT
#else
#endif
#ifdef HAS_SETSERVENT
#else
#endif
#ifdef HAS_ENDHOSTENT
#else
#endif
#ifdef HAS_ENDNETENT
#else
#endif
#ifdef HAS_ENDPROTOENT
#else
#endif
#ifdef HAS_ENDSERVENT
#else
#endif
#if defined(HAS_GROUP) && defined(HAS_SETGRENT)
#else
#endif
#if defined(HAS_GROUP) && defined(HAS_ENDGRENT)
#else
#endif
#if defined(HAS_PASSWD) && defined(HAS_SETPWENT)
#else
#endif
#if defined(HAS_PASSWD) && defined(HAS_ENDPWENT)
#else
#endif
#ifdef HAS_PASSWD
#   if defined(__CYGWIN__) && defined(USE_REENTRANT_API)
#   endif
#   ifdef HAS_GETPWENT
#ifdef POSIX_BC   
#endif
#   else
#   endif
#   if Uid_t_sign <= 0
#   else
#   endif
#   if defined(HAS_GETSPNAM) && !defined(_AIX)
#   endif
#   ifdef PWPASSWD
#   endif
#   ifndef INCOMPLETE_TAINTS
#   endif
#   if Uid_t_sign <= 0
#   else
#   endif
#   if Uid_t_sign <= 0
#   else
#   endif
#   ifdef PWCHANGE
#   else
#       ifdef PWQUOTA
#       else
#           ifdef PWAGE
#	    else
#           endif
#       endif
#   endif
#   ifdef PWCLASS
#   else
#       ifdef PWCOMMENT
#	else
#       endif
#   endif
#   ifdef PWGECOS
#   else
#   endif
#   ifndef INCOMPLETE_TAINTS
#   endif
#   ifndef INCOMPLETE_TAINTS
#   endif
#   ifdef PWEXPIRE
#   endif
#else
#endif
#ifdef HAS_GROUP
#ifdef HAS_GETGRENT
#else
#endif
#if Gid_t_sign <= 0
#else
#endif
#ifdef GRPASSWD
#else
#endif
#if Gid_t_sign <= 0
#else
#endif
#if !(defined(_CRAYMPP) && defined(USE_REENTRANT_API))
#endif
#else
#endif
#ifdef HAS_GETLOGIN
#else
#endif
#ifdef HAS_SYSCALL
#if defined(__i386__)
#elif defined(__x86_64__)
#else
#error Unknown architecture
#endif
#else
#endif
#ifdef FCNTL_EMULATE_FLOCK
#endif 
#ifdef LOCKF_EMULATE_FLOCK
# ifndef F_ULOCK
#  define F_ULOCK	0	
# endif
# ifndef F_LOCK
#  define F_LOCK	1	
# endif
# ifndef F_TLOCK
#  define F_TLOCK	2	
# endif
# ifndef F_TEST
#  define F_TEST	3	
# endif
#endif 
