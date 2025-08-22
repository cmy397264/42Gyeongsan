/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_hc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:57:28 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 14:46:30 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_hc_case2(t_stack *a)
{
	int	size;

	size = a->size;
	if (a->head->idx == size - 1)
		ft_rs(a, 1, 1);
}

void	ft_hc_case3(t_stack *a, int size)
{
	if (a->bottom->idx == size - 3)
	{
		if (a->head->idx == size - 2)
			ft_rrs(a, 1, 1);
		else
		{
			ft_s(a, 1, 1);
			ft_rrs(a, 1, 1);
		}
	}
	else if (a->bottom->idx == size - 2)
	{
		if (a->head->idx == size - 3)
		{
			ft_rrs(a, 1, 1);
			ft_s(a, 1, 1);
		}
		else
			ft_rs(a, 1, 1);
	}
	else
		ft_s(a, 1, 1);
}

void	ft_hc_case4(t_stack *a, t_stack *b, int size)
{
	set_top_stack(a, 0, 1);
	if (ft_is_sorted(a, size))
		return ;
	ft_ps(b, a, 0);
	ft_hc_case3(a, size);
	ft_ps(a, b, 1);
}

void	ft_hc_case5(t_stack *a, t_stack *b, int size)
{
	set_top_stack(a, 0, 1);
	if (ft_is_sorted(a, size))
		return ;
	ft_ps(b, a, 0);
	set_top_stack(a, 1, 1);
	if (!ft_is_sorted(a, size))
	{
		ft_ps(b, a, 0);
		ft_hc_case3(a, size);
		ft_ps(a, b, 1);
	}
	ft_ps(a, b, 1);
}

void	ft_hc_sort(t_stack *a, t_stack *b, int d_size)
{
	int	size;

	size = a->size;
	if (d_size == 2)
		ft_hc_case2(a);
	else if (d_size == 3)
		ft_hc_case3(a, size);
	else if (d_size == 4)
		ft_hc_case4(a, b, size);
	else if (d_size == 5)
		ft_hc_case5(a, b, size);
	else
		return ;
}
