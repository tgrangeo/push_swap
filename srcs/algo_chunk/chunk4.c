/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:17:31 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 11:49:46 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_n_chunk(t_struct *s)
{
	if (s->size_a >= 500)
		s->n_chunk = 11;
	else if (s->size_a >= 430)
		s->n_chunk = 10;
	else if (s->size_a >= 366)
		s->n_chunk = 9;
	else if (s->size_a >= 300)
		s->n_chunk = 8;
	else if (s->size_a >= 230)
		s->n_chunk = 7;
	else if (s->size_a >= 166)
		s->n_chunk = 6;
	else
		s->n_chunk = 5;
}

void	create_chunk(t_struct *s)
{
	int	i;

	i = -1;
	init_n_chunk(s);
	s->chunk = malloc(sizeof(int *) * s->n_chunk);
	if (s->chunk == NULL)
		message_free("Error malloc\n", 1, s);
	s->chunk_len = malloc(sizeof(int) * s->n_chunk);
	if (s->chunk_len == NULL)
		message_free("Error malloc\n", 1, s);
	while (++i < s->n_chunk - 1)
	{
		s->chunk[i] = malloc(sizeof(int) * s->size_a
				/ s->n_chunk - s->moinchunk[i]);
		if (s->chunk[i] == NULL)
			message_free("Error malloc\n", 1, s);
		s->chunk_len[i] = s->size_a / s->n_chunk - s->moinchunk[i];
	}
	s->chunk[i] = malloc(sizeof(int) * (s->size_a
				/ s->n_chunk + (s->size_a % s->n_chunk) - s->moinchunk[i]));
	if (s->chunk[i] == NULL)
		message_free("Error malloc\n", 1, s);
	s->chunk_len[i] = s->size_a / s->n_chunk + (s->size_a % s->n_chunk)
		- s->moinchunk[i];
	fill(s);
}

int	scan_up(t_struct *s, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->size_a)
	{
		while (j < s->chunk_len[x])
		{
			if (s->list_a[i] == s->chunk[x][j])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	chunk_is_present(t_struct *s, int x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->chunk_len[x])
	{
		while (j < s->size_a)
		{
			if (s->chunk[x][i] == s->list_a[j])
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	find_max(t_struct *s)
{
	int	min;
	int	i;
	int	ret;

	min = s->list_b[0];
	i = 1;
	ret = 0;
	while (i < s->size_b)
	{
		if (s->list_b[i] > min)
		{
			min = s->list_b[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
