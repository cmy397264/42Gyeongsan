/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:30:37 by whwang            #+#    #+#             */
/*   Updated: 2025/07/24 11:56:23 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#define INT_MAX	2147483647
#define INT_MIN	-2147483648

void	free_str_arr(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(char *s)
{
	long	sum;
	long	is_minus;

	sum = 0;
	is_minus = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			is_minus *= -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		sum *= 10;
		sum += *s - '0';
		s++;
	}
	return (sum * is_minus);
}

int	ft_check_atoi(long a)
{
	if (a > INT_MAX || a < INT_MIN)
		return (1);
	return (0);
}

int	*ft_atoi_arr(char **str, int wc)
{
	int		i;
	long	n;
	int		*arr;

	i = 0;
	arr = malloc(sizeof(int) * wc);
	while (str[i])
	{
		if (ft_check_digit(str[i]))
		{
			free_str_arr(str);
			free(arr);
			return (0);
		}
		n = ft_atol(str[i]);
		if (ft_check_atoi(n))
		{
			free_str_arr(str);
			free(arr);
			return (0);
		}
		arr[i++] = n;
	}
	free_str_arr(str);
	return (arr);
}
