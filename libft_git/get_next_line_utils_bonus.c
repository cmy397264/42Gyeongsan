/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:53:38 by whwang            #+#    #+#             */
/*   Updated: 2025/08/21 11:54:01 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_check_buffer_size(char *buf, int *idx, int fd)
{
	int	f;

	if (*idx == 0 || buf[*idx] == '\0' || *idx >= BUFFER_SIZE)
	{
		*idx = 0;
		f = read(fd, buf, BUFFER_SIZE);
		if (f == 0)
			return (0);
		if (f < 0)
			return (-1);
		buf[f] = '\0';
	}
	return (1);
}

int	is_enter_or_eof(char *buf, int *idx)
{
	while (*idx < BUFFER_SIZE && buf[*idx])
	{
		if (buf[(*idx)++] == '\n')
			return (1);
	}
	return (0);
}

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	char	*temp;
	int		s1_len;
	int		s2_len;
	int		i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	temp = s1;
	s = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s)
		return (0);
	while (*s1)
		s[i++] = *s1++;
	free(temp);
	temp = s2;
	while (*s2)
		s[i++] = *s2++;
	free(temp);
	s[i] = '\0';
	return (s);
}

char	*get_ret(char *buf, char *ret, int start, int end)
{
	char	*s;
	int		i;

	i = 0;
	if (!buf[start])
		return (ret);
	s = malloc(sizeof(char) * (end - start + 1));
	if (!s)
		return (0);
	while (start < end)
		s[i++] = buf[start++];
	s[i] = '\0';
	if (ret)
		ret = ft_strjoin(ret, s);
	else
		ret = s;
	return (ret);
}
