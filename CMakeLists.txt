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
	-Wno-macro-redefined
)
	
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/platform-include
)

add_subdirectory(5.16)
add_subdirectory(5.18)

install(DIRECTORY man DESTINATION libexec/darling/usr/share)

install(DIRECTORY symlinks/bin DESTINATION libexec/darling/usr)
