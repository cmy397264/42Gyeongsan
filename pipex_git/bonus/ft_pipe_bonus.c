/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:37:47 by whwang            #+#    #+#             */
/*   Updated: 2025/08/22 10:54:19 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	set_next_pipe(t_fd_info *t, int idx)
{
	int	p[2];

	if (idx == t->last)
	{
		t->r = -1;
		t->w = -1;
		return (0);
	}
	if (pipe(p) == -1)
	{
		perror("pipe");
		return (1);
	}
	t->r = p[0];
	t->w = p[1];
	return (0);
}

int	return_from_pids(t_fd_info *t, int idx)
{
	int		i;
	int		exit_code;
	int		status;
	pid_t	last;

	status = 0;
	exit_code = 0;
	last = t->pids[idx - 1];
	if (waitpid(last, &status, 0) == -1)
		exit_code = 1;
	else if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		exit_code = 128 + WTERMSIG(status);
	i = 0;
	while (i < idx - 1)
		waitpid(t->pids[i++], &status, 0);
	ft_free_all(t);
	return (exit_code);
}
