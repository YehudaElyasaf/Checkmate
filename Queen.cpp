#include "Queen.h"

Queen::Queen(bool color) :Rook(color), Bishop(color) {}

bool Queen::validMove(const Position& src, const Position& dst) const {
	return Rook::validMove(src, dst) || Bishop::validMove(src, dst);
}
char Queen::getType() const {
	if (this->_color == WHITE)
		return QUEEN_WHITE;
	else
		return QUEEN_BLACK;
}