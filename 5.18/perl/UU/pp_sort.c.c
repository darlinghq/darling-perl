#line 2 "pp_sort.c"
#include "EXTERN.h"
#define PERL_IN_PP_SORT_C
#include "perl.h"
#if defined(UNDER_CE)
#define	small xsmall
#endif
#define sv_cmp_static Perl_sv_cmp
#define sv_cmp_locale_static Perl_sv_cmp_locale
#ifndef SMALLSORT
#define	SMALLSORT (200)
#endif
#define SORTf_DESC   1
#define SORTf_STABLE 2
#define SORTf_QSORT  4
#define	APTR(P)	((aptr)(P))
#define	GPTP(P)	((gptr *)(P))
#define GPPP(P) ((gptr **)(P))
#define	BYTEOFF(P, Q) (APTR(Q) - APTR(P))
#define PSIZE sizeof(gptr)
#ifdef	PSHIFT
#define	PNELEM(P, Q)	(BYTEOFF(P,Q) >> (PSHIFT))
#define	PNBYTE(N)	((N) << (PSHIFT))
#define	PINDEX(P, N)	(GPTP(APTR(P) + PNBYTE(N)))
#else
#define	PNELEM(P, Q)	(GPTP(Q) - GPTP(P))
#define	PNBYTE(N)	((N) * (PSIZE))
#define	PINDEX(P, N)	(GPTP(P) + (N))
#endif
#define	POTHER(P, THIS, OTHER) GPTP(APTR(OTHER) + BYTEOFF(THIS,P))
#define FROMTOUPTO(src, dst, lim) do *dst++ = *src++; while(src<lim)
#define	NEXT(P)		(*GPPP(P))
#define	PTHRESH (8)
#define RTHRESH (6)
#ifndef QSORT_ORDER_GUESS
#define QSORT_ORDER_GUESS 2	
#endif
#ifndef QSORT_MAX_STACK
#define QSORT_MAX_STACK 32
#endif
#ifndef QSORT_BREAK_EVEN
#define QSORT_BREAK_EVEN 6
#endif
#ifndef QSORT_PLAY_SAFE
#define QSORT_PLAY_SAFE 255
#endif
#ifdef QSORT_ORDER_GUESS
#endif
#define qsort_cmp(elt1, elt2)     ((*compare)(aTHX_ array[elt1], array[elt2]))
#ifdef QSORT_ORDER_GUESS
#define QSORT_NOTICE_SWAP swapped++;
#else
#define QSORT_NOTICE_SWAP
#endif
#define qsort_swap(elt1, elt2)     STMT_START {        QSORT_NOTICE_SWAP        temp = array[elt1];        array[elt1] = array[elt2];        array[elt2] = temp;     } STMT_END
#define qsort_rotate(elt1, elt2, elt3)     STMT_START {        QSORT_NOTICE_SWAP        temp = array[elt1];        array[elt1] = array[elt2];        array[elt2] = array[elt3];        array[elt3] = temp;     } STMT_END
#ifdef QSORT_DEBUG
#define qsort_assert(t) (void)( (t) || (break_here(), 0) )
#define qsort_all_asserts(PC_LEFT, PC_RIGHT, U_LEFT, U_RIGHT)     doqsort_all_asserts(array, num_elts, elt_size, compare,                   PC_LEFT, PC_RIGHT, U_LEFT, U_RIGHT)
#else
#define qsort_assert(t) ((void)0)
#define qsort_all_asserts(PC_LEFT, PC_RIGHT, U_LEFT, U_RIGHT) ((void)0)
#endif
#ifdef QSORT_ORDER_GUESS
#endif
#ifdef QSORT_ORDER_GUESS
#else
#define qsort_break_even QSORT_BREAK_EVEN
#endif
#ifdef QSORT_ORDER_GUESS
#endif
#ifdef QSORT_ORDER_GUESS
#if QSORT_ORDER_GUESS == 1
#endif
#if QSORT_ORDER_GUESS == 2
#endif
#if QSORT_ORDER_GUESS == 3
#endif
#endif
#ifdef QSORT_ORDER_GUESS
#endif
#ifdef QSORT_ORDER_GUESS
#endif
#ifdef QSORT_ORDER_GUESS
#endif
#ifdef QSORT_ORDER_GUESS
#endif
#define SvNSIOK(sv) ((SvFLAGS(sv) & SVf_NOK) || ((SvFLAGS(sv) & (SVf_IOK|SVf_IVisUV)) == SVf_IOK))
#define SvSIOK(sv) ((SvFLAGS(sv) & (SVf_IOK|SVf_IVisUV)) == SVf_IOK)
#define SvNSIV(sv) ( SvNOK(sv) ? SvNVX(sv) : ( SvSIOK(sv) ? SvIVX(sv) : sv_2nv(sv) ) )
#if defined(NAN_COMPARE_BROKEN) && defined(Perl_isnan)
#else
#endif
#define tryCALL_AMAGICbin(left,right,meth)      (SvAMAGIC(left)||SvAMAGIC(right))  	? amagic_call(left, right, meth, 0)  	: NULL;
#define SORT_NORMAL_RETURN_VALUE(val)  (((val) > 0) ? 1 : ((val) ? -1 : 0))
