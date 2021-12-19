#pragma once
#include <iostream>
class Position
{
public:
	//c'tors
	Position(const std::string& posString);
	Position(int x, int y);
	//getters
	int getX() const;
	int getY() const;
	bool operator==(const Position& other) const;
private:
	int _x;
	int _y;
};
