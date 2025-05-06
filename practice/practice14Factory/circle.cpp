#include "circle.h"

Circle::Circle(double r) : radius(r) {}

double Circle::area() const
{
    return 3.14 * radius * radius;
}
