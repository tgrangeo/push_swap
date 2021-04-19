/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:42:34 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/06 13:45:03 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_while_2(t_struct *s)
{
	if (s->min_pos >= s->size_a / 2)
	{
		ft_ra(s);
	}
	else if (s->min_pos < s->size_a / 2)
	{
		ft_rra(s);
	}
}

void	ft_while(t_struct *s)
{
	s->min_pos = min_index(s);
	if (s->list_a[s->size_a - 1] > s->list_a[s->size_a - 2])
		ft_sa(s);
	else if (is_sorted(s) || s->size_a == 0)
		ft_pa(s);
	else if (s->min_pos == s->size_a - 1)
		ft_pb(s);
	else
		ft_while_2(s);
}

void	ft_init(int ac, char **av, t_struct *s)
{
	if (ac < 2)
		message_free("Error\n", 1, s);
	else if (ac == 2)
	{
		arg2(s, av);
		s->list_a = malloc(sizeof(int) * s->ac1 - s->a);
		if (s->list_a == NULL)
			message_free("error\n", 1, s);
		s->list_b = malloc(sizeof(int) * s->ac1 - s->a);
		if (s->list_b == NULL)
			message_free("error\n", 1, s);
	}
	else
	{
		s->list_a = malloc(sizeof(int) * (ac - s->a));
		if (s->list_a == NULL)
			message_free("error\n", 1, s);
		s->list_b = malloc(sizeof(int) * (ac - s->a));
		if (s->list_b == NULL)
			message_free("error\n", 1, s);
	}
}

int	check_doublon(int size, int *list)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < size)
	{
		while (x < size)
		{
			if (list[i] == list[x] && x != i)
				return (1);
			x++;
		}
		i++;
		x = 0;
	}
	return (0);
}
