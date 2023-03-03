#include "Clash.h"
#include <format>

Clash::Clash()
{     // Constructor
	std::cout << "Clash Constructor\n";
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
			hex_board_array[x][y].name(dum);

			if (x == 2 && y == 1) {
				// Set Player 1 Wizard Position
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->Set_Terrain(Terrain::PLAYER_1_STARTING_LAND);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].terrain(p_worker_terrain);
			}
			else if (x == 2 && y == 5) {
				// Set Player 2 Wizard Position
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->Set_Terrain(Terrain::PLAYER_2_STARTING_LAND);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].terrain(p_worker_terrain);
			} 
			else if (x == 3 && y == 1) {
				// Set Player 1 Summoning
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->Set_Terrain(Terrain::PLAYER_1_SUMMONING);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].terrain(p_worker_terrain);
			}
			else if (x == 3 && y == 5) {
				// Set Player 2 Summoning
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->Set_Terrain(Terrain::PLAYER_2_SUMMONING);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].terrain(p_worker_terrain);
			} 
			else if (x == 0 && y == 0) {
				// Set Player 1 Mana Source
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->Set_Terrain(Terrain::PLAYER_1_MANA_SOURCE);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].terrain(p_worker_terrain);
			}
			else if (x == 0 && y == 6) {
				// Set Player 2 Mana Source
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->Set_Terrain(Terrain::PLAYER_2_MANA_SOURCE);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].terrain(p_worker_terrain);
			}
			else {
				// Default to Grass
				Terrain* p_worker_terrain = new Terrain();
				p_worker_terrain->Set_Terrain(Terrain::GRASS);
				terrain_vector.push_back(*p_worker_terrain);
				hex_board_array[x][y].terrain(p_worker_terrain);
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
			std::string cell_value = hex_board_array[x][y].name();
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

			Player* p_player_data = hex_board_array[x][y].player();

			if (p_player_data) {
				std::string player_name = p_player_data->Name();
				std::string worker_str = CreateHexLine(player_name, hex_width);
				std::cout << worker_str << standard_spacing;
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
			std::string cell_value = hex_board_array[x][y].name();
			Creature* p_creature_value = hex_board_array[x][y].creature();
			// todo get the rest of the values of the hex and display all the data.  Maybe each value from terrain is on a different line?? 

			if (p_creature_value) {
				//std::string player_name = p_creature_value->get_name();
				std::string player_name = "";
				std::string worker_str = CreateHexLine(player_name, hex_width);
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

			Terrain* p_terrain_data = hex_board_array[x][y].terrain();

			if (p_terrain_data) {
//				Terrain::TERRAIN_TYPE tt = p_terrain_data->Get_Terrain();
				std::string Terrain_name = p_terrain_data->TerrainName();
				std::string worker_str = CreateHexLine(Terrain_name, hex_width);
				std::cout << worker_str << standard_spacing;
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

	retval = (value % 2) == 0;

	return retval;


}

void Clash::AddPlayer(std::string name, int player_number)
{
	// TODO: Add your implementation code here.
	Player* current_player = new Player;
	current_player->Name(name);
	current_player->PlayerNumber(player_number);
	player_vector.push_back(*current_player);
}

std::vector<Player>* Clash::Players() {
	return &player_vector;
}

void Clash::PlacePlayerOnBoard(int x, int y, Player* target_player) {

	hex_board_array[x][y].player(target_player);

}