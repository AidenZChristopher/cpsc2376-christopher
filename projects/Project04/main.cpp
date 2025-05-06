// main.cpp
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include "Engine.h"
#include "game.h"

int main() {
    Engine engine("Connect Four", 700, 700,
        "Ubuntu-Bold.ttf",
        24,
        "move.wav");
    Game game;
    bool running = true;
    int selectedCol = 0;
    int scoreX = 0;
    int scoreO = 0;
    Game::Status previousStatus = Game::Status::Running;

    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            else if (e.type == SDL_KEYDOWN) {
                auto key = e.key.keysym.sym;
                if (key == SDLK_LEFT && game.status() == Game::Status::Running && selectedCol > 0) {
                    selectedCol--;
                }
                else if (key == SDLK_RIGHT && game.status() == Game::Status::Running && selectedCol < 6) {
                    selectedCol++;
                }
                else if (key == SDLK_RETURN && game.status() == Game::Status::Running) {
                    game.play(selectedCol);
                    engine.playSound();
                }
                else if (key == SDLK_r) {
                    game.reset();
                    selectedCol = 0;
                    previousStatus = Game::Status::Running;
                }
                else if (key == SDLK_ESCAPE) {
                    running = false;
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && game.status() == Game::Status::Running) {
                int col = e.button.x / 100;
                if (col >= 0 && col < 7) {
                    game.play(col);
                    engine.playSound();
                }
            }
        }

        Game::Status status = game.status();
        if (previousStatus == Game::Status::Running && status == Game::Status::XWin) {
            scoreX++;
        }
        if (previousStatus == Game::Status::Running && status == Game::Status::OWin) {
            scoreO++;
        }
        previousStatus = status;

        engine.clear(SDL_Color{ 0, 0, 0, 255 });
        game.draw(engine);

        engine.drawText("Player 1: " + std::to_string(scoreX), 70, 10, SDL_Color{ 255, 0, 0, 255 });
        engine.drawText("Player 2: " + std::to_string(scoreO), 610, 10, SDL_Color{ 255, 255, 0, 255 });

        if (status == Game::Status::XWin) {
            engine.drawText("Player 1 Wins!", 350, 50, SDL_Color{ 255, 255, 255, 255 });
        }
        else if (status == Game::Status::OWin) {
            engine.drawText("Player 2 Wins!", 350, 50, SDL_Color{ 255, 255, 255, 255 });
        }
        else if (status == Game::Status::Draw) {
            engine.drawText("Draw!", 350, 50, SDL_Color{ 255, 255, 255, 255 });
        }

        engine.drawCircle(selectedCol * 100 + 50, 50, 15, SDL_Color{ 255, 255, 255, 255 });
        engine.drawText("Press R to restart or Esc to quit", 340, 10, SDL_Color{ 255, 255, 255, 255 });
        engine.flip();
        SDL_Delay(16);
    }

    return 0;
}

