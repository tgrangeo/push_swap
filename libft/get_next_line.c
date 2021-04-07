/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:42:48 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 12:42:49 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFFER_SIZE 5

int	ft_error(char **mem)
{
	free(*mem);
	*mem = NULL;
	return (-1);
}

int	ft_error_line(char **mem, char **line)
{
	free(*mem);
	free(*line);
	*mem = NULL;
	*line = NULL;
	return (-1);
}

static int	ft_scan(char **mem, char **line)
{
	int	n;
	int	size;

	n = ft_strchr_int(*mem, '\n');
	size = ft_strlen(*mem) - n - 1;
	if (n == 0)
		return (gnl_malloc(mem, line, size));
	else if (n > 0)
		return (gnl_malloc2(mem, line, size, n));
	return (ft_error(mem));
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	static char	*mem;

	if (!mem)
		mem = ft_strndup("", 0);
	else if ((ft_strchr_int(mem, '\n') >= 0))
		return (ft_scan(&mem, line));
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		mem = ft_strjoin_free_s1(mem, buf);
		if ((ft_strchr_int(mem, '\n') >= 0))
			return (ft_scan(&mem, line));
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (end_gnl(line, mem, ret));
}
