# $RCSfile: Makefile.SH,v 73960Revision: 4.1 73960Date: 92/08/07 18:29:07 $
#
# $Log:	Makefile.SH,v $

CC = /Users/ariel/private-bin/clang
BYACC = byacc
LDFLAGS =  -fstack-protector
shellflags = 

libs = 

#
# grrr
SHELL = /bin/sh

# These variables may need to be manually set for non-Unix systems.
AR = ar
EXE_EXT = 
LIB_EXT = .a
OBJ_EXT = .o
PATH_SEP = 

FIRSTMAKEFILE = GNUmakefile

# how to tr(anslate) newlines

TRNL = '\n'

OPTIMIZE = -Os

.SUFFIXES: .c $(OBJ_EXT)

RUN = 
PERL = ../miniperl


REALPERL = ../perl
CCCMD = `sh $(shellflags) cflags "optimize='$(OPTIMIZE)'" $@`

public = a2p$(EXE_EXT) s2p find2perl

private = 

manpages = a2p.man s2p.man

util =

sh = Makefile.SH cflags.SH
shextract = Makefile cflags

pl = find2perl.PL s2p.PL
plextract = find2perl s2p
plexe = find2perl.exe s2p.exe
plc   = find2perl.c s2p.c
plm   = a2p.loadmap

addedbyconf = $(shextract) $(plextract)

h = EXTERN.h INTERN.h ../config.h ../handy.h hash.h a2p.h str.h util.h

c = hash.c str.c util.c walk.c

obj = hash$(OBJ_EXT) str$(OBJ_EXT) util$(OBJ_EXT) walk$(OBJ_EXT)

lintflags = -phbvxac


.c$(OBJ_EXT):
	$(CCCMD) -DPERL_FOR_X2P $*.c

all: $(public) $(private) $(util)
	@echo " "

a2p$(EXE_EXT): $(obj) a2p$(OBJ_EXT)
	$(CC) -o a2p $(LDFLAGS) $(obj) a2p$(OBJ_EXT) $(libs)

# I now supply a2p.c with the kits, so the following section is
# used only if you force byacc to run by saying
#    make run_byacc
# byacc 1.8.2 or 1.9 are recommended.

run_byacc:	FORCE
	@ echo Expect many shift/reduce and reduce/reduce conflicts
	$(BYACC) a2p.y
	rm -f a2p.c
	sed -e 's/(yyn = yydefred\[yystate\])/((yyn = yydefred[yystate]))/' \
	    -e 's/(yys = getenv("YYDEBUG"))/((yys = getenv("YYDEBUG")))/' \
	    -e 's/^yyerrlab://' \
	    -e 's/^    goto yyerrlab;//' \
	    -e 's/^yynewerror://' \
	    -e 's/^    goto yynewerror;//' \
	    -e 's|^static char yysccsid\(.*\)|/* static char yysccsid\1 */|' \
	    -e 's/^\(char \*yyname\[\]\)/const \1/' \
	    -e 's/^\(char \*yyrule\[\]\)/const \1/' \
	    -e 's/^\(    register\) \(char \*yys;\)/\1 const \2/' \
	    < y.tab.c > a2p.c

FORCE:

# We don't want to regenerate a2p.c, but it might appear out-of-date
# after a patch is applied or a new distribution is made.
a2p.c: a2p.y
	-@sh -c true

a2p$(OBJ_EXT): a2p.c a2py.c a2p.h EXTERN.h util.h INTERN.h \
		../handy.h ../config.h str.h hash.h
	$(CCCMD) a2p.c

clean:
	rm -f a2p$(EXE_EXT) psed *$(OBJ_EXT) $(plexe) $(plc) $(plm)

distclean: veryclean

realclean: clean
	-rmdir .depending
	rm -f core $(addedbyconf) all
	rm -f $(FIRSTMAKEFILE) $(FIRSTMAKEFILE).old makefile.old

veryclean: realclean
	rm -f *~ *.orig

# The following lint has practically everything turned on.  Unfortunately,
# you have to wade through a lot of mumbo jumbo that can't be suppressed.
# If the source file has a /*NOSTRICT*/ somewhere, ignore the lint message
# for that spot.

lint:
	lint $(lintflags) $(defs) $(c) > a2p.fuzz

depend: ../makedepend
	sh ../makedepend MAKE=$(MAKE)

clist:
	echo $(c) | tr ' ' $(TRNL) >.clist

hlist:
	echo $(h) | tr ' ' $(TRNL) >.hlist

shlist:
	echo $(sh) | tr ' ' $(TRNL) >.shlist

$(plextract):
	$(RUN) $(PERL) -I../lib $@.PL

find2perl: find2perl.PL ../config.sh

s2p: s2p.PL ../config.sh

# AUTOMATICALLY GENERATED MAKE DEPENDENCIES--PUT NOTHING BELOW THIS LINE
# If this runs make out of memory, delete /usr/include lines.
hash$(OBJ_EXT): ../config.h
hash$(OBJ_EXT): ../handy.h
hash$(OBJ_EXT): /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.3/include/stdbool.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/Availability.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctermid.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctype.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_stdio.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/alloca.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/architecture/i386/math.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/ctype.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_mcontext.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/endian.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/signal.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/inttypes.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/_OSByteOrder.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/i386/_OSByteOrder.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/i386/_structs.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/endian.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/signal.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/malloc/_malloc.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/math.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/runetype.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_common.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_string.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_strings.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdint.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdlib.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/string.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/strings.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_endian.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_attr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_cond_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_condattr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_key_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutex_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutexattr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_once_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlock_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlockattr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_select.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blkcnt_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blksize_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_caddr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ct_rune_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_errno_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_clr.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_copy.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_isset.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_set.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_setsize.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_zero.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsblkcnt_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsfilcnt_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_id_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_addr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_port_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino64_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_key_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_nlink_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rsize_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rune_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval64.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_char.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_short.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/resource.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/signal.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/stdio.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/time.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/times.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/types.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/wait.h
hash$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/time.h
hash$(OBJ_EXT): EXTERN.h
hash$(OBJ_EXT): a2p.h
hash$(OBJ_EXT): hash.c
hash$(OBJ_EXT): hash.h
hash$(OBJ_EXT): str.h
hash$(OBJ_EXT): util.h
hash$(OBJ_EXT): cflags
str$(OBJ_EXT): ../config.h
str$(OBJ_EXT): ../handy.h
str$(OBJ_EXT): /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.3/include/stdbool.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/Availability.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctermid.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctype.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_stdio.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/alloca.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/architecture/i386/math.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/ctype.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_mcontext.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/endian.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/signal.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/inttypes.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/_OSByteOrder.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/i386/_OSByteOrder.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/i386/_structs.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/endian.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/signal.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/malloc/_malloc.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/math.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/runetype.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_common.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_string.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_strings.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdint.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdlib.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/string.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/strings.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_endian.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_attr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_cond_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_condattr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_key_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutex_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutexattr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_once_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlock_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlockattr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_select.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blkcnt_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blksize_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_caddr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ct_rune_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_errno_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_clr.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_copy.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_isset.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_set.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_setsize.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_zero.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsblkcnt_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsfilcnt_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_id_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_addr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_port_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino64_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_key_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_nlink_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rsize_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rune_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval64.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_char.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_short.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/resource.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/signal.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/stdio.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/time.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/times.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/types.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/wait.h
str$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/time.h
str$(OBJ_EXT): EXTERN.h
str$(OBJ_EXT): a2p.h
str$(OBJ_EXT): hash.h
str$(OBJ_EXT): str.c
str$(OBJ_EXT): str.h
str$(OBJ_EXT): util.h
str$(OBJ_EXT): cflags
util$(OBJ_EXT): ../config.h
util$(OBJ_EXT): ../handy.h
util$(OBJ_EXT): /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.3/include/stdarg.h
util$(OBJ_EXT): /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.3/include/stdbool.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/Availability.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctermid.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctype.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_stdio.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/alloca.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/architecture/i386/math.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/ctype.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_mcontext.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/endian.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/signal.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/inttypes.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/_OSByteOrder.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/i386/_OSByteOrder.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/i386/_structs.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/endian.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/signal.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/malloc/_malloc.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/math.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/runetype.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_common.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_string.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_strings.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdint.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdlib.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/string.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/strings.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_endian.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_attr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_cond_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_condattr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_key_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutex_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutexattr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_once_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlock_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlockattr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_select.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blkcnt_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blksize_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_caddr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ct_rune_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_errno_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_clr.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_copy.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_isset.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_set.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_setsize.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_zero.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsblkcnt_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsfilcnt_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_id_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_addr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_port_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino64_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_key_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_nlink_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rsize_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rune_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval64.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_char.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_short.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/resource.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/signal.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/stdio.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/time.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/times.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/types.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/wait.h
util$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/time.h
util$(OBJ_EXT): EXTERN.h
util$(OBJ_EXT): INTERN.h
util$(OBJ_EXT): a2p.h
util$(OBJ_EXT): hash.h
util$(OBJ_EXT): str.h
util$(OBJ_EXT): util.c
util$(OBJ_EXT): util.h
util$(OBJ_EXT): cflags
walk$(OBJ_EXT): ../config.h
walk$(OBJ_EXT): ../handy.h
walk$(OBJ_EXT): /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.3/include/stdbool.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/Availability.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctermid.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_ctype.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_stdio.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/alloca.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/architecture/i386/math.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/ctype.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_mcontext.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/_types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/endian.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/signal.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/i386/types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/inttypes.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/_OSByteOrder.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/libkern/i386/_OSByteOrder.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/i386/_structs.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/_types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/endian.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/signal.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/machine/types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/malloc/_malloc.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/math.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/runetype.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_common.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_string.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/secure/_strings.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdint.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdio.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/stdlib.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/string.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/strings.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_endian.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_attr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_cond_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_condattr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_key_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutex_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_mutexattr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_once_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlock_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_rwlockattr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_select.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blkcnt_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_blksize_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_caddr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ct_rune_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_errno_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_clr.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_copy.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_isset.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_set.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_setsize.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_zero.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsblkcnt_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_fsfilcnt_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_id_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_addr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_in_port_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino64_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_key_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_nlink_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rsize_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_rune_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval64.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_char.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_short.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/resource.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/signal.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/stdio.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/time.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/times.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/types.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/sys/wait.h
walk$(OBJ_EXT): /Users/ariel/git/darling/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/time.h
walk$(OBJ_EXT): EXTERN.h
walk$(OBJ_EXT): a2p.h
walk$(OBJ_EXT): hash.h
walk$(OBJ_EXT): str.h
walk$(OBJ_EXT): util.h
walk$(OBJ_EXT): walk.c
walk$(OBJ_EXT): cflags
cflags: cflags.SH ../config.sh ; /bin/sh cflags.SH
# WARNING: Put nothing here or make depend will gobble it up!
