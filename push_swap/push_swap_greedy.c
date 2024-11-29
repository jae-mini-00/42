/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_greedy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:52:02 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/28 15:52:04 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	push_swap_ra_cost(t_stack *a, t_node *b_now)
{
	int		ra_cost;
	t_node	*a_now;

	ra_cost = 0;
	a_now = a->top;
	while (a_now->data < b_now->data)
	{
		ra_cost++;
		a_now = a_now->next;
	}
	return (ra_cost);
}

int	push_swap_rra_cost(t_stack *a, t_node *b_now)
{
	int		rra_cost;
	t_node	*a_now;

	rra_cost = 0;
	a_now = a->bottom;
	while (a_now->data < b_now->data)
	{
		if (a->bottom->data > a->bottom->prev->data)
			return (-1);
		rra_cost++;
		a_now = a_now->prev;
	}
	return (rra_cost);
}

int	push_swap_minimum_cost(t_stack *a, t_stack *b)
{
	int		ra_cost;
	int		rra_cost;

	if (b->size)
	{
		ra_cost = push_swap_ra_cost(a, b->top);
		rra_cost = push_swap_rra_cost(a, b->top);
		if (rra_cost > 0 && rra_cost <= ra_cost)
		{
			while (rra_cost)
			{
				rra(a);
				rra_cost--;
			}
			pa(a, b);
		}
		else
		{
			while (ra_cost)
			{
				ra(a);
				ra_cost--;
			}
			pa(a, b);
		}
	}
}

void	push_swap_greedy(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		push_swap_minimum_cost(a, b); 
	}
}
