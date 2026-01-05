/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:19:52 by smakkass          #+#    #+#             */
/*   Updated: 2025/10/26 15:06:39 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	little_len;

	if (!big && !len)
		return (NULL);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (big[i] == little[0])
			if (!ft_strncmp(&big[i], little, little_len))
				return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
