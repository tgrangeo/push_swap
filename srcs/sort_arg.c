/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:42:24 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/07 11:56:48 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	arg1(t_struct *s, int ac, char **av)
{
	int	i;

	s->a = 1;
	s->list_a = malloc(sizeof(int) * ac - 1);
	if (s->list_a == NULL)
		message_free("Error malloc\n", 1, s);
	s->list_b = malloc(sizeof(int) * ac - 1);
	if (s->list_b == NULL)
		message_free("Error malloc\n", 1, s);
	s->size_a = ac - 1;
	s->max = s->size_a;
	s->size_b = 0;
	i = ac - 2;
	s->a = 1;
	if (check_isnum(av, ac, 1))
		message_free("Error\n", 1, s);
	while (s->a < ac)
		s->list_a[i--] = ft_atoi(av[s->a++]);
	if (check_doublon(s->size_a, s->list_a))
		message_free("Error\n", 1, s);
}

static void	ft_count(char *str, t_struct *s)
{
	int		i;

	i = 0;
	s->ac1 = 0;
	while (str[i] == ' ' || str[i] == '-' || (str[i] <= '9' && str[i] >= '0'))
		i++;
	if (i != ft_strlen(str))
		message_free("Error\n", 1, s);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			s->ac1++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	if (s->ac1 == 1)
		message_free("", 0, s);
}

static void	put_arg(char *str, char **av1, t_struct *s)
{
	int	i;
	int	c;
	int	x;

	i = 0;
	c = 0;
	x = 1;
	av1[0] = ft_strdup("./checker");
	while (i < ft_strlen(str))
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == '-')
		{
			while (((str[i] <= '9' && str[i] >= '0')
					|| str[i] == '-') && str[i++])
				c++;
			av1[x] = ft_substr(str, i - c, c);
			if (av1[x] == NULL)
				message_free("Error\n", 1, s);
			c = 0;
			x++;
		}
		i++;
	}
}

void	arg2(t_struct *s, char **av)
{
	ft_count(av[1], s);
	s->ac1 += 1;
	if (s->ac1 == 1 && check_isnum(av, 1, 0))
		message_free("", 1, s);
	else if (s->ac1 == 1)
		message_free("Error\n", 1, s);
	s->f = 1;
	s->a = 1;
	s->av1 = malloc(sizeof(char *) * s->ac1);
	if (s->av1 == NULL)
		message_free("Error\n", 1, s);
	put_arg(av[1], s->av1, s);
}

void	sort_arg(int ac, char **av, t_struct *s)
{
	if (ac > 2)
		arg1(s, ac, av);
	else if (ac == 2)
	{
		s->f = 1;
		arg2(s, av);
		arg1(s, s->ac1, s->av1);
	}
	else
		message_free("Error\n", 1, s);
}
