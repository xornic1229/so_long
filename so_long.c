#include "so_long.h"

void game_error(const char *msg)
{
    write(2, "Error: ", 7);
    if (msg)
        write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

int close_hook(t_game *g)
{
    (void)g;
    exit(0);
    return 0;
}

int key_hook(int keycode, t_game *g)
{
    int nx = g->player_x;
    int ny = g->player_y;
    if (keycode == 65307) /* ESC */
        close_hook(g);
    else if (keycode == 'w') ny--;
    else if (keycode == 's') ny++;
    else if (keycode == 'a') nx--;
    else if (keycode == 'd') nx++;
    if (g->map[ny][nx] == '1') return 0;
    if (g->map[ny][nx] == 'C') g->collected++;
    if (g->map[ny][nx] == 'E' && g->collected == g->collectibles)
        game_error("Has ganado! (cerrar) ");
    g->map[g->player_y][g->player_x] = '0';
    g->player_x = nx;
    g->player_y = ny;
    g->map[ny][nx] = 'P';
    render_map(g);
    return 0;
}

int main(int argc, char **argv)
{
    t_game g;

    if (argc != 2)
        game_error("Uso: ./so_long map/map1.ber");
    g.map = NULL; g.width = 0; g.height = 0; g.player_x = -1; g.player_y = -1; g.collectibles=0; g.collected=0;
    if (!load_map(&g, argv[1]))
        game_error("No se pudo cargar mapa");
    if (!validate_map(&g))
        game_error("Mapa invalido");
    g.mlx = mlx_init();
    if (!g.mlx) game_error("mlx_init fallo");
    g.offset_x = 0;
    g.offset_y = 0;
    g.win = mlx_new_window(g.mlx, g.width * TILE_SIZE, g.height * TILE_SIZE, "so_long");
    if (!g.win) game_error("mlx_new_window fallo");
    load_textures(&g);
    render_map(&g);
    mlx_key_hook(g.win, key_hook, &g);
    mlx_hook(g.win, 17, 0, close_hook, &g);
    mlx_loop(g.mlx);
    free_map(g.map);
    return 0;
}
