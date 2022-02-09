/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:48:33 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/01 12:43:05 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_min(t_list *a)
{
	int	m;

	m = 2147483647;
	while (a != NULL)
	{
		if (a->n < m)
			m = a->n;
		a = a->next;
	}
	return (m);
}

int	ft_max(t_list *a)
{
	int	m;

	m = -2147483648;
	while (a != NULL)
	{
		if (a->n > m)
			m = a->n;
		a = a->next;
	}
	return (m);
}

int	ft_ind(t_list *a, int m)
{
	int	i;

	i = 1;
	while (a->n != m)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_f(t_list *a)
{
	int	f;

	f = 0;
	if (ft_lstsize(&a) < 250)
		f = (ft_max(a) - ft_min(a)) / 11;
	else if (ft_lstsize(&a) > 250)
		f = (ft_max(a) - ft_min(a)) / 12;
	return (f);
}
