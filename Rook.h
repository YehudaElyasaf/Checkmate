#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	bool validMove(const Position& src, const Position& dst) const override;
};