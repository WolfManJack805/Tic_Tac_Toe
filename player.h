#pragma once

#include "constants.h"


// A class with at least one pure function is implicitly an abstract class
// and objects cannot be created/instantiated.
// A class with at least one pure function may also be declared explicitly abstract
class Player {
	private:
		int				number;
		PLAYER_TYPES	type;
		char			piece;
		
		
	public:
		Player(int number, PLAYER_TYPES type, char piece);

		// A Base class that has a virtual function is called "a polymorphic class".
		// A Base class must have at least one virtual function:
		// 1. To avoid "Object Slicing", the loss of child class variable data when storing
		//	  child objects in a variable of type Base class:
		//
		// For example:
		// class Base
		// class Derived : public Base
		//		int name;
		// vector<Base> baseVector;
		// baseVector.push_back(new Derived())
		//
		// 2  To avoid memory leaks:
		//    Destructor should be declared virtual in base class and child classes.
		//	  If your derived class destructor is virtual then objects will be deleted
		//	  in order (first derived object destructor is called then base object destructor).
		//	  If your derived class destructor is NOT virtual then only base class object
		//	  will get deleted. There will be memory leak for derived object.
		virtual ~Player();

		// Getters
		int				getNumber();
		PLAYER_TYPES	getType();
		char			getPiece();

		// A virtual function is an abstract function. Functions cannot be declared "abstract".
		// Pure virtual function (= 0): requires an overriding function be provided in each child class
		// with the same signature as the parent class.
		virtual void move() = 0;
};

