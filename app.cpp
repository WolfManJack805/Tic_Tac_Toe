/* 
	//David Magana III
	//Partners: Murat Dugan, Davin Ross, Scott Dingman, Beibk
	//AI Class
	//TicTacToe
	//Week 11 Dec. 11, 2017
*/

#include "controller.h"
#include "view.h"
#include <iostream>


void main() {
	Controller controller;
	View view(controller);
	view.menu();	
}