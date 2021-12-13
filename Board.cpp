#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

Board::Board(const std::string& formatString) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			switch (formatString[i * BOARD_SIZE + j]) {
			case 'K':
				_board[i][j] = new King(WHITE);
				break;
			case 'k':
				_board[i][j] = new King(BLACK);
				break;
			case 'Q':
				_board[i][j] = new Queen(WHITE);
				break;
			case 'q':
				_board[i][j] = new Queen(BLACK);
				break;
			case 'R':
				_board[i][j] = new Rook(WHITE);
				break;
			case 'r':
				_board[i][j] = new Rook(BLACK);
				break;
			case 'N':
				_board[i][j] = new Knight(WHITE);
				break;
			case 'n':
				_board[i][j] = new Knight(BLACK);
				break;
			case 'B':
				_board[i][j] = new Bishop(WHITE);
				break;
			case 'b':
				_board[i][j] = new Bishop(BLACK);
				break;
			case 'P':
				_board[i][j] = new Pawn(WHITE);
				break;
			case 'p':
				_board[i][j] = new Pawn(BLACK);
				break;
			case NULL_PLAYER:
				_board[i][j] = nullptr;
			}
		}
	}
}
Board::~Board() {

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			delete _board[i][j];
		}
	}
}

void Board::movePiece(const Position& src, const Position& dst) {
	if (_board[dst.getY()][dst.getX()] == nullptr)
	{
		delete _board[dst.getY()][dst.getX()];
	}
	_board[dst.getY()][dst.getX()] = _board[src.getY()][src.getX()];
	_board[src.getY()][src.getX()] = 0;
}
void Board::printBoard() const {
	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << "\t";
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_board[i][j] != nullptr)
				std::cout << _board[i][j]->getType() << " ";
			else
				std::cout << ". ";
		}
		std::cout << "\n";
	}
}

std::string Board::getBoard() {
	std::string formatString = "";

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_board[i][j] == nullptr)
				formatString += NULL_PLAYER;
			else
				formatString += _board[i][j]->getType();
		}
	}
	return formatString;
}
Piece* Board::operator[] (const Position& position) const {
	return _board[position.getY()][position.getX()];
}