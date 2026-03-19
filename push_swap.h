/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:07:28 by gumagni           #+#    #+#             */
/*   Updated: 2026/03/19 18:53:26 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

long	ft_atoi(const char *str);
long	ft_is_space(char c);
void	error(long a);

typedef struct s_list
{
	int				n;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
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
void	sort_3(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
int		max(t_list *a);
int		min(t_list *a);
int		pos(t_list *a, int value);

#endif