#include "Game.h"
#define BOARD_STRING_END 64

enum moveTypes { VALID = '0', CHECK, INVALID_SRC, INVALID_DEST, CAUSE_CHECK, INVALID_INDEX, INVALID_MOVE, SAME_SRC_AND_DEST, CHECK_MATE };

Game::Game(const string& formatString) : _board(formatString.substr(0, BOARD_STRING_END)), _turn(formatString[BOARD_STRING_END] - '0') {}

Game::Game() : Game("RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1") {}

int Game::move(const string& moveString)
{
	Position src(moveString.substr(0, 2));
	Position dest(moveString.substr(2, 2));
	int type = moveType(src, dest);
	if (type == VALID || type == CHECK || type == CHECK_MATE)
	{
		_board.movePiece(src, dest);
		_turn = !_turn;
	}
	return type;
	
}

string Game::getGuiStr() const
{
	string guiStr = _board.getBoard();
	guiStr += ((int)_turn + '0');
	return guiStr;

}

Position Game::findPiece(const char type, const Board& board) const
{
	bool found = false;
	int i, j;
	for (i = 0; i < BOARD_SIZE && !found; i++)
	{
		for (j = 0; j < BOARD_SIZE && !found; j++)
		{
			found = (board[Position(j, i)] != nullptr) && (board[Position(j, i)]->getType() == type);
		}
	}
	return Position(j - 1, i - 1);
}

bool Game::isCheck(const Position& src, const Position& dest, bool turn) const
{
	Board tempBoard(_board);
	tempBoard.movePiece(src, dest);
	bool check = false;
	int type;
	Piece* currPiece = nullptr;
	Position kingPos = (turn == WHITE) ? findPiece(KING_BLACK, tempBoard) : findPiece(KING_WHITE, tempBoard);
	for (size_t i = 0; i < BOARD_SIZE && !check; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE && !check; j++)
		{
			currPiece = tempBoard[Position(j, i)];
			check = (currPiece != nullptr) && (currPiece->getColor() == turn) && currPiece->validMove(tempBoard, Position(j, i), kingPos);
		}
	}
	return check;
}

int Game::moveType(const Position& src, const Position& dest) const
{
	if (src.getX() >= BOARD_SIZE || src.getY() >= BOARD_SIZE || dest.getX() >= BOARD_SIZE || dest.getY() >= BOARD_SIZE)
	{
		return INVALID_INDEX;
	}
	if (src == dest)
	{
		return SAME_SRC_AND_DEST;
	}
	if (_board[src] == nullptr || _board[src]->getColor() != _turn)
	{
		return INVALID_SRC;
	}
	if (!(_board[src]->validMove(_board, src, dest)))
	{
		return INVALID_MOVE;
	}
	if (_board[dest] != nullptr && _board[dest]->getColor() == _turn)
	{
		return INVALID_DEST;
	}
	if (isCheck(src, dest, _turn))
	{
		return CHECK;
	}
	if (isCheck(src, dest, !_turn))
	{
		return CAUSE_CHECK;
	}
	return VALID;
}
