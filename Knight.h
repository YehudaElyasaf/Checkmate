#pragma once
#include "Piece.h"
class Knight :
    public Piece
{
public:
    Knight(bool color);
    bool validMove(const Board& board, const Position& src, const Position& dst) const override;
    char getType() const override;
};

