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
		PING,
		HELP,
		START,
		TIME,
		QUIT,
		TEST_DUMPSCREEN,
		DUMPSCREEN,
		ADD_PLAYER_1,
		ADD_PLAYER_2,
		ADD_PLAYER,
		LIST_PLAYERS,
		SETUP_BOARD,
		BOOT_GAME,

		UNKNOWN
	};

	std::map<std::string, COMMANDS> commands_map;

	COMMANDS commandId(std::string command);
	void AddPlayer1(Clash*);
	void AddPlayer2(Clash*);
	void AddPlayer(Clash* myClash);

	void SetupBoard(Clash*);


};

