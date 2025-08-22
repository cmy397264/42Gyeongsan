/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:52:44 by whwang            #+#    #+#             */
/*   Updated: 2025/04/12 12:37:17 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t e_count, size_t e_size)
{
	void	*arr;

	if (!e_count || !e_size)
		return (malloc(0));
	if (SIZE_MAX / e_count < e_size)
		return (0);
	arr = malloc(e_count * e_size);
	if (!arr)
		return (0);
	ft_bzero(arr, e_count * e_size);
	return (arr);
}
