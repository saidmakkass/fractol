/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:45:51 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 16:18:17 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define MANDLEBROT 0
# define JULIA 1
# define BURNING_SHIP 2

# define DEFAULT_WIDTH 600
# define DEFAULT_HEIGHT 600

# define DEFAULT_JULIA_X 0.285
# define DEFAULT_JULIA_Y 0.01

# define DEFAULT_ZOOM 0.25
# define DEFAULT_ITER 100

# define ZOOM_FACTOR 1.1

# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define RIGHT_CLICK 3
# define LEFT_CLICK 1

typedef struct s_options
{
	int			fractal;
	int			width;
	int			height;
	double		julia_x;
	double		julia_y;
}				t_options;

typedef struct s_win
{
	void		*win;
	void		*img_ptr;
	char		*img_buf;
	int			bpp;
	int			sl;
	int			endian;
}				t_win;

typedef struct s_data
{
	char		*name;
	t_options	*options;
	void		*mlx;
	t_win		*fractal;
	int			max_iter;
	double		zoom;
	double		ox;
	double		oy;
	bool		info;
	bool		disco;
	int			color;
	t_win		*map;
	bool		hold;
}				t_data;

void			clear_data(t_data *data);
int				quit(t_data *data);
void			usage(t_data *data);
void			parse_args(t_data *data, int argc, char **argv);
double			ft_atof(t_data *data, char **s);

int				mandelbrot(t_data *data, double x, double y);
int				julia(t_data *data, double x, double y);
int				burning_ship(t_data *data, double x, double y);

int				color(t_data *data, int iter);

void			put_pixel(t_win *fractal, int x, int y, int color);
void			plot(t_data *data);

void			print_info(t_data *data);

void			start_map(t_data *data);
int				map_key_hook(int keycode, t_data *data);
int				map_click_hook(int button, int x, int y, t_data *data);
int				map_release_hook(int button, int x, int y, t_data *data);
int				map_expose_hook(t_data *data);
void			draw_map(t_data *data);
int				end_map(t_data *data);

int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				loop_hook(t_data *data);

#endif