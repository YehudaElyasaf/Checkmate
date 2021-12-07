#include "Position.h"

Position::Position(const std::string& posString): Position(posString[0] - 'a', posString[1] - '1') {}

Position::Position(int x, int y): _x(x), _y(y) {}

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