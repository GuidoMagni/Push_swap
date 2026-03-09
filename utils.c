/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:54:20 by gumagni           #+#    #+#             */
/*   Updated: 2026/03/09 16:00:39 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_is_space(char c)
{
	return ((c == ' ')
		|| (c == '\t')
		|| (c == '\n')
		|| (c == '\v')
		|| (c == '\f')
		|| (c == '\r'));
}

long	ft_atoi(const char *str)
{
	int		i;
	int		a;
	long	result;

	result = 0;
	i = 0;
	a = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	error(result * a);
	return (result * a);
}

void	error(long a)
{
	if (a < INT_MIN || a > INT_MAX)
	{
		write(1, "Error\n", 1);
		exit(1);
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->n = content;
	new->next = NULL;
	return (new);
}
