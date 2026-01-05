/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 13:35:28 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 18:15:04 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_data *data, double x, double y)
{
	int		iter;
	double	xtemp;

	iter = 0;
	while (x * x + y * y <= 4.0 && iter < data->max_iter)
	{
		xtemp = x * x - y * y + data->flags->julia_x;
		y = 2 * x * y + data->flags->julia_y;
		x = xtemp;
		iter++;
	}
	return (color(data, iter));
}
