#include "Queen.h"

Queen::Queen(bool color) :Rook(color), Bishop(color) , Piece(color) {}

bool Queen::validMove(const Board& board, const Position& src, const Position& dst) const {
	return Rook::validMove(board, src, dst) || Bishop::validMove(board, src, dst);
}
char Queen::getType() const {
	if (Piece::_color == WHITE)
		return QUEEN_WHITE;
	else
		return QUEEN_BLACK;
}