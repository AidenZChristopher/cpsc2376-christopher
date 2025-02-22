/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/

//Prompt 2a: Calculator(Support Both int and double)
//Objective :
//    Modify calculate<T> to handle both int and double input.
//
//    If the user enters a decimal, it uses double.
//    Otherwise, it uses int.
// 
//    Example UI :
//Enter first number : 5
//Enter second number : 2
//Enter operation(+, -, *, / ) : *
//Result : 10
//
//Enter first number : 5.5
//Enter second number : 2
//Enter operation(+, -, *, / ) : *
//Result : 11.00

#include <iostream>
#include <limits>

template <typename T>
T calculate(T num1, T num2, char operation)
{
    if (operation == '+')
        return num1 + num2;
    else if (operation == '-')
        return num1 - num2;
    else if (operation == '*')
        return num1 * num2;
    else if (operation == '/')
        return num1 / num2;
    return 0;
}

bool isValidNumber(double& num)
{
    std::cin >> num;
    if (std::cin.fail())
    {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        return false;
    }
    return true;
}

bool isValidOperation(char& operation)
{
    std::cin >> operation;
    return (operation == '+' || operation == '-' || operation == '*' || operation == '/');
}

void line()
{
	std::cout << "--------------------------------\n";
}

int main()
{
    line();
	std::cout << "Calculator App\n";
    line();
    std::cout << std::endl;
    while (true)
    {
        line();
        std::cout << "Enter first number : ";
        double num1;
        while (!isValidNumber(num1))
        {
            std::cout << "Invalid input! Please enter a valid number: ";
        }
        line();
        std::cout << "Enter operation(+, -, *, / ) : ";
        char operation;
        while (!isValidOperation(operation))
        {
            std::cout << "Invalid operation! Please enter one of (+, -, *, /): ";
        }
        line();
        std::cout << "Enter second number : ";
        double num2;
        while (!isValidNumber(num2))
        {
            std::cout << "Invalid input! Please enter a valid number: ";
        }
        line();
        if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2))
        {
            // Use int if both numbers are integers
            int result = calculate<int>(static_cast<int>(num1), static_cast<int>(num2), operation);
            std::cout << "Result : " << result << "\n";
        }
        else
        {
            // Use double if any number is a decimal
            double result = calculate<double>(num1, num2, operation);
            std::cout << "Result : " << result << "\n";
        }
        line();
        std::cout << std::endl;
    }
}


