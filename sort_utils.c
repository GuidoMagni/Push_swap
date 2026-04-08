/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:34:19 by guido             #+#    #+#             */
/*   Updated: 2026/04/03 12:49:38 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list *a)
{
	int	max;

	max = a->n;
	while (a)
	{
		if (a->n > max)
			max = a->n;
		a = a->next;
	}
	return (max);
}

int	min(t_list *a)
{
	int	min;

	min = a->n;
	while (a)
	{
		if (a->n < min)
			min = a->n;
		a = a->next;
	}
	return (min);
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
