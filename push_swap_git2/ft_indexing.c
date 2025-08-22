/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:29:21 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 14:36:22 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_qsort(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	if (start < end)
	{
		pivot = arr[(start + end) / 2];
		i = start;
		j = end;
		while (i <= j)
		{
			while (arr[i] < pivot)
				i++;
			while (arr[j] > pivot)
				j--;
			if (i <= j)
			{
				ft_swap(&arr[i], &arr[j]);
				i++;
				j--;
			}
		}
		ft_qsort(arr, start, j);
		ft_qsort(arr, i, end);
	}
}

int	*ft_indexing(int *arr, int a_size)
{
	int	*temp;
	int	i;

	i = 0;
	temp = malloc(sizeof(temp) * a_size);
	while (i < a_size)
	{
		temp[i] = arr[i];
		i++;
	}
	ft_qsort(temp, 0, a_size - 1);
	return (temp);
}
