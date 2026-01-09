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

static void	*render_rows(void *arg)
{
	t_thread_data	*thread_data;
	t_data			*data;
	int				x;
	int				y;
	double			fx;
	double			fy;
	static int		(*fractals[])(t_data *, double, double) = {mandelbrot,
		julia, burning_ship};

	thread_data = (t_thread_data *)arg;
	data = thread_data->data;
	y = thread_data->start_y;
	while (y < thread_data->end_y)
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
	return (NULL);
}

void	plot(t_data *data)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				i;
	int				rows_per_thread;

	if (data->options->height == 0)
		return ;
	rows_per_thread = data->options->height / NUM_THREADS;
	i = 0;
	while (i < NUM_THREADS)
	{
		thread_data[i].data = data;
		thread_data[i].start_y = i * rows_per_thread;
		if (i == NUM_THREADS - 1)
			thread_data[i].end_y = data->options->height;
		else
			thread_data[i].end_y = (i + 1) * rows_per_thread;
		if (pthread_create(&threads[i], NULL, render_rows, &thread_data[i]))
		{
			while (--i >= 0)
				pthread_join(threads[i], NULL);
			return ;
		}
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
		pthread_join(threads[i++], NULL);
	mlx_put_image_to_window(data->mlx, data->fractal->win,
		data->fractal->img_ptr, 0, 0);
	print_info(data);
}
