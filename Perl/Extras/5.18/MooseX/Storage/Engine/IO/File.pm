package MooseX::Storage::Engine::IO::File;
{
  $MooseX::Storage::Engine::IO::File::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::Engine::IO::File::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: The actually file storage mechanism.
use Moose;

use IO::File;

has 'file' => (
    is       => 'ro',
    isa      => 'Str',
    required => 1,
);

sub load {
    my ($self) = @_;
    my $fh = IO::File->new($self->file, 'r')
        || confess "Unable to open file (" . $self->file . ") for loading : $!";
    return do { local $/; <$fh>; };
}

sub store {
    my ($self, $data) = @_;
    my $fh = IO::File->new($self->file, 'w')
        || confess "Unable to open file (" . $self->file . ") for storing : $!";
    $fh->binmode(':utf8') if utf8::is_utf8($data);
    print $fh $data;
}

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Chris Prather Stevan Little יובל קוג'מן (Yuval Kogman) Infinity
Interactive, Inc. Florian Ragwitz Johannes Plunien Jonathan Rockway Yu Jos
Boumans Karen Etheridge Ricardo Signes Robert Boone Shawn M Moore Tomas
Doran Cory Yuval Kogman Watson Dagfinn Ilmari Mannsåker David Golden
Steinbrunner

=head1 NAME

MooseX::Storage::Engine::IO::File - The actually file storage mechanism.

=head1 VERSION

version 0.45

=head1 DESCRIPTION

This provides the actual means to store data to a file.

=head1 METHODS

=over 4

=item B<file>

=item B<load>

=item B<store ($data)>

=back

=head2 Introspection

=over 4

=item B<meta>

=back

=head1 BUGS

All complex software has bugs lurking in it, and this module is no
exception. If you find a bug please either email me, or add the bug
to cpan-RT.

=head1 AUTHORS

=over 4

=item *

Chris Prather <chris.prather@iinteractive.com>

=item *

Stevan Little <stevan.little@iinteractive.com>

=item *

יובל קוג'מן (Yuval Kogman) <nothingmuch@woobling.org>

=back

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2007 by Infinity Interactive, Inc..

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
