#ifndef GAME_H
#define GAME_H

#include "stdlib.h"
#include "card.h"
#include "raylib.h"
typedef struct
{
    int grid_size;
    int width;
    int height;
    int cell_size;
    Rectangle game_area;
    Card *cards;
} Game;

Game create_game(int, int, int, int);

#endif // GAME_H