/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:24:32 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_prefix(t_printf_data *data)
{
	const t_format	format = data->format;

	if (format.specifier == 'p')
	{
		write_output(data, '0');
		write_output(data, 'x');
	}
	else if ((format.hash && format.specifier == 'x'))
	{
		write_output(data, '0');
		write_output(data, 'x');
	}
	else if (format.hash && format.specifier == 'X')
	{
		write_output(data, '0');
		write_output(data, 'X');
	}
}

void	write_var(t_printf_data *data)
{
	char	specifier;

	specifier = data->format.specifier;
	if (specifier == 'c')
		ft_putcharf(data, va_arg(data->args, int));
	else if (specifier == 's')
		ft_putstrf(data, va_arg(data->args, char *));
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbrf(data, va_arg(data->args, int));
	else if (specifier == 'u')
		ft_putunbrf(data, va_arg(data->args, unsigned int));
	else if (specifier == 'x')
		ft_puthex_lower(data, va_arg(data->args, unsigned int));
	else if (specifier == 'X')
		ft_puthex_upper(data, va_arg(data->args, unsigned int));
	else if (specifier == 'p')
		ft_putaddr(data, va_arg(data->args, void *));
	else if (specifier == '%')
		write_output(data, '%');
}

void	write_padding(t_printf_data *data, char c, int n)
{
	while (n > 0 && n--)
		write_output(data, c);
}

void	write_output(t_printf_data *data, char c)
{
	data->written += write(1, &c, 1);
}
