#!/usr/bin/perl

# Copyright 2007 Messiah College. All rights reserved.
# Jason Long <jlong@messiah.edu>

use strict;
use warnings;

# This class contains a method to perform synchronous DNS queries.
# Hopefully some day it will have a method to perform
# asynchronous DNS queries.

package Mail::DKIM::DNS;
use Net::DNS;
our $TIMEOUT = 10;

# query- returns a list of RR objects
#   or an empty list if the domain record does not exist
#       (e.g. in the case of NXDOMAIN or NODATA)
#   or throws an error on a DNS query time-out or other transient error
#       (e.g. SERVFAIL)
#
# if an empty list is returned, $@ is also set to a string explaining
# why no records were returned (e.g. "NXDOMAIN").
#
sub query
{
	my ($domain, $type) = @_;

	my $rslv = Net::DNS::Resolver->new()
		or die "can't create DNS resolver";

	#
	# perform the DNS query
	#   if the query takes too long, we should generate an error
	#
	my $resp;
	my $remaining_time = alarm(0);  # check time left, stop the timer
	my $deadline = time + $remaining_time;
	eval
	{
		# set a 10 second timeout
		local $SIG{ALRM} = sub { die "DNS query timeout for $domain\n" };
		alarm $TIMEOUT;

		# the query itself could cause an exception, which would prevent
		# us from resetting the alarm before leaving the eval {} block
		# so we wrap the query in a nested eval {} block
		eval
		{
			$resp = $rslv->query($domain, $type);
		};
		my $E = $@;
		alarm 0;
		die $E if $E;
	};
	my $E = $@;
	alarm 0;
	# restart the timer if it was active
	if ($remaining_time > 0)
	{
		my $dt = $deadline - time;
		# make sure the timer expiration will trigger a signal,
		# even at the expense of stretching the interval by one second
		alarm($dt < 1 ? 1 : $dt);
	}
	die $E if $E;

	if ($resp)
	{
		my @result = grep { lc $_->type eq lc $type } $resp->answer;
		return @result if @result;
	}

	$@ = $rslv->errorstring;
	return () if ($@ eq "NOERROR" || $@ eq "NXDOMAIN");
	die "DNS error: $@\n";
}

# query_async() - perform a DNS query asynchronously
#
#   my $waiter = query_async("example.org", "TXT",
#                        Callbacks => {
#                                Success => \&on_success,
#                                Error => \&on_error,
#                                },
#                            );
#   my $result = $waiter->();
#
sub query_async
{
	my ($domain, $type, %prms) = @_;

	my $callbacks = $prms{Callbacks} || {};
	my $on_success = $callbacks->{Success} || sub { $_[0] };
	my $on_error = $callbacks->{Error} || sub { die $_[0] };

	my $waiter = sub {
		my @resp;
		my $warning;
		eval {
			@resp = query($domain, $type);
			$warning = $@;
			undef $@;
		};
		$@ and return $on_error->($@);
		$@ = $warning;
		return $on_success->(@resp);
	};
	return $waiter;
}

1;
