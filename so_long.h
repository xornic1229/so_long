#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/includes/libft.h"
#include "minilibx-linux/mlx.h"

#define BASE_TILE 32
#define SCALE 4
#define TILE_SIZE (BASE_TILE * SCALE)
#define VALID_CHARS "01PCE"

typedef struct s_textures {
    void *wall;
    void *floor;
    void *player;
    void *player_left;
    void *player_right;
    void *player_back;
    void *exit;
    void *collectible;
} t_textures;

typedef struct s_game {
    void *mlx;
    void *win;
    char **map;
    int width;
    int height;
    int player_x;
    int player_y;
    t_textures tex;
    int collectibles;
    int collected;
    int offset_x;
    int offset_y;
    int player_direction;
    int moves;
} t_game;

/* map */
int     load_map(t_game *g, const char *path);
int     validate_map(t_game *g);
void    free_map(char **map);

/* render */
void    load_textures(t_game *g);
void    render_map(t_game *g);
void    render_tile(t_game *g, char c, int x, int y);

/* input */
int     key_hook(int keycode, t_game *g);

/* utils */
void    game_error(const char *msg);
void    handle_movement(int keycode, t_game *g, int *nx, int *ny, int *moved);
int     check_collision(t_game *g, int nx, int ny);
void    handle_collectible(t_game *g, int nx, int ny);

/* pathfind */
void    init_bfs_visited(int **visited, t_game *g);
void    bfs_explore(t_game *g, int **visited, int queue[1024][2], int *rear, int *collected_count);
void    free_visited(int **visited, t_game *g);

/* init */
void    init_game(t_game *g);
void    setup_graphics(t_game *g, int width, int height);

/* validate */
void    validate_char(t_game *g, char c, int *players, int *exits, int x, int y);

#endif
