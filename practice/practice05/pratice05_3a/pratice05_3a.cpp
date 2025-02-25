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
3a.Write a program that prompts the user to enter a list of integers.Use std::for_each with a lambda function 
to print each element squared.Then, use a new lambda to help sum up all squared values using accumulate and 
print the result.
*/#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

int main()
{
    std::vector<int> numbers;
    int num;

    std::cout << "Begin entering integers, and when you are done, enter 0" << std::endl;

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

    std::cout << "Values Squared: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n)
        {
            std::cout << n * n << " ";
        });
    std::cout << std::endl;

    int sum_of_squares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int total, int n)
        {
            return total + n * n;
        });

    std::cout << "Sum of squared values: " << sum_of_squares << std::endl;

    return 0;
}
