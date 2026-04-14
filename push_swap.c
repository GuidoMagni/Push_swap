/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:33:24 by guido             #+#    #+#             */
/*   Updated: 2026/04/14 18:39:26 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	pstack(t_list *a)
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
}*/

void	ft_pushswap(t_list **a, t_list **b)
{
	int		size;

	size = ft_lstsize(*a);
	if (size == 2 && (*a)->n > (*a)->next->n)
		sa(*a);
	else if (size == 3)
		sort_3(a);
	else if (size == 5)
		sort_5(a, b);
	else
		sort_stack(a, b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	else if (ac == 2 && !av[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av++;
	init_a(&a, av);
	if (!is_sorted(a))
		ft_pushswap(&a, &b);
	/*while (num < ac)
	{
		n = 0;
		n = atoi(av[num]);
		ft_lstadd_back(&a, ft_lstnew(n));
		num++;
	}
	ft_pushswap(&a, &b);
	write(1, "STACK a:\n", 9);
	pstack(a);
	write(1, "STACK b:\n", 9);
	pstack(b);
	free_stack(&b);*/
	free_stack(&a);
	return(0);
}
