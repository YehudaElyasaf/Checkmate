#pragma once
#include "Piece.h"
class Pawn :
    public Piece
{
public:
    //c'tor
    Pawn(bool color);
    //check if the move's path is valid to this specific piece and empty
    bool validMove(const Board& board, const Position& src, const Position& dst) const override;
    //getters
    char getType() const override;
private:
    //check if the pawn eats a piece
    bool diagonalMove(const Position& src, const Position& dest) const;
};

