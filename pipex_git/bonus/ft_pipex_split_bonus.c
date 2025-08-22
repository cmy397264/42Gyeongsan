/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:12:30 by whwang            #+#    #+#             */
/*   Updated: 2025/08/21 17:25:16 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	convert_quote(short *is_word, size_t *wc)
{
	if (!*is_word)
	{
		*is_word = 1;
		++*wc;
	}
}

static size_t	pipex_count_word(char *s, char c)
{
	short	is_word;
	short	in_quote;
	size_t	wc;

	is_word = 0;
	in_quote = 0;
	wc = 0;
	while (*s)
	{
		if (*s == '\'')
		{
			in_quote = !in_quote;
			convert_quote(&is_word, &wc);
		}
		else if (*s == c && !in_quote)
			is_word = 0;
		else if (!is_word)
			convert_quote(&is_word, &wc);
		s++;
	}
	return (wc);
}

static char	*pipex_get_word(char *s, int *j)
{
	int		start;
	int		len;
	int		k;
	char	*ret;

	(*j)++;
	start = *j;
	while (s[*j] && s[*j] != '\'')
		(*j)++;
	if (s[*j] != '\'')
		return (0);
	len = *j - start;
	ret = (char *)malloc((size_t)len + 1);
	if (!ret)
		return (0);
	k = 0;
	while (k < len)
	{
		ret[k] = s[start + k];
		k++;
	}
	ret[len] = '\0';
	(*j)++;
	return (ret);
}

short	pipex_put_word(char *s, char **arr, char c, int wc)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < wc)
	{
		while (s[j] && s[j] == c)
			j++;
		if (!s[j])
		{
			free_words(arr, i);
			return (0);
		}
		if (s[j] == '\'')
			arr[i] = pipex_get_word(s, &j);
		else
			arr[i] = get_word(s, c, &j);
		if (!arr[i])
		{
			free_words(arr, i);
			return (0);
		}
	}
	return (1);
}

char	**pipex_split(char *s, char delim)
{
	int		w;
	char	**arr;

	w = pipex_count_word(s, delim);
	arr = (char **)malloc(sizeof(char *) * (w + 1));
	if (!arr)
		return (0);
	arr[w] = (char *)0;
	if (!pipex_put_word(s, arr, delim, w))
		return (0);
	return (arr);
}
