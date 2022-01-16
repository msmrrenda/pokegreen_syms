#!/usr/bin/perl

use strict;
use warnings;

sub OutputLoop($);
sub OutputEngine($);

my $current_bank;
my $current_addr;
my @loop_prefix;

require "./wram.pl";
require "./hram.pl";
our @wram;
our @hram;

my $data = [
	{ "origin" => 0x01A3, "bank" => "00", "name" => "FarMemCopy" },
	{ "origin" => 0x01BB, "bank" => "00", "name" => "MemCopy" },
	{ "origin" => 0x186A, "bank" => "00", "name" => "ChooseQuantity" },
	{ "origin" => 0x1B55, "bank" => "00", "name" => "IsHiddenMachine" },
	{ "origin" => 0x3121, "bank" => "00", "name" => "FarCall_IsKeyItem" },
	{ "origin" => 0x3620, "bank" => "00", "name" => "FarCall" },
	{ "origin" => 0x3827, "bank" => "00", "name" => "GetItemPrice" },
	{ "origin" => 0x3E9D, "bank" => "00", "name" => "CallFunction" },
	{ "origin" => 0x421C, "bank" => "01", "name" => "ItemPriceList" },
	{ "origin" => 0x5642, "bank" => "03", "name" => "ItemJumpTable" },
	{ "origin" => 0x6A6F, "bank" => "03", "name" => "IsKeyItemImpl" },
	{ "origin" => 0x6AA4, "bank" => "03", "name" => "KeyItemFlagList" },
	{ "origin" => 0x799C, "bank" => "03", "name" => "OperateBitfield" },
	@wram,
	@hram,
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

