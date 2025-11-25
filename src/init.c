/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:36 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/25 17:52:21 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(t_game *g)
{
	g->map = NULL;
	g->width = 0;
	g->height = 0;
	g->player_x = -1;
	g->player_y = -1;
	g->collectibles = 0;
	g->collected = 0;
	g->player_direction = 0;
	g->moves = 0;
}

void	setup_graphics(t_game *g, int width, int height)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		game_error("mlx_init fallo");
	g->win = mlx_new_window(g->mlx, width * TILE_SIZE, height * TILE_SIZE,
			"so_long");
	if (!g->win)
		game_error("mlx_new_window fallo");
	load_textures(g);
}
