#include "Game.h"
#define BOARD_STRING_END 64

Game::Game(const string& formatString): _board(formatString.substr(0, BOARD_STRING_END)), _turn(formatString[BOARD_STRING_END] - '0') {}

Game::Game(): Game("RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1") {}

int Game::move(const string& moveString)
{
	return 0;
}

int Game::moveType(const Position& src, const Position& dest) const
{
	return 0;
}
