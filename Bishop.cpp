#include "Bishop.h"
#include <cstdlib>

Bishop::Bishop(bool color) :Piece(color) {}

bool Bishop::validMove(const Position& src, const Position& dst) const {
	return std::abs(src.getX() - dst.getX()) ==
		std::abs(src.getY() - dst.getY());
}
char Bishop::getType() const{
	if (this->_color == WHITE)
		return BISHOP_WHITE;
	else
		return BISHOP_BLACK;
}