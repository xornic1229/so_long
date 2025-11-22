// Texture loader with fallback to solid color tiles if XPM fails
#include "../so_long.h"
#include <string.h>
#include <stdint.h>

static void *create_color_tile(t_game *g, int color)
{
    int x, y;
    int bpp, sl, endian;
    void *img = mlx_new_image(g->mlx, TILE_SIZE, TILE_SIZE);
    if (!img)
        game_error("Error creando imagen");
    char *data = mlx_get_data_addr(img, &bpp, &sl, &endian);
    for (y = 0; y < TILE_SIZE; ++y)
    {
        for (x = 0; x < TILE_SIZE; ++x)
        {
            *(uint32_t *)(data + y * sl + x * (bpp / 8)) = (uint32_t)color;
        }
    }
    return img;
}

static void *scale_image(t_game *g, void *src, int w, int h)
{
    if (!src || w != 32 || h != 32 || TILE_SIZE == 32)
        return src; /* only scale 32->TILE_SIZE */
    int sbpp, ssl, sendian;
    char *sdata = mlx_get_data_addr(src, &sbpp, &ssl, &sendian);
    void *dst = mlx_new_image(g->mlx, TILE_SIZE, TILE_SIZE);
    if (!dst) return src;
    int dbpp, dsl, dend;
    char *ddata = mlx_get_data_addr(dst, &dbpp, &dsl, &dend);
    for (int y = 0; y < TILE_SIZE; ++y)
        for (int x = 0; x < TILE_SIZE; ++x)
        {
            int sx = x * 32 / TILE_SIZE;
            int sy = y * 32 / TILE_SIZE;
            uint32_t pixel = *(uint32_t *)(sdata + sy * ssl + sx * (sbpp/8));
            *(uint32_t *)(ddata + y * dsl + x * (dbpp/8)) = pixel;
        }
    return dst;
}

static void *load_one(t_game *g, const char *path, int fallback_color)
{
    int w, h;
    void *img = mlx_xpm_file_to_image(g->mlx, (char *)path, &w, &h);
    if (!img)
        img = create_color_tile(g, fallback_color);
    else
        img = scale_image(g, img, w, h);
    return img;
}

void load_textures(t_game *g)
{
    g->tex.wall = load_one(g, "textures/wall.xpm", 0xFF222222);
    g->tex.floor = load_one(g, "textures/floor.xpm", 0xFF3E3E3E);
    g->tex.player = load_one(g, "textures/player.xpm", 0xFF2C7CFF);
    g->tex.exit = load_one(g, "textures/exit.xpm", 0xFFFF2020);
    g->tex.collectible = load_one(g, "textures/collectible.xpm", 0xFFF8C800);
}
