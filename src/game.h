#ifndef GAME_H
#define GAME_H

#include "stdlib.h"
#include "card.h"
#include "raylib.h"

typedef enum
{
    MATCH_TO_ANSWER = 0
} Gamemode;

typedef struct
{
    int grid_size;
    int width;
    int height;
    int cell_size;
    Rectangle game_area;
    Card *cards;
    Gamemode mode;
} Game;

Game create_game(int, int, int, int);
void generate_cards_for_gamemode(Game *);
void cards_shuffle(Card *, size_t);

#endif // GAME_H