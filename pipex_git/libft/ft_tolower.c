/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:33:56 by whwang            #+#    #+#             */
/*   Updated: 2025/04/08 20:12:34 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	tmp;

	tmp = (unsigned char)c;
	if ('A' <= tmp && tmp <= 'Z')
		tmp += 32;
	return (tmp);
}
