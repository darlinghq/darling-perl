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


package Apache2::RequestUtil;

use strict;
use warnings FATAL => 'all';



use Apache2::XSLoader ();
our $VERSION = '2.000009';
Apache2::XSLoader::load __PACKAGE__;



1;
__END__

=head1 NAME

Apache2::RequestUtil - Perl API for Apache request record utils




=head1 Synopsis

  use Apache2::RequestUtil ();
  
  # add httpd config dynamically
  $r->add_config(['require valid-user']);
  
  # dump the request object as a string
  print $r->as_string();
  
  # default content_type
  $content_type = $r->default_type();
  
  # get PerlSetVar/PerlAddVar values
  @values = $r->dir_config->get($key);
  
  # get server docroot
  $docroot = $r->document_root();
  
  # set server docroot
  $r->document_root($new_root);
  
  # what are the registered perl handlers for a given phase
  my @handlers = @{ $r->get_handlers('PerlResponseHandler') || [] };
  
  # push a new handler for a given phase
  $r->push_handlers(PerlCleanupHandler => \&handler);
  
  # set handlers for a given phase (resetting previous values)
  $r->set_handlers(PerlCleanupHandler => []);
  
  # what's the request body limit
  $limit = $r->get_limit_req_body();
  
  # server and port names
  $server = $r->get_server_name();
  $port   = $r->get_server_port();
  
  # what string Apache is going to send for a given status code
  $status_line = Apache2::RequestUtil::get_status_line(404);
  
  # are we in the main request?
  $is_initial = $r->is_initial_req();
  
  # directory level PerlOptions flags lookup
  $r->subprocess_env unless $r->is_perl_option_enabled('SetupEnv');
  
  # current <Location> value
  $location = $r->location();
  
  # merge a <Location> container in a request object
  $r->location_merge($location);
  
  # create a new Apache2::RequestRec object
  $r = Apache2::RequestRec->new($c);
  
  # tell the client not to cache the response
  $r->no_cache($boolean);
  
  # share perl objects by reference like $r->notes
  $r->pnotes($key => [$obj1, $obj2]);
  
  # get HTML signature
  $sig = $r->psignature($prefix);
  
  # get the global request object (requires PerlOptions +GlobalRequest)
  $r = Apache2::RequestUtil->request;
  
  # insert auth credentials into the request as if the client did that
  $r->set_basic_credentials($username, $password);
  
  # slurp the contents of $r->filename
  my $content = ${ $r->slurp_filename() };
  
  # terminate the current child after this request
  $r->child_terminate();







=head1 Description

C<Apache2::RequestUtil> provides the L<Apache request
object|docs::2.0::api::Apache2::RequestRec> utilities API.





=head1 API




=head2 C<add_config>

Dynamically add Apache configuration at request processing runtime:

  $r->add_config($lines);
  $r->add_config($lines, $override);
  $r->add_config($lines, $override, $path);
  $r->add_config($lines, $override, $path, $override_opts);

Configuration directives are processed as if given in a C<E<lt>LocationE<gt>>
block.

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$lines> (ARRAY ref)

An ARRAY reference containing configuration lines per element, without
the new line terminators.

=item opt arg2: C<$override> ( C<L<Apache2::Const override
constant|docs::2.0::api::Apache2::Const>> )

Which allow-override bits are set

Default value is:
C<L<Apache2::Const::OR_AUTHCFG|docs::2.0::api::Apache2::Const/C_Apache2__Const__OR_AUTHCFG_>>

=item opt arg3: C<$path> ( string )

Set the C<L<Apache2::CmdParms object|docs::2.0::api::Apache2::CmdParms>> C<path> component.
This is the path of the C<E<lt>LocationE<gt>> block. Some directives need this,
for example C<ProxyPassReverse>.

If an empty string is passed a C<NULL> pointer is passed further at C-level.
This is necessary to make something like this work:

  $r->add_config( [
	 	   '<Directory />',
		   'AllowOverride Options AuthConfig',
		   '</Directory>',
                  ], ~0, '' );

Note: C<AllowOverride> is valid only in directory context.

B<Caution:> Some directives need a non-empty path otherwise they cause
segfaults. Thus, use the empty path with caution.

Default value is: C</>

=item opt arg4: C<$override_opts> ( C<L<Apache2::Const options
constant|docs::2.0::api::Apache2::Const>> )

Apache limits the applicable directives in certain situations with
C<AllowOverride>. With Apache 2.2 comes the possibility to enable or
disable single options, for example

  AllowOverride AuthConfig Options=ExecCGI,Indexes

Internally, this directive is parsed into 2 bit fields that are represented
by the C<$override> and C<$override_opts> parameters to C<add_config>.
The above example is parsed into an C<$override> with 2 bits set, one for
C<AuthConfig> the other for C<Options> and an C<$override_opts> with
2 bits set for ExecCGI and Indexes.

When applying other directives, for example C<AuthType> or C<Options> the
appropriate bits in C<$override> must be set. For the C<Options> directive
additionally C<$override_opts> bits must be set.

The C<$override> and C<$override_opts> parameters to C<add_config> are
valid while applying C<$lines>.

C<$override_opts> is new in Apache 2.2. The mod_perl implementation for
Apache 2.0 lets you pass the parameter but ignores it.

Default for C<$override_opts> is:
C<L<Apache2::Const::OPT_UNSET|docs::2.0::api::Apache2::Const/C_Apache2__Const__OPT_UNSET_>> |
C<L<Apache2::Const::OPT_ALL|docs::2.0::api::Apache2::Const/C_Apache2__Const__OPT_ALL_>> |
C<L<Apache2::Const::OPT_INCNOEXEC|docs::2.0::api::Apache2::Const/C_Apache2__Const__OPT_INCNOEXEC_>> |
C<L<Apache2::Const::OPT_SYM_OWNER|docs::2.0::api::Apache2::Const/C_Apache2__Const__OPT_SYM_OWNER_>> |
C<L<Apache2::Const::OPT_MULTI|docs::2.0::api::Apache2::Const/C_Apache2__Const__OPT_MULTI_>>

That means, all options are allowed.

=item ret: no return value

=item since: 2.0.00, C<$path> and C<$override_opts> since 2.0.3

=back

See also:
C<L<$s-E<gt>add_config|docs::2.0::api::Apache2::ServerUtil/C_add_config_>>

For example:

  use Apache2::RequestUtil ();
  use Apache2::Access ();

  $r->add_config(['require valid-user']);

  # this regards the current AllowOverride setting
  $r->add_config(['AuthName secret',
                  'AuthType Basic',
                  'Options ExecCGI'],
                 $r->allow_override, $path, $r->allow_override_opts);





=head2 C<as_string>

Dump the request object as a string

  $dump = $r->as_string();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item ret: C<$dump> ( string )

=item since: 2.0.00

=back

Dumps various request and response headers (mainly useful for
debugging)




=head2 C<child_terminate>

Terminate the current worker process as soon as the current request is
over

  $r->child_terminate();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item ret: no return value

=item since: 2.0.00

=back

This method is not supported in threaded MPMs



=head2 C<default_type>

Retrieve the value of the DefaultType directive for the current
request. If not set C<text/plain> is returned.

  $content_type = $r->default_type();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request

=item ret: C<$content_type> ( string )

The default type

=item since: 2.0.00

=item removed from the C<httpd> API in version 2.3.2

=back






=head2 C<dir_config>

C<$r-E<gt>dir_config()> provides an interface for the per-directory
variable specified by the C<PerlSetVar> and C<PerlAddVar> directives,
and also can be manipulated via the
C<L<APR::Table|docs::2.0::api::APR::Table>> methods.

  $table  = $r->dir_config();
  $value  = $r->dir_config($key);
  @values = $r->dir_config->get($key);
  $r->dir_config($key, $val);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item opt arg2: C<$key> ( string )

Key string

=item opt arg3: C<$val> ( string )

Value string

=item ret: ...

Depends on the passed arguments, see further discussion

=item since: 2.0.00

=back

The keys are case-insensitive.

  $apr_table = $r->dir_config();

dir_config() called in a scalar context without the C<$key> argument
returns a I<HASH> reference blessed into the
C<L<APR::Table|docs::2.0::api::APR::Table>> class. This object can be
manipulated via the C<L<APR::Table|docs::2.0::api::APR::Table>>
methods. For available methods see
the C<L<APR::Table|docs::2.0::api::APR::Table>> manpage.

  $value = $r->dir_config($key);

If the C<$key> argument is passed in the scalar context only a single
value will be returned. Since the table preserves the insertion order,
if there is more than one value for the same key, the oldest value
assosiated with the desired key is returned. Calling in the scalar
context is also much faster, as it'll stop searching the table as soon
as the first match happens.

  @values = $r->dir_config->get($key);

To receive a list of values you must use C<get()> method from the
C<L<APR::Table|docs::2.0::api::APR::Table>> class.

  $r->dir_config($key => $val);

If the C<$key> and the C<$val> arguments are used, the set() operation
will happen: all existing values associated with the key C<$key> (and
the key itself) will be deleted and C<$value> will be placed instead.

  $r->dir_config($key => undef);

If C<$val> is I<undef> the unset() operation will happen: all existing
values associated with the key C<$key> (and the key itself) will be
deleted.







=head2 C<document_root>

Retrieve the document root for this server

  $docroot = $r->document_root();
  $docroot = $r->document_root($new_root);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request

=item opt arg1: C<$new_root>

Sets the document root to a new value B<only for the duration of the
current request>.

Note the L<limited functionality under threaded
MPMs|docs::2.0::api::Apache2::ServerRec/Limited_Functionality_under_Threaded_MPMs>.

=item ret: C<$docroot> ( string )

The document root

=item since: 2.0.00

=back








=head2 C<get_handlers>

Returns a reference to a list of handlers enabled for a given phase.

  $handlers_list = $r->get_handlers($hook_name);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$hook_name> ( string )

a string representing the phase to handle (e.g. C<PerlLogHandler>)

=item ret: C<$handlers_list> (ref to an ARRAY of CODE refs)

a list of handler subroutines CODE references

=item since: 2.0.00

=back

See also:
C<L<$s-E<gt>add_config|docs::2.0::api::Apache2::ServerUtil/C_get_handlers_>>

For example:

A list of handlers configured to run at the response phase:

  my @handlers = @{ $r->get_handlers('PerlResponseHandler') || [] };







=head2 C<get_limit_req_body>

Return the limit on bytes in request msg body

  $limit = $r->get_limit_req_body();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request

=item ret: C<$limit> (integer)

the maximum number of bytes in the request msg body

=item since: 2.0.00

=back





=head2 C<get_server_name>

Get the current request's server name

  $server = $r->get_server_name();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request

=item ret: C<$server> ( string )

the server name

=item since: 2.0.00

=back

For example, consruct a hostport string:

  use Apache2::RequestUtil ();
  my $hostport = join ':', $r->get_server_name, $r->get_server_port;





=head2 C<get_server_port>

Get the current server port

  $port = $r->get_server_port();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

The current request

=item ret: C<$port> ( integer )

The server's port number

=item since: 2.0.00

=back

For example, consruct a hostport string:

  use Apache2::RequestUtil ();
  my $hostport = join ':', $r->get_server_name, $r->get_server_port;







=head2 C<get_status_line>

Return the C<Status-Line> for a given status code (excluding the
HTTP-Version field).

  $status_line = Apache2::RequestUtil::get_status_line($status);

=over 4

=item arg1: C<$status> (integer)

The HTTP status code

=item ret: C<$status_line> ( string )

The Status-Line

If an invalid or unknown status code is passed, C<"500 Internal Server
Error"> will be returned.

=item since: 2.0.00

=back

For example:

  use Apache2::RequestUtil ();
  print Apache2::RequestUtil::get_status_line(400);

will print:

  400 Bad Request





=head2 C<is_initial_req>

Determine whether the current request is the main request or a
sub-request

  $is_initial = $r->is_initial_req();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

A request or a sub-request object

=item ret: C<$is_initial> ( boolean )

If true -- it's the main request, otherwise it's a sub-request

=item since: 2.0.00

=back







=head2 C<is_perl_option_enabled>

check whether a directory level C<PerlOptions> flag is enabled or not.

  $result = $r->is_perl_option_enabled($flag);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$flag> ( string )

=item ret: C<$result> ( boolean )

=item since: 2.0.00

=back

For example to check whether the C<SetupEnv> option is enabled for the
current request (which can be disabled with C<PerlOptions -SetupEnv>)
and populate the environment variables table if disabled:

  $r->subprocess_env unless $r->is_perl_option_enabled('SetupEnv');

See also:
L<PerlOptions|docs::2.0::user::config::config/C_PerlOptions_> and
L<the equivalent function for server level PerlOptions
flags|docs::2.0::api::Apache2::ServerUtil/C_is_perl_option_enabled_>.





=head2 C<location>

Get the path of the E<lt>LocationE<gt> section from which the current
C<Perl*Handler> is being called.

  $location = $r->location();

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item ret: C<$location> ( string )

=item since: 2.0.00

=back






=head2 C<location_merge>

Merge a given C<E<lt>LocationE<gt>> container into the current request
object:

  $ret = $r->location_merge($location);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$location> ( string )

The argument in a C<E<lt>LocationE<gt>> section. For example to merge
a container:

  <Location /foo>
      ...
  </Location>

that argument will be I</foo>

=item ret: C<$ret> ( boolean )

a true value if the merge was successful (i.e. the request
C<$location> match was found), otherwise false.

=item since: 2.0.00

=back

Useful for insertion of a configuration section into a custom
C<Apache2::RequestRec> object, created via the
C<Apache2::RequestRec-E<gt>new()> method. See for example the L<Command
Server protocol
example|docs::2.0::user::handlers::protocols/Command_Server>.





=head2 C<new>

Create a new C<Apache2::RequestRec> object.

  $r = Apache2::RequestRec->new($c);
  $r = Apache2::RequestRec->new($c, $pool);

=over 4

=item obj: C<Apache2::RequestRec>
( C<L<Apache2::RequestRec class name|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$c>
(C<L<Apache2::Connection object|docs::2.0::api::Apache2::Connection>>)

=item opt arg2: C<$pool>

If no C<$pool> argument is passed, C<$c-E<gt>pool> is used. That means
that the created C<Apache2::RequestRec> object will be valid as long as
the connection object is valid.

=item ret: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item since: 2.0.00

=back

It's possible to reuse the HTTP framework features outside the
familiar HTTP request cycle. It's possible to write your own full or
partial HTTP implementation without needing a running Apache
server. You will need the C<Apache2::RequestRec> object in order to be
able to reuse the rich functionality supplied via this object.

See for example the L<Command Server protocol
example|docs::2.0::user::handlers::protocols/Command_Server> which
reuses HTTP AAA model under non-HTTP protocol.







=head2 C<no_cache>

Add/remove cache control headers:

  $prev_no_cache = $r->no_cache($boolean);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$boolean> ( boolean )

A true value sets the C<no_cache> request record member to a true
value and inserts:

  Pragma: no-cache
  Cache-control: no-cache

into the response headers, indicating that the data being returned is
volatile and the client should not cache it.

A false value unsets the C<no_cache> request record member and the
mentioned headers if they were previously set.

=item ret: C<$prev_no_cache> ( boolean )

Should you care, the C<no_cache> request record member value prior to
the change is returned.

=item since: 2.0.00

=back

This method should be invoked before any response data has been sent
out.





=head2 C<pnotes>

Share Perl variables between Perl HTTP handlers

  # to share variables by value and not reference, $val should be a lexical.
  $old_val  = $r->pnotes($key => $val);
  $val      = $r->pnotes($key);
  $hash_ref = $r->pnotes();

B<Note:> sharing variables really means it. The variable is not copied.
Only its reference count is incremented. If it is changed after being
put in pnotes that change also affects the stored value. The following
example illustrates the effect:

  my $v=1;                     my $v=1;
  $r->pnotes( 'v'=>$v );       $r->pnotes->{v}=$v;
  $v++;                        $v++;
  my $x=$r->pnotes('v');       my $x=$r->pnotes->{v};

In both cases C<$x> is C<2> not C<1>. See also C<Apache2::SafePnotes> on
CPAN.

There has been a lot of discussion advocating for pnotes sharing variables
by value and not reference.  Sharing by reference can create 'spooky action
at a distance' effects when the sharing is assumed to share a copy of the
value.  Tim Bunce offers the following summary and suggestion for sharing
by value.

What's wrong with this code:

  sub foo {
      my ($r, $status, $why) = @_;
      $r->pnotes('foo', ($why) ? "$status:$why" : $status);
      return;
  }

Nothing, except it doesn't work as expected due to this pnotes bug: If the 
same code is called in a sub-request then the pnote of $r-E<gt>prev is magically 
updated at a distance to the same value!

Try explain why that is to anyone not deeply familar with perl internals!

The fix is to avoid pnotes taking a ref to the invisible op_targ embededed in 
the code by passing a simple lexical variable as the actual argument. That can be done in-line like this:

  sub mark_as_internally_redirected {
      my ($r, $status, $why) = @_;
      $r->pnotes('foo', my $tmp = (($why) ? "$status:$why" : $status));
      return;
  }

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item opt arg1: C<$key> ( string )

A key value

=item opt arg2: C<$val> ( SCALAR )

Any scalar value (e.g. a reference to an array)

=item ret: (3 different possible values)

if both, C<$key> and C<$val> are passed the previous value for C<$key>
is returned if such existed, otherwise C<undef> is returned.

if only C<$key> is passed, the current value for the given key is
returned.

if no arguments are passed, a hash reference is returned, which can
then be directly accessed without going through the C<pnotes()>
interface.

=item since: 2.0.00

=back

This method provides functionality similar to
(C<L<Apache2::RequestRec::notes|docs::2.0::api::Apache2::RequestRec/C_notes_>>),
but values can be any Perl variables. That also means that it can be
used only between Perl modules.

The values get reset automatically at the end of each HTTP request.

Examples:

Set a key/value pair:

  $r->pnotes(foo => [1..5]);

Get the value:

  $val = $r->pnotes("foo");

C<$val> now contains an array ref containing 5 elements (C<1..5>).

Now change the existing value:

  $old_val = $r->pnotes(foo => ['a'..'c']);
  $val = $r->pnotes("foo");

C<$old_val> now contains an array ref with 5 elements (C<1..5>) and
C<$val> contains an array ref with 3 elements C<'a'>, C<'b'>, C<'c'>.

Alternatively you can access the hash reference with all pnotes
values:

  $pnotes = $r->pnotes;

Now we can read what's in there for the key I<foo>:

  $val = $pnotes->{foo};

and as before C<$val> still gives us an array ref with 3 elements
C<'a'>, C<'b'>, C<'c'>.

Now we can add elements to it:

  push @{ $pnotes{foo} }, 'd'..'f';

and we can try to retrieve them using the hash and non-hash API:

  $val1 = $pnotes{foo};
  $val2 = $r->pnotes("foo");

Both C<$val1> and C<$val2> contain an array ref with 6 elements
(letters 'a' to 'f').

Finally to reset an entry you could just assign C<undef> as a value:

  $r->pnotes(foo => undef);

but the entry for the key I<foo> still remains with the value
C<undef>. If you really want to completely remove it, use the hash
interface:

  delete $r->pnotes->{foo};








=head2 C<psignature>

Get HTML describing the address and (optionally) admin of the server.

  $sig = $r->psignature($prefix);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$prefix> ( string )

Text which is prepended to the return value

=item ret: C<$sig> ( string )

HTML text describing the server. Note that depending on the value of
the C<ServerSignature> directive, the function may return the address,
including the admin information or nothing at all.

=item since: 2.0.00

=back







=head2 C<request>

Get/set the ( C<L<Apache2::RequestRec
object|docs::2.0::api::Apache2::RequestRec>> ) object for the current
request.

  $r = Apache2::RequestUtil->request;
       Apache2::RequestUtil->request($new_r);

=over 4

=item obj: C<Apache2> (class name)

The Apache class name

=item opt arg1: C<$new_r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item ret: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item since: 2.0.00

=back

The get-able part of this method is only available if C<L<PerlOptions
+GlobalRequest|docs::2.0::user::config::config/C_GlobalRequest_>> is
in effect or if C<Apache2-E<gt>request($new_r)> was called earlier. So
instead of setting C<L<PerlOptions
+GlobalRequest|docs::2.0::user::config::config/C_GlobalRequest_>>, one
can set the global request from within the handler.






=head2 C<push_handlers>

Add one or more handlers to a list of handlers to be called for a
given phase.

  $ok = $r->push_handlers($hook_name => \&handler);
  $ok = $r->push_handlers($hook_name => ['Foo::Bar::handler', \&handler2]);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$hook_name> ( string )

the phase to add the handlers to

=item arg2: C<$handlers> ( CODE ref or SUB name or an ARRAY ref )

a single handler CODE reference or just a name of the subroutine
(fully qualified unless defined in the current package).

if more than one passed, use a reference to an array of CODE refs
and/or subroutine names.

=item ret: C<$ok> ( boolean )

returns a true value on success, otherwise a false value

=item since: 2.0.00

See also:
C<L<$s-E<gt>add_config|docs::2.0::api::Apache2::ServerUtil/C_push_handlers_>>

Note that to push input/output filters you have to use
C<L<Apache2::Filter|docs::2.0::api::Apache2::Filter>> methods:
C<L<add_input_filter|docs::2.0::api::Apache2::Filter/C_add_input_filter_>>
and
C<L<add_output_filter|docs::2.0::api::Apache2::Filter/C_add_output_filter_>>.

=back

Examples:

A single handler:

  $r->push_handlers(PerlResponseHandler => \&handler);

Multiple handlers:

  $r->push_handlers(PerlFixupHandler => ['Foo::Bar::handler', \&handler2]);

Anonymous functions:

  $r->push_handlers(PerlLogHandler => sub { return Apache2::Const::OK });






=head2 C<set_basic_credentials>

Populate the incoming request headers table (C<headers_in>) with
authentication headers for Basic Authorization as if the client has
submitted those in first place:

  $r->set_basic_credentials($username, $password);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$username> ( string )

=item arg2: C<$password> ( string )

=item ret: no return value

=item since: 2.0.00

=back

See for example the L<Command Server protocol
example|docs::2.0::user::handlers::protocols/Command_Server> which
reuses HTTP AAA model under non-HTTP protocol.







=head2 C<set_handlers>

Set a list of handlers to be called for a given phase. Any previously
set handlers are forgotten.

  $ok = $r->set_handlers($hook_name => \&handler);
  $ok = $r->set_handlers($hook_name => ['Foo::Bar::handler', \&handler2]);
  $ok = $r->set_handlers($hook_name => []);
  $ok = $r->set_handlers($hook_name => undef);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$hook_name> ( string )

the phase to set the handlers in

=item arg2: C<$handlers> (CODE ref or SUB name or an ARRAY ref)

a reference to a single handler CODE reference or just a name of the
subroutine (fully qualified unless defined in the current package).

if more than one passed, use a reference to an array of CODE refs
and/or subroutine names.

if the argument is C<undef> or C<[]> the list of handlers is reset to
zero.

=item ret: C<$ok> ( boolean )

returns a true value on success, otherwise a false value

=item since: 2.0.00

=back

See also:
C<L<$s-E<gt>add_config|docs::2.0::api::Apache2::ServerUtil/C_set_handlers_>>

Examples:

A single handler:

  $r->set_handlers(PerlResponseHandler => \&handler);

Multiple handlers:

  $r->set_handlers(PerlFixupHandler => ['Foo::Bar::handler', \&handler2]);

Anonymous functions:

  $r->set_handlers(PerlLogHandler => sub { return Apache2::Const::OK });

Reset any previously set handlers:

  $r->set_handlers(PerlCleanupHandler => []);

or

  $r->set_handlers(PerlCleanupHandler => undef);







=head2 C<slurp_filename>

Slurp the contents of C<$r-E<gt>filename>:

  $content_ref = $r->slurp_filename($tainted);

=over 4

=item obj: C<$r>
( C<L<Apache2::RequestRec object|docs::2.0::api::Apache2::RequestRec>> )

=item arg1: C<$tainted> (number)

If the server is run under the tainting mode (C<-T>) which we hope you
do, by default the returned data is tainted. If an optional
C<$tainted> flag is set to zero, the data will be marked as
non-tainted.

Do B<not> set this flag to zero unless you know what you are doing,
you may create a security hole in your program if you do. For more
information see the I<perlsec> manpage.

If you wonder why this option is available, it is used internally by
the C<L<ModPerl::Registry|docs::2.0::api::ModPerl::Registry>> handler
and friends, because the CGI scripts that it reads are considered safe
(you could just as well C<require()> them).

=item ret: C<$content_ref> ( SCALAR ref )

A reference to a string with the contents

=item excpt: C<L<APR::Error|docs::2.0::api::APR::Error>>

Possible error codes could be:
C<L<APR::Const::EACCES|docs::2.0::api::APR::Const/C_APR__Const__EACCES_>>
(permission problems),
C<L<APR::Const::ENOENT|docs::2.0::api::APR::Const/C_APR__Const__ENOENT_>>
(file not found), and others. For checking such error codes, see the
documentation for, for example,
C<L<APR::Status::is_EACCES|docs::2.0::api::APR::Status/C_is_EACCES_>>
and
C<L<APR::Status::is_ENOENT|docs::2.0::api::APR::Status/C_is_ENOENT_>>.


=item since: 2.0.00

=back

Note that if you assign to C<$r-E<gt>filename> you need to L<update
its stat record|docs::2.0::api::Apache2::RequestRec/C_filename_>.





=head1 See Also

L<mod_perl 2.0 documentation|docs::2.0::index>.




=head1 Copyright

mod_perl 2.0 and its core modules are copyrighted under
The Apache Software License, Version 2.0.




=head1 Authors

L<The mod_perl development team and numerous
contributors|about::contributors::people>.

=cut

