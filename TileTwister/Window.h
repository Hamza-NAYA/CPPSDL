#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    Window();
    ~Window();

    bool init(const char* title, int width, int height);
    void clear();
    void present();
    void cleanup();
    SDL_Renderer* getRenderer();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif
