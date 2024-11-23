/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:38:50 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/23 18:38:53 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_pivot2(t_stack *a, t_stack *b)
{
	t_node	*now;
	int		pivot;
	int		s;
	int		i;

	i = 1;
	pivot = 2147483647;
	s = -2147483648;
	while (i <= (a->size / 3 + a->size / 3))
	{
		now = a->top;
		pivot = 2147483647;
		while (now->next)
		{
			if (now->data <= pivot && s < now->data)
				pivot = now->data;
			now = now->next;
		}
		s = pivot;
		i++;
	}
	return (s);
}

int	ft_pivot(t_stack *a, t_stack *b)
{
	t_node	*now;
	int		pivot;
	int		s;
	int		i;

	i = 1;
	pivot = 2147483647;
	s = -2147483648;
	while (i <= (a->size / 3))
	{
		now = a->top;
		pivot = 2147483647;
		while (now->next)
		{
			if (now->data <= pivot && s < now->data)
				pivot = now->data;
			now = now->next;
		}
		s = pivot;
		i++;
	}
	return (s);
}

void	rb_ox(t_stack *b, int pivot2)
{
	t_node	*now;

	now = b->top;
	if (b->size > 1 && (now->data <= pivot2))
		rb(b);
}

void	pivot_setting(t_stack *a, t_stack *b)
{
	int	p1;
	int	p2;
	int	i;

	p1 = ft_pivot(a, b);
	p2 = ft_pivot2(a, b);
	i = a->size;
	while (i--)
	{
		if (a->top->data <= p2)
		{
			pb(b, a);
			rb_ox(b, p1);
		}
		else
			ra(a);
	}
	while (a->size > 3)
		pb(b, a);
}
