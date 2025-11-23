#include "../so_long.h"

static char *append_line(char *acc, char *line)
{
    char *joined;
    size_t len1 = acc ? ft_strlen(acc) : 0;
    size_t len2 = ft_strlen(line);
    joined = (char *)malloc(len1 + len2 + 2);
    if (!joined) return NULL;
    if (acc) ft_memcpy(joined, acc, len1);
    ft_memcpy(joined + len1, line, len2);
    joined[len1 + len2] = '\n';
    joined[len1 + len2 + 1] = '\0';
    free(acc);
    return joined;
}

int load_map(t_game *g, const char *path)
{
    int fd = open(path, O_RDONLY);
    char *line;
    char *all = NULL;
    int lines = 0;

    if (fd < 0) return 0;
    while ((line = get_next_line(fd)))
    {
        if (line[0] == '\n') { free(line); break; }
        all = append_line(all, line);
        free(line);
        lines++;
    }
    close(fd);
    if (!all) return 0;
    g->map = ft_split(all, '\n');
    free(all);
    g->height = 0;
    g->width = g->map[0] ? (int)ft_strlen(g->map[0]) : 0;
    while (g->map[g->height]) g->height++;
    return 1;
}

void free_map(char **map)
{
    int i = 0;
    if (!map) return;
    while (map[i]) { free(map[i]); i++; }
    free(map);
}
