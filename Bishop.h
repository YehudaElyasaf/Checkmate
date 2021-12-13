#pragma once
#include "Piece.h"

#define REMOVE_ZERO -1

class Bishop : public Piece
{
public:
	Bishop(bool color);
	bool validMove(const Board& board, const Position& src, const Position& dst) const override;
	char getType() const override;
};