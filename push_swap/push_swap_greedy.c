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

#include "push_swap.h"

int	push_swap_find_ra_minimum_cost(t_stack *a, t_stack *b, int *ra_flag)
{
	int	ra_cost1;
	int	ra_cost2;
	int	ra_flag1;
	int	ra_flag2;

	ra_cost1 = push_swap_ra_minimum_cost1(a, b, &ra_flag1);
	ra_cost2 = push_swap_ra_minimum_cost2(a, b, &ra_flag2);
	if (ra_cost1 <= ra_cost2)
	{
		ra_flag[0] = 1;
		ra_flag[1] = ra_flag1;
		return (ra_cost1);
	}
	else
	{
		ra_flag[0] = 2;
		ra_flag[1] = ra_flag2;
		return (ra_cost2);
	}
}

int	push_swap_find_rra_minimum_cost(t_stack *a, t_stack *b, int *rra_flag)
{
	int	rra_cost1;
	int	rra_cost2;
	int	rra_flag1;
	int	rra_flag2;

	rra_cost1 = push_swap_rra_minimum_cost1(a, b, &rra_flag1);
	rra_cost2 = push_swap_rra_minimum_cost2(a, b, &rra_flag2);
	if (rra_cost1 <= rra_cost2)
	{
		rra_flag[0] = 1;
		rra_flag[1] = rra_flag1;
		return (rra_cost1);
	}
	else
	{
		rra_flag[0] = 2;
		rra_flag[1] = rra_flag2;
		return (rra_cost2);
	}
}

void	go_rra(t_stack *a, t_stack *b, int rra_cost, int *rra_flag)
{
	if (rra_flag[0] == 1)
		while (rra_flag[1]-- > 0)
			rb(b);
	else if (rra_flag[0] == 2)
		while (rra_flag[1]-- > 0)
			rrb(b);
	while (rra_cost)
	{
		rra(a);
		rra_cost--;
	}
}

void	go_ra(t_stack *a, t_stack *b, int ra_cost, int *ra_flag)
{
	if (ra_flag[0] == 1)
		while (ra_flag[1]-- > 0)
			rb(b);
	else if (ra_flag[0] == 2)
		while (ra_flag[1]-- > 0)
			rrb(b);
	while (ra_cost)
	{
		ra(a);
		ra_cost--;
	}
}

void	push_swap_greedy(t_stack *a, t_stack *b)
{
	int	ra_cost;
	int	rra_cost;
	int	ra_flag[2];
	int	rra_flag[2];

	while (b->size)
	{
		ra_cost = push_swap_find_ra_minimum_cost(a, b, ra_flag);
		rra_cost = push_swap_find_rra_minimum_cost(a, b, rra_flag);
		if (rra_cost <= ra_cost)
			go_rra(a, b, rra_cost, rra_flag);
		else
			go_ra(a, b, ra_cost, ra_flag);
		pa(a, b);
	}
}
