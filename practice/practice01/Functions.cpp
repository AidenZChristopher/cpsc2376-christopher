#include "functions.h"
#include <iostream>

void Functions::displayMenu()
{
    std::cout << "\nMenu:\n"
        << "1. Add an item to a list\n"
        << "2. Print the list\n"
        << "3. Double all numbers\n"
        << "4. Find the sum of all the numbers\n"
        << "5. Print multiples of a selected number\n"
        << "6. Exit\n";
}

int Functions::setChoice()
{
    std::cout << "Enter your input: ";
    while (!(std::cin >> choice))
    {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter a valid choice: ";
    }
    return choice;
}

void Functions::addNum()
{
    int num;
    std::cout << "\nInput a number: ";
    while (!(std::cin >> num))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer: ";
    }
    numbers.push_back(num);
}

void Functions::printVector() const
{
    if (numbers.empty())
    {
        std::cout << "\nThe vector is empty.\n";
    }
    else
    {
        std::cout << "\nVector contents: ";
        for (const int& num : numbers)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

void Functions::doubleVector()
{
    for (int& num : numbers)
    {
        num *= 2;
    }
    std::cout << "\nAll numbers in the vector have been doubled.\n";
}

void Functions::calculateSum()
{
    total = 0; // Reset total to 0
    for (int num : numbers)
    {
        total += num;
    }
    std::cout << "\nThe sum is " << total << std::endl;
}

void Functions::printMultiples()
{
    int userNum;
    std::cout << "\nWhat values would you like to check against? ";
    while (!(std::cin >> userNum) || userNum == 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a non-zero integer: ";
    }
    std::cout << "\nMultiples of " << userNum << ": ";
    bool found = false;
    for (int num : numbers)
    {
        if (num % userNum == 0)
        {
            std::cout << num << " ";
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "None";
    }
    std::cout << std::endl;
}
