/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:48:40 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	u_nbrlen(uintptr_t n)
{
	int	nlen;

	if (n == 0)
		return (1);
	nlen = 0;
	while (n)
	{
		nlen++;
		n /= 10;
	}
	return (nlen);
}

static void	write_putnbr(t_printf_data *data, unsigned int n)
{
	int	i;

	if (n == UINT_MAX)
	{
		i = 0;
		while (i < 10)
			write_output(data, "4294967295"[i++]);
		return ;
	}
	if (n <= 9)
	{
		write_output(data, n + '0');
		return ;
	}
	write_putnbr(data, n / 10);
	write_putnbr(data, n % 10);
}

static int	width_padding_calc(t_printf_data *data, unsigned int n)
{
	const t_format	format = data->format;
	int				nlen;
	int				padding;
	int				written;
	int				digits;

	nlen = u_nbrlen(n);
	if (format.precision == 0 && n == 0)
		nlen = 0;
	digits = nlen;
	written = nlen;
	if (format.precision > digits)
		written += format.precision - digits;
	padding = format.width - written;
	return (padding);
}

void	ft_putunbrf(t_printf_data *data, unsigned int n)
{
	const t_format	format = data->format;
	const int		nlen = u_nbrlen(n);
	char			padd;

	padd = ' ';
	if (format.zero && format.precision < 0)
		padd = '0';
	if (format.minus)
	{
		write_padding(data, '0', format.precision - nlen);
		if (!(format.precision == 0 && n == 0))
			write_putnbr(data, n);
		write_padding(data, ' ', width_padding_calc(data, n));
		return ;
	}
	write_padding(data, padd, width_padding_calc(data, n));
	write_padding(data, '0', format.precision - nlen);
	if (!(format.precision == 0 && n == 0))
		write_putnbr(data, n);
}
