project(perl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -nostdinc -fwrapv -fPIC -std=c89 -ansi -fno-common -fno-strict-aliasing -pipe -fstack-protector")

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
	${CMAKE_SOURCE_DIR}/src/libmalloc/include
)

include(darling_bundle)

add_subdirectory(5.16)
add_subdirectory(5.18)

install(DIRECTORY man DESTINATION libexec/darling/usr/share)

install(DIRECTORY symlinks/bin DESTINATION libexec/darling/usr)

install(DIRECTORY Perl DESTINATION libexec/darling/System/Library)
