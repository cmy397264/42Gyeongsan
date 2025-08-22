/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:02:52 by whwang            #+#    #+#             */
/*   Updated: 2025/08/21 17:18:05 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *s, char c)
{
	short	is_word;
	int		wc;

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

char	*get_word(char *s, char c,	int *j)
{
	int		start;
	int		len;
	int		k;
	char	*ret;

	start = *j;
	while (s[*j] && s[*j] != c)
		(*j)++;
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
	return (ret);
}

void	free_words(char **arr,	int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

short	put_word(char *s, char **arr, char c, int wc)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < wc)
	{
		while (s[j] && s[j] == c)
			++j;
		if (!s[j])
		{
			free_words(arr, i);
			return (0);
		}
		arr[i] = get_word(s, c, &j);
		while (s[j] && s[j] == c)
			++j;
		if (!arr[i])
		{
			free_words(arr, i);
			return (0);
		}
	}
	return (1);
}

char	**ft_split(char	*s, char c)
{
	int		w;
	char	**arr;

	w = count_word(s, c);
	arr = (char **)malloc(sizeof(char *) * (w + 1));
	if (!arr)
		return (0);
	arr[w] = (char *)0;
	if (!put_word(s, arr, c, w))
		return (0);
	return (arr);
}
