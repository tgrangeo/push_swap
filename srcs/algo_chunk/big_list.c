#include "../../includes/push_swap.h"

static void	big_list2(t_struct *s, t_node	*p, t_node	*n)
{
	int	i;

	i = 0;
	p = n;
	while (i < s->size_a - 1)
	{
		if (n[i].len > p->len)
			p = n + i;
		i++;
	}
	s->big_size = p->len;
	s->big_list = malloc(sizeof(int) * p->len);
	if (s->big_list == NULL)
		message_free("Error malloc\n", 1, s);
	s->big_list[0] = p->val;
	i = 1;
	while (i < s->big_size)
	{
		p = p->next;
		s->big_list[i] = p->val;
		i++;
	}
	free(n);
}

static void	big_list3(t_struct *s, t_node	*p, t_node	*n, int i)
{
	while (p++ < n + s->size_a - 1)
	{
		if (p->val < n[i].val && p->len >= n[i].len)
		{
			n[i].next = p;
			n[i].len = p->len + 1;
		}
	}
}

void	big_list(t_struct *s)
{
	int		i;
	t_node	*p;
	t_node	*n;

	n = calloc(s->size_a, sizeof(*n));
	if (n == NULL)
		message_free("Error malloc\n", 1, s);
	i = 0;
	while (i < s->size_a - 1)
	{
		n[i].val = s->list_a[i];
		i++;
	}
	i = s->size_a - 1;
	while (i >= 0)
	{
		p = n + i;
		big_list3(s, p, n, i);
		i--;
	}
	big_list2(s, p, n);
}

void	create_sort2(t_struct *s, int i, int j)
{
	int	a;

	a = 0;
	while (i < s->size_a)
	{
		j = i + 1;
		while (j < s->size_a)
		{
			if (s->sorted[i] < s->sorted[j])
			{
				a = s->sorted[i];
				s->sorted[i] = s->sorted[j];
				s->sorted[j] = a;
			}
			j++;
		}
		i++;
	}
}
