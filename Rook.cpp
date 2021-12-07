#include "Rook.h"

Rook::Rook(bool color) :Piece(color) {}

bool Rook::validMove(const Board& board, const Position& src, const Position& dst) const {
	return src.getX() == dst.getX() ||
		src.getY() == dst.getY();
} 

char Rook::getType() const {
	if (this->_color == WHITE)
		return ROOK_WHITE;
	else
		return ROOK_BLACK;
}