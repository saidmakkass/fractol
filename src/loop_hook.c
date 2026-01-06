/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:29:22 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 15:15:54 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_hook(t_data *data)
{
	int	x;
	int	y;

	if (data->disco)
	{
		data->color++;
		if (data->color > 1000)
			data->color = 0;
		plot(data);
	}
	if (data->map)
	{
		mlx_mouse_get_pos(data->mlx, data->map->win, &x, &y);
		data->options->julia_x = (x - 150) / 0.25 / 300;
		data->options->julia_y = (150 - y) / 0.25 / 300;
		plot(data);
	}
	return (0);
}
