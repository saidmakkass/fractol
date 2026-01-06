/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:00:16 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/06 17:10:19 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	lower(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		*s = ft_tolower(*s);
		s++;
	}
}

static void	parse_fractal(t_data *data, char *arg)
{
	if (!arg)
		return ;
	if (!ft_strcmp("m", arg) || !ft_strcmp("mandelbrot", arg))
		data->options->fractal = MANDLEBROT;
	else if (!ft_strcmp("j", arg) || !ft_strcmp("julia", arg))
		data->options->fractal = JULIA;
	else if (!ft_strcmp("b", arg) || !ft_strcmp("burning_ship", arg))
		data->options->fractal = BURNING_SHIP;
	else
		usage(data);
}

static void	parse_size(t_data *data, char *arg)
{
	if (!arg)
		usage(data);
	if (ft_isdigit(*arg))
		data->options->width = ft_atoi(arg);
	else
		usage(data);
	while (ft_isdigit(*arg))
		arg++;
	if (*arg == 'x' || *arg == 'X')
		arg++;
	else
		usage(data);
	if (ft_isdigit(*arg))
		data->options->height = ft_atoi(arg);
	else
		usage(data);
	while (ft_isdigit(*arg))
		arg++;
	if (*arg)
		usage(data);
}

static void	parse_julia(t_data *data, char *arg)
{
	int	sign;

	sign = 1;
	data->options->julia_x = ft_atof(data, &arg);
	while (ft_isspace(*arg))
		arg++;
	if (*arg == '+')
		arg++;
	else if (*arg == '-')
	{
		sign = -1;
		arg++;
	}
	else
		usage(data);
	while (ft_isspace(*arg))
		arg++;
	data->options->julia_y = sign * ft_atof(data, &arg);
	if (*arg == 'i')
		arg++;
	else
		usage(data);
	if (*arg)
		usage(data);
}

void	parse_args(t_data *data, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		usage(data);
	lower(argv[1]);
	parse_fractal(data, argv[1]);
	i = 2;
	while (i < argc)
	{
		lower(argv[i]);
		if (!ft_strcmp("-s", argv[i]))
			parse_size(data, argv[++i]);
		else if (data->options->fractal == JULIA)
			parse_julia(data, argv[i]);
		else
			usage(data);
		i++;
	}
}
