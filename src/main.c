/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:35 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 21:06:11 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_data(t_data *data)
{
	data->options = ft_calloc(1, sizeof(t_options));
	data->options->width = DEFAULT_WIDTH;
	data->options->height = DEFAULT_HEIGHT;
	data->options->julia_x = DEFAULT_JULIA_X;
	data->options->julia_y = DEFAULT_JULIA_Y;
	data->max_iter = DEFAULT_ITER;
	data->zoom = DEFAULT_ZOOM;
}

static void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->options->width,
			data->options->height, data->name);
	data->img_data = ft_calloc(1, sizeof(t_img));
	data->img_data->img_ptr = mlx_new_image(data->mlx, data->options->width,
			data->options->height);
	data->img_data->img_buf = mlx_get_data_addr(data->img_data->img_ptr,
			&data->img_data->bpp, &data->img_data->sl, &data->img_data->endian);
}

static int	expose_hook(t_data *data)
{
	plot(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	init_data(data);
	data->name = argv[0];
	parse_args(data, argc, argv);
	init_mlx(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_loop_hook(data->mlx, loop_hook, data);
	mlx_hook(data->win, 17, 0, quit, data);
	mlx_loop(data->mlx);
	clear_data(data);
	return (0);
}
