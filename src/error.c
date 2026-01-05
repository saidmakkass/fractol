/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:29 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 22:07:28 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	quit(t_data *data)
{
	clear_data(data);
	exit(0);
	return (0);
}

void	clear_data(t_data *data)
{
	if (data->options)
		free(data->options);
	if (data->img_data)
	{
		mlx_destroy_image(data->mlx, data->img_data->img_ptr);
		free(data->img_data);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

static void	print_fractals(void)
{
	ft_putstr_fd("Fractals:\n", 2);
	ft_putstr_fd("\tM (Mandelbrot)\n", 2);
	ft_putstr_fd("\tJ (Julia)\n", 2);
	ft_putstr_fd("\tB (Burning_ship)\n", 2);
}

static void	print_options(void)
{
	ft_putstr_fd("Options:\n", 2);
	ft_putstr_fd("\t-s <size>\t//example: -s 800x800\n", 2);
	ft_putstr_fd("\t-j <c>\t\t//example: -j \"-0.8 + 0.156i\"\n", 2);
}

void	usage(t_data *data)
{
	ft_putstr_fd("Invalid or no arguments\n", 2);
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(data->name, 2);
	ft_putstr_fd(" <fractal> [options]\n", 2);
	print_fractals();
	print_options();
	ft_putstr_fd("Hint:\n\tHit \"P\" when running to show commands.\n", 2);
	clear_data(data);
	exit(1);
}
