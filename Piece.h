#pragma once
#include "Position.h"
#include "Board.h"

enum colors { WHITE, BLACK };
enum types {
	KING_WHITE = 'K', KING_BLACK = 'k',
	QUEEN_WHITE = 'Q', QUEEN_BLACK = 'q',
	ROOK_WHITE = 'R', ROOK_BLACK = 'r',
	KNIGHT_WHITE = 'N', KNIGHT_BLACK = 'n',
	BISHOP_WHITE = 'B', BISHOP_BLACK = 'b',
	PAWN_WHITE = 'P', PAWN_BLACK = 'p' };
class Board;
class Piece
{
protected:
	bool _color;
public:
	Piece(bool color);
	virtual ~Piece();
	virtual bool validMove(const Board& board, const Position& src, const Position& dst) const = 0 ;
	virtual char getType() const = 0;
};

