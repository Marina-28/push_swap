/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:58:53 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/01 17:43:10 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_sc(t_list **c)
{
	int		data;
	t_list	*temp;

	temp = *c;
	if (ft_lstsize(c) > 1)
	{
		data = temp->n;
		temp->n = temp->next->n;
		temp->next->n = data;
		*c = temp;
	}
}

void	ch_pc(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	if (ft_lstsize(a) < 1)
		return ;
	*a = temp->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp);
}

void	ch_rc(t_list **c)
{
	t_list	*temp;

	if (ft_lstsize(c) <= 1)
		return ;
	temp = *c;
	*c = temp->next;
	temp->next = NULL;
	ft_lstadd_back(c, temp);
}

void	ch_rrc(t_list **c)
{
	t_list	*temp1;
	t_list	*temp2;

	if (ft_lstsize(c) <= 1)
		return ;
	temp1 = *c;
	if (temp1 == NULL)
		exit(0);
	temp2 = ft_lstlast(temp1);
	while (temp1->next->next != NULL)
		temp1 = temp1->next;
	temp1->next = NULL;
	ft_lstadd_front(c, temp2);
}

void	ch_r(t_list **a, t_list **b, char s)
{
	if (s == 'r')
	{
		ch_rc(a);
		ch_rc(b);
	}
	else
	{
		ch_rrc(a);
		ch_rrc(b);
	}
}
