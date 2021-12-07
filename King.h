#pragma once
#include "Piece.h"
#include "Position.h"
class King :
    public Piece
{
public:
    King(bool color);
    bool validMove(const Board& board, const Position& src, const Position& dst) const override;
    char getType() const override;
};

