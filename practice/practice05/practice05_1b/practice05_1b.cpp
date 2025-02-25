/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/

/*
1b. Write a program that takes user input for a list of integers, stores them in a std::vector, 
and prints them in reverse order using iterators.
*/
#include <iostream>
#include <vector>
#include <limits>

int main()
{
    std::vector<int> numbers;
    int num;

    std::cout << "Enter integers (enter 0 to stop):" << std::endl;

    while (true)
    {
        std::cout << "Integer: ";
        if (!(std::cin >> num))
        {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (num == 0)
        {
            break;
        }

        numbers.push_back(num);
    }

    if (numbers.empty())
    {
        std::cout << "No numbers entered.\n";
        return 0;
    }

    std::cout << "Numbers in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
