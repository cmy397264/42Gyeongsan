/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:51:27 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 14:32:19 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rs(t_stack *s, int is_a, int is_print)
{
	s->head = s->head->next;
	s->bottom = s->bottom->next;
	if (is_a && is_print)
		write(1, "ra\n", 3);
	else if (!is_a && is_print)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rs(a, 1, 0);
	ft_rs(b, 0, 0);
	write(1, "rr\n", 3);
}

void	ft_rrs(t_stack *s, int is_a, int is_print)
{
	s->head = s->head->prev;
	s->bottom = s->bottom->prev;
	if (is_a && is_print)
		write(1, "rra\n", 4);
	else if (!is_a && is_print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rrs(a, 1, 0);
	ft_rrs(b, 0, 0);
	write(1, "rrr\n", 4);
}
