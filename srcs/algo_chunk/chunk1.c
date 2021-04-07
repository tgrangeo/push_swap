/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:53:07 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 11:36:24 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	create_sort_tab(t_struct *s)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	s->sorted = malloc(sizeof(int) * s->size_a);
	if (s->sorted == NULL)
		message_free("Error malloc\n", 1, s);
	while (++i < s->size_a)
		s->sorted[i] = s->list_a[i];
	i = 0;
	create_sort2(s, i, j);
}

int	in_biglist(t_struct *s, int j)
{
	int	i;

	i = 0;
	while (i < s->big_size)
	{
		if (s->sorted[j] == s->big_list[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_biglist(t_struct *s, int j)
{
	int	i;

	i = 0;
	while (i < s->big_size)
	{
		if (j == s->big_list[i])
			return (1);
		i++;
	}
	return (0);
}

int	just_biglist(t_struct *s)
{
	int	i;

	i = 0;
	while (i < s->size_a)
	{
		if (is_biglist(s, s->list_a[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	fill(t_struct *s)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	j = 0;
	while (x < s->n_chunk)
	{
		while (i < s->chunk_len[x] && j < s->size_a)
		{
			if (!in_biglist(s, j))
			{
				s->chunk[x][i] = s->sorted[j];
				i++;
			}
			j++;
		}
		i = 0;
		x++;
	}
}
