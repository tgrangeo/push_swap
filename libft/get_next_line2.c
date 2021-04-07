/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:42:59 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 12:43:00 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_malloc(char **mem, char **line, int size)
{
	*line = ft_strndup("", 0);
	if (*line == NULL)
		return (ft_error(mem));
	*mem = ft_substr_free(*mem, 1, size);
	if (*mem == NULL)
		return (ft_error_line(mem, line));
	return (1);
}

int	gnl_malloc2(char **mem, char **line, int size, int n)
{
	*line = ft_strndup(*mem, n);
	if (*line == NULL)
		return (ft_error(mem));
	*mem = ft_substr_free(*mem, n + 1, size);
	if (*mem == NULL)
		return (ft_error_line(mem, line));
	return (1);
}

int	end_gnl(char **line, char *mem, int ret)
{
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		*line = ft_strndup(mem, ft_strlen(mem));
		if (*line == NULL)
			return (ft_error(&mem));
	}
	free(mem);
	mem = NULL;
	return (0);
}
