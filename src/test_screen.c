#include "test_screen.h"

#include "stdio.h"
#include "stdlib.h"

typedef enum
{
    A = 0,
    B
} CardType;

typedef struct
{
    int x;
    int y;
    int width;
    int height;
    Color color;
    CardType type;
} Card;

Card cards[8 * 8];

int match_A = -1;
int match_B = -1;

void test_init(Game *ctx)
{
    Rectangle game_area = {
        .x = (ctx->width / 2) - ((((ctx->cell_size + 10) * ctx->grid_size) + 10) / 2),
        .y = (ctx->height / 2) - ((((ctx->cell_size + 10) * ctx->grid_size) + 10) / 2),
        .width = (((ctx->cell_size + 10) * ctx->grid_size) + 10),
        .height = (((ctx->cell_size + 10) * ctx->grid_size) + 10),
    };
    init_cards(ctx->grid_size, ctx->grid_size, game_area.x, game_area.y, ctx->cell_size);
}

void test_render(float delta)
{
    (void)delta;
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
        click_card();
    }

    if (match_A != -1 && match_B != -1)
    {
        printf("HI\n");
        check_match();
    }

    BeginDrawing();
    ClearBackground(BLACK);

    // DrawRectangleRec(game_area, RED);

    for (int i = 0; i < 8 * 8; i++)
    {
        DrawRectangle(cards[i].x, cards[i].y, cards[i].width, cards[i].height, cards[i].color);
    }

    EndDrawing();
}

void test_dispose()
{
    printf("Dispose\n");
}

void init_cards(int cols, int rows, int x, int y, int cell_size)
{
    int start_x = x + 10;
    int start_y = y + 10;
    int index = 0;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cards[index] = (Card){
                .x = start_x,
                .y = start_y,
                .width = cell_size,
                .height = cell_size,
                .color = WHITE,
                .type = GetRandomValue(0, 1),
            };
            index++;
            start_x += (10 + cell_size); // 10 pad + 10 cell width
        }
        start_y += (10 + cell_size);
        start_x = x + 10; // 10 pad + 10 cell width
    }
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

    for (int i = 0; i < 8 * 8; i++)
    {
        // fixme 22/09/06: Mayube check for null ptr before deref them
        Card at = cards[i];
        if (mouse_x < at.x + at.width && mouse_x > at.x && mouse_y < at.y + at.height && mouse_y > at.y)
        {
            if (match_A != -1)
            {
                match_B = i;
            }
            else
            {
                match_A = i;
            }
            cards[i].color = color_from_type(cards[i].type);
        }
    }

    return;
}

void check_match(void)
{
    if (cards[match_A].type == cards[match_B].type)
    {
        cards[match_A].color = BLACK;
        cards[match_B].color = BLACK;
    }
    else
    {
        cards[match_A].color = WHITE;
        cards[match_B].color = WHITE;
    }
    match_A = -1;
    match_B = -1;
}