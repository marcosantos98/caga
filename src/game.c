#include "game.h"

Game create_game(int grid_sz, int w, int h, int cell_sz)
{
    return (Game){
        .grid_size = grid_sz,
        .width = w,
        .height = h,
        .cell_size = cell_sz,
        .game_area = (Rectangle){
            .x = (w / 2) - ((((cell_sz + 10) * grid_sz) + 10) / 2),
            .y = (h / 2) - ((((cell_sz + 10) * grid_sz) + 10) / 2),
            .width = (((cell_sz + 10) * grid_sz) + 10),
            .height = (((cell_sz + 10) * grid_sz) + 10),
        },
        .cards = malloc((grid_sz * grid_sz) * sizeof(Card)),
    };
}
