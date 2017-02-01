project(perl-5.18)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/gen
)

add_library(perlcore OBJECT
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
set_target_properties(perl5.18 perlcore PROPERTIES COMPILE_FLAGS "-DPERL_CORE")

install(TARGETS perl5.18 DESTINATION libexec/darling/usr/bin)

# Bundles
set(bundir "libexec/darling/System/Library/Perl/5.18/darwin-thread-multi-2level/auto")
set(bunexdir "libexec/darling/System/Library/Perl/Extras/5.18/darwin-thread-multi-2level/auto")

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
install(TARGETS Dumper DESTINATION ${bundir}/Data/Dumper)
