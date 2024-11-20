/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:15:42 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/30 15:56:32 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*c;

	i = 0;
	while (src[i] != '\0')
		i++;
	c = (char *)malloc (sizeof(char) * i + 1);
	if (c == 0)
		return (0);
	i = 0;
	while (src[i])
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*temp;
	int			i;

	if (ac < 0 || av == NULL)
		return (NULL);
	i = 0;
	temp = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (temp == 0)
		return (0);
	while (i < ac)
	{
		temp[i].size = len(av[i]);
		temp[i].str = av[i];
		temp[i].copy = ft_strdup(av[i]);
		i++;
	}
	temp[i].str = 0;
	return (temp);
}
