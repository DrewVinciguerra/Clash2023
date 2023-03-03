#include "Terrain.h"

Terrain::Terrain() {
	m_terrain_type = GRASS;

	TerrainMap[PLAYER_1_STARTING_LAND] = "P1 StartLand";
	TerrainMap[PLAYER_2_STARTING_LAND] = "P2 StartLand";
	TerrainMap[PLAYER_1_SUMMONING] = "P1 Summoning";
	TerrainMap[PLAYER_2_SUMMONING] = "P2 Summoning";
	TerrainMap[PLAYER_1_MANA_SOURCE] = "P1 ManaSource";
	TerrainMap[PLAYER_2_MANA_SOURCE] = "P2 ManaSource";

	TerrainMap[PAVED] = "PAVED";
	TerrainMap[MOUNTAIN] = "MOUNTAIN";
	TerrainMap[WATER] = "WATER";
	TerrainMap[MUD] = "MUD";
	TerrainMap[LAVA] = "LAVA";
	TerrainMap[GRASS] = "GRASS";
	TerrainMap[DESERT] = "DESERT";
	TerrainMap[SWAMP] = "SWAMP";
	TerrainMap[EMPTY] = "VOID";

	TerrainMap[TUNNEL] = "TUNNEL";
		
}

Terrain::~Terrain() {

}

void Terrain::TerrainData(Terrain::TERRAIN_TYPE type) {

	m_terrain_type = type;

}

Terrain::TERRAIN_TYPE Terrain::TerrainData() {

	return m_terrain_type;
}

std::string Terrain::TerrainName() {

	return TerrainMap[m_terrain_type];
}
