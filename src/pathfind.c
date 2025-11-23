#include "../so_long.h"

void init_bfs_visited(int **visited, t_game *g)
{
    int y = 0;
    int x;
    while (y < g->height)
    {
        x = 0;
        while (x < g->width)
        {
            visited[y][x] = 0;
            x++;
        }
        y++;
    }
}

void bfs_explore(t_game *g, int **visited, int queue[1024][2], int *rear, int *collected_count)
{
    int y = queue[*rear][0];
    int x = queue[*rear][1];
    (void)collected_count;
    if (y > 0 && !visited[y - 1][x] && g->map[y - 1][x] != '1')
    {
        visited[y - 1][x] = 1;
        (*rear)++;
        queue[*rear][0] = y - 1;
        queue[*rear][1] = x;
    }
    if (y < g->height - 1 && !visited[y + 1][x] && g->map[y + 1][x] != '1')
    {
        visited[y + 1][x] = 1;
        (*rear)++;
        queue[*rear][0] = y + 1;
        queue[*rear][1] = x;
    }
    if (x > 0 && !visited[y][x - 1] && g->map[y][x - 1] != '1')
    {
        visited[y][x - 1] = 1;
        (*rear)++;
        queue[*rear][0] = y;
        queue[*rear][1] = x - 1;
    }
    if (x < g->width - 1 && !visited[y][x + 1] && g->map[y][x + 1] != '1')
    {
        visited[y][x + 1] = 1;
        (*rear)++;
        queue[*rear][0] = y;
        queue[*rear][1] = x + 1;
    }
}

void free_visited(int **visited, t_game *g)
{
    int y = 0;
    while (y < g->height)
    {
        free(visited[y]);
        y++;
    }
    free(visited);
}
