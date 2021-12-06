#pragma once
#include "Piece.h"
#include<iostream>

#define BOARD_SIZE 8

class Board
{
private:
	Piece* _board[BOARD_SIZE][BOARD_SIZE];
public:
	Board(const std::string& formatString);
	~Board();
	void movePiece(const Position& src, const Position& dst);
	std::string getBoard();
	Piece* operator[] (const Position&);
};

