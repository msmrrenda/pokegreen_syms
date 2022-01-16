#!/usr/bin/perl

use strict;
use warnings;

my @box_pokemon_structure = (
		{ "name" => "InternalId"},
		{ "name" => "CurrentHp" , "size" => 2 },
		{ "name" => "BoxLevel"  },
		{ "name" => "Status"    },
		{ "name" => "Type1"     },
		{ "name" => "Type2"     },
		{ "name" => "RarityOrItem" },
		{ "loop" => 4, "prefix" => "Move%d","data" => [
			{ "name" => "Id" },
		]},
		{ "name" => "TrainerId" , "size" => 2 },
		{ "name" => "Exp" , "size" => 3 },
		{ "name" => "HpExp" , "size" => 2 },
		{ "name" => "AtkExp" , "size" => 2 },
		{ "name" => "DefExp" , "size" => 2 },
		{ "name" => "SpdExp" , "size" => 2 },
		{ "name" => "SpcExp" , "size" => 2 },
		{ "name" => "Potential" , "size" => 2 },
		{ "loop" => 4, "prefix" => "Move%d","data" => [
			{ "name" => "PP" },
		]},
);

our @wram = (
	{ "origin" => 0xCEE4, "bank" => "00", "name" => "GenericBufferCEE4" },

	{ "origin" => 0xd039, "bank" => "01", "name" => "EncountId" },
	{ "origin" => 0xd03a, "bank" => "01", "name" => "TrainerVariation" },
	{ "origin" => 0xd0e9, "bank" => "01", "name" => "ItemSellSelected" },
	{ "origin" => 0xd123, "bank" => "01" },
	{ "name" => "PartyCount" },
	{ "loop" => 7, "prefix" => "Party%d", "data" => [
		{ "name" => "ExternalId" },
	]},
	{ "loop" => 6, "prefix" => "Party%d", "data" => [
		@box_pokemon_structure,
		{ "name" => "Level"  },
		{ "name" => "Hp" , "size" => 2 },
		{ "name" => "Atk" , "size" => 2 },
		{ "name" => "Def" , "size" => 2 },
		{ "name" => "Spd" , "size" => 2 },
		{ "name" => "Spc" , "size" => 2 },
	]},
	{ "loop" => 6, "prefix" => "Party%d", "data" => [
		{ "name" => "TrainerName" , "size" => 6 },
	]},
	{ "loop" => 6, "prefix" => "Party%d", "data" => [
		{ "name" => "NickName" , "size" => 6 },
	]},
	{ "name" => "PokeDexCaught" , "size" => 19 },
	{ "name" => "PokeDexFound"  , "size" => 19 },

	{ "name" => "ItemCount" },
	{ "loop" => 20, "prefix" => "Item%02d", "data" => [
		{ "name" => "Type" },
		{ "name" => "Count" },
	]},
	{ "name" => "ItemTerminate" },
	{ "name" => "Money", "size" => 3 },
	{ "name" => "RivalName" , "size" => 6 },
	{ "name" => "Config" },
	{ "name" => "Badge" },
	{ "skip" => 2, "comment" => "unknown D2D6,D2D7" },
	{ "name" => "PlayerId" , "size" => 2 },
	{ "name" => "BGMno" },
	{ "name" => "BGMbank" },
	{ "name" => "ColorPattern" },
	{ "name" => "CurrentMapId" },
	{ "name" => "CurrentMapTileNo", "size" => 2 },
	{ "name" => "PlayerY" },
	{ "name" => "PlayerX" },
	{ "name" => "TileOffsetY" },
	{ "name" => "TileOffsetX" },
	{ "name" => "OuterMapNo" },
	{ "skip" => 6 },
	{ "name" => "NPCMsgPtr", "size" => 2},
	{ "name" => "MapEventPtr", "size" => 2},

	{ "origin" => 0xd4b9, "bank" => "01" },
	{ "name" => "PCItemCount" },
	{ "loop" => 20, "prefix" => "PCItem%02d", "data" => [
		{ "name" => "Type" },
		{ "name" => "Count" },
	]},
	{ "name" => "PCItemTerminate" },

	{ "origin" => 0xd523, "bank" => "01" },
	{ "name" => "Coin", "size" => 2 },

	{ "origin" => 0xd62c, "bank" => "01" },
	{ "name" => "KuchibaGymTrash1st" },
	{ "name" => "KuchibaGymTrash2nd" },

	{ "origin" => 0xd67f, "bank" => "01" },
	{ "name" => "MoveTypeFlag", "size" => 1, "comment" => "自転車 0x01: 倍速移動 0x02: 倍速解除" },

	{ "origin" => 0xd68a, "bank" => "01" },
	{ "name" => "FlySelectableFlag", "size" => 2 },
	{ "skip" => 2 },
	{ "name" => "FossilItemId" },
	{ "name" => "FossilPokemonId" },
	{ "skip" => 3 },
	{ "name" => "JumpCounter" },
	{ "skip" => 4 },
	{ "name" => "TeleportDestination" },
	{ "name" => "FlyDestination" },

	{ "origin" => 0xd808, "bank" => "01" },
	{ "loop" => 20, "prefix" => "EncountTable%02d", "data" => [
		{ "name" => "PokemonId" },
		{ "name" => "Level" },
	]},

	{ "origin" => 0xd985, "bank" => "01" },
	{ "prefix" => "DayCare", "data" => [
		{ "name" => "NickName" , "size" => 6},
		{ "name" => "TrainerName" , "size" => 6},
		@box_pokemon_structure,
	]},
	{ "name" => "BoxCount"},
	{ "loop" => 31, "prefix" => "Box%02d", "data" => [
		{ "name" => "ExternalId" },
	]},
	{ "loop" => 30, "prefix" => "Box%02d", "data" => [
		@box_pokemon_structure,
	]},
	{ "loop" => 30, "prefix" => "Box%02d", "data" => [
		{ "name" => "TrainerName" , "size" => 6},
	]},
	{ "loop" => 30, "prefix" => "Box%02d", "data" => [
		{ "name" => "NickName" , "size" => 6},
	]},
);

