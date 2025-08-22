/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:37:35 by whwang            #+#    #+#             */
/*   Updated: 2025/04/12 12:16:25 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	s_len;
	size_t	i;

	i = 1;
	s_len = ft_strlen(src);
	if (n)
	{
		while (i < n && *src)
		{
			*dest = *src;
			i++;
			src++;
			dest++;
		}
		*dest = '\0';
	}
	return (s_len);
}
