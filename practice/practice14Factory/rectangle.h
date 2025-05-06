#pragma once
#include "shape.h"

class Rectangle : public Shape
{
    double width;
    double height;
public:
    Rectangle(double w, double h);
    double area() const override;
};
