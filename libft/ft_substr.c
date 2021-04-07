/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:52:08 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 12:41:51 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (!(s))
		return (NULL);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	if ((int)start > ft_strlen(s))
	{
		dest[i] = '\0';
		return (dest);
	}
	while (i < len && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr_free(char *s, int start, int len)
{
	int		i;
	char	*dest;

	if (!(s))
		return (NULL);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
	{
		dest[i] = '\0';
		return (dest);
	}
	while (i < len && s[start])
		dest[i++] = s[start++];
	dest[i] = '\0';
	free(s);
	return (dest);
}
