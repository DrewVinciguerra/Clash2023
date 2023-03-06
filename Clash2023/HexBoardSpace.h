#pragma once
#include "Creature.h"
#include "Player.h"
#include "Terrain.h"

class HexBoardSpace
{
public:
	void CreatureData(Creature* creature_value);
	Creature* CreatureData();

	HexBoardSpace();
	void Name(std::string);
	std::string Name();

	void TerrainData(Terrain* terrain_value);
	Terrain* TerrainData();

	void PlayerData(Player* player_value);
	Player* PlayerData();



private:
	Creature* pCreature;
	Player* pPlayer;
	Terrain* pTerrain;
	std::string m_name;
	

};

