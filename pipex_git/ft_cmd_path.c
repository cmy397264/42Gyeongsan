/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:44:23 by whwang            #+#    #+#             */
/*   Updated: 2025/08/21 20:31:19 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_path_command(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	if (len > 0 && cmd[0] == '/')
		return (1);
	if (len > 1 && cmd[0] == '.' && cmd[1] == '/')
		return (1);
	if (len > 2 && cmd[0] == '.' && cmd[1] == '.' && cmd[2] == '/')
		return (1);
	return (0);
}

char	*find_cmd_path(char *cmd, char *env[], int *is_dir)
{
	char	*path_env;
	char	*ret;
	char	**token;

	ret = 0;
	path_env = find_path_env(env);
	if (!path_env)
		return (0);
	token = ft_split(path_env, ':');
	*is_dir = is_path_command(cmd);
	if (*is_dir == 1)
		ret = ft_strdup(cmd);
	else
		ret = get_path(token, cmd);
	free_token(token);
	return (ret);
}
