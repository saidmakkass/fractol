/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 19:45:51 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 17:57:30 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <math.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define MANDLEBROT 0
# define JULIA 1
# define BURNING_SHIP 2

# define DEFAULT_ZOOM 0.25
# define DEFAULT_ITER 100

# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define RIGHT_CLICK 3
# define LEFT_CLICK 1

typedef struct s_flags
{
	int		fractal;
	int		width;
	int		height;
	double	julia_x;
	double	julia_y;
}			t_flags;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_buf;
	int		bpp;
	int		sl;
	int		endian;
}			t_img;

typedef struct s_data
{
	char	*name;
	t_flags	*flags;
	void	*mlx;
	void	*win;
	t_img	*img_data;
	int		max_iter;
	double	zoom;
	double	ox;
	double	oy;
	bool	info;
	bool	disco;
	int		color;
}			t_data;

void		clear_data(t_data *data);
void		usage(t_data *data);
void		parse_args(t_data *data, int argc, char **argv);
double		ft_atof(t_data *data, char **s);

int			mandelbrot(t_data *data, double x, double y);
int			julia(t_data *data, double x, double y);
int			burning_ship(t_data *data, double x, double y);

int			color(t_data *data, int iter);

void		plot(t_data *data);

void		print_info(t_data *data);

int			key_hook(int keycode, t_data *data);
int			mouse_hook(int button, int x, int y, t_data *data);
int			loop_hook(t_data *data);

#endif