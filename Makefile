# Project Makefile for so_long
# Builds libft (with printf + gnl bonus), minilibx, and so_long executable

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft/includes -Ift_printf -Iget_next_line -Iminilibx-linux -I. -Isrc
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRC = $(addprefix $(FT_PRINTF_DIR)/, ft_printf.c ft_putchars.c ft_putnbrs.c utils.c utils2.c)
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

GNL_SRC = get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c
GNL_OBJ = $(GNL_SRC:.c=.o)

SRCS = so_long.c \
	src/read_map.c src/validate_map.c src/load_textures.c src/render.c src/key_hooks.c src/utils.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(MLX_LIB) $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(FT_PRINTF_OBJ) $(GNL_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_OBJ) $(GNL_OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean || true
	$(RM) $(OBJS) $(FT_PRINTF_OBJ) $(GNL_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
