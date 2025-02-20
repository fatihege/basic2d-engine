#pragma once

#include <SDL.h>

class Engine {
    bool initializeSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void processEvents();
    void update(float dt);
    void render();

    SDL_Window *window_ = nullptr;
    SDL_Renderer *renderer_ = nullptr;

    bool isRunning_ = true;

public:
    Engine();
    ~Engine();

    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void run();
    void shutdown();
};
