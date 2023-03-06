#pragma once
#include <map>
#include "Clash.h"

class CommandLine
{
public:
	void start();
	CommandLine();
	~CommandLine();

private:
	enum COMMANDS
	{
		// MISC COMMANDS
		PING,
		TIME,
		TEST_DUMPSCREEN,

		// UTILS
		QUIT,
		HELP,

		// STARTING GAME ENGINE AND GAME SETUP
		START,
		ADD_PLAYER_1,
		ADD_PLAYER_2,
		ADD_PLAYER,
		LIST_PLAYERS,
		SETUP_BOARD,
		BOOT_GAME,

		// GAME PLAY COMMANDS
		DUMPSCREEN,

		// IMPLIMENT THESE COMMANDS
		END_TURN_PLAYER_1,
		END_TURN_PLAYER_2,
		NEXT_TURN,
		PLAY_CREATURE,
		GENERATE_RANDOM_CREATURE,
		GAME_STATUS,	// What state is the game in?  Waiting on which players?  Turn count. etc.
		PLAYER_INFO,	// All player info.  Hit points, deck, discard, etc.

		UNKNOWN
	};

	std::map<std::string, COMMANDS> commands_map;

	COMMANDS commandId(std::string command);
	void AddPlayer1(Clash*);
	void AddPlayer2(Clash*);
	void AddPlayer(Clash* myClash);

	void SetupBoard(Clash*);

	void PlayCreature(Clash* myClash);



};

