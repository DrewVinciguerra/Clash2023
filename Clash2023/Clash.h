#pragma once
#include <iostream>
#include <vector>

#include "Creature.h"
#include "Player.h"
#include "HexBoardSpace.h"
#include "Terrain.h"

class Clash
{
public:
	Clash();      // Constructor
	~Clash();

	int SetupClash();
	void DumpScreenData();
	std::vector<Player>* Players();
	void PlacePlayerOnBoard(int x, int y, Player* target_player);
	void AddPlayer(std::string name, int player_number);

private:
	enum BOARD
	{
		BOARD_WIDTH = 6,
		BOARD_HEIGHT = 7
	};

	bool Odd(int);
	std::string StringOfChars(std::string& dest, std::string value, int length);
	std::string CreateHexLine(std::string str, int length);

	int int_board_array[BOARD_WIDTH][BOARD_HEIGHT];
	HexBoardSpace hex_board_array[BOARD_WIDTH][BOARD_HEIGHT];
	std::vector<Creature> creature_vector;
	std::vector<Player> player_vector;
	std::vector<Terrain> terrain_vector;


public:
	int test_setupClash();
	void test_dumpScreenData();
	void test_dumpScreenDataV2();
};

