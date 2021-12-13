#pragma once
#include "Board.h"
using std::string;
class Game
{
public:
	Game(const string& formatString);
	Game();
	int move(const string& moveString);
private:
	Board _board;
	bool _turn;
	int moveType(const Position& src, const Position& dest) const;
	Position findPiece(char type) const;
	bool isCheck() const;
};

