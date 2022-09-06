#include "stdio.h"
#include "stdlib.h"

#include "raylib.h"
#include "game.h"

#include "screen.h"
#include "test_screen.h"

#define WIDTH 800
#define HEIGHT 800

Screen *master_screen = {0};

Screen test = {
    .init = test_init,
    .render = test_render,
    .dispose = test_dispose,
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

    CloseWindow();
}