#!/bin/sh

export SRCROOT="$(pwd)"
export OBJROOT="$(pwd)/OBJROOT"
export TARARGS="xozf"
export PROJECT="perl"
export VERSION="5.28.2"
export PROJVERS="${PROJECT}-${VERSION}"
export MODSUFFIX="-mod"
export TARBALLPATTERN="${PROJVERS}${MODSUFFIX}.tar."
export TARBALL="$(ls "${SRCROOT}/${TARBALLPATTERN}"*)"
export ENV_PERL_BASE_VERSION="$(basename ${VERSION})"
export ENV_VERSION_ALT=""

set -x && \
: The addition of the colon before \`cd\` is a Darling addition && \
: Apple\'s code is weird an inconsistent and \*says\* it needs to be in OBJROOT, but it really doesn\'t && \
: cd "${OBJROOT}" && \
tar -${TARARGS} "${TARBALL}" && \
rm -rf ${PROJECT} && \
mv ${PROJVERS} ${PROJECT} && \
: && \
: Darling addition && \
find "${PROJECT}" -type f -perm 0444 -exec chmod 0644 {} \; && \
find "${PROJECT}" -type f -perm 0555 -exec chmod 0755 {} \; && \
: && \
cat hints.append >> ${PROJECT}/hints/darwin.sh && \
ed - ${PROJECT}/Configure < fix/Configure.ed && \
ed - ${PROJECT}/cpan/Compress-Raw-Bzip2/Makefile.PL < fix/cpan_Compress-Raw-Bzip2_Makefile.PL.ed && \
ed - ${PROJECT}/cpan/Compress-Raw-Zlib/Makefile.PL < fix/cpan_Compress-Raw-Zlib_Makefile.PL.ed && \
ed - ${PROJECT}/cpan/DB_File/config.in < fix/cpan_DB_File_config.in.ed && \
ed - ${PROJECT}/cpan/DB_File/Makefile.PL < fix/cpan_DB_File_Makefile.PL.ed && \
ed - ${PROJECT}/cpan/Pod-Perldoc/lib/Pod/Perldoc.pm < fix/lib_Pod_Perldoc.pm.ed && \
ed - ${PROJECT}/cpan/Pod-Perldoc/lib/Pod/Perldoc/ToMan.pm < fix/lib_Pod_Perldoc_ToMan.pm.ed && \
ed - ${PROJECT}/doio.c < fix/doio.c.ed && \
ed - ${PROJECT}/ext/DynaLoader/dl_dlopen.xs < fix/dl_dlopen.xs.ed && \
ed - ${PROJECT}/handy.h < fix/handy.h.ed && \
ed - ${PROJECT}/hints/darwin.sh < fix/darwin.sh.ed && \
ed - ${PROJECT}/patchlevel.h < fix/patchlevel.h.ed && \
patch -p0 ${PROJECT}/perl.c fix/perl.c.patch && \
patch -p0 ${PROJECT}/perl.c fix/deprecate.diff && \
patch -p0 ${PROJECT}/perlio.c fix/perlio.c.patch && \
ed - ${PROJECT}/pp_sys.c < fix/pp_sys.c.ed && \
patch -p0 -F0 ${PROJECT}/config_h.SH fix/CORE-config.h.diff && \
(cd ${PROJECT} ; patch -p1 -F0 < ${SRCROOT}/fix/perl_inc.diff) && \
sed -e 's/@VERSION@/'"${VERSION}"'/g' \
	-e 's/@VERSION_DEFAULT@/'"${ENV_PERL_BASE_VERSION}"'/g' \
	-e 's/@VERSION_ALT@/'"${ENV_VERSION_ALT}"'/g' \
	fix/README.macosx.ed | ed - ${PROJECT}/README.macosx && \
ed - ${PROJECT}/cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM_Unix.pm < fix/ExtUtils_MM_Unix.pm.ed
