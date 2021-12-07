#pragma once
#include "Piece.h"
class Knight :
    public Piece
{
public:
    Knight(bool color);
    bool validMove(const Position& src, const Position& dest) const override;
    char getType() const override;
};

