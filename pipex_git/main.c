/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:27:02 by whwang            #+#    #+#             */
/*   Updated: 2025/08/21 17:29:06 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	int			idx;
	t_fd_info	*t;

	idx = 0;
	if (argc != 5)
		return (1);
	t = set_info(argc, argv, env);
	if (!t)
		return (1);
	while (idx < t->ncmd)
	{
		if (set_next_pipe(t, idx))
			exit(1);
		t->pids[idx] = fork();
		if (t->pids[idx] == 0)
			ft_child_process(t, idx);
		else
			ft_parent_process(t, idx);
		idx++;
	}
	if (t->infile > 0)
		close(t->infile);
	if (t->outfile > 0)
		close(t->outfile);
	return (return_from_pids(t, idx));
}
