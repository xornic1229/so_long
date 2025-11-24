/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:53 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/24 20:22:08 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_movement(int keycode, t_game *g, t_move *ctx)
{
	if (keycode == 'w')
	{
		ctx->ny -= 1;
		g->player_direction = 1;
		ctx->moved = 1;
	}
	else if (keycode == 's')
	{
		ctx->ny += 1;
		g->player_direction = 0;
		ctx->moved = 1;
	}
	else if (keycode == 'a')
	{
		ctx->nx -= 1;
		g->player_direction = 2;
		ctx->moved = 1;
	}
	else if (keycode == 'd')
	{
		ctx->nx += 1;
		g->player_direction = 3;
		ctx->moved = 1;
	}
}

int	check_collision(t_game *g, int nx, int ny)
{
	if (ny < 0 || ny >= g->height || nx < 0 || nx >= g->width)
		return (1);
	if (g->map[ny][nx] == '1')
		return (1);
	if (g->map[ny][nx] == 'E' && g->collected < g->collectibles)
		return (1);
	return (0);
}

void	handle_collectible(t_game *g, int nx, int ny)
{
	if (g->map[ny][nx] == 'C')
		g->collected++;
}
