/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:48:23 by gumagni           #+#    #+#             */
/*   Updated: 2026/04/08 17:26:25 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_list *a, t_list *b) //Define a function that sets for the current `a` node, its target node from stack `a`
{
	t_list	*current_b; //To store the pointer to the current `a` node
	t_list	*target_node; //To store the pointer of the target node for `b` node
	long	best_match_index; //To store the "closest bigger" number so far

	while (a)
	{
		best_match_index = LONG_MIN; //Set the current best match to the max long
		current_b = b; //Assign the pointer to point to the current `a` node
		while (current_b) //While the pointer is not set to NULL
		{
			if (current_b->n > b->n 
				&& current_b->n < best_match_index) //Check if the `a` node's value is bigger than `b` node, && smaller than the "closest bigger" so far
			{
				best_match_index = current_b->n; //Set the best match as the value in the current `a` node
				target_node = current_b; //Set `b` node's target node pointer to point to the current `a` node
			}
			current_b = current_b->next; //Move to the next `a` node for processing
		}
		if (best_match_index == LONG_MIN) //If the best match value has not changed
			a->target = find_max(b); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			a->target = target_node; //If the best match value has been updated, then we have a target node for the current `a` node
		a = a->next; //Move to the next `b` node for processing
	}
}

