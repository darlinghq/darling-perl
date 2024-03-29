/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of scalar.xs. Do not edit this file, edit scalar.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "scalar.xs"
#define PERL_NO_GET_CONTEXT
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#ifdef PERLIO_LAYERS

#include "perliol.h"

static const char code_point_warning[] =
 "Strings with code points over 0xFF may not be mapped into in-memory file handles\n";

typedef struct {
    struct _PerlIO base;	/* Base "class" info */
    SV *var;
    Off_t posn;
} PerlIOScalar;

IV
PerlIOScalar_pushed(pTHX_ PerlIO * f, const char *mode, SV * arg,
		    PerlIO_funcs * tab)
{
    IV code;
    PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
    /* If called (normally) via open() then arg is ref to scalar we are
     * using, otherwise arg (from binmode presumably) is either NULL
     * or the _name_ of the scalar
     */
    if (arg && SvOK(arg)) {
	if (SvROK(arg)) {
	    if (SvREADONLY(SvRV(arg)) && !SvIsCOW(SvRV(arg))
	     && mode && *mode != 'r') {
		if (ckWARN(WARN_LAYER))
		    Perl_warner(aTHX_ packWARN(WARN_LAYER), "%s", PL_no_modify);
		SETERRNO(EINVAL, SS_IVCHAN);
		return -1;
	    }
	    s->var = SvREFCNT_inc(SvRV(arg));
	    SvGETMAGIC(s->var);
	    if (!SvPOK(s->var) && SvOK(s->var))
		(void)SvPV_nomg_const_nolen(s->var);
	}
	else {
	    s->var =
		SvREFCNT_inc(perl_get_sv
			     (SvPV_nolen(arg), GV_ADD | GV_ADDMULTI));
	}
    }
    else {
	s->var = newSVpvn("", 0);
    }
    SvUPGRADE(s->var, SVt_PV);
    code = PerlIOBase_pushed(aTHX_ f, mode, Nullsv, tab);
    if (!SvOK(s->var) || (PerlIOBase(f)->flags) & PERLIO_F_TRUNCATE)
    {
	sv_force_normal(s->var);
	SvCUR_set(s->var, 0);
    }
    if (SvUTF8(s->var) && !sv_utf8_downgrade(s->var, TRUE)) {
	if (ckWARN(WARN_UTF8))
	    Perl_warner(aTHX_ packWARN(WARN_UTF8), code_point_warning);
	SETERRNO(EINVAL, SS_IVCHAN);
	SvREFCNT_dec(s->var);
	s->var = Nullsv;
	return -1;
    }
    if ((PerlIOBase(f)->flags) & PERLIO_F_APPEND)
    {
	sv_force_normal(s->var);
	s->posn = SvCUR(s->var);
    }
    else
	s->posn = 0;
    SvSETMAGIC(s->var);
    return code;
}

IV
PerlIOScalar_popped(pTHX_ PerlIO * f)
{
    PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
    if (s->var) {
	SvREFCNT_dec(s->var);
	s->var = Nullsv;
    }
    return 0;
}

IV
PerlIOScalar_close(pTHX_ PerlIO * f)
{
    IV code = PerlIOBase_close(aTHX_ f);
    PerlIOBase(f)->flags &= ~(PERLIO_F_RDBUF | PERLIO_F_WRBUF);
    return code;
}

IV
PerlIOScalar_fileno(pTHX_ PerlIO * f)
{
    PERL_UNUSED_ARG(f);
    return -1;
}

IV
PerlIOScalar_seek(pTHX_ PerlIO * f, Off_t offset, int whence)
{
    PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);

    switch (whence) {
    case SEEK_SET:
	s->posn = offset;
	break;
    case SEEK_CUR:
	s->posn = offset + s->posn;
	break;
    case SEEK_END:
      {
	STRLEN oldcur;
	(void)SvPV(s->var, oldcur);
	s->posn = offset + oldcur;
	break;
      }
    }
    if (s->posn < 0) {
        if (ckWARN(WARN_LAYER))
	    Perl_warner(aTHX_ packWARN(WARN_LAYER), "Offset outside string");
	SETERRNO(EINVAL, SS_IVCHAN);
	return -1;
    }
    return 0;
}

Off_t
PerlIOScalar_tell(pTHX_ PerlIO * f)
{
    PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
    return s->posn;
}


SSize_t
PerlIOScalar_read(pTHX_ PerlIO *f, void *vbuf, Size_t count)
{
    if (!f)
	return 0;
    if (!(PerlIOBase(f)->flags & PERLIO_F_CANREAD)) {
	PerlIOBase(f)->flags |= PERLIO_F_ERROR;
	SETERRNO(EBADF, SS_IVCHAN);
	return 0;
    }
    {
	PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
	SV *sv = s->var;
	char *p;
	STRLEN len;
	I32 got;
	p = SvPV(sv, len);
	if (SvUTF8(sv)) {
	    if (sv_utf8_downgrade(sv, TRUE)) {
	        p = SvPV_nomg(sv, len);
	    }
	    else {
	        if (ckWARN(WARN_UTF8))
		    Perl_warner(aTHX_ packWARN(WARN_UTF8), code_point_warning);
	        SETERRNO(EINVAL, SS_IVCHAN);
	        return -1;
	    }
	}
	got = len - (STRLEN)(s->posn);
	if (got <= 0)
	    return 0;
	if ((STRLEN)got > (STRLEN)count)
	    got = (STRLEN)count;
	Copy(p + (STRLEN)(s->posn), vbuf, got, STDCHAR);
	s->posn += (Off_t)got;
	return (SSize_t)got;
    }
}

SSize_t
PerlIOScalar_write(pTHX_ PerlIO * f, const void *vbuf, Size_t count)
{
    if (PerlIOBase(f)->flags & PERLIO_F_CANWRITE) {
	Off_t offset;
	PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
	SV *sv = s->var;
	char *dst;
	SvGETMAGIC(sv);
	if (!SvROK(sv)) sv_force_normal(sv);
	if (SvOK(sv)) SvPV_force_nomg_nolen(sv);
	if (SvUTF8(sv) && !sv_utf8_downgrade(sv, TRUE)) {
	    if (ckWARN(WARN_UTF8))
	        Perl_warner(aTHX_ packWARN(WARN_UTF8), code_point_warning);
	    SETERRNO(EINVAL, SS_IVCHAN);
	    return 0;
	}
	if ((PerlIOBase(f)->flags) & PERLIO_F_APPEND) {
	    dst = SvGROW(sv, SvCUR(sv) + count + 1);
	    offset = SvCUR(sv);
	    s->posn = offset + count;
	}
	else {
	    STRLEN const cur = SvCUR(sv);
	    if (s->posn > cur) {
		dst = SvGROW(sv, (STRLEN)s->posn + count + 1);
		Zero(SvPVX(sv) + cur, (STRLEN)s->posn - cur, char);
	    }
	    else if ((s->posn + count) >= cur)
		dst = SvGROW(sv, (STRLEN)s->posn + count + 1);
	    else
		dst = SvPVX(sv);
	    offset = s->posn;
	    s->posn += count;
	}
	Move(vbuf, dst + offset, count, char);
	if ((STRLEN) s->posn > SvCUR(sv)) {
	    SvCUR_set(sv, (STRLEN)s->posn);
	    dst[(STRLEN) s->posn] = 0;
	}
	SvPOK_on(sv);
	SvSETMAGIC(sv);
	return count;
    }
    else
	return 0;
}

IV
PerlIOScalar_fill(pTHX_ PerlIO * f)
{
    PERL_UNUSED_ARG(f);
    return -1;
}

IV
PerlIOScalar_flush(pTHX_ PerlIO * f)
{
    PERL_UNUSED_ARG(f);
    return 0;
}

STDCHAR *
PerlIOScalar_get_base(pTHX_ PerlIO * f)
{
    PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
    if (PerlIOBase(f)->flags & PERLIO_F_CANREAD) {
	SvGETMAGIC(s->var);
	return (STDCHAR *) SvPV_nolen(s->var);
    }
    return (STDCHAR *) NULL;
}

STDCHAR *
PerlIOScalar_get_ptr(pTHX_ PerlIO * f)
{
    if (PerlIOBase(f)->flags & PERLIO_F_CANREAD) {
	PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
	return PerlIOScalar_get_base(aTHX_ f) + s->posn;
    }
    return (STDCHAR *) NULL;
}

SSize_t
PerlIOScalar_get_cnt(pTHX_ PerlIO * f)
{
    if (PerlIOBase(f)->flags & PERLIO_F_CANREAD) {
	PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
	STRLEN len;
	SvGETMAGIC(s->var);
	if (isGV_with_GP(s->var))
	    (void)SvPV(s->var,len);
	else len = SvCUR(s->var);
	if (len > (STRLEN) s->posn)
	    return len - (STRLEN)s->posn;
	else
	    return 0;
    }
    return 0;
}

Size_t
PerlIOScalar_bufsiz(pTHX_ PerlIO * f)
{
    if (PerlIOBase(f)->flags & PERLIO_F_CANREAD) {
	PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
	SvGETMAGIC(s->var);
	return SvCUR(s->var);
    }
    return 0;
}

void
PerlIOScalar_set_ptrcnt(pTHX_ PerlIO * f, STDCHAR * ptr, SSize_t cnt)
{
    PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
    STRLEN len;
    PERL_UNUSED_ARG(ptr);
    SvGETMAGIC(s->var);
    if (isGV_with_GP(s->var)) (void)SvPV(s->var,len);
    else len = SvCUR(s->var);
    s->posn = len - cnt;
}

PerlIO *
PerlIOScalar_open(pTHX_ PerlIO_funcs * self, PerlIO_list_t * layers, IV n,
		  const char *mode, int fd, int imode, int perm,
		  PerlIO * f, int narg, SV ** args)
{
    SV *arg = (narg > 0) ? *args : PerlIOArg;
    PERL_UNUSED_ARG(fd);
    PERL_UNUSED_ARG(imode);
    PERL_UNUSED_ARG(perm);
    if (SvROK(arg) || SvPOK(arg)) {
	if (!f) {
	    f = PerlIO_allocate(aTHX);
	}
	if ( (f = PerlIO_push(aTHX_ f, self, mode, arg)) ) {
	    PerlIOBase(f)->flags |= PERLIO_F_OPEN;
	}
	return f;
    }
    return NULL;
}

SV *
PerlIOScalar_arg(pTHX_ PerlIO * f, CLONE_PARAMS * param, int flags)
{
    PerlIOScalar *s = PerlIOSelf(f, PerlIOScalar);
    SV *var = s->var;
    if (flags & PERLIO_DUP_CLONE)
	var = PerlIO_sv_dup(aTHX_ var, param);
    else if (flags & PERLIO_DUP_FD) {
	/* Equivalent (guesses NI-S) of dup() is to create a new scalar */
	var = newSVsv(var);
    }
    else {
	var = SvREFCNT_inc(var);
    }
    return newRV_noinc(var);
}

PerlIO *
PerlIOScalar_dup(pTHX_ PerlIO * f, PerlIO * o, CLONE_PARAMS * param,
		 int flags)
{
    /* Duplication causes the scalar layer to be pushed on to clone, caus-
       ing the cloned scalar to be set to the empty string by
       PerlIOScalar_pushed.  So set aside our scalar temporarily. */
    PerlIOScalar * const os = PerlIOSelf(o, PerlIOScalar);
    PerlIOScalar *fs;
    SV * const var = os->var;
    os->var = newSVpvs("");
    if ((f = PerlIOBase_dup(aTHX_ f, o, param, flags))) {
	fs = PerlIOSelf(f, PerlIOScalar);
	/* var has been set by implicit push, so replace it */
	SvREFCNT_dec(fs->var);
    }
    SvREFCNT_dec(os->var);
    os->var = var;
    if (f) {
	SV * const rv = PerlIOScalar_arg(aTHX_ o, param, flags);
	fs->var = SvREFCNT_inc(SvRV(rv));
	SvREFCNT_dec(rv);
	fs->posn = os->posn;
    }
    return f;
}

PERLIO_FUNCS_DECL(PerlIO_scalar) = {
    sizeof(PerlIO_funcs),
    "scalar",
    sizeof(PerlIOScalar),
    PERLIO_K_BUFFERED | PERLIO_K_RAW,
    PerlIOScalar_pushed,
    PerlIOScalar_popped,
    PerlIOScalar_open,
    PerlIOBase_binmode,
    PerlIOScalar_arg,
    PerlIOScalar_fileno,
    PerlIOScalar_dup,
    PerlIOScalar_read,
    NULL, /* unread */
    PerlIOScalar_write,
    PerlIOScalar_seek,
    PerlIOScalar_tell,
    PerlIOScalar_close,
    PerlIOScalar_flush,
    PerlIOScalar_fill,
    PerlIOBase_eof,
    PerlIOBase_error,
    PerlIOBase_clearerr,
    PerlIOBase_setlinebuf,
    PerlIOScalar_get_base,
    PerlIOScalar_bufsiz,
    PerlIOScalar_get_ptr,
    PerlIOScalar_get_cnt,
    PerlIOScalar_set_ptrcnt,
};


#endif /* Layers available */

#line 412 "scalar.c"
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

#line 554 "scalar.c"
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_PerlIO__scalar); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_PerlIO__scalar)
{
    dVAR; dXSARGS;

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;


    /* Initialisation Section */

#line 407 "scalar.xs"
{
#ifdef PERLIO_LAYERS
 PerlIO_define_layer(aTHX_ PERLIO_FUNCS_CAST(&PerlIO_scalar));
#endif
}

#line 580 "scalar.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

