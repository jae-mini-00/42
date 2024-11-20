/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_opperation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:25:52 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/19 15:25:54 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*bottom_pop(t_stack *list)
{
	t_node	*temp;

	if (list->size < 1)
		return (NULL);
	temp = list->bottom;
	list->bottom = list->bottom->prev;
	if (list->size > 1)
		list->bottom->next = NULL;
	else
		list->bottom = NULL;
	temp->prev = NULL;
	list->size--;
	return (temp);
}

void	bottom_push(t_stack *list, t_node *new)
{
	if (list->bottom == NULL)
	{
		list->top = new;
		list->bottom = new;
	}
	else
	{
		list->bottom->next = new;
		new->prev = list->bottom;
		list->bottom = new;
	}
	list->size++;
}

void	ra(t_stack *a)
{
	t_node	*temp;

	temp = pop(a);
	if (!temp)
		return ;
	bottom_push(a, temp);
	write (1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*temp;

	temp = pop(b);
	if (!temp)
		return ;
	bottom_push(b, temp);
	write (1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	t_node	*atemp;
	t_node	*btemp;

	if (a->size < 2 || b->size < 2)
		return ;
	atemp = pop(a);
	btemp = pop(b);
	bottom_push(a, atemp);
	bottom_push(b, btemp);
	write (1, "rr\n", 3);
}
