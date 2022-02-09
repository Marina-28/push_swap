/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:31 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/02 13:36:47 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_list **a, int q, t_cmd **d, t_list **b)
{
	if (q == 2)
	{
		if ((*a)->n > (*a)->next->n)
			ft_sc(a, b, 'a', d);
	}
	else if (q == 3)
	{
		if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
			ft_rc(a, 'a', d, b);
		if ((*a)->next->n > (*a)->n && (*a)->next->n > (*a)->next->next->n)
			ft_rrc(a, 'a', d, b);
		if ((*a)->n > (*a)->next->n)
			ft_sc(a, b, 'a', d);
		if ((*a)->next->n > (*a)->next->next->n)
		{
			ft_rc(a, 'a', d, b);
			ft_sc(a, b, 'a', d);
			ft_rrc(a, 'a', d, b);
		}
	}
}

void	ft_sort_midl(t_list	**a, t_list **b, t_cmd **d)
{
	int		i;
	int		m;

	while (ft_lstsize(a) != 3)
	{
		m = ft_min(*a);
		i = ft_ind(*a, m);
		if (i > ft_lstsize(a) / 2)
		{
			while ((*a)->n != m)
				ft_rrc(a, 'a', d, b);
		}
		else
		{
			while ((*a)->n != m)
				ft_rc(a, 'a', d, b);
		}
		ft_pc(a, b, 'a', d);
	}
	ft_sort_small(a, ft_lstsize(a), d, b);
	while (*b != NULL)
		ft_pc(b, a, 'b', d);
}

void	ft_sort_big(t_list **a, t_list **b, t_cmd **d)
{
	int	k;
	int	c;
	int	f;
	int	min;

	k = 0;
	f = ft_f(*a);
	min = ft_min(*a);
	while (ft_lstsize(a) != 0)
	{
		k++;
		if (ft_checksort(*a) == 1)
			break ;
		while (1)
		{
			c = ft_find_ind(a, min, f, k);
			if (c > 1)
				ft_move(a, b, d, c);
			else if (c == 0)
				break ;
			ft_pc(a, b, 'a', d);
		}
	}
	ft_fromb(a, b, d);
}

void	ft_push_swap(t_list **a, t_list **b, t_cmd **d)
{
	int	q;

	q = ft_lstsize(a);
	if (q <= 3)
		ft_sort_small(a, q, d, b);
	else if (q > 3 && q <= 20)
		ft_sort_midl(a, b, d);
	else
		ft_sort_big(a, b, d);
	ft_putcmd(*d);
	ft_free1(d);
}

int	main(int argc, char	**argv)
{
	t_list	*a;
	t_list	*b;
	t_cmd	*d;

	a = NULL;
	b = NULL;
	d = NULL;
	if (argc == 1)
		write(1, "Enter numbers\n", 14);
	if (argc == 2)
		ft_onearg(argv, &a);
	else if (argc > 2)
		ft_fewarg(argc, argv, &a);
	if (a != NULL)
	{
		if (ft_checkdubl(&a) == 0 && ft_checksort(a) == 0)
			ft_push_swap(&a, &b, &d);
	}
	if (ft_checkdubl(&a) != 0)
		write(2, "Error\n", 6);
	ft_free(a);
	return (0);
}
