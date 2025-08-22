/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:35:41 by whwang            #+#    #+#             */
/*   Updated: 2025/08/22 17:23:08 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_return_execve(t_fd_info *t, int idx)
{
	char	*cmd_path;
	char	**token;
	int		is_dir_command;
	int		code;

	code = 1;
	is_dir_command = 0;
	token = pipex_split(t->argv[t->cmd_start + idx], ' ');
	if (!token || !token[0])
		ft_safety_exit(t, token, NULL, 127);
	cmd_path = find_cmd_path(token[0], t->env, &is_dir_command);
	if (!cmd_path)
		ft_safety_exit(t, token, NULL, 127);
	execve(cmd_path, token, t->env);
	if (access(cmd_path, F_OK) == -1)
		code = 127;
	else if (access(cmd_path, X_OK) == -1)
		code = 126;
	else if (is_dir_command)
		code = 126;
	else
		code = 1;
	ft_safety_exit(t, token, cmd_path, code);
}

static void	ft_dup2_last_index(t_fd_info *t, char *av)
{
	if (strncmp(t->argv[1], "here_doc\0", 9) == 0)
		t->outfile = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		t->outfile = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (t->outfile < 0)
	{
		perror("outfile");
		close(t->prev);
		close(t->infile);
		ft_free_all(t);
		exit(126);
	}
	dup2(t->outfile, STDOUT_FILENO);
}

void	ft_child_process(t_fd_info *t, int idx)
{
	dup2(t->prev, STDIN_FILENO);
	if (idx == t->last)
		ft_dup2_last_index(t, t->argv[t->argc - 1]);
	else
		dup2(t->w, STDOUT_FILENO);
	if (idx != 0)
		close(t->prev);
	if (idx != t->last)
	{
		close(t->r);
		close(t->w);
	}
	close(t->infile);
	if (t->outfile > 0)
		close(t->outfile);
	ft_return_execve(t, idx);
}

void	ft_parent_process(t_fd_info *t, int idx)
{
	close(t->prev);
	if (idx != t->last)
	{
		t->prev = t->r;
		if (t->w >= 0)
			close(t->w);
		t->r = -1;
	}
}
