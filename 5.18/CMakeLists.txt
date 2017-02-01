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

add_bundle(B gen/ext/B/B.c)
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
