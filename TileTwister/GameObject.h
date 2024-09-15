#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>

class GameObject {
public:
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif
