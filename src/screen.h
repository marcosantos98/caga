#ifndef SCREEN_H
#define SCREEN_H

#include "game.h"

typedef struct
{
    void (*init)(Game *);
    void (*render)(float);
    void (*dispose)(void);
} Screen;

#endif