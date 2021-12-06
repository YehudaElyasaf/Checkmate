#include "Position.h"

Position::Position(const std::string& posString)
{
	_x = posString[0] - 'a';
	_y = posString[1] - '1';
}

int Position::getX() const
{
	return _x;
}

int Position::getY() const
{
	return _y;
}

bool Position::operator==(const Position& other) const
{
	return this->_x == other._x && this->_y == other._y;
}