/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:43:15 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/07 11:56:30 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_sa(t_struct *p)
{
	int	temp;

	temp = 0;
	if (p->size_a < 2)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "sa\n", 3);
	temp = p->list_a[p->size_a - 1];
	p->list_a[p->size_a - 1] = p->list_a[p->size_a - 2];
	p->list_a[p->size_a - 2] = temp;
	if (p->v && p->push)
		print(p);
	return (0);
}

int	ft_sb(t_struct *p)
{
	int	temp;

	temp = 0;
	if (p->size_b < 2)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "sb\n", 3);
	temp = p->list_b[p->size_b - 1];
	p->list_b[p->size_b - 1] = p->list_b[p->size_b - 2];
	p->list_b[p->size_b - 2] = temp;
	if (p->v && p->push)
		print(p);
	return (0);
}

int	ft_ss(t_struct *p)
{
	if (ft_sa(p))
		return (0);
	if (ft_sb(p))
		return (0);
	return (0);
}

int	ft_pa(t_struct *p)
{
	if (p->size_b == 0)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "pa\n", 3);
	p->list_a[p->size_a] = p->list_b[p->size_b - 1];
	p->size_a++;
	p->size_b--;
	if (p->v && p->push)
		print(p);
	return (0);
}

int	ft_pb(t_struct *p)
{
	if (p->size_a == 0)
		return (0);
	if (p->push == 1)
		write(STDOUT_FILENO, "pb\n", 3);
	p->list_b[p->size_b] = p->list_a[p->size_a - 1];
	p->size_a--;
	p->size_b++;
	if (p->v && p->push)
		print(p);
	return (0);
}
