# Project Makefile for so_long
# Builds libft (with printf + gnl bonus), minilibx, and so_long executable

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft/includes -Iminilibx-linux -I. -Isrc
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = so_long.c \
	src/read_map.c src/validate_map.c src/validate_char.c src/load_textures.c src/render.c \
	src/utils.c src/pathfind.c src/init.c src/texture_utils.c src/bfs_utils.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR) 2>&1 | grep -v "warning:" || true

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean || true
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
