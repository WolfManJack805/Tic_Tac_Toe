#pragma once

const int BOARD_ROWS	= 3;
const int BOARD_COLS	= 3;
const int BOARD_SIZE = BOARD_COLS * BOARD_ROWS;
const int MAX_PLAYERS	= 2;

enum class GAME_STATES {
	STANDBY,
	PLAYING,
	WON,
	DRAW
};

enum class GAME_TYPES {
	NONE,
	HUMAN_VS_HUMAN,
	HUMAN_VS_AI,
	AI_VS_AI,
};


enum class PLAYER_TYPES {
	HUMAN, 
	AI
};

const char PLAYER_PIECES[MAX_PLAYERS] = {
	'X',
	'O'
};
