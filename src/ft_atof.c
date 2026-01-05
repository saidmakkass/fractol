/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 15:27:44 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 15:20:26 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	atof_helper(t_data *data, char **s, double result)
{
	double	div;

	div = 1.0;
	if (!ft_isdigit(**s))
		usage(data);
	while (ft_isdigit(**s))
	{
		div *= 10.0;
		result += (*(*s)++ - '0') / div;
	}
	return (result);
}

double	ft_atof(t_data *data, char **s)
{
	int		sign;
	double	result;

	sign = 1;
	result = 0.0;
	if (!s || !*s)
		usage(data);
	if (**s == '-' || **s == '+')
		if (*(*s)++ == '-')
			sign = -1;
	if (!ft_isdigit(**s))
		usage(data);
	while (ft_isdigit(**s))
		result = result * 10.0 + (*(*s)++ - '0');
	if (**s == '.')
		(*s)++;
	else
		usage(data);
	result = atof_helper(data, s, result);
	return (result * sign);
}
