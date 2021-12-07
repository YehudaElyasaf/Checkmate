#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(bool color);
	bool validMove(const Board& board, const Position& src, const Position& dst) const override;
	char getType() const override;
};