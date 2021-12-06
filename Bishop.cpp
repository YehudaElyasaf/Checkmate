#include "Bishop.h"
#include <cstdlib>

Bishop::Bishop(bool color) :Piece(color) {}
bool Bishop::validMove(const Position& src, const Position& dst) const {
	return std::abs(src.getX() - dst.getX()) ==
		std::abs(src.getY() - dst.getY());
}