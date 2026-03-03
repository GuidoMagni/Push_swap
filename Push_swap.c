/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:33:24 by guido             #+#    #+#             */
/*   Updated: 2026/03/03 18:19:07 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_pushswap(t_list *stacka)
{
	if (!stacka)
	{
		printf("(empty)\n");
		return ;
	}
	while (stacka)
	{
		printf("%d ", *stacka->n);
		stacka = stacka->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	int		a;
	int		*b;
	t_list	*stacka;

	a = 1;
	stacka = NULL;
	while (a < ac)
	{
		b = malloc(sizeof(int));
		*b = atoi(av[a]);
		ft_lstadd_back(&stacka, ft_lstnew(b));
		a++;
	}
	ft_pushswap(stacka);
	free_list(stacka);
}

//printf("%d ", *stacka->n);//dovro usare ft_printf mi sa