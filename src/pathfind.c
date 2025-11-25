/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:45 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/25 18:06:15 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_bfs_visited(int **visited, t_game *g)
{
	int	y;
	int	x;

	y = 0;
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

static void	check_direction(t_game *g, t_bfs *ctx, int base[2], int d[2])
{
	int	n[2];

	n[0] = base[0] + d[0];
	n[1] = base[1] + d[1];
	if (n[0] >= 0 && n[0] < g->height && n[1] >= 0 && n[1] < g->width
		&& !ctx->visited[n[0]][n[1]] && g->map[n[0]][n[1]] != '1')
	{
		if (g->map[n[0]][n[1]] == 'E' && ctx->collected_count < g->collectibles)
			return ;
		ctx->visited[n[0]][n[1]] = 1;
		ctx->rear++;
		ctx->queue[ctx->rear][0] = n[0];
		ctx->queue[ctx->rear][1] = n[1];
		if (g->map[n[0]][n[1]] == 'C')
			ctx->collected_count++;
	}
}

void	bfs_explore(t_game *g, t_bfs *ctx)
{
	int	base[2];
	int	d[4][2];
	int	i;

	d[0][0] = -1;
	d[0][1] = 0;
	d[1][0] = 1;
	d[1][1] = 0;
	d[2][0] = 0;
	d[2][1] = -1;
	d[3][0] = 0;
	d[3][1] = 1;
	base[0] = ctx->queue[ctx->front][0];
	base[1] = ctx->queue[ctx->front][1];
	i = 0;
	while (i < 4)
	{
		check_direction(g, ctx, base, d[i]);
		i++;
	}
}

void	free_visited(int **visited, t_game *g)
{
	int	y;

	y = 0;
	while (y < g->height)
	{
		free(visited[y]);
		y++;
	}
	free(visited);
}
