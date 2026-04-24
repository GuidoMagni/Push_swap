/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:54:20 by gumagni           #+#    #+#             */
/*   Updated: 2026/04/21 17:51:32 by guido            ###   ########.fr       */
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
		write(2, "Error\n", 6);
		exit(1);
	}
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
