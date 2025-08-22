/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:16:22 by whwang            #+#    #+#             */
/*   Updated: 2025/05/13 15:41:25 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define FD_MAX 1024
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_fp
{
	char	buf[BUFFER_SIZE + 1];
	int		idx;
}	t_fp;

char		*get_ret(char *buf, char *ret, int start, int end);
char		*get_next_line(int fd);
int			ft_check_buffer_size(char *buf, int *idx, int fd);
int			is_enter_or_eof(char *buf, int *idx);
#endif
