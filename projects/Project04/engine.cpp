#include "Engine.h"
#include <iostream>
#include <stdexcept>

Engine::Engine(const std::string& title, int width, int height,
    const std::string& fontPath, int fontSize, const std::string& soundPath)
    : window(nullptr), renderer(nullptr), font(nullptr), sound(nullptr)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) throw std::runtime_error(SDL_GetError());
    if (TTF_Init() == -1) { SDL_Quit(); throw std::runtime_error(TTF_GetError()); }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) { TTF_Quit(); SDL_Quit(); throw std::runtime_error(Mix_GetError()); }
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) { Mix_Quit(); TTF_Quit(); SDL_Quit(); throw std::runtime_error(SDL_GetError()); }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) { SDL_DestroyWindow(window); Mix_Quit(); TTF_Quit(); SDL_Quit(); throw std::runtime_error(SDL_GetError()); }
    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); Mix_Quit(); TTF_Quit(); SDL_Quit(); throw std::runtime_error(TTF_GetError()); }
    sound = Mix_LoadWAV(soundPath.c_str());
}

Engine::~Engine() {
    if (sound) Mix_FreeChunk(sound);
    if (font) TTF_CloseFont(font);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

void Engine::drawCircle(int centerX, int centerY, int radius, SDL_Color color) {
    filledCircleRGBA(renderer, centerX, centerY, radius, color.r, color.g, color.b, color.a);
    aacircleRGBA(renderer, centerX, centerY, radius, color.r, color.g, color.b, color.a);
}

void Engine::drawCircleOutline(int centerX, int centerY, int radius, SDL_Color color) {
    aacircleRGBA(renderer, centerX, centerY, radius, color.r, color.g, color.b, color.a);
}

void Engine::drawRectangle(int centerX, int centerY, int rectWidth, int rectHeight, SDL_Color color) {
    SDL_Rect rect{ centerX - rectWidth / 2, centerY - rectHeight / 2, rectWidth, rectHeight };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
}

void Engine::drawText(const std::string& text, int centerX, int centerY, SDL_Color color) {
    SDL_Surface* surf = TTF_RenderText_Blended(font, text.c_str(), color);
    if (!surf) return;
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_Rect dst{ centerX - surf->w / 2, centerY - surf->h / 2, surf->w, surf->h };
    SDL_RenderCopy(renderer, tex, nullptr, &dst);
    SDL_DestroyTexture(tex);
    SDL_FreeSurface(surf);
}

void Engine::clear(SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void Engine::flip() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Engine::getRenderer() const {
    return renderer;
}

void Engine::playSound() {
    if (sound) Mix_PlayChannel(-1, sound, 0);
}
