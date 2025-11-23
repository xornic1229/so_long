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

static int check_valid_path(t_game *g)
{
    int **visited;
    int y;
    int x;
    int queue[1024][2];
    int front = 0;
    int rear = 0;
    int found_exit = 0;
    int collected_count = 0;

    visited = (int **)malloc(sizeof(int *) * g->height);
    y = 0;
    while (y < g->height)
    {
        visited[y] = (int *)malloc(sizeof(int) * g->width);
        x = 0;
        while (x < g->width)
        {
            visited[y][x] = 0;
            x++;
        }
        y++;
    }
    queue[rear][0] = g->player_y;
    queue[rear][1] = g->player_x;
    rear++;
    visited[g->player_y][g->player_x] = 1;
    while (front < rear)
    {
        y = queue[front][0];
        x = queue[front][1];
        front++;
        if (g->map[y][x] == 'E')
            found_exit = 1;
        if (g->map[y][x] == 'C')
            collected_count++;
        if ((y > 0 && !visited[y - 1][x] && g->map[y - 1][x] != '1'))
        {
            visited[y - 1][x] = 1;
            queue[rear][0] = y - 1;
            queue[rear][1] = x;
            rear++;
        }
        if ((y < g->height - 1 && !visited[y + 1][x] && g->map[y + 1][x] != '1'))
        {
            visited[y + 1][x] = 1;
            queue[rear][0] = y + 1;
            queue[rear][1] = x;
            rear++;
        }
        if ((x > 0 && !visited[y][x - 1] && g->map[y][x - 1] != '1'))
        {
            visited[y][x - 1] = 1;
            queue[rear][0] = y;
            queue[rear][1] = x - 1;
            rear++;
        }
        if ((x < g->width - 1 && !visited[y][x + 1] && g->map[y][x + 1] != '1'))
        {
            visited[y][x + 1] = 1;
            queue[rear][0] = y;
            queue[rear][1] = x + 1;
            rear++;
        }
    }
    y = 0;
    while (y < g->height)
    {
        free(visited[y]);
        y++;
    }
    free(visited);
    return (found_exit && collected_count == g->collectibles);
}

int validate_map(t_game *g)
{
    int y = 0;
    int x;
    int players = 0; int exits = 0;
    
    if (!g->map || g->width <= 0 || g->height <= 0)
        return 0;
    if (!is_rectangle(g) || !surrounded_by_walls(g))
        return 0;
    
    while (g->map[y])
    {
        x = 0;
        while (g->map[y][x])
        {
            char c = g->map[y][x];
            if (!ft_strchr(VALID_CHARS, c))
                return 0;
            if (c == 'P')
            {
                players++;
                g->player_x = x;
                g->player_y = y;
            }
            else if (c == 'E')
                exits++;
            else if (c == 'C')
                g->collectibles++;
            x++;
        }
        y++;
    }
    if (players != 1 || exits != 1 || g->collectibles < 1)
        return 0;
    return check_valid_path(g);
}
