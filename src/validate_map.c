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
    int queue[1024][2];
    int front = 0;
    int rear = 0;
    int found_exit = 0;
    int collected_count = 0;

    visited = (int **)malloc(sizeof(int *) * g->height);
    for (int i = 0; i < g->height; i++)
        visited[i] = (int *)malloc(sizeof(int) * g->width);
    init_bfs_visited(visited, g);
    queue[0][0] = g->player_y;
    queue[0][1] = g->player_x;
    visited[g->player_y][g->player_x] = 1;
    rear = 0;
    while (front <= rear)
    {
        if (g->map[queue[front][0]][queue[front][1]] == 'E')
            found_exit = 1;
        if (g->map[queue[front][0]][queue[front][1]] == 'C')
            collected_count++;
        bfs_explore(g, visited, queue, &rear, &collected_count);
        front++;
    }
    free_visited(visited, g);
    return (found_exit && collected_count == g->collectibles);
}

static void count_elements(t_game *g, int *players, int *exits)
{
    int y = 0;
    int x;
    while (g->map[y])
    {
        x = 0;
        while (g->map[y][x])
        {
            validate_char(g, g->map[y][x], players, exits, x, y);
            x++;
        }
        y++;
    }
}

int validate_map(t_game *g)
{
    int players = 0;
    int exits = 0;

    if (!g->map || g->width <= 0 || g->height <= 0)
        return 0;
    if (!is_rectangle(g) || !surrounded_by_walls(g))
        return 0;
    count_elements(g, &players, &exits);
    if (players != 1 || exits != 1 || g->collectibles < 1)
        return 0;
    return check_valid_path(g);
}



