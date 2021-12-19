#pragma once
#include "Piece.h"
#include<iostream>

#define BOARD_SIZE 8
class Piece;
class Board
{
private:
	Piece* _board[BOARD_SIZE][BOARD_SIZE];
public:
	//c'tors
	Board(const std::string& formatString);
	Board(const Board& other);
	~Board();
	void movePiece(const Position& src, const Position& dst);
	//get the board's string
	std::string getBoard() const;
	Piece* operator[] (const Position&) const;
};

