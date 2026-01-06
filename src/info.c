/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:02:38 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 16:10:40 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print(t_data *data, char *s, int *y)
{
	mlx_string_put(data->mlx, data->fractal->win, 6, *y + 1, 0x000000, s);
	mlx_string_put(data->mlx, data->fractal->win, 5, *y, 0xFFFFFF, s);
	*y += 15;
}

static void	print_fractal(t_data *data, int *y)
{
	if (data->options->fractal == MANDLEBROT)
		print(data, "fractal = Mandelbrot", y);
	if (data->options->fractal == JULIA)
		print(data, "fractal = Julia", y);
	if (data->options->fractal == BURNING_SHIP)
		print(data, "fractal = Burning Ship", y);
}

static void	print_iter(t_data *data, int *y)
{
	char	*max_iter;
	char	*buf;

	max_iter = ft_itoa(data->max_iter);
	buf = ft_strjoin("max_iter = ", max_iter);
	free(max_iter);
	print(data, buf, y);
	free(buf);
}

static void	print_commands(t_data *data, int *y)
{
	*y += 5;
	print(data, "Commands:", y);
	print(data, "Arrow Keys = pan view", y);
	print(data, "Mouse wheel up / down = zoom", y);
	print(data, "'-' / '+' = zoom", y);
	print(data, "'[' / ']' = chnage max iter", y);
	print(data, "';' / ''' = chnage color", y);
	print(data, "'R' = reset view", y);
	print(data, "'F' = change fractal", y);
	print(data, "'O' = toggle disco", y);
	print(data, "'M' = toggle Julia map", y);
	print(data, "'P' = toggle info", y);
}

void	print_info(t_data *data)
{
	int	y;

	y = 15;
	if (!data->info)
		return ;
	print_fractal(data, &y);
	print_iter(data, &y);
	print_commands(data, &y);
}
