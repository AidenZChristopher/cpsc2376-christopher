// practice02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/
#include <iostream>
#include <fstream>
#include <iomanip>

int getPositiveInteger(std::string prompt)
{
    double num;
    while (true)
    {
        std::cout << prompt;
        std::cin >> num;

        if (std::cin.fail() || num <= 0 || std::floor(num) != num)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 - 4.\n";

        }
        else
        {
            return static_cast<int>(num);
        }
    }
}

void displayMenu()
{
    std::cout << "\nMenu:" << std::endl;
    std::cout << "1. Check Balance" << std::endl;
    std::cout << "2. Deposit Money" << std::endl;
    std::cout << "3. Withdraw Money" << std::endl;
    std::cout << "4. Exit" << std::endl;
}

double initBalance()
{
    std::ifstream file("accountBalance.txt");
    double balance;

    if (!file)
    {
        std::cout << "Initializing account with $100.00\n";
        balance = 100.00;
        std::ofstream newFile("accountBalance.txt");
        newFile << balance;
    }
    else
    {
        file >> balance;
        std::cout << "Your current balance is: $" << balance << '\n';
    }

    return balance;
}

double readBalance()
{
    std::ifstream file("accountBalance.txt");

    if (file.fail())
    {
        std::cerr << "Error: Failed to read balance from file.\n";
        exit(1);
    }

    double balance;
    file >> balance;

    std::cout << "Your current balance is $" << balance << std::endl;
    return balance;
}

void deposit(double& balance)
{
    double amount;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;

    if (std::cin.fail() || amount <= 0)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Error: Deposit amount must be positive." << std::endl;
        return;
    }

    balance += amount;

    std::ofstream file("accountBalance.txt");
    if (!file)
    {
        std::cerr << "Error: Unable to update balance." << std::endl;
        exit(1);
    }

    file << std::fixed << std::setprecision(2) << balance;
    std::cout << "Deposit successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

void withdraw(double& balance)
{
    double amount;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;

    if (std::cin.fail() || amount <= 0)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Error: Withdrawal amount must be positive." << std::endl;
        return;
    }

    if (amount > balance)
    {
        std::cout << "Error: Insufficient funds. Your balance is $" << std::fixed << std::setprecision(2) << balance << std::endl;
        return;
    }

    balance -= amount;

    std::ofstream file("accountBalance.txt");
    if (!file)
    {
        std::cerr << "Error: Unable to update balance." << std::endl;
        exit(1);
    }
    file << std::fixed << std::setprecision(2) << balance;
    std::cout << "Withdrawal successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

int main()
{
    std::cout << "Welcome to Aiden's Bank!\nWhat would you like to do today?\n" << std::endl;
    double balance = initBalance();

    while (true)
    {
        displayMenu();
        int choice = getPositiveInteger("Enter Your Choie: ");

        if (choice == 1) //Check Balance
        {
            balance = readBalance();
        }
        else if (choice == 2) //Deposit
        {
            deposit(balance);
        }
        else if (choice == 3) //Withdrawal 
        {
            withdraw(balance);
        }
        else if (choice == 4) //Exit
        {
            std::cout << "Thank you for using the bank system!" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
