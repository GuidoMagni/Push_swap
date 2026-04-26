/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:46:51 by gumagni           #+#    #+#             */
/*   Updated: 2026/04/26 15:32:07 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->n > b->n && current_a->n < best_match_index)
			{
				best_match_index = current_a->n;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_list *a, t_list *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

void	move_b_to_a(t_list **a, t_list **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b);
}
