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

int	ft_push_swap_atoi(char *av)
{
	int			i;
	int			flag;
	long long	temp;

	i = 0;
	flag = 1;
	temp = 0;
	if (av[i] == '-' || av[i] == '+')
	{
		if (av[i] == '-')
			flag = -1;
		i++;
	}
	while (av[i] >= '0' && av[i] <= '9')
	{
		temp = (temp * 10) + av[i] - 48;
		i++;
	}
	if (temp > 2147483647 || temp < -2147483648 || av[i] != '\0')
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	return ((int)temp * flag);
}

void	stack_add(t_stack *a, t_stack *b, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		push(b, node_create(ft_push_swap_atoi(av[i])));
		i++;
	}
	while (b->size > 0)
	{
		push(a, pop(b));
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	stack_add(a, b, av);
	/*t_node *now;
	printf("------------------------------\n");
	int	i;

	i = 1;
	while (av[i])
	{
		push(b, node_create(ft_push_swap_atoi(av[i])));
		i++;
	}
	rra(a);
	now = a->top;
	while (now->next)
	{
		printf("a :%d\n", now->data);
		now = now->next;
	}
	printf("a :%d\n", now->data);
	printf("------------------------------\n");
	now = b->top;
	while (now->next)
	{
		printf("b :%d\n", now->data);
		now = now->next;
	}
	printf("b :%d\n", now->data);*/
}
