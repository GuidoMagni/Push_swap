/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:54:48 by guido             #+#    #+#             */
/*   Updated: 2026/03/09 16:04:48 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
