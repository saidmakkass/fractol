/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:18:42 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 15:06:51 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	map_key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_m)
		end_map(data);
	return (0);
}

int	map_mouse_hook(int button, int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	if (button == LEFT_CLICK)
	{
		dx = (x - 150) / 0.25 / 300;
		dy = (150 - y) / 0.25 / 300;
		data->options->julia_x = dx;
		data->options->julia_y = dy;
		plot(data);
	}
	return (0);
}
