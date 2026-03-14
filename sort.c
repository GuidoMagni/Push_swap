/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:15:12 by guido             #+#    #+#             */
/*   Updated: 2026/03/14 19:09:43 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a, t_list **b)
{
	if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
		ra(a);
	if ((*a)->next->n > (*a)->n && (*a)->next->n > (*a)->next->next->n)
		rra(a);
	if ((*a)->n > (*a)->next->n)
		sa(*a);
}

void	sort_5(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) != 3)
	{
		if (pos(*a, min(*a)) < ft_lstsize(*a) / 2)
		{
			while ((*a)->n != min(*a))
				ra(a);
		}
		else
		{
			while ((*a)->n != min(*a))
				rra(a);
		}
		pb(a, b);
	}
	sort_3(a, b);
	pa(a, b);
	pa(a, b);
}

	// pb(a, b);
	// pb(a, b);
	// sort_3(a, b);
	// if ((*b)->next->n > (*b)->n)
	// 	sb(*b);
	// pa(a, b);
	// if ((*a)->n > (*a)->next->next->next->n)
	// 	ra(a);
	// pa(a, b);