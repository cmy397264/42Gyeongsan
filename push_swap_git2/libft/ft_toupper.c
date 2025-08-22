/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:33:56 by whwang            #+#    #+#             */
/*   Updated: 2025/04/08 20:09:32 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	tmp;

	tmp = (unsigned char)c;
	if ('a' <= tmp && tmp <= 'z')
		tmp -= 32;
	return (tmp);
}
