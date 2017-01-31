# 
# /*
#  * *********** WARNING **************
#  * This file generated by ModPerl::WrapXS/0.01
#  * Any changes made here will be lost
#  * ***********************************
#  * 01: lib/ModPerl/Code.pm:716
#  * 02: /Library/Caches/com.apple.xbs/Binaries/apache_mod_perl/apache_mod_perl-109~228/TempContent/Objects/mod_perl-2.0.9/blib/lib/ModPerl/WrapXS.pm:635
#  * 03: /Library/Caches/com.apple.xbs/Binaries/apache_mod_perl/apache_mod_perl-109~228/TempContent/Objects/mod_perl-2.0.9/blib/lib/ModPerl/WrapXS.pm:1186
#  * 04: Makefile.PL:435
#  * 05: Makefile.PL:333
#  * 06: Makefile.PL:59
#  */
# 


package Apache2::URI;

use strict;
use warnings FATAL => 'all';



use Apache2::XSLoader ();
our $VERSION = '2.000009';
Apache2::XSLoader::load __PACKAGE__;



1;
__END__

=head1 NAME

Apache2::URI - Perl API for manipulating URIs




=head1 Synopsis

  use Apache2::URI ();
  
  $hostport = $r->construct_server();
  $hostport = $r->construct_server($hostname);
  $hostport = $r->construct_server($hostname, $port);
  $hostport = $r->construct_server($hostname, $port, $pool);
  
  $url = $r->construct_url();
  $url = $r->construct_url($rel_uri);
  $url = $r->construct_url($rel_uri, $pool);
  
  $parsed_uri = $r->parse_uri($uri);
  
  $parsed_uri = $r->parsed_uri();
  
  $url = join '%20', qw(one two three);
  Apache2::URI::unescape_url($url);









=head1 Description

While C<APR::URI> provides a generic API to dissect, adjust and put
together any given URI string, C<Apache2::URI> provides an API specific
to Apache, by taking the information directly from the C<$r>
object. Therefore when manipulating the URI of the current HTTP
request usually methods from both classes are used.






=head1 API

C<Apache2::URI> provides the following functions and methods:






=head2 C<construct_server>

Construct a string made of hostname and port

  $hostport = $r->construct_server();
  $hostport = $r->construct_server($hostname);
  $hostport = $r->construct_server($hostname, $port);
  $hostport = $r->construct_server($hostname, $port, $pool);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request object

=item opt arg1: C<$hostname> ( string )

The hostname of the server.

If that argument is not passed,
C<L<$r-E<gt>get_server_name|docs::2.0::api::Apache2::RequestUtil/C_get_server_name_>>
is used.

=item opt arg2: C<$port> ( string )

The port the server is running on.

If that argument is not passed,
C<L<$r-E<gt>get_server_port|docs::2.0::api::Apache2::RequestUtil/C_get_server_port_>>
is used.

=item opt arg3: C<$pool>
( C<L<APR::Pool object|docs::2.0::api::APR::Pool>> )

The pool to allocate the string from.

If that argument is not passed,
C<L<$r-E<gt>pool|docs::2.0::api::Apache2::RequestRec/C_pool_>> is used.

=item ret: C<$hostport> ( string )

The server's hostport string

=item since: 2.0.00

=back

Examples:

=over

=item *

Assuming that:

  $r->get_server_name == "localhost";
  $r->get_server_port == 8001;

The code:

  $hostport = $r->construct_server();

returns a string:

  localhost:8001

=item *

The following code sets the values explicitly:

  $hostport = $r->construct_server("my.example.com", 8888);

and it returns a string:

  my.example.com:8888

=back






=head2 C<construct_url>

Build a fully qualified URL from the uri and information in the
request rec:

  $url = $r->construct_url();
  $url = $r->construct_url($rel_uri);
  $url = $r->construct_url($rel_uri, $pool);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request object

=item opt arg1: C<$rel_uri> ( string )

The path to the requested file (it may include a concatenation of
I<path>, I<query> and I<fragment> components).

If that argument is not passed,
C<L<$r-E<gt>uri|docs::2.0::api::Apache2::RequestRec/C_uri_>> is used.

=item opt arg2: C<$pool>
( C<L<APR::Pool object|docs::2.0::api::APR::Pool>> )

The pool to allocate the URL from

If that argument is not passed,
C<L<$r-E<gt>pool|docs::2.0::api::Apache2::RequestRec/C_pool_>> is used.

=item ret: C<$url> ( string )

A fully qualified URL

=item since: 2.0.00

=back

Examples:

=over

=item *

Assuming that the request was

  http://localhost.localdomain:8529/test?args

The code:

  my $url = $r->construct_url;

returns the string:

  http://localhost.localdomain:8529/test

notice that the query (args) component is not in the string. You need
to append it manually if it's needed.


=item *

Assuming that the request was

  http://localhost.localdomain:8529/test?args

The code:

  my $rel_uri = "/foo/bar?tar";
  my $url = $r->construct_url($rel_uri);

returns the string:

  http://localhost.localdomain:8529/foo/bar?tar

=back








=head2 C<parse_uri>

Break apart URI (affecting the current request's uri components)

  $r->parse_uri($uri);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request object

=item arg1: C<$uri> ( string )

The uri to break apart

=item ret: no return value

=item warning:

This method has several side-effects explained below

=item since: 2.0.00

=back

This method call has the following side-effects:

=over

=item 1

sets C<L<$r-E<gt>args|docs::2.0::api::Apache2::RequestRec/C_args_>> to
the rest after C<'?'> if such exists in the passed C<$uri>, otherwise
sets it to C<undef>.

=item 2

sets C<L<$r-E<gt>uri|docs::2.0::api::Apache2::RequestRec/C_uri_>> to
the passed C<$uri> without the
C<L<$r-E<gt>args|docs::2.0::api::Apache2::RequestRec/C_args_>> part.

=item 3

sets
C<L<$r-E<gt>hostname|docs::2.0::api::Apache2::RequestRec/C_hostname_>>
(if not set already) using the (C<scheme://host:port>) parts of the
passed C<$uri>.

=back






=head2 C<parsed_uri>

Get the current request's parsed uri object

  my $uri = $r->parsed_uri();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request object

=item ret: C<$uri>
( C<L<APR::URI object|docs::2.0::api::APR::URI>> )

The parsed uri

=item since: 2.0.00

This object is suitable for using with C<L<APR::URI::rpath|docs::2.0::api::APR::URI/C_rpath_>>

=back








=head2 C<unescape_url>

Unescape URLs

  Apache2::URI::unescape_url($url);

=over 4

=item obj: C<$url> ( string )

The URL to unescape

=item ret: no return value

The argument C<$url> is now unescaped

=item since: 2.0.00

=back

Example:

  my $url = join '%20', qw(one two three);
  Apache2::URI::unescape_url($url);

C<$url> now contains the string:

  "one two three";







=head1 See Also

C<L<APR::URI|docs::2.0::api::APR::URI>>, L<mod_perl 2.0
documentation|docs::2.0::index>.




=head1 Copyright

mod_perl 2.0 and its core modules are copyrighted under
The Apache Software License, Version 2.0.




=head1 Authors

L<The mod_perl development team and numerous
contributors|about::contributors::people>.

=cut

