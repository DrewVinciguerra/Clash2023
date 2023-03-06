#pragma once
//#include "HexBoardSpace.h"
//#include <guiddef.h>
//#include <combaseapi.h>
#include <string>

class Creature
{
private:

	std::string	name;
	int health;
	int attack_range_close;		// How close it can attack
	int attack_range_far;		// How far away it can attack
	int shield;					// absorbs this much damage each turn
	int movement;
	bool flying;
	bool aggressive;			// It will only try to get to the target player.
	bool defensive;				// It will stay back and protect the summoner.
	bool opportunistic;			// If the player is being attacked, it will switch to defensive, otherwise it will act aggressive.

	int controler_id;			// Which player controls this creature

	//I should be able to use a forward dec if I really want to use this.
	//HexBoardSpace* p_location;	// Where this creature is currently located

	// I need a way to mark a target for this creature to travel to and/or attack
	// A creature could either want to travel to the other player, a specific creature or just a hex.
	int player_target_id;
	int creature_target_id;
	int hex_target_id;

	int id;					// This creature's id
	
	//Hex grid location
	int x;	
	int y;

public:
	Creature(std::string name, int health, int attack_range_close, int attack_range_far, int movement, int controler_id, int player_target_id, int x, int y);
	~Creature();
	std::string Name();
};

/*Beholder
Dragon (any color or type)
Mind Flayer
Orc
Goblin
Troll
Giant (any type)
Kobold
Medusa
Basilisk
Hydra
Chimera
Manticore
Gelatinous Cube
Rust Monster
Mimic
Gargoyle
Harpy
Minotaur
Skeleton*/