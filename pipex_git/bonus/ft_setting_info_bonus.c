/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting_info_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:29:40 by whwang            #+#    #+#             */
/*   Updated: 2025/08/22 17:31:33 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	set_info_basic(t_fd_info *t, int argc, char *argv[], char *env[])
{
	char	**min_env;

	t->argc = argc;
	t->argv = argv;
	t->env = env;
	if (env == NULL || env[0] == NULL)
	{
		min_env = malloc(sizeof(char *) * 2);
		if (!min_env)
			return (1);
		min_env[0] = ft_strdup("PATH=/usr/bin:/bin");
		if (!min_env[0])
		{
			free(min_env);
			return (1);
		}
		min_env[1] = NULL;
		t->env = min_env;
		t->env_owned = 1;
	}
	else
		t->env_owned = 0;
	t->r = -1;
	t->w = -1;
	return (0);
}

static void	ft_setup_heredoc_child(t_fd_info *t, int *p)
{
	char	*limiter;
	char	*line;
	size_t	l_size;

	close(p[0]);
	limiter = t->argv[2];
	l_size = ft_strlen(limiter);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(line, limiter, l_size) && line[l_size] == '\n')
		{
			free(line);
			break ;
		}
		write(p[1], line, ft_strlen(line));
		free(line);
	}
	close(p[1]);
	ft_free_env(t);
	exit(0);
}

static int	ft_setup_heredoc(t_fd_info *t)
{
	int		p[2];
	pid_t	pid;

	if (t->argc < 6)
		return (1);
	if (pipe(p) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid = fork();
	if (pid == 0)
		ft_setup_heredoc_child(t, p);
	close(p[1]);
	t->infile = p[0];
	waitpid(pid, NULL, 0);
	return (0);
}

static int	setup_info_heredoc_check(t_fd_info *t, int argc, char *av)
{
	if (ft_strncmp(av, "here_doc\0", 9) == 0)
	{
		if (ft_setup_heredoc(t))
			return (1);
		t->cmd_start = 3;
		t->ncmd = argc - 4;
	}
	else
	{
		t->infile = open(av, O_RDONLY);
		if (t->infile < 0)
		{
			t->infile = open("/dev/null", O_RDONLY);
			if (t->infile < 0)
			{
				perror("open /dev/null");
				return (1);
			}
			perror("infile");
		}
		t->cmd_start = 2;
		t->ncmd = argc - 3;
	}
	return (0);
}

t_fd_info	*set_info(int argc, char *argv[], char *env[])
{
	t_fd_info	*t;

	t = malloc(sizeof(t_fd_info));
	if (!t)
		return (NULL);
	if (set_info_basic(t, argc, argv, env))
	{
		free(t);
		return (0);
	}
	if (setup_info_heredoc_check(t, argc, argv[1]))
	{
		ft_free_env(t);
		return (NULL);
	}
	t->last = t->ncmd - 1;
	t->prev = t->infile;
	t->outfile = -1;
	t->pids = malloc(sizeof(pid_t) * t->ncmd);
	if (!t->pids)
	{
		ft_free_all(t);
		return (NULL);
	}
	return (t);
}
