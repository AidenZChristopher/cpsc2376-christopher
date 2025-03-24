#pragma once
#include <iostream>
#include <vector>

class Game
{
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;
    bool gameOver;

    void switchPlayer();
    bool checkWin(int row, int col);
    bool checkDirection(int row, int col, int dRow, int dCol);
    bool checkDraw();
    bool isValidMove(int col);
    int dropPiece(int col);

public:
    Game();
    void displayBoard() const;
    void playTurn(int col);
    bool isGameOver() const;
    char getWinner() const;
    void reset();
    int validInput();
    char validYesNo();
};

