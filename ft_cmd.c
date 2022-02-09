/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:52:36 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/01 16:40:08 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sc(t_list **c, t_list **b, char s, t_cmd **d)
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
		if (s == 'a')
			ft_cmdadd_back(d, ft_cmdnew("sa\n", c, b, d));
		if (s == 'b')
			ft_cmdadd_back(d, ft_cmdnew("sb\n", c, b, d));
	}
}

void	ft_pc(t_list **a, t_list **b, char s, t_cmd **d)
{
	t_list	*temp;

	temp = *a;
	if (temp == NULL)
		exit(0);
	*a = temp->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp);
	if (s == 'b')
		ft_cmdadd_back(d, ft_cmdnew("pa\n", a, b, d));
	if (s == 'a')
		ft_cmdadd_back(d, ft_cmdnew("pb\n", a, b, d));
}

void	ft_rc(t_list **c, char s, t_cmd **d, t_list **b)
{
	t_list	*temp;

	temp = *c;
	if (temp == NULL)
		exit(0);
	*c = temp->next;
	temp->next = NULL;
	ft_lstadd_back(c, temp);
	if (s == 'a')
		ft_cmdadd_back(d, ft_cmdnew("ra\n", c, b, d));
	if (s == 'b')
		ft_cmdadd_back(d, ft_cmdnew("rb\n", c, b, d));
}

void	ft_rrc(t_list **c, char s, t_cmd **d, t_list **b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *c;
	if (temp1 == NULL)
		exit(0);
	temp2 = ft_lstlast(temp1);
	while (temp1->next->next != NULL)
		temp1 = temp1->next;
	temp1->next = NULL;
	ft_lstadd_front(c, temp2);
	if (s == 'a')
		ft_cmdadd_back(d, ft_cmdnew("rra\n", c, b, d));
	if (s == 'b')
		ft_cmdadd_back(d, ft_cmdnew("rrb\n", c, b, d));
}
