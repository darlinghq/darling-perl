project(perl)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89 -fwrapv -fPIC -fno-common -fno-strict-aliasing -pipe -fstack-protector")

add_compile_options(
	-w
)

add_definitions(
	-ansi
	-nostdinc
)

add_compile_definitions(
	PERL_DARWIN
	DTRACE_PROBES_DISABLED # Darling doesn't do DTrace (yet?)
)

include(darling_bundle)
include(versioner)

versioner(perl "5.18;5.28" "5.18")
# we need to install a copy of `perl` for `a2p` (that's what Apple's Makefile does),
# but i'm not sure how at the moment
#
# ¯\_(ツ)_/¯ we weren't doing up 'til now, so it can stay that way for a bit longer

add_subdirectory(5.18)
add_subdirectory(5.28)

install(DIRECTORY "DSTROOT/" DESTINATION libexec/darling)

set(DUMMIES
	c2ph
	config_data
	corelist
	cpan
	cpan2dist
	cpanp
	cpanp-run-perl
	enc2xs
	encguess
	find2perl
	h2ph
	h2xs
	instmodsh
	json_pp
	libnetcfg
	perlbug
	perldoc
	perlivp
	perlthanks
	piconv
	pl2pm
	pod2html
	pod2latex
	pod2man
	pod2text
	pod2usage
	podchecker
	podselect
	prove
	psed
	pstruct
	ptar
	ptardiff
	ptargrep
	s2p
	shasum
	splain
	xsubpp
	zipdetails
)

foreach(DUMMY IN LISTS DUMMIES)
	install(PROGRAMS fix/dummy.pl DESTINATION libexec/darling/usr/bin RENAME "${DUMMY}")
endforeach()
