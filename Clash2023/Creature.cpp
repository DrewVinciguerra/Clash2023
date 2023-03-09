#include "Creature.h"


Creature::Creature(std::string name_value, int health_value, int attack_range_close_value, int attack_range_far_value, int movement_value, 
	int controler_player_id_value, int player_target_id_value, int x, int y) {
	name = name_value;
	health = health_value;
	attack_range_close = attack_range_close_value;		// How close it can attack
	attack_range_far = attack_range_far_value;		// How far away it can attack
	shield = 0;					// absorbs this much damage each turn
	movement = movement_value;
	flying = false;
	aggressive = false;			// It will only try to get to the target player.
	defensive = false;				// It will stay back and protect the summoner.
	opportunistic = false;			// If the player is being attacked, it will switch to defensive, otherwise it will act aggressive.

	controler_id = controler_player_id_value;			// Which player controls this creature

	// I need a way to mark a target for this creature to travel to and/or attack
	// A creature could either want to travel to the other player, a specific creature or just a hex.
	player_target_id = player_target_id_value;
	creature_target_id = 0;
	hex_target_id = 0;

	id = 1;	// Use a static to control this id?  Trying to avoid GUIDS if possible 

	this->x = x;
	this->y = y;
}


Creature::~Creature() {


}

std::string Creature::Name() {
	return name;
}
