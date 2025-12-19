/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:31:00 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/27 11:18:25 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_bfs_context(t_game *g, t_bfs *ctx)
{
	int	i;

	ctx->front = 0;
	ctx->rear = 0;
	ctx->collected_count = 0;
	ctx->visited = (int **)malloc(sizeof(int *) * g->height);
	i = 0;
	while (i < g->height)
	{
		ctx->visited[i] = (int *)malloc(sizeof(int) * g->width);
		i++;
	}
	init_bfs_visited(ctx->visited, g);
	ctx->queue[0][0] = g->player_y;
	ctx->queue[0][1] = g->player_x;
	ctx->visited[g->player_y][g->player_x] = 1;
}

static int	bfs_process_queue(t_game *g, t_bfs *ctx)
{
	while (ctx->front <= ctx->rear)
	{
		bfs_explore(g, ctx);
		ctx->front++;
	}
	return (1);
}

static void	find_exit_position(t_game *g, int *exit_y, int *exit_x)
{
	int	i;
	int	j;

	*exit_y = -1;
	*exit_x = -1;
	i = 0;
	while (i < g->height && *exit_y == -1)
	{
		j = 0;
		while (j < g->width)
		{
			if (g->map[i][j] == 'E')
			{
				*exit_y = i;
				*exit_x = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	check_exit_accessibility(t_game *g)
{
	t_bfs	ctx;
	int		exit_y;
	int		exit_x;
	int		result;

	init_bfs_context(g, &ctx);
	while (ctx.front <= ctx.rear)
	{
		bfs_explore(g, &ctx);
		ctx.front++;
	}
	find_exit_position(g, &exit_y, &exit_x);
	result = ctx.visited[exit_y][exit_x];
	free_visited(ctx.visited, g);
	return (result);
}

int	check_path_validity(t_game *g)
{
	t_bfs	ctx;
	int		can_collect_all;
	int		can_reach_exit;

	init_bfs_context(g, &ctx);
	bfs_process_queue(g, &ctx);
	can_collect_all = (ctx.collected_count == g->collectibles);
	free_visited(ctx.visited, g);
	if (!can_collect_all)
		return (0);
	can_reach_exit = check_exit_accessibility(g);
	return (can_reach_exit);
}
