#include "score.h"

Score::Score() {
	wins	= 0;
	loses	= 0;
	draws	= 0;
}


Score::~Score() {
}

void Score::incWins() {
	wins++;
}

void Score::incLoses() {
	loses++;
}

void Score::incDraws() {
	draws++;
}

int Score::getWins() {
	return wins;
}

int Score::getLoses() {
	return loses;
}

int Score::getDraws() {
	return draws;
}
