project(perl-5.18)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/perl
)

#
# libperl
#

set(DYLIB_INSTALL_NAME "/System/Library/Perl/5.18/darwin-thread-multi-2level/CORE/libperl.dylib")
set(DYLIB_CURRENT_VERSION "5.18.4")
set(DYLIB_COMPAT_VERSION "5.18.0")

add_darling_library(libperl5.18
	perl/av.c
	perl/deb.c
	perl/doio.c
	perl/doop.c
	perl/dump.c
	perl/globals.c
	perl/gv.c
	perl/hv.c
	perl/keywords.c
	perl/locale.c
	perl/mathoms.c
	perl/mg.c
	perl/mro.c
	perl/numeric.c
	perl/op.c
	perl/pad.c
	perl/perl.c
	perl/perlapi.c
	perl/perlio.c
	perl/perly.c
	perl/pp_ctl.c
	perl/pp_hot.c
	perl/pp_pack.c
	perl/pp_sort.c
	perl/pp_sys.c
	perl/pp.c
	perl/reentr.c
	perl/regcomp.c
	perl/regexec.c
	perl/run.c
	perl/scope.c
	perl/sv.c
	perl/taint.c
	perl/toke.c
	perl/universal.c
	perl/utf8.c
	perl/util.c

	perl/ext/DynaLoader/DynaLoader.c
)

set_source_files_properties(perl/ext/DynaLoader/DynaLoader.c PROPERTIES
	COMPILE_DEFINITIONS "VERSION=\"1.18\";XS_VERSION=\"1.18\";LIBC="
)

target_compile_definitions(libperl5.18 PRIVATE
	PERL_CORE
)
target_link_libraries(libperl5.18
	system
)

set_target_properties(libperl5.18 PROPERTIES
	OUTPUT_NAME "perl"
)

install(TARGETS libperl5.18 DESTINATION libexec/darling/System/Library/Perl/5.18/darwin-thread-multi-2level/CORE)

#
# perl executable
#

add_darling_executable(perl5.18
	perl/perlmain.c
)
make_fat(perl5.18)

target_compile_definitions(perl5.18 PRIVATE
	PERL_CORE
)
target_link_libraries(perl5.18
	libperl5.18
)

install(TARGETS perl5.18 DESTINATION libexec/darling/usr/bin)

#
# bundle helper function
#

function(add_bundle install_path version)
	foreach(f IN LISTS ARGN)
		set(sources ${sources} ${f})
	endforeach()

	string(REPLACE "/" "_" name "${install_path}")
	set(name "perl5.18_${name}")

	get_filename_component(bundle_name "${install_path}" NAME)
	get_filename_component(dir_name "${install_path}" DIRECTORY)

	add_darling_bundle("${name}" ${CMAKE_CURRENT_BINARY_DIR}/libperl.dylib ${sources})

	set_target_properties("${name}" PROPERTIES
		PREFIX ""
		OUTPUT_NAME "${bundle_name}"
		SUFFIX ".bundle"
	)

	target_link_options("${name}" PRIVATE
		-Wl,-flat_namespace
	)

	add_dependencies("${name}" libperl5.18)

	target_compile_definitions("${name}" PRIVATE
		VERSION="${version}"
		XS_VERSION="${version}"
	)

	install(TARGETS "${name}" DESTINATION "libexec/darling/System/Library/Perl/5.18/darwin-thread-multi-2level/auto/${dir_name}")
endfunction(add_bundle)

#
# actual bundle definitions
#

add_bundle(arybase/arybase 0.06
	perl/ext/arybase/arybase.c
)

add_bundle(attributes/attributes 0.21
	perl/ext/attributes/attributes.c
)

add_bundle(B/B 1.42_02
	perl/ext/B/B.c
)

add_bundle(Compress/Raw/Bzip2/Bzip2 2.060
	perl/cpan/Compress-Raw-Bzip2/Bzip2.c
)
target_compile_definitions(perl5.18_Compress_Raw_Bzip2_Bzip2 PRIVATE
	BZ_NO_STDIO
)
target_link_libraries(perl5.18_Compress_Raw_Bzip2_Bzip2
	bz2
)

add_bundle(Compress/Raw/Zlib/Zlib 2.060
	perl/cpan/Compress-Raw-Zlib/Zlib.c
)
target_compile_definitions(perl5.18_Compress_Raw_Zlib_Zlib PRIVATE
	NO_VIZ
	Z_SOLO
	GZIP_OS_CODE=3
)
target_link_libraries(perl5.18_Compress_Raw_Zlib_Zlib
	z
)

add_bundle(Cwd/Cwd 3.40
	perl/dist/Cwd/Cwd.c
)

add_bundle(Data/Dumper/Dumper 2.145
	perl/dist/Data-Dumper/Dumper.c
)

add_bundle(DB_File/DB_File 1.827
	perl/cpan/DB_File/DB_File.c
	perl/cpan/DB_File/version.c
)
target_compile_definitions(perl5.18_DB_File_DB_File PRIVATE
	_NOT_CORE
	mDB_Prefix_t=size_t
	mDB_Hash_t=u_int32_t
)

add_bundle(Devel/Peek/Peek 1.11
	perl/ext/Devel-Peek/Peek.c
)

add_bundle(Devel/PPPort/PPPort 3.20
	perl/cpan/Devel-PPPort/RealPPPort.c
	perl/cpan/Devel-PPPort/module2.c
	perl/cpan/Devel-PPPort/module3.c
)

add_bundle(Digest/MD5/MD5 2.52
	perl/cpan/Digest-MD5/MD5.c
)
target_compile_definitions(perl5.18_Digest_MD5_MD5 PRIVATE
	U32_ALIGNMENT_REQUIRED
)

add_bundle(Digest/SHA/SHA 5.84_02
	perl/cpan/Digest-SHA/SHA.c
)
target_compile_definitions(perl5.18_Digest_SHA_SHA PRIVATE
	SHA_PerlIO
)
#install(FILES cpan/Digest-SHA/shasum
#	PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#	DESTINATION "libexec/darling/usr/bin"
#)

add_bundle(Encode/Encode 2.49
	perl/cpan/Encode/Encode.c
	perl/cpan/Encode/encengine.c
	perl/cpan/Encode/def_t.c
)

add_bundle(Encode/Byte/Byte 2.04
	perl/cpan/Encode/Byte/Byte.c
	perl/cpan/Encode/Byte/byte_t.c
)

add_bundle(Encode/CN/CN 2.03
	perl/cpan/Encode/CN/CN.c
	perl/cpan/Encode/CN/cp_00_t.c
	perl/cpan/Encode/CN/eu_01_t.c
	perl/cpan/Encode/CN/gb_02_t.c
	perl/cpan/Encode/CN/gb_03_t.c
	perl/cpan/Encode/CN/ir_04_t.c
	perl/cpan/Encode/CN/ma_05_t.c
)

add_bundle(Encode/EBCDIC/EBCDIC 2.02
	perl/cpan/Encode/EBCDIC/EBCDIC.c
	perl/cpan/Encode/EBCDIC/ebcdic_t.c
)

add_bundle(Encode/JP/JP 2.04
	perl/cpan/Encode/JP/cp_00_t.c
	perl/cpan/Encode/JP/eu_01_t.c
	perl/cpan/Encode/JP/ji_02_t.c
	perl/cpan/Encode/JP/ji_03_t.c
	perl/cpan/Encode/JP/ji_04_t.c
	perl/cpan/Encode/JP/ma_05_t.c
	perl/cpan/Encode/JP/sh_06_t.c
)

add_bundle(Encode/KR/KR 2.03
	perl/cpan/Encode/KR/KR.c
	perl/cpan/Encode/KR/cp_00_t.c
	perl/cpan/Encode/KR/eu_01_t.c
	perl/cpan/Encode/KR/jo_02_t.c
	perl/cpan/Encode/KR/ks_03_t.c
	perl/cpan/Encode/KR/ma_04_t.c
)

add_bundle(Encode/Symbol/Symbol 2.02
	perl/cpan/Encode/Symbol/Symbol.c
	perl/cpan/Encode/Symbol/symbol_t.c
)

add_bundle(Encode/TW/TW 2.03
	perl/cpan/Encode/TW/TW.c
	perl/cpan/Encode/TW/bi_00_t.c
	perl/cpan/Encode/TW/bi_01_t.c
	perl/cpan/Encode/TW/cp_02_t.c
	perl/cpan/Encode/TW/ma_03_t.c
)

add_bundle(Encode/Unicode/Unicode 2.07
	perl/cpan/Encode/Unicode/Unicode.c
)

set(ENCODE_MODULES
	Encode/Encode
	Encode/Byte/Byte
	Encode/CN/CN
	Encode/EBCDIC/EBCDIC
	Encode/JP/JP
	Encode/KR/KR
	Encode/Symbol/Symbol
	Encode/TW/TW
	Encode/Unicode/Unicode
)
foreach(MOD IN LISTS ENCODE_MODULES)
	string(REPLACE "/" "_" name "${MOD}")
	set(name "perl5.18_${name}")

	target_include_directories("${name}" PRIVATE
		perl/cpan/Encode/Encode
	)
endforeach()

add_bundle(Fcntl/Fcntl 1.11
	perl/ext/Fcntl/Fcntl.c
)

add_bundle(File/DosGlob/DosGlob 1.10
	perl/ext/File-DosGlob/DosGlob.c
)

add_bundle(File/Glob/Glob 1.20_01
	perl/ext/File-Glob/Glob.c
	perl/ext/File-Glob/bsd_glob.c
)

add_bundle(Filter/Util/Call/Call 1.45
	perl/cpan/Filter-Util-Call/Call.c
)

add_bundle(Hash/Util/Util 0.16
	perl/ext/Hash-Util/Util.c
)
target_compile_definitions(perl5.18_Hash_Util_Util PRIVATE
	PERL_EXT
)

add_bundle(Hash/Util/FieldHash/FieldHash 1.10
	perl/ext/Hash-Util-FieldHash/FieldHash.c
)

add_bundle(I18N/Langinfo/Langinfo 0.10
	perl/ext/I18N-Langinfo/Langinfo.c
)

add_bundle(IO/IO 1.28
	perl/dist/IO/IO.c
	perl/dist/IO/poll.c
)

add_bundle(IPC/SysV/SysV 2.03
	perl/cpan/IPC-SysV/SysV.c
)

add_bundle(List/Util/Util 1.27
	perl/cpan/List-Util/ListUtil.c
)
target_compile_definitions(perl5.18_List_Util_Util PRIVATE
	PERL_EXT
)

add_bundle(Math/BigInt/FastCalc/FastCalc 0.30
	perl/dist/Math-BigInt-FastCalc/FastCalc.c
)

add_bundle(MIME/Base64/Base64 3.13
	perl/cpan/MIME-Base64/Base64.c
)

add_bundle(mro/mro 1.11
	perl/ext/mro/mro.c
)

add_bundle(NDBM_File/NDBM_File 1.12
	perl/ext/NDBM_File/NDBM_File.c
)

add_bundle(Opcode/Opcode 1.25
	perl/ext/Opcode/Opcode.c
)

add_bundle(PerlIO/encoding/encoding 0.16
	perl/ext/PerlIO-encoding/encoding.c
)

add_bundle(PerlIO/mmap/mmap 0.011
	perl/ext/PerlIO-mmap/mmap.c
)

add_bundle(PerlIO/scalar/scalar 0.16
	perl/ext/PerlIO-scalar/scalar.c
)

add_bundle(PerlIO/via/via 0.12
	perl/ext/PerlIO-via/via.c
)

add_bundle(POSIX/POSIX 1.32
	perl/ext/POSIX/POSIX.c
)

add_bundle(re/re 0.23
	perl/ext/re/re.c
	perl/ext/re/re_exec.c
	perl/ext/re/re_comp.c
)
target_compile_definitions(perl5.18_re_re PRIVATE
	PERL_EXT_RE_BUILD
	PERL_EXT_RE_DEBUG
	PERL_EXT
)

add_darling_static_library(perl5.18_libsdbm FAT SOURCES
	perl/ext/SDBM_File/sdbm/hash.c
	perl/ext/SDBM_File/sdbm/pair.c
	perl/ext/SDBM_File/sdbm/sdbm.c
)
target_compile_definitions(perl5.18_libsdbm PRIVATE
	SDBM
	DUFF

	# fairly certain these aren't necessary, but the Makefile defines them, so whatever
	VERSION=""
	XS_VERSION=""
)

add_bundle(SDBM_File/SDBM_File 1.09
	perl/ext/SDBM_File/SDBM_File.c
)
target_link_libraries(perl5.18_SDBM_File_SDBM_File
	perl5.18_libsdbm
)

add_bundle(Socket/Socket 2.009
	perl/cpan/Socket/Socket.c
)

add_bundle(Storable/Storable 2.4
	perl/dist/Storable/Storable.c
)

add_bundle(Sys/Hostname/Hostname 1.17
	perl/ext/Sys-Hostname/Hostname.c
)

add_bundle(Sys/Syslog/Syslog 0.32
	perl/cpan/Sys-Syslog/Syslog.c
)

add_bundle(Text/Soundex/Soundex 3.04
	perl/cpan/Text-Soundex/Soundex.c
)

add_bundle(threads/threads 1.86
	perl/dist/threads/threads.c
)

add_bundle(threads/shared/shared 1.43
	perl/dist/threads-shared/shared.c
)

add_bundle(Tie/Hash/NamedCapture/NamedCapture 0.09
	perl/ext/Tie-Hash-NamedCapture/NamedCapture.c
)

add_bundle(Time/HiRes/HiRes 1.9725
	perl/cpan/Time-HiRes/HiRes.c
)
target_compile_definitions(perl5.18_Time_HiRes_HiRes PRIVATE
	TIME_HIRES_NANOSLEEP
	TIME_HIRES_CLOCK_GETTIME
	TIME_HIRES_CLOCK_GETRES
	TIME_HIRES_CLOCK
	TIME_HIRES_STAT=1
	ATLEASTFIVEOHOHFIVE
)

add_bundle(Time/Piece/Piece 1.20_01
	perl/cpan/Time-Piece/Piece.c
)

add_bundle(Unicode/Collate/Collate 0.97
	perl/cpan/Unicode-Collate/Collate.c
)

add_bundle(Unicode/Normalize/Normalize 1.16
	perl/cpan/Unicode-Normalize/Normalize.c
)
