/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:41:04 by whwang            #+#    #+#             */
/*   Updated: 2025/08/21 19:44:20 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_fd_info
{
	int		argc;
	char	**argv;
	char	**env;
	int		infile;
	int		outfile;
	int		ncmd;
	int		last;
	int		cmd_start;
	pid_t	*pids;
	int		prev;
	int		r;
	int		w;
	int		env_owned;
}	t_fd_info;

void		ft_free(t_fd_info *t);
void		ft_free_all(t_fd_info *t);
char		*find_cmd_path(char *cmd, char *env[], int *is_dir);
t_fd_info	*set_info(int argc, char *argv[], char *env[]);
void		ft_child_process(t_fd_info *t, int idx);
void		ft_parent_process(t_fd_info *t, int idx);
void		free_token(char **token);
char		*find_path_env(char *env[]);
char		*get_path(char **token, char *cmd);
int			set_next_pipe(t_fd_info *t, int idx);
int			return_from_pids(t_fd_info *t, int idx);
char		**pipex_split(char *s, char delim);
void		ft_free_all(t_fd_info *t);
void		ft_free_env(t_fd_info *t);
void		ft_safety_exit(t_fd_info *t, char **token, char *path, int code);
#endif
