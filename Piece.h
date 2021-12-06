#pragma once

#define WHITE 0
#define BLACK 1

class Piece
{
private:
	bool _color;
public:
	virtual ~Piece();
	virtual int validMove(const Board& board, const Position& src, const Position& dst) const = 0 ;
};

