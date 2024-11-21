/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:55:21 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/19 13:55:23 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->top = NULL;
	new->bottom = NULL;
	new->size = 0;
	return (new);
}

t_node	*node_create(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->next = NULL;
	new->prev = NULL;
	new->data = data;
	return (new);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**data;

	if (ac < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	data = make_data(av, ac);
	stack_add(a, b, data);
	push_swap_algorithm(a, b);
	t_node *now;
	printf("------------------------------\n");
	now = a->top;
	while (now->next)
	{
		printf("a :%d\n", now->data);
		now = now->next;
	}
	printf("a :%d\n", now->data);
	printf("------------------------------\n");
	/*now = b->top;
	while (now->next)
	{
		printf("b :%d\n", now->data);
		now = now->next;
	}
	printf("b :%d\n", now->data);*/
}
