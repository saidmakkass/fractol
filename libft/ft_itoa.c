/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:50:39 by smakkass          #+#    #+#             */
/*   Updated: 2025/12/08 21:00:28 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*rec_itoi(char *str, int n, size_t *i)
{
	if (n < 0)
	{
		n *= -1;
		str[(*i)++] = '-';
	}
	if (n < 10)
	{
		str[(*i)++] = n + '0';
	}
	else
	{
		rec_itoi(str, n / 10, i);
		rec_itoi(str, n % 10, i);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	nbrlen;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbrlen = ft_nbrlen(n);
	str = malloc(nbrlen + 1);
	if (!str)
		return (NULL);
	i = 0;
	str = rec_itoi(str, n, &i);
	str[nbrlen] = '\0';
	return (str);
}
