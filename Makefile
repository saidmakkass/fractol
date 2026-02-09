NAME        = fractol

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

INCLUDE_DIR = ./include
HEADER      = $(INCLUDE_DIR)/fractol.h

SRC_DIR     = ./src
SRCS        = main.c error.c plot.c parsing.c ft_atof.c mandelbrot.c julia.c info.c color.c burning_ship.c loop_hook.c mouse_hook.c key_hook.c map.c map_hooks.c
OBJS        = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

MLX_DIR     = ./minilibx-linux
MLX         = $(MLX_DIR)/libmlx.a

LIBS        = -L$(MLX_DIR) -L$(LIBFT_DIR) -lft -lmlx -lXext -lX11 -lz -lm
INCLUDES    = -I$(INCLUDE_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "Building Fractol..."
	@$(CC) $(OBJS) $(LIBS) -o $@
	@echo "Done."

$(MLX): $(MLX_DIR)
	@echo "Building Minilibx..."
	@$(MAKE) -sC $(MLX_DIR) >/dev/null 2>&1

$(MLX_DIR):
	@echo "Cloning Minilibx..."
	@git clone https://github.com/42paris/minilibx-linux.git $@ >/dev/null 2>&1


$(LIBFT):
	@echo "Building Libft..."
	@make -sC $(LIBFT_DIR)

%.o: %.c $(HEADER) | $(MLX)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@$(RM) $(MLX_DIR)
	@make fclean -sC $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
