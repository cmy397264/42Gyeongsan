/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:29:40 by whwang            #+#    #+#             */
/*   Updated: 2025/08/22 17:19:31 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static int	setup_info_infile(t_fd_info *t, int ac, char *av)
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
	t->outfile = -1;
	t->cmd_start = 2;
	t->ncmd = ac - 3;
	t->last = t->ncmd - 1;
	t->prev = t->infile;
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
		return (NULL);
	}
	if (setup_info_infile(t, argc, argv[1]))
	{
		ft_free_env(t);
		return (NULL);
	}
	t->pids = malloc(sizeof(pid_t) * t->ncmd);
	if (!t->pids)
	{
		ft_free_all(t);
		return (NULL);
	}
	return (t);
}
