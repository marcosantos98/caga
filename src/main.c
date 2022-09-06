#include "stdio.h"
#include "stdlib.h"

#include "raylib.h"
#include "game.h"

#include "screen.h"
#include "game_screen.h"

#define WIDTH 800
#define HEIGHT 800

Screen *master_screen = {0};

Screen test = {
    .init = game_init,
    .render = game_render,
    .dispose = game_dispose,
};

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "caga");
    SetTargetFPS(60);

    int cell = 800 / 10;
    int cols = 800 / (cell + 10);

    Game game = create_game(cols, WIDTH, HEIGHT, cell);

    master_screen = &test;

    master_screen->init(&game);

    while (!WindowShouldClose())
    {
        master_screen->render(GetFrameTime());
    }

    master_screen->dispose();

    free(game.cards);

    CloseWindow();
}