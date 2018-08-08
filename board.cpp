#include "board.h"

Board::Board() {
	for (int row = 0; row < BOARD_ROWS; row++) {
		for (int cols = 0; cols < BOARD_COLS; cols++ ){
			board[row][cols] = ' ';
		}
	}

	playedPiece = ' ';
	playedRow = 0;
	playedCol = 0;
	playedPositions = 0;
}


Board::~Board() {
}

char Board::getPosition(int row, int cols) {
	return board[row -1][cols -1];
}

void Board::setPosition(int row, int col, char piece){
	board[row -1][col -1]	= piece;
	playedPiece				= piece;
	playedRow				= row;
	playedCol				= col;
	playedPositions++;
}

GAME_STATES Board::checkState(){
	GAME_STATES gameState = GAME_STATES::PLAYING;

	//Check for a win
	if (checkHorizontal() || checkVertical() || checkRightDiagonal() || checkLeftDiagonal3()) {
		gameState = GAME_STATES::WON;
	}
	else if (playedPositions == BOARD_SIZE)
	{
		// board is full// no need to check further
		gameState = GAME_STATES::DRAW;
	}
	//Check for a draw
	else if (checkHorizontalDraw() /*&& checkVerticalDraw()*/) {
		gameState = GAME_STATES::DRAW;
	}

	return gameState;
}

bool Board::isValid(int row, int col)
{
	//check the move is within the board
	bool isVal = false;

	if (row >= 1 && row <= BOARD_ROWS && col >= 1 && col <= BOARD_COLS && board[row - 1][col - 1] == ' ') {
		isVal = true;
	}

	return isVal;
}

bool Board::checkHorizontal() {
	bool	won = false;
	int		myPieces = 0;
			
	for (int col = 1; col <= BOARD_COLS; col++) {
		char position = getPosition(playedRow, col);

		if (position == playedPiece) {
			myPieces++;
		}
		else if (position != ' ') {
			break;
		}
	}

	// Check if current Player won
	if (myPieces == BOARD_COLS) {
		won = true;
	}

	return won;
}

bool Board::checkVertical() {
	bool won = false;
	int myPieces = 0;

	for (int row = 1; row <= BOARD_ROWS; row++) {
		char position = getPosition(row, playedCol);

		if (position == playedPiece) {
			myPieces++;
		}
		else if (position != ' ') {
			break;
		}
	}

	// Check if current Player won
	if (myPieces == BOARD_ROWS) {
		won = true;
	}

	return won;
}

bool Board::checkRightDiagonal() {
	bool won = false;
	int myPieces = 0;

	for (int row = 1; row <= BOARD_ROWS; row++) {
		for (int col = row; col <= row; col++) {
			char position = getPosition(row, col);

			if (position == playedPiece) {
				myPieces++;
			}
			else if (position != ' ') {
				break;
			}
		}

		// Check if current Player won
		if (myPieces == BOARD_COLS) {
			won = true;
			break;
		}
	}

	return won;
}

bool Board::checkLeftDiagonal1() {
	bool won = false;
	int myPieces = 0;

	// Row-first approach
	for (int row = BOARD_ROWS; row >= 1; row--) {
		for (int col = BOARD_ROWS - (row - 1); col <= BOARD_ROWS - (row - 1); col++) {
			char position = getPosition(row, col);

			if (position == playedPiece) {
				myPieces++;
			}
			else if (position != ' ') {
				break;
			}
		}

		// Check if current Player won
		if (myPieces == BOARD_COLS) {
			won = true;
			break;
		}
	}

	return won;
}

bool Board::checkLeftDiagonal2() {
	bool won = false;
	int myPieces = 0;

	// Cols-first approach
	for (int col = BOARD_COLS; col >= 1; col--) {
		for (int row = BOARD_COLS - (col - 1); row <= BOARD_COLS - (col - 1); row++) {
			char position = getPosition(row, col);

			if (position == playedPiece) {
				myPieces++;
			}
			else if (position != ' ') {
				break;
			}
		}

		// Check if current Player won
		if (myPieces == BOARD_COLS) {
			won = true;
			break;
		}
	}

	return won;
}

bool Board::checkLeftDiagonal3() {
	bool won = false;
	int myPieces = 0;
	int row = 1;

	// Cols-first approach
	for (int col = BOARD_COLS; col >= 1; col--) {
		char position = getPosition(row, col);

		if (position == playedPiece) {
			myPieces++;
		}
		else if (position != ' ') {
			break;
		}

		row++;
	}

	// Check if current Player won
	if (myPieces == BOARD_COLS) {
		won = true;
	}

	return won;
}

bool Board::checkHorizontalDraw() {
	bool draw			= false;
	int myPieces		= 0;
	int opponentsPieces	= 0;
	int drawCount		= 0;
	
	if (playedPositions >= BOARD_SIZE - BOARD_ROWS)
	{


		for (int row = 1; row <= BOARD_ROWS; row++) {
			// the inner for loop reps one row full of columns
			for (int col = 1; col <= BOARD_COLS; col++) {
				char position = getPosition(row, col);

				if (position == playedPiece) {
					myPieces++;
				}
				else if (position != ' ') {
					opponentsPieces++;
				}
				
			}

			// Check if game draw
			if (myPieces >= 1 && opponentsPieces >= 1) {
				drawCount++;
			}
			else if (row == 2 && myPieces == 0 && opponentsPieces == 0) {
				draw = true;
				break;
			}
			

			myPieces = 0;
			opponentsPieces = 0;
		}

		if (drawCount == BOARD_ROWS)
		{
			draw = true;
		}
	}
	return draw;
}

bool Board::checkVerticalDraw()
{
	bool draw = false;
	int myPieces = 0;
	int opponentPieces = 0;
	int drawCount = 0;

	if (playedPositions >= BOARD_SIZE - BOARD_COLS)
	{
		for (int cols = 1; cols <= BOARD_COLS; ++cols)
		{
			for (int rows = 1; rows <= BOARD_ROWS; ++rows)
			{
				char position = getPosition(cols, rows);

				if (position == playedPiece)
				{
					myPieces++;
				} 
				else if (position == ' ')
				{
					opponentPieces++;
				}
			}

			if (myPieces >= 1 && opponentPieces >= 1) {
				drawCount++;
			}
			else if (cols == 2 && myPieces == 0 && opponentPieces == 0) {
				
				draw = true;
				break;
			}
			

			myPieces = 0;
			opponentPieces = 0;
		}

		if (drawCount == 3)
		{
			draw = true;
		}
	}

	return draw;
}




