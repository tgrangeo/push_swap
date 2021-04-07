/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:53:12 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 10:20:00 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	scan_down(t_struct *s, int x)
{
	int	i;
	int	j;

	i = s->size_a - 1;
	j = 0;
	while (i >= 0)
	{
		while (j < s->chunk_len[x])
		{
			if (s->list_a[i] == s->chunk[x][j])
				return (i);
			j++;
		}
		j = 0;
		i--;
	}
	return (0);
}

void	go_up_a(int index, t_struct *s)
{
	int	j;
	int	rra;

	j = s->list_a[index];
	while (s->list_a[s->size_a - 1] != j)
	{
		rra = find_place_two(s, index);
		if (index - 1 > s->size_a / 2)
			ft_ra(s);
		else
			ft_rra(s);
	}
}

void	go_up_b(int index, t_struct *s)
{
	int	j;
	int	i;

	i = 0;
	j = s->list_b[index];
	while (s->list_b[s->size_b - 1] != j)
	{
		if (index - 1 > s->size_b / 2)
			ft_rb(s);
		else
			ft_rrb(s);
		i++;
	}
}

int	find_min(t_struct *s)
{
	int	min;
	int	i;
	int	ret;

	min = s->list_b[0];
	i = 1;
	ret = 0;
	while (i < s->size_b)
	{
		if (s->list_b[i] < min)
		{
			min = s->list_b[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	find_min_a(t_struct *s)
{
	int	min;
	int	i;
	int	ret;

	min = s->list_a[0];
	i = 1;
	ret = 0;
	while (i < s->size_a)
	{
		if (s->list_a[i] < min)
		{
			min = s->list_a[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}
