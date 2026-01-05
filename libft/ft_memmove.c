/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:53:34 by smakkass          #+#    #+#             */
/*   Updated: 2025/10/18 14:48:49 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc = src;
	size_t				i;

	cdest = dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*cdest++ = *csrc++;
			i++;
		}
	}
	else if (dest > src)
	{
		i = n;
		while (i)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (dest);
}
