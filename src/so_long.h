
#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

#include "../libft/includes/libft.h"

#define MAX_MAP_LINES 1000

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	char	**map;
	int		map_width;
	int		map_height;
}	t_game;

#endif
