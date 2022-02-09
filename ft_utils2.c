/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:13:39 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/01 16:43:18 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	a;
	int	k;
	int	n;

	k = 1;
	n = 0;
	a = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			k = k * (-1);
		str++;
	}
	while (*str == 48)
		str++;
	while (*str > 47 && *str < 58)
	{
		n = n * 10 + k * (*str - 48);
		str++;
		a++;
	}
	return (n);
}

void	ft_push(t_list **b, t_cmd **d, char *s, t_list **a)
{
	char	*ra;
	char	*rra;
	t_list	*temp;

	ra = "ra\n";
	rra = "rra\n";
	temp = NULL;
	if (*b != NULL)
	{
		temp = ft_lstlast(*b);
		if ((*b)->next != NULL && (*b)->n < (*b)->next->n && s == ra)
			ft_rc(b, 'b', d, a);
		else if (*b != NULL && (*b)->n < temp->n && s == rra)
			ft_rrc(b, 'b', d, a);
	}
}

void	ft_fromb(t_list **a, t_list **b, t_cmd **d)
{
	int	i;
	int	m;

	while ((*b)->next != NULL)
	{
		m = ft_max(*b);
		i = ft_ind(*b, m);
		if (i > ft_lstsize(b) / 2)
		{
			while ((*b)->n != m)
				ft_rrc(b, 'b', d, a);
		}
		else
		{
			while ((*b)->n != m)
				ft_rc(b, 'b', d, a);
		}
		ft_pc(b, a, 'b', d);
	}
	ft_pc(b, a, 'b', d);
}

void	ft_move(t_list **a, t_list **b, t_cmd **d, int c)
{
	if (c <= (ft_lstsize(a) / 2))
	{
		while (c != 1)
		{
			ft_rc(a, 'a', d, a);
			c = c - 1;
		}
		ft_push(b, d, "ra\n", a);
	}
	else if (c > (ft_lstsize(a) / 2))
	{
		while ((ft_lstsize(a) - c + 1) != 0)
		{
			ft_rrc(a, 'a', d, a);
			c = c + 1;
		}
		ft_push(b, d, "rra\n", a);
	}
}

int	ft_find_ind(t_list **a, int min, int f, int k)
{
	int		c;
	int		j;
	int		i;
	t_list	*temp;

	c = 0;
	temp = *a;
	while (temp != NULL)
	{
		if ((temp->n >= (min + (f * (k - 1)))) && (temp->n < (min + (f * k))))
		{
			j = ft_ind(*a, temp->n);
			c++;
		}
		if ((temp->n >= (min + (f * (k - 1))))
			&& (temp->n < (min + (f * k))) && c == 1)
			i = ft_ind(*a, temp->n);
		temp = temp->next;
	}
	if (c != 0 && (i - 1) < (ft_lstsize(a) - j + 1))
		return (i);
	else if (c != 0 && (i - 1) >= (ft_lstsize(a) - j + 1))
		return (j);
	return (0);
}
