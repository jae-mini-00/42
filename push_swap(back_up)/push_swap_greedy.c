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

int	push_swap_ra_minimum_cost(t_stack *a, t_stack *b, int *ra_flag)
{
	int		ra_top_cost;
	int		ra_top_next_cost;
	int		ra_bottom_cost;

	ra_top_next_cost = 600;
	ra_top_cost = push_swap_ra_cost(a, b->top);
	if (b->size > 1)
		ra_top_next_cost = push_swap_ra_cost(a, b->top->next);
	ra_bottom_cost = push_swap_ra_cost(a, b->bottom);
	//printf("ra = top :%d top_n : %d bot :%d\n", ra_top_cost, ra_top_next_cost, ra_bottom_cost);
	if (ra_top_cost <= ra_top_next_cost && ra_top_cost <= ra_bottom_cost)
	{
		*ra_flag = 0;
		return(ra_top_cost);
	}
	else if (ra_bottom_cost <= ra_top_cost && ra_bottom_cost <= ra_top_next_cost)
	{
		*ra_flag = 1;
		return (ra_bottom_cost);
	}
	else
	{
		*ra_flag = 2;
		return (ra_top_next_cost);
	}
	/*if (b->size)
	{
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
	}*/
}

int	push_swap_rra_minimum_cost(t_stack *a, t_stack *b, int *rra_flag)
{
	int		rra_top_cost;
	int		rra_top_next_cost;
	int		rra_bottom_cost;

	rra_top_next_cost = 600;
	rra_top_cost = push_swap_rra_cost(a, b->top);
	if (b->size > 1)
		rra_top_next_cost = push_swap_rra_cost(a, b->top->next);
	rra_bottom_cost = push_swap_rra_cost(a, b->bottom);

	//printf("rra = top :%d top_n : %d bot :%d\n", rra_top_cost, rra_top_next_cost, rra_bottom_cost);
	if (rra_top_cost <= rra_top_next_cost && rra_top_cost <= rra_bottom_cost)
	{
		*rra_flag = 0;
		return(rra_top_cost);
	}
	else if (rra_bottom_cost <= rra_top_cost && rra_bottom_cost <= rra_top_next_cost)
	{
		*rra_flag = 1;
		return (rra_bottom_cost);
	}
	else
	{
		*rra_flag = 2;
		return (rra_top_next_cost);
	}
}

void	push_swap_greedy(t_stack *a, t_stack *b)
{
	int	ra_cost;
	int	rra_cost;
	int	ra_flag;
	int	rra_flag;

	while (b->size)
	{
		ra_cost = push_swap_ra_minimum_cost(a, b, &ra_flag);
		rra_cost = push_swap_rra_minimum_cost(a, b, &rra_flag);
		if (rra_cost <= ra_cost)
		{
			if (rra_flag == 2)
				sb(b);
			else if (rra_flag == 1)
				rrb(b);
			while (rra_cost)
			{
				rra(a);
				rra_cost--;
			}
		}
		else
		{
			if (ra_flag == 2)
				sb(b);
			else if (ra_flag == 1)
				rrb(b);
			while (ra_cost)
			{
				ra(a);
				ra_cost--;
			}
		}
		pa(a, b);
	}
	while (a->bottom->data < a->top->data)
		rra(a);
}
