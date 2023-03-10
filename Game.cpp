#include "Game.h"
#define BOARD_STRING_END 64

enum moveTypes { VALID = '0', CHECK, INVALID_SRC, INVALID_DEST, CAUSE_CHECK, INVALID_INDEX, INVALID_MOVE, SAME_SRC_AND_DEST, CHECK_MATE };

Game::Game(const string& formatString) : _board(formatString.substr(0, BOARD_STRING_END)), _turn(formatString[BOARD_STRING_END] - '0') {
	_points[BLACK] = 0;
	_points[WHITE] = 0;
}

Game::Game() : Game("RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1") {
	_points[BLACK] = 0;
	_points[WHITE] = 0;
}

int Game::move(const string& moveString)
{
	Position src(moveString.substr(0, 2));
	Position dest(moveString.substr(2, 2));
	int type = moveType(src, dest);
	if (type == VALID || type == CHECK || type == CHECK_MATE)
	{
		printPoints(dest);
		_board.movePiece(src, dest);
		_turn = !_turn;
		if (type == CHECK)
		{
			if (isCheckMate())
			{
				type = CHECK_MATE;
			}
		}
	}

	return type;
}

void Game::printPoints(const Position& dest) {
	calcualtePoints(dest);

	std::cout << "\t<---------------->" << std::endl;
	std::cout << "\t BLACK's POINTS: " << _points[BLACK] << std::endl;
	std::cout << "\t WHITE's POINTS: " << _points[WHITE] << std::endl;
	std::cout << "\t<----------------->" << std::endl;
}

void Game::calcualtePoints(const Position& dest) {
	if (_board[dest] == nullptr)
		return;

	switch (_board[dest]->getType())
	{
	case QUEEN_BLACK:
		_points[BLACK] += QUEEN_VALUE;
		break;
	case ROOK_BLACK:
		_points[BLACK] += ROOK_VALUE;
		break;
	case KNIGHT_BLACK:
		_points[BLACK] += KNIGHT_VALUE;
		break;
	case BISHOP_BLACK:
		_points[BLACK] += BISHOP_VALUE;
		break;
	case PAWN_BLACK:
		_points[BLACK] += PAWN_VALUE;
		break;

	case QUEEN_WHITE:
		_points[WHITE] += QUEEN_VALUE;
		break;
	case ROOK_WHITE:
		_points[WHITE] += ROOK_VALUE;
		break;
	case KNIGHT_WHITE:
		_points[WHITE] += KNIGHT_VALUE;
		break;
	case BISHOP_WHITE:
		_points[WHITE] += BISHOP_VALUE;
		break;
	case PAWN_WHITE:
		_points[WHITE] += PAWN_VALUE;
		break;
	}
}

bool Game::isCheckMate() const
{
	int move;
	bool cantMove = true, exit_sub_loop = false;
	for (size_t i = 0; i < BOARD_SIZE && cantMove; i++)
	{
		exit_sub_loop = false;
		for (size_t j = 0; j < BOARD_SIZE && cantMove; j++)
		{
			exit_sub_loop = false;
			for (size_t k = 0; k < BOARD_SIZE && cantMove && !exit_sub_loop; k++)
			{
				for (size_t l = 0; l < BOARD_SIZE && cantMove && !exit_sub_loop; l++)
				{
					move = moveType(Position(i, j), Position(k, l));
					if (move == INVALID_SRC)
					{
						exit_sub_loop = true;
					}
					else
					{
						if (move == VALID || move == CHECK)
						{
							cantMove = false;
						}
					}
				}
			}
		}
	}
	return cantMove;
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
