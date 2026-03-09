/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:48:25 by guido             #+#    #+#             */
/*   Updated: 2026/03/09 15:59:27 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
