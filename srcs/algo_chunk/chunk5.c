/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:43:10 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 12:43:11 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_max_a(t_struct *s)
{
	int	min;
	int	i;
	int	ret;

	min = s->list_a[0];
	i = 1;
	ret = 0;
	while (i < s->size_a)
	{
		if (s->list_a[i] > min)
		{
			min = s->list_a[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

\
void	ft_algo_finish(t_struct *s)
{
	int	i;

	i = 0;
	go_up_a(find_min_a(s), s);
	go_up_b(find_max(s), s);
	while (1)
	{
		i = s->size_b - 1;
		while (i >= 0 && s->list_b[i] > s->list_a[0])
		{
			ft_pa(s);
			i--;
		}
		go_up_a(0, s);
		if (find_max_a(s) == 0)
			break ;
	}
	while (s->size_a != s->max)
		ft_pa(s);
	message_free("", 0, s);
}

void	ft_algo_chunk(t_struct *s)
{
	int	x;

	x = 0;
	while (1)
	{
		if (x < s->n_chunk && !just_biglist(s))
		{
			ft_while_chunk(x, s);
			x++;
		}
		else
			ft_algo_finish(s);
	}
}
