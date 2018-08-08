#include "view.h"

View::View(Controller& ctrl) : controller(ctrl) {
}

void View::newGame(GAME_TYPES gameType) {
	controller.newGame(gameType);
	play(gameType);
}

void View::play(GAME_TYPES gameType) {
	int	playerMove[2];

	// Display the game board
	if (gameType != GAME_TYPES::AI_VS_AI) {
		displayBoard();
	}
	
	// Play Loop
	while (controller.gameIsInProgress()) {
		if (gameType != GAME_TYPES::AI_VS_AI) {
			// Tell the current Player to play
			getPlayerMove(playerMove);

			// Tell the Controller the current Player's move
			controller.move(playerMove[0], playerMove[1]);
		}
		else {
			controller.move();
		}

		// Display the game board
		displayBoard();

		// Check for a winner or a draw
		GAME_STATES gameStates = controller.getGameState();

		if (gameStates == GAME_STATES::WON ) {
			cout << "Player: " << controller.getWinner() << endl << endl;
		}
		else if (gameStates == GAME_STATES::DRAW) {
			cout << "This Game is a draw!" << endl << endl;
		}
	}
}

void View::displayBoard() {
	cout << endl;

	for (int row = 1; row <= BOARD_ROWS; row++) {
		for (int col = 1; col <= BOARD_COLS - 1; col++) {
			cout << "   |";
		}

		cout << endl;

		for (int col = 1; col <= BOARD_COLS; col++) {
			cout << " " << controller.getBoardPosition(row, col) << " ";

			if (col != BOARD_COLS) {
				cout << "|";
			}
		}

		cout << endl;

		for (int col = 1; col <= BOARD_COLS; col++) {
			cout << "   ";

			if (col != BOARD_COLS) {
				cout << "|";
			}
		}

		cout << endl;

		for (int col = 1; col <= BOARD_COLS; col++) {
			if (row != BOARD_ROWS) {
				cout << "---";
			}

			if (row != BOARD_ROWS && col != BOARD_COLS) {
				cout << "|";
			}
		}

		cout << endl;
	}
}

void View::getPlayerMove(int playerMove[]) {
	bool finished = false;

	while (!finished) {
		// Input the current Player's move (row,col)
		cout << "Player " << controller.getCurrentPlayer() << ", it's your move: " << endl << endl;
		cout << "Enter the Row # (1 to " << BOARD_ROWS << "): ";
		cin >> playerMove[0];
		cout << "Enter the Col # (1 to " << BOARD_COLS << "): ";
		cin >> playerMove[1];


		// Validate the current Player's move:
		// Row and col must be within game board and the position must be unoccupied
		if (controller.isMoveValid(playerMove[0], playerMove[1])) {
			finished = true;
		}
		else {
			cout << endl << "The board position you have chosen is outside the board or already occupied" << endl << endl;
		}
	}
}

void View::menu() {
	int choice			= 0;
	GAME_TYPES gameType	= GAME_TYPES::NONE;

	while (choice != 9) {
		cout << "Tic-Tac-Toe" << endl << endl;
		cout << "1. Player vs. Player" << endl;
		cout << "2. Player vs. AI" << endl;
		cout << "3. AI vs. AI" << endl;
		cout << "9. Exit" << endl << endl;

		cout << "Enter your Menu choice: ";
		cin >> choice;

		cin.clear();
		// Forward slash hangs cin!
		cin.ignore(INT32_MAX, '\n');

		switch (choice) {
			case 1: {
				newGame(GAME_TYPES::HUMAN_VS_HUMAN);
				break;
			}
			case 2: {
				newGame(GAME_TYPES::HUMAN_VS_AI);
				break;
			}
			case 3: {
				newGame(GAME_TYPES::AI_VS_AI);
				break;
			}
			case 9: {
				cout << endl << "Thank you for playing Tic-Tac-Toe!" << endl << endl;
				break;
			}
			default: {
				cout << endl << "Invalid Menu choice." << endl << endl;
				break;
			}
		}
	}
}
