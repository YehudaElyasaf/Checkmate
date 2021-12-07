#pragma once
#include <iostream>
class Position
{
public:
	Position(const std::string& posString);
	Position(int x, int y);
	int getX() const;
	int getY() const;
	bool operator==(const Position& other) const;
private:
	int _x;
	int _y;
};
