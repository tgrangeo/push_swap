/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:52:54 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/06 13:44:41 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# define _GREEN_ "\e[32m"
# define _WHITE_ "\e[37m"
# define _BRIGHT_BLACK_ "\e[90m"
# define _EOFORMAT_ "\e[0m"

typedef struct s_node
{
	int				val;
	int				len;
	struct s_node	*next;
}				t_node;

typedef struct s_struct
{
	int		**chunk;
	int		*chunk_len;
	int		*moinchunk;
	int		n_chunk;
	int		*sorted;
	int		*list_a;
	int		*list_b;
	int		size_a;
	int		size_b;
	int		a;
	int		max;
	int		min_pos;
	char	**av1;
	int		ac1;
	int		f;
	int		push;
	int		big_size;
	int		*big_list;
	int		aa;
}				t_struct;

int		ft_sa(t_struct *p);
int		ft_sb(t_struct *p);
int		ft_ss(t_struct *p);
int		ft_pa(t_struct *p);
int		ft_pb(t_struct *p);
int		ft_ra(t_struct *p);
int		ft_rb(t_struct *p);
int		ft_rr(t_struct *p);
int		ft_rra(t_struct *p);
int		ft_rrb(t_struct *p);
int		ft_rrr(t_struct *p);
int		check_doublon(int size, int *list);
void	print(t_struct *s);
int		message(char *str, int ret);
int		message_free(char *str, int ret, t_struct *s);
void	ft_free(t_struct *s);
int		is_sorted(t_struct *s);
int		ft_issame(char *a, char *b);
int		check_isnum(char **t, int ac, int a);
void	ft_while(t_struct *s);
int		just_biglist(t_struct *s);
void	print_str_colored(t_struct *s, char *color);
int		min_index(t_struct *s);
void	ft_init(int ac, char **av, t_struct *s);
void	sort_arg(int ac, char **av, t_struct *s);
void	arg2(t_struct *s, char **av);
int		chunk_is_present(t_struct *s, int x);
int		scan_up(t_struct *s, int x);
void	create_chunk(t_struct *s);
int		find_place_two(t_struct *s, int search);
void	fill(t_struct *s);
void	create_sort_tab(t_struct *s);
int		scan_down(t_struct *s, int x);
void	go_up_a(int index, t_struct *s);
void	go_up_b(int index, t_struct *s);
int		find_min(t_struct *s);
int		find_min_a(t_struct *s);
int		find_max_a(t_struct *s);
int		find_max(t_struct *s);
int		find_place(t_struct *s);
void	good_place(t_struct *s);
void	ft_algo_chunk(t_struct *s);
void	big_list(t_struct *s);
void	ft_free2(t_struct *s);
int		find_sorted(t_struct *s, int i);
int		ft_while_chunk(int x, t_struct *s);
void	create_sort2(t_struct *s, int i, int j);
int		check_line(char *str);
char	*ifzero(char *str);

#endif
