#pragma once

#include <vector>

class Functions
{
private:

public:
    std::vector<int> numbers;

    int choice;
    int total;


    void displayMenu();

    int setChoice();

    //functions
    void addNum();

    void printVector() const;

    void doubleVector();

    void calculateSum();

    void printMultiples();
};
