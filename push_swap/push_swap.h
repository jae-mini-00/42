/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:17:07 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/03 18:42:24 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

int			ft_pivot(t_stack *a);
int			ft_pivot2(t_stack *a);
int			push_swap_hard_pivot(t_stack *a);
int			push_swap_ra_cost(t_stack *a, t_node *b_now);
int			push_swap_rra_cost(t_stack *a, t_node *b_now);
int			push_swap_ra_minimum_cost1(t_stack *a, t_stack *b, int *ra_flag);
int			push_swap_ra_minimum_cost2(t_stack *a, t_stack *b, int *ra_flag);
int			push_swap_rra_minimum_cost1(t_stack *a, t_stack *b, int *rra_flag);
int			push_swap_rra_minimum_cost2(t_stack *a, t_stack *b, int *rra_flag);
void		push(t_stack *list, t_node *data);
void		push_swap_greedy(t_stack *a, t_stack *b);
void		push_swap_atob(t_stack *a, t_stack *b);
void		push_swap_rb_ox(t_stack *b, int pivot2);
void		push_swap_pivot_setting1(t_stack *a, t_stack *b);
void		push_swap_pivot_setting2(t_stack *a, t_stack *b);
void		push_swap_algorithm(t_stack *a, t_stack *b);
void		push_swap_stack_add(t_stack *a, t_stack *b, char **data);
void		push_swap_error_check(t_stack *a, t_stack *b, char **data);
void		ft_data_free(char **data);
void		ft_stack_free(t_stack *list, t_stack *b);
void		ft_end_free(t_stack *list, t_stack *b);
void		bottom_push(t_stack *list, t_node *data);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *b, t_stack *a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
char		**push_swap_make_data(char **av, int ac);
t_node		*push_swap_node_create(int data);
t_node		*pop(t_stack *list);
t_node		*bottom_pop(t_stack *list);
long long	push_swap_atoi(char *av);

#endif
