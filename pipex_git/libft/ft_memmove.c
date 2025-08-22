/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:52:34 by whwang            #+#    #+#             */
/*   Updated: 2025/04/08 20:40:42 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	copy_backward(unsigned char *d, unsigned char *s, size_t n)
{
	while (n > 0)
	{
		*(d + n - 1) = *(s + n - 1);
		n--;
	}
}

void	copy_forward(unsigned char *d, unsigned char *s, size_t n)
{
	while (n > 0)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
		copy_backward(d, s, n);
	else
		copy_forward(d, s, n);
	return (dest);
}
