// game.h
#pragma once
#include <vector>
#include "Engine.h"

class Game {
public:
    enum class Status { Running, XWin, OWin, Draw };

    Game();
    void play(int col);
    Status status() const;
    void draw(Engine& engine) const;
    void reset();

private:
    static constexpr int rows = 6;
    static constexpr int cols = 7;
    std::vector<std::vector<char>> board;
    char currentPlayer;
    Status gameStatus;

    void switchPlayer();
    bool checkWin(int row, int col) const;
    bool checkDirection(int row, int col, int dRow, int dCol) const;
    bool checkDraw() const;
    bool isValidMove(int col) const;
    int dropPiece(int col);
};
