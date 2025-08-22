/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:32:17 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 14:50:50 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_find_idx(int *i_dict, int d_size, int n)
{
	int	i;

	i = 0;
	while (i < d_size)
	{
		if (n == i_dict[i])
			return (i);
		i++;
	}
	return (0);
}

void	ft_sort_init(t_stack *a, int *dict, int *i_dict, int d_size)
{
	int	i;
	int	idx;

	i = 0;
	while (i < d_size)
	{
		idx = ft_find_idx(i_dict, d_size, dict[i]);
		ft_stack_add_reverse(a, dict[i++], idx);
	}
	a->size = i;
	free(i_dict);
}

void	ft_sort_process(int *dict, int d_size)
{
	t_stack	*a;
	t_stack	*b;
	int		*indexing_dict;

	indexing_dict = ft_indexing(dict, d_size);
	a = ft_make_stack();
	b = ft_make_stack();
	if (!a)
		return ;
	ft_sort_init(a, dict, indexing_dict, d_size);
	if (!ft_is_sorted(a, d_size))
	{
		if (d_size <= 5)
			ft_hc_sort(a, b, d_size);
		else
			ft_chunk_sort(a, b, d_size);
	}
	ft_stack_free(a);
	ft_stack_free(b);
}
