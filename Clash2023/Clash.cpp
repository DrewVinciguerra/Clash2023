#include "Clash.h"
#include <format>
#include <iostream>
#include <map>
#include <string>
#include <iterator>

Clash::Clash()
{     // Constructor

	// direction helpers
	
	even_row[TRAVEL_DIRECTION::NE] = std::make_pair(0, -1);
	even_row[TRAVEL_DIRECTION::E] = std::make_pair(1, 0);
	even_row[TRAVEL_DIRECTION::SE] = std::make_pair(0, 1);
	even_row[TRAVEL_DIRECTION::SW] = std::make_pair(-1, 1);
	even_row[TRAVEL_DIRECTION::W] = std::make_pair(-1, 0);
	even_row[TRAVEL_DIRECTION::NW] = std::make_pair(-1, -1);

	odd_row[TRAVEL_DIRECTION::NE] = std::make_pair(1, -1);
	odd_row[TRAVEL_DIRECTION::E] = std::make_pair(1, 0);
	odd_row[TRAVEL_DIRECTION::SE] = std::make_pair(1, 1);
	odd_row[TRAVEL_DIRECTION::SW] = std::make_pair(0, 1);
	odd_row[TRAVEL_DIRECTION::W] = std::make_pair(-1, 0);
	odd_row[TRAVEL_DIRECTION::NW] = std::make_pair(0, -1);

	test_setupClash();
	SetupClash();

}

Clash::~Clash() {

	std::cout << "Clash Destructor\n";
	std::cout << "TODO Free all Vector members\n";
}


int Clash::SetupClash()
{
	int count = 0;

	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::string dum = std::format("{}-{}", x, y);
			hex_board_array[x][y].Name(dum);
			hex_board_array[x][y].LocationX(x);
			hex_board_array[x][y].LocationY(y);

			if (x == 2 && y == 1) {
				// Set Player 1 Wizard Position
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->TerrainData(Terrain::PLAYER_1_STARTING_LAND);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].TerrainData(p_worker_terrain);
			}
			else if (x == 2 && y == 5) {
				// Set Player 2 Wizard Position
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->TerrainData(Terrain::PLAYER_2_STARTING_LAND);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].TerrainData(p_worker_terrain);
			} 

			else {
				// Default to Grass
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->TerrainData(Terrain::GRASS);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].TerrainData(p_worker_terrain);
			}

		}

	}

	return 0;
}

int Clash::test_setupClash()
{
	int count = 0;

	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			int_board_array[x][y] = count++;
		}

	}

    return 0;
}


void Clash::DumpScreenData() {

	int hex_width = 13;
	std::string worker_str = "";
	StringOfChars(worker_str, "-", hex_width);
	std::string indent_spacing = "";
	StringOfChars(indent_spacing, " ", 9);
	std::string standard_spacing = "";
	StringOfChars(standard_spacing, " ", 3);

	std::cout << ".-==Dump Screen==-.\n\n";


	for (int y = 0; y < BOARD_HEIGHT; y++) {

		// ======================= TOP BORDER ============================
		std::cout << "\n";
		if (Odd(y)) {
			std::cout << indent_spacing;
		}

		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::cout << "/" << worker_str << "\\" << standard_spacing;
		}
		// ================================================================

		//======================= LINE 1. Hex coords =======================
		std::cout << "\n";
		if (Odd(y)) {
			std::cout << indent_spacing;
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			//std::cout << "|             |" << standard_spacing;
			std::string cell_value = hex_board_array[x][y].Name();
			int length = (int)cell_value.length();

			int pre_pad_length = 1;

			std::string pre_pad_str;
			StringOfChars(pre_pad_str, " ", pre_pad_length);
			std::string post_pad_str;

			int post_pad_length = hex_width - (length + 1);
			StringOfChars(post_pad_str, " ", post_pad_length);

			std::cout << "|" << pre_pad_str << cell_value << post_pad_str << "|" << standard_spacing;

		}
		// ================================================================

		// =======================  LINE 2.  Player Info =======================
		std::cout << "\n";
		if (Odd(y)) {
			std::cout << indent_spacing;
		}

		for (int x = 0; x < BOARD_WIDTH; x++) {

			Player* p_player_data = hex_board_array[x][y].PlayerData();

			if (p_player_data) {
				std::string player_name = p_player_data->Name();
				std::string worker_str = CreateHexLine(player_name, hex_width);
				PlayerColorPrint(p_player_data->Id(), worker_str);
				std::cout << standard_spacing;
//				std::cout << worker_str << standard_spacing;
			}
			else {
				std::string worker_str = CreateHexLine("", hex_width);
				std::cout << worker_str << standard_spacing;
			}

		}
		// ================================================================

		// =======================  LINE 3. CREATURES =======================
		std::cout << "\n";
		if (Odd(y)) {
			std::cout << indent_spacing;
		}

		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::string cell_value = hex_board_array[x][y].Name();
			Creature* p_creature_value = hex_board_array[x][y].CreatureData();
			// todo get the rest of the values of the hex and display all the data.  Maybe each value from terrain is on a different line?? 

			if (p_creature_value) {
				std::string creature_name = p_creature_value->Name();
				std::string worker_str = CreateHexLine(creature_name, hex_width);
				std::cout << worker_str << standard_spacing;
			}
			else {
				std::string worker_str = CreateHexLine("", hex_width);
				std::cout << worker_str << standard_spacing;
			}

		}
		// ================================================================


		// =======================  LINE 4. TERRAIN =======================

		std::cout << "\n";
		if (Odd(y)) {
			std::cout << indent_spacing;
		}

		for (int x = 0; x < BOARD_WIDTH; x++) {

			Terrain* p_terrain_data = hex_board_array[x][y].TerrainData();

			if (p_terrain_data) {
				Terrain::TERRAIN_TYPE ttype = p_terrain_data->TerrainData();
				std::string Terrain_name = p_terrain_data->TerrainName();
				std::string worker_str = CreateHexLine(Terrain_name, hex_width);
				int player_id = 0;

				switch (ttype)	{
				case Terrain::PLAYER_1_STARTING_LAND:
				case Terrain::PLAYER_1_SUMMONING:
				case Terrain::PLAYER_1_MANA_SOURCE:
					player_id = 1;
					break;
				case Terrain::PLAYER_2_STARTING_LAND:
				case Terrain::PLAYER_2_SUMMONING:
				case Terrain::PLAYER_2_MANA_SOURCE:
					player_id = 2;
					break;
				case Terrain::PAVED:
				case Terrain::MOUNTAIN:
				case Terrain::WATER:
				case Terrain::MUD:
				case Terrain::LAVA:
				case Terrain::GRASS:
				case Terrain::DESERT:
				case Terrain::SWAMP:
				case Terrain::EMPTY:
				case Terrain::TUNNEL:
					player_id = 0;
					break;
				default:
					player_id = 0;
					break;
				}

				PlayerColorPrint(player_id, worker_str);
				std::cout << standard_spacing;
				//std::cout << worker_str << standard_spacing;
			}
			else {
				std::string worker_str = CreateHexLine("", hex_width);
				std::cout << worker_str << standard_spacing;
			}
		}
//		for (int x = 0; x < BOARD_WIDTH; x++) {
//			std::cout << "|             |" << standard_spacing;
//		}
		// ================================================================


		// ================================= BOTTOM BORDER =================================
		std::cout << "\n";
		if (Odd(y)) {
			std::cout << indent_spacing;
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::cout << "\\" << worker_str << "/" << standard_spacing;
		}


		std::cout << "\n";
	}

}

void Clash::PlayerColorPrint(int player_id, std::string text) {
	ColorText::ColorCode player_1_color = ColorText::ColorCode::FG_YELLOW;
	ColorText::ColorCode player_2_color = ColorText::ColorCode::FG_GREEN;
	ColorText::ColorCode default_color = ColorText::ColorCode::FG_WHITE;

	if (player_id == 0) {
		color_text.PrintToScreen(text, default_color, 1);
	}
	if (player_id == 1) {
		color_text.PrintToScreen(text, player_1_color, 1);
	}
	if (player_id == 2) {
		color_text.PrintToScreen(text, player_2_color, 1);
	}
}


std::string Clash::CreateHexLine(std::string centered_str, int total_length) {
	std::string retval = "";

	int str_length = (int)centered_str.length();
	int needed_padding = total_length - str_length;
	int pre_pad_length = needed_padding / 2;
	int post_pad_length = pre_pad_length;
	if (needed_padding % 2) {
		post_pad_length++;
	}



	std::string pre_pad_str;
	StringOfChars(pre_pad_str, " ", pre_pad_length);
	std::string post_pad_str;
	StringOfChars(post_pad_str, " ", post_pad_length);
	/*			if (cell_value < 10) {
		pad_str = "0";
	};
*/

	retval =  "|" + pre_pad_str + centered_str + post_pad_str + "|";

	return retval;


}

std::string Clash::StringOfChars(std::string &dest, std::string value, int length) {

	for (int i = 0; i < length; i++) {
		dest += value;
	}

	return dest;
}

void Clash::test_dumpScreenData() {

	for (int y = 0; y < BOARD_HEIGHT; y++) {

		if (Odd(y)) {
			//odd
			std::cout << "\t";
		}
		else {
			//even
		}

		for (int x = 0; x < BOARD_WIDTH; x++) {


			std::cout << "[" << int_board_array[x][y] << "]\t\t";
		}

		std::cout << "\n";
	}
};

void Clash::test_dumpScreenDataV2() {

	for (int y = 0; y < BOARD_HEIGHT; y++) {

		std::cout << "\n";
		if (Odd(y)) {
			//odd
			std::cout << "\t";
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::cout << "/--------\\ \t";
		}

		std::cout << "\n";
		if (Odd(y)) {
			//odd
			std::cout << "\t";
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::cout << "|        | \t";
		}

		std::cout << "\n";
		if (Odd(y)) {
			//odd
			std::cout << "\t";
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			int cell_value = int_board_array[x][y];
			std::string pad_str = "";
			if (cell_value < 10) {
				pad_str = "0";
			};
			

			std::cout << "|  [" << pad_str << int_board_array[x][y] << "]  |  \t";
		}

		std::cout << "\n";
		if (Odd(y)) {
			//odd
			std::cout << "\t";
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::cout << "|        | \t";
		}

		std::cout << "\n";
		if (Odd(y)) {
			//odd
			std::cout << "\t";
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::cout << "\\--------/ \t";
		}


		std::cout << "\n";
	}
};



bool Clash::Odd(int value) {
	bool retval = false;

	retval = ((value % 2) == 1);

	return retval;


}

void Clash::AddPlayer(std::string name, int player_id)
{
	int x = 0;
	int y = 0;

	// TODO: Make sure the ID hasn't already been used.
	Player* current_player = new Player;
	current_player->Name(name);
	current_player->Id(player_id);

	if (player_id == 1) {
		// Set Player 1 Summoning
		x = 3;
		y = 1;
		Terrain* p_worker_terrain = new Terrain();
		p_worker_terrain->TerrainData(Terrain::PLAYER_1_SUMMONING);
		terrain_vector.push_back(*p_worker_terrain);
		hex_board_array[x][y].TerrainData(p_worker_terrain);

		current_player->SummoningLocation(x, y);
		player_vector.push_back(*current_player);

		// Set Player 1 Mana Source
		x = 0;
		y = 0;
		p_worker_terrain = new Terrain();
		p_worker_terrain->TerrainData(Terrain::PLAYER_1_MANA_SOURCE);
		terrain_vector.push_back(*p_worker_terrain);
		hex_board_array[x][y].TerrainData(p_worker_terrain);

	}
	if (player_id == 2) {
		// Set Player 1 Summoning
		x = 3;
		y = 5;
		Terrain* p_worker_terrain = new Terrain();
		p_worker_terrain->TerrainData(Terrain::PLAYER_2_SUMMONING);
		terrain_vector.push_back(*p_worker_terrain);
		hex_board_array[x][y].TerrainData(p_worker_terrain);

		current_player->SummoningLocation(x, y);
		player_vector.push_back(*current_player);

		// Set Player 2 Mana Source
		x = 0;
		y = 6;
		p_worker_terrain = new Terrain();
		p_worker_terrain->TerrainData(Terrain::PLAYER_2_MANA_SOURCE);
		terrain_vector.push_back(*p_worker_terrain);
		hex_board_array[x][y].TerrainData(p_worker_terrain);

	}

}


/*/*			else if (x == 3 && y == 1) {
				// Set Player 1 Summoning
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->TerrainData(Terrain::PLAYER_1_SUMMONING);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].TerrainData(p_worker_terrain);
			}
			else if (x == 3 && y == 5) {
				// Set Player 2 Summoning
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->TerrainData(Terrain::PLAYER_2_SUMMONING);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].TerrainData(p_worker_terrain);
			} */


/*			else if (x == 0 && y == 0) {	// ADD THIS CODE TO ADD PLAYER INSTEAD
				// Set Player 1 Mana Source
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->TerrainData(Terrain::PLAYER_1_MANA_SOURCE);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].TerrainData(p_worker_terrain);
			}
			else if (x == 0 && y == 6) {
				// Set Player 2 Mana Source
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->TerrainData(Terrain::PLAYER_2_MANA_SOURCE);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].TerrainData(p_worker_terrain);
			}*/



std::vector<Player>* Clash::Players() {
	return &player_vector;
}

void Clash::PlacePlayerOnBoard(int x, int y, Player* target_player) {

	hex_board_array[x][y].PlayerData(target_player);

}


void Clash::PlayCreature(std::string name, int attack, int health, int player_id) {

	std::vector<Player>* my_players;
	my_players = Players();
	Player* p_player = NULL;

//	std::cout << "\n---Who is summoning this creature?---\n";

	for (Player& e : *my_players) {
		if (e.Id() == player_id) {
			p_player = &e;
			break;
		}
	}

	if (p_player) {
		std::cout << "Player: " << p_player->Name() << " is summoning: " << name <<  "\n";
		std::cout << "----------\n";

		int attack_range_close = 1;
		int attack_range_far = 1;
		int movement = 1;
		int player_target_id = 2;

		std::pair<int, int> summoning_pair = p_player->SummoningLocation();

		int x = summoning_pair.first;
		int y = summoning_pair.second;
		Creature* p_creature = new Creature(name, health, attack_range_close, attack_range_far, movement, player_id, player_target_id, x, y);

		std::vector<Creature>* p_creature_vector = p_player->CreatureVector();

		p_creature_vector->push_back(*p_creature);
		hex_board_array[x][y].CreatureData(p_creature);



	}
	else {
		std::cout << "ERROR:  Couldn't find player.\n";
	}
}

void Clash::NextTurn() {
	// This function loops through each player and moves it's creatures.

	std::cout << "\n\n===========================\n";

	std::cout << "Starting Next Turn\n \n";

	debug_interation_counter = 0;
	std::vector<Player>* my_players;
	my_players = Players();
	Player* p_player = NULL;
	first_path = true;
	best_path_vector.clear();


	for (Player& p : *my_players) {
		std::cout << "Processing Player: " << p.Name() << "\n";

		std::vector<Creature>* current_creature_vector = p.CreatureVector();


		for (Creature& c : *current_creature_vector) {
			std::cout << "Processing Creature: " << c.Name() << "\n";
			best_path_vector.clear();
			first_path = true;
			std::vector<std::pair<int, int>> path_vector;
			std::pair<int, int> current_location = { c.X(), c.Y() };
			path_vector.push_back(current_location);
			GeneratePath(c, path_vector);

			std::cout << "This is the best path for the current Creature: " << c.Name() << "\n";
			PrintMiniMap(best_path_vector);

			//Move creature along path

			if (best_path_vector.size() > 1) {
				MoveCreature(c, best_path_vector);
			}

			//Look for targets to attack
			std::vector<std::pair<int, int>> attack_targets;
			CurrentAttackTargets(c, attack_targets);
		}
	}


	std::cout << "\nNext Turn is complete. \n";
	std::cout << "=========================== \n\n";

}

void Clash::CurrentAttackTargets(Creature& c, std::vector<std::pair<int, int>> attack_targets) {
}


void Clash::MoveCreature(Creature &c, std::vector<std::pair<int, int>> path_vector) {
	std::cout << "\nMoving Creature. \n";

	// Remove creature from current hex
	hex_board_array[c.X()][c.Y()].CreatureData(NULL);

	// Add it to the new hex

	// Find how far along the path this creature moves. Make sure the movement isn't greater than the path length.
	int path_index = -1;
	if (c.Movement() > path_vector.size()) {
		path_index = (int)path_vector.size();
	}
	else {
		path_index = c.Movement();
	}

	int new_x = path_vector[path_index].first;
	int new_y = path_vector[path_index].second;
	c.X(new_x);
	c.Y(new_y);
	hex_board_array[new_x][new_y].CreatureData(&c);


}

void Clash::DebugTest() {
	std::cout << "\nRunning Debug Test. \n";

//	std::vector<std::pair<int, int>> current_path;
//	first_path = false;
//	TestGeneratePath(6, current_path);

	std::list<int> current_path = {};
	first_path = false;
	Test2GeneratePath(6, current_path);


}

void Clash::Test2GeneratePath(int value, std::list<int>current_path) {


	//PrintMiniMap(current_path);

	for (int td = 0; td < 3; td++) {

		if (current_path.size() > 6) {
			first_path = true;
		}

		if (first_path) {
			break;
		}
		else {
			//ADD THIS X Y TO PATH VECTOR
			int v = td;
			current_path.push_back(v);
			std::cout << "pushing location on to vector. size: " << current_path.size() << "\n";
			Test2GeneratePath(6, current_path);
			std::cout << "GeneratePath returned. size: " << current_path.size() << "\n";

		}


	}

	// We hit a dead end.
//	std::cout << "Pre pop size: " << current_path.size() << "\n";
//	current_path.pop_back();
//	std::cout << "popping location off of current path.  New size: " << current_path.size() << "\n";

}

void Clash::TestGeneratePath(int value, std::vector<std::pair<int, int>>& current_path) {


	//PrintMiniMap(current_path);

	for (int td = 0; td < 6; td++) {


		//ADD THIS X Y TO PATH VECTOR
		current_path.push_back(std::pair<int,int>{td, td});
		std::cout << "pushing location on to vector. size: " << current_path.size() << "\n";

		if (current_path.size() > 6) {
			first_path = true;
		}

		if (first_path) {
			break;
		}

		TestGeneratePath(6, current_path);
		std::cout << "GeneratePath returned. size: " << current_path.size() << "\n";

	}

	// We hit a dead end.
	std::cout << "Pre pop size: " << current_path.size() << "\n";
	current_path.pop_back();
	std::cout << "popping location off of current path.  New size: " << current_path.size() << "\n";

}


void Clash::GeneratePath(Creature& creature, std::vector<std::pair<int, int>> current_path) {
	//Try to travel in each direction
	HexBoardSpace* p_hex = NULL;
	bool found_target = false;


	std::pair<int, int> current_location = current_path.back();


	// Did we find our target?  If so, we are with this path.
	Player* p_player = IsCreaturesTargetNear(current_location, creature);	//TODO Don't return player object because the target could be something else.
	if (p_player) {
		//PrintMiniMap(current_path);

		std::cout << "We found the creature's target player\n";
		if (first_path) {
			std::cout << "Setting the best path for the first time\n";
			first_path = false;
			best_path_vector = current_path;
		}
		else {
			std::cout << "Found a new path.  Is it better?\n";
			int best_path_size = (int)best_path_vector.size();
			int current_path_size = (int)current_path.size();
			std::cout << "Best path size: " << best_path_size << "\n";
			std::cout << "Current path size: " << current_path_size << "\n";
			if (current_path_size < best_path_size) {
				std::cout << "We found a better path!\n";
				best_path_vector = current_path;
			}

		}
		return;	//Break out of for loop.  We are done.
	}



	//std::cout << "GeneratePath: Current Location " << current_location.first << ", " << current_location.second << "\n";

	//PrintMiniMap(current_path);

	for (int td = NE; td <= NW; td++) {
		TRAVEL_DIRECTION my_travel_direction = static_cast<TRAVEL_DIRECTION>(td);

		/*		if (current_location == std::pair<int, int>{4, 0})
				{
					std::cout << "HERE";
				}*/
				/*	if (current_location == std::pair<int, int>{4, 1})
						{
							std::cout << "HERE";
						}*/

		p_hex = Travel(current_location, creature, my_travel_direction, found_target);
		if (p_hex) {
			// We found a valid space to move into but we need to make sure we are not back tracking over the way we just came.
			std::pair<int, int> test_location{ p_hex->LocationX(), p_hex->LocationY() };
			if (std::find(current_path.begin(), current_path.end(), test_location) == current_path.end()) {
				// Didn't find the item
				std::pair<int, int> new_location{ p_hex->LocationX(), p_hex->LocationY() };

				//ADD THIS X Y TO PATH VECTOR
				current_path.push_back(new_location);
				current_location = current_path.back();

				//std::cout << "pushing location on to vector. size: " << current_path.size() << "\n";
				//PrintMiniMap(current_path);

				//If this current path is already longer than our best path, bail.
				if (first_path == false && (current_path.size() >= best_path_vector.size())) {
					return;
				}

				debug_interation_counter++;
				if (debug_interation_counter == 8) { 
					int i = 5; 
				}

				GeneratePath(creature, current_path);
				//std::cout << "Pre pop size: " << current_path.size() << "\n";
				current_path.pop_back();
				current_location = current_path.back();

				//std::cout << "popping location off of current path.  New size: " << current_path.size() << "\n";
				//PrintMiniMap(current_path);
				//std::cout << ".\n";

			}
			else {
				//This hex is already in the list.  .
				//return;
			}
		}
		
	}

	// We hit a dead end.
//	std::cout << "Pre pop size: " << current_path.size() << "\n";
//	current_path.pop_back();
//	std::cout << "popping location off of current path.  New size: " << current_path.size() << "\n";

	return;


}



HexBoardSpace* Clash::Travel(std::pair<int, int> current_location, Creature& creature, TRAVEL_DIRECTION direction, bool& found_target) {
	// Returns a valid HexBoardSpace if the move is valid.  Otherwise HexBoardSpace is NULL.

	HexBoardSpace* p_hex = NULL;
	Player* p_player = NULL;
	found_target = false;

	std::pair<int, int> new_location(-5,-5);	// Init to weird value

	if (Odd(current_location.second)) {
		AddPairs(current_location, odd_row[direction], new_location);
		//std::cout << new_location.first;
	}
	else {
		AddPairs(current_location, even_row[direction], new_location);
		//std::cout << new_location.first;
	}

	// Is this new location within the boards boundries?
	if ((new_location.first >= 0 && new_location.first < BOARD::BOARD_WIDTH) &&
		(new_location.second >= 0 && new_location.second < BOARD::BOARD_HEIGHT)) {
		p_hex = &hex_board_array[new_location.first][new_location.second];
		
		p_player = IsCreaturesTargetNear(current_location, creature);

		// What is on this hex space?
		Creature* p_creature = p_hex->CreatureData();	
		//Player* p_player = p_hex->PlayerData();
		Terrain* p_terrain = p_hex->TerrainData();

//		if (p_creature) {
//			std::cout << "=============== There is a Creature here: " << p_creature->Name() << "\n";
//		}

		if (p_player) {
			// Did we find the creatures target?
			if (creature.PlayerTargetId() == p_player->Id()) {
				//std::cout << "=============== Creature found the target player\n";
				found_target = true;
			}
		}

		// Can't move into this space if it's already occupied. 
		if (p_creature || p_player) {
			p_hex = NULL;
		}

	}

	return p_hex;

}


Player* Clash::IsCreaturesTargetNear(std::pair<int, int> current_location, Creature& creature) {
	// Check all the surrounding spaces to see if the creatures target is next to the creature

	HexBoardSpace* p_hex = NULL;
	Player* p_player = NULL;


	for (int td = NE; td <= NW; td++) {
		TRAVEL_DIRECTION my_travel_direction = static_cast<TRAVEL_DIRECTION>(td);
		std::pair<int, int> new_location(-5, -5);	// Init to weird value

		if (Odd(current_location.second)) {
			AddPairs(current_location, odd_row[my_travel_direction], new_location);
			//std::cout << new_location.first;
		}
		else {
			AddPairs(current_location, even_row[my_travel_direction], new_location);
			//std::cout << new_location.first;
		}

		// Is this new location within the boards boundries?
		if ((new_location.first >= 0 && new_location.first < BOARD::BOARD_WIDTH) &&
			(new_location.second >= 0 && new_location.second < BOARD::BOARD_HEIGHT)) {
			p_hex = &hex_board_array[new_location.first][new_location.second];

			// What is on this hex space?
			Creature* p_creature = p_hex->CreatureData();
			p_player = p_hex->PlayerData();
			Terrain* p_terrain = p_hex->TerrainData();

			if (p_player) {
				// Did we find the creatures target?
				if (creature.PlayerTargetId() == p_player->Id()) {
					std::cout << "=============== Creature found the target player, " << p_player->Name() << ", in an adjoining hex\n";
					std::cout << "=============== Creature Player Target ID = " << creature.PlayerTargetId() << " And the found player ID = " << p_player->Id() << "\n";
					//found_target = true;
					return p_player;
				}
				else {
					// We found the wrong player
					p_player = NULL;
				}
			}

		}

	}

	return p_player;
}

void Clash::AddPairs(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int>& new_location) {
	new_location.first = p1.first + p2.first;
	new_location.second = p1.second + p2.second;
}

void Clash::SubtractPairs(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int>& new_location) {
	new_location.first = p1.first - p2.first;
	new_location.second = p1.second - p2.second;
}


void Clash::PrintMiniMap(std::vector<std::pair<int, int>>& current_path) {
	int hex_width = 13;
	std::string worker_str = "";
	StringOfChars(worker_str, "-", hex_width);
	std::string indent_spacing = "";
	StringOfChars(indent_spacing, " ", 4);
	std::string standard_spacing = "";
	StringOfChars(standard_spacing, " ", 3);

	std::cout << ".-==Dump Mini Screen==-.\n\n";



	for (int y = 0; y < BOARD_HEIGHT; y++) {

		std::cout << "\n";
		if (Odd(y)) {
			std::cout << indent_spacing;
		}

		for (int x = 0; x < BOARD_WIDTH; x++) {
			std::string player_marker = ".";
			std::string creature_marker = ".";
			std::string path_marker = ".";

			Player* p_player_data = hex_board_array[x][y].PlayerData();
			if (p_player_data) {
				player_marker = "p";
			}
			Creature* p_creature_value = hex_board_array[x][y].CreatureData();
			if (p_creature_value) {
				creature_marker = "c";
			}
			
			// Is this space on the current path?
			std::pair<int, int> test_location{ x, y };
			std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<int, int>>>> item_found = std::find(current_path.begin(), current_path.end(), test_location);
			int index = item_found - current_path.begin();
			if (std::find(current_path.begin(), current_path.end(), test_location) != current_path.end()) {
				
				// find the item
				path_marker = "*";
				std::string s = std::to_string(index);
				path_marker = s;
			}




			//			std::cout << "[...]" << standard_spacing;
			std::cout << "[" << player_marker << creature_marker << path_marker << "]" << standard_spacing;
		}
		// ================================================================


		std::cout << "\n";
	}

	std::cout << "Mini Map End\n\n";

}

