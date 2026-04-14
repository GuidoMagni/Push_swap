/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:01:10 by guido             #+#    #+#             */
/*   Updated: 2026/04/13 11:32:23 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	if (!lst) 
		return (0);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

t_list	*find_last(t_list *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
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
