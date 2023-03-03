#include "HexBoardSpace.h"

HexBoardSpace::HexBoardSpace()
{
	pCreature = NULL;
	pPlayer = NULL;
	pTerrain = NULL;
	m_name = "Blank";
}


void HexBoardSpace::name(std::string name_value)
{
	// TODO: Add your implementation code here.
	m_name = name_value;
}

std::string HexBoardSpace::name()
{
	// TODO: Add your implementation code here.
	return m_name;
}

void HexBoardSpace::terrain(Terrain* terrain_value)
{
	pTerrain = terrain_value;
}

Terrain* HexBoardSpace::terrain()
{
	return pTerrain;
}

void HexBoardSpace::creature(Creature* creature_value)
{
	pCreature = creature_value;
}

Creature* HexBoardSpace::creature()
{
	return pCreature;
}

void HexBoardSpace::player(Player* player_value)
{
	pPlayer = player_value;
}

Player* HexBoardSpace::player()
{
	return pPlayer;
}


