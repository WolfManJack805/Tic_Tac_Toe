#include "controller.h"

Controller::Controller() {
	board = nullptr;

	for (int index = 0; index < MAX_PLAYERS; index++) {
		players[index] = nullptr;
	}

	currentPlayer = 0;
	gameState = GAME_STATES::STANDBY;
}

Controller::~Controller() {
	// Delete the old Board
	if (board != nullptr) {
		delete board;
	}

	// Delete the old Players
	for (int index = 0; index < MAX_PLAYERS; index++) {
		if (players[index] != nullptr) {
			delete players[index];
		}
	}
}

void Controller::newGame(GAME_TYPES gameType) {
	// Delete the old Board
	if (board != nullptr) {
		delete board;
	}

	// Create the new Board
	board = new Board();

	// check for proper board//(odd number squared board)
	if (BOARD_SIZE % 2 == 0)
	{
		std::string message = "CONTROLLER::NEW GAME(): board must be an odd size square to play.";
		throw std::exception(message.c_str());
	}

	// Delete the old Players
	for (int index = 0; index < MAX_PLAYERS; index++) {
		if (players[index] != nullptr) {
			delete players[index];
		}
	}

	// Create the new Players
	for (int index = 0; index < MAX_PLAYERS; index++) {
		switch (gameType) {
		case GAME_TYPES::HUMAN_VS_HUMAN: {
			HumanPlayer* humanPlayer = new HumanPlayer(index + 1, PLAYER_TYPES::HUMAN, PLAYER_PIECES[index]);
			players[index] = humanPlayer;
			break;
		}
		case GAME_TYPES::HUMAN_VS_AI: {
			if (index == 0) {
				HumanPlayer* humanPlayer = new HumanPlayer(index + 1, PLAYER_TYPES::HUMAN, PLAYER_PIECES[index]);
				players[index] = humanPlayer;
			}
			else {
				AIPlayer* aiPlayer = new AIPlayer(index + 1, PLAYER_TYPES::AI, PLAYER_PIECES[index], board);
				players[index] = aiPlayer;
			}
			break;
		}
		case GAME_TYPES::AI_VS_AI: {
			AIPlayer* aiPlayer = new AIPlayer(index + 1, PLAYER_TYPES::AI, PLAYER_PIECES[index], board);
			players[index] = aiPlayer;
			break;
		}
		}
	}

	currentPlayer = 1;
	gameState = GAME_STATES::PLAYING;
	winner = 0;
}

void Controller::move(int row, int col) {
	board->setPosition(row, col, players[currentPlayer - 1]->getPiece());

	// Check the game status
	gameState = board->checkState();

	// If game not over, give next Player a turn
	if (gameState == GAME_STATES::PLAYING) {
		nextPlayer();
		if (players[currentPlayer - 1]->getType() == PLAYER_TYPES::AI) {
			move();
		}
	}
	else if (gameState == GAME_STATES::WON){
		winner = currentPlayer;

	}
}

void Controller::move() {
	// check if new current player is an AI
	if (players[currentPlayer - 1]->getType() == PLAYER_TYPES::AI) {
		players[currentPlayer - 1]->move();

		gameState = board->checkState();

		if (gameState == GAME_STATES::PLAYING) {
			nextPlayer();
			
		}
		else if (gameState == GAME_STATES::WON) {
			winner = currentPlayer;

		}
	}

}

bool Controller::gameIsInProgress() {
	return gameState == GAME_STATES::PLAYING;
}

void Controller::nextPlayer(){
	currentPlayer++;

	if (currentPlayer > MAX_PLAYERS) {
		currentPlayer = 1;
	}	
}

GAME_STATES Controller::getGameState() {
	return gameState;
}

int Controller::getWinner() {
	return winner;
}

char Controller::getBoardPosition(int row, int col) {
	return board->getPosition(row, col);
}

int Controller::getCurrentPlayer() {
	return currentPlayer;
}

bool Controller::isMoveValid(int row, int col) {
	return board->isValid(row, col);
}
