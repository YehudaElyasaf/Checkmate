#pragma once
#include "Position.h"

#define WHITE 0
#define BLACK 1

class Piece
{
private:
	bool _color;
public:
	Piece(bool color);
	virtual ~Piece();
	virtual bool validMove(const Position& src, const Position& dst) const = 0 ;
};

