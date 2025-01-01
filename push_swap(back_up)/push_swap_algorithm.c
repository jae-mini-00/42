/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:25:30 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/20 20:25:33 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_swap_hard_coding(t_stack *a)
{
	if ((a->top->data > a->bottom->data) && (a->top->data > a->top->next->data))
	{
		ra(a);
		if (a->top->next->data < a->top->data)
			sa(a);
	}
	else if ((a->top->data < a->bottom->data) && \
		(a->bottom->data > a->top->next->data))
	{
		if (a->top->data > a->top->next->data)
			sa(a);
	}
	else
	{
		rra(a);
		if (a->top->data > a->top->next->data)
			sa(a);
	}
}

void	push_swap_hard_hard_coding(t_stack *a, t_stack *b)
{
	int	pivot_data;

	pivot_data = push_swap_hard_pivot(a);
	while (a->size > 3)
	{
		if (a->top->data < pivot_data)
			pb(b, a);
		else if (a->bottom->data < pivot_data)
			rra(a);
		else
			ra(a);
	}
	push_swap_hard_coding(a);
	while (b->size)
		pa(a, b);
	if (a->top->data > a->top->next->data)
		sa(a);
}

/*void	greedy(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		while (b->size > 0 && (a->top->data < b->top->data))
			ra(a);
		if (b->top->data < a->top->data)
			pa(a, b);
		while (b->size > 0 && (a->bottom->data < a->top->data) && \
			(a->bottom->data > b->top->data))
			rra(a);
	}
	while (a->bottom->data < a->top->data)
		rra(a);
}*/

void	push_swap_algorithm(t_stack *a, t_stack *b)
{
	if (a->size < 6)
	{
		if (a->size < 4)
			push_swap_hard_coding(a);
		else
			push_swap_hard_hard_coding(a, b);
	}
	else
	{
		push_swap_pivot_setting2(a, b);
		push_swap_hard_coding(a);
		//greedy(a, b);
		push_swap_greedy(a, b);
	}
}
