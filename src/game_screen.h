#ifndef TEST_SCREEN_H
#define TEST_SCREEN_H

#include "raylib.h"

#include "screen.h"
#include "game.h"

void game_init(Game *);
void game_render(float);
void game_dispose(void);

void init_cards(int, int, int, int, int);
Color color_from_type(int);
void click_card(void);
void check_match(void);

#endif //TEST_SCREEN_H