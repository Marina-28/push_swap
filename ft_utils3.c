/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:16:38 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/02 13:33:13 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list *a)
{
	t_list	*temp;
	t_list	*t;

	temp = a;
	while (temp != NULL)
	{
		t = temp;
		temp = (temp)->next;
		free(t);
	}
}

void	ft_free1(t_cmd **d)
{
	t_cmd	*temp;
	t_cmd	*t;

	temp = *d;
	while (temp != NULL)
	{
		t = temp;
		temp = (temp)->next;
		free(t);
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_onearg(char **argv, t_list **a)
{
	char	**arr;
	int		k;
	t_list	*new;

	k = 0;
	arr = ft_split(argv[1], ' ');
	if (ft_checkinttwo(arr) != 0)
	{
		ft_free_arr(arr);
		write(2, "Error\n", 6);
		exit (1);
	}
	while (arr[k] != NULL)
	{
		new = ft_lstnew(ft_atoi(arr[k]));
		if (new == NULL)
		{
			ft_free_arr(arr);
			ft_free(*a);
		}
		ft_lstadd_back(a, new);
		k++;
	}
	ft_free_arr(arr);
}

void	ft_fewarg(int argc, char **argv, t_list **a)
{
	int		i;
	int		j;
	t_list	*new;

	i = argc - 1;
	j = 1;
	if (ft_checkint(i, argv) != 0)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	while (j <= i)
	{
		new = ft_lstnew(ft_atoi(argv[j]));
		if (new == NULL)
			ft_free(*a);
		ft_lstadd_back(a, new);
		j++;
	}
}
