/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:33:24 by guido             #+#    #+#             */
/*   Updated: 2026/03/06 20:21:18 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_Pushswap(t_list *a)
{
	int	tmp;
	int	size;

	size = ft_lstsize(a);
	if (size == 2 && a->n > a->next->n)
	{
		sa(a);
	}
	if (size > 2)
	{
		//ra(a);
		rra(a);
	}
}

void	ft_plist(t_list *a)
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

int	main(int ac, char **av)
{
	int		num;
	int		b;
	t_list	*a;

	num = 1;
	a = NULL;
	while (num < ac)
	{
		b = 0;
		b = atoi(av[num]);
		ft_lstadd_back(&a, ft_lstnew(b));
		num++;
	}
	ft_plist(a);
	printf("\n");
	ft_Pushswap(a);
	ft_plist(a);
	free_list(a);
}

//dovro usare ft_printf mi sa

/*if (a->n > a->next->n && a->n > a->next->next->n)
{
	tmp = a->next->next->n;
	a->next->next->n = a->n;
	if (tmp > a->next->n)
	{
		a->n = a->next->n;
		a->next->n = tmp;
	}
	else
		a->n = tmp;
}
if (a->n > a->next->n)
{
	tmp = a->next->n;
	a->next->n = a->n;
	if (tmp > a->next->next->n)
		a->next->next->n = tmp;
	a->n = tmp;
}
if (a->n > a->next->next->n)
{
	tmp = a->next->next->n;
	a->next->next->n = a->n;
	if (a->next->n > tmp)
	{
		a->n = a->next->n;
		a->next->n = tmp;
	}
	else
		a->n = tmp;
}*/