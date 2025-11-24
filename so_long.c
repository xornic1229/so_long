/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:06:15 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/24 17:17:24 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_error(const char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(EXIT_FAILURE);
}

int	close_hook(t_game *g)
{
	(void)g;
	exit(0);
	return (0);
}

static void	check_win(t_game *g, int nx, int ny)
{
	if (g->map[ny][nx] == 'E' && g->collected == g->collectibles)
	{
		g->moves++;
		ft_printf("Movimientos: %d\n", g->moves);
		ft_printf("¡Has ganado!\n");
		close_hook(g);
	}
}

int	key_hook(int keycode, t_game *g)
{
	t_move	ctx;

	ctx.nx = g->player_x;
	ctx.ny = g->player_y;
	ctx.moved = 0;
	if (keycode == 65307)
		close_hook(g);
	handle_movement(keycode, g, &ctx);
	if (!ctx.moved)
		return (0);
	if (check_collision(g, ctx.nx, ctx.ny))
	{
		render_map(g);
		return (0);
	}
	handle_collectible(g, ctx.nx, ctx.ny);
	check_win(g, ctx.nx, ctx.ny);
	g->map[g->player_y][g->player_x] = '0';
	g->player_x = ctx.nx;
	g->player_y = ctx.ny;
	g->map[ctx.ny][ctx.nx] = 'P';
	g->moves++;
	ft_printf("Movimientos: %d\n", g->moves);
	render_map(g);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		game_error("Uso: ./so_long map/map1.ber");
	init_game(&g);
	if (!load_map(&g, argv[1]))
		game_error("No se pudo cargar mapa");
	if (!validate_map(&g))
		game_error("Mapa invalido");
	setup_graphics(&g, g.width, g.height);
	render_map(&g);
	mlx_key_hook(g.win, key_hook, &g);
	mlx_hook(g.win, 17, 0, close_hook, &g);
	mlx_loop(g.mlx);
	free_map(g.map);
	return (0);
}
