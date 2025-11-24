/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:48 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/24 17:17:11 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*append_line(char *acc, char *line)
{
	char	*joined;
	size_t	len1;
	size_t	len2;

	if (acc)
		len1 = ft_strlen(acc);
	else
		len1 = 0;
	len2 = ft_strlen(line);
	joined = (char *)malloc(len1 + len2 + 2);
	if (!joined)
		return (NULL);
	if (acc)
		ft_memcpy(joined, acc, len1);
	ft_memcpy(joined + len1, line, len2);
	joined[len1 + len2] = '\n';
	joined[len1 + len2 + 1] = '\0';
	free(acc);
	return (joined);
}

static char	*read_all_lines(int fd)
{
	char	*line;
	char	*all;

	all = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			break ;
		}
		all = append_line(all, line);
		free(line);
		line = get_next_line(fd);
	}
	return (all);
}

int	load_map(t_game *g, const char *path)
{
	int		fd;
	char	*all;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	all = read_all_lines(fd);
	close(fd);
	if (!all)
		return (0);
	g->map = ft_split(all, '\n');
	free(all);
	g->height = 0;
	g->width = 0;
	if (g->map[0])
		g->width = (int)ft_strlen(g->map[0]);
	while (g->map[g->height])
		g->height++;
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
