#include "Engine.h"

#include <iostream>

bool Engine::initializeSDL(const char *title, const int xpos, const int ypos, const int width, const int height,
                           const bool fullscreen) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Initialization Failed: " << SDL_GetError() << '\n';
        return false;
    }

    window_ = SDL_CreateWindow(title, xpos == -1 ? SDL_WINDOWPOS_CENTERED : xpos,
                               ypos == -1 ? SDL_WINDOWPOS_CENTERED : ypos, width, height,
                               fullscreen ? SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN);
    if (!window_) {
        std::cerr << "Window Creation Failed: " << SDL_GetError() << '\n';
        return false;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        std::cerr << "Renderer Creation Failed: " << SDL_GetError() << '\n';
        return false;
    }

    return true;
}
