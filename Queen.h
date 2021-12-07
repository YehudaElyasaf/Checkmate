#pragma once

#include "Bishop.h"
#include "Rook.h"

class Queen :public Bishop,public Rook, public Piece
{
public:
	Queen(bool color);
	bool validMove(const Board& board, const Position& src, const Position& dst) const override;
	char getType() const override;
};

