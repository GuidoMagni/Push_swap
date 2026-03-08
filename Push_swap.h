/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:07:28 by gumagni           #+#    #+#             */
/*   Updated: 2026/03/08 21:54:59 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long	ft_atoi(const char *str);
long	ft_is_space(char c);
void	error(long a);

typedef struct s_list
{
	int				n;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_stack(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	sa(t_list *a);
void	sb(t_list *a);
void	ss(t_list *a, t_list *b);
void	ra(t_list **a);
void	rb(t_list **a);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **a);
void	rrr(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

#endif