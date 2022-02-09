/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeana <bjeana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:31:59 by bjeana            #+#    #+#             */
/*   Updated: 2021/12/02 13:38:13 by bjeana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				n;
	struct s_list	*next;
}	t_list;
typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}	t_cmd;
int		ft_checksort(t_list *a);
int		ft_checkdubl(t_list **a);
int		ft_atoicheck(char	*str);
int		ft_checkint(int end, char **argv);
int		ft_checkinttwo(char **argv);
void	ft_sc(t_list **c, t_list **b, char s, t_cmd **d);
void	ft_pc(t_list **a, t_list **b, char s, t_cmd **d);
void	ft_rc(t_list **c, char s, t_cmd **d, t_list **b);
void	ft_rrc(t_list **c, char s, t_cmd **d, t_list **b);
t_list	*ft_lstnew(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list **lst);
t_cmd	*ft_cmdnew(char *s, t_list **a, t_list **b, t_cmd **d);
void	ft_cmdadd_back(t_cmd **lst, t_cmd *new);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
void	ft_putcmd(t_cmd *a);
char	**ft_split(char *s, char c);
int		ft_strlen(const char *s);
int		ft_min(t_list *a);
int		ft_max(t_list *a);
int		ft_ind(t_list *a, int m);
int		ft_f(t_list *a);
int		ft_atoi(char *str);
void	ft_push(t_list **b, t_cmd **d, char *s, t_list **a);
void	ft_fromb(t_list **a, t_list **b, t_cmd **d);
void	ft_move(t_list **a, t_list **b, t_cmd **d, int c);
int		ft_find_ind(t_list **a, int min, int f, int k);
void	ft_onearg(char **argv, t_list **a);
void	ft_fewarg(int argc, char **argv, t_list **a);
void	ft_free(t_list *a);
void	ft_free1(t_cmd **d);
void	ft_sort_small(t_list **a, int q, t_cmd **d, t_list **b);
void	ft_sort_midl(t_list	**a, t_list **b, t_cmd **d);
void	ft_sort_big(t_list **a, t_list **b, t_cmd **d);
void	ft_push_swap(t_list **a, t_list **b, t_cmd **d);
void	ch_sc(t_list **c);
void	ch_pc(t_list **a, t_list **b);
void	ch_rc(t_list **c);
void	ch_rrc(t_list **c);
void	ch_r(t_list **a, t_list **b, char s);
void	ft_error(t_list *a, t_list *b, char *arr, char s);
void	move(t_list **a, t_list **b, char	**s);
void	ft_checker(t_list **a, t_list	**b);
int		ft_reader(char **arr, t_list **a, t_list **b);
#endif
