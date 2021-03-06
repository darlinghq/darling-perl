#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>
#define U8 U8
#include "encode.h"
#include "cp_00_t.h"
#include "gb_02_t.h"
#include "ir_04_t.h"
#include "ma_05_t.h"
#include "gb_03_t.h"
#include "eu_01_t.h"

static void
Encode_XSEncoding(pTHX_ encode_t *enc)
{
 dSP;
 HV *stash = gv_stashpv("Encode::XS", TRUE);
 SV *sv    = sv_bless(newRV_noinc(newSViv(PTR2IV(enc))),stash);
 int i = 0;
 PUSHMARK(sp);
 XPUSHs(sv);
 while (enc->name[i])
  {
   const char *name = enc->name[i++];
   XPUSHs(sv_2mortal(newSVpvn(name,strlen(name))));
  }
 PUTBACK;
 call_pv("Encode::define_encoding",G_DISCARD);
 SvREFCNT_dec(sv);
}

MODULE = Encode::CN	PACKAGE = Encode::CN
PROTOTYPES: DISABLE
BOOT:
{
#include "cp_00_t.exh"
#include "gb_02_t.exh"
#include "ir_04_t.exh"
#include "ma_05_t.exh"
#include "gb_03_t.exh"
#include "eu_01_t.exh"
}
