/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_opperation0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:33:35 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/18 18:33:37 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*pop(t_stack *list)
{
	t_node	*node;

	if (list->size < 1)
		return (NULL);
	node = list->top;
	list->top = list->top->next;
	if (list->size > 1)
		list->top->prev = NULL;
	else
		list->bottom = NULL;
	node->next = NULL;
	list->size--;
	return (node);
}

void	push(t_stack *list, t_node *new)
{
	if (list->top == NULL)
	{
		list->top = new;
		list->bottom = new;
	}
	else
	{
		list->top->prev = new;
		new->next = list->top;
		list->top = new;
	}
	list->size++;
}

void	sa(t_stack *a)
{
	t_node	*top;
	t_node	*top_next;

	if (a->size < 2)
		return ;
	top = pop(a);
	top_next = pop(a);
	push(a, top);
	push(a, top_next);
	write (1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*top;
	t_node	*top_next;

	if (b->size < 2)
		return ;
	top = pop(b);
	top_next = pop(b);
	push(b, top);
	push(b, top_next);
	write (1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	t_node	*atop;
	t_node	*atop_next;
	t_node	*btop;
	t_node	*btop_next;

	if (a->size < 2 || b->size < 2)
		return ;
	atop = pop(a);
	atop_next = pop(a);
	btop = pop(b);
	btop_next = pop(b);
	push(a, atop);
	push(a, atop_next);
	push(b, btop);
	push(b, btop_next);
	write (1, "ss\n", 3);
}
