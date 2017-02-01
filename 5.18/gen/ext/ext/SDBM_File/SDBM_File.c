/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of SDBM_File.xs. Do not edit this file, edit SDBM_File.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "SDBM_File.xs"
#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "sdbm/sdbm.h"

#define fetch_key 0
#define store_key 1
#define fetch_value 2
#define store_value 3

typedef struct {
	DBM * 	dbp ;
	SV *    filter[4];
	int     filtering ;
	} SDBM_File_type;

typedef SDBM_File_type * SDBM_File ;
typedef datum datum_key ;
typedef datum datum_value ;

#define sdbm_TIEHASH(dbtype,filename,flags,mode) sdbm_open(filename,flags,mode)
#define sdbm_FETCH(db,key)			sdbm_fetch(db->dbp,key)
#define sdbm_STORE(db,key,value,flags)		sdbm_store(db->dbp,key,value,flags)
#define sdbm_DELETE(db,key)			sdbm_delete(db->dbp,key)
#define sdbm_EXISTS(db,key)			sdbm_exists(db->dbp,key)
#define sdbm_FIRSTKEY(db)			sdbm_firstkey(db->dbp)
#define sdbm_NEXTKEY(db,key)			sdbm_nextkey(db->dbp)


#line 41 "SDBM_File.c"
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

#line 183 "SDBM_File.c"

XS_EUPXS(XS_SDBM_File_TIEHASH); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_TIEHASH)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "dbtype, filename, flags, mode");
    {
	char *	dbtype = (char *)SvPV_nolen(ST(0))
;
	char *	filename = (char *)SvPV_nolen(ST(1))
;
	int	flags = (int)SvIV(ST(2))
;
	int	mode = (int)SvIV(ST(3))
;
	SDBM_File	RETVAL;
#line 40 "SDBM_File.xs"
	{
	    DBM * 	dbp ;

	    RETVAL = NULL ;
	    if ((dbp = sdbm_open(filename,flags,mode))) {
	        RETVAL = (SDBM_File)safecalloc(1, sizeof(SDBM_File_type));
		RETVAL->dbp = dbp ;
	    }

	}
#line 212 "SDBM_File.c"
	ST(0) = sv_newmortal();
        sv_setref_pv(ST(0), dbtype, (void*)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "db");
    {
	SDBM_File	db;

	if (SvROK(ST(0))) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not a reference",
			"SDBM_File::DESTROY",
			"db")
;
#line 57 "SDBM_File.xs"
	if (db) {
	    int i = store_value;
	    sdbm_close(db->dbp);
	    do {
		if (db->filter[i])
		    SvREFCNT_dec(db->filter[i]);
	    } while (i-- > 0);
	    safefree(db) ;
	}
#line 248 "SDBM_File.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_SDBM_File_FETCH); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_FETCH)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "db, key");
    {
	SDBM_File	db;
	datum_key	key;
	datum_value	RETVAL;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"SDBM_File::FETCH",
			"db", "SDBM_File")
;

	{
	    STRLEN len;
	    DBM_ckFilter(ST(1), filter[store_key], "filter_store_key");
	    key.dptr = SvPVbyte(ST(1), len);
	    key.dsize = (int)len;
	}
;

	RETVAL = sdbm_FETCH(db, key);
	ST(0) = sv_newmortal();
	sv_setpvn(ST(0), RETVAL.dptr, RETVAL.dsize);
	DBM_ckFilter(ST(0), filter[fetch_value],"filter_fetch_value");
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_STORE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_STORE)
{
    dVAR; dXSARGS;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "db, key, value, flags = DBM_REPLACE");
    {
	SDBM_File	db;
	datum_key	key;
	datum_value	value;
	int	flags;
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"SDBM_File::STORE",
			"db", "SDBM_File")
;

	{
	    STRLEN len;
	    DBM_ckFilter(ST(1), filter[store_key], "filter_store_key");
	    key.dptr = SvPVbyte(ST(1), len);
	    key.dsize = (int)len;
	}
;

        DBM_ckFilter(ST(2), filter[store_value], "filter_store_value");
	if (SvOK(ST(2))) {
	    STRLEN len;
	    value.dptr = SvPVbyte(ST(2), len);
	    value.dsize = (int)len;
	}
	else {
	    value.dptr = "";
	    value.dsize = 0;
	}
;

	if (items < 4)
	    flags = DBM_REPLACE;
	else {
	    flags = (int)SvIV(ST(3))
;
	}

	RETVAL = sdbm_STORE(db, key, value, flags);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 79 "SDBM_File.xs"
	if (RETVAL) {
	    if (RETVAL < 0 && errno == EPERM)
		croak("No write permission to sdbm file");
	    croak("sdbm store returned %d, errno %d, key \"%s\"",
			RETVAL,errno,key.dptr);
	    sdbm_clearerr(db->dbp);
	}
#line 353 "SDBM_File.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_DELETE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_DELETE)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "db, key");
    {
	SDBM_File	db;
	datum_key	key;
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"SDBM_File::DELETE",
			"db", "SDBM_File")
;

	{
	    STRLEN len;
	    DBM_ckFilter(ST(1), filter[store_key], "filter_store_key");
	    key.dptr = SvPVbyte(ST(1), len);
	    key.dsize = (int)len;
	}
;

	RETVAL = sdbm_DELETE(db, key);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_EXISTS); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_EXISTS)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "db, key");
    {
	SDBM_File	db;
	datum_key	key;
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"SDBM_File::EXISTS",
			"db", "SDBM_File")
;

	{
	    STRLEN len;
	    DBM_ckFilter(ST(1), filter[store_key], "filter_store_key");
	    key.dptr = SvPVbyte(ST(1), len);
	    key.dsize = (int)len;
	}
;

	RETVAL = sdbm_EXISTS(db, key);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_FIRSTKEY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_FIRSTKEY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "db");
    {
	SDBM_File	db;
	datum_key	RETVAL;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"SDBM_File::FIRSTKEY",
			"db", "SDBM_File")
;

	RETVAL = sdbm_FIRSTKEY(db);
	ST(0) = sv_newmortal();
	sv_setpvn(ST(0), RETVAL.dptr, RETVAL.dsize);
	DBM_ckFilter(ST(0), filter[fetch_key],"filter_fetch_key");
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_NEXTKEY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_NEXTKEY)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "db, key");
    {
	SDBM_File	db;
	datum_key	key;
	datum_key	RETVAL;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"SDBM_File::NEXTKEY",
			"db", "SDBM_File")
;

	{
	    STRLEN len;
	    DBM_ckFilter(ST(1), filter[store_key], "filter_store_key");
	    key.dptr = SvPVbyte(ST(1), len);
	    key.dsize = (int)len;
	}
;

	RETVAL = sdbm_NEXTKEY(db, key);
	ST(0) = sv_newmortal();
	sv_setpvn(ST(0), RETVAL.dptr, RETVAL.dsize);
	DBM_ckFilter(ST(0), filter[fetch_key],"filter_fetch_key");
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_error); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_error)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "db");
    {
	SDBM_File	db;
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			GvNAME(CvGV(cv)),
			"db", "SDBM_File")
;
#line 112 "SDBM_File.xs"
	RETVAL = ix ? sdbm_clearerr(db->dbp) : sdbm_error(db->dbp);
#line 523 "SDBM_File.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_SDBM_File_filter_fetch_key); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_SDBM_File_filter_fetch_key)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "db, code");
    {
	SDBM_File	db;
	SV *	code = ST(1)
;
	SV *	RETVAL = &PL_sv_undef ;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "SDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(SDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			GvNAME(CvGV(cv)),
			"db", "SDBM_File")
;
#line 127 "SDBM_File.xs"
	    DBM_setFilter(db->filter[ix], code);
#line 554 "SDBM_File.c"
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_SDBM_File); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_SDBM_File)
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

    {
        CV * cv;

        newXS("SDBM_File::TIEHASH", XS_SDBM_File_TIEHASH, file);
        newXS("SDBM_File::DESTROY", XS_SDBM_File_DESTROY, file);
        newXS("SDBM_File::FETCH", XS_SDBM_File_FETCH, file);
        newXS("SDBM_File::STORE", XS_SDBM_File_STORE, file);
        newXS("SDBM_File::DELETE", XS_SDBM_File_DELETE, file);
        newXS("SDBM_File::EXISTS", XS_SDBM_File_EXISTS, file);
        newXS("SDBM_File::FIRSTKEY", XS_SDBM_File_FIRSTKEY, file);
        newXS("SDBM_File::NEXTKEY", XS_SDBM_File_NEXTKEY, file);
        cv = newXS("SDBM_File::sdbm_clearerr", XS_SDBM_File_error, file);
        XSANY.any_i32 = 1;
        cv = newXS("SDBM_File::error", XS_SDBM_File_error, file);
        XSANY.any_i32 = 0;
        cv = newXS("SDBM_File::filter_store_value", XS_SDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = store_value;
        cv = newXS("SDBM_File::filter_store_key", XS_SDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = store_key;
        cv = newXS("SDBM_File::filter_fetch_value", XS_SDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = fetch_value;
        cv = newXS("SDBM_File::filter_fetch_key", XS_SDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = fetch_key;
    }
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

