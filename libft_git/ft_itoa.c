/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:37:21 by whwang            #+#    #+#             */
/*   Updated: 2025/04/12 11:05:24 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	put_c(char *s, size_t last, size_t n)
{
	if (n > 9)
		put_c(s, last - 1, n / 10);
	s[last] = n % 10 + '0';
}

unsigned int	set_temp(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	size_t			wl;
	char			*word;
	unsigned int	temp;

	wl = (n <= 0) * 1;
	temp = set_temp(n);
	while (temp > 0)
	{
		wl++;
		temp /= 10;
	}
	word = (char *)malloc(sizeof(char) * wl + 1);
	if (!word)
		return (0);
	word[wl] = '\0';
	if (n < 0)
		word[0] = '-';
	temp = set_temp(n);
	put_c(word, wl - 1, temp);
	return (word);
}
