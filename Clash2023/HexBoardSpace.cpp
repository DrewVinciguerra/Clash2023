#include "HexBoardSpace.h"

HexBoardSpace::HexBoardSpace()
{
	pCreature = NULL;
	pPlayer = NULL;
	pTerrain = NULL;
	m_name = "Blank";
	x = -1;
	y = -1;

}


void HexBoardSpace::Name(std::string name_value)
{
	// TODO: Add your implementation code here.
	m_name = name_value;
}

std::string HexBoardSpace::Name()
{
	// TODO: Add your implementation code here.
	return m_name;
}

void HexBoardSpace::TerrainData(Terrain* terrain_value)
{
	pTerrain = terrain_value;
}

Terrain* HexBoardSpace::TerrainData()
{
	return pTerrain;
}

void HexBoardSpace::CreatureData(Creature* creature_value)
{
	pCreature = creature_value;
}

Creature* HexBoardSpace::CreatureData()
{
	return pCreature;
}

void HexBoardSpace::PlayerData(Player* player_value)
{
	pPlayer = player_value;
}

Player* HexBoardSpace::PlayerData()
{
	return pPlayer;
}


