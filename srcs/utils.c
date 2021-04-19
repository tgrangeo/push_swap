/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:42:41 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/06 13:05:35 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_issame(char *a, char *b)
{
	int	alen;
	int	i;

	i = 0;
	alen = ft_strlen(a);
	if (ft_strlen(a) != ft_strlen(b))
		return (0);
	while (a[i] == b[i] && a[i])
		i++;
	if (i != alen)
		return (0);
	return (1);
}

void	print_two(char c, int j, int list_a)
{
	write(1, &c, 1);
	write(1, "[", 1);
	ft_putnbr_fd(j, 1);
	write(1, "] ", 1);
	ft_putnbr_fd(list_a, 1);
	return ;
}

void	print(t_struct *s)
{
	int	j;

	if (s->size_a > s->size_b)
		j = s->size_a - 1;
	else
		j = s->size_b - 1;
	while (j >= 0)
	{
		if (j < s->size_a)
			print_two('A', j, s->list_a[j]);
		write(1, "\t\t", 2);
		if (j < s->size_b)
			print_two('B', j, s->list_b[j]);
		write(1, "\n", 1);
		j--;
	}
}

int	is_sorted(t_struct *s)
{
	int	i;

	i = -1;
	while (++i < s->size_a - 1)
	{
		if (s->list_a[i] < s->list_a[i + 1])
			return (0);
	}
	return (1);
}

int	check_isnum(char **t, int ac, int a)
{
	int	y;
	int	x;

	y = a;
	x = 0;
	while (y < ac)
	{
		if (ft_atoi(t[y]) > INT_MAX || ft_atoi(t[y]) < INT_MIN)
			return (1);
		while (x < ft_strlen(t[y]))
		{
			if ((t[y][x] <= '9' && t[y][x] >= '0')
				|| (t[y][x] == '-' && ft_isdigit(t[y][x + 1])))
				x++;
			else
				return (1);
		}
		x = 0;
		y++;
	}
	return (0);
}
