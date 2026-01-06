/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:55:16 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 16:20:17 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	map_key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_m)
		end_map(data);
	return (0);
}

int	map_click_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		data->hold = true;
	return (0);
}

int	map_release_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		data->hold = false;
	return (0);
}

int	map_expose_hook(t_data *data)
{
	draw_map(data);
	return (0);
}
