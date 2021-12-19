#pragma once
#include "Piece.h"

#define REMOVE_ZERO -1

class Bishop : public Piece
{
public:
	//c'tor
	Bishop(bool color);
	//check if the move's path is valid to this specific piece and empty
	bool validMove(const Board& board, const Position& src, const Position& dst) const override;
	//getters
	char getType() const override;
};