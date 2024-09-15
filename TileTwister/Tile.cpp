#include "Tile.h"
#include <SDL2/SDL.h>

Tile::Tile(int val) : value(val) {}

void Tile::render(SDL_Renderer* renderer) {
    SDL_Color color = getColorForValue(value);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);

    // Dessiner la tuile en fonction de sa position et de sa valeur
    // Ici, tu peux ajouter la logique pour positionner la tuile sur l'écran.
}

void Tile::setValue(int val) {
    value = val;
}

int Tile::getValue() const {
    return value;
}

SDL_Color Tile::getColorForValue(int val) {
    switch (val) {
    case 2: return { 255, 255, 224, 255 }; // Jaune clair
    case 4: return { 255, 255, 192, 255 }; // Jaune plus foncé
    case 8: return { 255, 223, 186, 255 }; // Orange clair
    case 16: return { 255, 183, 178, 255 }; // Orange foncé
    case 32: return { 255, 165, 0, 255 };  // Orange
    case 64: return { 255, 140, 0, 255 };  // Orange profond
    default: return { 205, 193, 180, 255 }; // Gris pour une tuile vide
    }
}
