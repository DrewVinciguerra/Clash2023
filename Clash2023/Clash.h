#pragma once
#include <iostream>
#include <map>
#include <set>
#include <list>

#include "Creature.h"
#include "Player.h"
#include "HexBoardSpace.h"
#include "Terrain.h"
#include "ColorText.h"

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
	void PlayCreature(std::string name, int attack, int health, int player_id);
	void NextTurn();
	void DebugTest();
	void MoveCreature(Creature& c, std::vector<std::pair<int, int>> path_vector);



private:
	enum BOARD
	{
		BOARD_WIDTH = 6,
		BOARD_HEIGHT = 7
	};

	enum TRAVEL_DIRECTION
	{
		NE,
		E,
		SE,
		SW,
		W,
		NW,
	};

	std::map<TRAVEL_DIRECTION, std::pair<int, int>> even_row;
	std::map<TRAVEL_DIRECTION, std::pair<int, int>> odd_row;

	bool Odd(int);
	std::string StringOfChars(std::string& dest, std::string value, int length);
	std::string CreateHexLine(std::string str, int length);
	void PlayerColorPrint(int player_id, std::string text);
	void GeneratePath(Creature& pCreature, std::vector<std::pair<int, int>> current_path);

	//DEBUG STUFF
	void TestGeneratePath(int value, std::vector<std::pair<int, int>>& current_path);
	void Test2GeneratePath(int value, std::list<int> current_path);

	HexBoardSpace* Travel(std::pair<int, int> current_location, Creature& creature, TRAVEL_DIRECTION direction, bool& found_target);

	int int_board_array[BOARD_WIDTH][BOARD_HEIGHT];
	HexBoardSpace hex_board_array[BOARD_WIDTH][BOARD_HEIGHT];
 	std::vector<Player> player_vector;
	std::vector<Terrain> terrain_vector;
	ColorText color_text;

	// Path finding vars
	bool first_path;
	std::vector<std::pair<int, int>> best_path_vector;

	void AddPairs(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int>& new_location);
	void SubtractPairs(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int>& new_location);
	void PrintMiniMap(std::vector<std::pair<int, int>>& current_path);
	Player* IsCreaturesTargetNear(std::pair<int, int> current_location, Creature& creature);


public:
	int test_setupClash();
	void test_dumpScreenData();
	void test_dumpScreenDataV2();
	int debug_interation_counter;
};

