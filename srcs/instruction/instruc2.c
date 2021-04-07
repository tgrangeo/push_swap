/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:43:20 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/07 11:56:29 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_ra(t_struct *p)
{
	int	x;
	int	temp;

	x = p->size_a - 1;
	if (p->size_a == 0)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "ra\n", 3);
	temp = p->list_a[p->size_a - 1];
	while (x > 0)
	{
		p->list_a[x] = p->list_a[x - 1];
		x--;
	}
	p->list_a[0] = temp;
	if (p->v && p->push)
		print(p);
	return (0);
}

int	ft_rb(t_struct *p)
{
	int	x;
	int	temp;

	x = p->size_b - 1;
	if (p->size_b == 0)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "rb\n", 3);
	temp = p->list_b[p->size_b - 1];
	while (x > 0)
	{
		p->list_b[x] = p->list_b[x - 1];
		x--;
	}
	p->list_b[0] = temp;
	if (p->v && p->push)
		print(p);
	return (0);
}

int	ft_rr(t_struct *p)
{
	int	ret;

	ret = ft_ra(p);
	ret += ft_rb(p);
	if (ret == 0)
		return (0);
	else
		return (0);
}

int	ft_rra(t_struct *p)
{
	int	x;
	int	temp;

	x = 0;
	if (p->size_a == 0)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "rra\n", 4);
	temp = p->list_a[0];
	while (x < p->size_a - 1)
	{
		p->list_a[x] = p->list_a[x + 1];
		x++;
	}
	p->list_a[p->size_a - 1] = temp;
	if (p->v && p->push)
		print(p);
	return (0);
}

int	ft_rrb(t_struct *p)
{
	int	x;
	int	temp;

	x = 0;
	if (p->size_b == 0)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "rrb\n", 4);
	temp = p->list_b[0];
	while (x < p->size_b - 1)
	{
		p->list_b[x] = p->list_b[x + 1];
		x++;
	}
	p->list_b[p->size_b - 1] = temp;
	if (p->v && p->push)
		print(p);
	return (0);
}
