/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:13:36 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/10 15:33:27 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putcharf(t_printf_data *data, unsigned char c)
{
	const t_format	format = data->format;

	if (format.minus)
	{
		write_output(data, c);
		write_padding(data, ' ', format.width - 1);
	}
	else
	{
		write_padding(data, ' ', format.width - 1);
		write_output(data, c);
	}
}
