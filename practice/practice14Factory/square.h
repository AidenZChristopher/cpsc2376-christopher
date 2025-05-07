#pragma once
#include "shape.h"

class Square : public Shape
{
    double side;
public:
    Square(double s);
    double area() const override;
};
