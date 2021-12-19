#pragma once
#include "Board.h"

#define NUM_OF_PLAYERS 2

enum values {
	QUEEN_VALUE = 9,
	ROOK_VALUE = 5,
	KNIGHT_VALUE = 3,
	BISHOP_VALUE = 3,
	PAWN_VALUE = 1,
};

using std::string;
class Game
{
public:
	//c'tors
	Game(const string& formatString);
	Game();
	//manage a turn according to the instruct from the GUI
	int move(const string& moveString);
	//return a string to return to the GUI
	string getGuiStr() const;
private:
	Board _board;
	bool _turn;
	int _points[NUM_OF_PLAYERS];
	//check the move's code to return to the GUI
	int moveType(const Position& src, const Position& dest) const;
	//check whare a piece exists on the board
	Position findPiece(const char type, const Board& board) const;
	//check if the king is in a danger
	bool isCheck(const Position& src, const Position& dest, bool turn) const;
	//print the points of each player
	void printPoints(const Position& dest);
	//calculate the points of each player
	void calcualtePoints(const Position& dest);
	//check if the king is in a danger he can't avoid
	bool isCheckMate() const;
};

