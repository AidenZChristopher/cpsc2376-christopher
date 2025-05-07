#pragma once
#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include "shape.h"
#include "circle.h"
#include "square.h"
#include "rectangle.h"
class ShapeFactory
{
public:
    static std::unique_ptr<Shape> createShape(const std::string& line)
    {
        std::istringstream stream(line);
        std::string type;
        stream >> type;

        if (type == "circle")
        {
            double r;
            if (stream >> r && r > 0)
            {
                return std::make_unique<Circle>(r);
            }
            else
            {
                std::cerr << "[Error] Invalid radius for circle: " << line << "\n";
            }
        }
        else if (type == "square")
        {
            double s;
            if (stream >> s && s > 0)
            {
                return std::make_unique<Square>(s);
            }
            else
            {
                std::cerr << "[Error] Invalid side length for square: " << line << "\n";
            }
        }
        else if (type == "rectangle")
        {
            double w, h;
            if (stream >> w >> h && w > 0 && h > 0)
            {
                return std::make_unique<Rectangle>(w, h);
            }
            else
            {
                std::cerr << "[Error] Invalid width/height for rectangle: " << line << "\n";
            }
        }
        else
        {
            std::cerr << "[Error] Unknown shape type: " << type << "\n";
        }

        return nullptr;
    }
};