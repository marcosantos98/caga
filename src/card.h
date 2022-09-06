#ifndef CARD_H
#define CARD_H

#include "stdbool.h"

typedef enum
{
    A = 0,
    B
} CardType;

typedef struct
{
    int index;
    int type;
    bool revelead;
} Card;

#endif //CARD_H