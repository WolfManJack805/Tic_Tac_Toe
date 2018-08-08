#pragma once
#include "player.h"

class HumanPlayer :	public Player {
	private:

	public:
		HumanPlayer(int number, PLAYER_TYPES type, char piece);
		virtual ~HumanPlayer();

		
		// A virtual function is an abstract function. Functions cannot be declared "abstract".
		// virtual in child class: explicitly overrides the parent class' virtual function,
		// defaults to virtual if ommited.
		// override in child class: to make sure the child function overrides
		// the parent class' function 
		virtual void move() override;
};

