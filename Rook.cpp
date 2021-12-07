#include "Rook.h"

Rook::Rook(bool color) :Piece(color) {}

bool Rook::validMove(const Board& board, const Position& src, const Position& dst) const {
	if (src.getX() == dst.getX())
	{
		if (src.getY() < dst.getY()) {
			for (int i = src.getY() + 1; i < dst.getY(); i++) {
				if (board[Position(src.getX(), i)] != nullptr)
					return false;
			}
		}
		else {
			for (int i = src.getY() - 1; i > dst.getY(); i--) {
				if (board[Position(src.getX(), i)] != nullptr) 
					return false;
			}
		}
	}
	else if (src.getY() == dst.getY()) {
		if (src.getX() < dst.getX()) {
			for (int i = src.getX() + 1; i < dst.getX(); i++) {
				if (board[Position(i, src.getY())] != nullptr)
					return false;
			}
		}
		else {
			for (int i = src.getX() - 1; i > dst.getX(); i--) {
				if (board[Position(i, src.getY())] != nullptr)
					return false;
			}
		}
	}

	return false;
}

char Rook::getType() const {
	if (this->_color == WHITE)
		return ROOK_WHITE;
	else
		return ROOK_BLACK;
}