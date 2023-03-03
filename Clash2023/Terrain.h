#pragma once
#include <map>
#include <string>

class Terrain
{

public:
	enum TERRAIN_TYPE
	{
		PLAYER_1_STARTING_LAND,
		PLAYER_2_STARTING_LAND,
		PLAYER_1_SUMMONING,
		PLAYER_2_SUMMONING,
		PLAYER_1_MANA_SOURCE,
		PLAYER_2_MANA_SOURCE,
		PAVED,
		MOUNTAIN,
		WATER,
		MUD,
		LAVA,
		GRASS,
		DESERT,
		SWAMP,
		EMPTY,
		TUNNEL
	};

	std::map<TERRAIN_TYPE, std::string> TerrainMap;
	std::string TerrainName();

	Terrain();
	~Terrain();

	void TerrainData(TERRAIN_TYPE type);
	TERRAIN_TYPE TerrainData();




private:
	TERRAIN_TYPE m_terrain_type;

};

