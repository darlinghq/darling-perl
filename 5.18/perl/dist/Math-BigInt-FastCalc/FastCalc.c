/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of FastCalc.xs. Do not edit this file, edit FastCalc.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "FastCalc.xs"
#define PERL_NO_GET_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* for Perl prior to v5.7.1 */
#ifndef SvUOK
#  define SvUOK(sv) SvIOK_UV(sv)
#endif

/* for Perl v5.6 (RT #63859) */
#ifndef croak_xs_usage
# define croak_xs_usage croak
#endif

double XS_BASE = 0;
double XS_BASE_LEN = 0;

#line 30 "FastCalc.c"
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

#line 172 "FastCalc.c"
#define RETURN_MORTAL_INT(value)		\
      ST(0) = sv_2mortal(newSViv(value));	\
      XSRETURN(1);

XS_EUPXS(XS_Math__BigInt__FastCalc__new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__new)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1)
;
	SV *	RETVAL;
#line 59 "FastCalc.xs"
    STRLEN len;
    char* cur;
    STRLEN part_len;
    AV *av = newAV();

#line 193 "FastCalc.c"
#line 65 "FastCalc.xs"
    if (SvUOK(x) && SvUV(x) < XS_BASE)
      {
      /* shortcut for integer arguments */
      av_push (av, newSVuv( SvUV(x) ));
      }
    else
      {
      /* split the input (as string) into XS_BASE_LEN long parts */
      /* in perl:
		[ reverse(unpack("a" . ($il % $BASE_LEN+1)
		. ("a$BASE_LEN" x ($il / $BASE_LEN)), $_[1])) ];
      */
      cur = SvPV(x, len);			/* convert to string & store length */
      cur += len;				/* doing "cur = SvEND(x)" does not work! */
      while (len > 0)
        {
        /* use either BASE_LEN or the amount of remaining digits */
        part_len = (STRLEN) XS_BASE_LEN;
        if (part_len > len)
          {
          part_len = len;
          }
        /* processed so many digits */
        cur -= part_len;
        len -= part_len;
        /* printf ("part '%s' (part_len: %i, len: %i, BASE_LEN: %i)\n", cur, part_len, len, XS_BASE_LEN); */
        if (part_len > 0)
	  {
	  av_push (av, newSVpvn(cur, part_len) );
	  }
        }
      }
    RETVAL = newRV_noinc((SV *)av);
#line 228 "FastCalc.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__copy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__copy)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1)
;
#line 109 "FastCalc.xs"
    AV*	a;
    AV*	a2;
    I32	elems;

#line 250 "FastCalc.c"
#line 114 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    a2 = (AV*)sv_2mortal((SV*)newAV());
    av_extend (a2, elems);		/* pre-padd */
    while (elems >= 0)
      {
      /* av_store( a2,  elems, newSVsv( (SV*)*av_fetch(a, elems, 0) ) ); */

      /* looking and trying to preserve IV is actually slower when copying */
      /* temp = (SV*)*av_fetch(a, elems, 0);
      if (SvIOK(temp))
        {
        av_store( a2,  elems, newSViv( SvIV( (SV*)*av_fetch(a, elems, 0) )));
        }
      else
        {
        av_store( a2,  elems, newSVnv( SvNV( (SV*)*av_fetch(a, elems, 0) )));
        }
      */
      av_store( a2,  elems, newSVnv( SvNV( (SV*)*av_fetch(a, elems, 0) )));
      elems--;
      }
    ST(0) = sv_2mortal( newRV_inc((SV*) a2) );
#line 275 "FastCalc.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc___strip_zeros); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc___strip_zeros)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "x");
    {
	SV*	x = ST(0)
;
#line 145 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    I32	elems;
    I32	index;

#line 296 "FastCalc.c"
#line 151 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    ST(0) = x;				/* we return x */
    if (elems == -1)
      { 
      av_push (a, newSViv(0));		/* correct empty arrays */
      XSRETURN(1);
      }
    if (elems == 0)
      {
      XSRETURN(1);			/* nothing to do since only one elem */
      }
    index = elems;
    while (index > 0)
      {
      temp = *av_fetch(a, index, 0);	/* fetch ptr to current element */
      if (SvNV(temp) != 0)
        {
        break;
        }
      index--;
      }
    if (index < elems)
      {
      index = elems - index;
      while (index-- > 0)
        {
        av_pop (a);
        }
      }
    XSRETURN(1);
#line 329 "FastCalc.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__dec); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__dec)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1)
;
#line 190 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    I32	elems;
    I32	index;
    NV	MAX;

#line 351 "FastCalc.c"
#line 197 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    ST(0) = x;				/* we return x */

    MAX = XS_BASE - 1;
    index = 0;
    while (index <= elems)
      {
      temp = *av_fetch(a, index, 0);	/* fetch ptr to current element */
      sv_setnv (temp, SvNV(temp)-1);	/* decrement */
      if (SvNV(temp) >= 0)
        {
        break;				/* early out */
        }
      sv_setnv (temp, MAX);		/* overflow, so set this to $MAX */
      index++;
      } 
    /* do have more than one element? */
    /* (more than one because [0] should be kept as single-element) */
    if (elems > 0)
      {
      temp = *av_fetch(a, elems, 0);	/* fetch last element */
      if (SvIV(temp) == 0)		/* did last elem overflow? */ 
        {
        av_pop(a);			/* yes, so shrink array */
        				/* aka remove leading zeros */
        }
      }
    XSRETURN(1);			/* return x */
#line 382 "FastCalc.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__inc); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__inc)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1)
;
#line 234 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    I32	elems;
    I32	index;
    NV	BASE;

#line 404 "FastCalc.c"
#line 241 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    ST(0) = x;				/* we return x */

    BASE = XS_BASE;
    index = 0;
    while (index <= elems)
      {
      temp = *av_fetch(a, index, 0);	/* fetch ptr to current element */
      sv_setnv (temp, SvNV(temp)+1);
      if (SvNV(temp) < BASE)
        {
        XSRETURN(1);			/* return (early out) */
        }
      sv_setiv (temp, 0);		/* overflow, so set this elem to 0 */
      index++;
      } 
    temp = *av_fetch(a, elems, 0);	/* fetch last element */
    if (SvIV(temp) == 0)		/* did last elem overflow? */
      {
      av_push(a, newSViv(1));		/* yes, so extend array by 1 */
      }
    XSRETURN(1);			/* return x */
#line 429 "FastCalc.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__zero); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__zero)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
#line 274 "FastCalc.xs"
    AV *av = newAV();
#line 445 "FastCalc.c"
	SV *	RETVAL;
#line 276 "FastCalc.xs"
    av_push (av, newSViv( ix ));
    RETVAL = newRV_noinc((SV *)av);
#line 450 "FastCalc.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__is_even); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__is_even)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1)
;
#line 289 "FastCalc.xs"
    AV*	a;
    SV*	temp;

#line 472 "FastCalc.c"
#line 293 "FastCalc.xs"
    a = (AV*)SvRV(x);		/* ref to aray, don't check ref */
    temp = *av_fetch(a, 0, 0);	/* fetch first element */
    ST(0) = sv_2mortal(boolSV((SvIV(temp) & 1) == ix));
#line 477 "FastCalc.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__is_zero); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__is_zero)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1)
;
#line 307 "FastCalc.xs"
    AV*	a;

#line 496 "FastCalc.c"
#line 310 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    if ( av_len(a) != 0)
      {
      ST(0) = &PL_sv_no;		/* len != 1, can't be '0' */
      }
    else
      {
      SV *const temp = *av_fetch(a, 0, 0);	/* fetch first element */
      ST(0) = boolSV(SvIV(temp) == ix);
      }
    XSRETURN(1);
#line 509 "FastCalc.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__len); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__len)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, x");
    {
	SV*	x = ST(1)
;
#line 328 "FastCalc.xs"
    AV*	a;
    SV*	temp;
    IV	elems;
    STRLEN len;

#line 530 "FastCalc.c"
#line 334 "FastCalc.xs"
    a = (AV*)SvRV(x);			/* ref to aray, don't check ref */
    elems = av_len(a);			/* number of elems in array */
    temp = *av_fetch(a, elems, 0);	/* fetch last element */
    SvPV(temp, len);			/* convert to string & store length */
    len += (IV) XS_BASE_LEN * elems;
    ST(0) = sv_2mortal(newSViv(len));
#line 538 "FastCalc.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Math__BigInt__FastCalc__acmp); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Math__BigInt__FastCalc__acmp)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "class, cx, cy");
    {
	SV*	cx = ST(1)
;
	SV*	cy = ST(2)
;
#line 348 "FastCalc.xs"
    AV* array_x;
    AV* array_y;
    I32 elemsx, elemsy, diff;
    SV* tempx;
    SV* tempy;
    STRLEN lenx;
    STRLEN leny;
    NV diff_nv;
    I32 diff_str;

#line 566 "FastCalc.c"
#line 359 "FastCalc.xs"
    array_x = (AV*)SvRV(cx);		/* ref to aray, don't check ref */
    array_y = (AV*)SvRV(cy);		/* ref to aray, don't check ref */
    elemsx =  av_len(array_x);
    elemsy =  av_len(array_y);
    diff = elemsx - elemsy;		/* difference */

    if (diff > 0)
      {
      RETURN_MORTAL_INT(1);		/* len differs: X > Y */
      }
    else if (diff < 0)
      {
      RETURN_MORTAL_INT(-1);		/* len differs: X < Y */
      }
    /* both have same number of elements, so check length of last element
       and see if it differs */
    tempx = *av_fetch(array_x, elemsx, 0);	/* fetch last element */
    tempy = *av_fetch(array_y, elemsx, 0);	/* fetch last element */
    SvPV(tempx, lenx);			/* convert to string & store length */
    SvPV(tempy, leny);			/* convert to string & store length */
    diff_str = (I32)lenx - (I32)leny;
    if (diff_str > 0)
      {
      RETURN_MORTAL_INT(1);		/* same len, but first elems differs in len */
      }
    if (diff_str < 0)
      {
      RETURN_MORTAL_INT(-1);		/* same len, but first elems differs in len */
      }
    /* same number of digits, so need to make a full compare */
    diff_nv = 0;
    while (elemsx >= 0)
      {
      tempx = *av_fetch(array_x, elemsx, 0);	/* fetch curr x element */
      tempy = *av_fetch(array_y, elemsx, 0);	/* fetch curr y element */
      diff_nv = SvNV(tempx) - SvNV(tempy);
      if (diff_nv != 0)
        {
        break; 
        }
      elemsx--;
      } 
    if (diff_nv > 0)
      {
      RETURN_MORTAL_INT(1);
      }
    if (diff_nv < 0)
      {
      RETURN_MORTAL_INT(-1);
      }
    ST(0) = sv_2mortal(newSViv(0));		/* X and Y are equal */
#line 619 "FastCalc.c"
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Math__BigInt__FastCalc); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Math__BigInt__FastCalc)
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

        newXS("Math::BigInt::FastCalc::_new", XS_Math__BigInt__FastCalc__new, file);
        newXS("Math::BigInt::FastCalc::_copy", XS_Math__BigInt__FastCalc__copy, file);
        newXS("Math::BigInt::FastCalc::__strip_zeros", XS_Math__BigInt__FastCalc___strip_zeros, file);
        newXS("Math::BigInt::FastCalc::_dec", XS_Math__BigInt__FastCalc__dec, file);
        newXS("Math::BigInt::FastCalc::_inc", XS_Math__BigInt__FastCalc__inc, file);
        cv = newXS("Math::BigInt::FastCalc::_ten", XS_Math__BigInt__FastCalc__zero, file);
        XSANY.any_i32 = 10;
        cv = newXS("Math::BigInt::FastCalc::_two", XS_Math__BigInt__FastCalc__zero, file);
        XSANY.any_i32 = 2;
        cv = newXS("Math::BigInt::FastCalc::_zero", XS_Math__BigInt__FastCalc__zero, file);
        XSANY.any_i32 = 0;
        cv = newXS("Math::BigInt::FastCalc::_one", XS_Math__BigInt__FastCalc__zero, file);
        XSANY.any_i32 = 1;
        cv = newXS("Math::BigInt::FastCalc::_is_even", XS_Math__BigInt__FastCalc__is_even, file);
        XSANY.any_i32 = 0;
        cv = newXS("Math::BigInt::FastCalc::_is_odd", XS_Math__BigInt__FastCalc__is_even, file);
        XSANY.any_i32 = 1;
        cv = newXS("Math::BigInt::FastCalc::_is_ten", XS_Math__BigInt__FastCalc__is_zero, file);
        XSANY.any_i32 = 10;
        cv = newXS("Math::BigInt::FastCalc::_is_one", XS_Math__BigInt__FastCalc__is_zero, file);
        XSANY.any_i32 = 1;
        cv = newXS("Math::BigInt::FastCalc::_is_two", XS_Math__BigInt__FastCalc__is_zero, file);
        XSANY.any_i32 = 2;
        cv = newXS("Math::BigInt::FastCalc::_is_zero", XS_Math__BigInt__FastCalc__is_zero, file);
        XSANY.any_i32 = 0;
        newXS("Math::BigInt::FastCalc::_len", XS_Math__BigInt__FastCalc__len, file);
        newXS("Math::BigInt::FastCalc::_acmp", XS_Math__BigInt__FastCalc__acmp, file);
    }

    /* Initialisation Section */

#line 45 "FastCalc.xs"
{
    if (items < 4)
	croak("Usage: Math::BigInt::FastCalc::BOOT(package, version, base_len, base)");
    XS_BASE_LEN = SvIV(ST(2));
    XS_BASE = SvNV(ST(3));
}

#line 686 "FastCalc.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

