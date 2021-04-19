/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:43:25 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/06 13:11:57 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rrr(t_struct *p)
{
	int	bool;

	bool = 0;
	if (p->push)
	{
		bool = 1;
		p->push = 0;
	}
	if (p->push == 1)
		write(STDOUT_FILENO, "rrr\n", 4);
	ft_rra(p);
	ft_rrb(p);
	if (bool)
		p->push = 1;
	return (0);
}
