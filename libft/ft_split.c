/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakkass <smakkass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:47:38 by smakkass          #+#    #+#             */
/*   Updated: 2025/10/20 13:43:07 by smakkass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_arr(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
}

static char	*next_word(const char **s, char c)
{
	size_t	len;
	char	*word;

	while (**s == c && **s)
		(*s)++;
	len = 0;
	while ((*s)[len] != c && (*s)[len])
		len++;
	word = ft_substr(*s, 0, len);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		arr[i] = next_word(&s, c);
		if (!arr[i])
		{
			free_arr(arr, i);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
