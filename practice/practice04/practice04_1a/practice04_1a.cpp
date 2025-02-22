/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/

// practice04_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Modify convertTemperature so the menu allows choosing Celsius → Fahrenheit or Fahrenheit → Celsius, but both use the same function.
//
//convertTemperature(double temp, char scale = 'F')
//'F': Converts Celsius to Fahrenheit
//'C' : Converts Fahrenheit to Celsius
//The UI offers both options, but both call the same function.

//Example output
//1. Convert Celsius to Fahrenheit
//2. Convert Fahrenheit to Celsius
//Choose an option : 1
//Enter temperature : 100
//Converted : 212.00°F
//
//1. Convert Celsius to Fahrenheit
//2. Convert Fahrenheit to Celsius
//Choose an option : 2
//Enter temperature : 212
//Converted : 100.00°C

#include <iostream>
#include <limits>

void convertTemperature(double temp, char scale = 'F')
{
    if (scale == 'F')
    {
        double result = (temp * 9.0 / 5.0) + 32;
        std::cout << "Converted : " << result << " Degrees F\n";
    }
    else if (scale == 'C')
    {
        double result = (temp - 32) * 5.0 / 9.0;
        std::cout << "Converted : " << result << " Degrees C\n";
    }
}

bool isValidNumber(double& num)
{
    std::cin >> num;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    return true;
}

bool isValidOption(int& option)
{
    std::cin >> option;
    if (std::cin.fail() || (option != 1 && option != 2))
    {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    return true;
}

int main()
{
    while (true)
    {
        std::cout << "Temperature Converter\n"
            << "1. Convert Celsius to Fahrenheit\n"
            << "2. Convert Fahrenheit to Celsius\n"
            << "Input: ";
        int input;
        while (!isValidOption(input)) // Validate menu input
        {
            std::cout << "Invalid choice! Please enter 1 or 2: ";
        }

        double temp;
        std::cout << "Enter temperature: ";
        while (!isValidNumber(temp)) // Validate temperature input
        {
            std::cout << "Invalid temperature! Please enter a valid number: ";
        }

        if (input == 1)
        {
            convertTemperature(temp, 'F');
        }
        else if (input == 2)
        {
            convertTemperature(temp, 'C');
        }
    }
}

