/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:33:24 by guido             #+#    #+#             */
/*   Updated: 2026/03/03 15:01:36 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_pushswap(t_list *stacka)
{
	while (stacka)
	{
		printf("%d ", stacka->n);//dovro usare ft_printf mi sa
		stacka = stacka->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	int	a;
	t_list	*stacka;

	a = 1;
	stacka = NULL;
	while (a < ac)
		ft_lstadd_back(&stacka, ft_lstnew(atoi(av[a++])));
	ft_pushswap(stacka);
}
