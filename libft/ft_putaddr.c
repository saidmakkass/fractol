/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:38:21 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_addr(t_printf_data *data, uintptr_t n)
{
	const char	*base = "0123456789abcdef";

	if (n < 16)
	{
		write_output(data, base[n]);
		return ;
	}
	write_addr(data, n / 16);
	write_addr(data, n % 16);
}

static int	width_padding_calc(t_printf_data *data, int nlen)
{
	const t_format	format = data->format;
	int				padding;
	int				written;
	int				digits;

	digits = nlen;
	written = nlen;
	written += 2;
	if (format.plus || format.space)
		written++;
	if (format.precision > digits)
		written += format.precision - digits;
	padding = format.width - written;
	return (padding);
}

static bool	write_nil(t_printf_data *data, uintptr_t n)
{
	t_printf_data	data_copy;

	data_copy = *data;
	if (!n)
	{
		data_copy.format.precision = -1;
		ft_putstrf(&data_copy, "(nil)");
		data->written = data_copy.written;
		return (1);
	}
	else
		return (0);
}

static void	write_addr_sign(t_printf_data *data)
{
	const t_format	format = data->format;

	if (format.plus)
		write_output(data, '+');
	else if (format.space)
		write_output(data, ' ');
}

void	ft_putaddr(t_printf_data *data, void *p)
{
	const t_format	format = data->format;
	const uintptr_t	n = (uintptr_t)p;
	const int		nlen = hex_len(n);

	if (write_nil(data, n))
		return ;
	if (format.minus)
	{
		write_addr_sign(data);
		write_prefix(data);
		write_padding(data, '0', format.precision - nlen);
		write_addr(data, n);
		write_padding(data, ' ', width_padding_calc(data, nlen));
		return ;
	}
	write_padding(data, ' ', width_padding_calc(data, nlen));
	write_addr_sign(data);
	write_prefix(data);
	write_padding(data, '0', format.precision - nlen);
	write_addr(data, n);
}
