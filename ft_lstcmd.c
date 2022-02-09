/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:28:48 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/01 16:34:27 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd	*ft_cmdnew(char *s, t_list **a, t_list **b, t_cmd **d)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
	{
		ft_free(*a);
		ft_free(*b);
		ft_free1(d);
	}
	new->cmd = s;
	new->next = NULL;
	return (new);
}

void	ft_cmdadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*temp;

	temp = *lst;
	if (temp != NULL)
	{
		while (temp ->next != NULL)
			temp = temp ->next;
		temp ->next = new;
	}
	else
		*lst = new;
}
