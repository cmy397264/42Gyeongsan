/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:02:52 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 15:11:02 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char *s, char c)
{
	short	is_word;
	size_t	wc;

	is_word = 1;
	wc = 0;
	while (*s)
	{
		if (is_word && *s != c)
		{
			is_word = 0;
			wc++;
		}
		else if (*s == c)
			is_word = 1;
		s++;
	}
	return (wc);
}

char	*get_word(char *s, char c, size_t idx, size_t s_len)
{
	size_t	i;
	size_t	len;
	char	*word;

	len = 0;
	while (idx + len < s_len && s[idx + len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * len + 1);
	if (!word)
		return (0);
	i = 0;
	while (len > 0)
	{
		word[i] = s[i + idx];
		i++;
		len--;
	}
	word[i] = '\0';
	return (word);
}

void	free_words(char **arr, size_t i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

short	put_word(char *s, char **arr, char c, size_t wc)
{
	size_t	i;
	size_t	j;
	size_t	s_len;

	i = -1;
	j = 0;
	s_len = ft_strlen(s);
	while (++i < wc)
	{
		while (s[j] == c && j < s_len)
			j++;
		arr[i] = get_word(s, c, j, s_len);
		if (!arr[i])
		{
			free_words(arr, i);
			return (0);
		}
		while (s[j] != c && j < s_len)
			j++;
	}
	return (1);
}

char	**ft_split(char	*s, char c, int *wc)
{
	size_t	w;
	char	**arr;

	w = count_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (w + 1));
	if (!arr)
		return (0);
	arr[w] = (char *)0;
	if (!put_word(s, arr, c, w))
		return (0);
	*wc += w;
	return (arr);
}
