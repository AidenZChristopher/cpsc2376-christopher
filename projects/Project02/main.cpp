/*
This code may have been developed with the assistance of artificial intelligence (AI) tools,
which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/

#include "game.h"

int main()
{
    Game game;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        while (!game.isGameOver())
        {
            game.displayBoard();
            std::cout << "Player " << (game.getWinner() == ' ' ? 'X' : 'O') << ", enter column (1-7): ";

            int col = game.validInput();
            game.playTurn(col - 1);  // Adjust for 0-based indexing
        }

        game.displayBoard();

        if (game.getWinner() != ' ')
        {
            std::cout << "Player " << game.getWinner() << " wins!\n";
        }
        else
        {
            std::cout << "It's a draw!\n";
        }

        std::cout << "Do you want to play again? (y/n): ";
        choice = game.validYesNo();

        if (choice == 'y' || choice == 'Y')
        {
            game.reset();
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
