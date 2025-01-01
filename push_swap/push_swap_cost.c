/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:52:14 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/02 20:52:16 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	push_swap_ra_cost(t_stack *a, t_node *b_now)
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
*/
int	push_swap_ra_minimum_cost1(t_stack *a, t_stack *b, int *ra_flag)
{
	int		ra_cost;
	int		cost_temp;
	int		i;
	t_node	*now;

	i = 0;
	*ra_flag = 0;
	ra_cost = 1000;
	now = b->top;
	while (b->size > i)
	{
		if (!now || ra_cost < i)
			return (ra_cost);
		cost_temp = push_swap_ra_cost(a, now);
		if (ra_cost >= cost_temp + i)
		{
			ra_cost = cost_temp;
			*ra_flag = i;
		}
		now = now->next;
		i++;
	}
	return (ra_cost);
}

int	push_swap_ra_minimum_cost2(t_stack *a, t_stack *b, int *ra_flag)
{
	int		ra_cost;
	int		cost_temp;
	int		i;
	t_node	*now;

	i = 0;
	*ra_flag = 0;
	ra_cost = 1000;
	now = b->bottom;
	while (b->size > i)
	{
		if (!now || ra_cost < i)
			return (ra_cost);
		cost_temp = push_swap_ra_cost(a, now);
		i++;
		if (ra_cost >= cost_temp + i)
		{
			ra_cost = cost_temp;
			*ra_flag = i;
		}
		now = now->prev;
	}
	return (ra_cost);
}

int	push_swap_rra_minimum_cost1(t_stack *a, t_stack *b, int *rra_flag)
{
	int		rra_cost;
	int		cost_temp;
	int		i;
	t_node	*now;

	i = 0;
	*rra_flag = 0;
	rra_cost = 1000;
	now = b->top;
	while (b->size > i)
	{
		if (!now || rra_cost < i)
			return (rra_cost);
		cost_temp = push_swap_rra_cost(a, now);
		if (rra_cost >= cost_temp + i)
		{
			rra_cost = cost_temp;
			*rra_flag = i;
		}
		now = now->next;
		i++;
	}
	return (rra_cost);
}

int	push_swap_rra_minimum_cost2(t_stack *a, t_stack *b, int *rra_flag)
{
	int		rra_cost;
	int		cost_temp;
	int		i;
	t_node	*now;

	i = 0;
	*rra_flag = 0;
	rra_cost = 1000;
	now = b->bottom;
	while (b->size > i)
	{
		if (!now || rra_cost < i)
			return (rra_cost);
		cost_temp = push_swap_rra_cost(a, now);
		i++;
		if (rra_cost >= cost_temp + i)
		{
			rra_cost = cost_temp;
			*rra_flag = i;
		}
		now = now->prev;
	}
	return (rra_cost);
}
