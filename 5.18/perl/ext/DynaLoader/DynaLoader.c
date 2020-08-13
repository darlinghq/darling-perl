/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of DynaLoader.xs. Do not edit this file, edit DynaLoader.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "DynaLoader.xs"
/* dl_dlopen.xs
 * 
 * Platform:	SunOS/Solaris, possibly others which use dlopen.
 * Author:	Paul Marquess (Paul.Marquess@btinternet.com)
 * Created:	10th July 1994
 *
 * Modified:
 * 15th July 1994     - Added code to explicitly save any error messages.
 * 3rd August 1994    - Upgraded to v3 spec.
 * 9th August 1994    - Changed to use IV
 * 10th August 1994   - Tim Bunce: Added RTLD_LAZY, switchable debugging,
 *                      basic FreeBSD support, removed ClearError
 * 29th February 2000 - Alan Burlison: Added functionality to close dlopen'd
 *                      files when the interpreter exits
 *
 */

/* Porting notes:


   Definition of Sunos dynamic Linking functions
   =============================================
   In order to make this implementation easier to understand here is a
   quick definition of the SunOS Dynamic Linking functions which are
   used here.

   dlopen
   ------
     void *
     dlopen(path, mode)
     char * path; 
     int    mode;

     This function takes the name of a dynamic object file and returns
     a descriptor which can be used by dlsym later. It returns NULL on
     error.

     The mode parameter must be set to 1 for Solaris 1 and to
     RTLD_LAZY (==2) on Solaris 2.


   dlclose
   -------
     int
     dlclose(handle)
     void * handle;

     This function takes the handle returned by a previous invocation of
     dlopen and closes the associated dynamic object file.  It returns zero
     on success, and non-zero on failure.


   dlsym
   ------
     void *
     dlsym(handle, symbol)
     void * handle; 
     char * symbol;

     Takes the handle returned from dlopen and the name of a symbol to
     get the address of. If the symbol was found a pointer is
     returned.  It returns NULL on error. If DL_PREPEND_UNDERSCORE is
     defined an underscore will be added to the start of symbol. This
     is required on some platforms (freebsd).

   dlerror
   ------
     char * dlerror()

     Returns a null-terminated string which describes the last error
     that occurred with either dlopen or dlsym. After each call to
     dlerror the error message will be reset to a null pointer. The
     SaveError function is used to save the error as soon as it happens.


   Return Types
   ============
   In this implementation the two functions, dl_load_file &
   dl_find_symbol, return void *. This is because the underlying SunOS
   dynamic linker calls also return void *.  This is not necessarily
   the case for all architectures. For example, some implementation
   will want to return a char * for dl_load_file.

   If void * is not appropriate for your architecture, you will have to
   change the void * to whatever you require. If you are not certain of
   how Perl handles C data types, I suggest you start by consulting	
   Dean Roerich's Perl 5 API document. Also, have a look in the typemap 
   file (in the ext directory) for a fairly comprehensive list of types 
   that are already supported. If you are completely stuck, I suggest you
   post a message to perl5-porters, comp.lang.perl.misc or if you are really 
   desperate to me.

   Remember when you are making any changes that the return value from 
   dl_load_file is used as a parameter in the dl_find_symbol 
   function. Also the return value from find_symbol is used as a parameter 
   to install_xsub.


   Dealing with Error Messages
   ============================
   In order to make the handling of dynamic linking errors as generic as
   possible you should store any error messages associated with your
   implementation with the StoreError function.

   In the case of SunOS the function dlerror returns the error message 
   associated with the last dynamic link error. As the SunOS dynamic 
   linker functions dlopen & dlsym both return NULL on error every call 
   to a SunOS dynamic link routine is coded like this

	RETVAL = dlopen(filename, 1) ;
	if (RETVAL == NULL)
	    SaveError("%s",dlerror()) ;

   Note that SaveError() takes a printf format string. Use a "%s" as
   the first parameter if the error may contain any % characters.

*/

#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

#ifdef I_DLFCN
#include <dlfcn.h>	/* the dynamic linker include file for Sunos/Solaris */
#else
#include <nlist.h>
#include <link.h>
#endif

#ifndef RTLD_LAZY
# define RTLD_LAZY 1	/* Solaris 1 */
#endif

#ifndef HAS_DLERROR
# ifdef __NetBSD__
#  define dlerror() strerror(errno)
# else
#  define dlerror() "Unknown error - dlerror() not implemented"
# endif
#endif


#include "dlutils.c"	/* SaveError() etc	*/


static void
dl_private_init(pTHX)
{
    (void)dl_generic_private_init(aTHX);
}

#line 164 "DynaLoader.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 306 "DynaLoader.c"

XS_EUPXS(XS_DynaLoader_dl_load_file); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_DynaLoader_dl_load_file)
{
    dVAR; dXSARGS;
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "filename, flags=0");
    {
	char *	filename = (char *)SvPV_nolen(ST(0))
;
	int	flags;
#line 165 "DynaLoader.xs"
    int mode = RTLD_LAZY;
    void *handle;
#line 321 "DynaLoader.c"

	if (items < 2)
	    flags = 0;
	else {
	    flags = (int)SvIV(ST(1))
;
	}
#line 168 "DynaLoader.xs"
{
#if defined(DLOPEN_WONT_DO_RELATIVE_PATHS)
    char pathbuf[PATH_MAX + 2];
    if (*filename != '/' && strchr(filename, '/')) {
	if (getcwd(pathbuf, PATH_MAX - strlen(filename))) {
	    strcat(pathbuf, "/");
	    strcat(pathbuf, filename);
	    filename = pathbuf;
	}
    }
#endif
#ifdef RTLD_NOW
    {
	dMY_CXT;
	if (dl_nonlazy)
	    mode = RTLD_NOW;
    }
#endif
    if (flags & 0x01)
#ifdef RTLD_GLOBAL
	mode |= RTLD_GLOBAL;
#else
	Perl_warn(aTHX_ "Can't make loaded symbols global on this platform while loading %s",filename);
#endif
    DLDEBUG(1,PerlIO_printf(Perl_debug_log, "dl_load_file(%s,%x):\n", filename,flags));
    handle = dlopen(filename, mode) ;
    DLDEBUG(2,PerlIO_printf(Perl_debug_log, " libref=%lx\n", (unsigned long) handle));
    ST(0) = sv_newmortal() ;
    if (handle == NULL)
    {
	char *error = dlerror();
#ifdef __LP64__
	char *cp;
	char *err = NULL;
#endif /* __LP64__ */
	if (!error) error = "Unknown dlopen error";
#ifdef __LP64__
	else if ((cp = strstr(error, ": no matching architecture in universal wrapper")) != NULL) {
	    char *p = strchr(error, '\t');
	    if (p && ++p < cp) {
		    asprintf(&err, "%.*s: no appropriate 64-bit architecture (see \"man perl\" for running in 32-bit mode)", (cp - p), p);
		    if (err) error = err;
	    }
	}
#endif /* __LP64__ */
	SaveError(aTHX_ "%s", error);
#ifdef __LP64__
	if (err) free(err);
#endif /* __LP64__ */
    }
    else
	sv_setiv( ST(0), PTR2IV(handle));
}
#line 383 "DynaLoader.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_DynaLoader_dl_unload_file); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_DynaLoader_dl_unload_file)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "libref");
    {
	void *	libref = INT2PTR(void *,SvIV(ST(0)))
;
	int	RETVAL;
	dXSTARG;
#line 227 "DynaLoader.xs"
    DLDEBUG(1,PerlIO_printf(Perl_debug_log, "dl_unload_file(%lx):\n", PTR2ul(libref)));
    RETVAL = (dlclose(libref) == 0 ? 1 : 0);
    if (!RETVAL)
        SaveError(aTHX_ "%s", dlerror()) ;
    DLDEBUG(2,PerlIO_printf(Perl_debug_log, " retval = %d\n", RETVAL));
#line 406 "DynaLoader.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_DynaLoader_dl_find_symbol); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_DynaLoader_dl_find_symbol)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "libhandle, symbolname");
    {
	void *	libhandle = INT2PTR(void *,SvIV(ST(0)))
;
	char *	symbolname = (char *)SvPV_nolen(ST(1))
;
#line 241 "DynaLoader.xs"
    void *sym;
#line 426 "DynaLoader.c"
#line 243 "DynaLoader.xs"
#ifdef DLSYM_NEEDS_UNDERSCORE
    symbolname = Perl_form_nocontext("_%s", symbolname);
#endif
    DLDEBUG(2, PerlIO_printf(Perl_debug_log,
			     "dl_find_symbol(handle=%lx, symbol=%s)\n",
			     (unsigned long) libhandle, symbolname));
    sym = dlsym(libhandle, symbolname);
    DLDEBUG(2, PerlIO_printf(Perl_debug_log,
			     "  symbolref = %lx\n", (unsigned long) sym));
    ST(0) = sv_newmortal() ;
    if (sym == NULL)
	SaveError(aTHX_ "%s",dlerror()) ;
    else
	sv_setiv( ST(0), PTR2IV(sym));
#line 442 "DynaLoader.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_DynaLoader_dl_undef_symbols); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_DynaLoader_dl_undef_symbols)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 261 "DynaLoader.xs"
#line 456 "DynaLoader.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_DynaLoader_dl_install_xsub); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_DynaLoader_dl_install_xsub)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "perl_name, symref, filename=\"$Package\"");
    {
	char *	perl_name = (char *)SvPV_nolen(ST(0))
;
	void *	symref = INT2PTR(void *,SvIV(ST(1)))
;
	const char *	filename;

	if (items < 3)
	    filename = "DynaLoader";
	else {
	    filename = (const char *)SvPV_nolen(ST(2))
;
	}
#line 273 "DynaLoader.xs"
    DLDEBUG(2,PerlIO_printf(Perl_debug_log, "dl_install_xsub(name=%s, symref=%"UVxf")\n",
		perl_name, PTR2UV(symref)));
    ST(0) = sv_2mortal(newRV((SV*)newXS_flags(perl_name,
					      DPTR2FPTR(XSUBADDR_t, symref),
					      filename, NULL,
					      XS_DYNAMIC_FILENAME)));
#line 488 "DynaLoader.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_DynaLoader_dl_error); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_DynaLoader_dl_error)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
	char *	RETVAL;
	dXSTARG;
#line 284 "DynaLoader.xs"
    dMY_CXT;
    RETVAL = dl_last_error ;
#line 506 "DynaLoader.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}

#if defined(USE_ITHREADS)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_DynaLoader_CLONE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_DynaLoader_CLONE)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    {
#line 294 "DynaLoader.xs"
    MY_CXT_CLONE;

    /* MY_CXT_CLONE just does a memcpy on the whole structure, so to avoid
     * using Perl variables that belong to another thread, we create our 
     * own for this thread.
     */
    MY_CXT.x_dl_last_error = newSVpvn("", 0);
#line 530 "DynaLoader.c"
    }
    XSRETURN_EMPTY;
}

#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_DynaLoader); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_DynaLoader)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("DynaLoader::dl_load_file", XS_DynaLoader_dl_load_file, file);
        newXS("DynaLoader::dl_unload_file", XS_DynaLoader_dl_unload_file, file);
        newXS("DynaLoader::dl_find_symbol", XS_DynaLoader_dl_find_symbol, file);
        newXS("DynaLoader::dl_undef_symbols", XS_DynaLoader_dl_undef_symbols, file);
        newXS("DynaLoader::dl_install_xsub", XS_DynaLoader_dl_install_xsub, file);
        newXS("DynaLoader::dl_error", XS_DynaLoader_dl_error, file);
#if XSubPPtmpAAAA
        newXS("DynaLoader::CLONE", XS_DynaLoader_CLONE, file);
#endif

    /* Initialisation Section */

#line 157 "DynaLoader.xs"
    (void)dl_private_init(aTHX);

#if XSubPPtmpAAAA
#endif
#line 573 "DynaLoader.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

