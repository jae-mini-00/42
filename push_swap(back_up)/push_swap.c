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

t_stack	*push_swap_stack_init(void)
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

t_node	*push_swap_node_create(int data)
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

void	ft_end_free(t_stack *list, t_stack *b)
{
	t_node	*temp;

	while (list->size)
	{
		temp = pop(list);
		free(temp);
	}
	free(list);
	free(b);
	exit(3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**data;

	if (ac < 2)
		return (0);
	a = push_swap_stack_init();
	b = push_swap_stack_init();
	data = push_swap_make_data(av, ac);
	if (!data)
		return (0);
	push_swap_stack_add(a, b, data);
	push_swap_error_check(a, b, data);
	push_swap_algorithm(a, b);
	/*printf("------------------------------\n");
	t_node *now;
	t_node *now2;
	int	d;
	now = a->top;
	now2 = b->top;
	d = 1;
	while (a->size - d + 1 > 0 || b->size - d + 1> 0)
	{
		if(a->size - d + 1 > 0 && b->size - d + 1 > 0)
			printf("%d = b :%d    a :%d\n",d, now2->data, now->data);
		else if (a->size - d + 1 > 0)
			printf("%d = b :     a :%d\n",d, now->data);
		else if (b->size - d + 1 > 0)
			printf("%d = b :%d    a :\n",d, now2->data);
		d++;
		if (now)
			now = now->next;
		if (now2)
			now2 = now2->next;
	}
	printf("------------------------------\n");
	*/
	ft_end_free(a, b);
}
