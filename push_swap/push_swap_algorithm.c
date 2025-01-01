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

int	push_swap_ra_cost(t_stack *a, t_node *b_now)
{
	int		ra_cost;
	t_node	*a_now;

	ra_cost = 0;
	a_now = a->top;
	if (a_now->data > b_now->data && \
		((a->bottom->data > a->bottom->prev->data && \
		a->bottom->data > a_now->data) || a->bottom->data < b_now->data))
		return (0);
	while (1)
	{
		ra_cost++;
		a_now = a_now->next;
		if (!a_now->next)
			return (ra_cost);
		else if (a_now->data > b_now->data && a_now->prev->data < b_now->data)
			return (ra_cost);
		else if (a_now->data > a_now->next->data && \
				b_now->data < a->bottom->data && \
				a_now->next->data > b_now->data)
			return (ra_cost + 1);
	}
	return (ra_cost);
}

int	push_swap_rra_cost(t_stack *a, t_node *b_now)
{
	int		rra_cost;
	t_node	*a_now;

	rra_cost = 0;
	a_now = a->bottom;
	while (1)
	{
		if (!a_now->prev)
			return (0);
		else if (a_now->data > b_now->data && a_now->prev->data < b_now->data)
			return (++rra_cost);
		else if (a_now->data > b_now->data && a_now->data < a_now->prev->data)
			return (++rra_cost);
		rra_cost++;
		a_now = a_now->prev;
	}
	return (rra_cost);
}

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
		push_swap_greedy(a, b);
	}
}
