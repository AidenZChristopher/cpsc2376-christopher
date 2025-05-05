// game.cpp
#include "game.h"

Game::Game() : board(rows, std::vector<char>(cols, ' ')), currentPlayer('X'), gameStatus(Status::Running) {}

void Game::play(int col) {
    if (gameStatus != Status::Running) return;
    if (!isValidMove(col)) return;
    int row = dropPiece(col);
    if (checkWin(row, col)) {
        gameStatus = (currentPlayer == 'X') ? Status::XWin : Status::OWin;
    }
    else if (checkDraw()) {
        gameStatus = Status::Draw;
    }
    else {
        switchPlayer();
    }
}

Game::Status Game::status() const {
    return gameStatus;
}

void Game::draw(Engine& engine) const {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int centerX = c * 100 + 50;
            int centerY = (r + 1) * 100 + 50;
            engine.drawRectangle(centerX, centerY, 95, 95, SDL_Color{ 0, 0, 255, 255 });
            char t = board[r][c];
            if (t == 'X') {
                engine.drawCircle(centerX, centerY, 40, SDL_Color{ 255, 0, 0, 255 });
            }
            else if (t == 'O') {
                engine.drawCircle(centerX, centerY, 40, SDL_Color{ 255, 255, 0, 255 });
            }
        }
    }
}

void Game::reset() {
    board.assign(rows, std::vector<char>(cols, ' '));
    currentPlayer = 'X';
    gameStatus = Status::Running;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool Game::isValidMove(int col) const {
    return col >= 0 && col < cols && board[0][col] == ' ';
}

int Game::dropPiece(int col) {
    for (int r = rows - 1; r >= 0; r--) {
        if (board[r][col] == ' ') {
            board[r][col] = currentPlayer;
            return r;
        }
    }
    return -1;
}

bool Game::checkDraw() const {
    for (int c = 0; c < cols; c++) {
        if (board[0][c] == ' ') return false;
    }
    return true;
}

bool Game::checkWin(int row, int col) const {
    return checkDirection(row, col, 1, 0)
        || checkDirection(row, col, 0, 1)
        || checkDirection(row, col, 1, 1)
        || checkDirection(row, col, 1, -1);
}

bool Game::checkDirection(int row, int col, int dRow, int dCol) const {
    char sym = board[row][col];
    int count = 1;
    for (int i = 1; i < 4; i++) {
        int r = row + i * dRow;
        int c = col + i * dCol;
        if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == sym) {
            count++;
        }
        else break;
    }
    for (int i = 1; i < 4; i++) {
        int r = row - i * dRow;
        int c = col - i * dCol;
        if (r >= 0 && r < rows && c >= 0 && c < cols && board[r][c] == sym) {
            count++;
        }
        else break;
    }
    return count >= 4;
}
