/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:56:38 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/24 17:37:08 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*load_one(t_game *g, const char *path, int fallback_color)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(g->mlx, (char *)path, &w, &h);
	if (!img)
		img = create_color_tile(g, fallback_color);
	else
		img = scale_image(g, img, w, h);
	return (img);
}

void	load_textures(t_game *g)
{
	g->tex.wall = load_one(g, "textures/wall.xpm", 0xFF222222);
	g->tex.floor = load_one(g, "textures/floor.xpm", 0xFF3E3E3E);
	g->tex.player = load_one(g, "textures/player.xpm", 0xFF2C7CFF);
	g->tex.player_left = load_one(g, "textures/playerleft.xpm", 0xFF2C7CFF);
	g->tex.player_right = load_one(g, "textures/playerright.xpm", 0xFF2C7CFF);
	g->tex.player_back = load_one(g, "textures/playerback.xpm", 0xFF2C7CFF);
	g->tex.exit = load_one(g, "textures/exit.xpm", 0xFFFF2020);
	g->tex.collectible = load_one(g, "textures/collectible.xpm", 0xFFF8C800);
}
