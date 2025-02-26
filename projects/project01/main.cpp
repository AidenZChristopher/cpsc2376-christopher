/*
This code may have been developed with the assistance of artificial intelligence (AI) tools, which were utilized to consolidate, edit, or refine the content.
However, these tools were employed solely to enhance clarity, efficiency, or structure.
All concepts, logic, and problem-solving approaches were originally conceived, reviewed, and fully understood by me,
ensuring that I can ethically and confidently claim this code as my own work.
AI tools were used as supplementary resources and did not replace my involvement or understanding in any aspect of the code's creation.
I am responsibility for this code's functionality and accuracy rests entirely with me.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <thread>
#include <chrono>

enum class Cell { BLANK, X, O };
enum class GameStatus { ONGOING, X_WON, O_WON, DRAW };

void line()
{
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void menu()
{
	std::cout << "Welcome to Connect Four!\n"
	"The game is played on a 7x6 board.\n"
	"Players take turns dropping their pieces into a column.\n"
    "The first player to get four of their pieces in a row wins!\n"
	"Player X goes first." << std::endl;
	line();
}

std::vector<std::vector<Cell>> makeBoard(int rows = 7, int columns = 6)
{
    return std::vector<std::vector<Cell>>(rows, std::vector<Cell>(columns, Cell::BLANK));
}

void horizontalBar(int columnCount)
{
    std::cout << "\n +";
    for (int column = 0; column < columnCount; column++)
    {
        std::cout << "---+";
    }
    std::cout << "\n";
}

void printBoard(const std::vector<std::vector<Cell>>& board)
{
    int rowCount = board.size();
    int columnCount = board.at(0).size();

    line();
    std::cout << "   ";
    for (int columnNumber = 1; columnNumber <= columnCount; columnNumber++)
    {
        std::cout << columnNumber << "   ";
    }

    horizontalBar(columnCount);
    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
    {
        std::cout << " |";
        for (int columnIndex = 0; columnIndex < columnCount; columnIndex++)
        {
            Cell cell = board.at(rowIndex).at(columnIndex);

            if (cell == Cell::O)
            {
                std::cout << " O ";
            }
            else if (cell == Cell::X)
            {
                std::cout << " X ";
            }
            else
            {
                std::cout << "   ";
            }

            std::cout << "|";
        }
        horizontalBar(columnCount);
    }
    line();
}

bool play(std::vector<std::vector<Cell>>& board, int col, Cell token)
{
    int width = board.at(0).size();
    int height = board.size();

    if (col >= width || col < 0)
    {
        return false;
    }

    // Find the lowest available row in the selected column
    for (int row = height - 1; row >= 0; row--)
    {
        if (board.at(row).at(col) == Cell::BLANK)
        {
            board.at(row).at(col) = token;
            return true;
        }
    }
    return false; // Column is full
}

Cell getCurrentToken(const std::vector<std::vector<Cell>>& board)
{
    int count = 0;
    for (const auto& row : board)
    {
        for (const auto& cell : row)
        {
            if (cell != Cell::BLANK)
            {
                count++;
            }
        }
    }
    return (count % 2 == 0) ? Cell::X : Cell::O;
}

GameStatus checkWin(const std::vector<std::vector<Cell>>& board)
{
    int rows = board.size();
    int cols = board[0].size();
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (board[r][c] == Cell::BLANK) continue;
            Cell token = board[r][c];
            if (c + 3 < cols && board[r][c + 1] == token && board[r][c + 2] == token && board[r][c + 3] == token)
            {
                return (token == Cell::X) ? GameStatus::X_WON : GameStatus::O_WON;
            }
            if (r + 3 < rows && board[r + 1][c] == token && board[r + 2][c] == token && board[r + 3][c] == token)
            {
                return (token == Cell::X) ? GameStatus::X_WON : GameStatus::O_WON;
            }
            if (r + 3 < rows && c + 3 < cols && board[r + 1][c + 1] == token && board[r + 2][c + 2] == token && board[r + 3][c + 3] == token)
            {
                return (token == Cell::X) ? GameStatus::X_WON : GameStatus::O_WON;
            }
            if (r - 3 >= 0 && c + 3 < cols && board[r - 1][c + 1] == token && board[r - 2][c + 2] == token && board[r - 3][c + 3] == token)
            {
                return (token == Cell::X) ? GameStatus::X_WON : GameStatus::O_WON;
            }
        }
    }
    for (const auto& row : board)
    {
        for (Cell cell : row)
        {
            if (cell == Cell::BLANK)
            {
                return GameStatus::ONGOING;
            }
        }
    }
    return GameStatus::DRAW;
}

int getPositiveInteger(const std::string& prompt)
{
    int value;
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        char extra;
        if (!(iss >> value) || (iss >> extra) || (value <= 0))
        {
            std::cout << "Invalid input! Please enter a positive integer.\n";
            continue;
        }
        return value;
    }
}

int exitOption()
{
    std::string input;
    std::cout << "Would you like to play again? (Y/N): ";
    std::getline(std::cin, input);
    if (input == "Y" || input == "y")
    {
        return 1;
    }
    else if (input == "N" || input == "n")
    {
        std::cout << "Goodbye!" << std::endl;
        return 2;
    }
    else
    {
        std::cout << "Invalid input! Please enter Y or N." << std::endl;
        exitOption();
    }
}


int main()
{
    line();
    menu();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto board = makeBoard();
    
    while (true)
    {
        printBoard(board);
        Cell token = getCurrentToken(board);


        GameStatus status = checkWin(board);
        if (status != GameStatus::ONGOING)
        {
            printBoard(board);

            line();
            if (status == GameStatus::X_WON)
            {
                std::cout << "Player X wins!\n";
            }
            else if (status == GameStatus::O_WON)
            {
                std::cout << "Player O wins!\n";
            }
            else
            {
                std::cout << "It's a draw!\n";
            }
      
			if (exitOption() == 1)
			{
				board = makeBoard();
				continue;
			}
			else
			{
				break;
			}
        }

        std::cout << "Player " << ((token == Cell::X) ? "X" : "O") << "'s turn!\n";

       
        while (true)
        {
            std::cout << "Which column would you like to place your piece in" << std::endl;
            int col = getPositiveInteger("Input: ");

            if (col < 1 || col > board.at(0).size())
            {
                std::cout << "Invalid column, try again.\n";
                continue;
            }

            if (play(board, col - 1, token))
            {
                break;
            }
            else
            {
                std::cout << "Column full, choose another.\n";
            }
            line();

        }
        line();
    }
}
