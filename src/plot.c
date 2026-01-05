/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:23 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 18:15:43 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_img *img_data, int x, int y, int color)
{
	int	*pixel;

	pixel = (int *)((img_data->img_buf) + (y * img_data->sl) + (x
				* (img_data->bpp / 8)));
	*pixel = color;
}

void	plot(t_data *data)
{
	static int	(*fractals[])(t_data *, double, double) = {mandelbrot, julia,
		burning_ship};
	int			x;
	int			y;
	double		fx;
	double		fy;

	y = 0;
	while (y < data->flags->height)
	{
		x = 0;
		while (x < data->flags->width)
		{
			fx = (x - data->flags->width / 2.0) / data->zoom
				/ data->flags->width + data->ox;
			fy = (y - data->flags->height / 2.0) / data->zoom
				/ data->flags->height + data->oy;
			put_pixel(data->img_data, x++, y, mlx_get_color_value(data->mlx,
					fractals[data->flags->fractal](data, fx, fy)));
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img_data->img_ptr, 0,
		0);
	print_info(data);
}
