#pragma once
#include "Piece.h"
#include "Position.h"
class King :
    public Piece
{
public:
    //c'tor
    King(bool color);
    //check if the move's path is valid to this specific piece and empty
    bool validMove(const Board& board, const Position& src, const Position& dst) const override;
    //getters
    char getType() const override;
};

