/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:50 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/27 10:54:24 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_tile(t_game *g, char c, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	mlx_put_image_to_window(g->mlx, g->win, g->tex.floor, px, py);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->tex.wall, px, py);
	else if (c == 'P')
	{
		if (g->player_direction == 0)
			mlx_put_image_to_window(g->mlx, g->win, g->tex.player, px, py);
		else if (g->player_direction == 1)
			mlx_put_image_to_window(g->mlx, g->win, g->tex.player_back, px, py);
		else if (g->player_direction == 2)
			mlx_put_image_to_window(g->mlx, g->win, g->tex.player_left, px, py);
		else if (g->player_direction == 3)
			mlx_put_image_to_window(g->mlx, g->win, g->tex.player_right, px,
				py);
	}
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->tex.collectible, px, py);
	else if (c == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->tex.exit, px, py);
}

void	render_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	if (!g || !g->map || g->width <= 0 || g->height <= 0)
		return ;
	while (y < g->height && g->map[y])
	{
		x = 0;
		while (x < g->width && g->map[y][x])
		{
			render_tile(g, g->map[y][x], x, y);
			x++;
		}
		y++;
	}
	render_score(g);
}
