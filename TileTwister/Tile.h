#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include <SDL2/SDL.h>

class Tile : public GameObject {
public:
    Tile(int value = 0);
    void render(SDL_Renderer* renderer) override;
    void setValue(int val);
    int getValue() const;

private:
    int value;
    SDL_Color getColorForValue(int val);
};

#endif
