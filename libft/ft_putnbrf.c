/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:20:05 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_nbr(t_printf_data *data, int n)
{
	int	i;

	if (n == INT_MIN)
	{
		i = 0;
		while (i < 10)
			write_output(data, "2147483648"[i++]);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n >= 0 && n <= 9)
	{
		write_output(data, n + '0');
		return ;
	}
	write_nbr(data, n / 10);
	write_nbr(data, n % 10);
}

static void	write_sign(t_printf_data *data, int n)
{
	if (n < 0)
		write_output(data, '-');
	else if (data->format.plus)
		write_output(data, '+');
	else if (data->format.space)
		write_output(data, ' ');
}

static int	width_padding_calc(t_printf_data *data, int n)
{
	const t_format	format = data->format;
	int				nlen;
	int				padding;
	int				written;
	int				digits;

	nlen = ft_nbrlen(n);
	if (format.precision == 0 && n == 0)
		nlen = 0;
	digits = nlen;
	if (n < 0)
		digits--;
	written = nlen;
	if (n >= 0 && (format.plus || format.space))
		written++;
	if (format.precision > digits)
		written += format.precision - digits;
	padding = format.width - written;
	return (padding);
}

static int	precision_padding_calc(t_printf_data *data, int n)
{
	const t_format	format = data->format;
	const int		nlen = ft_nbrlen(n);
	int				padding;
	int				digits;

	digits = nlen;
	if (n < 0)
		digits--;
	padding = format.precision - digits;
	return (padding);
}

void	ft_putnbrf(t_printf_data *data, int n)
{
	const t_format	format = data->format;
	char			padd;

	padd = ' ';
	if (format.zero && format.precision < 0)
		padd = '0';
	if (format.minus)
	{
		write_sign(data, n);
		write_padding(data, '0', precision_padding_calc(data, n));
		if (!(format.precision == 0 && n == 0))
			write_nbr(data, n);
		write_padding(data, ' ', width_padding_calc(data, n));
		return ;
	}
	if (format.zero && format.precision < 0)
		write_sign(data, n);
	write_padding(data, padd, width_padding_calc(data, n));
	if (!(format.zero && format.precision < 0))
		write_sign(data, n);
	write_padding(data, '0', precision_padding_calc(data, n));
	if (!(format.precision == 0 && n == 0))
		write_nbr(data, n);
}
