/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:43:06 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/03/29 12:43:06 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_index(t_struct *s)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < s->size_a)
	{
		if (s->list_a[i] < s->list_a[min])
			min = i;
		i++;
	}
	return (min);
}

void	print_str_colored(t_struct *s, char *color)
{
	write(1, color, ft_strlen(color));
	print(s);
	write(1, _EOFORMAT_, ft_strlen(_EOFORMAT_));
}

int	message(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	exit(ret);
}

void	ft_free_checker(t_struct *s)
{
	int	i;

	i = 0;
	if (s->list_a != NULL)
		free(s->list_a);
	if (s->list_b != NULL)
		free(s->list_b);
}

int	message_free(char *str, int ret, t_struct *s)
{
	write(1, str, ft_strlen(str));
	if (s->push)
		ft_free(s);
	else
		ft_free_checker(s);
	exit(ret);
}
