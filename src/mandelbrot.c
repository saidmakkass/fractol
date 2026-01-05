/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:26 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 15:35:49 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data, double x, double y)
{
	double	zx;
	double	zy;
	int		iter;
	double	xtemp;

	zx = 0;
	zy = 0;
	iter = 0;
	while (zx * zx + zy * zy <= 4.0 && iter < data->max_iter)
	{
		xtemp = zx * zx - zy * zy + x;
		zy = 2.0 * zx * zy + y;
		zx = xtemp;
		iter++;
	}
	return (color(data, iter));
}
