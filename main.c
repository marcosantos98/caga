#include "stdio.h"

#include "raylib.h"

#define WIDTH 800
#define HEIGHT 800

typedef enum {
    A = 0,
    B
} CardType;

typedef struct {
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

void click_card(void)
{
    int mouse_x = GetMouseX();
    int mouse_y = GetMouseY();

    for(int i = 0; i < 8 * 8; i++)
    {
        //fixme 22/09/06: Mayube check for null ptr before deref them
        Card at = cards[i];
        if(mouse_x < at.x + at.width && mouse_x > at.x && mouse_y < at.y + at.height && mouse_y > at.y)
        {
            if(match_A != -1)
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

    return ;
}

void check_match(void)
{
    if(cards[match_A].type == cards[match_B].type)
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

int main(void)
{

    InitWindow(WIDTH, HEIGHT, "caga");

    int cell_size = 800 / 10;
    int cols = 800 / (cell_size + 10);
    int rows = 800 / (cell_size + 10);

    Rectangle game_area = {
        .x = (WIDTH / 2) - ((((cell_size + 10) * rows) + 10) / 2),
        .y = (HEIGHT / 2) - ((((cell_size + 10) * cols) + 10) / 2),
        .width = (((cell_size + 10) * rows) + 10),
        .height = (((cell_size + 10) * cols) + 10),
    };

    init_cards(cols, rows, game_area.x, game_area.y, cell_size);

    while (!WindowShouldClose())
    {
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            click_card();
        }

        if(match_A != -1 && match_B != -1)
        {
            printf("HI\n");
            check_match();
        }

        BeginDrawing();
        ClearBackground(BLACK);

        //DrawRectangleRec(game_area, RED);

        for (int i = 0; i < 8 * 8; i++)
        {
             DrawRectangle(cards[i].x, cards[i].y, cards[i].width, cards[i].height, cards[i].color);
        }

        EndDrawing();
    }

    CloseWindow();
}