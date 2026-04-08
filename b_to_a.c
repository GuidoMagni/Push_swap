/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:46:51 by gumagni           #+#    #+#             */
/*   Updated: 2026/04/08 17:25:51 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_list *a, t_list *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	t_list	*current_a; //To store the pointer to the current `a` node
	t_list	*target_node; //To store the pointer of the target node for `b` node
	long	best_match_index; //To store the "closest bigger" number so far

	while (b)
	{
		best_match_index = LONG_MAX; //Set the current best match to the max long
		current_a = a; //Assign the pointer to point to the current `a` node
		while (current_a) //While the pointer is not set to NULL
		{
			if (current_a->n > b->n 
				&& current_a->n < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_a->n; //Set the best match as the value in the current `a` node
				target_node = current_a; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_a = current_a->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MAX) //If the best match value has not changed
			b->target = find_min(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next; //Move to the next `b` node for processing
	}
}

void	init_nodes_b(t_list *a, t_list *b) //Define a function that prepares the nodes for pushing `b` to `a`
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	move_b_to_a(t_list **a, t_list **b) //Define a function that prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
{
	prep_for_push(a, (*b)->target, 'a'); //Ensure `b`'s target `a` node is on top of the stack
	pa(a, b);
}