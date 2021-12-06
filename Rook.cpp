#include "Rook.h"

bool Rook::validMove(const Position& src, const Position& dst) const {
	return src.getX() == dst.getX() ||
		src.getY() == dst.getY();
}