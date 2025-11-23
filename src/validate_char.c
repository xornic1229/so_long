#include "../so_long.h"

void validate_char(t_game *g, char c, int *players, int *exits, int x, int y)
{
    if (!ft_strchr(VALID_CHARS, c))
    {
        *players = -1;
        return ;
    }
    if (c == 'P')
    {
        (*players)++;
        g->player_x = x;
        g->player_y = y;
    }
    else if (c == 'E')
        (*exits)++;
    else if (c == 'C')
        g->collectibles++;
}
