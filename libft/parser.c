/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:12:26 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	parse_flags(t_printf_data *data, int *steps)
{
	while (*data->s && ft_strchr("-0# +", *data->s))
	{
		if (*data->s == '-')
			data->format.minus = true;
		else if (*data->s == '0')
			data->format.zero = true;
		else if (*data->s == '#')
			data->format.hash = true;
		else if (*data->s == ' ')
			data->format.space = true;
		else if (*data->s == '+')
			data->format.plus = true;
		data->s++;
		(*steps)++;
	}
}

static void	parse_width(t_printf_data *data, int *steps)
{
	int	var;

	if (ft_isdigit(*data->s))
	{
		data->format.width = ft_atoi(data->s);
		data->s += ft_nbrlen(data->format.width);
		*steps += ft_nbrlen(data->format.width);
	}
	else if (*data->s == '*')
	{
		var = va_arg(data->args, int);
		if (var < 0)
		{
			var = -var;
			data->format.minus = true;
		}
		data->format.width = var;
		data->s++;
		(*steps)++;
	}
}

static void	parse_precision(t_printf_data *data, int *steps)
{
	int	var;

	if (*data->s == '.')
	{
		data->format.precision = 0;
		data->s++;
		(*steps)++;
		if (ft_isdigit(*data->s))
		{
			data->format.precision = ft_atoi(data->s);
			data->s += ft_nbrlen(data->format.precision);
			*steps += ft_nbrlen(data->format.precision);
		}
		else if (*data->s == '*')
		{
			var = va_arg(data->args, int);
			if (var >= 0)
				data->format.precision = var;
			else
				data->format.precision = -1;
			data->s++;
			(*steps)++;
		}
	}
}

static void	parse_specifier(t_printf_data *data, int *steps)
{
	if (*(data->s) && ft_strchr("cspdiuxX%", *data->s))
	{
		data->format.specifier = *data->s;
		(data->s)++;
		(*steps)++;
	}
	else if (*(data->s))
	{
		data->error = true;
		(data->s) -= *steps + 1;
	}
	else
		data->error = true;
}

void	parser(t_printf_data *data)
{
	int	steps;

	steps = 0;
	if (*(data->s))
	{
		ft_bzero(&data->format, sizeof(t_format));
		data->format.precision = -1;
		parse_flags(data, &steps);
		parse_width(data, &steps);
		parse_precision(data, &steps);
		parse_specifier(data, &steps);
	}
}
