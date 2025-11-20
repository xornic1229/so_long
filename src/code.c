/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:09:10 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/20 13:35:51 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
#include "../minilibx-linux/mlx.h"

void error(int num)
{
    if (num == 1)
    {
        perror("Error apertura archivo");
        exit(EXIT_FAILURE);
    }
    else if (num == 2)
    {
        perror("Error malloc");
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(stderr, "Error desconocido\n");
        exit(EXIT_FAILURE);
    }
}
void load_images(t_game *game)
{
    int w;
    int h;

    /* Use textures/ directory created earlier */
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w, &h);
    game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w, &h);
    game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &w, &h);
    game->img_collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &w, &h);
    game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w, &h);

    if (!game->img_wall || !game->img_floor || !game->img_player || !game->img_collectible || !game->img_exit)
    {
        fprintf(stderr, "Error cargando imágenes (revisa rutas y minilibx)\n");
        exit(EXIT_FAILURE);
    }
}

void	read_map(t_game *game, const char *filename)
{
    int	fd;
    char	*line;
    int	row;

    row = 0;
    game->map = malloc(sizeof(char *) * (MAX_MAP_LINES + 1));
    if (!game->map)
        error(2);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error(1);
    while ((line = get_next_line(fd)) != NULL && row < MAX_MAP_LINES)
    {
        game->map[row] = line;
        row++;
    }
    game->map[row] = NULL;
    game->map_height = row;
    if (row > 0)
        game->map_width = (int)strlen(game->map[0]);
    else
        game->map_width = 0;
    close(fd);
}

void free_map(t_game *game)
{
    int i;

    if (!game || !game->map)
        return ;
    i = 0;
    while (game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    game->map = NULL;
}

void draw_map(t_game *game)
{
    int x, y;
    int tile_size = 32; /* textures are 64x64 */

    for (y = 0; y < game->map_height; y++)
    {
        for (x = 0; x < game->map_width; x++)
        {
            char c = game->map[y][x];
            /* draw floor first */
            mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * tile_size, y * tile_size);

            if (c == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * tile_size, y * tile_size);
            else if (c == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * tile_size, y * tile_size);
            else if (c == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x * tile_size, y * tile_size);
            else if (c == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * tile_size, y * tile_size);
        }
    }
}


static int close_hook(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(void)
{
    t_game game;
    int tile = 64;

    /* Inicializar a NULL por seguridad */
    game.map = NULL;
    game.map_width = 0;
    game.map_height = 0;

    /* Leer mapa */
    read_map(&game, "maps/mapa1.ber");

    /* Inicializar MLX */
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        fprintf(stderr, "No se pudo inicializar MLX\n");
        return (1);
    }

    /* Crear ventana */
    game.win = mlx_new_window(game.mlx, game.map_width * tile, game.map_height * tile, "so_long");
    if (!game.win)
    {
        fprintf(stderr, "No se pudo crear la ventana\n");
        return (1);
    }

    load_images(&game);
    draw_map(&game);

    /* Hooks */
    mlx_hook(game.win, 17, 0, close_hook, &game); /* close button */
    mlx_key_hook(game.win, close_hook, &game);

    mlx_loop(game.mlx);

    /* nunca llega aquí normalmente */
    free_map(&game);
    return 0;
}
