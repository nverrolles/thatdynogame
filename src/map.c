#include "map.h"

void print_map(map_t map, player_t player)
{
    for (int i = 0; i < map.height; i++)
    {
        for (int j = 0; j < map.width; j++)
        {
            if (i == player.y && j == player.x)
                putchar(player.symbol);
            else
            putchar(map.map_d[i][j]);
        }
        putchar('\n');
    }
}

map_t map_gen()
{
    map_t map;
    map.width = 200;
    map.height = 10;
    map.current_row = 0;
    map.map_d = malloc(sizeof(char *) * map.height);

    for (int i = 0; i < map.height; i++)
    {
        map.map_d[i] = malloc(sizeof(char) * map.width);
        for (int j = 0; j < map.width; j++)
        {
            if (i == map.height - 1 || i == 0)
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
        for (int j = 1; j < map->height - 1; j++)
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

