/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:34:19 by guido             #+#    #+#             */
/*   Updated: 2026/04/13 10:21:29 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *a) //Define a function that searches a a and returns the node with the smallest number
{
	long			min; //To store the smallest value so far
	t_list	*min_node; //To store a pointer that points to the smallest number

	if (!a)
		return (NULL);
	min = LONG_MAX; //Assign to the smallest value so far, the max long integer
	while (a) //Loop until the end of the a is reached
	{
		if (a->n < min) //Check if the current node value is smaller than the smallest so far
		{
			min = a->n; //If so, update the smallest number so far
			min_node = a; //Set the pointer to point to the node with the smallest number so far
		}
		a = a->next; //Move to the next node for processing
	}
	return (min_node); 
}

t_list	*find_max(t_list *a) //Define a function that searches a a and returns the node with the biggest number
{
	long			max; //To store the biggest value so far
	t_list	*max_node; //To store a pointer that points to the biggest number

	if (!a)
		return (NULL);
	max = LONG_MIN; //Assign to the biggest value so far, the max long integer
	while (a) //Loop until the end of the a is reached
	{
		if (a->n > max) //Check if the current node value is smaller than the biggest so far
		{
			max = a->n; //If so, update the biggest number so far
			max_node = a; //Set the pointer to point to the node with the biggest number so far
		}
		a = a->next; //Move to the next node for processing
	}
	return (max_node);
}

int	pos(t_list *a, int value)
{
	int	pos;

	pos = 0;
	while (a->n != value)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

void	current_index(t_list *a)
{
	int	i;
	int	median;

	i = 0;
	if (!a)
		return ;
	median = ft_lstsize(a) / 2;
	while (a)
	{
		a->index = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		++i;
	}
}
