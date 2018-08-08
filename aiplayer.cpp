#include "aiplayer.h"


AIPlayer::AIPlayer(int number, PLAYER_TYPES type, char piece, Board* board) : Player(number, type, piece) {
	this->board = board;
}

AIPlayer::~AIPlayer() {
}

void AIPlayer::move() {
	
	//Check if we can win
	if (!checkHorizontal()) {
		if (!checkVertical()) {
			if (!checkRightDiagonal()) {
				if (!checkLeftDiagonal1()) {
					if (!checkHorizontalBlock()) {
						if (!checkVerticalBlock()) {
							if (!checkRightDiagBlock()) {
								if (!checkLeftDiagBlock()) {

									//implement new function here
									if (!implementStrategy()) {
										
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool AIPlayer::checkHorizontal() {
	bool	found			= false;
	char	piece			= getPiece();
	int		myPieces		= 0;
	int		opponentPieces	= 0;
	int		emptySpot		= 0;

	for (int row = 1; row <= BOARD_ROWS; row++) {
		for (int col = 1; col <= BOARD_COLS; col++) {
			char position = board->getPosition(row, col);

			if (position == piece) {
				myPieces++;
			}
			else if (position == ' ') {
				emptySpot = col;
			}
			else {
				opponentPieces++;
			}
		}

		// Check if we can win
		if (myPieces == BOARD_COLS - 1 && opponentPieces == 0) {
			// Play the winning piece
			board->setPosition(row, emptySpot, piece);
			found = true;
			break;
		}
		else {
			//Prepare to check the next col
			myPieces = 0;
			opponentPieces = 0;
			emptySpot = 0;

		}
	}
	return found;
}

bool AIPlayer::checkVertical() {
	bool	found				= false;
	char	piece				= getPiece();
	int		myPieces			= 0;
	int		opponentPieces		= 0;
	int		emptySpot			= 0;

	for (int col = 1; col <= BOARD_COLS; col++) {
		for (int row = 1; row <= BOARD_ROWS; row++) {
			char position = board->getPosition(row, col);

			if (position == piece) {
				myPieces++;
			}
			else if (position == ' ') {
				emptySpot = row;
			}
			else {
				opponentPieces++;
			}
		}

		// Check if we can win
		if (myPieces == BOARD_ROWS - 1 && opponentPieces == 0) {
			// Play the winning piece
			board->setPosition(emptySpot, col,  piece);
			found = true;
			break;
		}
		else {
			//Prepare to check the next col
			myPieces		= 0;
			opponentPieces	= 0;
			emptySpot		= 0;

		}
	}
	return found;
}

bool AIPlayer::checkRightDiagonal(){
	bool	found				= false;
	char	piece				= getPiece();
	int		myPieces			= 0;
	int		opponentPieces		= 0;
	int		emptySpotRow		= 0;
	int		emptySpotCol		= 0;

	for (int row = 1; row <= BOARD_ROWS; row++) {
		for (int col = row; col <= row; col++) {
			char position = board->getPosition(row, col);

			if (position == piece) {
				myPieces++;
			}
			else if (position == ' ') {
				emptySpotRow = row;
				emptySpotCol = col;
			}
			else {
				opponentPieces++;
			}
		}	
	}
	// Check if we can win
	if (myPieces == BOARD_COLS - 1 && opponentPieces == 0) {
		// Play the winning piece
		board->setPosition(emptySpotRow, emptySpotCol, piece);
		found = true;
	}
		return found;
}

bool AIPlayer::checkLeftDiagonal1() {
	bool	found				= false;
	char	piece				= getPiece();
	int		myPieces			= 0;
	int		opponentPieces		= 0;
	int		emptySpotRow		= 0;
	int		emptySpotCol		= 0;

	// Row-first approach
	for (int row = BOARD_ROWS; row >= 1; row--) {
		for (int col = BOARD_ROWS -(row -1); col <= BOARD_ROWS - (row - 1); col++) {
			char position = board->getPosition(row, col);

			if (position == piece) {
				myPieces++;
			}
			else if (position == ' ') {
				emptySpotRow = row;
				emptySpotCol = col;
			}
			else {
				opponentPieces++;
			}
		}
	}

	// Check if we can win
	if (myPieces == BOARD_COLS - 1 && opponentPieces == 0) {
		// Play the winning piece
		board->setPosition(emptySpotRow, emptySpotCol, piece);
		found = true;
	}
	return found;

}

bool AIPlayer::checkLeftDiagonal2() {
	bool	found = false;
	char	piece = getPiece();
	int		myPieces = 0;
	int		opponentPieces = 0;
	int		emptySpotRow = 0;
	int		emptySpotCol = 0;

	// Col-first approach
	for (int col = BOARD_COLS; col >= 1; col--) {
		for (int row = BOARD_COLS - (col - 1); col <= BOARD_COLS - (col - 1); row++) {
			char position = board->getPosition(row, col);

			if (position == piece) {
				myPieces++;
			}
			else if (position == ' ') {
				emptySpotRow = row;
				emptySpotCol = col;
			}
			else {
				opponentPieces++;
			}
		}
	}

	// Check if we can win
	if (myPieces == BOARD_COLS - 1 && opponentPieces == 0) {
		// Play the winning piece
		board->setPosition(emptySpotRow, emptySpotCol, piece);
		found = true;
	}
	return found;
}

bool AIPlayer::checkLeftDiagonal3() {
	bool	found				= false;
	char	piece				= getPiece();
	int		myPieces			= 0;
	int		opponentPieces		= 0;
	int		emptySpot			= 0;
	int		row					= 1;

	// Single-loop approach
	for (int col = BOARD_COLS; col >= 1; col--) {
		char position = board->getPosition(row, col);

		if (position == piece) {
			myPieces++;
		}
		else if (position == ' ') {
			emptySpot = col;
		}
		else {
			opponentPieces++;
		}
		
		// Check if we (as the AI) can win
		if (myPieces == BOARD_COLS - 1 && opponentPieces == 0) {
			// Play the winning piece
			board->setPosition(row, emptySpot, piece);
			found = true;
		}
		row++;
	}

	
	
	return found;
}

bool AIPlayer::checkHorizontalBlock() {
	bool isOpen = false;
	char piece = getPiece();
	int oppPieces = 0;
	int myAIPieces = 0;
	int emptySpotRow = 0;
	int emptySpotCol = 0;

	for (int row = 1; row <= BOARD_ROWS; ++row) {
		for (int col = 1; col <= BOARD_COLS; ++col) {
			char pos = board->getPosition(row, col);

			if (pos == piece) {
				myAIPieces++;
			}
			else if (pos == ' ') {

				emptySpotCol = col;
			}
			else {
				oppPieces++;
			}
		}

		if (oppPieces == 2 && myAIPieces == 0) {
			board->setPosition(row, emptySpotCol, piece);
			isOpen = true;
			break;
		}
		else {
			//Prepare to check the next col
			myAIPieces = 0;
			oppPieces = 0;
			emptySpotRow = 0;
			emptySpotCol = 0;

		}
	}

	
	return isOpen;
}

bool AIPlayer::checkVerticalBlock() {
	bool isOpen = false;
	char piece = getPiece();
	int myPieces = 0;
	int oppPieces = 0;
	int emptySpotRow = 0;

	for (int cols = 1; cols <= BOARD_COLS; ++cols)
	{
		for (int rows = 1; rows <= BOARD_ROWS; ++rows)
		{
			char pos = board->getPosition(rows, cols);

			if (pos == piece)
			{
				myPieces++;
			}
			else if (pos == ' ')
			{
				emptySpotRow = rows;
			}
			else
			{
				oppPieces++;
			}
		}
		if (oppPieces == BOARD_COLS - 1 && myPieces == 0) {
			board->setPosition(emptySpotRow, cols, piece);
			isOpen = true;
			break;
		}
		else {
			//Prepare to check the next col
			myPieces = 0;
			oppPieces = 0;
			emptySpotRow = 0;

		}
	}
	return isOpen;
}

bool AIPlayer::checkRightDiagBlock() {
	bool isOpen = false;
	char piece = getPiece();
	int myPieces = 0;
	int oppPieces = 0;
	int emptySpotRows = 0;
	int emptySpotCols = 0;

	for (int rows = 1; rows <= BOARD_ROWS; rows++)
	{
		for (int cols = rows; cols <= rows; cols++)
		{
			char position = board->getPosition(rows, cols);

			if (position == piece)
			{
				myPieces++;
			}
			else if (position == ' ')
			{
				emptySpotRows = rows;
				emptySpotCols = cols;
			}
			else
			{
				oppPieces++;
			}
		}
	}

	if (oppPieces == BOARD_COLS - 1 && myPieces == 0)
	{
		board->setPosition(emptySpotRows, emptySpotCols, piece);
		isOpen = true;
	}
	return isOpen;
}

bool AIPlayer::checkLeftDiagBlock() {
	bool isOpen = false;
	char piece = getPiece();
	int myPieces = 0;
	int oppPieces = 0;
	int emptyRows = 0;
	int emptyCols = 0;

	// rows first approach
	for (int rows = BOARD_ROWS; rows >= 1; --rows)
	{
		for (int cols = BOARD_ROWS - (rows - 1); cols >= BOARD_ROWS - (rows - 1); --cols)
		{
			char pos = board->getPosition(rows, cols);
			
			if (pos == piece)
			{
				myPieces++;
			}
			else if (pos == ' ')
			{
				emptyRows = rows;
				emptyCols = cols;
			}
			else
			{
				oppPieces++;
			}
		}
	}

	if (myPieces == 0 && oppPieces == BOARD_ROWS - 1)
	{
		board->setPosition(emptyRows, emptyCols, piece);
		isOpen = true;
	}

	return isOpen;
}
//----------------------------------------------------------
bool AIPlayer::implementStrategy() 
{
	bool implement = true;

	//randomly call one of the strategy functions//
	//if one cant be implemented then none of them can be implemented//
	//std::cout << "\nWe are checking if not lStrategy here!...\n\n";
	if (!threeCornerStrategy())
	{
		//std::cout << " We have determined !lStrategy() called in : AiPlayer::implementStragety// this means we are entering v corners\n\n";
		if (!vStrategy())
		{
			//std::cout << " We have determined !vStrategy() called in : AiPlayer::implementStragety// this means we are entering 3 corners\n\n";
			if (!lStrategy())
			{
				//std::cout << " We have determined !threeCornerStrategy() Strat called in : AiPlayer::implementStragety//this means that we are entering isCenterOpen()\n\n";
				if (!isCenterOpen())
				{
					//std::cout << " We have determined !CenterOpen() Strat called in : AiPlayer::implementStragety// this means that we are entering is anyPosOpen\n\n";
					if (!isAnyPosOpen())
					{
						std::string message = "\n AIPlayer::move() : the board is already full";

						throw std::exception(message.c_str());
					}
				}
			}
			//implement = false;
		}
	}
	return implement;
}
//==============================================================

bool AIPlayer::threeCornerStrategy()
{
	bool implement = false;
	int emptyRows = 1;
	int emptyCols = 1;
	char piece = getPiece();
	char position = board->getPosition(emptyRows, emptyCols);
	if (!implement)
	{
		//[1][1],[3][3],[1][3]
		//option a - if all pos are empty
		//[0,0] == [1][1] = empty// [2][2] == [3][3] = empty// [0][2] == [1][3] = empty
		if (position == ' ' && board->getPosition(emptyRows + 2, emptyCols + 2) == ' ' &&
			board->getPosition(emptyRows, emptyCols + 2) == ' ') {

			board->setPosition(emptyRows, emptyCols, piece);
			implement = true;

		}
		//option b - if 1st pos([1][1]) filled and rest are empty
		//[0,0] == [1][1] = piece// [2][2] == [3][3] == empty// [0][2] == [1][3] = empty
		else if (position == piece && board->getPosition(emptyRows + 2, emptyCols + 2) == ' ' &&
			board->getPosition(emptyRows, emptyCols + 2) == ' ')
		{
			board->setPosition(emptyRows, emptyCols + 2, piece);
			implement = true;
		}
		//option c - if 1st pos([1][1]) and nextPos ([3][3]) filled and rest are empty
		//[0,0] == [1][1] = piece// [0][2] == [1][3] == piece// [2][2] == [3][3]  = empty
		else if (position == piece && board->getPosition(emptyRows, emptyCols + 2) == piece &&
			board->getPosition(emptyRows + 2, emptyCols + 2) == ' ')
		{
			board->setPosition(emptyRows + 2, emptyCols + 2, piece);
			implement = true;
		}

		//option b - if first pos has piece and all rest are empty [1][3],[3][1],[3][3]
		//option c - if  first and second pos have piece and all pos are empty
		//option d - if rest pos are empty
	}
	return implement;
}

bool AIPlayer::vStrategy()
{
	bool implement = false;
	char piece = getPiece();
	int emptyRows = 0;
	int emptyCols = 0;
	char position = board->getPosition(emptyRows, emptyCols);

	if (!implement)
	{
		//option a - if all pos are empty
		//[0,0] == [1][1] = empty// [1][1] == [2][2] = empty// [0][2] == [1][3] = empty
		if (position == ' ' && position + 1 == ' ' && board->getPosition(emptyRows, emptyCols + 2) == ' ')
		{
			board->setPosition(emptyRows, emptyCols, piece);
			implement = true;
		}
		//option b - if 1st pos([1][1]) filled and rest are empty
		//[0,0] == [1][1] = piece// [1][1] == [2][2] == empty// [0][2] == [1][3] = empty
		else if (position == piece && position + 1 == ' ' && board->getPosition(emptyRows, emptyCols + 2) == ' ')
		{
			board->setPosition(emptyRows + 1, emptyCols + 1, piece);
			implement = true;
		}
		//option c - if 1st pos([1][1]) and nextPos ([2][2]) filled and rest are empty
		//[0,0] == [1][1] = piece// [1][1] == [2][2] == piece// [0][2] == [1][3] = empty
		else if (position == piece && position + 1 == piece && board->getPosition(emptyRows, emptyCols + 2) == ' ')
		{
			board->setPosition(emptyRows, emptyCols + 2, piece);
			implement = true;
		}
	}

	return implement;
}

bool AIPlayer::lStrategy()
{

	// just check pos 1,3 or 3,1 to see if we could block
	//play 11 or 23
	bool implement = false;
	char piece = getPiece();
	int myPieces = 0;
	int oppPieces = 0;
	int emptyRows = 0;
	int emptyCols = 0;
	int mveCounter = 0;

	char position = board->getPosition(emptyRows, emptyCols);

	for (int rows = 1; rows <= BOARD_ROWS; ++rows)
	{
		for (int cols = rows; cols <= BOARD_COLS; ++cols)
		{
			if (position == piece)
			{
				myPieces++;
			}
			else if (piece == ' ')
			{
				emptyRows = rows;
				emptyCols = cols;
			}
			else
			{
				oppPieces++;
			}
			
		}
		mveCounter++;
		if (board->getPosition(2, 2) != ' ' && mveCounter == 1 && board->getPosition(2, 1) == ' ')
		{
			//std::cout << " we came to a conclusion that the player did chose the center" << std::endl;
			board->setPosition(emptyRows + 2, emptyCols + 1, piece);
			implement = true;
		}
	}

	
	
	return implement;
}

bool AIPlayer::isCenterOpen() {
	bool isOpen = false;
	float row = BOARD_ROWS;
	float col = BOARD_COLS;
	int centerCol = (int) ceil(col / 2);
	int centerRow = (int) ceil(row / 2);

	if (board->getPosition(centerRow, centerCol) == ' ') {
		board->setPosition(centerRow, centerCol, getPiece());
		isOpen = true;
	}
	return isOpen;
}

bool AIPlayer::isAnyPosOpen() {
	bool isOpen = false;
	char piece = getPiece();

	for (int row = 1; row <= BOARD_ROWS; ++row)
	{
		for (int col = 1; col <= BOARD_COLS; ++col)
		{
			char pos = board->getPosition(row, col);

			if (pos == ' ')
			{
				isOpen = true;
				board->setPosition(row, col, piece);
				break;
			}

		}
		if (isOpen)
		{
			break;
		}
	}
	return isOpen;
}
