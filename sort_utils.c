/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:34:19 by guido             #+#    #+#             */
/*   Updated: 2026/04/21 20:40:02 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *a)
{
	long			min;
	t_list			*min_node;

	if (!a)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (a->n < min)
		{
			min = a->n;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

t_list	*find_max(t_list *a)
{
	long			max;
	t_list			*max_node;

	if (!a)
		return (NULL);
	max = LONG_MIN;
	while (a)
	{
		if (a->n > max)
		{
			max = a->n;
			max_node = a;
		}
		a = a->next;
	}
	return (max_node);
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
