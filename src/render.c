#include "../so_long.h"

void render_tile(t_game *g, char c, int x, int y)
{
    int px = x * TILE_SIZE;
    int py = y * TILE_SIZE;
    mlx_put_image_to_window(g->mlx, g->win, g->tex.floor, px, py);
    if (c == '1') mlx_put_image_to_window(g->mlx, g->win, g->tex.wall, px, py);
    else if (c == 'P') mlx_put_image_to_window(g->mlx, g->win, g->tex.player, px, py);
    else if (c == 'C') mlx_put_image_to_window(g->mlx, g->win, g->tex.collectible, px, py);
    else if (c == 'E') mlx_put_image_to_window(g->mlx, g->win, g->tex.exit, px, py);
}

void render_map(t_game *g)
{
    int y = 0; int x;
    while (g->map[y])
    {
        x = 0;
        while (g->map[y][x])
        {
            render_tile(g, g->map[y][x], x, y);
            x++;
        }
        y++;
    }
}
