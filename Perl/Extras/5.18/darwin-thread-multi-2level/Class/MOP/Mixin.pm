package Class::MOP::Mixin;
BEGIN {
  $Class::MOP::Mixin::AUTHORITY = 'cpan:STEVAN';
}
$Class::MOP::Mixin::VERSION = '2.1202';
use strict;
use warnings;

use Scalar::Util 'blessed';

sub meta {
    require Class::MOP::Class;
    Class::MOP::Class->initialize( blessed( $_[0] ) || $_[0] );
}

1;

# ABSTRACT: Base class for mixin classes

__END__

=pod

=encoding UTF-8

=head1 NAME

Class::MOP::Mixin - Base class for mixin classes

=head1 VERSION

version 2.1202

=head1 DESCRIPTION

This class provides a single method shared by all mixins

=head1 METHODS

This class provides a few methods which are useful in all metaclasses.

=over 4

=item B<< Class::MOP::Mixin->meta >>

This returns a L<Class::MOP::Class> object for the mixin class.

=back

=head1 AUTHORS

=over 4

=item *

Stevan Little <stevan.little@iinteractive.com>

=item *

Dave Rolsky <autarch@urth.org>

=item *

Jesse Luehrs <doy@tozt.net>

=item *

Shawn M Moore <code@sartak.org>

=item *

יובל קוג'מן (Yuval Kogman) <nothingmuch@woobling.org>

=item *

Karen Etheridge <ether@cpan.org>

=item *

Florian Ragwitz <rafl@debian.org>

=item *

Hans Dieter Pearcey <hdp@weftsoar.net>

=item *

Chris Prather <chris@prather.org>

=item *

Matt S Trout <mst@shadowcat.co.uk>

=back

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2006 by Infinity Interactive, Inc..

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
