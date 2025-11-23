#include "../so_long.h"

void render_tile(t_game *g, char c, int x, int y)
{
    int px = x * TILE_SIZE;
    int py = y * TILE_SIZE;
    mlx_put_image_to_window(g->mlx, g->win, g->tex.floor, px, py);
    if (c == '1') mlx_put_image_to_window(g->mlx, g->win, g->tex.wall, px, py);
    else if (c == 'P')
    {
        if (g->player_direction == 0)
            mlx_put_image_to_window(g->mlx, g->win, g->tex.player, px, py);
        else if (g->player_direction == 1)
            mlx_put_image_to_window(g->mlx, g->win, g->tex.player_back, px, py);
        else if (g->player_direction == 2)
            mlx_put_image_to_window(g->mlx, g->win, g->tex.player_left, px, py);
        else if (g->player_direction == 3)
            mlx_put_image_to_window(g->mlx, g->win, g->tex.player_right, px, py);
    }
    else if (c == 'C') mlx_put_image_to_window(g->mlx, g->win, g->tex.collectible, px, py);
    else if (c == 'E') mlx_put_image_to_window(g->mlx, g->win, g->tex.exit, px, py);
}

void render_map(t_game *g)
{
    int y = 0;
    int x;
    
    if (!g || !g->map || g->width <= 0 || g->height <= 0)
        return ;
    
    while (y < g->height && g->map[y])
    {
        x = 0;
        while (x < g->width && g->map[y][x])
        {
            render_tile(g, g->map[y][x], x, y);
            x++;
        }
        y++;
    }
}
