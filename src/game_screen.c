#include "game_screen.h"

#include "stdio.h"
#include "stdlib.h"
#include "card.h"

int match_A = -1;
int match_B = -1;

Game *ctx;

void game_init(Game *game)
{
    ctx = game;

    for (int i = 0; i < ctx->grid_size * ctx->grid_size; i++)
    {
        ctx->cards[i] = (Card){
            .index = i,
            .type = GetRandomValue(0, 1)};
    }
}

void game_render(float delta)
{
    (void)delta;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        click_card();
    }

    if (match_A != -1 && match_B != -1)
    {
        check_match();
    }

    BeginDrawing();
    ClearBackground(BLACK);

    int start_x = ctx->game_area.x + 10;
    int start_y = ctx->game_area.y + 10;
    int index = 0;
    for (int i = 0; i < ctx->grid_size; i++)
    {
        for (int j = 0; j < ctx->grid_size; j++)
        {
            DrawRectangle(start_x, start_y, ctx->cell_size, ctx->cell_size, ctx->cards[index].revelead ? GREEN : WHITE);
            char text[100];
            snprintf(text, 100, "%d", ctx->cards[index].type);
            DrawText(text, start_x, start_y + 22, 12, BLACK);
            snprintf(text, 100, "%d", index++);
            DrawText(text, start_x, start_y, 12, BLACK);
            start_x += (10 + ctx->cell_size); // 10 pad + 10 cell width
        }
        start_y += (10 + ctx->cell_size);
        start_x = ctx->game_area.x + 10; // 10 pad + 10 cell width
    }

    EndDrawing();
}

void game_dispose(void)
{
    printf("Dispose\n");
}

Color color_from_type(int type)
{
    switch (type)
    {
    case A:
        return BLUE;
    case B:
        return GREEN;
    default:
        exit(1);
    }
}

void click_card(void)
{
    int mouse_x = GetMouseX();
    int mouse_y = GetMouseY();

    int start_x = ctx->game_area.x + 10;
    int start_y = ctx->game_area.y + 10;
    int index = 0;
    for (int i = 0; i < ctx->grid_size; i++)
    {
        for (int j = 0; j < ctx->grid_size; j++)
        {
            if (mouse_x < start_x + ctx->cell_size && mouse_x > start_x && mouse_y < start_y + ctx->cell_size && mouse_y > start_y)
            {
                printf("%d\n", index);
                if (match_A != -1)
                {
                    match_B = index;
                }
                else
                {
                    match_A = index;
                }
                ctx->cards[index].revelead = true;
            }
            index++;
            start_x += (10 + ctx->cell_size); // 10 pad + 10 cell width
        }
        start_y += (10 + ctx->cell_size);
        start_x = ctx->game_area.x + 10; // 10 pad + 10 cell width
    }
}

void check_match(void)
{
    if (ctx->cards[match_A].type == ctx->cards[match_B].type)
    {
        ctx->cards[match_A].revelead = true;
        ctx->cards[match_B].revelead = true;
    }
    else
    {
        ctx->cards[match_A].revelead = false;
        ctx->cards[match_B].revelead = false;
    }
    match_A = -1;
    match_B = -1;
}