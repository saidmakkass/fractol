/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:29:19 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 21:58:56 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	view_hook(int keycode, t_data *data)
{
	if (keycode == XK_equal)
		data->zoom *= ZOOM_FACTOR;
	if (keycode == XK_minus)
		data->zoom /= ZOOM_FACTOR;
	if (keycode == XK_Left)
		data->ox -= 0.1 / data->zoom;
	if (keycode == XK_Right)
		data->ox += 0.1 / data->zoom;
	if (keycode == XK_Up)
		data->oy -= 0.1 / data->zoom;
	if (keycode == XK_Down)
		data->oy += 0.1 / data->zoom;
	if (keycode == XK_bracketright)
		data->max_iter += 10;
	if (keycode == XK_bracketleft)
	{
		data->max_iter -= 10;
		if (data->max_iter <= 10)
			data->max_iter = 10;
	}
}

static void	color_hook(int keycode, t_data *data)
{
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
}

static void	misc_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		quit(data);
	if (keycode == XK_p)
	{
		if (!data->info)
			data->info = true;
		else
			data->info = false;
	}
	if (keycode == XK_r)
	{
		data->max_iter = DEFAULT_ITER;
		data->zoom = DEFAULT_ZOOM;
		data->ox = 0;
		data->oy = 0;
	}
	if (keycode == XK_f)
	{
		data->options->fractal++;
		if (data->options->fractal > BURNING_SHIP)
			data->options->fractal = MANDLEBROT;
	}
}

int	key_hook(int keycode, t_data *data)
{
	view_hook(keycode, data);
	color_hook(keycode, data);
	misc_hook(keycode, data);
	plot(data);
	return (0);
}
