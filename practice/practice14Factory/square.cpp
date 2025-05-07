#include "square.h"

Square::Square(double s) : side(s) {}

double Square::area() const
{
    return side * side;
}
