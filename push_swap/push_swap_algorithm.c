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

void	hard_coding(t_stack *a)
{
	int		big_data;

	if ((a->top->data > a->bottom->data) && (a->top->data > a->top->next->data))
	{
		ra(a);
		if (a->top->next->data < a->top->data)
			sa(a);
	}
	else if ((a->top->data < a->bottom->data) && (a->bottom->data > a->top->next->data))
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

void	push_swap_algorithm(t_stack *a, t_stack *b)
{
	t_node	*now;
	int	p;
	int	i;
	int	small_data;

	pivot_setting(a, b);
	hard_coding(a);
//	int fuck = 5;
/*	while (a->size)
	{
		i = 1;
		now = a->top;
		small_data = 2147483647;
		while (now->next)
		{
			if (small_data >= now->data)
			{
				small_data = now->data;
				p = i;
			}
			now = now->next;
			i++;
		}
		if (a->bottom->data < small_data)
		{
			small_data = a->bottom->data;
			p = a->size;
		}
	//	printf ("\nsmall :%d\np :%d\nsize :%d\n\n", small_data, p, a->size);
		if (p <= a->size/2 + 1)
		{
			i = 1;
			while (p > i++)
				ra(a);
		}
		else
		{
			i = 0;
			while (p + i++ <= a->size)
				rra(a);
		}
		//printf("data :%d\n\n", a->top->data);
		pb(b, a);
	}
	while (b->size)
		pa(a, b);*/
}
