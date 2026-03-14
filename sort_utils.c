/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:34:19 by guido             #+#    #+#             */
/*   Updated: 2026/03/14 19:07:37 by guido            ###   ########.fr       */
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
