#include "Knight.h"
#include <math.h>
Knight::Knight(bool color): Piece(color) {}

bool Knight::validMove(const Board&, const Position& src, const Position& dest) const
{
	return (abs(dest.getX() - src.getX()) == 1 && abs(dest.getY() - src.getY()) == 2) || (abs(dest.getX() - src.getX()) == 2 && abs(dest.getY() - src.getY()) == 1);
}

char Knight::getType() const
{
	if (_color == WHITE)
	{
		return KNIGHT_WHITE;
	}
	return KNIGHT_BLACK;
}
