/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:53:31 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 18:14:41 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_data *data, double x, double y)
{
	int		iter;
	double	zx;
	double	zy;
	double	xtemp;

	iter = 0;
	zx = 0.0;
	zy = 0.0;
	while (zx * zx + zy * zy < 4.0 && iter < data->max_iter)
	{
		xtemp = zx * zx - zy * zy + x;
		zy = fabs(2 * zx * zy) + y;
		zx = xtemp;
		iter++;
	}
	return (color(data, iter));
}
