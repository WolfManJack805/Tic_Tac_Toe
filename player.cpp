#include "player.h"


Player::Player(int number, PLAYER_TYPES type, char piece) {
	this->number = number;
	this->type = type;
	this->piece = piece;
}

Player::~Player() {
}

int Player::getNumber() {
	return number;
}

PLAYER_TYPES Player::getType() {
	return type;
}

char Player::getPiece() {
	return piece;
}


