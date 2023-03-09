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

	// Accessors
	std::string Name() const { return name; }
	int Health() const { return health; }
	int AttackRangeClose() const { return attack_range_close; }
	int AttackRangeFar() const { return attack_range_far; }
	int Shield() const { return shield; }
	int Movement() const { return movement; }
	bool isFlying() const { return flying; }
	bool isAggressive() const { return aggressive; }
	bool isDefensive() const { return defensive; }
	bool isOpportunistic() const { return opportunistic; }
	int ControllerId() const { return controler_id; }
	int PlayerTargetId() const { return player_target_id; }
	int CreatureTargetId() const { return creature_target_id; }
	int HexTargetId() const { return hex_target_id; }
	int Id() const { return id; }
	int X() const { return x; }
	int Y() const { return y; }


	// Mutators
	void Name(std::string name) { this->name = name; }
	void Health(int health) { this->health = health; }
	void AttackRangeClose(int attack_range_close) { this->attack_range_close = attack_range_close; }
	void AttackRangeFar(int attack_range_far) { this->attack_range_far = attack_range_far; }
	void Shield(int shield) { this->shield = shield; }
	void Movement(int movement) { this->movement = movement; }
	void Flying(bool flying) { this->flying = flying; }
	void Aggressive(bool aggressive) { this->aggressive = aggressive; }
	void Defensive(bool defensive) { this->defensive = defensive; }
	void Opportunistic(bool opportunistic) { this->opportunistic = opportunistic; }
	void ControllerId(int controller_id) { this->controler_id = controller_id; }
	void PlayerTargetId(int player_target_id) { this->player_target_id = player_target_id; }
	void CreatureTargetId(int creature_target_id) { this->creature_target_id = creature_target_id; }
	void HexTargetId(int hex_target_id) { this->hex_target_id = hex_target_id; }
	void Id(int id) { this->id = id; }
	void X(int x) { this->x = x; }
	void Y(int y) { this->y = y; }
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