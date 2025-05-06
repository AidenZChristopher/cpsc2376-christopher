#include <iostream>
#include <memory>
#include "FilterStrategy.h"
#include "ReverseFilter.h"
#include "UppercaseFilter.h"
#include "VowelRemover.h"
#include "CensorFilter.h"

class ReverseFilter;
class UppercaseFilter;
class VowelRemover;
class CensorFilter;

int main()
{
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    bool running = true;

    while (running)
    {
        std::cout << "\nChoose a filter:\n";
        std::cout << "1. Reverse\n2. Uppercase\n3. Remove vowels\n4. Censor bad words\n5. Quit\n";
        std::cout << "Enter choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        std::unique_ptr<FilterStrategy> strategy;

        if (choice == 1)
        {
            strategy = std::make_unique<ReverseFilter>();
        }
        else if (choice == 2)
        {
            strategy = std::make_unique<UppercaseFilter>();
        }
        else if (choice == 3)
        {
            strategy = std::make_unique<VowelRemover>();
        }
        else if (choice == 4)
        {
            strategy = std::make_unique<CensorFilter>();
        }
        else if (choice == 5)
        {
            running = false;
        }
        else
        {
            std::cout << "Invalid choice.\n";
        }

        if (strategy)
        {
            std::string result = strategy->apply(input);
            std::cout << "Filtered text: " << result << "\n";
        }
    }

    return 0;
}