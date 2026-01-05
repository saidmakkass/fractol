/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:02:38 by smakkass          #+#    #+#             */
/*   Updated: 2026/01/05 18:12:58 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_info(t_data *data)
{
	char	*buf;
	char	*max_iter;

	max_iter = ft_itoa(data->max_iter);
	if (!data->info)
		return ;
	buf = ft_strjoin("max_iter = ", max_iter);
	free(max_iter);
	mlx_string_put(data->mlx, data->win, 6, 16, 0x000000, buf);
	mlx_string_put(data->mlx, data->win, 5, 15, 0xFFFFFF, buf);
	free(buf);
}
