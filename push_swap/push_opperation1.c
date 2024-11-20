/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_opperation1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:02:53 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/19 14:02:55 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = pop(b);
	if (!temp)
		return ;
	push(a, temp);
	write (1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	t_node	*temp;

	temp = pop(a);
	if (!temp)
		return ;
	push(b, temp);
	write (1, "pb\n", 3);
}

void	rra(t_stack *a)
{
	t_node	*temp;

	temp = bottom_pop(a);
	if (!temp)
		return ;
	push(a, temp);
	write (1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*temp;

	temp = bottom_pop(b);
	if (!temp)
		return ;
	push(b, temp);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	t_node	*atemp;
	t_node	*btemp;

	if (a->size < 2 || b->size < 2)
		return ;
	atemp = bottom_pop(a);
	btemp = bottom_pop(b);
	push(a, atemp);
	push(b, btemp);
	write (1, "rrr\n", 4);
}
