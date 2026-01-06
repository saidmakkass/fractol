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

MLX_DIR		= /usr/include/minilibx-linux

LIBS		= -L$(MLX_DIR) -L$(LIBFT_DIR) -lft -lmlx -lXext -lX11 -lz -lm
INCLUDES	= -I$(INCLUDE_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)

RM          = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBS) -o $@

$(LIBFT):
	make -sC $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make fclean -sC $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
