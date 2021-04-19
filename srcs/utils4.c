/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:11:12 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/19 12:14:06 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(t_struct *s)
{	
	int	i;

	i = 0;
	if (s->list_a != NULL)
		free(s->list_a);
	if (s->list_b != NULL)
		free(s->list_b);
	while (i < s->ac1 && s->av1[i] != NULL)
	{
		free(s->av1[i]);
		i++;
	}
	if (s->av1 != NULL)
		free(s->av1);
	if (s->size_a > 100)
		ft_free2(s);
}

void	ft_free2(t_struct *s)
{
	int	i;

	i = 0;
	if (s->av1 != NULL)
		free(s->av1);
	if (s->sorted != NULL)
		free(s->sorted);
	if (s->moinchunk != NULL)
		free(s->moinchunk);
	if (s->chunk_len != NULL)
		free(s->chunk_len);
	if (s->big_list != NULL)
		free(s->big_list);
	while (i < s->n_chunk && s->chunk[i] != NULL )
	{
		free(s->chunk[i]);
		i++;
	}
	if (s->chunk != NULL)
		free(s->chunk);
}

int	find_sorted(t_struct *s, int i)
{
	int	c;
	int	j;

	j = 0;
	c = s->big_list[i];
	while (j < s->size_a && c != s->sorted[j])
		j++;
	return (j);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '-' || (str[i] <= '9' && str[i] >= '0'))
		i++;
	if (i != ft_strlen(str))
		return (1);
	else
		return (0);
}

char	*ifzero(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '0' && (str[1] == ' ' || str[1] == '\0'))
		return (str);
	while (str[i] == '0')
	{
		str++;
		i++;
		if (i == ft_strlen(str))
			return (str + i - 1);
	}
	return (str + i);
}
