#pragma once
#include <string>
//#include <guiddef.h>
#include <combaseapi.h>

class Player
{
public:
	Player();
	GUID get_id();
	std::string get_name();
	void name(std::string target_name);
	void hit_points(int hitpoints);
	int hit_points();
	void PlayerNumber(int number);
	int PlayerNumber();

private:
	int health;
	std::string m_name;
	int movement;
	GUID id;	// Each player has it's own ID
	int player_number;	//1st player, 2nd player, etc

};

