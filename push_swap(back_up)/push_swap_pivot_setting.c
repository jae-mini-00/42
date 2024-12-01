/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:59:53 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/24 18:59:55 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_atob(t_stack *a, t_stack *b)
{
	int	p1;

	p1 = push_swap_hard_pivot(a);
	while (a->size > 3)
	{
		if (a->top->data < p1)
		{
			pb(b, a);
			/*if (b->size > 1 && (b->top->data < b->top->next->data))
				sb(b);*/
		}
		else
			ra(a);
	}
}

void	push_swap_pivot_setting1(t_stack *a, t_stack *b)
{
	int	p1;
	int	p2;
	int	i;

	p1 = ft_pivot(a);
	p2 = ft_pivot2(a);
	i = a->size;
	while (i--)
	{
		if (a->top->data <= p2)
		{
			pb(b, a);
			push_swap_rb_ox(b, p1);
		}
		else
			ra(a);
	}
}

void	push_swap_pivot_setting2(t_stack *a, t_stack *b)
{
	int	p1;
	int	i;

	push_swap_pivot_setting1(a, b);
	p1 = ft_pivot2(a);
	i = a->size;
	while (i--)
	{
		if (a->top->data <= p1)
		{
		pb(b, a);
			/*if (b->size > 1 && (b->top->data < b->top->next->data))
				sb(b);*/
		}
		else
			ra(a);
	}
	push_swap_atob(a, b);
}
