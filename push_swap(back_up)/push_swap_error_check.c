/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:49:50 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/24 21:49:52 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_data_free(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		free(data[i++]);
	free(data);
}

void	ft_stack_free(t_stack *list, t_stack *b)
{
	t_node	*temp;

	while (list->size)
	{
		temp = pop(list);
		free(temp);
	}
	free(list);
	free(b);
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_ascending_order_check(t_stack *a, t_stack *b)
{
	t_node	*now;
	int		i;

	now = a->top;
	while (now->next)
	{
		i = now->data;
		if (i > now->next->data)
			break ;
		now = now->next;
	}
	if (!(now->next) && now->data > i)
	{
		ft_end_free(a, b);
		exit(2);
	}
}

void	ft_same_data_check(t_node *now, t_stack *a, t_stack *b)
{
	t_node	*temp;
	int		i;
	int		j;

	j = 1;
	while (a->size > j++)
	{
		i = now->data;
		temp = now->next;
		while (temp->next)
		{
			if (i == temp->data)
				ft_stack_free(a, b);
			temp = temp->next;
		}
		if (i == temp->data)
			ft_stack_free(a, b);
		now = now->next;
	}
}

void	push_swap_error_check(t_stack *a, t_stack *b, char **data)
{
	t_node	*now;
	int		i;

	ft_data_free(data);
	if (a->size < 2)
		ft_end_free(a, b);
	ft_ascending_order_check(a, b);
	ft_same_data_check(a->top, a, b);
}
