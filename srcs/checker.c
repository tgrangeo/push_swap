/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:46:27 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 09:55:52 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	instruction(t_struct *s, char *buf)
{
	if (ft_issame(buf, "sa"))
		return (ft_sa(s));
	else if (ft_issame(buf, "sb"))
		return (ft_sb(s));
	else if (ft_issame(buf, "ss"))
		return (ft_ss(s));
	else if (ft_issame(buf, "pa"))
		return (ft_pa(s));
	else if (ft_issame(buf, "pb"))
		return (ft_pb(s));
	else if (ft_issame(buf, "ra"))
		return (ft_ra(s));
	else if (ft_issame(buf, "rb"))
		return (ft_rb(s));
	else if (ft_issame(buf, "rr"))
		return (ft_rr(s));
	else if (ft_issame(buf, "rra"))
		return (ft_rra(s));
	else if (ft_issame(buf, "rrb"))
		return (ft_rrb(s));
	else if (ft_issame(buf, "rrr"))
		return (ft_rrr(s));
	else
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	s;
	char		*buf;
	int			ret;

	s.push = 0;
	if (ac == 1)
		return (0);
	sort_arg(ac, av, &s);
	while (get_next_line(0, &buf) > 0)
	{
		if (instruction(&s, buf))
			message("Error\n", 1);
		free(buf);
	}
	ret = is_sorted(&s);
	if (ret && s.size_a == s.max)
		message_free("OK\n", 0, &s);
	else
		message_free("KO\n", 1, &s);
}
