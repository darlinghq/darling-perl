#line 2 "toke.c"
#include "EXTERN.h"
#define PERL_IN_TOKE_C
#include "perl.h"
#include "dquote_static.c"
#define new_constant(a,b,c,d,e,f,g)	 	S_new_constant(aTHX_ a,b,STR_WITH_LEN(c),d,e,f, g)
#define pl_yylval	(PL_parser->yylval)
#define PL_lex_brackets		(PL_parser->lex_brackets)
#define PL_lex_allbrackets	(PL_parser->lex_allbrackets)
#define PL_lex_fakeeof		(PL_parser->lex_fakeeof)
#define PL_lex_brackstack	(PL_parser->lex_brackstack)
#define PL_lex_casemods		(PL_parser->lex_casemods)
#define PL_lex_casestack        (PL_parser->lex_casestack)
#define PL_lex_defer		(PL_parser->lex_defer)
#define PL_lex_dojoin		(PL_parser->lex_dojoin)
#define PL_lex_expect		(PL_parser->lex_expect)
#define PL_lex_formbrack        (PL_parser->lex_formbrack)
#define PL_lex_inpat		(PL_parser->lex_inpat)
#define PL_lex_inwhat		(PL_parser->lex_inwhat)
#define PL_lex_op		(PL_parser->lex_op)
#define PL_lex_repl		(PL_parser->lex_repl)
#define PL_lex_starts		(PL_parser->lex_starts)
#define PL_lex_stuff		(PL_parser->lex_stuff)
#define PL_multi_start		(PL_parser->multi_start)
#define PL_multi_open		(PL_parser->multi_open)
#define PL_multi_close		(PL_parser->multi_close)
#define PL_preambled		(PL_parser->preambled)
#define PL_sublex_info		(PL_parser->sublex_info)
#define PL_linestr		(PL_parser->linestr)
#define PL_expect		(PL_parser->expect)
#define PL_copline		(PL_parser->copline)
#define PL_bufptr		(PL_parser->bufptr)
#define PL_oldbufptr		(PL_parser->oldbufptr)
#define PL_oldoldbufptr		(PL_parser->oldoldbufptr)
#define PL_linestart		(PL_parser->linestart)
#define PL_bufend		(PL_parser->bufend)
#define PL_last_uni		(PL_parser->last_uni)
#define PL_last_lop		(PL_parser->last_lop)
#define PL_last_lop_op		(PL_parser->last_lop_op)
#define PL_lex_state		(PL_parser->lex_state)
#define PL_rsfp			(PL_parser->rsfp)
#define PL_rsfp_filters		(PL_parser->rsfp_filters)
#define PL_in_my		(PL_parser->in_my)
#define PL_in_my_stash		(PL_parser->in_my_stash)
#define PL_tokenbuf		(PL_parser->tokenbuf)
#define PL_multi_end		(PL_parser->multi_end)
#define PL_error_count		(PL_parser->error_count)
#ifdef PERL_MAD
#  define PL_endwhite		(PL_parser->endwhite)
#  define PL_faketokens		(PL_parser->faketokens)
#  define PL_lasttoke		(PL_parser->lasttoke)
#  define PL_nextwhite		(PL_parser->nextwhite)
#  define PL_realtokenstart	(PL_parser->realtokenstart)
#  define PL_skipwhite		(PL_parser->skipwhite)
#  define PL_thisclose		(PL_parser->thisclose)
#  define PL_thismad		(PL_parser->thismad)
#  define PL_thisopen		(PL_parser->thisopen)
#  define PL_thisstuff		(PL_parser->thisstuff)
#  define PL_thistoken		(PL_parser->thistoken)
#  define PL_thiswhite		(PL_parser->thiswhite)
#  define PL_thiswhite		(PL_parser->thiswhite)
#  define PL_nexttoke		(PL_parser->nexttoke)
#  define PL_curforce		(PL_parser->curforce)
#else
#  define PL_nexttoke		(PL_parser->nexttoke)
#  define PL_nexttype		(PL_parser->nexttype)
#  define PL_nextval		(PL_parser->nextval)
#endif
#ifdef PERL_MAD
#  define CURMAD(slot,sv) if (PL_madskills) { curmad(slot,sv); sv = 0; }
#  define NEXTVAL_NEXTTOKE PL_nexttoke[PL_curforce].next_val
#else
#  define CURMAD(slot,sv)
#  define NEXTVAL_NEXTTOKE PL_nextval[PL_nexttoke]
#endif
#define XENUMMASK  0x3f
#define XFAKEEOF   0x40
#define XFAKEBRACK 0x80
#ifdef USE_UTF8_SCRIPTS
#   define UTF (!IN_BYTES)
#else
#   define UTF ((PL_linestr && DO_UTF8(PL_linestr)) || ( !(PL_parser->lex_flags & LEX_IGNORE_UTF8_HINTS) && (PL_hints & HINT_UTF8)))
#endif
#define UNRECOGNIZED_PRECEDE_COUNT 10
#define isCONTROLVAR(x) (isUPPER(x) || strchr("[\\]^_?", (x)))
#define SPACE_OR_TAB(c) ((c)==' '||(c)=='\t')
#define LEX_NORMAL		10 
#define LEX_INTERPNORMAL	 9 
#define LEX_INTERPCASEMOD	 8 
#define LEX_INTERPPUSH		 7 
#define LEX_INTERPSTART		 6 
#define LEX_INTERPEND		 5 
#define LEX_INTERPENDMAYBE	 4 
#define LEX_INTERPCONCAT	 3 
#define LEX_INTERPCONST		 2 
#define LEX_FORMLINE		 1 
#define LEX_KNOWNEXT		 0 
#ifdef DEBUGGING
#endif
#ifdef ff_next
#undef ff_next
#endif
#include "keywords.h"
#ifdef CLINE
#undef CLINE
#endif
#define CLINE (PL_copline = (CopLINE(PL_curcop) < PL_copline ? CopLINE(PL_curcop) : PL_copline))
#ifdef PERL_MAD
#  define SKIPSPACE0(s) skipspace0(s)
#  define SKIPSPACE1(s) skipspace1(s)
#  define SKIPSPACE2(s,tsv) skipspace2(s,&tsv)
#  define PEEKSPACE(s) skipspace2(s,0)
#else
#  define SKIPSPACE0(s) skipspace(s)
#  define SKIPSPACE1(s) skipspace(s)
#  define SKIPSPACE2(s,tsv) skipspace(s)
#  define PEEKSPACE(s) skipspace(s)
#endif
#ifdef DEBUGGING 
#   define REPORT(retval) tokereport((I32)retval, &pl_yylval)
#else
#   define REPORT(retval) (retval)
#endif
#define TOKEN(retval) return ( PL_bufptr = s, REPORT(retval))
#define OPERATOR(retval) return (PL_expect = XTERM, PL_bufptr = s, REPORT(retval))
#define AOPERATOR(retval) return ao((PL_expect = XTERM, PL_bufptr = s, REPORT(retval)))
#define PREBLOCK(retval) return (PL_expect = XBLOCK,PL_bufptr = s, REPORT(retval))
#define PRETERMBLOCK(retval) return (PL_expect = XTERMBLOCK,PL_bufptr = s, REPORT(retval))
#define PREREF(retval) return (PL_expect = XREF,PL_bufptr = s, REPORT(retval))
#define TERM(retval) return (CLINE, PL_expect = XOPERATOR, PL_bufptr = s, REPORT(retval))
#define LOOPX(f) return (pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)LOOPEX))
#define FTST(f)  return (pl_yylval.ival=f, PL_expect=XTERMORDORDOR, PL_bufptr=s, REPORT((int)UNIOP))
#define FUN0(f)  return (pl_yylval.ival=f, PL_expect=XOPERATOR, PL_bufptr=s, REPORT((int)FUNC0))
#define FUN0OP(f)  return (pl_yylval.opval=f, CLINE, PL_expect=XOPERATOR, PL_bufptr=s, REPORT((int)FUNC0OP))
#define FUN1(f)  return (pl_yylval.ival=f, PL_expect=XOPERATOR, PL_bufptr=s, REPORT((int)FUNC1))
#define BOop(f)  return ao((pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)BITOROP)))
#define BAop(f)  return ao((pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)BITANDOP)))
#define SHop(f)  return ao((pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)SHIFTOP)))
#define PWop(f)  return ao((pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)POWOP)))
#define PMop(f)  return(pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)MATCHOP))
#define Aop(f)   return ao((pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)ADDOP)))
#define Mop(f)   return ao((pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)MULOP)))
#define Eop(f)   return (pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)EQOP))
#define Rop(f)   return (pl_yylval.ival=f, PL_expect=XTERM, PL_bufptr=s, REPORT((int)RELOP))
#define UNI3(f,x,have_x) {  	pl_yylval.ival = f;  	if (have_x) PL_expect = x;  	PL_bufptr = s;  	PL_last_uni = PL_oldbufptr;  	PL_last_lop_op = f;  	if (*s == '(')  	    return REPORT( (int)FUNC1 );  	s = PEEKSPACE(s);  	return REPORT( *s=='(' ? (int)FUNC1 : (int)UNIOP );  	}
#define UNI(f)    UNI3(f,XTERM,1)
#define UNIDOR(f) UNI3(f,XTERMORDORDOR,1)
#define UNIPROTO(f,optional) {  	if (optional) PL_last_uni = PL_oldbufptr;  	OPERATOR(f);  	}
#define UNIBRACK(f) UNI3(f,0,0)
#define OLDLOP(f)  	do {  	    if (!PL_lex_allbrackets && PL_lex_fakeeof > LEX_FAKEEOF_LOWLOGIC)  		PL_lex_fakeeof = LEX_FAKEEOF_LOWLOGIC;  	    pl_yylval.ival = (f);  	    PL_expect = XTERM;  	    PL_bufptr = s;  	    return (int)LSTOP;  	} while(0)
#define COPLINE_INC_WITH_HERELINES		         STMT_START {				      	CopLINE_inc(PL_curcop);			       	if (PL_parser->lex_shared->herelines)	        	    CopLINE(PL_curcop) += PL_parser->lex_shared->herelines,  	    PL_parser->lex_shared->herelines = 0;		          } STMT_END
#ifdef DEBUGGING
#endif
#include "feature.h"
#ifdef PERL_CR_FILTER
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#define LEX_FAKE_EOF 0x80000000
#define LEX_NO_TERM  0x40000000
#ifdef PERL_MAD
#endif
#define LEX_NO_NEXT_CHUNK 0x80000000
#ifdef PERL_MAD
#endif 
#ifdef PERL_MAD
#endif 
#ifdef PERL_MAD
#endif 
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif 
#ifdef PERL_MAD
#endif 
#ifdef PERL_MAD
#endif 
#define LOP(f,x) return lop(f,x,s)
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#  define start_force(where)    NOOP
#  define curmad(slot, sv)      NOOP
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef USE_LOCALE_NUMERIC
#endif
#ifdef USE_LOCALE_NUMERIC
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#else
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#else
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef EBCDIC
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_MICRO
#else
#endif
#ifdef PERL_CR_FILTER
#endif
#ifdef PERL_MAD 
#endif
#ifdef DEBUGGING
#endif
#define word_takes_any_delimeter(p,l) S_word_takes_any_delimeter(p,l)
#ifdef __SC__
#pragma segment Perl_yylex
#endif
#ifdef COMMENTARY
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#if defined(PERLIO_USING_CRLF) && defined(PERL_TEXTMODE_SCRIPTS)
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef ALTERNATE_SHEBANG
#endif 
#ifdef ARG_ZERO_IS_SCRIPT
#endif 
#if defined(DOSISH)
#endif
#ifdef ALTERNATE_SHEBANG
#endif 
#ifdef PERL_STRICT_CR
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#if 0
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_STRICT_CR
#else
#endif
#ifdef PERL_STRICT_CR
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#if defined(HAS_FCNTL) && defined(F_SETFD)
#endif
#if defined(WIN32) && !defined(PERL_TEXTMODE_SCRIPTS)
#ifdef NETWARE
#else
#endif	
#endif
#ifdef PERLIO_LAYERS
#endif
#ifdef PERL_MAD
#endif
#ifdef FCRYPT
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifdef PERL_MAD
#else
#endif
#ifndef PERL_MAD
#endif
#ifdef EBCDIC
#else
#endif
#ifdef __SC__
#pragma segment Main
#endif
#define VALID_LEN_ONE_IDENT(d, u)     (isPUNCT_A((U8)*(d))                                              || isCNTRL_A((U8)*(d))                                          || isDIGIT_A((U8)*(d))                                          || (!(u) && !UTF8_IS_INVARIANT((U8)*(d))))
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifndef PERL_STRICT_CR
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifndef PERL_STRICT_CR
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifndef PERL_STRICT_CR
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#if UVSIZE > 4
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_STRICT_CR
#else
#endif
#ifndef PERL_STRICT_CR
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef PERL_MAD
#endif
#ifdef __SC__
#pragma segment Perl_yylex
#endif
#ifndef NETWARE
#endif
#ifndef NETWARE
#endif
#ifdef __SC__
#pragma segment Main
#endif
#ifndef PERL_NO_UTF16_FILTER
#else
#endif
#ifndef PERL_NO_UTF16_FILTER
#else
#endif
#ifndef PERL_NO_UTF16_FILTER
#else
#endif
#ifdef EBCDIC
#endif
#ifndef PERL_NO_UTF16_FILTER
#else
#endif
#ifndef PERL_NO_UTF16_FILTER
#endif
#ifdef EBCDIC
#endif
#define parse_recdescent(g,p) S_parse_recdescent(aTHX_ g,p)
#define parse_recdescent_for_op(g,p) S_parse_recdescent_for_op(aTHX_ g,p)
#define parse_expr(p,f) S_parse_expr(aTHX_ p,f)
