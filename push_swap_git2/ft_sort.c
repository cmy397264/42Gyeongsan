/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:57:17 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 14:41:31 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 0;
	while (a->size != 0)
	{
		if (a->head->idx <= i)
		{
			ft_ps(b, a, 0);
			++i;
		}
		else if (a->head->idx <= i + chunk)
		{
			ft_ps(b, a, 0);
			ft_rs(b, 0, 1);
			++i;
		}
		else
			ft_rs(a, 1, 1);
	}
}

void	set_top_stack(t_stack *s, int target, int is_a)
{
	int		cnt;
	int		i;
	t_node	*st;
	t_node	*sb;

	st = s->head;
	sb = s->bottom;
	cnt = 0;
	i = -1;
	while (st->idx != target && sb->idx != target)
	{
		cnt++;
		st = st->next;
		sb = sb->prev;
	}
	if (st->idx == target)
	{
		while (++i < cnt)
			ft_rs(s, is_a, 1);
	}
	else
	{
		while (++i < cnt + 1)
			ft_rrs(s, is_a, 1);
	}
}

void	b_to_a(t_stack *a, t_stack *b, int d_size)
{
	int	i;

	i = d_size - 1;
	while (b->size != 0)
	{
		set_top_stack(b, i, 0);
		ft_ps(a, b, 1);
		--i;
	}
}

int	get_chunk(int n)
{
	int	i;

	i = 1;
	while (i < n / 2 + 1)
	{
		if (i * i >= n)
			break ;
		i++;
	}
	return (i);
}

void	ft_chunk_sort(t_stack *a, t_stack *b, int d_size)
{
	int	chunk;

	chunk = get_chunk(d_size);
	a_to_b(a, b, chunk);
	b_to_a(a, b, d_size);
}
