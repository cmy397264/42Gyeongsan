/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:40:24 by whwang            #+#    #+#             */
/*   Updated: 2025/08/15 18:55:38 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*build_path(char *dir, char *cmd)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (0);
	path = ft_strjoin(temp, cmd);
	free(temp);
	return (path);
}

static char	*nomalizer_token(char *token)
{
	if (token && token[0] != '\0')
		return (token);
	return (".");
}

char	*get_path(char **token, char *cmd)
{
	int		i;
	char	*full_path;
	char	*ret;
	char	*n;

	i = 0;
	ret = NULL;
	while (token[i])
	{
		n = nomalizer_token(cmd);
		full_path = build_path(token[i], n);
		if (access(full_path, X_OK) == 0)
		{
			ret = full_path;
			break ;
		}
		else
			free(full_path);
		i++;
	}
	return (ret);
}

char	*find_path_env(char *env[])
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (0);
}
