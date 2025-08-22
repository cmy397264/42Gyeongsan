/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:01:16 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 14:30:37 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stack *s, int is_a, int is_print)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	if (!s->head || s->head == s->bottom)
		return ;
	first = s->head;
	second = s->head->next;
	third = second->next;
	last = s->head->prev;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	third->prev = first;
	s->head = second;
	if (is_a && is_print)
		write(1, "sa\n", 3);
	else if (!is_a && is_print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_s(a, 1, 0);
	ft_s(b, -1, 0);
	write(1, "ss\n", 3);
}

void	ft_ps(t_stack *dest, t_stack *src, int is_a)
{
	t_node	*temp;

	temp = src->head;
	if (src->size == 0)
		return ;
	if (src->size == 1)
	{
		src->head = NULL;
		src->bottom = NULL;
	}
	else
	{
		src->head = temp->next;
		src->head->prev = src->bottom;
		if (temp == src->bottom)
			src->bottom = src->head->prev;
		src->bottom->next = src->head;
	}
	src->size--;
	ft_stack_add(dest, temp->data, temp->idx);
	free(temp);
	if (is_a)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
