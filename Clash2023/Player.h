#pragma once
#include <string>
//#include <combaseapi.h>
#include <vector>
#include "Creature.h"

class Player
{
public:
	Player();
	int Id();
	void Id(int number);
	std::string Name();
	void Name(std::string target_name);
	void HitPoints(int hitpoints);
	int HitPoints();
//	void PlayerNumber(int number);
//	int PlayerNumber();


private:
	int health;
	std::string m_name;
	int movement;
	int player_id;	// Each player has it's own ID
//	int player_number;	//1st player, 2nd player, etc

	//  Make a vector that holds a deck of cards and use std::random_shuffle or std::shuffle 
	std::vector<Creature> creature_vector;


};

