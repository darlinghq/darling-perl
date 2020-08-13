#line 2 "regcomp.c"
#ifdef PERL_EXT_RE_BUILD
#include "re_top.h"
#endif
#include "EXTERN.h"
#define PERL_IN_REGCOMP_C
#include "perl.h"
#ifndef PERL_IN_XSUB_RE
#  include "INTERN.h"
#endif
#define REG_COMP_C
#ifdef PERL_IN_XSUB_RE
#  include "re_comp.h"
#else
#  include "regcomp.h"
#endif
#include "dquote_static.c"
#include "charclass_invlists.h"
#include "inline_invlist.c"
#include "unicode_constants.h"
#define HAS_NONLATIN1_FOLD_CLOSURE(i) _HAS_NONLATIN1_FOLD_CLOSURE_ONLY_FOR_USE_BY_REGCOMP_DOT_C_AND_REGEXEC_DOT_C(i)
#define IS_NON_FINAL_FOLD(c) _IS_NON_FINAL_FOLD_ONLY_FOR_USE_BY_REGCOMP_DOT_C(c)
#define IS_IN_SOME_FOLD_L1(c) _IS_IN_SOME_FOLD_ONLY_FOR_USE_BY_REGCOMP_DOT_C(c)
#ifdef op
#undef op
#endif 
#ifdef MSDOS
#  if defined(BUGGY_MSC6)
#    pragma optimize("a",off)
#    pragma optimize("w",on )
#  endif 
#endif 
#ifndef STATIC
#define	STATIC	static
#endif
#if ADD_TO_REGEXEC
#define RExC_starttry	(pRExC_state->starttry)
#endif
#ifdef DEBUGGING
#define RExC_lastparse	(pRExC_state->lastparse)
#define RExC_lastnum	(pRExC_state->lastnum)
#define RExC_paren_name_list    (pRExC_state->paren_name_list)
#endif
#define RExC_seen_unfolded_sharp_s (pRExC_state->seen_unfolded_sharp_s)
#define RExC_flags	(pRExC_state->flags)
#define RExC_pm_flags	(pRExC_state->pm_flags)
#define RExC_precomp	(pRExC_state->precomp)
#define RExC_rx_sv	(pRExC_state->rx_sv)
#define RExC_rx		(pRExC_state->rx)
#define RExC_rxi	(pRExC_state->rxi)
#define RExC_start	(pRExC_state->start)
#define RExC_end	(pRExC_state->end)
#define RExC_parse	(pRExC_state->parse)
#define RExC_whilem_seen	(pRExC_state->whilem_seen)
#define RExC_seen_unfolded_sharp_s (pRExC_state->seen_unfolded_sharp_s)
#ifdef RE_TRACK_PATTERN_OFFSETS
#define RExC_offsets	(pRExC_state->rxi->u.offsets) 
#endif
#define RExC_emit	(pRExC_state->emit)
#define RExC_emit_start	(pRExC_state->emit_start)
#define RExC_emit_bound	(pRExC_state->emit_bound)
#define RExC_naughty	(pRExC_state->naughty)
#define RExC_sawback	(pRExC_state->sawback)
#define RExC_seen	(pRExC_state->seen)
#define RExC_size	(pRExC_state->size)
#define RExC_npar	(pRExC_state->npar)
#define RExC_nestroot   (pRExC_state->nestroot)
#define RExC_extralen	(pRExC_state->extralen)
#define RExC_seen_zerolen	(pRExC_state->seen_zerolen)
#define RExC_utf8	(pRExC_state->utf8)
#define RExC_uni_semantics	(pRExC_state->uni_semantics)
#define RExC_orig_utf8	(pRExC_state->orig_utf8)
#define RExC_open_parens	(pRExC_state->open_parens)
#define RExC_close_parens	(pRExC_state->close_parens)
#define RExC_opend	(pRExC_state->opend)
#define RExC_paren_names	(pRExC_state->paren_names)
#define RExC_recurse	(pRExC_state->recurse)
#define RExC_recurse_count	(pRExC_state->recurse_count)
#define RExC_in_lookbehind	(pRExC_state->in_lookbehind)
#define RExC_contains_locale	(pRExC_state->contains_locale)
#define RExC_override_recoding (pRExC_state->override_recoding)
#define RExC_in_multi_char_class (pRExC_state->in_multi_char_class)
#define	ISMULT1(c)	((c) == '*' || (c) == '+' || (c) == '?')
#define	ISMULT2(s)	((*s) == '*' || (*s) == '+' || (*s) == '?' ||  	((*s) == '{' && regcurly(s, FALSE)))
#ifdef SPSTART
#undef SPSTART		
#endif
#define	WORST		0	
#define	HASWIDTH	0x01	
#define	SIMPLE		0x02
#define	SPSTART		0x04	
#define POSTPONED	0x08    
#define TRYAGAIN	0x10	
#define RESTART_UTF8    0x20    
#define REG_NODE_NUM(x) ((x) ? (int)((x)-RExC_emit_start) : -1)
#if PERL_ENABLE_EXTENDED_TRIE_OPTIMISATION
#define TRIE_STUDY_OPT
#define FULL_TRIE_STUDY
#define TRIE_STCLASS
#endif
#define PBYTE(u8str,paren) ((U8*)(u8str))[(paren) >> 3]
#define PBITVAL(paren) (1 << ((paren) & 7))
#define PAREN_TEST(u8str,paren) ( PBYTE(u8str,paren) & PBITVAL(paren))
#define PAREN_SET(u8str,paren) PBYTE(u8str,paren) |= PBITVAL(paren)
#define PAREN_UNSET(u8str,paren) PBYTE(u8str,paren) &= (~PBITVAL(paren))
#define REQUIRE_UTF8	STMT_START {                                                                             if (!UTF) {                                                                     *flagp = RESTART_UTF8;                                                      return NULL;                                                            }                                                              } STMT_END
#define namedclass_to_classnum(class)  ((int) ((class) / 2))
#define classnum_to_namedclass(classnum)  ((classnum) * 2)
#define SF_BEFORE_EOL		(SF_BEFORE_SEOL|SF_BEFORE_MEOL)
#define SF_BEFORE_SEOL		0x0001
#define SF_BEFORE_MEOL		0x0002
#define SF_FIX_BEFORE_EOL	(SF_FIX_BEFORE_SEOL|SF_FIX_BEFORE_MEOL)
#define SF_FL_BEFORE_EOL	(SF_FL_BEFORE_SEOL|SF_FL_BEFORE_MEOL)
#ifdef NO_UNARY_PLUS
#  define SF_FIX_SHIFT_EOL	(0+2)
#  define SF_FL_SHIFT_EOL		(0+4)
#else
#  define SF_FIX_SHIFT_EOL	(+2)
#  define SF_FL_SHIFT_EOL		(+4)
#endif
#define SF_FIX_BEFORE_SEOL	(SF_BEFORE_SEOL << SF_FIX_SHIFT_EOL)
#define SF_FIX_BEFORE_MEOL	(SF_BEFORE_MEOL << SF_FIX_SHIFT_EOL)
#define SF_FL_BEFORE_SEOL	(SF_BEFORE_SEOL << SF_FL_SHIFT_EOL)
#define SF_FL_BEFORE_MEOL	(SF_BEFORE_MEOL << SF_FL_SHIFT_EOL) 
#define SF_IS_INF		0x0040
#define SF_HAS_PAR		0x0080
#define SF_IN_PAR		0x0100
#define SF_HAS_EVAL		0x0200
#define SCF_DO_SUBSTR		0x0400
#define SCF_DO_STCLASS_AND	0x0800
#define SCF_DO_STCLASS_OR	0x1000
#define SCF_DO_STCLASS		(SCF_DO_STCLASS_AND|SCF_DO_STCLASS_OR)
#define SCF_WHILEM_VISITED_POS	0x2000
#define SCF_TRIE_RESTUDY        0x4000 
#define SCF_SEEN_ACCEPT         0x8000 
#define UTF cBOOL(RExC_utf8)
#define LOC (get_regex_charset(RExC_flags) == REGEX_LOCALE_CHARSET)
#define DEPENDS_SEMANTICS (get_regex_charset(RExC_flags) == REGEX_DEPENDS_CHARSET)
#define UNI_SEMANTICS (get_regex_charset(RExC_flags) == REGEX_UNICODE_CHARSET)
#define AT_LEAST_UNI_SEMANTICS (get_regex_charset(RExC_flags) >= REGEX_UNICODE_CHARSET)
#define ASCII_RESTRICTED (get_regex_charset(RExC_flags) == REGEX_ASCII_RESTRICTED_CHARSET)
#define AT_LEAST_ASCII_RESTRICTED (get_regex_charset(RExC_flags) >= REGEX_ASCII_RESTRICTED_CHARSET)
#define ASCII_FOLD_RESTRICTED (get_regex_charset(RExC_flags) == REGEX_ASCII_MORE_RESTRICTED_CHARSET)
#define FOLD cBOOL(RExC_flags & RXf_PMf_FOLD)
#define OOB_NAMEDCLASS		-1
#define OOB_UNICODE		0xDEADBEEF
#define CHR_SVLEN(sv) (UTF ? sv_len_utf8(sv) : SvCUR(sv))
#define CHR_DIST(a,b) (UTF ? utf8_distance(a,b) : a - b)
#define RegexLengthToShowInErrorMessages 127
#define MARKER1 "<-- HERE"    
#define MARKER2 " <-- HERE "  
#define REPORT_LOCATION " in regex; marked by " MARKER1 " in m/%.*s" MARKER2 "%s/"
#define _FAIL(code) STMT_START {					     const char *ellipses = "";						     IV len = RExC_end - RExC_precomp;					 									     if (!SIZE_ONLY)							 	SAVEFREESV(RExC_rx_sv);						     if (len > RegexLengthToShowInErrorMessages) {			 		 	len = RegexLengthToShowInErrorMessages - 10;			 	ellipses = "...";						     }									     code;                                                                } STMT_END
#define	FAIL(msg) _FAIL(			         Perl_croak(aTHX_ "%s in regex m/%.*s%s/",	     	    msg, (int)len, RExC_precomp, ellipses))
#define	FAIL2(msg,arg) _FAIL(			         Perl_croak(aTHX_ msg " in regex m/%.*s%s/",	     	    arg, (int)len, RExC_precomp, ellipses))
#define	Simple_vFAIL(m) STMT_START {					     const IV offset = RExC_parse - RExC_precomp;			     Perl_croak(aTHX_ "%s" REPORT_LOCATION,				 	    m, (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	vFAIL(m) STMT_START {				     if (!SIZE_ONLY)					 	SAVEFREESV(RExC_rx_sv);				     Simple_vFAIL(m);					 } STMT_END
#define	Simple_vFAIL2(m,a1) STMT_START {			     const IV offset = RExC_parse - RExC_precomp;			     S_re_croak2(aTHX_ m, REPORT_LOCATION, a1,			 	    (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	vFAIL2(m,a1) STMT_START {			     if (!SIZE_ONLY)					 	SAVEFREESV(RExC_rx_sv);				     Simple_vFAIL2(m, a1);				 } STMT_END
#define	Simple_vFAIL3(m, a1, a2) STMT_START {			     const IV offset = RExC_parse - RExC_precomp;		     S_re_croak2(aTHX_ m, REPORT_LOCATION, a1, a2,		 	    (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	vFAIL3(m,a1,a2) STMT_START {			     if (!SIZE_ONLY)					 	SAVEFREESV(RExC_rx_sv);				     Simple_vFAIL3(m, a1, a2);				 } STMT_END
#define	Simple_vFAIL4(m, a1, a2, a3) STMT_START {		     const IV offset = RExC_parse - RExC_precomp;		     S_re_croak2(aTHX_ m, REPORT_LOCATION, a1, a2, a3,		 	    (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	vFAIL4(m,a1,a2,a3) STMT_START {			     if (!SIZE_ONLY)					 	SAVEFREESV(RExC_rx_sv);				     Simple_vFAIL4(m, a1, a2, a3);			 } STMT_END
#define reg_warn_non_literal_string(loc, m) STMT_START {                     const IV offset = loc - RExC_precomp;                                    Perl_warner(aTHX_ packWARN(WARN_REGEXP), "%s" REPORT_LOCATION,                   m, (int)offset, RExC_precomp, RExC_precomp + offset);        } STMT_END
#define	ckWARNreg(loc,m) STMT_START {					     const IV offset = loc - RExC_precomp;				     Perl_ck_warner(aTHX_ packWARN(WARN_REGEXP), m REPORT_LOCATION,	 	    (int)offset, RExC_precomp, RExC_precomp + offset);		 } STMT_END
#define	vWARN_dep(loc, m) STMT_START {				             const IV offset = loc - RExC_precomp;				     Perl_warner(aTHX_ packWARN(WARN_DEPRECATED), m REPORT_LOCATION,	 	    (int)offset, RExC_precomp, RExC_precomp + offset);	         } STMT_END
#define	ckWARNdep(loc,m) STMT_START {				             const IV offset = loc - RExC_precomp;				     Perl_ck_warner_d(aTHX_ packWARN(WARN_DEPRECATED),	                 	    m REPORT_LOCATION,						 	    (int)offset, RExC_precomp, RExC_precomp + offset);		 } STMT_END
#define	ckWARNregdep(loc,m) STMT_START {				     const IV offset = loc - RExC_precomp;				     Perl_ck_warner_d(aTHX_ packWARN2(WARN_DEPRECATED, WARN_REGEXP),	 	    m REPORT_LOCATION,						 	    (int)offset, RExC_precomp, RExC_precomp + offset);		 } STMT_END
#define	ckWARN2regdep(loc,m, a1) STMT_START {				     const IV offset = loc - RExC_precomp;				     Perl_ck_warner_d(aTHX_ packWARN2(WARN_DEPRECATED, WARN_REGEXP),	 	    m REPORT_LOCATION,						 	    a1, (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	ckWARN2reg(loc, m, a1) STMT_START {				     const IV offset = loc - RExC_precomp;				     Perl_ck_warner(aTHX_ packWARN(WARN_REGEXP), m REPORT_LOCATION,	 	    a1, (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	vWARN3(loc, m, a1, a2) STMT_START {				     const IV offset = loc - RExC_precomp;				     Perl_warner(aTHX_ packWARN(WARN_REGEXP), m REPORT_LOCATION,		 	    a1, a2, (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	ckWARN3reg(loc, m, a1, a2) STMT_START {				     const IV offset = loc - RExC_precomp;				     Perl_ck_warner(aTHX_ packWARN(WARN_REGEXP), m REPORT_LOCATION,	 	    a1, a2, (int)offset, RExC_precomp, RExC_precomp + offset);	 } STMT_END
#define	vWARN4(loc, m, a1, a2, a3) STMT_START {				     const IV offset = loc - RExC_precomp;				     Perl_warner(aTHX_ packWARN(WARN_REGEXP), m REPORT_LOCATION,		 	    a1, a2, a3, (int)offset, RExC_precomp, RExC_precomp + offset);  } STMT_END
#define	ckWARN4reg(loc, m, a1, a2, a3) STMT_START {			     const IV offset = loc - RExC_precomp;				     Perl_ck_warner(aTHX_ packWARN(WARN_REGEXP), m REPORT_LOCATION,	 	    a1, a2, a3, (int)offset, RExC_precomp, RExC_precomp + offset);  } STMT_END
#define	vWARN5(loc, m, a1, a2, a3, a4) STMT_START {			     const IV offset = loc - RExC_precomp;				     Perl_warner(aTHX_ packWARN(WARN_REGEXP), m REPORT_LOCATION,		 	    a1, a2, a3, a4, (int)offset, RExC_precomp, RExC_precomp + offset);  } STMT_END
#define REGC(c,s) STMT_START {			     if (!SIZE_ONLY) *(s) = (c); else (void)(s);	 } STMT_END
#ifndef RE_TRACK_PATTERN_OFFSETS
#define Set_Node_Offset_To_R(node,byte)
#define Set_Node_Offset(node,byte)
#define Set_Cur_Node_Offset
#define Set_Node_Length_To_R(node,len)
#define Set_Node_Length(node,len)
#define Set_Node_Cur_Length(node)
#define Node_Offset(n) 
#define Node_Length(n) 
#define Set_Node_Offset_Length(node,offset,len)
#define ProgLen(ri) ri->u.proglen
#define SetProgLen(ri,x) ri->u.proglen = x
#else
#define ProgLen(ri) ri->u.offsets[0]
#define SetProgLen(ri,x) ri->u.offsets[0] = x
#define Set_Node_Offset_To_R(node,byte) STMT_START {			     if (! SIZE_ONLY) {							 	MJD_OFFSET_DEBUG(("** (%d) offset of node %d is %d.\n",		 		    __LINE__, (int)(node), (int)(byte)));		 	if((node) < 0) {						 	    Perl_croak(aTHX_ "value of node is %d in Offset macro", (int)(node));  	} else {							 	    RExC_offsets[2*(node)-1] = (byte);				 	}								     }									 } STMT_END
#define Set_Node_Offset(node,byte)      Set_Node_Offset_To_R((node)-RExC_emit_start, (byte)-RExC_start)
#define Set_Cur_Node_Offset Set_Node_Offset(RExC_emit, RExC_parse)
#define Set_Node_Length_To_R(node,len) STMT_START {			     if (! SIZE_ONLY) {							 	MJD_OFFSET_DEBUG(("** (%d) size of node %d is %d.\n",		 		__LINE__, (int)(node), (int)(len)));			 	if((node) < 0) {						 	    Perl_croak(aTHX_ "value of node is %d in Length macro", (int)(node));  	} else {							 	    RExC_offsets[2*(node)] = (len);				 	}								     }									 } STMT_END
#define Set_Node_Length(node,len)      Set_Node_Length_To_R((node)-RExC_emit_start, len)
#define Set_Cur_Node_Length(len) Set_Node_Length(RExC_emit, len)
#define Set_Node_Cur_Length(node)      Set_Node_Length(node, RExC_parse - parse_start)
#define Node_Offset(n) (RExC_offsets[2*((n)-RExC_emit_start)-1])
#define Node_Length(n) (RExC_offsets[2*((n)-RExC_emit_start)])
#define Set_Node_Offset_Length(node,offset,len) STMT_START {	     Set_Node_Offset_To_R((node)-RExC_emit_start, (offset));	     Set_Node_Length_To_R((node)-RExC_emit_start, (len));	 } STMT_END
#endif
#if PERL_ENABLE_EXPERIMENTAL_REGEX_OPTIMISATIONS
#define EXPERIMENTAL_INPLACESCAN
#endif 
#define DEBUG_STUDYDATA(str,data,depth)                               DEBUG_OPTIMISE_MORE_r(if(data){                                           PerlIO_printf(Perl_debug_log,                                             "%*s" str "Pos:%"IVdf"/%"IVdf                                         " Flags: 0x%"UVXf" Whilem_c: %"IVdf" Lcp: %"IVdf" %s",                (int)(depth)*2, "",                                                   (IV)((data)->pos_min),                                                (IV)((data)->pos_delta),                                              (UV)((data)->flags),                                                  (IV)((data)->whilem_c),                                               (IV)((data)->last_closep ? *((data)->last_closep) : -1),              is_inf ? "INF " : ""                                              );                                                                    if ((data)->last_found)                                                   PerlIO_printf(Perl_debug_log,                                             "Last:'%s' %"IVdf":%"IVdf"/%"IVdf" %sFixed:'%s' @ %"IVdf              " %sFloat: '%s' @ %"IVdf"/%"IVdf"",                                   SvPVX_const((data)->last_found),                                      (IV)((data)->last_end),                                               (IV)((data)->last_start_min),                                         (IV)((data)->last_start_max),                                         ((data)->longest &&                                                    (data)->longest==&((data)->longest_fixed)) ? "*" : "",               SvPVX_const((data)->longest_fixed),                                   (IV)((data)->offset_fixed),                                           ((data)->longest &&                                                    (data)->longest==&((data)->longest_float)) ? "*" : "",               SvPVX_const((data)->longest_float),                                   (IV)((data)->offset_float_min),                                       (IV)((data)->offset_float_max)                                    );                                                                PerlIO_printf(Perl_debug_log,"\n");                               });
#define SET_SSC_EOS(node)   STMT_START { (node)->next_off = TRUE; } STMT_END
#define CLEAR_SSC_EOS(node) STMT_START { (node)->next_off = FALSE; } STMT_END
#define TEST_SSC_EOS(node)  cBOOL((node)->next_off)
#define cl_init_zero		S_cl_init
#define TRIE_LIST_ITEM(state,idx) (trie->states[state].trans.list)[ idx ]
#define TRIE_LIST_CUR(state)  ( TRIE_LIST_ITEM( state, 0 ).forid )
#define TRIE_LIST_LEN(state) ( TRIE_LIST_ITEM( state, 0 ).newstate )
#define TRIE_LIST_USED(idx)  ( trie->states[state].trans.list ? (TRIE_LIST_CUR( idx ) - 1) : 0 )
#ifdef DEBUGGING
#endif
#define TRIE_STORE_REVCHAR(val)                                                 STMT_START {                                                            	if (UTF) {							                SV *zlopp = newSV(7);                     	    unsigned char *flrbbbbb = (unsigned char *) SvPVX(zlopp);	                unsigned const char *const kapow = uvuni_to_utf8(flrbbbbb, val);  	    SvCUR_set(zlopp, kapow - flrbbbbb);				    	    SvPOK_on(zlopp);						    	    SvUTF8_on(zlopp);						    	    av_push(revcharmap, zlopp);					    	} else {							                char ooooff = (char)val;                                            	    av_push(revcharmap, newSVpvn(&ooooff, 1));			    	}								            } STMT_END
#define TRIE_READ_CHAR STMT_START {                                                          wordlen++;                                                                               if ( UTF ) {                                                                                             uvc = utf8n_to_uvuni( (const U8*) uc, UTF8_MAXLEN, &len, uniflags);                  }                                                                                        else if (folder == PL_fold_latin1) {                                                                         if ( foldlen > 0 ) {                                                                        uvc = utf8n_to_uvuni( (const U8*) scan, UTF8_MAXLEN, &len, uniflags );                   foldlen -= len;                                                                          scan += len;                                                                             len = 0;                                                                              } else {                                                                                     len = 1;                                                                                 uvc = _to_fold_latin1( (U8) *uc, foldbuf, &foldlen, 1);                                  skiplen = UNISKIP(uvc);                                                                  foldlen -= skiplen;                                                                      scan = foldbuf + skiplen;                                                            }                                                                                    } else {                                                                                                                                uvc = (U32)*uc;                                                                          len = 1;                                                                             }                                                                                    } STMT_END
#define TRIE_LIST_PUSH(state,fid,ns) STMT_START {                    if ( TRIE_LIST_CUR( state ) >=TRIE_LIST_LEN( state ) ) {     	U32 ging = TRIE_LIST_LEN( state ) *= 2;                  	Renew( trie->states[ state ].trans.list, ging, reg_trie_trans_le );      }                                                                TRIE_LIST_ITEM( state, TRIE_LIST_CUR( state ) ).forid = fid;          TRIE_LIST_ITEM( state, TRIE_LIST_CUR( state ) ).newstate = ns;        TRIE_LIST_CUR( state )++;                                    } STMT_END
#define TRIE_LIST_NEW(state) STMT_START {                            Newxz( trie->states[ state ].trans.list,                	4, reg_trie_trans_le );                                       TRIE_LIST_CUR( state ) = 1;                                      TRIE_LIST_LEN( state ) = 4;                                 } STMT_END
#define TRIE_HANDLE_WORD(state) STMT_START {                         U16 dupe= trie->states[ state ].wordnum;                         regnode * const noper_next = regnext( noper );                                                                                    DEBUG_r({                                                                                             SV* tmp;                                                         if (OP(noper) != NOTHING)                                            tmp = newSVpvn_utf8(STRING(noper), STR_LEN(noper), UTF);	         else                                                                 tmp = newSVpvn_utf8( "", 0, UTF );			         av_push( trie_words, tmp );                                  });                                                                                                                               curword++;                                                       trie->wordinfo[curword].prev   = 0;                              trie->wordinfo[curword].len    = wordlen;                        trie->wordinfo[curword].accept = state;                                                                                           if ( noper_next < tail ) {                                           if (!trie->jump)                                                     trie->jump = (U16 *) PerlMemShared_calloc( word_count + 1, sizeof(U16) );          trie->jump[curword] = (U16)(noper_next - convert);               if (!jumper)                                                         jumper = noper_next;                                         if (!nextbranch)                                                     nextbranch= regnext(cur);                                }                                                                                                                                 if ( dupe ) {                                                                           	trie->wordinfo[curword].prev = trie->wordinfo[dupe].prev;  	trie->wordinfo[dupe].prev = curword;                         } else {                                                                       trie->states[ state ].wordnum = curword;                     }                                                            } STMT_END
#define TRIE_TRANS_STATE(state,base,ucharcount,charid,special)		      ( ( base + charid >=  ucharcount					          && base + charid < ubound					          && state == trie->trans[ base - ucharcount + charid ].check	          && trie->trans[ base - ucharcount + charid ].next )		            ? trie->trans[ base - ucharcount + charid ].next		            : ( state==1 ? special : 0 )					       )
#define MADE_TRIE       1
#define MADE_JUMP_TRIE  2
#define MADE_EXACT_TRIE 4
#ifdef DEBUGGING
#else
#endif
#ifndef DEBUGGING
#endif
#ifdef DEBUGGING
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif 
#endif 
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifdef DEBUGGING	    
#endif
#ifdef DEBUGGING
#ifdef PERL_EXT_RE_BUILD
#else
#endif
#endif
#ifdef DEBUGGING
#else
#endif
#ifndef DEBUGGING
#endif
#if defined(__sparc64__) && defined(__GNUC__)
#   if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 96)
#       undef  SPARC64_GCC_WORKAROUND
#       define SPARC64_GCC_WORKAROUND 1
#   endif
#endif
#define DEBUG_PEEP(str,scan,depth)      DEBUG_OPTIMISE_r({if (scan){         SV * const mysv=sv_newmortal();         regnode *Next = regnext(scan);         regprop(RExC_rx, mysv, scan);         PerlIO_printf(Perl_debug_log, "%*s" str ">%3d: %s (%d)\n",         (int)depth*2, "", REG_NODE_NUM(scan), SvPV_nolen_const(mysv),        Next ? (REG_NODE_NUM(Next)) : 0 );     }});
#define JOIN_EXACT(scan,min_subtract,has_exactf_sharp_s, flags)      if (PL_regkind[OP(scan)] == EXACT)          join_exact(pRExC_state,(scan),(min_subtract),has_exactf_sharp_s, (flags),NULL,depth+1)
#ifdef DEBUGGING
#else
#endif
#ifndef EXPERIMENTAL_INPLACESCAN
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef EXPERIMENTAL_INPLACESCAN
#endif
#ifdef DEBUGGING
#endif
#define INIT_AND_WITHP      assert(!and_withp);      Newx(and_withp,1,struct regnode_charclass_class);      SAVEFREEPV(and_withp)
#define SCAN_COMMIT(s, data, m) scan_commit(s, data, m, is_inf)
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#define TRIE_TYPE(X) ( ( NOTHING == (X) ) ? NOTHING :                           ( EXACT == (X) )   ? EXACT :                                ( EXACTFU == (X) || EXACTFU_SS == (X) || EXACTFU_TRICKYFOLD == (X) ) ? EXACTFU :                                0 )
#if defined(DEBUGGING) || defined(NOJUMPTRIE)
#endif
#ifdef NOJUMPTRIE
#endif
#if !defined(DEBUGGING) && !defined(NOJUMPTRIE)
#endif
#ifdef NOJUMPTRIE
#endif
#ifdef TRIE_STUDY_OPT
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#if 0
#endif
#if defined(SPARC64_GCC_WORKAROUND)
#else
#endif
#if 0
#endif
#ifdef DEBUGGING
#endif
#if PERL_ENABLE_POSITIVE_ASSERTION_STUDY
#endif
#ifdef TRIE_STUDY_OPT
#ifdef FULL_TRIE_STUDY
#else
#endif 
#endif 
#ifndef PERL_IN_XSUB_RE
#endif
#ifdef TRIE_STUDY_OPT
#define CHECK_RESTUDY_GOTO_butfirst(dOsomething)                 STMT_START {                                                     if (                                                               (data.flags & SCF_TRIE_RESTUDY)                              && ! restudied++                                       ) {                                                              dOsomething;                                                 goto reStudy;                                            }                                                        } STMT_END
#else
#define CHECK_RESTUDY_GOTO_butfirst
#endif        
#ifndef PERL_IN_XSUB_RE 
#endif
#ifdef PERL_IN_XSUB_RE
#else
#endif
#ifdef TRIE_STUDY_OPT    
#endif    
#ifndef PERL_IN_XSUB_RE
#endif
#ifdef DEBUGGING
#endif
#if 0 
#endif
#ifdef DEBUGGING
#else 
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifdef TRIE_STUDY_OPT
#else
#endif    
#ifdef TRIE_STCLASS
#endif
#ifdef TRIE_STUDY_OPT
#else
#endif
#ifdef DEBUGGING
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifdef USE_ITHREADS
#endif
#if NO_TAINT_SUPPORT
#else
#endif
#define REG_RSN_RETURN_NULL    0
#define REG_RSN_RETURN_NAME    1
#define REG_RSN_RETURN_DATA    2
#define DEBUG_PARSE_MSG(funcname)     DEBUG_PARSE_r({                int rem=(int)(RExC_end - RExC_parse);                            int cut;                                                         int num;                                                         int iscut=0;                                                     if (rem>10) {                                                        rem=10;                                                          iscut=1;                                                     }                                                                cut=10-rem;                                                      if (RExC_lastparse!=RExC_parse)                                      PerlIO_printf(Perl_debug_log," >%.*s%-*s",                           rem, RExC_parse,                                                 cut + 4,                                                         iscut ? "..." : "<"                                          );                                                           else                                                                 PerlIO_printf(Perl_debug_log,"%16s","");                                                                                      if (SIZE_ONLY)                                                      num = RExC_size + 1;                                          else                                                                num=REG_NODE_NUM(RExC_emit);                                  if (RExC_lastnum!=num)                                              PerlIO_printf(Perl_debug_log,"|%4d",num);                     else                                                                PerlIO_printf(Perl_debug_log,"|%4s","");                      PerlIO_printf(Perl_debug_log,"|%*s%-4s",                             (int)((depth*2)), "",                                            (funcname)                                                   );                                                               RExC_lastnum=num;                                                RExC_lastparse=RExC_parse;                                   })
#define DEBUG_PARSE(funcname)     DEBUG_PARSE_r({                DEBUG_PARSE_MSG((funcname));                                 PerlIO_printf(Perl_debug_log,"%4s","\n");                })
#define DEBUG_PARSE_FMT(funcname,fmt,args)     DEBUG_PARSE_r({                DEBUG_PARSE_MSG((funcname));                                 PerlIO_printf(Perl_debug_log,fmt "\n",args);                })
#define TO_INTERNAL_SIZE(x) (((x) + HEADER_LENGTH) * sizeof(UV))
#define FROM_INTERNAL_SIZE(x) (((x)/ sizeof(UV)) - HEADER_LENGTH)
#define INVLIST_INITIAL_LEN 10
#ifndef PERL_IN_XSUB_RE
#if HEADER_LENGTH != 5
#   error Need to regenerate INVLIST_VERSION_ID by running perl -E 'say int(rand 2**31-1)', and then changing the #if to the new length
#endif
#endif
#define _invlist_union_complement_2nd(a, b, output) _invlist_union_maybe_complement_2nd(a, b, TRUE, output)
#ifndef PERL_IN_XSUB_RE
#endif
#ifndef PERL_IN_XSUB_RE
#endif
#ifndef PERL_IN_XSUB_RE
#endif
#ifdef PERL_ARGS_ASSERT__INVLIST_DUMP
#endif
#if 0
#endif
#undef HEADER_LENGTH
#undef INVLIST_INITIAL_LENGTH
#undef TO_INTERNAL_SIZE
#undef FROM_INTERNAL_SIZE
#undef INVLIST_LEN_OFFSET
#undef INVLIST_ZERO_OFFSET
#undef INVLIST_ITER_OFFSET
#undef INVLIST_VERSION_ID
#undef INVLIST_PREVIOUS_INDEX_OFFSET
#define WASTED_O  0x01
#define WASTED_G  0x02
#define WASTED_C  0x04
#define WASTED_GC (0x02|0x04)
#define REGTAIL(x,y,z) regtail((x),(y),(z),depth+1)
#ifdef DEBUGGING
#define REGTAIL_STUDY(x,y,z) regtail_study((x),(y),(z),depth+1)
#else
#define REGTAIL_STUDY(x,y,z) regtail((x),(y),(z),depth+1)
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#if 0				
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifndef REG_ALLOW_MINMOD_SUSPEND
#endif
#ifdef DEBUGGING
#endif
#define MAX_NODE_STRING_SIZE 127
#define POSIXCC_DONE(c)   ((c) == ':')
#define POSIXCC_NOTYET(c) ((c) == '=' || (c) == '.')
#define POSIXCC(c) (POSIXCC_DONE(c) || POSIXCC_NOTYET(c))
#define IS_OPERAND(a)  (! SvIOK(a))
#undef IS_OPERAND
#define HAS_NONLOCALE_RUNTIME_PROPERTY_DEFINITION (SvCUR(listsv) != initial_listsv_len)
#ifdef EBCDIC
#endif
#ifndef DEBUGGING
#endif
#ifdef EBCDIC
#endif
#ifdef HAS_ISASCII
#endif  
#ifndef HAS_ISBLANK
#endif
#ifndef HAS_ISBLANK
#endif
#ifndef HAS_ISBLANK
#endif
#ifndef HAS_ISBLANK
#endif
#ifndef EBCDIC
#else
#endif
#if 0   
#endif
#if 0
#endif
#ifdef HAS_ISASCII
#else
#endif
#ifndef HAS_ISBLANK
#endif
#undef HAS_NONLOCALE_RUNTIME_PROPERTY_DEFINITION
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif            
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif    
#ifndef DEBUGGING
#endif
#ifdef DEBUGGING
#ifdef EXPERIMENTAL_INPLACESCAN
#endif
#ifdef EXPERIMENTAL_INPLACESCAN
#endif
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#else
#endif	
#define EMIT_ANYOF_TEST_SEPARATOR(do_sep,sv,flags)  STMT_START {          if (do_sep) {                                        Perl_sv_catpvf(aTHX_ sv,"%s][%s",PL_colors[1],PL_colors[0]);              if (flags & ANYOF_INVERT)                                              sv_catpvs(sv, "^");                          do_sep = 0;                                  }                                        } STMT_END
#ifdef DEBUGGING
#if _CC_WORDCHAR != 0 || _CC_DIGIT != 1 || _CC_ALPHA != 2 || _CC_LOWER != 3      || _CC_UPPER != 4 || _CC_PUNCT != 5 || _CC_PRINT != 6                        || _CC_ALPHANUMERIC != 7 || _CC_GRAPH != 8 || _CC_CASED != 9                 || _CC_SPACE != 10 || _CC_BLANK != 11 || _CC_XDIGIT != 12                    || _CC_PSXSPC != 13 || _CC_CNTRL != 14 || _CC_ASCII != 15                    || _CC_VERTSPACE != 16
  #error Need to adjust order of anyofs[]
#endif
#else
#endif	
#ifndef PERL_IN_XSUB_RE
#ifdef PERL_ANY_COW
#endif
#ifdef PERL_ANY_COW
#endif
#endif
#ifdef RE_TRACK_PATTERN_OFFSETS
#endif
#define av_dup_inc(s,t)	MUTABLE_AV(sv_dup_inc((const SV *)s,t))
#define hv_dup_inc(s,t)	MUTABLE_HV(sv_dup_inc((const SV *)s,t))
#define SAVEPVN(p,n)	((p) ? savepvn(p,n) : NULL)
#if defined(USE_ITHREADS)
#ifndef PERL_IN_XSUB_RE
#ifdef PERL_ANY_COW
#endif
#endif 
#ifdef RE_TRACK_PATTERN_OFFSETS
#else
#endif
#endif    
#ifndef PERL_IN_XSUB_RE
#endif
#ifdef I_STDARG
#else
#endif
#ifndef PERL_IN_XSUB_RE
#ifdef PERL_ANY_COW
#endif
#endif
#ifdef DEBUGGING
#define CLEAR_OPTSTART      if (optstart) STMT_START {  	    DEBUG_OPTIMISE_r(PerlIO_printf(Perl_debug_log, " (%"IVdf" nodes)\n", (IV)(node - optstart)));  	    optstart=NULL;      } STMT_END
#define DUMPUNTIL(b,e) CLEAR_OPTSTART; node=dumpuntil(r,start,(b),(e),last,sv,indent+1,depth+1);
#ifdef DEBUG_DUMPUNTIL
#endif
#ifdef DEBUGGING
#endif
#ifdef DEBUG_DUMPUNTIL    
#endif
#endif	
