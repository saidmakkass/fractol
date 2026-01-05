/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:22:48 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_hex(t_printf_data *data, uintptr_t n)
{
	const char	*base = "0123456789abcdef";

	if (n < 16)
	{
		write_output(data, base[n]);
		return ;
	}
	write_hex(data, n / 16);
	write_hex(data, n % 16);
}

static int	width_padding_calc(t_printf_data *data, unsigned int n, int nlen)
{
	const t_format	format = data->format;
	int				padding;
	int				written;
	int				digits;

	if (format.precision == 0 && n == 0)
		nlen = 0;
	digits = nlen;
	written = nlen;
	if (format.hash && n)
		written += 2;
	if (format.precision > digits)
		written += format.precision - digits;
	padding = format.width - written;
	return (padding);
}

void	ft_puthex_lower(t_printf_data *data, unsigned int n)
{
	const t_format	format = data->format;
	const int		nlen = hex_len(n);
	char			padd;

	padd = ' ';
	if (format.zero && format.precision < 0)
		padd = '0';
	if (format.minus)
	{
		if (n)
			write_prefix(data);
		write_padding(data, '0', format.precision - nlen);
		if (!(format.precision == 0 && n == 0))
			write_hex(data, n);
		write_padding(data, ' ', width_padding_calc(data, n, nlen));
		return ;
	}
	write_padding(data, padd, width_padding_calc(data, n, nlen));
	if (n)
		write_prefix(data);
	write_padding(data, '0', format.precision - nlen);
	if (!(format.precision == 0 && n == 0))
		write_hex(data, n);
}
