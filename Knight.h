#pragma once
#include "Piece.h"
class Knight :
    public Piece
{
public:
    Knight(bool color);
    bool validMove(const Board&, const Position& src, const Position& dst) const override;
    char getType() const override;
};

