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
#include "Fraction.h"
#include "MixedFraction.h"
#include <limits>

int main() {
    Fraction currentFraction(0, 1); // The current fraction starts as 0/1
    int choice;
    int num, den, whole, numerator, denominator;

    while (true) {
        // Display the current fraction
        std::cout << "\nCurrent Fraction: " << currentFraction << std::endl;

        // Display menu
        std::cout << "\nOptions:\n";
        std::cout << "1. Enter a fraction manually\n";
        std::cout << "2. Add a fraction\n";
        std::cout << "3. Subtract a fraction\n";
        std::cout << "4. Multiply by a fraction\n";
        std::cout << "5. Divide by a fraction\n";
        std::cout << "6. Display as Mixed Fraction\n";
        std::cout << "7. Clear Fraction\n";
        std::cout << "8. Exit\n";
        std::cout << "Choose an option: ";

        // Get user input
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore leftover input

        if (choice == 1) {
            // Enter a fraction manually
            std::cout << "Enter numerator: ";
            std::cin >> num;
            std::cout << "Enter denominator: ";
            std::cin >> den;

            if (den == 0) {
                std::cout << "Error: Denominator cannot be zero.\n";
            }
            else {
                currentFraction.setNum(num);
                currentFraction.setDen(den);
                currentFraction.simplify();  // Simplify after setting the fraction
            }
        }
        else if (choice == 2) {
            // Add a fraction
            std::cout << "Enter numerator: ";
            std::cin >> num;
            std::cout << "Enter denominator: ";
            std::cin >> den;

            if (den == 0) {
                std::cout << "Error: Denominator cannot be zero.\n";
            }
            else {
                currentFraction = currentFraction + Fraction(num, den);
                currentFraction.simplify();  // Simplify the result
            }
        }
        else if (choice == 3) {
            // Subtract a fraction
            std::cout << "Enter numerator: ";
            std::cin >> num;
            std::cout << "Enter denominator: ";
            std::cin >> den;

            if (den == 0) {
                std::cout << "Error: Denominator cannot be zero.\n";
            }
            else {
                currentFraction = currentFraction - Fraction(num, den);
                currentFraction.simplify();  // Simplify the result
            }
        }
        else if (choice == 4) {
            // Multiply by a fraction
            std::cout << "Enter numerator: ";
            std::cin >> num;
            std::cout << "Enter denominator: ";
            std::cin >> den;

            if (den == 0) {
                std::cout << "Error: Denominator cannot be zero.\n";
            }
            else {
                currentFraction = currentFraction * Fraction(num, den);
                currentFraction.simplify();  // Simplify the result
            }
        }
        else if (choice == 5) {
            // Divide by a fraction
            std::cout << "Enter numerator: ";
            std::cin >> num;
            std::cout << "Enter denominator: ";
            std::cin >> den;

            if (den == 0) {
                std::cout << "Error: Denominator cannot be zero.\n";
            }
            else if (num == 0) {
                std::cout << "Error: Cannot divide by a fraction with numerator zero.\n";
            }
            else {
                currentFraction = currentFraction / Fraction(num, den);
                currentFraction.simplify();  // Simplify the result
            }
        }
        else if (choice == 6) {
            // Display as Mixed Fraction
            MixedFraction mixed(currentFraction);
            std::cout << "Mixed Fraction: " << mixed << std::endl;
        }
        else if (choice == 7) {
            // Clear Fraction (reset to 0/1)
            currentFraction = Fraction(0, 1);
            std::cout << "Fraction cleared.\n";
        }
        else if (choice == 8) {
            // Exit the program
            std::cout << "Exiting program.\n";
            return 0;
        }
        else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
