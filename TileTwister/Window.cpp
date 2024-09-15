#include "Window.h"
#include <iostream>

Window::Window() : window(nullptr), renderer(nullptr) {}

Window::~Window() {}

bool Window::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Window::clear() {
    if (renderer) {
        SDL_RenderClear(renderer);
    }
}

void Window::present() {
    SDL_RenderPresent(renderer);
}

void Window::cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

SDL_Renderer* Window::getRenderer() {
    return renderer;
}
