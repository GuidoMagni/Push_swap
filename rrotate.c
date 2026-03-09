/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:52:42 by guido             #+#    #+#             */
/*   Updated: 2026/03/09 15:59:35 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_list **a)
{
	t_list	*last;
	t_list	*penultimo;

	if (!a || !*a || !(*a)->next)
		return ;
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
