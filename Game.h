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
	Game(const string& formatString);
	Game();
	int move(const string& moveString);
	string getGuiStr() const;
private:
	Board _board;
	bool _turn;
	int _points[NUM_OF_PLAYERS];
	int moveType(const Position& src, const Position& dest) const;
	Position findPiece(const char type, const Board& board) const;
	bool isCheck(const Position& src, const Position& dest, bool turn) const;
	void printPoints(const Position& dest);
	void calcualtePoints(const Position& dest);
};

