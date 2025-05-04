// main.cpp
#include "Engine.h"
#include "game.h"
#include <SDL2/SDL.h>

int main() {
    Engine engine("Connect Four", 700, 700);
    Game game;
    bool running = true;
    int selectedCol = 0;

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
                else if ((key == SDLK_r || key == SDLK_R)) {
                    game.reset();
                    selectedCol = 0;
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

        engine.clear(SDL_Color{ 0, 0, 0, 255 });
        game.draw(engine);

        if (game.status() == Game::Status::XWin) {
            engine.drawText("X Wins!", 350, 50, SDL_Color{ 255, 255, 255, 255 });
        }
        else if (game.status() == Game::Status::OWin) {
            engine.drawText("O Wins!", 350, 50, SDL_Color{ 255, 255, 255, 255 });
        }
        else if (game.status() == Game::Status::Draw) {
            engine.drawText("Draw!", 350, 50, SDL_Color{ 255, 255, 255, 255 });
        }

        engine.drawCircle(selectedCol * 100 + 50, 50, 15, SDL_Color{ 255, 255, 255, 255 });
        engine.drawText("Press R to restart or Esc to quit", 350, 680, SDL_Color{ 255, 255, 255, 255 });
        engine.flip();
        SDL_Delay(16);
    }

    return 0;
}
