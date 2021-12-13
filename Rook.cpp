#include "Rook.h"

Rook::Rook(bool color) :Piece(color) {}

bool Rook::validMove(const Board& board, const Position& src, const Position& dst) const {
	Position startCheck(0, 0);
	Position endCheck(0, 0);

	if (src.getX() == dst.getX())
	{
		if (src.getY() < dst.getY()) {
			startCheck = src;
			endCheck = dst;
		}
		else {
			startCheck = dst;
			endCheck = src;
		}

		for (int i = startCheck.getY() + 1; i < endCheck.getY(); i++) {
			if (board[Position(startCheck.getX(), i)] != nullptr)
				return false;
		}
		return true;
	}
	else if (src.getY() == dst.getY()) {
		if (src.getX() < dst.getX()) {
			startCheck = src;
			endCheck = dst;
		}
		else {
			startCheck = dst;
			endCheck = src;
		}

		for (int i = src.getX() + 1; i < dst.getX(); i++) {
			if (board[Position(i, src.getY())] != nullptr)
				return false;
		}
		return true;
	}

	return false;
}

char Rook::getType() const {
	if (this->_color == WHITE)
		return ROOK_WHITE;
	else
		return ROOK_BLACK;
}