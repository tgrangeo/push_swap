/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 08:49:09 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 10:21:35 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_place(t_struct *s)
{
	long	min;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	min = -2147483648;
	while (i < s->size_b)
	{
		if (s->list_b[i] < s->list_a[s->size_a - 1] && s->list_b[i] > min)
		{
			min = s->list_b[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	find_place_two(t_struct *s, int search)
{
	long	min;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	min = 2147483648;
	while (i < s->size_b)
	{
		if (s->list_b[i] > search && s->list_b[i] < min)
		{
			min = s->list_b[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	find_place_b(t_struct *s)
{
	long	min;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	min = 2147483648;
	while (i < s->size_b)
	{
		if (s->list_a[i] > s->list_b[s->size_b - 1] && s->list_a[i] < min)
		{
			min = s->list_b[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

void	good_place(t_struct *s)
{
	int	i;
	int	j;
	int	to_up;
	int	x;

	x = 0;
	i = 0;
	j = 0;
	to_up = 0;
	while (x < s->size_b)
	{
		if (s->list_a[s->size_a - 1] < s->list_b[x])
			i++;
		else
			j++;
		x++;
	}
	if (s->size_b == 0)
		ft_pb(s);
	else if (i == x || j == x)
		go_up_b(find_max(s), s);
	else
		go_up_b(find_place(s), s);
	ft_pb(s);
}

int	ft_while_chunk(int x, t_struct *s)
{
	int	ret1;
	int	ret2;

	while (chunk_is_present(s, x))
	{
		ret1 = scan_down(s, x);
		ret2 = scan_up(s, x);
		if ((s->size_a - 1 - ret1) > ret2)
			go_up_a(ret2, s);
		else
			go_up_a(ret1, s);
		good_place(s);
		if (s->size_a == 0)
			return (0);
	}
	return (1);
}
