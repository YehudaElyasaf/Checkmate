#pragma once

#include "Bishop.h"
#include "Rook.h"

class Queen :virtual Bishop,virtual Rook, public Piece
{
public:
	//c'tor
	Queen(bool color);
	//check if the move's path is valid to this specific piece and empty
	bool validMove(const Board& board, const Position& src, const Position& dst) const override;
	//getters
	char getType() const override;
};

