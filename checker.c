/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:21:01 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/02 13:49:13 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list *a, t_list *b, char *arr, char s)
{
	ft_free(a);
	ft_free(b);
	free(arr);
	if (s == 'w')
		write(2, "Error\n", 6);
	exit (1);
}

void	move(t_list **a, t_list **b, char	**s)
{
	if (ft_strcmp(*s, "ra"))
		ch_rc(a);
	else if (ft_strcmp(*s, "rb"))
		ch_rc(b);
	else if (ft_strcmp(*s, "sa"))
		ch_sc(a);
	else if (ft_strcmp(*s, "sb"))
		ch_sc(b);
	else if (ft_strcmp(*s, "rra"))
		ch_rrc(a);
	else if (ft_strcmp(*s, "rrb"))
		ch_rrc(b);
	else if (ft_strcmp(*s, "pa"))
		ch_pc(b, a);
	else if (ft_strcmp(*s, "pb"))
		ch_pc(a, b);
	else if (ft_strcmp(*s, "rr"))
		ch_r(a, b, 'r');
	else if (ft_strcmp(*s, "rrr"))
		ch_r(a, b, 'q');
	else
		ft_error(*a, *b, *s, 'w');
}

void	ft_checker(t_list **a, t_list	**b)
{
	if ((ft_checksort(*a) == 0 || *b != NULL))
		write(1, "KO\n", 3);
	else if ((ft_checksort(*a) != 0))
		write(1, "OK\n", 3);
}

int	ft_reader(char **arr, t_list **a, t_list **b)
{
	int		j;
	int		i;
	char	*buf;

	j = 0;
	buf = (char *)malloc(5 * sizeof(char));
	if (buf == NULL)
		ft_error(*a, *b, *arr, 'n');
	i = read(0, &buf[j], 1);
	while (i > 0 && buf[j] != '\n')
	{
		j++;
		i = read(0, &buf[j], 1);
	}
	buf[j] = '\0';
	if (i == -1)
		ft_error(*a, *b, *arr, 'n');
	*arr = buf;
	return (i);
}

int	main(int argc, char	**argv)
{
	t_list	*a;
	t_list	*b;
	char	*arr;

	a = NULL;
	b = NULL;
	arr = NULL;
	if (argc == 1)
		write(1, "Enter numbers\n", 14);
	if (argc == 2)
		ft_onearg(argv, &a);
	else if (argc > 2)
		ft_fewarg(argc, argv, &a);
	if (a != NULL)
	{
		if (ft_checkdubl(&a) != 0)
			ft_error(a, b, arr, 'w');
		while (ft_reader(&arr, &a, &b) > 0)
		{
			move(&a, &b, &arr);
			free(arr);
		}
		free(arr);
		ft_checker(&a, &b);
	}
	ft_free(a);
	return (0);
}
