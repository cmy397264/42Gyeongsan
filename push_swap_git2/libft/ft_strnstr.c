/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:01:38 by whwang            #+#    #+#             */
/*   Updated: 2025/04/10 13:08:23 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *b, char *l, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	i = 0;
	if (*l == 0)
		return (b);
	l_len = ft_strlen(l);
	while (b[i] && i < len)
	{
		j = 0;
		while (l[j] && b[i + j] && b[i + j] == l[j])
			j++;
		if (j == l_len && i + j <= len)
			return (b + i);
		i++;
	}
	return (0);
}
