/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:48:23 by gumagni           #+#    #+#             */
/*   Updated: 2026/04/14 19:03:21 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_list *a, t_list *b) //Define a function that sets for the current `a` node, its target node from stack `a`
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
			if (current_b->n < a->n 
				&& current_b->n > best_match_index) //Check if the current `b` node's value is bigger than the current `a` node, && smaller than the "closest bigger" so far
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

void	cost_analysis_a(t_list *a, t_list *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		if (a->target->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->cost += a->target->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->cost += len_b - (a->target->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_list *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	t_list			*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = true; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

void	init_nodes_a(t_list *a, t_list *b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

void	move_a_to_b(t_list **a, t_list **b) //Define a function that prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
{
	t_list	*cheapest_node; //To store the pointer to the cheapest `a` node

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node || !cheapest_node->target)
		return ;
	if (cheapest_node->above_median 
		&& cheapest_node->target->above_median) //If both the cheapest `a` node and its target `b` node are above the median
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target->above_median)) //If both the cheapest `a` node and its target `b` node are below the median
		rev_rotate_both(a, b, cheapest_node); //`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node, 'a'); //Ensure the cheapest nodes is at the top, ready for pushing
	prep_for_push(b, cheapest_node->target, 'b'); //Ensure the target node is at the top, ready for pushing
	pb(a, b);
}