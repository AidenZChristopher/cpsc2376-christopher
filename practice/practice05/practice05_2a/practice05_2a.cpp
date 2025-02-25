/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, 
which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/

/*
2a. Write a program that calculates the sum of all elements in a vector using std::accumulate. E
xtend the program to also calculate the product of all elements in the vector and print both results.
*/
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

int main()
{
    std::vector<int> numbers;
    int num;

    std::cout << "Begin entering integers, and when you are done, enter 0" << std::endl;

    while (true)
    {
        std::cout << "Enter a number: ";

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

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, [](int total, int n)
        {
            return total * n;
        });

    std::cout << "Sum of elements: " << sum << std::endl;
    std::cout << "Product of elements: " << product << std::endl;

    return 0;
}
