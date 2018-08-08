#pragma once

#include"constants.h"

class Board {
	private:
		char	board[BOARD_ROWS][BOARD_COLS];
		char	playedPiece;
		int		playedRow;
		int		playedCol;
		int		playedPositions;

		// Helper functions are private functions
		bool checkHorizontal();
		bool checkVertical();
		bool checkRightDiagonal();
		bool checkHorizontalDraw();
		bool checkVerticalDraw();
		

		// Three approaches:
		// 1. Row-first		(Bibek)
		// 2. Col-first		(Scott)
		// 3. Single-Loop	(Ando)
		bool checkLeftDiagonal1();
		bool checkLeftDiagonal2();
		bool checkLeftDiagonal3();

	public:
		Board();
		~Board();

		//Getters
		char getPosition(int row, int col);
		bool isValid(int row, int col);
		//Setters
		void setPosition(int row, int col, char piece);

		GAME_STATES checkState();		
};

