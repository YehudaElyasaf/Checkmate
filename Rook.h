#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(bool color);
	bool validMove(const Position& src, const Position& dst) const override;
	char getType() const override;
};