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
	if (a_now->data > b_now->data && ((a->bottom->data > a->bottom->prev->data && \
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
		else if (a_now->data > a_now->next->data && b_now->data < a->bottom->data && \
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
		//rra_cost++;
		//a_now = a_now->prev;
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
/*
int	push_swap_rra_cost(t_stack *a, t_node *b_now)
{
	int		rra_cost;
	t_node	*a_now;

	rra_cost = 0;
	a_now = a->bottom;
	if (a->top->data > b_now->data && a_now->data > b_now->data && \
		(a_now->data > a_now->prev->data && a_now->data > a->top->data))
		return (0);
	else if (a_now->data > b_now->data && (a_now->prev->data < b_now->data || \
			a_now->data < a_now->prev->data))
		return (1);
	while (1)
	{
		rra_cost++;
		a_now = a_now->prev;
		if (!a_now->prev)
				return (rra_cost);
		else if (a_now->data > b_now->data && a_now->prev->data < b_now->data)
			return (++rra_cost);
		else if (a_now->data > b_now->data && a_now->data < a_now->prev->data)
			return (++rra_cost);
	}
	return (rra_cost);
}
*/
int	push_swap_minimum_cost(t_stack *a, t_stack *b)
{
	int		ra_cost;
	int		rra_cost;

	if (b->size)
	{
		ra_cost = push_swap_ra_cost(a, b->top);
		rra_cost = push_swap_rra_cost(a, b->top);
		//printf("b :%d cost_ra :%d cost_rra :%d\n",b->top->data, ra_cost, rra_cost);
		if (rra_cost <= ra_cost)
		{
			while (rra_cost)
			{
				rra(a);
				rra_cost--;
			}
		}
		else
		{
			while (ra_cost)
			{
				ra(a);
				ra_cost--;
			}
		}
		pa(a,b);
	}
}

void	push_swap_greedy(t_stack *a, t_stack *b)
{
	while (b->size)
	//int	fuck = 15;
	//while (fuck--)
	{
		push_swap_minimum_cost(a, b); 
	}
	while (a->bottom->data < a->top->data)
		rra(a);
}
