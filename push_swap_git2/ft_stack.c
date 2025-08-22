/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:26:17 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 16:37:45 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"
#include <stdlib.h>

void	ft_stack_add_reverse(t_stack *stack, int data, int idx)
{
	t_node	*new_node;
	t_node	*cur;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->idx = idx;
	if (!stack->head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->head = new_node;
		stack->bottom = new_node;
	}
	else
	{
		cur = stack->bottom;
		cur->next = new_node;
		new_node->prev = cur;
		new_node->next = stack->head;
		stack->bottom = new_node;
		stack->head->prev = new_node;
	}
	stack->size++;
}

void	ft_stack_add(t_stack *stack, int data, int idx)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->idx = idx;
	if (!stack->head)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->head = new_node;
		stack->bottom = new_node;
	}
	else
	{
		new_node->next = stack->head;
		new_node->prev = stack->head->prev;
		stack->head->prev->next = new_node;
		stack->head->prev = new_node;
		stack->head = new_node;
		stack->bottom = stack->head->prev;
	}
	stack->size++;
}

void	ft_stack_free(t_stack *s)
{
	t_node	*cur;
	t_node	*start;
	t_node	*next;

	if (!s)
		return ;
	if (s->head)
	{
		cur = s->head;
		start = s->head;
		while (1)
		{
			next = cur->next;
			free(cur);
			if (next == start)
				break ;
			cur = next;
		}
	}
	free(s);
}

t_stack	*ft_make_stack(void)
{
	t_stack	*temp;

	temp = malloc(sizeof(t_stack));
	if (!temp)
		return (0);
	temp->head = 0;
	temp->bottom = 0;
	temp->size = 0;
	return (temp);
}
