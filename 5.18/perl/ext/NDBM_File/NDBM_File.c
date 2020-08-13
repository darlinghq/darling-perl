/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of NDBM_File.xs. Do not edit this file, edit NDBM_File.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "NDBM_File.xs"
#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#undef NDBM_HEADER_USES_PROTOTYPES
#if defined(I_GDBM_NDBM)
#  ifdef GDBM_NDBM_H_USES_PROTOTYPES
#    define NDBM_HEADER_USES_PROTOTYPES
START_EXTERN_C
#  endif
#  include <gdbm-ndbm.h> /* Debian compatibility version */
#elif defined(I_GDBMNDBM)
#  ifdef GDBMNDBM_H_USES_PROTOTYPES
#    define NDBM_HEADER_USES_PROTOTYPES
START_EXTERN_C
#  endif
#  include <gdbm/ndbm.h> /* RedHat compatibility version */
#elif defined(I_NDBM)
#  ifdef NDBM_H_USES_PROTOTYPES
#    define NDBM_HEADER_USES_PROTOTYPES
START_EXTERN_C
#  endif
#  include <ndbm.h>
#endif
#ifdef NDBM_HEADER_USES_PROTOTYPES
END_EXTERN_C
#endif

#define fetch_key 0
#define store_key 1
#define fetch_value 2
#define store_value 3

typedef struct {
	DBM * 	dbp ;
	SV *    filter[4];
	int     filtering ;
	} NDBM_File_type;

typedef NDBM_File_type * NDBM_File ;
typedef datum datum_key ;
typedef datum datum_value ;


#if defined(__cplusplus) && !defined(NDBM_HEADER_USES_PROTOTYPES)
/* gdbm's header file used for compatibility with gdbm */
/* isn't compatible to C++ syntax, so we need these */
/* declarations to make everyone happy. */
EXTERN_C DBM *dbm_open(const char *, int, mode_t);
EXTERN_C void dbm_close(DBM *);
EXTERN_C datum dbm_fetch(DBM *, datum);
EXTERN_C int dbm_store(DBM *, datum, datum, int);
EXTERN_C int dbm_delete(DBM *, datum);
EXTERN_C datum dbm_firstkey(DBM *);
EXTERN_C datum dbm_nextkey(DBM *);
#endif

#line 69 "NDBM_File.c"
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

#line 211 "NDBM_File.c"

XS_EUPXS(XS_NDBM_File_TIEHASH); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_TIEHASH)
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
	NDBM_File	RETVAL;
#line 68 "NDBM_File.xs"
	{
	    DBM * 	dbp ;

	    RETVAL = NULL ;
	    if ((dbp =  dbm_open(filename, flags, mode))) {
	        RETVAL = (NDBM_File)safecalloc(1, sizeof(NDBM_File_type));
		RETVAL->dbp = dbp ;
	    }

	}
#line 240 "NDBM_File.c"
	ST(0) = sv_newmortal();
        sv_setref_pv(ST(0), dbtype, (void*)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_NDBM_File_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "db");
    {
	NDBM_File	db;
#line 85 "NDBM_File.xs"
	int i = store_value;
#line 258 "NDBM_File.c"

	if (SvROK(ST(0))) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not a reference",
			"NDBM_File::DESTROY",
			"db")
;
#line 87 "NDBM_File.xs"
	dbm_close(db->dbp);
	do {
	    if (db->filter[i])
		SvREFCNT_dec(db->filter[i]);
	} while (i-- > 0);
	safefree(db);
#line 276 "NDBM_File.c"
    }
    XSRETURN_EMPTY;
}

#define ndbm_FETCH(db,key)			dbm_fetch(db->dbp,key)

XS_EUPXS(XS_NDBM_File_FETCH); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_FETCH)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "db, key");
    {
	NDBM_File	db;
	datum_key	key;
	datum_value	RETVAL;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"NDBM_File::FETCH",
			"db", "NDBM_File")
;

	{
	    STRLEN len;
	    DBM_ckFilter(ST(1), filter[store_key], "filter_store_key");
	    key.dptr = SvPVbyte(ST(1), len);
	    key.dsize = (int)len;
	}
;

	RETVAL = ndbm_FETCH(db, key);
	ST(0) = sv_newmortal();
	sv_setpvn(ST(0), (char *)RETVAL.dptr, RETVAL.dsize);
	DBM_ckFilter(ST(0), filter[fetch_value], "filter_fetch_value");
    }
    XSRETURN(1);
}

#define ndbm_STORE(db,key,value,flags)		dbm_store(db->dbp,key,value,flags)

XS_EUPXS(XS_NDBM_File_STORE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_STORE)
{
    dVAR; dXSARGS;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "db, key, value, flags = DBM_REPLACE");
    {
	NDBM_File	db;
	datum_key	key;
	datum_value	value;
	int	flags;
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"NDBM_File::STORE",
			"db", "NDBM_File")
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
	    value.dptr = (char *)"";
	    value.dsize = 0;
	}
;

	if (items < 4)
	    flags = DBM_REPLACE;
	else {
	    flags = (int)SvIV(ST(3))
;
	}

	RETVAL = ndbm_STORE(db, key, value, flags);
	XSprePUSH; PUSHi((IV)RETVAL);
#line 108 "NDBM_File.xs"
	if (RETVAL) {
	    if (RETVAL < 0 && errno == EPERM)
		croak("No write permission to ndbm file");
	    croak("ndbm store returned %d, errno %d, key \"%s\"",
			RETVAL,errno,key.dptr);
	    dbm_clearerr(db->dbp);
	}
#line 383 "NDBM_File.c"
    }
    XSRETURN(1);
}

#define ndbm_DELETE(db,key)			dbm_delete(db->dbp,key)

XS_EUPXS(XS_NDBM_File_DELETE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_DELETE)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "db, key");
    {
	NDBM_File	db;
	datum_key	key;
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"NDBM_File::DELETE",
			"db", "NDBM_File")
;

	{
	    STRLEN len;
	    DBM_ckFilter(ST(1), filter[store_key], "filter_store_key");
	    key.dptr = SvPVbyte(ST(1), len);
	    key.dsize = (int)len;
	}
;

	RETVAL = ndbm_DELETE(db, key);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#define ndbm_FIRSTKEY(db)			dbm_firstkey(db->dbp)

XS_EUPXS(XS_NDBM_File_FIRSTKEY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_FIRSTKEY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "db");
    {
	NDBM_File	db;
	datum_key	RETVAL;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"NDBM_File::FIRSTKEY",
			"db", "NDBM_File")
;

	RETVAL = ndbm_FIRSTKEY(db);
	ST(0) = sv_newmortal();
	sv_setpvn(ST(0), (char *)RETVAL.dptr, RETVAL.dsize);
	DBM_ckFilter(ST(0), filter[fetch_key], "filter_fetch_key");
    }
    XSRETURN(1);
}

#define ndbm_NEXTKEY(db,key)			dbm_nextkey(db->dbp)

XS_EUPXS(XS_NDBM_File_NEXTKEY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_NEXTKEY)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "db, key");
    {
	NDBM_File	db;
	datum_key	key;
	datum_key	RETVAL;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"NDBM_File::NEXTKEY",
			"db", "NDBM_File")
;

	RETVAL = ndbm_NEXTKEY(db, key);
	ST(0) = sv_newmortal();
	sv_setpvn(ST(0), (char *)RETVAL.dptr, RETVAL.dsize);
	DBM_ckFilter(ST(0), filter[fetch_key], "filter_fetch_key");
    }
    XSRETURN(1);
}

#define ndbm_error(db)				dbm_error(db->dbp)

XS_EUPXS(XS_NDBM_File_error); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_error)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "db");
    {
	NDBM_File	db;
	int	RETVAL;
	dXSTARG;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"NDBM_File::error",
			"db", "NDBM_File")
;

	RETVAL = ndbm_error(db);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#define ndbm_clearerr(db)			dbm_clearerr(db->dbp)

XS_EUPXS(XS_NDBM_File_clearerr); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_clearerr)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "db");
    {
	NDBM_File	db;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			"NDBM_File::clearerr",
			"db", "NDBM_File")
;

	ndbm_clearerr(db);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_NDBM_File_filter_fetch_key); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_NDBM_File_filter_fetch_key)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "db, code");
    {
	NDBM_File	db;
	SV *	code = ST(1)
;
	SV *	RETVAL = &PL_sv_undef ;

	if (SvROK(ST(0)) && sv_derived_from(ST(0), "NDBM_File")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    db = INT2PTR(NDBM_File,tmp);
	}
	else
	    Perl_croak(aTHX_ "%s: %s is not of type %s",
			GvNAME(CvGV(cv)),
			"db", "NDBM_File")
;
#line 155 "NDBM_File.xs"
	    DBM_setFilter(db->filter[ix], code);
#line 567 "NDBM_File.c"
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_NDBM_File); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_NDBM_File)
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

        newXS("NDBM_File::TIEHASH", XS_NDBM_File_TIEHASH, file);
        newXS("NDBM_File::DESTROY", XS_NDBM_File_DESTROY, file);
        newXS("NDBM_File::FETCH", XS_NDBM_File_FETCH, file);
        newXS("NDBM_File::STORE", XS_NDBM_File_STORE, file);
        newXS("NDBM_File::DELETE", XS_NDBM_File_DELETE, file);
        newXS("NDBM_File::FIRSTKEY", XS_NDBM_File_FIRSTKEY, file);
        newXS("NDBM_File::NEXTKEY", XS_NDBM_File_NEXTKEY, file);
        newXS("NDBM_File::error", XS_NDBM_File_error, file);
        newXS("NDBM_File::clearerr", XS_NDBM_File_clearerr, file);
        cv = newXS("NDBM_File::filter_store_key", XS_NDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = store_key;
        cv = newXS("NDBM_File::filter_store_value", XS_NDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = store_value;
        cv = newXS("NDBM_File::filter_fetch_key", XS_NDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = fetch_key;
        cv = newXS("NDBM_File::filter_fetch_value", XS_NDBM_File_filter_fetch_key, file);
        XSANY.any_i32 = fetch_value;
    }
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

