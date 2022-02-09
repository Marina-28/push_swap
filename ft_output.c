/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:52:35 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/02 13:49:23 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return (0);
		}
		else
			i++;
	}
	return (1);
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

void	ft_putcmd(t_cmd *a)
{
	while (a->next != NULL)
	{
		if (ft_strcmp(a->cmd, "ra\n") && ft_strcmp(a->next->cmd, "rb\n"))
		{
			ft_putstr("rr\n");
			a = a->next->next;
		}
		else if (ft_strcmp(a->cmd, "rra\n") && ft_strcmp(a->next->cmd, "rrb\n"))
		{
			ft_putstr("rrr\n");
			a = a->next->next;
		}
		else
		{
			ft_putstr(a->cmd);
			a = a->next;
		}
	}
	ft_putstr(a->cmd);
}
