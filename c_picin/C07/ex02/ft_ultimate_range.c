/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:32:32 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/28 03:01:37 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;
	int	*k;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	i = max - min;
	j = 0;
	k = (int *)malloc(sizeof(int) * i);
	if (range == 0)
		return (0);
	while (j < i)
	{
		k[j] = min + j;
		j++;
	}
	*range = k;
	return (i);
}
