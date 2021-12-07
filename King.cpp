#include "King.h"
#include <math.h>

King::King(bool color) : Piece(color) {}

bool King::validMove(const Position& src, const Position& dest) const
{
	return abs(src.getX() - dest.getX()) <= 1 && abs(src.getY() - dest.getY()) <= 1;
}

char King::getType() const
{
	if (_color == WHITE)
	{
		return 'K';
	}
	return 'k';
}
