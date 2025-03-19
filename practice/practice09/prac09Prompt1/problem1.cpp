#include <iostream>
#include <string>
#include <limits>

bool isValidPotionChoice(const std::string& choice)
{
    return choice == "Red" || choice == "red" || choice == "Blue" || choice == "blue" || choice == "Done" || choice == "done";
}

bool isValidMillilitersInput(float& amount)
{
    if (std::cin.fail() || amount < 0) {
        std::cin.clear();  // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
        return false;
    }
    return true;
}

void line()
{
    std::cout << "------------------------------------------------------------------------------------" << std::endl;
}

int main()
{
    float redPotion{ 0.0f };
    float bluePotion{ 0.0f };
    float* flask{ nullptr };
    std::string choice;
    float amount;

    while (true) {
        line();
        std::cout << "Which potion to add liquid to (Red or Blue)? (Type 'Done' to finish): ";
        std::cin >> choice;



        while (!isValidPotionChoice(choice)) {
            line();
            std::cout << "Invalid input. Please type 'Red', 'Blue', or 'Done': ";
            std::cin >> choice;
        }

        if (choice == "Done" || choice == "done") {
            break;
        }
        if (choice == "Red" || choice == "red") {
            flask = &redPotion;
        }
        else {
            flask = &bluePotion;
        }

        line();
        std::cout << "How many milliliters to add? ";

        while (true) {
            std::cin >> amount;

            if (isValidMillilitersInput(amount)) {
                break;
            }
            else {
                line();
                std::cout << "Invalid amount. Please enter a positive number: ";
            }
        }

        *flask += amount;
        line();
        std::cout << "Red potion level: " << redPotion << " mL\n";
        std::cout << "Blue potion level: " << bluePotion << " mL\n";
    }

    return 0;
}