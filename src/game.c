#include "game.h"

Game create_game(int grid_sz, int w, int h, int cell_sz)
{
    return (Game){
        .grid_size = grid_sz,
        .width = w,
        .height = h,
        .cell_size = cell_sz,
    };
}
