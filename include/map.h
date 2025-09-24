#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdio.h>
#include "player.h"

typedef struct map
{
    char **map_d;
    int width;
    int height;
    int current_row;
} map_t;

int game_loop();
map_t map_gen();
void fill_map(map_t *map);

#endif /* MAP_H */