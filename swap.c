/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:14:47 by gumagni           #+#    #+#             */
/*   Updated: 2026/04/26 15:41:10 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->n;
	a->n = a->next->n;
	a->next->n = tmp;
}

void	sa(t_list *a)
{
	write(1, "sa\n", 3);
	swap(a);
}

void	sb(t_list *a)
{
	write(1, "sb\n", 3);
	swap(a);
}

void	ss(t_list *a, t_list *b)
{
	write(1, "ss\n", 3);
	swap(a);
	swap(b);
}
