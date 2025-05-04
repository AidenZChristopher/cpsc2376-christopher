/*
This code may have been developed with the assistance of artificial intelligence (AI) tools,
which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <iomanip>
const double pi = 3.14159;

class Shape
{
public:
	virtual double getArea() const = 0;
	virtual ~Shape() = default;
};

class Rectangle : public Shape
{
private:
	double width;
	double height;
public:
	Rectangle(double width, double height) : width(width), height(height) {}
	double getArea() const override { return width * height; }

};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double radius) : radius(radius) {}
	double getArea() const override { return pi * radius * radius; }

};

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes)
{
	for (const std::unique_ptr<Shape>& shape : shapes)
	{
		std::cout << "Area: " << shape->getArea() << "\n";
	}
}


int main()
{
	std::ifstream file("shapes.txt");
	if (!file) {
		std::cerr << "Error opening shapes.txt\n";
		return 1;
	}

	std::vector<std::unique_ptr<Shape>> shapes;
	std::string type;
	while (file >> type)
	{
		if (type == "rectangle")
		{
			double width, height;
			file >> width >> height;
			auto rectPtr = std::make_unique<Rectangle>(width, height);
			shapes.push_back(std::move(rectPtr));
		}
		else if (type == "circle")
		{
			double radius;
			file >> radius;
			auto circPtr = std::make_unique<Circle>(radius);
			shapes.push_back(std::move(circPtr));
		}
	}
	printAllAreas(shapes);
}