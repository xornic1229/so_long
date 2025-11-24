/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaialons <jaialons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:18:28 by jaialons          #+#    #+#             */
/*   Updated: 2025/11/24 17:37:08 by jaialons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE_TILE 32
# define SCALE 4
# define TILE_SIZE 128
# define VALID_CHARS "01PCE"

typedef struct s_textures
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*player_left;
	void		*player_right;
	void		*player_back;
	void		*exit;
	void		*collectible;
}				t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	t_textures	tex;
	int			collectibles;
	int			collected;
	int			offset_x;
	int			offset_y;
	int			player_direction;
	int			moves;
}				t_game;

typedef struct s_bfs
{
	int			**visited;
	int			queue[1024][2];
	int			front;
	int			rear;
	int			collected_count;
}				t_bfs;

typedef struct s_move
{
	int			nx;
	int			ny;
	int			moved;
}				t_move;

typedef struct s_counts
{
	int			players;
	int			exits;
}				t_counts;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_tex_data
{
	char		*data;
	int			meta[3];
	int			v[2];
}				t_tex_data;

/* map */
int				load_map(t_game *g, const char *path);
int				validate_map(t_game *g);
void			free_map(char **map);

/* render */
void			load_textures(t_game *g);
void			render_map(t_game *g);
void			render_tile(t_game *g, char c, int x, int y);
void			*create_color_tile(t_game *g, int color);
void			*scale_image(t_game *g, void *src, int w, int h);

/* input */
int				key_hook(int keycode, t_game *g);

/* utils */
void			game_error(const char *msg);
void			handle_movement(int keycode, t_game *g, t_move *ctx);
int				check_collision(t_game *g, int nx, int ny);
void			handle_collectible(t_game *g, int nx, int ny);

/* pathfind */
void			init_bfs_visited(int **visited, t_game *g);
void			bfs_explore(t_game *g, t_bfs *ctx);
void			free_visited(int **visited, t_game *g);
int				path_is_valid(t_game *g);
int				check_path_validity(t_game *g);

/* init */
void			init_game(t_game *g);
void			setup_graphics(t_game *g, int width, int height);

/* validate */
void			validate_char(t_game *g, char c, t_counts *counters, t_pos pos);

#endif
