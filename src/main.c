#include <stdio.h>
#include <stdlib.h>
#include "map.h"


int main (int ac, char **av)
{
    while (1)
    {
        game_loop();
        exit(0);
    }
    return 0;
}

int game_loop()
{
    map_t map = map_gen();
    printf("Map generated with dimensions: %dx%d\n", map.width, map.height);
    for (int i = 0; i < map.height; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            putchar(map.map_d[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

map_t map_gen()
{
    map_t map;
    map.width = 200;
    map.height = 10;
    map.map_d = malloc(sizeof(char *) * map.height);

    for (int i = 0; i < map.height; i++)
    {
        map.map_d[i] = malloc(sizeof(char) * map.width);
        for (int j = 0; j < map.width; j++)
        {
            if (i == map.height - 1)
                map.map_d[i][j] = '#'; // Ground
            else
                map.map_d[i][j] = ' '; // Empty space
        }
    }
    fill_map(&map);
    return map;
}

void fill_map(map_t *map)
{
    int obs = 0;

    for (int i = 0; i <map->width; i++)
    {
        for (int j = 0; j < map->height - 1; j++)
        {
            if (rand() % 10 < 2 && obs < 3) // 20% chance to place a platform
            {
                map->map_d[j][i] = 'x';
                obs++;
            }
        }
        obs = 0;
    }
}

