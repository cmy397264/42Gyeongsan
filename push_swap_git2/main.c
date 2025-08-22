/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:38:14 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 17:25:12 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "./libft/libft.h"

int	ft_check_parse(char *argv, int **dict, int *tc)
{
	char	**splitted_array;
	int		*atoi_array;
	int		*temp;
	int		ic;

	ic = 0;
	splitted_array = ft_split(argv, ' ', &ic);
	if (ic == 0)
	{
		free(splitted_array);
		return (1);
	}
	atoi_array = ft_atoi_arr(splitted_array, ic);
	if (atoi_array == NULL)
		return (1);
	temp = *dict;
	*dict = ft_merge(temp, atoi_array, *tc, ic);
	if (*dict == 0)
		return (1);
	*tc += ic;
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;
	int	tc;
	int	*dict;

	i = 0;
	tc = 0;
	dict = NULL;
	if (argc > 1)
	{
		while (++i < argc)
		{
			if (ft_check_parse(argv[i], &dict, &tc))
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		ft_sort_process(dict, tc);
		free(dict);
	}
}
