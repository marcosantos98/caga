#ifndef TEST_SCREEN_H
#define TEST_SCREEN_H

#include "raylib.h"

#include "screen.h"
#include "game.h"

void test_init(Game *);
void test_render(float);
void test_dispose(void);

void init_cards(int, int, int, int, int);
Color color_from_type(int);
void click_card(void);
void check_match(void);

#endif //TEST_SCREEN_H