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

	int setupClash();
	int test_setupClash();
	void test_dumpScreenData();
	void test_dumpScreenDataV2();
	void dumpScreenData();
	std::vector<Player>* players();
	void PlacePlayerOnBoard(int x, int y, Player* target_player);

private:
	enum BOARD
	{
		BOARD_WIDTH = 6,
		BOARD_HEIGHT = 7
	};


	int int_board_array[BOARD_WIDTH][BOARD_HEIGHT];
	HexBoardSpace hex_board_array[BOARD_WIDTH][BOARD_HEIGHT];
	bool odd(int);
	std::string string_of_chars(std::string& dest, std::string value, int length);
	std::string createHexLine(std::string str, int length);

	std::vector<Creature> creature_vector;
	std::vector<Player> player_vector;
	std::vector<Terrain> terrain_vector;


public:
	void addPlayer(std::string name, int player_number);
};

