package MooseX::Getopt::Strict;
{
  $MooseX::Getopt::Strict::VERSION = '0.59';
}
BEGIN {
  $MooseX::Getopt::Strict::AUTHORITY = 'cpan:STEVAN';
}
# ABSTRACT: only make options for attributes with the Getopt metaclass

use Moose::Role;

with 'MooseX::Getopt';

around '_compute_getopt_attrs' => sub {
    my $next = shift;
    my ( $class, @args ) = @_;
    grep {
        $_->does("MooseX::Getopt::Meta::Attribute::Trait")
    } $class->$next(@args);
};

no Moose::Role;

1;

__END__

=pod

=encoding UTF-8

=for :stopwords Stevan Little Infinity Interactive, Inc

=head1 NAME

MooseX::Getopt::Strict - only make options for attributes with the Getopt metaclass

=head1 VERSION

version 0.59

=head1 DESCRIPTION

This is an stricter version of C<MooseX::Getopt> which only processes the
attributes if they explicitly set as C<Getopt> attributes. All other attributes
are ignored by the command line handler.

=head1 AUTHOR

Stevan Little <stevan@iinteractive.com>

=head1 COPYRIGHT AND LICENSE

This software is copyright (c) 2007 by Infinity Interactive, Inc.

This is free software; you can redistribute it and/or modify it under
the same terms as the Perl 5 programming language system itself.

=cut
