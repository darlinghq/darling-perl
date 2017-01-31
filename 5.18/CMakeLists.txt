project(perl-5.18)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/gen
)

add_library(perllib5.18 OBJECT
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
add_darling_executable(perl5.18 gen/perlmain.c $<TARGET_OBJECTS:perllib5.18>)

install(TARGETS perl5.18 DESTINATION libexec/darling/usr/bin)
