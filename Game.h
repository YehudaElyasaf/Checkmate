#pragma once
#include "Board.h"

#define NUM_OF_PLAYERS 2

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
	void printPoints(const int type, const Position& dest);
};

