/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:12:02 by jaejo             #+#    #+#             */
/*   Updated: 2024/11/20 17:12:03 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_stack_add(t_stack *a, t_stack *b, char **data)
{
	int			i;
	long long	temp;

	i = 0;
	if (!data)
		exit(2);
	while (data[i])
	{
		temp = push_swap_atoi(data[i]);
		if (temp < -2147483648)
		{
			ft_data_free(data);
			ft_stack_free(b, a);
		}
		push(b, push_swap_node_create((int)temp));
		i++;
	}
	while (b->size > 0)
	{
		push(a, pop(b));
	}
}

long long	push_swap_atoi(char *av)
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
	temp *= flag;
	if ((temp > 2147483647 || temp < -2147483648 || av[i] != '\0') && \
		av[i] != ' ')
		return (-2147483649);
	return (temp * flag);
}

char	**push_swap_make_data(char **av, int ac)
{
	char	**data;
	char	*temp;
	char	*line;
	int		i;

	i = 1;
	line = (char *)ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	temp = NULL;
	while (i < ac)
	{
		if (temp)
			line = temp;
		temp = ft_strjoin(line, av[i++]);
		if (temp)
		{
			free(line);
			line = temp;
		}
		temp = ft_strjoin(temp, " ");
		free(line);
	}
	data = ft_split(temp, ' ');
	return (free(temp), data);
}
