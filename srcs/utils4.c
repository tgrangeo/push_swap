/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:11:12 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/07 11:50:33 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(t_struct *s)
{	
	int	i;

	i = 0;
	if (s->list_a != NULL)
		free(s->list_a);
	if (s->list_b != NULL)
		free(s->list_b);
	if (s->ac1 > 1)
		while (i < s->ac1 && s->av1[i] != NULL)
		{
			free(s->av1[i]);
			i++;
		}
	if (s->size_a > 100)
		ft_free2(s);
}

void	ft_free2(t_struct *s)
{
	int	i;

	i = 0;
	if (s->av1 != NULL)
		free(s->av1);
	if (s->sorted != NULL)
		free(s->sorted);
	if (s->moinchunk != NULL)
		free(s->moinchunk);
	if (s->chunk_len != NULL)
		free(s->chunk_len);
	if (s->big_list != NULL)
		free(s->big_list);
	while (i < s->n_chunk && s->chunk[i] != NULL )
	{
		free(s->chunk[i]);
		i++;
	}
	if (s->chunk != NULL)
		free(s->chunk);
}

int	find_sorted(t_struct *s, int i)
{
	int	c;
	int	j;

	j = 0;
	c = s->big_list[i];
	while (j < s->size_a && c != s->sorted[j])
		j++;
	return (j);
}
