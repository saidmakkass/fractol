/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:29:08 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 16:06:59 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_hook(int button, double dx, double dy, t_data *data)
{
	if (button == WHEEL_UP)
	{
		data->ox -= dx - dx / ZOOM_FACTOR;
		data->oy -= dy - dy / ZOOM_FACTOR;
		data->zoom *= ZOOM_FACTOR;
	}
	if (button == WHEEL_DOWN)
	{
		data->ox += dx - dx / ZOOM_FACTOR;
		data->oy += dy - dy / ZOOM_FACTOR;
		data->zoom /= ZOOM_FACTOR;
	}
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->options->width / 2.0 - x) / data->zoom / data->options->width;
	dy = (data->options->height / 2.0 - y) / data->zoom / data->options->height;
	zoom_hook(button, dx, dy, data);
	plot(data);
	return (0);
}
