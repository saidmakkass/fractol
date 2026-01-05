/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 23:27:40 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	printf_loop(t_printf_data *data)
{
	while (*data->s)
	{
		if (!data->error && *data->s == '%' && !(*(data->s + 1)))
			data->error = true;
		if (!data->error && *data->s == '%' && *(data->s + 1) && *data->s++)
		{
			parser(data);
			write_var(data);
		}
		else if ((data->error && *(data->s + 1)) || !(*data->s == '%'))
		{
			write_output(data, *data->s);
			data->error = false;
			data->s++;
		}
		else
			data->s++;
	}
}

int	ft_printf(const char *format_str, ...)
{
	t_printf_data	data;

	ft_bzero(&data, sizeof(t_printf_data));
	data.s = (char *)format_str;
	va_start(data.args, format_str);
	printf_loop(&data);
	va_end(data.args);
	if (data.error)
		return (-1);
	return (data.written);
}
