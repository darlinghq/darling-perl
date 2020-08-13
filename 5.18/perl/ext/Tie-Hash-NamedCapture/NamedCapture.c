/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of NamedCapture.xs. Do not edit this file, edit NamedCapture.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "NamedCapture.xs"
#define PERL_NO_GET_CONTEXT     /* we want efficiency */
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* These are tightly coupled to the RXapif_* flags defined in regexp.h  */
#define UNDEF_FATAL  0x80000
#define DISCARD      0x40000
#define EXPECT_SHIFT 24
#define ACTION_MASK  0x000FF

#define FETCH_ALIAS  (RXapif_FETCH  | (2 << EXPECT_SHIFT))
#define STORE_ALIAS  (RXapif_STORE  | (3 << EXPECT_SHIFT) | UNDEF_FATAL | DISCARD)
#define DELETE_ALIAS (RXapif_DELETE | (2 << EXPECT_SHIFT) | UNDEF_FATAL)
#define CLEAR_ALIAS  (RXapif_CLEAR  | (1 << EXPECT_SHIFT) | UNDEF_FATAL | DISCARD)
#define EXISTS_ALIAS (RXapif_EXISTS | (2 << EXPECT_SHIFT))
#define SCALAR_ALIAS (RXapif_SCALAR | (1 << EXPECT_SHIFT))

static void
tie_it(pTHX_ const char name, UV flag, HV *const stash)
{
    GV *const gv = gv_fetchpvn(&name, 1, GV_ADDMULTI|GV_NOTQUAL, SVt_PVHV);
    HV *const hv = GvHV(gv);
    SV *rv = newSV_type(SVt_RV);

    SvRV_set(rv, newSVuv(flag));
    SvROK_on(rv);
    sv_bless(rv, stash);

    sv_unmagic((SV *)hv, PERL_MAGIC_tied);
    sv_magic((SV *)hv, rv, PERL_MAGIC_tied, NULL, 0);
    SvREFCNT_dec(rv); /* As sv_magic increased it by one.  */
}

#line 45 "NamedCapture.c"
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

#line 187 "NamedCapture.c"

XS_EUPXS(XS_Tie__Hash__NamedCapture_TIEHASH); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Tie__Hash__NamedCapture_TIEHASH)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "package, ...");
    {
	const char *	package = (const char *)SvPV_nolen(ST(0))
;
#line 49 "NamedCapture.xs"
	UV flag = RXapif_ONE;
#line 200 "NamedCapture.c"
	SV *	RETVAL;
#line 51 "NamedCapture.xs"
	mark += 2;
	while(mark < sp) {
	    STRLEN len;
	    const char *p = SvPV_const(*mark, len);
	    if(memEQs(p, len, "all"))
		flag = SvTRUE(mark[1]) ? RXapif_ALL : RXapif_ONE;
	    mark += 2;
	}
	RETVAL = newSV_type(SVt_RV);
	sv_setuv(newSVrv(RETVAL, package), flag);
#line 213 "NamedCapture.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Tie__Hash__NamedCapture_FETCH); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Tie__Hash__NamedCapture_FETCH)
{
    dVAR; dXSARGS;
    dXSI32;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 74 "NamedCapture.xs"
	REGEXP *const rx = PL_curpm ? PM_GETRE(PL_curpm) : NULL;
	U32 flags;
	SV *ret;
	const U32 action = ix & ACTION_MASK;
	const int expect = ix >> EXPECT_SHIFT;
#line 236 "NamedCapture.c"
#line 80 "NamedCapture.xs"
	if (items != expect)
	    croak_xs_usage(cv, expect == 2 ? "$key"
				           : (expect == 3 ? "$key, $value"
							  : ""));

	if (!rx || !SvROK(ST(0))) {
	    if (ix & UNDEF_FATAL)
		Perl_croak_no_modify();
	    else
		XSRETURN_UNDEF;
	}

	flags = (U32)SvUV(SvRV(MUTABLE_SV(ST(0))));

	PUTBACK;
	ret = RX_ENGINE(rx)->named_buff(aTHX_ (rx), expect >= 2 ? ST(1) : NULL,
				    expect >= 3 ? ST(2) : NULL, flags | action);
	SPAGAIN;

	if (ix & DISCARD) {
	    /* Called with G_DISCARD, so our return stack state is thrown away.
	       Hence if we were returned anything, free it immediately.  */
	    SvREFCNT_dec(ret);
	} else {
	    PUSHs(ret ? sv_2mortal(ret) : &PL_sv_undef);
	}
#line 264 "NamedCapture.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Tie__Hash__NamedCapture_FIRSTKEY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Tie__Hash__NamedCapture_FIRSTKEY)
{
    dVAR; dXSARGS;
    dXSI32;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 112 "NamedCapture.xs"
	REGEXP *const rx = PL_curpm ? PM_GETRE(PL_curpm) : NULL;
	U32 flags;
	SV *ret;
	const int expect = ix ? 2 : 1;
	const U32 action = ix ? RXapif_NEXTKEY : RXapif_FIRSTKEY;
#line 286 "NamedCapture.c"
#line 118 "NamedCapture.xs"
	if (items != expect)
	    croak_xs_usage(cv, expect == 2 ? "$lastkey" : "");

	if (!rx || !SvROK(ST(0)))
	    XSRETURN_UNDEF;

	flags = (U32)SvUV(SvRV(MUTABLE_SV(ST(0))));

	PUTBACK;
	ret = RX_ENGINE(rx)->named_buff_iter(aTHX_ (rx),
					     expect >= 2 ? ST(1) : NULL,
					     flags | action);
	SPAGAIN;

	PUSHs(ret ? sv_2mortal(ret) : &PL_sv_undef);
#line 303 "NamedCapture.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Tie__Hash__NamedCapture_flags); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Tie__Hash__NamedCapture_flags)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 137 "NamedCapture.xs"
	EXTEND(SP, 2);
	mPUSHu(RXapif_ONE);
	mPUSHu(RXapif_ALL);
#line 322 "NamedCapture.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Tie__Hash__NamedCapture); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Tie__Hash__NamedCapture)
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

        newXS("Tie::Hash::NamedCapture::TIEHASH", XS_Tie__Hash__NamedCapture_TIEHASH, file);
        cv = newXS("Tie::Hash::NamedCapture::SCALAR", XS_Tie__Hash__NamedCapture_FETCH, file);
        XSANY.any_i32 = SCALAR_ALIAS;
        cv = newXS("Tie::Hash::NamedCapture::CLEAR", XS_Tie__Hash__NamedCapture_FETCH, file);
        XSANY.any_i32 = CLEAR_ALIAS;
        cv = newXS("Tie::Hash::NamedCapture::EXISTS", XS_Tie__Hash__NamedCapture_FETCH, file);
        XSANY.any_i32 = EXISTS_ALIAS;
        cv = newXS("Tie::Hash::NamedCapture::FETCH", XS_Tie__Hash__NamedCapture_FETCH, file);
        XSANY.any_i32 = FETCH_ALIAS;
        cv = newXS("Tie::Hash::NamedCapture::DELETE", XS_Tie__Hash__NamedCapture_FETCH, file);
        XSANY.any_i32 = DELETE_ALIAS;
        cv = newXS("Tie::Hash::NamedCapture::STORE", XS_Tie__Hash__NamedCapture_FETCH, file);
        XSANY.any_i32 = STORE_ALIAS;
        cv = newXS("Tie::Hash::NamedCapture::FIRSTKEY", XS_Tie__Hash__NamedCapture_FIRSTKEY, file);
        XSANY.any_i32 = 0;
        cv = newXS("Tie::Hash::NamedCapture::NEXTKEY", XS_Tie__Hash__NamedCapture_FIRSTKEY, file);
        XSANY.any_i32 = 1;
        newXS("Tie::Hash::NamedCapture::flags", XS_Tie__Hash__NamedCapture_flags, file);
    }

    /* Initialisation Section */

#line 39 "NamedCapture.xs"
	{
	    HV *const stash = GvSTASH(CvGV(cv));
	    tie_it(aTHX_ '-', RXapif_ALL, stash);
	    tie_it(aTHX_ '+', RXapif_ONE, stash);
	}

#line 380 "NamedCapture.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

