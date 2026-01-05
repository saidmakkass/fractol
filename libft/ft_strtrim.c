/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:47:52 by smakkass          #+#    #+#             */
/*   Updated: 2025/10/19 16:36:12 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	size_t	pref;
	size_t	suff;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	slen = ft_strlen(s1);
	pref = 0;
	while (ft_strchr(set, s1[pref]))
		pref++;
	if (pref >= slen)
		return (ft_strdup(""));
	suff = 0;
	while (ft_strchr(set, s1[slen - suff - 1]))
		suff++;
	trimmed = malloc(slen - suff - pref + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + pref, slen - pref - suff + 1);
	return (trimmed);
}
