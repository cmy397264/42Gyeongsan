/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:36:07 by whwang            #+#    #+#             */
/*   Updated: 2025/08/21 11:54:25 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_fp	farr[FD_MAX];
	char		*ret;
	int			start;
	int			b;
	int			st;

	ret = 0;
	b = 0;
	if (fd < 0)
		return (0);
	while (!b)
	{
		st = ft_check_buffer_size(farr[fd].buf, &(farr[fd].idx), fd);
		if (st <= 0)
			return (ret);
		start = farr[fd].idx;
		b = is_enter_or_eof(farr[fd].buf, &(farr[fd].idx));
		ret = get_ret(farr[fd].buf, ret, start, farr[fd].idx);
	}
	return (ret);
}
