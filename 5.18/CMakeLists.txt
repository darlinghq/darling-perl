project(perl-5.18)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/gen
)

add_darling_object_library(perlcore
	op.c
	perl.c
	gv.c
	toke.c
	perly.c
	pad.c
	regcomp.c
	dump.c
	util.c
	mg.c
	reentr.c
	mro.c
	keywords.c
	hv.c
	av.c
	run.c
	pp_hot.c
	sv.c
	pp.c
	scope.c
	pp_ctl.c
	pp_sys.c
	doop.c
	doio.c
	regexec.c
	utf8.c
	taint.c
	deb.c
	universal.c
	globals.c
	perlio.c
	perlapi.c
	numeric.c
	mathoms.c
	locale.c
	pp_pack.c
	pp_sort.c
	gen/DynaLoader.c
)

set_source_files_properties(FILES gen/perlmain.c PROPERTIES COMPILE_FLAGS "-DDOINIT")
add_darling_executable(perl5.18 gen/perlmain.c $<TARGET_OBJECTS:perlcore>)
make_fat(perl5.18)
set_property(TARGET perl5.18 perlcore APPEND_STRING PROPERTY COMPILE_FLAGS " -DPERL_CORE")

install(TARGETS perl5.18 DESTINATION libexec/darling/usr/bin)

# Bundles
set(bundir "libexec/darling/System/Library/Perl/5.18/darwin-thread-multi-2level/auto")
set(bunexdir "libexec/darling/System/Library/Perl/Extras/5.18/darwin-thread-multi-2level/auto")

function(add_bundle name)
	foreach(f IN LISTS ARGN)
		set(sources ${sources} ${f})
	endforeach(f)
	add_darling_bundle(${name} ${CMAKE_CURRENT_BINARY_DIR}/perl5.18 ${sources})
	set_target_properties(${name} PROPERTIES PREFIX "" SUFFIX ".bundle")
	set_property(TARGET "${name}" APPEND_STRING PROPERTY LINK_FLAGS " -Wl,-flat_namespace ")
	add_dependencies("${name}" perl5.18)
endfunction(add_bundle)

add_bundle(B
	gen/ext/B/B.c
)
target_include_directories(B PRIVATE gen/ext/B ext/B)
target_compile_definitions(B PRIVATE -DVERSION="1.35" -DXS_VERSION="1.35")
install(TARGETS B DESTINATION "${bundir}/B")

add_bundle(Bzip2
	cpan/Compress-Raw-Bzip2/bzip2-src/blocksort.c
	cpan/Compress-Raw-Bzip2/bzip2-src/huffman.c
	cpan/Compress-Raw-Bzip2/bzip2-src/crctable.c
	cpan/Compress-Raw-Bzip2/bzip2-src/randtable.c
	cpan/Compress-Raw-Bzip2/bzip2-src/compress.c
	cpan/Compress-Raw-Bzip2/bzip2-src/decompress.c
	cpan/Compress-Raw-Bzip2/bzip2-src/bzlib.c
	gen/cpan/Compress-Raw-Bzip2/bzip2-src/Bzip2.c
)
target_include_directories(Bzip2 PRIVATE cpan/Compress-Raw-Bzip2/bzip2-src cpan/Compress-Raw-Bzip2/fallback)
target_compile_definitions(Bzip2 PRIVATE -DVERSION="2.048" -DXS_VERSION="2.048" -DBZ_NO_STDIO)
install(TARGETS Bzip2 DESTINATION "${bundir}/Compress/Raw/Bzip2")

add_bundle(Zlib
	gen/cpan/Compress-Raw-Zlib/zlib-src/Zlib.c
	cpan/Compress-Raw-Zlib/zlib-src/adler32.c
	cpan/Compress-Raw-Zlib/zlib-src/crc32.c
	cpan/Compress-Raw-Zlib/zlib-src/infback.c
	cpan/Compress-Raw-Zlib/zlib-src/inflate.c
	cpan/Compress-Raw-Zlib/zlib-src/uncompr.c
	cpan/Compress-Raw-Zlib/zlib-src/compress.c
	cpan/Compress-Raw-Zlib/zlib-src/deflate.c
	cpan/Compress-Raw-Zlib/zlib-src/inffast.c
	cpan/Compress-Raw-Zlib/zlib-src/inftrees.c
	cpan/Compress-Raw-Zlib/zlib-src/trees.c
	cpan/Compress-Raw-Zlib/zlib-src/zutil.c
)
target_include_directories(Zlib PRIVATE cpan/Compress-Raw-Zlib/zlib-src cpan/Compress-Raw-Zlib/fallback)
target_compile_definitions(Zlib PRIVATE -DVERSION="2.048" -DXS_VERSION="2.048" -DNO_VIZ -DZ_SOLO -DGZIP_OS_CODE=3)
install(TARGETS Zlib DESTINATION "${bundir}/Compress/Raw/Zlib")

add_bundle(Cwd
	gen/dist/Cwd/Cwd.c
)
target_include_directories(Cwd PRIVATE gen/dist/Cwd)
target_compile_definitions(Cwd PRIVATE -DVERSION="3.39_02" -DXS_VERSION="3.39_02")
install(TARGETS Cwd DESTINATION "${bundir}/Cwd")

add_bundle(DB_File
	gen/cpan/DB_File/DB_File.c
	cpan/DB_File/version.c
)
target_include_directories(DB_File PRIVATE gen/cpan/DB_File)
target_compile_definitions(DB_File PRIVATE -DVERSION="1.826" -DXS_VERSION="1.826" -D_NOT_CORE -DmDB_Prefix_t=size_t -DmDB_Hash_t=u_int32_t)
install(TARGETS DB_File DESTINATION "${bundir}/DB_File")

add_bundle(Dumper
	gen/dist/Data-Dumper/Dumper.c
)
target_compile_definitions(Dumper PRIVATE -DVERSION="2.135_06" -DXS_VERSION="2.135_06")
install(TARGETS Dumper DESTINATION "${bundir}/Data/Dumper")

add_bundle(PPPort
	gen/cpan/Devel-PPPort/RealPPPort.c
	cpan/Devel-PPPort/module2.c
	cpan/Devel-PPPort/module3.c
)
target_include_directories(PPPort PRIVATE gen/cpan/Devel-PPPort)
target_compile_definitions(PPPort PRIVATE -DVERSION="3.20" -DXS_VERSION="3.20")
install(TARGETS PPPort DESTINATION "${bundir}/Devel/PPPort")

add_bundle(Peek
	gen/ext/Devel-Peek/Peek.c
)
target_compile_definitions(Peek PRIVATE -DVERSION="1.08" -DXS_VERSION="1.08")
install(TARGETS Peek DESTINATION "${bundir}/Devel/Peek")

add_bundle(MD5
	gen/cpan/Digest-MD5/MD5.c
)
target_compile_definitions(MD5 PRIVATE -DVERSION="2.51" -DXS_VERSION="2.51" -DU32_ALIGNMENT_REQUIRED)
install(TARGETS MD5 DESTINATION "${bundir}/Digest/MD5")

add_bundle(SHA
	gen/cpan/Digest-SHA/SHA.c
)
target_include_directories(SHA PRIVATE cpan/Digest-SHA)
target_compile_definitions(SHA PRIVATE -DVERSION="5.71" -DXS_VERSION="5.71" -DSHA_PERL_MODULE)
install(TARGETS SHA DESTINATION "${bundir}/Digest/SHA")
install(FILES cpan/Digest-SHA/shasum
	PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
	DESTINATION "libexec/darling/usr/bin"
)

add_bundle(Encode
	gen/cpan/Encode/Encode.c
	cpan/Encode/encengine.c
	gen/cpan/Encode/def_t.c
)
target_include_directories(Encode PRIVATE cpan/Encode/Encode gen/cpan/Encode)
target_compile_definitions(Encode PRIVATE -DVERSION="2.44_01" -DXS_VERSION="2.44_01")
install(TARGETS Encode DESTINATION "${bundir}/Encode")

add_bundle(Byte
	gen/cpan/Encode/Byte/Byte.c
	gen/cpan/Encode/Byte/byte_t.c
)
target_include_directories(Byte PRIVATE cpan/Encode/Encode gen/cpan/Encode/Byte)
target_compile_definitions(Byte PRIVATE -DVERSION="2.04" -DXS_VERSION="2.04")
install(TARGETS Byte DESTINATION "${bundir}/Encode/Byte")

add_bundle(CN
	gen/cpan/Encode/CN/CN.c
	gen/cpan/Encode/CN/cp_00_t.c
	gen/cpan/Encode/CN/eu_01_t.c
	gen/cpan/Encode/CN/gb_02_t.c
	gen/cpan/Encode/CN/gb_03_t.c
	gen/cpan/Encode/CN/ir_04_t.c
	gen/cpan/Encode/CN/ma_05_t.c
)
target_include_directories(CN PRIVATE cpan/Encode/Encode gen/cpan/Encode/CN)
target_compile_definitions(CN PRIVATE -DVERSION="2.03" -DXS_VERSION="2.03")
install(TARGETS CN DESTINATION "${bundir}/Encode/CN")

add_bundle(EBCDIC
	gen/cpan/Encode/EBCDIC/EBCDIC.c
	gen/cpan/Encode/EBCDIC/ebcdic_t.c
)
target_include_directories(EBCDIC PRIVATE cpan/Encode/Encode gen/cpan/Encode/EBCDIC)
target_compile_definitions(EBCDIC PRIVATE -DVERSION="2.02" -DXS_VERSION="2.02")
install(TARGETS EBCDIC DESTINATION "${bundir}/Encode/EBCDIC")

add_bundle(JP
	gen/cpan/Encode/JP/cp_00_t.c
	gen/cpan/Encode/JP/eu_01_t.c
	gen/cpan/Encode/JP/ji_02_t.c
	gen/cpan/Encode/JP/ji_03_t.c
	gen/cpan/Encode/JP/ji_04_t.c
	gen/cpan/Encode/JP/ma_05_t.c
	gen/cpan/Encode/JP/sh_06_t.c
)
target_include_directories(JP PRIVATE cpan/Encode/Encode gen/cpan/Encode/JP)
target_compile_definitions(JP PRIVATE -DVERSION="2.04" -DXS_VERSION="2.04")
install(TARGETS JP DESTINATION "${bundir}/Encode/JP")

add_bundle(KR
	gen/cpan/Encode/KR/KR.c
	gen/cpan/Encode/KR/cp_00_t.c
	gen/cpan/Encode/KR/eu_01_t.c
	gen/cpan/Encode/KR/jo_02_t.c
	gen/cpan/Encode/KR/ks_03_t.c
	gen/cpan/Encode/KR/ma_04_t.c
)
target_include_directories(KR PRIVATE cpan/Encode/Encode gen/cpan/Encode/KR)
target_compile_definitions(KR PRIVATE -DVERSION="2.03" -DXS_VERSION="2.03")
install(TARGETS KR DESTINATION "${bundir}/Encode/KR")

add_bundle(Symbol
	gen/cpan/Encode/Symbol/Symbol.c
	gen/cpan/Encode/Symbol/symbol_t.c
)
target_include_directories(Symbol PRIVATE cpan/Encode/Encode gen/cpan/Encode/Symbol)
target_compile_definitions(Symbol PRIVATE -DVERSION="2.02" -DXS_VERSION="2.02")
install(TARGETS Symbol DESTINATION "${bundir}/Encode/Symbol")

add_bundle(TW
	gen/cpan/Encode/TW/TW.c
	gen/cpan/Encode/TW/bi_00_t.c
	gen/cpan/Encode/TW/bi_01_t.c
	gen/cpan/Encode/TW/cp_02_t.c
	gen/cpan/Encode/TW/ma_03_t.c
)
target_include_directories(TW PRIVATE cpan/Encode/Encode gen/cpan/Encode/TW)
target_compile_definitions(TW PRIVATE -DVERSION="2.03" -DXS_VERSION="2.03")
install(TARGETS TW DESTINATION "${bundir}/Encode/TW")

add_bundle(Unicode
	gen/cpan/Encode/Unicode/Unicode.c
)
target_include_directories(Unicode PRIVATE cpan/Encode/Encode)
target_compile_definitions(Unicode PRIVATE -DVERSION="2.07" -DXS_VERSION="2.07")
install(TARGETS Unicode DESTINATION "${bundir}/Encode/Unicode")

add_bundle(Fcntl
	gen/ext/Fcntl/Fcntl.c
)
target_include_directories(Fcntl PRIVATE ext/Fcntl)
target_compile_definitions(Fcntl PRIVATE -DVERSION="1.11" -DXS_VERSION="1.11")
install(TARGETS Fcntl DESTINATION "${bundir}/Fcntl")

add_bundle(Glob
	gen/ext/File-Glob/Glob.c
	ext/File-Glob/bsd_glob.c
)
target_include_directories(Glob PRIVATE ext/File-Glob gen/ext/File-Glob)
target_compile_definitions(Glob PRIVATE -DVERSION="1.17" -DXS_VERSION="1.17")
install(TARGETS Glob DESTINATION "${bundir}/File/Glob")

add_bundle(Call
	gen/cpan/Filter-Util-Call/Call.c
)
target_compile_definitions(Call PRIVATE -DVERSION="1.40" -DXS_VERSION="1.40")
install(TARGETS Call DESTINATION "${bundir}/Filter/Util/Call")

add_bundle(Util
	gen/ext/Hash-Util/Util.c
)
target_compile_definitions(Util PRIVATE -DVERSION="0.11" -DXS_VERSION="0.11" -DPERL_EXT)
install(TARGETS Util DESTINATION "${bundir}/Hash/Util")

add_bundle(FieldHash
	gen/ext/Hash-Util-FieldHash/FieldHash.c
)
target_compile_definitions(FieldHash PRIVATE -DVERSION="1.10" -DXS_VERSION="1.10")
install(TARGETS FieldHash DESTINATION "${bundir}/Hash/Util/FieldHash")

add_bundle(Langinfo
	gen/ext/I18N-Langinfo/Langinfo.c
)
target_include_directories(Langinfo PRIVATE gen/ext/I18N-Langinfo)
target_compile_definitions(Langinfo PRIVATE -DVERSION="0.08_02" -DXS_VERSION="0.08_02")
install(TARGETS Langinfo DESTINATION "${bundir}/I18N/Langinfo")

add_bundle(IO
	gen/dist/IO/IO.c
	gen/dist/IO/poll.c
)
target_compile_definitions(IO PRIVATE -DVERSION="1.25_06" -DXS_VERSION="1.25_06")
install(TARGETS IO DESTINATION "${bundir}/IO")

add_bundle(SysV
	gen/cpan/IPC-SysV/SysV.c
)
target_include_directories(SysV PRIVATE gen/cpan/IPC-SysV)
target_compile_definitions(SysV PRIVATE -DVERSION="2.03" -DXS_VERSION="2.03")
install(TARGETS SysV DESTINATION "${bundir}/IPC/SysV")

add_bundle(List-Util
	gen/cpan/List-Util/ListUtil.c
)
# It has the same name as another target named "Util"
set_target_properties(List-Util PROPERTIES LIBRARY_OUTPUT_NAME Util LIBRARY_OUTPUT_DIRECTORY "List")
target_include_directories(List-Util PRIVATE gen/cpan/List-Util cpan/List-Util)
target_compile_definitions(List-Util PRIVATE -DVERSION="1.25" -DXS_VERSION="1.25")
install(TARGETS List-Util DESTINATION "${bundir}/List/Util" RENAME Util)

add_bundle(Base64
	gen/cpan/MIME-Base64/Base64.c
)
target_compile_definitions(Base64 PRIVATE -DVERSION="3.13" -DXS_VERSION="3.13")
install(TARGETS Base64 DESTINATION "${bundir}/MIME/Base64")

add_bundle(FastCalc
	gen/dist/Math-BigInt-FastCalc/FastCalc.c
)
target_compile_definitions(FastCalc PRIVATE -DVERSION="0.30" -DXS_VERSION="0.30")
install(TARGETS FastCalc DESTINATION "${bundir}/Math/BigInt/FastCalc")

add_bundle(NDBM_File
	gen/ext/NDBM_File/NDBM_File.c
)
target_compile_definitions(NDBM_File PRIVATE -DVERSION="1.12" -DXS_VERSION="1.12")
install(TARGETS NDBM_File DESTINATION "${bundir}/NDBM_File")

add_bundle(Opcode
	gen/ext/Opcode/Opcode.c
)
target_compile_definitions(Opcode PRIVATE -DVERSION="1.23" -DXS_VERSION="1.23")
install(TARGETS Opcode DESTINATION "${bundir}/Opcode")

add_bundle(POSIX
	gen/ext/POSIX/POSIX.c
)
target_include_directories(POSIX PRIVATE gen/ext/POSIX)
target_compile_definitions(POSIX PRIVATE -DVERSION="1.30" -DXS_VERSION="1.30")
install(TARGETS POSIX DESTINATION "${bundir}/POSIX")

add_bundle(encoding
	gen/ext/PerlIO-encoding/encoding.c
)
target_compile_definitions(encoding PRIVATE -DVERSION="0.15" -DXS_VERSION="0.15")
install(TARGETS encoding DESTINATION "${bundir}/PerlIO/encoding")

add_bundle(mmap
	gen/ext/PerlIO-mmap/mmap.c
)
target_compile_definitions(mmap PRIVATE -DVERSION="0.010" -DXS_VERSION="0.010")
install(TARGETS mmap DESTINATION "${bundir}/PerlIO/mmap")

add_bundle(scalar
	gen/ext/PerlIO-scalar/scalar.c
)
target_compile_definitions(scalar PRIVATE -DVERSION="0.14_01" -DXS_VERSION="0.14_01")
install(TARGETS scalar DESTINATION "${bundir}/PerlIO/scalar")

add_bundle(via
	gen/ext/PerlIO-via/via.c
)
target_compile_definitions(via PRIVATE -DVERSION="0.12" -DXS_VERSION="0.12")
install(TARGETS via DESTINATION "${bundir}/PerlIO/via")

add_bundle(SDBM_File
	gen/ext/SDBM_File/SDBM_File.c
	gen/ext/SDBM_File/sdbm/pair.c
	gen/ext/SDBM_File/sdbm/hash.c
	gen/ext/SDBM_File/sdbm/sdbm.c
)
target_include_directories(SDBM_File PRIVATE ext/SDBM_File ext/SDBM_File/sdbm)
set_source_files_properties(
	gen/ext/SDBM_File/sdbm/pair.c
	gen/ext/SDBM_File/sdbm/hash.c
	gen/ext/SDBM_File/sdbm/sdbm.c

	PROPERTIES COMPILE_FLAGS

	"-DVERSION=\\\"\\\" -DXS_VERSION=\\\"\\\" -DSDBM -DDUFF"
)
set_source_files_properties(
	gen/ext/SDBM_File/SDBM_File.c

	PROPERTIES COMPILE_FLAGS

	"-DPERL_EXTMALLOC_DEF -Dmalloc=Perl_malloc -Dfree=Perl_mfree -Drealloc=Perl_realloc -Dcalloc=Perl_calloc -DVERSION=\\\"1.09\\\" -DXS_VERSION=\\\"1.09\\\""
)
install(TARGETS SDBM_File DESTINATION "${bundir}/SDBM_File")

add_bundle(Socket
	gen/cpan/Socket/Socket.c
)
target_include_directories(Socket PRIVATE gen/cpan/Socket)
target_compile_definitions(Socket PRIVATE -DVERSION="2.001" -DXS_VERSION="2.001")
install(TARGETS Socket DESTINATION "${bundir}/Socket")

add_bundle(Storable
	gen/dist/Storable/Storable.c
)
target_compile_definitions(Storable PRIVATE -DVERSION="2.34" -DXS_VERSION="2.34")
install(TARGETS Storable DESTINATION "${bundir}/Storable")

add_bundle(Hostname
	gen/ext/Sys-Hostname/Hostname.c
)
target_compile_definitions(Hostname PRIVATE -DVERSION="1.16" -DXS_VERSION="1.16")
install(TARGETS Hostname DESTINATION "${bundir}/Sys/Hostname")

add_bundle(Syslog
	gen/cpan/Sys-Syslog/Syslog.c
)
target_include_directories(Syslog PRIVATE gen/cpan/Sys-Syslog)
target_compile_definitions(Syslog PRIVATE -DVERSION="0.29" -DXS_VERSION="0.29")
install(TARGETS Syslog DESTINATION "${bundir}/Sys/Syslog")

add_bundle(Soundex
	gen/cpan/Text-Soundex/Soundex.c
)
target_compile_definitions(Soundex PRIVATE -DVERSION="3.03_01" -DXS_VERSION="3.03_01")
install(TARGETS Soundex DESTINATION "${bundir}/Text/Soundex")

add_bundle(NamedCapture
	gen/ext/Tie-Hash-NamedCapture/NamedCapture.c
)
target_compile_definitions(NamedCapture PRIVATE -DVERSION="0.08" -DXS_VERSION="0.08")
install(TARGETS NamedCapture DESTINATION "${bundir}/Tie/Hash/NamedCapture")

add_bundle(HiRes
	gen/cpan/Time-HiRes/HiRes.c
)
target_include_directories(HiRes PRIVATE gen/cpan/Time-HiRes)
target_compile_definitions(HiRes PRIVATE -DVERSION="1.9725" -DXS_VERSION="1.9725" -DTIME_HIRES_NANOSLEEP -DTIME_HIRES_CLOCK_GETTIME -DTIME_HIRES_CLOCK_GETRES -DTIME_HIRES_CLOCK -DTIME_HIRES_STAT=1 -DATLEASTFIVEOHOHFIVE)
install(TARGETS HiRes DESTINATION "${bundir}/Time/HiRes")

add_bundle(Piece
	gen/cpan/Time-Piece/Piece.c
)
target_compile_definitions(Piece PRIVATE -DVERSION="1.20_01" -DXS_VERSION="1.20_01")
install(TARGETS Piece DESTINATION "${bundir}/Time/Piece")

add_bundle(Collate
	gen/cpan/Unicode-Collate/Collate.c
)
target_include_directories(Collate PRIVATE gen/cpan/Unicode-Collate)
target_compile_definitions(Collate PRIVATE -DVERSION="0.89" -DXS_VERSION="0.89")
install(TARGETS Collate DESTINATION "${bundir}/Unicode/Collate")

add_bundle(Normalize
	gen/cpan/Unicode-Normalize/Normalize.c
)
target_include_directories(Normalize PRIVATE gen/cpan/Unicode-Normalize)
target_compile_definitions(Normalize PRIVATE -DVERSION="1.14" -DXS_VERSION="1.14")
install(TARGETS Normalize DESTINATION "${bundir}/Unicode/Normalize")

add_bundle(arybase
	gen/ext/arybase/arybase.c
)
target_include_directories(arybase PRIVATE ext/arybase)
target_compile_definitions(arybase PRIVATE -DVERSION="0.05" -DXS_VERSION="0.05")
install(TARGETS arybase DESTINATION "${bundir}/arybase")

add_bundle(attributes
	gen/ext/attributes/attributes.c
)
target_compile_definitions(attributes PRIVATE -DVERSION="0.19" -DXS_VERSION="0.19")
install(TARGETS attributes DESTINATION "${bundir}/attributes")

add_bundle(mro
	gen/ext/mro/mro.c
)
target_compile_definitions(mro PRIVATE -DVERSION="1.09" -DXS_VERSION="1.09")
install(TARGETS mro DESTINATION "${bundir}/mro")

add_bundle(re
	gen/ext/re/re.c
	gen/ext/re/re_exec.c
		gen/ext/re/re_comp.c
)
target_include_directories(re PRIVATE gen/ext/re ext/re)
target_compile_definitions(re PRIVATE -DVERSION="0.19_01" -DXS_VERSION="0.19_01" -DPERL_EXT_RE_BUILD -DPERL_EXT_RE_DEBUG -DPERL_EXT)
install(TARGETS re DESTINATION "${bundir}/re")

add_bundle(threads
	gen/dist/threads/threads.c
)
target_compile_definitions(threads PRIVATE -DVERSION="1.86" -DXS_VERSION="1.86")
install(TARGETS threads DESTINATION "${bundir}/threads")

add_bundle(shared
	gen/dist/threads-shared/shared.c
)
target_compile_definitions(shared PRIVATE -DVERSION="1.40" -DXS_VERSION="1.40")
install(TARGETS shared DESTINATION "${bundir}/threads/shared")
