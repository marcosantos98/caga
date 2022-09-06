#include "game_screen.h"

#include "stdio.h"
#include "stdlib.h"
#include "card.h"

int match_A = -1;
int match_B = -1;

Game *ctx;
float card_timer = 0;

void game_init(Game *game)
{
    ctx = game;
    generate_cards_for_gamemode(game);
}

void game_render(float delta)
{
    if (card_timer == 0)
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            click_card();
        }
    }

    if (match_A != -1 && match_B != -1 && card_timer >= 1.0f)
    {
        check_match();
        card_timer = 0;
    }
    else if(match_A != -1 && match_B != -1 && card_timer <= 1.0f)
    {
        card_timer += delta;
    }

    BeginDrawing();
    ClearBackground(RAYWHITE);

    int start_x = ctx->game_area.x + 10;
    int start_y = ctx->game_area.y + 10;
    int index = 0;
    for (int i = 0; i < ctx->grid_size; i++)
    {
        for (int j = 0; j < ctx->grid_size; j++)
        {
            DrawRectangle(start_x, start_y, ctx->cell_size, ctx->cell_size, ctx->cards[index].revelead ? color_from_type(ctx->cards[index].type) : WHITE);
            DrawRectangleLines(start_x - 1, start_y - 1, ctx->cell_size + 1, ctx->cell_size + 1, BLACK);

            // char text[100];
            // snprintf(text, 100, "%d", ctx->cards[index].type);
            // DrawText(text, start_x, start_y + 22, 12, BLACK);
            // snprintf(text, 100, "%d", index);
            // DrawText(text, start_x, start_y, 12, BLACK);
            start_x += (10 + ctx->cell_size); // 10 pad + 10 cell width
            index++;
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
    case 0:
        return LIGHTGRAY;
    case 1:
        return GRAY;
    case 2:
        return DARKGRAY;
    case 3:
        return YELLOW;
    case 4:
        return GOLD;
    case 5:
        return ORANGE;
    case 6:
        return PINK;
    case 7:
        return RED;
    case 8:
        return MAROON;
    case 9:
        return GREEN;
    case 10:
        return LIME;
    case 11:
        return DARKGREEN;
    case 12:
        return SKYBLUE;
    case 13:
        return BLUE;
    case 14:
        return DARKBLUE;
    case 15:
        return PURPLE;
    case 16:
        return VIOLET;
    case 17:
        return DARKPURPLE;
    case 18:
        return BEIGE;
    case 19:
        return BROWN;
    case 20:
        return DARKBROWN;
    case 21:
        return WHITE;
    case 22:
        return MAGENTA;
    case 23:
        return BLACK;
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