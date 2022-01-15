#!/usr/bin/perl

use strict;
use warnings;

sub OutputLoop($);
sub OutputEngine($);

my $current_bank;
my $current_addr;
my @loop_prefix;

require "./wram.pl";
our @wram;

my $data = [
	{ "origin" => 0x5642, "bank" => "03", "name" => "ItemJumpTable" },
	@wram,
];

OutputLoop($data);

sub OutputLoop($){
	my $data = shift;
	foreach my $d (@$data){
		OutputEngine($d);
	}
}

sub OutputEngine($){
	my $d = shift;

	if(exists $d->{"origin"}){ $current_addr = $d->{"origin"}; }
	if(exists $d->{"bank"}){ $current_bank = $d->{"bank"}; }
	if(exists $d->{"loop"}){
		my $max = $d->{"loop"};
		for(my $i = 1; $i <= $max; $i++){
			push @loop_prefix, sprintf($d->{"prefix"}, $i);
			OutputLoop($d->{"data"});
			pop @loop_prefix;
		}
	}elsif(exists $d->{"prefix"}){
		push @loop_prefix, $d->{"prefix"};
		OutputLoop($d->{"data"});
		pop @loop_prefix;
	}

	if(exists $d->{"comment"}){
		print "; " . $d->{"comment"} . "\n";
	}

	if(exists $d->{"name"}){
		printf("%s:%04x %s\n", $current_bank, $current_addr, join("",@loop_prefix, $d->{"name"}));
		if(exists $d->{"size"}){
			$current_addr += $d->{"size"};
		}else{
			$current_addr++;
		}
	}
	if(exists $d->{"skip"}){
		$current_addr += $d->{"skip"};
	}
}

