/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:42:51 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/28 02:21:59 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*temp;

	if (min >= max)
		return (0);
	i = max - min;
	j = 0;
	temp = (int *)malloc(sizeof(int) * i);
	if (temp == 0)
		return (0);
	while (j < i)
	{
		temp[j] = min + j;
		j++;
	}
	return (temp);
}
