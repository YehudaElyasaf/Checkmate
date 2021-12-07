#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
public:
    Pawn(bool color);
    bool validMove(const Board&, const Position& src, const Position& dst) const override;
    bool diagonalMove(const Position& src, const Position& dest) const;
    char getType() const override;
};

