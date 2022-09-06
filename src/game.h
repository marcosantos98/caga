#ifndef GAME_H
#define GAME_H

typedef struct
{
    int grid_size;
    int width;
    int height;
    int cell_size;
} Game;

Game create_game(int, int, int, int);

#endif // GAME_H