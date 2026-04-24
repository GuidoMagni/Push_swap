/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:15:12 by guido             #+#    #+#             */
/*   Updated: 2026/04/21 20:43:01 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
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
	current_index(*a);
	while (ft_lstsize(*a) != 3)
	{
		min_on_top(a);
		pb(a, b);
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	sort_stack(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 5 && !is_sorted(*a))
		pb(a, b);
	if (len_a-- > 5 && !is_sorted(*a))
		pb(a, b);
	while (len_a-- > 5 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_5(a, b);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	min_on_top(t_list **a)
{
	while ((*a)->n != find_min(*a)->n)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
