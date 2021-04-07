/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:43:25 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/07 11:56:27 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rrr(t_struct *p)
{
	int	ret;
	int	bool;

	bool = 0;
	if (p->push)
	{
		bool = 1;
		p->push = 0;
	}
	if (p->push == 1)
		write(STDOUT_FILENO, "rrr\n", 4);
	ret = ft_rra(p);
	ret += ft_rrb(p);
	if (bool)
		p->push = 1;
	if (ret == 0)
		return (0);
	else
		return (0);
}
