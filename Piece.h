#pragma once
#include "Position.h"
#include "Board.h"

enum colors { BLACK, WHITE };
enum types {
	KING_WHITE = 'K', KING_BLACK = 'k',
	QUEEN_WHITE = 'Q', QUEEN_BLACK = 'q',
	ROOK_WHITE = 'R', ROOK_BLACK = 'r',
	KNIGHT_WHITE = 'N', KNIGHT_BLACK = 'n',
	BISHOP_WHITE = 'B', BISHOP_BLACK = 'b',
	PAWN_WHITE = 'P', PAWN_BLACK = 'p',
	NULL_PLAYER = '#' };
class Board;
class Piece
{
protected:
	bool _color;
public:
	//c'tor and d'tor
	Piece(bool color);
	virtual ~Piece();
	//check if the move's path is valid to this specific piece and empty
	virtual bool validMove(const Board& board, const Position& src, const Position& dst) const = 0 ;
	//getters
	virtual char getType() const = 0;
	bool getColor() const;
};

