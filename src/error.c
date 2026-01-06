/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:29 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 17:32:59 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_data(t_data *data)
{
	if (data->options)
		free(data->options);
	if (data->fractal)
	{
		if (data->fractal->img_ptr)
			mlx_destroy_image(data->mlx, data->fractal->img_ptr);
		if (data->fractal->win)
			mlx_destroy_window(data->mlx, data->fractal->win);
		free(data->fractal);
	}
	if (data->map)
		end_map(data);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

static void	print_fractals(void)
{
	ft_putstr_fd("Fractals:\n", 2);
	ft_putstr_fd("\tJ, Julia\n", 2);
	ft_putstr_fd("\tM, Mandelbrot\n", 2);
	ft_putstr_fd("\tB, Burning_ship\n", 2);
}

static void	print_options(void)
{
	ft_putstr_fd("Options:\n", 2);
	ft_putstr_fd("\t-j <c>\n", 2);
	ft_putstr_fd("\t\tset the constant c for the Julia fractal.\n", 2);
	ft_putstr_fd("\t\tDefault: 0.285 + 0.01i.\n", 2);
	ft_putstr_fd("\t-s <size>\n", 2);
	ft_putstr_fd("\t\tset the size of the window.\n", 2);
	ft_putstr_fd("\t\tDefault: 600x600.\n", 2);
}

static void	print_examples(t_data *data)
{
	ft_putstr_fd("Examples:\n\t", 2);
	ft_putstr_fd(data->name, 2);
	ft_putstr_fd(" Julia -j \"-0.8 + 0.156i\"\n\t", 2);
	ft_putstr_fd(data->name, 2);
	ft_putstr_fd(" Mandelbrot\n\t", 2);
	ft_putstr_fd(data->name, 2);
	ft_putstr_fd(" Burning_ship -s 800x800\n", 2);
}

void	usage(t_data *data)
{
	ft_putstr_fd("Invalid or no arguments\n", 2);
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(data->name, 2);
	ft_putstr_fd(" <fractal> [options]\n", 2);
	print_fractals();
	print_options();
	print_examples(data);
	ft_putstr_fd("Hint:\n\tHit \"P\" when running to show commands.\n", 2);
	clear_data(data);
	exit(1);
}
