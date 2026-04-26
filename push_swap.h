/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:07:28 by gumagni           #+#    #+#             */
/*   Updated: 2026/04/26 15:37:35 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

long	ft_atoi(const char *str);
long	ft_is_space(char c);
void	error(long a);

typedef struct s_list
{
	int				n;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*find_last(t_list *a);
int		error_syntax(char *str_n);
int		error_dup(t_list *a, int n);
void	free_stack(t_list **stack);
void	free_errors(t_list **a);
void	swap(t_list *a);
void	sa(t_list *a);
void	sb(t_list *a);
void	ss(t_list *a, t_list *b);
void	rotate(t_list **a);
void	ra(t_list **a);
void	rb(t_list **a);
void	rr(t_list **a, t_list **b);
void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	rrotate(t_list **a);
void	rra(t_list **a);
void	rrb(t_list **a);
void	rrr(t_list **a, t_list **b);
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
t_list	*find_min(t_list *a);
t_list	*find_max(t_list *a);
void	append_node(t_list **a, int num);
void	init_a(t_list **a, char **av);
bool	is_sorted(t_list *a);
t_list	*get_cheapest(t_list *a);
void	prep_for_push(t_list **a, t_list *top, char stack_name);
void	set_target_a(t_list *a, t_list *b);
void	cost_analysis_a(t_list *a, t_list *b);
void	set_cheapest(t_list *stack);
void	init_nodes_a(t_list *a, t_list *b);
void	move_a_to_b(t_list **a, t_list **b);
void	set_target_b(t_list *a, t_list *b);
void	init_nodes_b(t_list *a, t_list *b);
void	move_b_to_a(t_list **a, t_list **b);
void	min_on_top(t_list **a);
void	sort_3(t_list **a);
void	sort_5(t_list **a, t_list **b);
void	sort_stack(t_list **a, t_list **b);
char	**ft_split(char const *s, char c);
void	current_index(t_list *a);

#endif