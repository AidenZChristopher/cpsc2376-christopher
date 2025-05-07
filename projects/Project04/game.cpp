#include "game.h"

Game::Game()
    : board(rows, std::vector<char>(cols, ' ')),
    currentPlayer('X'),
    gameStatus(Status::Running)
{
}

void Game::play(int col) {
    if (gameStatus != Status::Running) return;
    if (!isValidMove(col)) return;
    winningPositions.clear();
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
            int x = c * 100 + 50;
            int y = (r + 1) * 100 + 50;
            engine.drawRectangle(x, y, 95, 95, SDL_Color{ 200, 200, 200, 255 });
            char t = board[r][c];
            if (t == 'X') {
                engine.drawCircle(x, y, 40, SDL_Color{ 255,0,0,255 });
            }
            else if (t == 'O') {
                engine.drawCircle(x, y, 40, SDL_Color{ 255,255,0,255 });
            }
        }
    }
    if (gameStatus == Status::XWin || gameStatus == Status::OWin) {
        for (auto& p : winningPositions) {
            int cx = p.second * 100 + 50;
            int cy = (p.first + 1) * 100 + 50;
            engine.drawCircleOutline(cx, cy, 45, SDL_Color{ 0,0,0,255 });
        }
    }
}

void Game::reset() {
    board.assign(rows, std::vector<char>(cols, ' '));
    currentPlayer = 'X';
    gameStatus = Status::Running;
    winningPositions.clear();
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

bool Game::checkWin(int row, int col) {
    char sym = board[row][col];
    const int dirs[4][2] = { {1,0},{0,1},{1,1},{1,-1} };
    for (auto& d : dirs) {
        int dr = d[0], dc = d[1];
        std::vector<std::pair<int, int>> temp{ {row,col} };
        for (int i = 1; i < 4; i++) {
            int r = row + dr * i, c = col + dc * i;
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != sym) break;
            temp.emplace_back(r, c);
        }
        for (int i = 1; i < 4; i++) {
            int r = row - dr * i, c = col - dc * i;
            if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != sym) break;
            temp.emplace_back(r, c);
        }
        if (temp.size() >= 4) {
            winningPositions = temp;
            return true;
        }
    }
    return false;
}

const std::vector<std::pair<int, int>>& Game::getWinningPositions() const {
    return winningPositions;
}
