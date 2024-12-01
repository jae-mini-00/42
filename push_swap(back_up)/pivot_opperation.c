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

int	ft_pivot2(t_stack *a)
{
	t_node		*now;
	int			pivot;
	int			i;
	long long	s;

	i = 1;
	pivot = 2147483647;
	s = -2147483649;
	while (i <= (a->size / 2))
	{
		now = a->top;
		pivot = 2147483647;
		while (now->next)
		{
			if (now->data <= pivot && s < now->data)
				pivot = now->data;
			now = now->next;
		}
		if (now->data <= pivot && s < now->data)
			pivot = now->data;
		s = pivot;
		i++;
	}
	return (s);
}

int	ft_pivot(t_stack *a)
{
	t_node		*now;
	int			pivot;
	int			i;
	long long	s;

	i = 1;
	pivot = 2147483647;
	s = -2147483649;
	while (i <= (a->size / 4))
	{
		now = a->top;
		pivot = 2147483647;
		while (now->next)
		{
			if (now->data <= pivot && s < now->data)
				pivot = now->data;
			now = now->next;
		}
		if (now->data <= pivot && s < now->data)
			pivot = now->data;
		s = pivot;
		i++;
	}
	return (s);
}

int	push_swap_hard_pivot(t_stack *a)
{
	t_node		*now;
	int			pivot;
	int			i;
	long long	s;

	i = 1;
	pivot = -2147483648;
	s = 2147483648;
	while (i <= 3)
	{
		now = a->top;
		pivot = -2147483648;
		while (now->next)
		{
			if (now->data >= pivot && s > now->data)
				pivot = now->data;
			now = now->next;
		}
		if (now->data >= pivot && s > now->data)
			pivot = now->data;
		s = pivot;
		i++;
	}
	return (s);
}

void	push_swap_rb_ox(t_stack *b, int pivot2)
{
	t_node	*now;

	now = b->top;
	if (b->size > 1 && (now->data <= pivot2))
		rb(b);
	/*else if (b->size > 1 && (now->data < now->next->data))
		sb(b);*/
}
