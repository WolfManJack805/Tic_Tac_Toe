#pragma once
#include "player.h"
#include "board.h"
#include <string>
#include <math.h>

class AIPlayer : public Player {
	private:
		Board* board;

		// Helper functions
		bool checkHorizontal();
		bool checkVertical();
		bool checkRightDiagonal();

		// Three approaches:
		// 1. Row-first		(Bibek)
		// 2. Col-first		(Scott)
		// 3. Single-Loop	(Ando)
		bool checkLeftDiagonal1();
		bool checkLeftDiagonal2();
		bool checkLeftDiagonal3();

		bool checkHorizontalBlock();
		bool checkVerticalBlock();
		bool checkRightDiagBlock();
		bool checkLeftDiagBlock();

		bool implementStrategy();
		bool threeCornerStrategy();
		bool vStrategy();
		bool lStrategy();
		bool isCenterOpen();
		bool isAnyPosOpen();

	public:
		AIPlayer(int number, PLAYER_TYPES type, char piece, Board* board);
		virtual ~AIPlayer();

		
		// A virtual function is an abstract function. Functions cannot be declared "abstract".
		// virtual in child class: explicitly overrides the parent class' virtual function,
		// defaults to virtual if ommited.
		// override in child class: to make sure the child function overrides
		// the parent class' function
		virtual void move() override;
};

