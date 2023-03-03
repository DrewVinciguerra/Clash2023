#pragma once
#include <string>
//#include <guiddef.h>
#include <combaseapi.h>

class Player
{
public:
	Player();
	GUID Id();
	std::string Name();
	void Name(std::string target_name);
	void HitPoints(int hitpoints);
	int HitPoints();
	void PlayerNumber(int number);
	int PlayerNumber();


private:
	int health;
	std::string m_name;
	int movement;
	GUID player_id;	// Each player has it's own ID
	int player_number;	//1st player, 2nd player, etc

};

