/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:31:00 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/25 18:06:15 by jaialons         ###   ########.fr       */
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
	int	found_exit;

	found_exit = 0;
	while (ctx->front <= ctx->rear)
	{
		if (g->map[ctx->queue[ctx->front][0]][ctx->queue[ctx->front][1]] == 'E')
			found_exit = 1;
		bfs_explore(g, ctx);
		ctx->front++;
	}
	return (found_exit);
}

int	check_path_validity(t_game *g)
{
	t_bfs	ctx;
	int		found_exit;

	init_bfs_context(g, &ctx);
	found_exit = bfs_process_queue(g, &ctx);
	free_visited(ctx.visited, g);
	return (found_exit && ctx.collected_count == g->collectibles);
}
