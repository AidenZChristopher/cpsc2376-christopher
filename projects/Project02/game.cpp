#include "game.h"

Game::Game() : board(6, std::vector<char>(7, ' ')), currentPlayer('X'), gameOver(false) {}

void Game::displayBoard() const
{
    std::cout << "   1   2   3   4   5   6   7  \n";
    std::cout << " +---+---+---+---+---+---+---+\n";

    for (const auto& row : board)
    {
        std::cout << " |";
        for (char cell : row)
        {
            std::cout << " " << cell << " |";
        }
        std::cout << "\n +---+---+---+---+---+---+---+\n";
    }
}

bool Game::isValidMove(int col)
{
    return col >= 0 && col < 7 && board[0][col] == ' ';
}

int Game::dropPiece(int col)
{
    for (int row = 5; row >= 0; --row)
    {
        if (board[row][col] == ' ')
        {
            board[row][col] = currentPlayer;
            return row;
        }
    }
    return -1;
}

void Game::playTurn(int col)
{
    if (!isValidMove(col))
    {
        std::cout << "Invalid move. Try again.\n";
        return;
    }

    int row = dropPiece(col);

    if (checkWin(row, col))
    {
        gameOver = true;
    }
    else if (checkDraw())
    {
        gameOver = true;
        currentPlayer = ' ';
    }
    else
    {
        switchPlayer();
    }
}

void Game::switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool Game::checkWin(int row, int col)
{
    return checkDirection(row, col, 1, 0) ||
        checkDirection(row, col, 0, 1) ||
        checkDirection(row, col, 1, 1) ||
        checkDirection(row, col, 1, -1);
}

bool Game::checkDirection(int row, int col, int dRow, int dCol)
{
    char symbol = board[row][col];
    int count = 1;

    for (int i = 1; i < 4; ++i)
    {
        int r = row + i * dRow, c = col + i * dCol;
        if (r >= 0 && r < 6 && c >= 0 && c < 7 && board[r][c] == symbol)
            count++;
        else
            break;
    }

    for (int i = 1; i < 4; ++i)
    {
        int r = row - i * dRow, c = col - i * dCol;
        if (r >= 0 && r < 6 && c >= 0 && c < 7 && board[r][c] == symbol)
            count++;
        else
            break;
    }

    return count >= 4;
}

bool Game::checkDraw()
{
    for (int col = 0; col < 7; ++col)
    {
        if (board[0][col] == ' ') return false;
    }
    return true;
}

bool Game::isGameOver() const
{
    return gameOver;
}

char Game::getWinner() const
{
    return gameOver && currentPlayer != ' ' ? currentPlayer : ' ';
}

void Game::reset()
{
    board.assign(6, std::vector<char>(7, ' '));
    currentPlayer = 'X';
    gameOver = false;
}
