/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:56:44 by whwang            #+#    #+#             */
/*   Updated: 2025/04/06 20:15:11 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	new_s = (char *)malloc(sizeof(char) * s_len + 1);
	if (!new_s)
		return (0);
	new_s[s_len] = '\0';
	i = 0;
	while (i < s_len)
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
