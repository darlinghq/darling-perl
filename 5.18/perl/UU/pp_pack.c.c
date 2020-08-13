#line 2 "pp_pack.c"
#include "EXTERN.h"
#define PERL_IN_PP_PACK_C
#include "perl.h"
#define TEMPSYM_INIT(symptr, p, e, f)      STMT_START {	 	(symptr)->patptr   = (p);	 	(symptr)->patend   = (e);	 	(symptr)->grpbeg   = NULL;	 	(symptr)->grpend   = NULL;	 	(symptr)->grpend   = NULL;	 	(symptr)->code     = 0;		 	(symptr)->length   = 0;		 	(symptr)->howlen   = e_no_len;	 	(symptr)->level    = 0;		 	(symptr)->flags    = (f);	 	(symptr)->strbeg   = 0;		 	(symptr)->previous = NULL;	    } STMT_END
#if defined(HAS_LONG_DOUBLE) && defined(USE_LONG_DOUBLE)
#endif
#if PERL_VERSION >= 9
# define PERL_PACK_CAN_BYTEORDER
# define PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifndef CHAR_BIT
# define CHAR_BIT	8
#endif
#define UTF8_EXPAND	2
#define SIZE16 2
#define SIZE32 4
#if U16SIZE > SIZE16 || U32SIZE > SIZE32
#  if BYTEORDER == 0x1234 || BYTEORDER == 0x12345678    
#    define OFF16(p)	((char*)(p))
#    define OFF32(p)	((char*)(p))
#  else
#    if BYTEORDER == 0x4321 || BYTEORDER == 0x87654321  
#      define OFF16(p)	((char*)(p) + (sizeof(U16) - SIZE16))
#      define OFF32(p)	((char*)(p) + (sizeof(U32) - SIZE32))
#    else
#    endif
#  endif
#else
#  define OFF16(p)     ((char *) (p))
#  define OFF32(p)     ((char *) (p))
#endif
#define SHIFT16(utf8, s, strend, p, datumtype) STMT_START {		     if (utf8) {								 	if (!uni_to_bytes(aTHX_ &(s), strend, OFF16(p), SIZE16, datumtype)) break;	     } else {								 	Copy(s, OFF16(p), SIZE16, char);				 	(s) += SIZE16;							     }									 } STMT_END
#define SHIFT32(utf8, s, strend, p, datumtype) STMT_START {		     if (utf8) {								 	if (!uni_to_bytes(aTHX_ &(s), strend, OFF32(p), SIZE32, datumtype)) break;	     } else {								 	Copy(s, OFF32(p), SIZE32, char);				 	(s) += SIZE32;							     }									 } STMT_END
#define PUSH16(utf8, cur, p) PUSH_BYTES(utf8, cur, OFF16(p), SIZE16)
#define PUSH32(utf8, cur, p) PUSH_BYTES(utf8, cur, OFF32(p), SIZE32)
#define SHIFT_BYTES(utf8, s, strend, buf, len, datumtype)	 STMT_START {						     if (utf8) {						         if (!uni_to_bytes(aTHX_ &s, strend,		 	  (char *) (buf), len, datumtype)) break;	     } else {						         Copy(s, (char *) (buf), len, char);		         s += len;					     }							 } STMT_END
#define SHIFT_VAR(utf8, s, strend, var, datumtype)	        SHIFT_BYTES(utf8, s, strend, &(var), sizeof(var), datumtype)
#define PUSH_VAR(utf8, aptr, var)	 	PUSH_BYTES(utf8, aptr, &(var), sizeof(var))
#define MAX_SUB_TEMPLATE_LEVEL 100
#define FLAG_WAS_UTF8	      0x40
#define FLAG_PARSE_UTF8       0x20	
#define FLAG_UNPACK_ONLY_ONE  0x10
#define FLAG_DO_UTF8          0x08	
#define FLAG_SLASH            0x04
#define FLAG_COMMA            0x02
#define FLAG_PACK             0x01
#if 'I' == 73 && 'J' == 74
#define ISUUCHAR(ch)    ((ch) >= ' ' && (ch) < 'a')
#else
#define ISUUCHAR(ch)    (memchr(PL_uuemap, (ch), sizeof(PL_uuemap)-1) || (ch) == ' ')
#endif
#define TYPE_IS_SHRIEKING	0x100
#define TYPE_IS_BIG_ENDIAN	0x200
#define TYPE_IS_LITTLE_ENDIAN	0x400
#define TYPE_IS_PACK		0x800
#define TYPE_ENDIANNESS_MASK	(TYPE_IS_BIG_ENDIAN|TYPE_IS_LITTLE_ENDIAN)
#define TYPE_MODIFIERS(t)	((t) & ~0xFF)
#define TYPE_NO_MODIFIERS(t)	((t) & 0xFF)
#ifdef PERL_PACK_CAN_SHRIEKSIGN
# define SHRIEKING_ALLOWED_TYPES "sSiIlLxXnNvV@."
#else
# define SHRIEKING_ALLOWED_TYPES "sSiIlLxX"
#endif
#ifndef PERL_PACK_CAN_BYTEORDER
# define TYPE_ENDIANNESS(t)	0
# define TYPE_NO_ENDIANNESS(t)	(t)
# define ENDIANNESS_ALLOWED_TYPES   ""
# define DO_BO_UNPACK(var, type)
# define DO_BO_PACK(var, type)
# define DO_BO_UNPACK_PTR(var, type, pre_cast, post_cast)
# define DO_BO_PACK_PTR(var, type, pre_cast, post_cast)
# define DO_BO_UNPACK_N(var, type)
# define DO_BO_PACK_N(var, type)
# define DO_BO_UNPACK_P(var)
# define DO_BO_PACK_P(var)
# define DO_BO_UNPACK_PC(var)
# define DO_BO_PACK_PC(var)
#else 
# define TYPE_ENDIANNESS(t)	((t) & TYPE_ENDIANNESS_MASK)
# define TYPE_NO_ENDIANNESS(t)	((t) & ~TYPE_ENDIANNESS_MASK)
# define ENDIANNESS_ALLOWED_TYPES   "sSiIlLqQjJfFdDpP("
# define DO_BO_UNPACK(var, type)                                                       STMT_START {                                                                     switch (TYPE_ENDIANNESS(datumtype)) {                                            case TYPE_IS_BIG_ENDIAN:    var = my_betoh ## type (var); break;               case TYPE_IS_LITTLE_ENDIAN: var = my_letoh ## type (var); break;               default: break;                                                              }                                                                            } STMT_END
# define DO_BO_PACK(var, type)                                                         STMT_START {                                                                     switch (TYPE_ENDIANNESS(datumtype)) {                                            case TYPE_IS_BIG_ENDIAN:    var = my_htobe ## type (var); break;               case TYPE_IS_LITTLE_ENDIAN: var = my_htole ## type (var); break;               default: break;                                                              }                                                                            } STMT_END
# define DO_BO_UNPACK_PTR(var, type, pre_cast, post_cast)                              STMT_START {                                                                     switch (TYPE_ENDIANNESS(datumtype)) {                                            case TYPE_IS_BIG_ENDIAN:                                                         var = (post_cast*) my_betoh ## type ((pre_cast) var);                          break;                                                                       case TYPE_IS_LITTLE_ENDIAN:                                                      var = (post_cast *) my_letoh ## type ((pre_cast) var);                         break;                                                                       default:                                                                         break;                                                                     }                                                                            } STMT_END
# define DO_BO_PACK_PTR(var, type, pre_cast, post_cast)                                STMT_START {                                                                     switch (TYPE_ENDIANNESS(datumtype)) {                                            case TYPE_IS_BIG_ENDIAN:                                                         var = (post_cast *) my_htobe ## type ((pre_cast) var);                         break;                                                                       case TYPE_IS_LITTLE_ENDIAN:                                                      var = (post_cast *) my_htole ## type ((pre_cast) var);                         break;                                                                       default:                                                                         break;                                                                     }                                                                            } STMT_END
# define BO_CANT_DOIT(action, type)                                                    STMT_START {                                                                     switch (TYPE_ENDIANNESS(datumtype)) {                                             case TYPE_IS_BIG_ENDIAN:                                                         Perl_croak(aTHX_ "Can't %s big-endian %ss on this "                                             "platform", #action, #type);                                  break;                                                                       case TYPE_IS_LITTLE_ENDIAN:                                                      Perl_croak(aTHX_ "Can't %s little-endian %ss on this "                                          "platform", #action, #type);                                  break;                                                                       default:                                                                         break;                                                                     }                                                                            } STMT_END
# if PTRSIZE == INTSIZE
#  define DO_BO_UNPACK_P(var)	DO_BO_UNPACK_PTR(var, i, int, void)
#  define DO_BO_PACK_P(var)	DO_BO_PACK_PTR(var, i, int, void)
#  define DO_BO_UNPACK_PC(var)	DO_BO_UNPACK_PTR(var, i, int, char)
#  define DO_BO_PACK_PC(var)	DO_BO_PACK_PTR(var, i, int, char)
# elif PTRSIZE == LONGSIZE
#  if LONGSIZE < IVSIZE && IVSIZE == 8
#   define DO_BO_UNPACK_P(var)	DO_BO_UNPACK_PTR(var, 64, IV, void)
#   define DO_BO_PACK_P(var)	DO_BO_PACK_PTR(var, 64, IV, void)
#   define DO_BO_UNPACK_PC(var)	DO_BO_UNPACK_PTR(var, 64, IV, char)
#   define DO_BO_PACK_PC(var)	DO_BO_PACK_PTR(var, 64, IV, char)
#  else
#   define DO_BO_UNPACK_P(var)	DO_BO_UNPACK_PTR(var, l, IV, void)
#   define DO_BO_PACK_P(var)	DO_BO_PACK_PTR(var, l, IV, void)
#   define DO_BO_UNPACK_PC(var)	DO_BO_UNPACK_PTR(var, l, IV, char)
#   define DO_BO_PACK_PC(var)	DO_BO_PACK_PTR(var, l, IV, char)
#  endif
# elif PTRSIZE == IVSIZE
#  define DO_BO_UNPACK_P(var)	DO_BO_UNPACK_PTR(var, l, IV, void)
#  define DO_BO_PACK_P(var)	DO_BO_PACK_PTR(var, l, IV, void)
#  define DO_BO_UNPACK_PC(var)	DO_BO_UNPACK_PTR(var, l, IV, char)
#  define DO_BO_PACK_PC(var)	DO_BO_PACK_PTR(var, l, IV, char)
# else
#  define DO_BO_UNPACK_P(var)	BO_CANT_DOIT(unpack, pointer)
#  define DO_BO_PACK_P(var)	BO_CANT_DOIT(pack, pointer)
#  define DO_BO_UNPACK_PC(var)	BO_CANT_DOIT(unpack, pointer)
#  define DO_BO_PACK_PC(var)	BO_CANT_DOIT(pack, pointer)
# endif
# if defined(my_htolen) && defined(my_letohn) &&      defined(my_htoben) && defined(my_betohn)
#  define DO_BO_UNPACK_N(var, type)                                                     STMT_START {                                                                     switch (TYPE_ENDIANNESS(datumtype)) {                                            case TYPE_IS_BIG_ENDIAN:    my_betohn(&var, sizeof(type)); break;              case TYPE_IS_LITTLE_ENDIAN: my_letohn(&var, sizeof(type)); break;              default: break;                                                              }                                                                            } STMT_END
#  define DO_BO_PACK_N(var, type)                                                       STMT_START {                                                                     switch (TYPE_ENDIANNESS(datumtype)) {                                            case TYPE_IS_BIG_ENDIAN:    my_htoben(&var, sizeof(type)); break;              case TYPE_IS_LITTLE_ENDIAN: my_htolen(&var, sizeof(type)); break;              default: break;                                                              }                                                                            } STMT_END
# else
#  define DO_BO_UNPACK_N(var, type)	BO_CANT_DOIT(unpack, type)
#  define DO_BO_PACK_N(var, type)	BO_CANT_DOIT(pack, type)
# endif
#endif 
#define PACK_SIZE_CANNOT_CSUM		0x80
#define PACK_SIZE_UNPREDICTABLE		0x40	
#define PACK_SIZE_MASK			0x3F
#if TYPE_IS_SHRIEKING != 0x100
#endif
#if 'J'-'I' == 1
#if defined(HAS_LONG_DOUBLE) && defined(USE_LONG_DOUBLE)
#else
#endif
#if defined(HAS_QUAD)
#else
#endif
#if defined(HAS_QUAD)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#else
#if defined(HAS_QUAD)
#else
#endif
#if defined(HAS_LONG_DOUBLE) && defined(USE_LONG_DOUBLE)
#else
#endif
#if defined(HAS_QUAD)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#if defined(PERL_PACK_CAN_SHRIEKSIGN)
#else
#endif
#endif
#define SHIFT_BYTE(utf8, s, strend, datumtype) ((utf8) ?  	uni_to_byte(aTHX_ &(s), (strend), (datumtype)) :  	*(U8 *)(s)++)
#define PUSH_BYTES(utf8, cur, buf, len)				 STMT_START {							     if (utf8)							 	(cur) = bytes_to_uni((U8 *) buf, len, (cur));		     else {							 	Copy(buf, cur, len, char);				 	(cur) += (len);						     }								 } STMT_END
#define SAFE_UTF8_EXPAND(var)	 STMT_START {				     if ((var) > SSize_t_MAX / UTF8_EXPAND)          Perl_croak(aTHX_ "%s", "Out of memory during pack()");      (var) = (var) * UTF8_EXPAND;  } STMT_END
#define GROWING2(utf8, cat, start, cur, item_size, item_count)	 STMT_START {							     if (SSize_t_MAX / (item_size) < (item_count))		         Perl_croak(aTHX_ "%s", "Out of memory during pack()");	     GROWING((utf8), (cat), (start), (cur), (item_size) * (item_count));  } STMT_END
#define GROWING(utf8, cat, start, cur, in_len)	 STMT_START {					     STRLEN glen = (in_len);			     STRLEN catcur = (STRLEN)((cur) - (start));	     if (utf8) SAFE_UTF8_EXPAND(glen);		     if (SSize_t_MAX - glen < catcur)		         Perl_croak(aTHX_ "%s", "Out of memory during pack()");      if (catcur + glen >= SvLEN(cat)) {	 	(start) = sv_exp_grow(cat, glen);	 	(cur) = (start) + SvCUR(cat);		     }						 } STMT_END
#define PUSH_GROWING_BYTES(utf8, cat, start, cur, buf, in_len)  STMT_START {					     const STRLEN glen = (in_len);		     STRLEN gl = glen;				     if (utf8) SAFE_UTF8_EXPAND(gl);		     if ((cur) + gl >= (start) + SvLEN(cat)) {	         *cur = '\0';				         SvCUR_set((cat), (cur) - (start));	 	(start) = sv_exp_grow(cat, gl);		 	(cur) = (start) + SvCUR(cat);		     }						     PUSH_BYTES(utf8, cur, buf, glen);		 } STMT_END
#define PUSH_BYTE(utf8, s, byte)		 STMT_START {					     if (utf8) {					 	const U8 au8 = (byte);			 	(s) = bytes_to_uni(&au8, 1, (s));	     } else *(U8 *)(s)++ = (byte);		 } STMT_END
#define NEXT_UNI_VAL(val, cur, str, end, utf8_flags)		 STMT_START {							     STRLEN retlen;						     if (str >= end) break;					     val = utf8n_to_uvchr((U8 *) str, end-str, &retlen, utf8_flags);	     if (retlen == (STRLEN) -1 || retlen == 0) {			 	*cur = '\0';						 	Perl_croak(aTHX_ "Malformed UTF-8 string in pack");	     }								     str += retlen;						 } STMT_END
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef PERL_PACK_CAN_BYTEORDER
#endif 
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#else 
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#else 
#endif
#if SHORTSIZE != SIZE16
#else
#endif
#if U16SIZE > SIZE16
#endif
#if U16SIZE > SIZE16
#endif
#if SHORTSIZE != SIZE16
#else
#endif
#if U16SIZE > SIZE16
#endif
#ifdef HAS_NTOHS
#endif
#ifdef HAS_VTOHS
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
# if U16SIZE > SIZE16
# endif
# ifdef HAS_NTOHS
# endif 
# ifdef HAS_VTOHS
# endif 
#endif 
#if IVSIZE == INTSIZE
#elif IVSIZE == LONGSIZE
#elif defined(HAS_QUAD) && IVSIZE == U64SIZE
#else
#endif
#if IVSIZE == INTSIZE
#elif IVSIZE == LONGSIZE
#elif defined(HAS_QUAD) && IVSIZE == U64SIZE
#else
#endif
#if LONGSIZE != SIZE32
#else
#endif
#if U32SIZE > SIZE32
#endif
#if U32SIZE > SIZE32
#endif
#if LONGSIZE != SIZE32
#else
#endif
#if U32SIZE > SIZE32
#endif
#ifdef HAS_NTOHL
#endif
#ifdef HAS_VTOHL
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
# if U32SIZE > SIZE32
# endif
# ifdef HAS_NTOHL
# endif
# ifdef HAS_VTOHL
# endif
#endif 
#ifdef HAS_QUAD
#endif 
#if defined(HAS_LONG_DOUBLE) && defined(USE_LONG_DOUBLE)
#endif
#define NEXTFROM (lengthcode ? lengthcode : items-- > 0 ? *beglist++ : &PL_sv_no)
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#else 
#endif
# if defined(VMS) && !defined(_IEEE_FP)
# else
# endif
# if defined(VMS) && !defined(_IEEE_FP)
# else
# endif
#ifdef __GNUC__
#else
#endif
#if defined(HAS_LONG_DOUBLE) && defined(USE_LONG_DOUBLE)
#  ifdef __GNUC__
#  else
#  endif
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef HAS_HTONS
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef HAS_HTOVS
#endif
#if SHORTSIZE != SIZE16
#else
#endif
#if SHORTSIZE != SIZE16
#else
#endif
#if IVSIZE == INTSIZE
#elif IVSIZE == LONGSIZE
#elif defined(HAS_QUAD) && IVSIZE == U64SIZE
#else
#endif
#if UVSIZE == INTSIZE
#elif UVSIZE == LONGSIZE
#elif defined(HAS_QUAD) && UVSIZE == U64SIZE
#else
#endif
#ifdef NV_MAX_10_EXP
#else
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef HAS_HTONL
#endif
#ifdef PERL_PACK_CAN_SHRIEKSIGN
#endif
#ifdef HAS_HTOVL
#endif
#if LONGSIZE != SIZE32
#else
#endif
#if LONGSIZE != SIZE32
#else
#endif
#ifdef HAS_QUAD
#endif 
#undef NEXTFROM
