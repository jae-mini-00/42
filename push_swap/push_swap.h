/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:17:07 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/19 13:32:16 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../ft_printf/libft/libft.h"

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

int		ft_push_swap_atoi(char *av);
int		ft_pivot(t_stack *a, t_stack *b);
t_node	*node_create(int data);
t_node	*pop(t_stack *list);
t_node	*bottom_pop(t_stack *list);
void	pivot_setting(t_stack *a, t_stack *b);
void	push_swap_algorithm(t_stack *a, t_stack *b);
void	stack_add(t_stack *a, t_stack *b, char **av);
void	push(t_stack *list, t_node *data);
void	bottom_push(t_stack *list, t_node *data);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
char	**make_data(char **av, int ac);

#endif
