/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/

// practice04_3a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Objective:
//Use std::list<std::string> to create a simple task list with the following menu options :
//
//Add a task
//Remove a task
//Show tasks
//Exit
//Example UI :
//1. Add Task
//2. Remove Task
//3. Show Tasks
//4. Exit
//Choice : 1
//Enter task : Finish C++ assignment
//Task added!
//
//1. Add Task
//2. Remove Task
//3. Show Tasks
//4. Exit
//Choice : 3
//Tasks :
//    1. Finish C++ assignment
//
//    1. Add Task
//    2. Remove Task
//    3. Show Tasks
//    4. Exit
//    Choice : 2
//    Enter task number to remove : 1
//    Task removed!

#include <iostream>
#include <list>
#include <string>
#include <limits>

void showTasks(const std::list<std::string>& tasks)
{
    if (tasks.empty())
    {
        std::cout << "No tasks added.\n";
        return;
    }

    std::cout << "Tasks:\n";
    int index = 1;
    for (const auto& task : tasks)
    {
        std::cout << index++ << ". " << task << '\n';
    }
}

bool isValidNumber(int& num)
{
    std::cin >> num;
    if (std::cin.fail() || num <= 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void line()
{
	std::cout << "--------------------------------\n";
}

int main()
{
    std::list<std::string> tasks;

    line();
	std::cout << "To do List\n";
    line();
    std::cout << std::endl;

    while (true)
    {
        line();
        std::cout << "1. Add Task\n"
            << "2. Remove Task\n"
            << "3. Show Tasks\n"
            << "4. Exit\n";
            line();
        std::cout<< "Input: ";

        int input;
        while (!isValidNumber(input) || input > 4)
        {
            std::cout << "Invalid choice! Please enter a number between 1 and 4: ";
        }
        line();
        if (input == 1)
        {
            std::cin.ignore();
            std::cout << "Enter task: ";
            std::string task;
            std::getline(std::cin, task);
            tasks.push_back(task);
            line();
            std::cout << "Task added!\n";
            line();
        }
        else if (input == 2)
        {
            if (tasks.empty())
            {
                std::cout << "No tasks to remove.\n";
                continue;
            }

            showTasks(tasks);
            std::cout << "Enter task number to remove: ";

            int taskNum;
            while (!isValidNumber(taskNum) || taskNum > tasks.size())
            {
                std::cout << "Invalid number! Please enter a valid task number: ";
            }

			auto remover = tasks.begin(); // Iterator to the first task
			std::advance(remover, taskNum - 1); // Move the iterator to the selected task (-1 because vectors start at 0)
			tasks.erase(remover); // Remove the task
            line();
            std::cout << "Task removed!\n";
            line();
        }
        else if (input == 3)
        {
            showTasks(tasks);
        }
        else if (input == 4)
        {
            std::cout << "Goodbye!\n";
            line();
            break;
        }
    }

    return 0;
}
