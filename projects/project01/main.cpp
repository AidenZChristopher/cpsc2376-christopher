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

enum class Cell { BLANK, X, O };
enum class GameStatus { ONGOING, X_WON, O_WON, DRAW };

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
    int columnCount = board[0].size();

    std::cout << "   ";
    for (int columnNumber = 1; columnNumber <= columnCount; columnNumber++)
    {
        std::cout << columnNumber << "   ";
    }
    std::cout << "\n +";

    horizontalBar(columnCount);

    for (int rowIndex = 0; rowIndex < rowCount; rowIndex++)
    {
        std::cout << rowIndex + 1 << "|";
        for (int columnIndex = 0; columnIndex < columnCount; columnIndex++)
        {
            Cell cell = board[rowIndex][columnIndex];

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
}

bool play(std::vector<std::vector<Cell>>& board, int row, int col, Cell token)
{
    int width = board.at(0).size();
    int height = board.size();
    if (row >= height || row < 0 || col >= width || col < 0)
    {
        return false;
    }

    Cell& cell = board.at(row).at(col);
    if (cell != Cell::BLANK)
    {
        return false;
    }
    cell = token;
    return true;
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

int main()
{
    auto board = makeBoard();
    GameStatus status = GameStatus::ONGOING;

    while (status == GameStatus::ONGOING)
    {
        printBoard(board);
        Cell token = getCurrentToken(board);

        std::cout << "Player " << ((token == Cell::X) ? "X" : "O") << "'s turn!\n";

        int row, col;
        std::cout << "Row: ";
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;

        if (!play(board, row - 1, col - 1, token))
        {
            std::cout << "Invalid move, try again\n";
            continue;
        }

        status = checkWin(board);
    }

    printBoard(board);

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
}
