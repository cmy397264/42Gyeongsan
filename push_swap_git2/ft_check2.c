/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:06:19 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 14:26:12 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int	ft_check_unique(int *dest, int *src, int d_size, int s_size)
{
	int	j;
	int	k;

	j = 0;
	while (j < s_size)
	{
		k = 0;
		while (k < d_size)
		{
			if (dest[k] == src[j])
				return (1);
			k++;
		}
		dest[d_size] = src[j];
		j++;
		d_size++;
	}
	return (0);
}

int	*ft_merge(int *a, int *na, int asize, int nsize)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * (asize + nsize));
	if (!temp)
		return (0);
	i = 0;
	while (i < asize)
	{
		temp[i] = a[i];
		i++;
	}
	if (ft_check_unique(temp, na, asize, nsize))
	{
		free(temp);
		temp = 0;
	}
	free(a);
	free(na);
	return (temp);
}

int	ft_is_sorted(t_stack *s, int tc)
{
	t_node	*cur;
	t_node	*start;
	int		prev_data;

	if (tc <= 1)
		return (1);
	cur = s->head->next;
	start = s->head;
	prev_data = start->data;
	while (cur)
	{
		if (cur == start)
			break ;
		if (prev_data > cur->data)
			return (0);
		prev_data = cur->data;
		cur = cur->next;
	}
	return (1);
}
