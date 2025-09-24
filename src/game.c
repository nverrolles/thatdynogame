#include "game.h"

int game_loop()
{
    map_t map = map_gen();
    player_t player = {1, map.height - 1, '@', false};

    while (1)
    {
        print_map(map, player);
    }
    
    return 0;
}