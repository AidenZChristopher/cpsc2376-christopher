#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "shape.h"
#include "shapeFactory.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <iomanip>
#include "Shape.h"
#include "ShapeFactory.h"

int main()
{
    std::ifstream file("input.txt");
    if (!file)
    {
        std::cerr << "[Error] Could not open input.txt\n";
        return 1;
    }

    std::string line;
    std::vector<std::unique_ptr<Shape>> shapes;

    int lineNumber = 0;
    while (std::getline(file, line))
    {
        ++lineNumber;
        if (line.empty())
        {
            std::cerr << "[Warning] Skipping empty line #" << lineNumber << "\n";
            continue;
        }

        auto shape = ShapeFactory::createShape(line);
        if (shape)
        {
            shapes.push_back(std::move(shape));
        }
        else
        {
            std::cerr << "[Warning] Skipping invalid shape at line #" << lineNumber << "\n";
        }
    }

    double totalArea = 0;
    for (const auto& shape : shapes)
    {
        totalArea += shape->area();
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nTotal valid shapes: " << shapes.size() << "\n";
    std::cout << "Total area: " << totalArea << "\n";

    return 0;
}
