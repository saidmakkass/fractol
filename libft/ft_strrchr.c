/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:42:55 by smakkass          #+#    #+#             */
/*   Updated: 2025/10/21 09:52:08 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	p += ft_strlen(s);
	while (p >= s)
	{
		if ((unsigned char)*p == (unsigned char)c)
			return (p);
		p--;
	}
	return (NULL);
}
