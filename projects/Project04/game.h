#pragma once
#include <vector>
#include <utility>
#include "Engine.h"

class Game {
public:
    enum class Status { Running, XWin, OWin, Draw };
    Game();
    void play(int col);
    Status status() const;
    void draw(Engine& engine) const;
    void reset();
    const std::vector<std::pair<int, int>>& getWinningPositions() const;

private:
    static constexpr int rows = 6;
    static constexpr int cols = 7;
    std::vector<std::vector<char>> board;
    char currentPlayer;
    Status gameStatus;
    std::vector<std::pair<int, int>> winningPositions;
    void switchPlayer();
    bool checkWin(int row, int col);
    bool checkDraw() const;
    bool isValidMove(int col) const;
    int dropPiece(int col);
};
