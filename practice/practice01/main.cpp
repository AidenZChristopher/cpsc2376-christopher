/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.

Main use of AI: creating checkers when needed
*/

#include "Functions.h"
#include <iostream>

int main()
{

    Functions func;

    while (true)
    {
        func.displayMenu();
        func.setChoice();

        if (func.choice == 1) //add
        {
            func.addNum();
        }
        else if (func.choice == 2) //print
        {
            func.printVector();
        }
        else if (func.choice == 3) //double 
        {
            func.doubleVector();
        }
        else if (func.choice == 4) //sum
        {
            func.calculateSum();
        }
        else if (func.choice == 5) //print multiples
        {
            func.printMultiples();
        }
    }
}
