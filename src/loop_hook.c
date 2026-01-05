/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:29:22 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 19:29:47 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	loop_hook(t_data *data)
{
	if (data->disco)
	{
		data->color++;
		if (data->color > 1000)
			data->color = 0;
		plot(data);
	}
	return (0);
}
