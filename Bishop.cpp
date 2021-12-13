#include "Bishop.h"

Bishop::Bishop(bool color) :Piece(color) {}

bool Bishop::validMove(const Board& board, const Position& src, const Position& dst) const {
	Position startCheck(0, 0);
	Position endCheck(0, 0);

	if (src.getY() < dst.getY()) {
		startCheck = src;
		endCheck = dst;
	}
	else {
		startCheck = dst;
		endCheck = src;
	}

	if (src.getX() - dst.getX() == src.getY() - dst.getY()) {
		//move in / shape
		for (int i = 1; startCheck.getX() + i < endCheck.getX(); i++) {
			if (board[Position(startCheck.getX() + i, startCheck.getY() + 1)] != nullptr)
				return false;
		}
		return true;
	}
	else if (src.getX() - dst.getX() == (src.getY() - dst.getY()) * REMOVE_ZERO) {
		//move in \ shape

		for (int i = 1; startCheck.getX() - i < endCheck.getX(); i--) {
			if (board[Position(startCheck.getX() - i, startCheck.getY() + 1)] != nullptr)
				return false;
		}
		return true;
	}
	return false;
}
char Bishop::getType() const {
	if (this->_color == WHITE)
		return BISHOP_WHITE;
	else
		return BISHOP_BLACK;
}