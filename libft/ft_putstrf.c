/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:39:45 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_str(t_printf_data *data, char *s)
{
	const t_format	format = data->format;
	const size_t	slen = ft_strlen(s);
	int				precision;

	precision = data->format.precision;
	if (format.minus)
	{
		while (*s && (precision == -1 || precision-- > 0))
			write_output(data, *s++);
		if ((size_t)format.precision > slen)
			write_padding(data, ' ', format.width - slen);
		else
			write_padding(data, ' ', format.width - format.precision);
	}
	else
	{
		if ((size_t)format.precision > slen)
			write_padding(data, ' ', format.width - slen);
		else
			write_padding(data, ' ', format.width - format.precision);
		while (*s && (precision == -1 || precision-- > 0))
			write_output(data, *s++);
	}
}

void	ft_putstrf(t_printf_data *data, char *s)
{
	const t_format	format = data->format;

	if (!s)
	{
		if (format.precision >= 0 && format.precision < 6)
		{
			s = "";
			write_str(data, s);
			return ;
		}
		s = "(null)";
	}
	write_str(data, s);
}
