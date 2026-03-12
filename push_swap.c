/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:33:24 by guido             #+#    #+#             */
/*   Updated: 2026/03/12 15:45:33 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pstack(t_list *a)
{
	if (!a)
	{
		printf("(empty)\n");
		return ;
	}
	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}

void	ft_pushswap(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*a);
	if (size == 2 && (*a)->n > (*a)->next->n)
	{
		sa(*a);
	}
	if (size == 3)
	{
		if ((*a)->n > (*a)->next->n && (*a)->n > (*a)->next->next->n)
			ra(a);
		if ((*a)->next->n > (*a)->n && (*a)->next->n > (*a)->next->next->n)
			rra(a);
		if ((*a)->n > (*a)->next->n)
			sa(*a);
	}
	if (size == 5)
	{
		pb(a, b);
		pb(a, b);
		ft_pushswap(a, b);
		pa(a, b);
		if ((*a)->n > (*a)->next->next->next->n)
			ra(a);
	}
}

int	main(int ac, char **av)
{
	int		num;
	int		n;
	t_list	*a;
	t_list	*b;

	num = 1;
	a = NULL;
	b = NULL;
	while (num < ac)
	{
		n = 0;
		n = atoi(av[num]);
		ft_lstadd_back(&a, ft_lstnew(n));
		num++;
	}
	ft_pushswap(&a, &b);
	write(1, "STACK a:\n", 9);
	pstack(a);
	write(1, "STACK b:\n", 10);
	pstack(b);
	free_stack(&a);
	free_stack(&b);
}
