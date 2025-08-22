/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:18:10 by whwang            #+#    #+#             */
/*   Updated: 2025/04/08 13:17:12 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recur_putnbr(unsigned int n, int fd)
{
	if (n > 9)
		recur_putnbr(n / 10, fd);
	write(fd, &"0123456789"[n % 10], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;

	temp = n * (n > 0) + n * (n < 0) * -1;
	if (n < 0)
		write(fd, &"-", 1);
	recur_putnbr(temp, fd);
}
