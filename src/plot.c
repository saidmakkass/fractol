/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:23 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 15:07:26 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_win *fractal, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)((fractal->img_buf) + (y * fractal->sl) + (x * (fractal->bpp
					/ 8)));
	*pixel = color;
}

void	plot(t_data *data)
{
	int			x;
	int			y;
	double		fx;
	double		fy;
	static int	(*fractals[])(t_data *, double, double) = {mandelbrot, julia,
		burning_ship};

	y = 0;
	while (y < data->options->height)
	{
		x = 0;
		while (x < data->options->width)
		{
			fx = (x - data->options->width / 2.0) / data->zoom
				/ data->options->width + data->ox;
			fy = (y - data->options->height / 2.0) / data->zoom
				/ data->options->height + data->oy;
			put_pixel(data->fractal, x++, y, mlx_get_color_value(data->mlx,
					fractals[data->options->fractal](data, fx, fy)));
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->fractal->win,
		data->fractal->img_ptr, 0, 0);
	print_info(data);
}
