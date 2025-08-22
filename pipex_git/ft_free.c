/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:29:33 by whwang            #+#    #+#             */
/*   Updated: 2025/08/22 17:29:54 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_token(char **token)
{
	int	i;

	i = 0;
	if (!token)
		return ;
	while (token[i])
		free(token[i++]);
	free(token);
}

void	ft_free_env(t_fd_info *t)
{
	if (t->env_owned)
	{
		free(t->env[0]);
		free(t->env);
	}
	free(t);
}

void	ft_free_all(t_fd_info *t)
{
	if (t->pids)
		free(t->pids);
	ft_free_env(t);
}

void	ft_safety_exit(t_fd_info *t, char **token, char *cmd_path, int code)
{
	if (token)
		free_token(token);
	if (cmd_path)
		free(cmd_path);
	ft_free_all(t);
	perror("Command");
	exit(code);
}
