# 
# /*
#  * *********** WARNING **************
#  * This file generated by Apache2::Build/0.01
#  * Any changes made here will be lost
#  * ***********************************
#  * 01: lib/ModPerl/Code.pm:716
#  * 02: lib/Apache2/Build.pm:988
#  * 03: lib/Apache2/Build.pm:1008
#  * 04: Makefile.PL:413
#  * 05: Makefile.PL:102
#  */
# 
package Apache2::BuildConfig;

use Apache2::Build ();

sub new {
    bless( {
'API_VERSION' => 2,
'APXS_APR_BINDIR' => '/Applications/Xcode.app/Contents/Developer/Toolchains/OSX10.12.xctoolchain/usr/local/bin',
'APXS_APU_BINDIR' => '/Applications/Xcode.app/Contents/Developer/Toolchains/OSX10.12.xctoolchain/usr/local/bin',
'APXS_BINDIR' => '/usr/bin',
'APXS_EXTRA_CFLAGS' => '',
'APXS_EXTRA_CPPFLAGS' => '-DDARWIN -DSIGPROCMASK_SETS_THREAD_MASK -DDARWIN_10 -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.Internal.sdk/usr/include/apr-1',
'APXS_INCLUDEDIR' => '/usr/include/apache2',
'APXS_LIBEXECDIR' => '/usr/libexec/apache2',
'APXS_NOTEST_CPPFLAGS' => '',
'MODPERL_AP_INCLUDEDIR' => '/usr/include/apache2',
'MODPERL_AP_LIBEXECDIR' => '/usr/libexec/apache2',
'MODPERL_AP_LIBS' => '',
'MODPERL_AR' => 'ar',
'MODPERL_ARCHLIBEXP' => '/System/Library/Perl/5.18/darwin-thread-multi-2level',
'MODPERL_CC' => 'cc',
'MODPERL_CCCDLFLAGS' => ' ',
'MODPERL_CCOPTS' => ' -arch x86_64 -pipe -g -pipe -fno-common -DPERL_DARWIN -fno-strict-aliasing -fstack-protector -I/System/Library/Perl/5.18/darwin-thread-multi-2level/CORE -DMOD_PERL -DMP_COMPAT_1X -arch x86_64 -g -Os -pipe -std=c89 -DDARWIN -DSIGPROCMASK_SETS_THREAD_MASK -DDARWIN_10 -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.Internal.sdk/usr/include/apr-1',
'MODPERL_CP' => 'cp',
'MODPERL_CPPRUN' => 'cc -E',
'MODPERL_C_FILES' => 'mod_perl.c modperl_interp.c modperl_tipool.c modperl_log.c modperl_config.c modperl_cmd.c modperl_options.c modperl_callback.c modperl_handler.c modperl_gtop.c modperl_util.c modperl_io.c modperl_io_apache.c modperl_filter.c modperl_bucket.c modperl_mgv.c modperl_pcw.c modperl_global.c modperl_env.c modperl_cgi.c modperl_perl.c modperl_perl_global.c modperl_perl_pp.c modperl_sys.c modperl_module.c modperl_svptr_table.c modperl_const.c modperl_constants.c modperl_apache_compat.c modperl_error.c modperl_debug.c modperl_common_util.c modperl_common_log.c modperl_hooks.c modperl_directives.c modperl_flags.c modperl_xsinit.c modperl_exports.c',
'MODPERL_DLEXT' => 'so',
'MODPERL_H_FILES' => 'mod_perl.h modperl_interp.h modperl_tipool.h modperl_log.h modperl_config.h modperl_cmd.h modperl_options.h modperl_callback.h modperl_handler.h modperl_gtop.h modperl_util.h modperl_io.h modperl_io_apache.h modperl_filter.h modperl_bucket.h modperl_mgv.h modperl_pcw.h modperl_global.h modperl_env.h modperl_cgi.h modperl_perl.h modperl_perl_global.h modperl_perl_pp.h modperl_sys.h modperl_module.h modperl_svptr_table.h modperl_const.h modperl_constants.h modperl_apache_compat.h modperl_error.h modperl_debug.h modperl_common_util.h modperl_common_log.h modperl_perl_unembed.h modperl_types.h modperl_time.h modperl_apache_includes.h modperl_perl_includes.h modperl_apr_includes.h modperl_apr_compat.h modperl_common_includes.h modperl_common_types.h modperl_hooks.h modperl_directives.h modperl_flags.h modperl_trace.h modperl_largefiles.h',
'MODPERL_INC' => '-I/Library/Caches/com.apple.xbs/Binaries/apache_mod_perl/apache_mod_perl-109~228/TempContent/Objects/mod_perl-2.0.9/src/modules/perl -I/Library/Caches/com.apple.xbs/Binaries/apache_mod_perl/apache_mod_perl-109~228/TempContent/Objects/mod_perl-2.0.9/xs -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.Internal.sdk/usr/include/apr-1 -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.Internal.sdk/usr/include/apr-1  -I/usr/include/apache2',
'MODPERL_LD' => 'cc -mmacosx-version-min=10.12.2',
'MODPERL_LDDLFLAGS' => '-arch x86_64 -pipe -bundle -undefined dynamic_lookup -fstack-protector',
'MODPERL_LDOPTS' => '  -arch x86_64 -pipe -fstack-protector  -L/System/Library/Perl/5.18/darwin-thread-multi-2level/CORE -lperl',
'MODPERL_LIB' => 'mod_perl.so',
'MODPERL_LIBNAME' => 'mod_perl',
'MODPERL_LIBPERL' => '/System/Library/Perl/5.18/darwin-thread-multi-2level/CORE/libperl.dylib',
'MODPERL_LIB_DSO' => 'mod_perl.so',
'MODPERL_LIB_EXT' => '.a',
'MODPERL_LIB_SHARED' => 'mod_perl.so',
'MODPERL_LIB_STATIC' => 'mod_perl.a',
'MODPERL_MAKEFILE' => 'Makefile',
'MODPERL_MV' => 'mv',
'MODPERL_OBJ_EXT' => '.o',
'MODPERL_OPTIMIZE' => '-Os',
'MODPERL_O_FILES' => 'mod_perl.o modperl_interp.o modperl_tipool.o modperl_log.o modperl_config.o modperl_cmd.o modperl_options.o modperl_callback.o modperl_handler.o modperl_gtop.o modperl_util.o modperl_io.o modperl_io_apache.o modperl_filter.o modperl_bucket.o modperl_mgv.o modperl_pcw.o modperl_global.o modperl_env.o modperl_cgi.o modperl_perl.o modperl_perl_global.o modperl_perl_pp.o modperl_sys.o modperl_module.o modperl_svptr_table.o modperl_const.o modperl_constants.o modperl_apache_compat.o modperl_error.o modperl_debug.o modperl_common_util.o modperl_common_log.o modperl_hooks.o modperl_directives.o modperl_flags.o modperl_xsinit.o modperl_exports.o',
'MODPERL_O_PIC_FILES' => 'mod_perl.lo modperl_interp.lo modperl_tipool.lo modperl_log.lo modperl_config.lo modperl_cmd.lo modperl_options.lo modperl_callback.lo modperl_handler.lo modperl_gtop.lo modperl_util.lo modperl_io.lo modperl_io_apache.lo modperl_filter.lo modperl_bucket.lo modperl_mgv.lo modperl_pcw.lo modperl_global.lo modperl_env.lo modperl_cgi.lo modperl_perl.lo modperl_perl_global.lo modperl_perl_pp.lo modperl_sys.lo modperl_module.lo modperl_svptr_table.lo modperl_const.lo modperl_constants.lo modperl_apache_compat.lo modperl_error.lo modperl_debug.lo modperl_common_util.lo modperl_common_log.lo modperl_hooks.lo modperl_directives.lo modperl_flags.lo modperl_xsinit.lo modperl_exports.lo',
'MODPERL_PERLPATH' => '/usr/bin/perl',
'MODPERL_PRIVLIBEXP' => '/System/Library/Perl/5.18',
'MODPERL_RANLIB' => '/usr/bin/ar s',
'MODPERL_RM' => 'rm',
'MODPERL_RM_F' => 'rm -f',
'MODPERL_TEST_F' => 'test -f',
'MODPERL_XSUBPP' => '$(MODPERL_PERLPATH) $(MODPERL_PRIVLIBEXP)/ExtUtils/xsubpp -typemap $(MODPERL_PRIVLIBEXP)/ExtUtils/typemap -typemap /Library/Caches/com.apple.xbs/Binaries/apache_mod_perl/apache_mod_perl-109~228/TempContent/Objects/mod_perl-2.0.9/lib/typemap',
'MP_APR_LIB' => 'aprext',
'MP_APXS' => '/usr/sbin/apxs',
'MP_CCOPTS' => '-arch x86_64 -g -Os -pipe  -std=c89',
'MP_COMPAT_1X' => 1,
'MP_GENERATE_XS' => 1,
'MP_LIBNAME' => 'mod_perl',
'MP_USE_DSO' => 1,
'VERSION' => '2.0.9',
'XS' => {},
'ap_includedir' => '/usr/include/apache2',
'apr_bindir' => '/Applications/Xcode.app/Contents/Developer/Toolchains/OSX10.12.xctoolchain/usr/local/bin',
'apr_config' => {
                  'HAS_DSO' => '1',
                  'HAS_FORK' => '1',
                  'HAS_INLINE' => '1',
                  'HAS_LARGE_FILES' => '1',
                  'HAS_MMAP' => '1',
                  'HAS_RANDOM' => '1',
                  'HAS_SENDFILE' => '1',
                  'HAS_THREADS' => '1'
                },
'apr_config_path' => '/Applications/Xcode.app/Contents/Developer/Toolchains/OSX10.12.xctoolchain/usr/local/bin/apr-1-config',
'apr_includedir' => '/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.Internal.sdk/usr/include/apr-1',
'apu_config_path' => '/Applications/Xcode.app/Contents/Developer/Toolchains/OSX10.12.xctoolchain/usr/local/bin/apu-1-config',
'cwd' => '/Library/Caches/com.apple.xbs/Binaries/apache_mod_perl/apache_mod_perl-109~228/TempContent/Objects/mod_perl-2.0.9',
'dir' => undef,
'file_build_config' => 'lib/Apache2/BuildConfig.pm',
'file_ldopts' => 'src/modules/perl/ldopts',
'file_makefile' => 'src/modules/perl/Makefile',
'httpd_is_source_tree' => '',
'httpd_version' => {
                     '/usr/include/apache2' => '2.4.23'
                   }
       }, 'Apache2::Build' );
}

1;
