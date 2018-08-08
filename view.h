#pragma once

#include "constants.h"
#include "controller.h"
#include <iostream>
#include <string>
using namespace std;

class View {
	private:
		Controller&		controller;
		char			gameBoard[BOARD_ROWS][BOARD_COLS];

		// Helper functions
		void newGame(GAME_TYPES gameType);
		void play(GAME_TYPES gameType);
		void displayBoard();
		void getPlayerMove(int playerMove[]);

	public:
		View(Controller& ctrl);
		
		void menu();
};
