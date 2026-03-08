/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:14:47 by gumagni           #+#    #+#             */
/*   Updated: 2026/03/08 21:53:50 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	swap(t_list *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->n;
	a->n = a->next->n;
	a->next->n = tmp;
}

void	sa(t_list *a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_list *a)
{
	write(1, "sb\n", 3);
	swap(a);
}

void	ss(t_list *a, t_list *b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}

void	rotate(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_list **a)
{
	write(1, "ra\n", 3);
	rotate(a);
}

void	rb(t_list **a)
{
	write(1, "rb\n", 3);
	rotate(a);
}

void	rr(t_list **a, t_list **b)
{
	write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}

void	rrotate(t_list **a)
{
	t_list	*last; //uso nodi invece dei valori
	t_list	*penultimo;

	if (!a || !*a || !(*a)->next)
		return;

	penultimo = *a;
	while (penultimo->next->next)
		penultimo = penultimo->next;
	last = penultimo->next;
	penultimo->next = NULL;
	last->next = *a;
	*a = last;
}

void	rra(t_list **a)
{
	write(1, "rra\n", 4);
	rrotate(a);
}

void	rrb(t_list **a)
{
	write(1, "rrb\n", 4);
	rrotate(a);
}

void	rrr(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	rrotate(a);
	rrotate(b);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*b_first;

	write(1, "pa\n", 3);
	if (!*b)
		return ;
	b_first = *b;
	*b = (*b)->next;
	b_first->next = *a;
	*a = b_first;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*a_first;

	write(1, "pb\n", 3);
	if (!*a)
		return ;
	a_first = *a;
	*a = (*a)->next;
	a_first->next = *b;
	*b = a_first;
}

/*void	rotate(t_list *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->n;
	while (a)
	{
		if (!a->next)
			a->n = tmp;
		else
			a->n = a->next->n;
		a = a->next;
	}
}*/