#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "map.h"

typedef struct player
{
    int x;
    int y;
    char symbol;
    bool up;
} player_t;


#endif /* PLAYER_H */
