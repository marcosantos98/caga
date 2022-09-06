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

void generate_cards_for_gamemode(Game *ctx)
{
    int cards_amount = ctx->grid_size * ctx->grid_size;

    for (int i = 0; i < cards_amount;)
    {
        int type = GetRandomValue(0, CATEGORY_LENGHT);
        ctx->cards[i] = (Card){
            .index = i,
            .type = type,
        };
        i++;
        ctx->cards[i] = (Card){
            .index = i,
            .type = type,
        };
        i++;
    }

    cards_suffle(ctx->cards, cards_amount);
}

void cards_suffle(Card *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          Card t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}
