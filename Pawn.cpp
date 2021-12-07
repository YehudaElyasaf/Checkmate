#include "Pawn.h"
#include <math.h>
#define WHITE_START 7
#define BLACK_START 2
Pawn::Pawn(bool color): Piece(color) {}

bool Pawn::validMove(const Position& src, const Position& dest) const
{
	if (_color == WHITE)
	{
		return ((src.getY() == WHITE_START && dest.getY() == WHITE_START - 2) || src.getY() - dest.getY() == 1);
	}
	return ((src.getY() == BLACK_START && dest.getY() == BLACK_START + 2) || src.getY() - dest.getY() == -1);
}

bool Pawn::diagonalMove(const Position& src, const Position& dest) const
{
	bool result = abs(src.getX() - dest.getX()) == 1;
	if (_color == WHITE)
	{
		result = result && src.getY() - dest.getY() == 1;
	}
	else
	{
		result = result && src.getY() - dest.getY() == -1;
	}
	return result;
}

char Pawn::getType() const
{
	if (_color == WHITE)
	{
		return PAWN_WHITE;
	}
	return PAWN_BLACK;
}
