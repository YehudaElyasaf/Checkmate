#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(bool color);
	bool validMove(const Position& src, const Position& dst) const override;
	char getType() const override;
};