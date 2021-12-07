#pragma once
#include "Piece.h"
#include "Position.h"
class King :
    public Piece
{
public:
    King(bool color);
    bool validMove(const Position& src, const Position& dest) const override;
    char getType() const override;
};

