#pragma once

#include "Bishop.h"
#include "Rook.h"

class Queen :public Bishop,public Rook
{
	Queen(bool color);
	bool validMove(const Position& src, const Position& dst) const override;
};

