project(perl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdinc -fwrapv -fPIC -std=c89 -ansi -fno-common -fno-strict-aliasing -pipe -fstack-protector")

set(CMAKE_SHARED_LINKER_FLAGS "-nodefaultlibs -nostdlib -fPIC -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")

set(CMAKE_EXE_LINKER_FLAGS "-nodefaultlibs -nostdlib -fPIC -Wl,--version-script=${DARLING_TOP_DIRECTORY}/darwin.map")

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/darling")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_compile_options(
	-Wno-pointer-bool-conversion
	-Wno-typedef-redefinition
	-Wno-logical-not-parentheses
	-Wno-tautological-constant-out-of-range-compare
	-Wno-format
	-Wno-pointer-sign
	-Wno-macro-redefined
	-Wno-int-conversion
	-Wno-incompatible-pointer-types
	-Wno-shift-negative-value
	-Wno-unused-value
)

add_definitions(
	-DPERL_DARWIN
)

include_directories(
	${CMAKE_SOURCE_DIR}/platform-include
)

function(add_bundle name)
	foreach(f IN LISTS ARGN)
		set(sources ${sources} ${f})
	endforeach(f)
	add_library(${name} SHARED ${sources})
	set_target_properties(${name} PROPERTIES COMPILE_FLAGS "-bundle" PREFIX "" SUFFIX ".bundle")
endfunction(add_bundle)

add_subdirectory(5.16)
add_subdirectory(5.18)

install(DIRECTORY man DESTINATION libexec/darling/usr/share)

install(DIRECTORY symlinks/bin DESTINATION libexec/darling/usr)

install(DIRECTORY Perl DESTINATION libexec/darling/System/Library)
