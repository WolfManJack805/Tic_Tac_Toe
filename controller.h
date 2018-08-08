#pragma once

#include "constants.h"
#include "player.h"
#include "humanplayer.h"
#include "aiplayer.h"
#include "score.h"
#include "board.h"
#include <map>
#include <string>

class Controller {
	private:
		Board* board;
		//Automatic array of Player pointers
		Player* players[MAX_PLAYERS];
		// Map: key (must be unique), value
		std::map<std::string, Score>	scores;
		int currentPlayer;
		GAME_STATES gameState;
		int winner;

		//Helper functions
		void nextPlayer();

	public:
		Controller();
		~Controller();

		//GETTERS
		GAME_STATES getGameState();
		int getWinner();
		char getBoardPosition(int row, int col);
		int getCurrentPlayer();

		bool isMoveValid(int row, int col);
		bool gameIsInProgress();
		void newGame(GAME_TYPES gameType);
		void move(int row, int col);
		void move();
		
};

