/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:33:24 by guido             #+#    #+#             */
/*   Updated: 2026/03/04 22:54:26 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_Pushswap(t_list *a)
{
	int	tmp;

	tmp = 0;
	if (ft_lstsize(a) == 2 && a->n > a->next->n)
	{
		tmp = a->n;
		a->n = a->next->n;
		a->next->n = tmp;
	}
	if (ft_lstsize(a) == 3)
	{
		if (a->n > a->next->n && a->n > a->next->next->n)
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