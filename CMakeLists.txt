project(perl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdinc -fwrapv -fPIC -std=c89 -ansi -fno-common -fno-strict-aliasing -pipe -fstack-protector")

set(CMAKE_SHARED_LINKER_FLAGS "-nodefaultlibs -nostdlib -fPIC -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")

set(CMAKE_EXE_LINKER_FLAGS "-nodefaultlibs -nostdlib -fPIC -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/darling")
SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_definitions(
	-DPERL_CORE
	-DPERL_DARWIN

	-Wno-pointer-bool-conversion
	-Wno-typedef-redefinition
	-Wno-logical-not-parentheses
	-Wno-tautological-constant-out-of-range-compare
	-Wno-format
	-Wno-pointer-sign
)

set(perl_5.16_inc
	${CMAKE_CURRENT_SOURCE_DIR}/perl-5.16.3
	${CMAKE_CURRENT_SOURCE_DIR}/include/5.16
)

set(perl_5.18_inc
	${CMAKE_CURRENT_SOURCE_DIR}/perl-5.18.2
	${CMAKE_CURRENT_SOURCE_DIR}/include/5.18
)
	
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/platform-include
)

add_library(perl-5.16-static STATIC
	perl-5.16.3/op.c
	perl-5.16.3/perl.c
	perl-5.16.3/gv.c
	perl-5.16.3/toke.c
	perl-5.16.3/perly.c
	perl-5.16.3/pad.c
	perl-5.16.3/regcomp.c
	perl-5.16.3/dump.c
	perl-5.16.3/util.c
	perl-5.16.3/mg.c
	perl-5.16.3/reentr.c
	perl-5.16.3/mro.c
	perl-5.16.3/keywords.c
	perl-5.16.3/hv.c
	perl-5.16.3/av.c
	perl-5.16.3/run.c
	perl-5.16.3/pp_hot.c
	perl-5.16.3/sv.c
	perl-5.16.3/pp.c
	perl-5.16.3/scope.c
	perl-5.16.3/pp_ctl.c
	perl-5.16.3/pp_sys.c
	perl-5.16.3/doop.c
	perl-5.16.3/doio.c
	perl-5.16.3/regexec.c
	perl-5.16.3/utf8.c
	perl-5.16.3/taint.c
	perl-5.16.3/deb.c
	perl-5.16.3/universal.c
	perl-5.16.3/globals.c
	perl-5.16.3/perlio.c
	perl-5.16.3/perlapi.c
	perl-5.16.3/numeric.c
	perl-5.16.3/mathoms.c
	perl-5.16.3/locale.c
	perl-5.16.3/pp_pack.c
	perl-5.16.3/pp_sort.c
	gen/DynaLoader.c
)
target_include_directories(perl-5.16-static PRIVATE ${perl_5.16_inc})

add_library(perl-5.18-static STATIC
	perl-5.18.2/op.c
	perl-5.18.2/perl.c
	perl-5.18.2/gv.c
	perl-5.18.2/toke.c
	perl-5.18.2/perly.c
	perl-5.18.2/pad.c
	perl-5.18.2/regcomp.c
	perl-5.18.2/dump.c
	perl-5.18.2/util.c
	perl-5.18.2/mg.c
	perl-5.18.2/reentr.c
	perl-5.18.2/mro.c
	perl-5.18.2/keywords.c
	perl-5.18.2/hv.c
	perl-5.18.2/av.c
	perl-5.18.2/run.c
	perl-5.18.2/pp_hot.c
	perl-5.18.2/sv.c
	perl-5.18.2/pp.c
	perl-5.18.2/scope.c
	perl-5.18.2/pp_ctl.c
	perl-5.18.2/pp_sys.c
	perl-5.18.2/doop.c
	perl-5.18.2/doio.c
	perl-5.18.2/regexec.c
	perl-5.18.2/utf8.c
	perl-5.18.2/taint.c
	perl-5.18.2/deb.c
	perl-5.18.2/universal.c
	#perl-5.18.2/globals.c		FIXME: Not working
	perl-5.18.2/perlio.c
	perl-5.18.2/perlapi.c
	perl-5.18.2/numeric.c
	perl-5.18.2/mathoms.c
	perl-5.18.2/locale.c
	perl-5.18.2/pp_pack.c
	perl-5.18.2/pp_sort.c
	gen/DynaLoader.c
)
target_include_directories(perl-5.18-static PRIVATE ${perl_5.18_inc})

install(DIRECTORY man DESTINATION libexec/darling/usr/share)
