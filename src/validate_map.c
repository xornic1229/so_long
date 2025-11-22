#include "../so_long.h"

static int is_rectangle(t_game *g)
{
    int i = 0;
    while (g->map[i])
    {
        if ((int)ft_strlen(g->map[i]) != g->width)
            return 0;
        i++;
    }
    return 1;
}

static int surrounded_by_walls(t_game *g)
{
    int x;
    int y;
    for (x = 0; x < g->width; x++)
        if (g->map[0][x] != '1' || g->map[g->height - 1][x] != '1') return 0;
    for (y = 0; y < g->height; y++)
        if (g->map[y][0] != '1' || g->map[y][g->width - 1] != '1') return 0;
    return 1;
}

int validate_map(t_game *g)
{
    int y = 0;
    int x;
    int players = 0; int exits = 0;
    if (!is_rectangle(g) || !surrounded_by_walls(g)) return 0;
    while (g->map[y])
    {
        x = 0;
        while (g->map[y][x])
        {
            char c = g->map[y][x];
            if (!ft_strchr(VALID_CHARS, c)) return 0;
            if (c == 'P') { players++; g->player_x = x; g->player_y = y; }
            else if (c == 'E') exits++;
            else if (c == 'C') g->collectibles++;
            x++;
        }
        y++;
    }
    return (players == 1 && exits >= 1 && g->collectibles >= 1);
}
