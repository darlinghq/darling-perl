#line 2 "perly.c"
#include "EXTERN.h"
#define PERL_IN_PERLY_C
#include "perl.h"
#define YYINITDEPTH 200
#ifdef YYDEBUG
#  undef YYDEBUG
#endif
#ifdef DEBUGGING
#  define YYDEBUG 1
#else
#  define YYDEBUG 0
#endif
#ifndef YY_NULL
# define YY_NULL 0
#endif
#include "perly.tab"
# define YYSIZE_T size_t
#define YYEOF		0
#define YYTERROR	1
#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1
#ifdef DEBUGGING
#  define yydebug (DEBUG_p_TEST)
#  define YYFPRINTF PerlIO_printf
#  define YYDPRINTF(Args)			 do {						     if (yydebug)				 	YYFPRINTF Args;				 } while (0)
#  define YYDSYMPRINTF(Title, Token, Value)			 do {								     if (yydebug) {						 	YYFPRINTF (Perl_debug_log, "%s ", Title);		 	yysymprint (aTHX_ Perl_debug_log,  Token, Value);	 	YYFPRINTF (Perl_debug_log, "\n");			     }								 } while (0)
#   ifdef YYPRINT
#   else
#   endif
#ifndef PERL_IN_MADLY_C
#endif
#  define YY_STACK_PRINT(parser)	 do {					     if (yydebug && DEBUG_v_TEST)	 	yy_stack_print (aTHX_ parser);	 } while (0)
#  define YY_REDUCE_PRINT(Rule)		 do {					     if (yydebug)			 	yy_reduce_print (aTHX_ Rule);		 } while (0)
#else 
#  define YYDPRINTF(Args)
#  define YYDSYMPRINTF(Title, Token, Value)
#  define YY_STACK_PRINT(parser)
#  define YY_REDUCE_PRINT(Rule)
#endif 
#ifdef PERL_IN_MADLY_C
#else
#endif
#define YYPOPSTACK   parser->ps = --ps
#define YYPUSHSTACK  parser->ps = ++ps
#ifndef PERL_IN_MADLY_C
#  ifdef PERL_MAD
#  endif
#endif
#ifdef PERL_IN_MADLY_C
#else
#endif
#  ifdef EBCDIC
#  endif
#ifdef DEBUGGING
#endif
#define dep() deprecate("\"do\" to call subroutines")
#ifdef PERL_IN_MADLY_C
#  define IVAL(i) (i)->tk_lval.ival
#  define PVAL(p) (p)->tk_lval.pval
#  define TOKEN_GETMAD(a,b,c) token_getmad((a),(b),(c))
#  define TOKEN_FREE(a) token_free(a)
#  define OP_GETMAD(a,b,c) op_getmad((a),(b),(c))
#  define IF_MAD(a,b) (a)
#  define DO_MAD(a) a
#  define MAD
#else
#  define IVAL(i) (i)
#  define PVAL(p) (p)
#  define TOKEN_GETMAD(a,b,c)
#  define TOKEN_FREE(a)
#  define OP_GETMAD(a,b,c)
#  define IF_MAD(a,b) (b)
#  define DO_MAD(a)
#  undef MAD
#endif
#include "perly.act"
#ifdef DEBUGGING
#endif
#ifdef DEBUGGING
#endif
