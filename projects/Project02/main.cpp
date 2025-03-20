#include "game.h"

int main()
{
    Game game;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        int col;

        while (!game.isGameOver())
        {
            game.displayBoard();
            std::cout << "Player " << (game.getWinner() == ' ' ? 'X' : 'O') << ", enter column (1-7): ";

            while (!(std::cin >> col) || col < 1 || col > 7)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Enter a column number (1-7): ";
            }

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
        std::cin >> choice;

        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Enter 'y' or 'n': ";
            std::cin >> choice;
        }

        if (choice == 'y' || choice == 'Y')
        {
            game.reset();
        }
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
