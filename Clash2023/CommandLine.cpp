#include <iostream>
#include <algorithm>
#include <cctype>
#include <ctime>
//#include <vector>

#include "CommandLine.h"


CommandLine::CommandLine() {

    // Insert some values into the map
    commands_map["ping"] = PING;
    commands_map["help"] = HELP;
    commands_map["start"] = START;
    commands_map["s"] = START;
    commands_map["time"] = TIME;
    commands_map["quit"] = QUIT;
    commands_map["exit"] = QUIT;
    commands_map["test_dumpscreen"] = TEST_DUMPSCREEN;
    commands_map["dumpscreen"] = DUMPSCREEN;
    commands_map["ds"] = DUMPSCREEN;
    commands_map["add_player_1"] = ADD_PLAYER_1;
    commands_map["ap1"] = ADD_PLAYER_1;
    commands_map["add_player_2"] = ADD_PLAYER_2;
    commands_map["ap2"] = ADD_PLAYER_2;
    commands_map["add_player"] = ADD_PLAYER;
    commands_map["ap"] = ADD_PLAYER;
    commands_map["list_players"] = LIST_PLAYERS;
    commands_map["lp"] = LIST_PLAYERS;
    commands_map["setup_board"] = SETUP_BOARD;
    commands_map["sb"] = SETUP_BOARD;
    commands_map["boot_game"] = BOOT_GAME;
    commands_map["bg"] = BOOT_GAME;

    commands_map["unknown"] = UNKNOWN;
};

CommandLine::~CommandLine() {
    std::cout << "CommandLine Destructor\n";
    std::cout << "TODO Free all NEWS\n";

}


void CommandLine::start() {
    Clash *myClash = NULL;
    std::string command;

    std::cout << "Starting Command Line\n\n";

    std::cout << "[:] =========================== [:]\n";
    std::cout << "[:]  commands to start a game   [:]\n";
    std::cout << "[:]       s, ap1, ap2, sb       [:]\n";
    std::cout << "[:]  - - - - - - - - - - - - -  [:]\n";
    std::cout << "[:]    bg does all of those     [:]\n";
    std::cout << "[:]  - - - - - - - - - - - - -  [:]\n";
    std::cout << "[:] ds to see the current board [:]\n";
    std::cout << "[:] =========================== [:]\n";


    
    bool run_main_command_loop = true;


    while (run_main_command_loop) {
        struct tm newtime;
        __time64_t long_time;
        char timebuf[26];
        errno_t err;

        std::cout << "\n>:";

        std::cin >> command;

        CommandLine::COMMANDS command_id = commandId(command);

        switch (command_id) {
        case BOOT_GAME:
            if (myClash == NULL) {
                std::cout << "Starting Clash\n";
                myClash = new Clash();
            }
            else {
                std::cout << "ERROR: Already started.\n>:";
            }


            AddPlayer1(myClash);
            AddPlayer2(myClash);
            SetupBoard(myClash);

            break;

        case START:
        {
            if (myClash == NULL) {
                std::cout << "Starting Clash\n";
                myClash = new Clash();
            }
            else {
                std::cout << "ERROR: Already started.\n>:";
            }
            break;
        }

        case TEST_DUMPSCREEN:
            std::cout << "TEST SCREEN DUMP\n\n";
            if (myClash) {
                myClash->test_dumpScreenDataV2();
            }
            else {
                std::cout << "ERROR: Clash not started.\n>:";
            }
            break;

        case DUMPSCREEN:
            std::cout << "SCREEN DUMP\n\n";
            if (myClash) {
                myClash->dumpScreenData();
            }
            else {
                std::cout << "ERROR: Clash not started.\n>:";
            }
            break;

        case ADD_PLAYER_1:
            AddPlayer1(myClash);
            break;

        case ADD_PLAYER_2:
            AddPlayer2(myClash);
            break;

        case ADD_PLAYER:
            AddPlayer(myClash);
            break;

        case PING:
            std::cout << "PONG\n";
            break;

        case HELP:
            std::cout << "\n\n================\n";
            std::cout <<     "= Command list =\n";
            std::cout <<     "================\n";

            for (auto command_iterator = commands_map.begin(); command_iterator != commands_map.end(); command_iterator++)
            {
                std::cout << command_iterator->first    // string (key)
                    << ':'
                    << command_iterator->second   // string's value 
                    << std::endl;
            }

            break;

        case TIME:

            // Get time as 64-bit integer.
            _time64(&long_time);
            // Convert to local time.
            err = _localtime64_s(&newtime, &long_time);
            if (err)
            {
                printf("Invalid argument to asctime_s.");
                exit(1);
            }
            err = asctime_s(timebuf, 26, &newtime);
            if (err)
            {
                printf("Invalid argument to asctime_s.");
                exit(1);
            }
            printf("%.19s\n", timebuf);
            break;

        case QUIT:
            std::cout << "exiting\n";
            run_main_command_loop = false;

            if (myClash != NULL) {
                delete myClash;
            }
            break;

        case LIST_PLAYERS:
            std::cout << "LIST_PLAYERS.\n";

            if (myClash) {
                std::vector<Player>* my_players;
                my_players = myClash->players();

                std::cout << "\n---CURRENT PLAYERS---\n";

                for (Player& e : *my_players) {
                    std::cout << "Player Name:\t" << e.get_name() << "\n";
                    std::cout << "Hit Points:\t" << e.hit_points() << "\n";
                    std::cout << "\n";
                }
                std::cout << "----------\n";
            }
            else {
                std::cout << "ERROR: Clash not started.\n";
            }
            break;

        case SETUP_BOARD:
            SetupBoard(myClash);
            break;

        case UNKNOWN:
            std::cout << "ERROR: Unknown command.\n";
            break;

        }
        
    }


}



void CommandLine::AddPlayer1(Clash* myClash) {
    std::cout << "ADD PLAYER 1\n\n";
    if (myClash) {
        myClash->addPlayer("Andrea", 1);
    }
    else {
        std::cout << "ERROR: Clash not started.\n>:";
    }

}

void CommandLine::AddPlayer2(Clash* myClash) {
    std::cout << "ADD PLAYER 2\n\n";
    if (myClash) {
        myClash->addPlayer("Billy", 2);
    }
    else {
        std::cout << "ERROR: Clash not started.\n>:";
    }
}

void CommandLine::AddPlayer(Clash* myClash) {
    std::cout << "ADD PLAYER\n\n";
    if (myClash) {
        std::vector<Player>* p_player_vec = myClash->players();
        int player_count = (int)p_player_vec->size();
        player_count++;
        std::cout << "Adding player #" << player_count << "\n\n";
        std::cout << "Enter player's name: ";
        std::string name = "no name";
        std::cin >> name;

        std::cout << "\n Adding " << name << " as player #" << player_count << "\n\n";

        myClash->addPlayer(name, player_count);
    }
    else {
        std::cout << "ERROR: Clash not started.\n>:";
    }
}


void CommandLine::SetupBoard(Clash* myClash) {
    std::cout << "Setting up board\n";

    if (myClash) {
        std::cout << "\n---SETTING UP PLAYERS---\n";
        std::vector<Player>* p_myplayers;
        p_myplayers = myClash->players();


        for (Player& e : *p_myplayers) {
            std::cout << "Placing player: " << e.get_name() << " on the board.\n";
            int pn = e.PlayerNumber();

            if (pn == 1) {
                myClash->PlacePlayerOnBoard(2, 1, &e);
            }
            else if (pn == 2) {
                myClash->PlacePlayerOnBoard(2, 5, &e);
            }
            else {

                std::cout << "Warning: Too many players: " << e.get_name() << " will not be placed on the board.\n";
            }

            //todo Place summoning circle for each player
        }
        /*                for (unsigned int i = 0; i < p_myplayers->size(); i++) {

                            std::cout << "Placing player: " << (*p_myplayers)[i].get_name() << " on the board.\n";
                            int pn = (*p_myplayers)[i].PlayerNumber();

                            if (pn == 1) {
                                myClash->PlacePlayerOnBoard(3, 1, (*p_myplayers)[i]);
                            }
                            if (pn == 2) {
                                myClash->PlacePlayerOnBoard(3, 4, (*p_myplayers)[i]);
                            }

                            //todo Place summoning circle for each player


                        }*/
    }
    else {
        std::cout << "ERROR: Clash not started.\n";
    }
}



CommandLine::COMMANDS CommandLine::commandId(std::string command)
{
    COMMANDS retval = UNKNOWN;

    //Convert param to lower case
    std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c) { return std::tolower(c); });

    for (auto command_iterator = commands_map.begin(); command_iterator != commands_map.end(); command_iterator++)
    {

        if (command == command_iterator->first) {
            retval = command_iterator->second;
            break;
        }

    }

    return retval;
}


