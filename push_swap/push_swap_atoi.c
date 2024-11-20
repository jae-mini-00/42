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

void	stack_add(t_stack *a, t_stack *b, char **av)
{
	int	i;

	i = 0;
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
	if ((temp > 2147483647 || temp < -2147483648 || av[i] != '\0') && \
		av[i] != ' ')
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	return ((int)temp * flag);
}

char	**make_data(char **av, int ac)
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
