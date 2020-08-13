#line 2 "regexec.c"
#ifdef PERL_EXT_RE_BUILD
#include "re_top.h"
#endif
#define NON_UTF8_TARGET_BUT_UTF8_REQUIRED(target) STMT_START {      DEBUG_EXECUTE_r(PerlIO_printf(Perl_debug_log, "%s", non_utf8_target_but_utf8_required));     goto target;  } STMT_END
#include "EXTERN.h"
#define PERL_IN_REGEXEC_C
#include "perl.h"
#ifdef PERL_IN_XSUB_RE
#  include "re_comp.h"
#else
#  include "regcomp.h"
#endif
#include "inline_invlist.c"
#include "unicode_constants.h"
#define HAS_NONLATIN1_FOLD_CLOSURE(i) _HAS_NONLATIN1_FOLD_CLOSURE_ONLY_FOR_USE_BY_REGCOMP_DOT_C_AND_REGEXEC_DOT_C(i)
#ifndef STATIC
#define	STATIC	static
#endif
#define REGINCLASS(prog,p,c)  (ANYOF_FLAGS(p) ? reginclass(prog,p,c,0)    					      : ANYOF_BITMAP_TEST(p,*(c)))
#define CHR_SVLEN(sv) (utf8_target ? sv_len_utf8(sv) : SvCUR(sv))
#define CHR_DIST(a,b) (PL_reg_match_utf8 ? utf8_distance(a,b) : a - b)
#define HOPc(pos,off)  	(char *)(PL_reg_match_utf8  	    ? reghop3((U8*)pos, off, (U8*)(off >= 0 ? PL_regeol : PL_bostr))  	    : (U8*)(pos + off))
#define HOPBACKc(pos, off)  	(char*)(PL_reg_match_utf8 	    ? reghopmaybe3((U8*)pos, -off, (U8*)PL_bostr)  	    : (pos - off >= PL_bostr)		 		? (U8*)pos - off		 		: NULL)
#define HOP3(pos,off,lim) (PL_reg_match_utf8 ? reghop3((U8*)(pos), off, (U8*)(lim)) : (U8*)(pos + off))
#define HOP3c(pos,off,lim) ((char*)HOP3(pos,off,lim))
#define NEXTCHR_EOS -10 
#define NEXTCHR_IS_EOS (nextchr < 0)
#define SET_nextchr      nextchr = ((locinput < PL_regeol) ? UCHARAT(locinput) : NEXTCHR_EOS)
#define SET_locinput(p)      locinput = (p);       SET_nextchr
#define LOAD_UTF8_CHARCLASS(swash_ptr, property_name) STMT_START {                     if (!swash_ptr) {                                                                  U8 flags = _CORE_SWASH_INIT_ACCEPT_INVLIST;                                    swash_ptr = _core_swash_init("utf8", property_name, &PL_sv_undef,                                           1, 0, NULL, &flags);                              assert(swash_ptr);                                                         }                                                                          } STMT_END
#ifdef DEBUGGING
#   define LOAD_UTF8_CHARCLASS_DEBUG_TEST(swash_ptr,                                                                     property_name,                                                                 utf8_char_in_property)                       LOAD_UTF8_CHARCLASS(swash_ptr, property_name);                                 assert(swash_fetch(swash_ptr, (U8 *) utf8_char_in_property, TRUE));
#else
#   define LOAD_UTF8_CHARCLASS_DEBUG_TEST(swash_ptr,                                                                     property_name,                                                                 utf8_char_in_property)                       LOAD_UTF8_CHARCLASS(swash_ptr, property_name)
#endif
#define LOAD_UTF8_CHARCLASS_ALNUM() LOAD_UTF8_CHARCLASS_DEBUG_TEST(                                                    PL_utf8_swash_ptrs[_CC_WORDCHAR],                                              swash_property_names[_CC_WORDCHAR],                                            GREEK_SMALL_LETTER_IOTA_UTF8)
#define LOAD_UTF8_CHARCLASS_GCB()                 STMT_START {                                                               	LOAD_UTF8_CHARCLASS_DEBUG_TEST(PL_utf8_X_regular_begin,                                                       "_X_regular_begin",                                                            GREEK_SMALL_LETTER_IOTA_UTF8);          	LOAD_UTF8_CHARCLASS_DEBUG_TEST(PL_utf8_X_extend,                                                              "_X_extend",                                                                   COMBINING_GRAVE_ACCENT_UTF8);               } STMT_END
#define PLACEHOLDER	
#define JUMPABLE(rn) (           OP(rn) == OPEN ||            (OP(rn) == CLOSE && (!cur_eval || cur_eval->u.eval.close_paren != ARG(rn))) ||      OP(rn) == EVAL ||        OP(rn) == SUSPEND || OP(rn) == IFMATCH ||      OP(rn) == PLUS || OP(rn) == MINMOD ||      OP(rn) == KEEPS ||      (PL_regkind[OP(rn)] == CURLY && ARG1(rn) > 0)  )
#define IS_EXACT(rn) (PL_regkind[OP(rn)] == EXACT)
#define HAS_TEXT(rn) ( IS_EXACT(rn) || PL_regkind[OP(rn)] == REF )
#if 0 
#define IS_TEXT(rn)   ( OP(rn)==EXACT   || OP(rn)==REF   || OP(rn)==NREF   )
#define IS_TEXTF(rn)  ( OP(rn)==EXACTFU || OP(rn)==EXACTFU_SS || OP(rn)==EXACTFU_TRICKYFOLD || OP(rn)==EXACTFA || OP(rn)==EXACTF || OP(rn)==REFF  || OP(rn)==NREFF )
#define IS_TEXTFL(rn) ( OP(rn)==EXACTFL || OP(rn)==REFFL || OP(rn)==NREFFL )
#else
#define IS_TEXT(rn)   ( OP(rn)==EXACT   )
#define IS_TEXTFU(rn)  ( OP(rn)==EXACTFU || OP(rn)==EXACTFU_SS || OP(rn)==EXACTFU_TRICKYFOLD || OP(rn) == EXACTFA)
#define IS_TEXTF(rn)  ( OP(rn)==EXACTF  )
#define IS_TEXTFL(rn) ( OP(rn)==EXACTFL )
#endif
#define FIND_NEXT_IMPT(rn) STMT_START {      while (JUMPABLE(rn)) {  	const OPCODE type = OP(rn);  	if (type == SUSPEND || PL_regkind[type] == CURLY)  	    rn = NEXTOPER(NEXTOPER(rn));  	else if (type == PLUS)  	    rn = NEXTOPER(rn);  	else if (type == IFMATCH)  	    rn = (rn->flags == 0) ? NEXTOPER(NEXTOPER(rn)) : rn + ARG(rn);  	else rn += NEXT_OFF(rn);      }  } STMT_END 
#define SBASE 0xAC00    
#define SCount 11172    
#define TCount 28
#define REGCP_PAREN_ELEMS 3
#define REGCP_OTHER_ELEMS 3
#define REGCP_FRAME_ELEMS 1
#define REGCP_SET(cp)                                                DEBUG_STATE_r(                                                           PerlIO_printf(Perl_debug_log,		         	        "  Setting an EVAL scope, savestack=%"IVdf"\n",	 	        (IV)PL_savestack_ix));                               cp = PL_savestack_ix
#define REGCP_UNWIND(cp)                                             DEBUG_STATE_r(                                                       if (cp != PL_savestack_ix) 		                     	    PerlIO_printf(Perl_debug_log,		         		"  Clearing an EVAL scope, savestack=%"IVdf"..%"IVdf"\n",  	        (IV)(cp), (IV)PL_savestack_ix));                     regcpblow(cp)
#define UNWIND_PAREN(lp, lcp)                    for (n = rex->lastparen; n > lp; n--)            rex->offs[n].end = -1;                   rex->lastparen = n;                          rex->lastcloseparen = lcp;
#if 1
#endif
#define regcpblow(cp) LEAVE_SCOPE(cp)	
#ifndef PERL_IN_XSUB_RE
#endif
#ifdef DEBUGGING
#endif
#ifdef QDEBUGGING	
#endif
#ifdef DEBUGGING
#endif
#define DECL_TRIE_TYPE(scan)      const enum { trie_plain, trie_utf8, trie_utf8_fold, trie_latin_utf8_fold }                      trie_type = ((scan->flags == EXACT)                                ? (utf8_target ? trie_utf8 : trie_plain)                                : (utf8_target ? trie_utf8_fold : trie_latin_utf8_fold))
#define REXEC_TRIE_READ_CHAR(trie_type, trie, widecharmap, uc, uscan, len, uvc, charid, foldlen, foldbuf, uniflags)  STMT_START {                                    STRLEN skiplen;                                                                      switch (trie_type) {                                                                 case trie_utf8_fold:                                                                     if ( foldlen>0 ) {                                                                       uvc = utf8n_to_uvuni( (const U8*) uscan, UTF8_MAXLEN, &len, uniflags );              foldlen -= len;                                                                      uscan += len;                                                                        len=0;                                                                           } else {                                                                                 uvc = to_utf8_fold( (const U8*) uc, foldbuf, &foldlen );                             len = UTF8SKIP(uc);                                                                  skiplen = UNISKIP( uvc );                                                            foldlen -= skiplen;                                                                  uscan = foldbuf + skiplen;                                                       }                                                                                    break;                                                                           case trie_latin_utf8_fold:                                                               if ( foldlen>0 ) {                                                                       uvc = utf8n_to_uvuni( (const U8*) uscan, UTF8_MAXLEN, &len, uniflags );              foldlen -= len;                                                                      uscan += len;                                                                        len=0;                                                                           } else {                                                                                 len = 1;                                                                             uvc = _to_fold_latin1( (U8) *uc, foldbuf, &foldlen, 1);                              skiplen = UNISKIP( uvc );                                                            foldlen -= skiplen;                                                                  uscan = foldbuf + skiplen;                                                       }                                                                                    break;                                                                           case trie_utf8:                                                                          uvc = utf8n_to_uvuni( (const U8*) uc, UTF8_MAXLEN, &len, uniflags );                 break;                                                                           case trie_plain:                                                                         uvc = (UV)*uc;                                                                       len = 1;                                                                         }                                                                                    if (uvc < 256) {                                                                         charid = trie->charmap[ uvc ];                                                   }                                                                                    else {                                                                                   charid = 0;                                                                          if (widecharmap) {                                                                       SV** const svpp = hv_fetch(widecharmap,                                                          (char*)&uvc, sizeof(UV), 0);                                             if (svpp)                                                                                charid = (U16)SvIV(*svpp);                                                   }                                                                                }                                                                                } STMT_END
#define REXEC_FBC_EXACTISH_SCAN(CoNd)                      STMT_START {                                                   while (s <= e) {                                       	if ( (CoNd)                                        	     && (ln == 1 || folder(s, pat_string, ln))     	     && (!reginfo || regtry(reginfo, &s)) )        	    goto got_it;                                   	s++;                                                   }                                                      } STMT_END
#define REXEC_FBC_UTF8_SCAN(CoDe)                      STMT_START {                                               while (s < strend) {                               	CoDe                                           	s += UTF8SKIP(s);                                  }                                                  } STMT_END
#define REXEC_FBC_SCAN(CoDe)                           STMT_START {                                               while (s < strend) {                               	CoDe                                           	s++;                                               }                                                  } STMT_END
#define REXEC_FBC_UTF8_CLASS_SCAN(CoNd)                REXEC_FBC_UTF8_SCAN(                                       if (CoNd) {                                        	if (tmp && (!reginfo || regtry(reginfo, &s)))  	    goto got_it;                               	else                                           	    tmp = doevery;                                 }                                                      else                                               	tmp = 1;                                       )
#define REXEC_FBC_CLASS_SCAN(CoNd)                     REXEC_FBC_SCAN(                                            if (CoNd) {                                        	if (tmp && (!reginfo || regtry(reginfo, &s)))   	    goto got_it;                               	else                                           	    tmp = doevery;                                 }                                                      else                                               	tmp = 1;                                       )
#define REXEC_FBC_TRYIT                if ((!reginfo || regtry(reginfo, &s)))      goto got_it
#define REXEC_FBC_CSCAN(CoNdUtF8,CoNd)                              if (utf8_target) {                                              	REXEC_FBC_UTF8_CLASS_SCAN(CoNdUtF8);                        }                                                               else {                                                      	REXEC_FBC_CLASS_SCAN(CoNd);                                 }
#define DUMP_EXEC_POS(li,s,doutf8)      dump_exec_pos(li,s,(PL_regeol),(PL_bostr),(PL_reg_starttry),doutf8)
#define UTF8_NOLOAD(TEST_NON_UTF8, IF_SUCCESS, IF_FAIL)  	tmp = (s != PL_bostr) ? UCHARAT(s - 1) : '\n';                          	tmp = TEST_NON_UTF8(tmp);                                               	REXEC_FBC_UTF8_SCAN(                                                    	    if (tmp == ! TEST_NON_UTF8((U8) *s)) {  		tmp = !tmp;                                                     		IF_SUCCESS;                                                     	    }                                                                   	    else {                                                              		IF_FAIL;                                                        	    }                                                                   	);                                                                      
#define UTF8_LOAD(TeSt1_UtF8, TeSt2_UtF8, IF_SUCCESS, IF_FAIL)  	if (s == PL_bostr) {                                                    	    tmp = '\n';                                                         	}                                                                       	else {                                                                  	    U8 * const r = reghop3((U8*)s, -1, (U8*)PL_bostr);                  	    tmp = utf8n_to_uvchr(r, UTF8SKIP(r), 0, UTF8_ALLOW_DEFAULT);        	}                                                                       	tmp = TeSt1_UtF8;                                                       	LOAD_UTF8_CHARCLASS_ALNUM();                                                                 	REXEC_FBC_UTF8_SCAN(                                                    	    if (tmp == ! (TeSt2_UtF8)) {  		tmp = !tmp;                                                     		IF_SUCCESS;                                                     	    }                                                                   	    else {                                                              		IF_FAIL;                                                        	    }                                                                   	);                                                                      
#define FBC_BOUND(TEST_NON_UTF8, TEST1_UTF8, TEST2_UTF8)      FBC_BOUND_COMMON(UTF8_LOAD(TEST1_UTF8, TEST2_UTF8, REXEC_FBC_TRYIT, PLACEHOLDER), TEST_NON_UTF8, REXEC_FBC_TRYIT, PLACEHOLDER)
#define FBC_BOUND_NOLOAD(TEST_NON_UTF8, TEST1_UTF8, TEST2_UTF8)      FBC_BOUND_COMMON(UTF8_NOLOAD(TEST_NON_UTF8, REXEC_FBC_TRYIT, PLACEHOLDER), TEST_NON_UTF8, REXEC_FBC_TRYIT, PLACEHOLDER)
#define FBC_NBOUND(TEST_NON_UTF8, TEST1_UTF8, TEST2_UTF8)      FBC_BOUND_COMMON(UTF8_LOAD(TEST1_UTF8, TEST2_UTF8, PLACEHOLDER, REXEC_FBC_TRYIT), TEST_NON_UTF8, PLACEHOLDER, REXEC_FBC_TRYIT)
#define FBC_NBOUND_NOLOAD(TEST_NON_UTF8, TEST1_UTF8, TEST2_UTF8)      FBC_BOUND_COMMON(UTF8_NOLOAD(TEST_NON_UTF8, PLACEHOLDER, REXEC_FBC_TRYIT), TEST_NON_UTF8, PLACEHOLDER, REXEC_FBC_TRYIT)
#define FBC_BOUND_COMMON(UTF8_CODE, TEST_NON_UTF8, IF_SUCCESS, IF_FAIL)      if (utf8_target) {                                                          		UTF8_CODE      }                                                                               else {                                                        	tmp = (s != PL_bostr) ? UCHARAT(s - 1) : '\n';                          	tmp = TEST_NON_UTF8(tmp);                                               	REXEC_FBC_SCAN(                                                         	    if (tmp == ! TEST_NON_UTF8((U8) *s)) {                              		tmp = !tmp;                                                     		IF_SUCCESS;                                                     	    }                                                                   	    else {                                                              		IF_FAIL;                                                        	    }                                                                   	);                                                                          }                                                                               if ((!prog->minlen && tmp) && (!reginfo || regtry(reginfo, &s)))            	goto got_it;
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef PERL_ANY_COW
#endif
#define SET_reg_curpm(Re2)      if (PL_reg_state.re_state_eval_setup_done) {     	(void)ReREFCNT_inc(Re2);		     	ReREFCNT_dec(PM_GETRE(PL_reg_curpm));	     	PM_SETRE((PL_reg_curpm), (Re2));	         }
#ifdef PERL_OLD_COPY_ON_WRITE
#endif
#ifdef USE_ITHREADS
#endif      
#ifdef PERL_ANY_COW
#endif
#ifdef DEBUGGING
#endif
#if 1
#endif
#define sayYES goto yes
#define sayNO goto no
#define sayNO_SILENT goto no_silent
#define CACHEsayNO      if (ST.cache_mask)         PL_reg_poscache[ST.cache_offset] |= ST.cache_mask;      sayNO
#define REPORT_CODE_OFF 32
#define CHRTEST_UNINIT -1001 
#define CHRTEST_VOID   -1000 
#define CHRTEST_NOT_A_CP_1 -999
#define CHRTEST_NOT_A_CP_2 -998
#define SLAB_FIRST(s) (&(s)->states[0])
#define SLAB_LAST(s)  (&(s)->states[PERL_REGMATCH_SLAB_SLOTS-1])
#if PERL_VERSION < 9 && !defined(PERL_CORE)
#endif
#define PUSH_STATE_GOTO(state, node, input)      pushinput = input;      scan = node;      st->resume_state = state;      goto push_state;
#define PUSH_YES_STATE_GOTO(state, node, input)      pushinput = input;      scan = node;      st->resume_state = state;      goto push_yes_state;
#define ST st->u.ifmatch
#undef ST
#define DEBUG_STATE_pp(pp)				         DEBUG_STATE_r({					     	DUMP_EXEC_POS(locinput, scan, utf8_target);		     	PerlIO_printf(Perl_debug_log,			     	    "    %*s"pp" %s%s%s%s%s\n",			     	    depth*2, "",				     	    PL_reg_name[st->resume_state],                      	    ((st==yes_state||st==mark_state) ? "[" : ""),    	    ((st==yes_state) ? "Y" : ""),                    	    ((st==mark_state) ? "M" : ""),                   	    ((st==yes_state||st==mark_state) ? "]" : "")     	);                                                       });
#define REG_NODE_NUM(x) ((x) ? (int)((x)-prog) : -1)
#ifdef DEBUGGING
#endif
#if PERL_VERSION < 9 && !defined(PERL_CORE)
#endif
#ifdef DEBUGGING
#endif
#undef  ST
#define ST st->u.trie
#undef  ST
#undef  ST
#define ST st->u.eval
#undef ST
#define CLOSE_CAPTURE      rex->offs[n].start = rex->offs[n].start_tmp;      rex->offs[n].end = locinput - PL_bostr;      DEBUG_BUFFERS_r(PerlIO_printf(Perl_debug_log,  	"rex=0x%"UVxf" offs=0x%"UVxf": \\%"UVuf": set %"IVdf"..%"IVdf"\n",  	PTR2UV(rex),  	PTR2UV(rex->offs),  	(UV)n,  	(IV)rex->offs[n].start,  	(IV)rex->offs[n].end      ))
#define ST st->u.curlyx
#undef ST
#define ST st->u.whilem
#undef  ST
#define ST st->u.branch
#undef  ST
#define ST st->u.curlym
#undef ST
#define ST st->u.curly
#define CURLY_SETPAREN(paren, success)      if (paren) {  	if (success) {  	    rex->offs[paren].start = HOPc(locinput, -1) - PL_bostr;  	    rex->offs[paren].end = locinput - PL_bostr;  	    if (paren > rex->lastparen)  		rex->lastparen = paren;  	    rex->lastcloseparen = paren;  	}  	else {  	    rex->offs[paren].end = -1;  	    rex->lastparen      = ST.lastparen;  	    rex->lastcloseparen = ST.lastcloseparen;  	}      }
#undef ST
#undef  ST
#define ST st->u.ifmatch
#undef ST
#define ST st->u.mark
#undef ST
#ifdef DEBUGGING
#else
#endif
#ifndef DEBUGGING
#endif
#if !defined(PERL_IN_XSUB_RE) || defined(PLUGGABLE_RE_EXTENSION)
#endif
#ifdef XXX_dmq
#endif
#ifdef PERL_ANY_COW
#endif
