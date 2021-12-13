#include "Pawn.h"
#include <math.h>
#define WHITE_START 1
#define BLACK_START 6

Pawn::Pawn(bool color) : Piece(color) {}

bool Pawn::validMove(const Board& board, const Position& src, const Position& dest) const
{
	if (diagonalMove(src, dest) && board[dest] != nullptr)
	{
		return (board[dest]->getColor()) != (board[src]->getColor());//color of dest must be different from color of src 
	}
	else
	{
		if (_color == WHITE)
		{
			return ((src.getY() == WHITE_START && dest.getY() == WHITE_START + 2) || (src.getY() - dest.getY() == -1) && src.getX() == dest.getX());
		}
		else { //color == BLACK
			return ((src.getY() == BLACK_START && dest.getY() == BLACK_START - 2) || (src.getY() - dest.getY() == 1) && src.getX() == dest.getX());
		}
	}
}

bool Pawn::diagonalMove(const Position& src, const Position& dest) const
{
	bool result = abs(src.getX() - dest.getX()) == 1;
	if (_color == WHITE)
	{
		result = result && src.getY() - dest.getY() == -1;
	}
	else
	{
		result = result && src.getY() - dest.getY() == 1;
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
