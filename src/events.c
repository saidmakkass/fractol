/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:37 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 18:14:07 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		clear_data(data);
		exit(0);
	}
	if (keycode == XK_bracketright)
		data->max_iter += 10;
	if (keycode == XK_bracketleft)
	{
		data->max_iter -= 10;
		if (data->max_iter <= 10)
			data->max_iter = 10;
	}
	if (keycode == XK_equal)
		data->zoom *= 1.2;
	if (keycode == XK_minus)
		data->zoom /= 1.2;
	if (keycode == XK_p)
	{
		if (!data->info)
			data->info = true;
		else
			data->info = false;
	}
	if (keycode == XK_Left)
		data->ox -= 0.1 / data->zoom;
	if (keycode == XK_Right)
		data->ox += 0.1 / data->zoom;
	if (keycode == XK_Up)
		data->oy -= 0.1 / data->zoom;
	if (keycode == XK_Down)
		data->oy += 0.1 / data->zoom;
	if (keycode == XK_r)
	{
		data->max_iter = DEFAULT_ITER;
		data->zoom = DEFAULT_ZOOM;
	}
	if (keycode == XK_o)
	{
		if (data->disco)
			data->disco = false;
		else
			data->disco = true;
	}
	if (keycode == XK_quoteright)
	{
		data->color++;
		if (data->color > 1000)
			data->color = 0;
	}
	if (keycode == XK_semicolon)
	{
		data->color--;
		if (data->color < 0)
			data->color = 1000;
	}
	plot(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == WHEEL_UP)
		data->zoom *= 1.2;
	if (button == WHEEL_DOWN)
		data->zoom /= 1.2;
	plot(data);
	return (0);
}

int	loop_hook(t_data *data)
{
	if (data->disco)
	{
		data->color++;
		if (data->color > 1000)
			data->color = 0;
		plot(data);
	}
	return (0);
}
