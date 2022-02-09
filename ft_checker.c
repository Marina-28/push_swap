/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:29:00 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/01 13:05:15 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checksort(t_list *a)
{
	while (a->next != NULL)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_checkdubl(t_list **a)
{
	t_list	*temp1;
	t_list	*temp2;
	int		p;

	temp1 = *a;
	temp2 = *a;
	while (temp2 != NULL)
	{
		temp1 = *a;
		p = 0;
		while (temp1 != NULL)
		{
			if (temp1->n == temp2->n)
			{
				p++;
				if (p > 1)
					return (1);
			}
			temp1 = temp1->next;
		}
		temp2 = temp2->next;
	}
	return (0);
}

int	ft_atoicheck(char *str)
{
	int		i;
	int		k;
	long	n;

	k = 1;
	n = 0;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			k = k * (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		n = n * 10 + k * (str[i] - 48);
		i++;
	}
	if (n > 2147483647 || n < -2147483648 || i != ft_strlen(str))
		return (1);
	return (0);
}

int	ft_checkint(int end, char **argv)
{
	int	i;

	i = 1;
	while (i <= end)
	{
		if (ft_atoicheck(argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkinttwo(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (ft_atoicheck(argv[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
