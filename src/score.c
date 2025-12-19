/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:00:00 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/27 10:59:15 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	clear_score_area(t_game *g, int base_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->width * TILE_SIZE)
	{
		j = 0;
		while (j < 50)
		{
			mlx_pixel_put(g->mlx, g->win, i, base_y + j, 0x000000);
			j++;
		}
		i++;
	}
}

static void	draw_text_multiple_times(t_game *g, char *text, int x, int y)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		mlx_string_put(g->mlx, g->win, x + (i % 3), y + (i / 3),
			0xFFFFFF, text);
		i++;
	}
}

static void	build_score_string(t_game *g, char *buffer)
{
	char	*moves_str;
	char	*collected_str;
	char	*total_str;

	moves_str = ft_itoa(g->moves);
	collected_str = ft_itoa(g->collected);
	total_str = ft_itoa(g->collectibles);
	if (!moves_str || !collected_str || !total_str)
		return ;
	ft_strlcpy(buffer, "MOVIMIENTOS: ", 256);
	ft_strlcat(buffer, moves_str, 256);
	ft_strlcat(buffer, " | COLECTABLES: ", 256);
	ft_strlcat(buffer, collected_str, 256);
	ft_strlcat(buffer, "/", 256);
	ft_strlcat(buffer, total_str, 256);
	free(moves_str);
	free(collected_str);
	free(total_str);
}

void	render_score(t_game *g)
{
	char	score_display[256];
	int		base_y;

	base_y = g->height * TILE_SIZE + 5;
	clear_score_area(g, base_y);
	build_score_string(g, score_display);
	draw_text_multiple_times(g, score_display, 15, base_y + 30);
}
