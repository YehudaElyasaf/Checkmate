#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
public:
    Pawn(bool color);
    bool validMove(const Board&, const Position& src, const Position& dst) const override;
    char getType() const override;
private:
    bool diagonalMove(const Position& src, const Position& dest) const;
};

