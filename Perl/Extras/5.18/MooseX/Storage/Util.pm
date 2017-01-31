package MooseX::Storage::Util;
{
  $MooseX::Storage::Util::VERSION = '0.45';
}
BEGIN {
  $MooseX::Storage::Util::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: A MooseX::Storage Swiss Army chainsaw

use Moose qw(confess blessed);

use MooseX::Storage::Engine ();

sub peek {
    my ($class, $data, %options) = @_;

    if (exists $options{'format'}) {

        my $inflater = $class->can('_inflate_' . lc($options{'format'}));

        (defined $inflater)
            || confess "No inflater found for " . $options{'format'};

        $data = $class->$inflater($data);
    }

    (ref($data) && ref($data) eq 'HASH' && !blessed($data))
        || confess "The data has to be a HASH reference, but not blessed";

    $options{'key'} ||= $MooseX::Storage::Engine::CLASS_MARKER;

    return $data->{$options{'key'}};

}

sub _inflate_json {
    my ($self, $json) = @_;

    eval { require JSON::Any; JSON::Any->import };
    confess "Could not load JSON module because : $@" if $@;

    utf8::encode($json) if utf8::is_utf8($json);

    my $data = eval { JSON::Any->jsonToObj($json) };
    if ($@) {
        confess "There was an error when attempting to peek at JSON: $@";
    }

    return $data;
}

sub _inflate_yaml {
    my ($self, $yaml) = @_;

    eval { require YAML::Any; YAML::Any->import };
    confess "Could not load YAML module because : $@" if $@;

    my $data = eval { Load($yaml) };
    if ($@) {
        confess "There was an error when attempting to peek at YAML : $@";
    }
    return $data;
}

no Moose::Role;

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Chris Prather Stevan Little יובל קוג'מן (Yuval Kogman) Infinity
Interactive, Inc. Florian Ragwitz Johannes Plunien Jonathan Rockway Yu Jos
Boumans Karen Etheridge Ricardo Signes Robert Boone Shawn M Moore Tomas
Doran Cory Yuval Kogman Watson Dagfinn Ilmari Mannsåker David Golden
Steinbrunner TODO

=head1 NAME

MooseX::Storage::Util - A MooseX::Storage Swiss Army chainsaw

=head1 VERSION

version 0.45

=head1 DESCRIPTION

This module provides a set of tools, some sharp and focused,
others more blunt and crude. But no matter what, they are useful
bits to have around when dealing with MooseX::Storage code.

=head1 METHODS

All the methods in this package are class methods and should
be called appropriately.

=over 4

=item B<peek ($data, %options)>

This method will help you to verify that the serialized class you
have gotten is what you expect it to be before you actually
unfreeze/unpack it.

The C<$data> can be either a perl HASH ref or some kind of serialized
data (JSON, YAML, etc.).

The C<%options> are as follows:

=over 4

=item I<format>

If this is left blank, we assume that C<$data> is a plain perl HASH ref
otherwise we attempt to inflate C<$data> based on the value of this option.

Currently only JSON and YAML are supported here.

=item I<key>

The default is to try and extract the class name, but if you want to check
another key in the data, you can set this option. It will return the value
found in the key for you.

=back

=back

=head2 Introspection

=over 4

=item B<meta>

=back

=head1 TODO

Add more stuff to this module :)

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
