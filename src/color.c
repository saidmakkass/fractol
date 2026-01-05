/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:14:13 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 18:16:34 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(t_data *data, int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == data->max_iter)
		return (0x000000);
	r = (int)(sin(0.3 * iter + data->color) * 127 + 128);
	g = (int)(sin(0.3 * iter + 2 + data->color) * 127 + 128);
	b = (int)(sin(0.3 * iter + 4 + data->color) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}
