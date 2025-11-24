/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:30:00 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/24 17:37:32 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdint.h>

void	*create_color_tile(t_game *g, int color)
{
	void		*img;
	t_tex_data	f;

	img = mlx_new_image(g->mlx, TILE_SIZE, TILE_SIZE);
	if (!img)
		game_error("Error creando imagen");
	f.data = mlx_get_data_addr(img, &f.meta[0], &f.meta[1], &f.meta[2]);
	f.v[0] = 0;
	while (f.v[0] < TILE_SIZE)
	{
		f.v[1] = 0;
		while (f.v[1] < TILE_SIZE)
		{
			*(uint32_t *)(f.data + f.v[0] * f.meta[1] + f.v[1] * (f.meta[0]
						/ 8)) = (uint32_t)color;
			f.v[1]++;
		}
		f.v[0]++;
	}
	return (img);
}

static void	scale_pixel_loop(t_tex_data *src, t_tex_data *dst)
{
	uint32_t	px;

	dst->v[0] = 0;
	while (dst->v[0] < TILE_SIZE)
	{
		dst->v[1] = 0;
		while (dst->v[1] < TILE_SIZE)
		{
			px = *(uint32_t *)(src->data + (dst->v[0] * 32 / TILE_SIZE)
					* src->meta[1] + (dst->v[1] * 32 / TILE_SIZE)
					* (src->meta[0] / 8));
			*(uint32_t *)(dst->data + dst->v[0] * dst->meta[1] + dst->v[1]
					* (dst->meta[0] / 8)) = px;
			dst->v[1]++;
		}
		dst->v[0]++;
	}
}

void	*scale_image(t_game *g, void *src, int w, int h)
{
	void		*dst_img;
	t_tex_data	src_data;
	t_tex_data	dst_data;

	if (!src || w != 32 || h != 32 || TILE_SIZE == 32)
		return (src);
	src_data.data = mlx_get_data_addr(src, &src_data.meta[0], &src_data.meta[1],
			&src_data.meta[2]);
	dst_img = mlx_new_image(g->mlx, TILE_SIZE, TILE_SIZE);
	if (!dst_img)
		return (src);
	dst_data.data = mlx_get_data_addr(dst_img, &dst_data.meta[0],
			&dst_data.meta[1], &dst_data.meta[2]);
	scale_pixel_loop(&src_data, &dst_data);
	return (dst_img);
}
