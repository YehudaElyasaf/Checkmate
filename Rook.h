#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	int validMove(const Board& board, const Position& src, const Position& dst) const override;
};