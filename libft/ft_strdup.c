/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:09:15 by smakkass          #+#    #+#             */
/*   Updated: 2025/10/18 13:38:08 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*p;
	int		i;

	slen = ft_strlen(s);
	p = malloc(slen + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i <= slen)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}
