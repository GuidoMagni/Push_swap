/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guido <guido@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:07:28 by gumagni           #+#    #+#             */
/*   Updated: 2026/03/04 22:30:36 by guido            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long	ft_atoi(const char *str);
long	ft_is_space(char c);
void	error(long a);

typedef struct s_list
{
	int				n;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	free_list(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

#endif