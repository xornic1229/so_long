/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:27 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/27 11:09:35 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_rectangle(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
	{
		if ((int)ft_strlen(g->map[i]) != g->width)
			return (0);
		i++;
	}
	return (1);
}

static int	surrounded_by_walls(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g->width)
	{
		if (g->map[0][x] != '1' || g->map[g->height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < g->height)
	{
		if (g->map[y][0] != '1' || g->map[y][g->width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static void	count_elements(t_game *g, t_counts *counters)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			validate_char(g, g->map[y][x], counters, (t_pos){x, y});
			x++;
		}
		y++;
	}
}

int	validate_map(t_game *g)
{
	t_counts	counters;

	counters.players = 0;
	counters.exits = 0;
	if (!g->map || g->width <= 0 || g->height <= 0)
		return (0);
	if (!is_rectangle(g) || !surrounded_by_walls(g))
		return (0);
	count_elements(g, &counters);
	if (counters.players != 1 || counters.exits != 1 || g->collectibles < 1)
		return (0);
	return (check_path_validity(g));
}
