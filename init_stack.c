/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 13:03:58 by guido             #+#    #+#             */
/*   Updated: 2026/04/13 12:10:03 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_list **a, int num)
{
	t_list	*node;
	t_list	*last_node;

	if (!a)
		return ;
	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->next = NULL;
	node->n = num;
	node->cheapest = 0;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_a(t_list **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			free_errors(a);
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);
		if (error_dup(*a, (int)n))
			free_errors(a);
		append_node(a, (int)n);
		i++;
	}
}

bool	is_sorted(t_list *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->n > a->next->n)
			return (false);
		a = a->next;
	}
	return (true);
}

t_list	*get_cheapest(t_list *a) //Define a function that searches for the cheapest node, that is set by bool
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	prep_for_push(t_list **a, t_list *top, char stack_name) //Define a function that moves the required node to the top of the a
{
	while (*a != top) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is a `a`, execute the following
		{
			if (top->above_median)
				ra(a);
			else
				rra(a);
		}
		else if (stack_name == 'b') //If not, and it is a `b`, execute the following
		{
			if (top->above_median)
				rb(a);
			else
				rrb(a);
		}	
	}
}
