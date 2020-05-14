project(perl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -fwrapv -fPIC -fno-common -fno-strict-aliasing -pipe -fstack-protector")

add_compile_options(
	-w
)

add_definitions(
	-ansi
	-nostdinc
)

add_definitions(
	-DPERL_DARWIN
)

include(darling_bundle)
include(versioner)

versioner(perl "5.16;5.18" "5.18")

add_subdirectory(5.16)
add_subdirectory(5.18)

install(DIRECTORY man DESTINATION libexec/darling/usr/share)

install(DIRECTORY Perl DESTINATION libexec/darling/System/Library)
