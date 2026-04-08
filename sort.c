/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:15:12 by guido             #+#    #+#             */
/*   Updated: 2026/04/08 16:42:47 by gumagni          ###   ########.fr       */
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
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	sort_stack(t_list **a, t_list **b)
{
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 5 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 5 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 5 && !is_sorted(*a)) //If stack `a` still has more than 5 nodes and aren't sorted
	{
		init_nodes_a(*a, *b); //Iniate all nodes from both stacks
		move_a_to_b(a, b); //Move the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	sort_5(a, b);
	while (*b) //Until the end of stack `b` is reached
	{
		init_nodes_b(*a, *b); //Initiate all nodes from both stacks
		move_b_to_a(a, b); //Move all `b` nodes back to a sorted stack `a`
	}
	current_index(*a); //Refresh the current position of stack `a`
	min_on_top(a); //Ensure smallest number is on top
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