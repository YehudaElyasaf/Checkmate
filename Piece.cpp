#include "Piece.h"

Piece::Piece(bool color) :_color(color) {}
Piece::~Piece(){}

char Piece::getColor() const
{
    return _color;
}
