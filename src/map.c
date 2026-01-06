/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:07:23 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 16:39:57 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	end_map(t_data *data)
{
	if (data->map)
	{
		if (data->map->img_ptr)
			mlx_destroy_image(data->mlx, data->map->img_ptr);
		if (data->map->win)
			mlx_destroy_window(data->mlx, data->map->win);
		free(data->map);
		data->map = NULL;
	}
	return (0);
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;
	double	fx;
	double	fy;

	y = 0;
	while (y < 300)
	{
		x = 0;
		while (x < 300)
		{
			fx = (x - 150) / 0.25 / 300;
			fy = (y - 150) / 0.25 / 300;
			put_pixel(data->map, x++, y, mlx_get_color_value(data->mlx,
					mandelbrot(data, fx, fy)));
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->map->win, data->map->img_ptr, 0,
		0);
}

void	start_map(t_data *data)
{
	data->map = ft_calloc(1, sizeof(t_win));
	data->map->win = mlx_new_window(data->mlx, 300, 300, "Julia Map");
	data->map->img_ptr = mlx_new_image(data->mlx, 300, 300);
	data->map->img_buf = mlx_get_data_addr(data->map->img_ptr, &data->map->bpp,
			&data->map->sl, &data->map->endian);
	mlx_key_hook(data->map->win, map_key_hook, data);
	mlx_hook(data->map->win, ButtonPress, ButtonPressMask, map_click_hook,
		data);
	mlx_hook(data->map->win, ButtonRelease, ButtonReleaseMask, map_release_hook,
		data);
	mlx_expose_hook(data->map->win, map_expose_hook, data);
}
