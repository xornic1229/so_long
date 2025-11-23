#include "../so_long.h"

void handle_movement(int keycode, t_game *g, int *nx, int *ny, int *moved)
{
    if (keycode == 'w')
    {
        *ny -= 1;
        g->player_direction = 1;
        *moved = 1;
    }
    else if (keycode == 's')
    {
        *ny += 1;
        g->player_direction = 0;
        *moved = 1;
    }
    else if (keycode == 'a')
    {
        *nx -= 1;
        g->player_direction = 2;
        *moved = 1;
    }
    else if (keycode == 'd')
    {
        *nx += 1;
        g->player_direction = 3;
        *moved = 1;
    }
}

int check_collision(t_game *g, int nx, int ny)
{
    if (ny < 0 || ny >= g->height || nx < 0 || nx >= g->width)
        return 1;
    if (g->map[ny][nx] == '1')
        return 1;
    if (g->map[ny][nx] == 'E' && g->collected < g->collectibles)
        return 1;
    return 0;
}

void handle_collectible(t_game *g, int nx, int ny)
{
    if (g->map[ny][nx] == 'C')
        g->collected++;
}
