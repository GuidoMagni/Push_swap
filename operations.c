/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:14:47 by gumagni           #+#    #+#             */
/*   Updated: 2026/03/06 21:13:43 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	sa(t_list	*a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->n;
	a->n = a->next->n;
	a->next->n = tmp;
}

void	ra(t_list	*a)
{
	int	tmp;

	tmp = a->n;
	while (a)
	{
		if (!a->next)
			a->n = tmp;
		else
			a->n = a->next->n;
		a = a->next;
	}
}

void	rra(t_list	*a)
{
	int	tmp1;
	t_list	*start;

	start = a;

	while (a->next)
	{
		if (!a->next->next)
			tmp1 = a->n;         // ???
		a = a->next;
	}
	start->n = a->n;
	a->n = tmp1;
}
