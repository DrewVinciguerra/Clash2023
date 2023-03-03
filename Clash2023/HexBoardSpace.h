#pragma once
#include "Creature.h"
#include "Player.h"
#include "Terrain.h"

class HexBoardSpace
{
public:
	HexBoardSpace();
	void name(std::string);
	std::string name();

	void terrain(Terrain* terrain_value);
	Terrain* terrain();

	void creature(Creature* creature_value);
	Creature* creature();

	void player(Player* player_value);
	Player* player();



private:
	Creature* pCreature;
	Player* pPlayer;
	Terrain* pTerrain;
	std::string m_name;
	

};

