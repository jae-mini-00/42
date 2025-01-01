/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:17:03 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/28 03:11:00 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	cmp(char *ar, char *arg)
{
	int	i;

	i = 0;
	while (ar[i] == arg[i])
	{
		if (ar[i] == '\0')
			return (ar[i] - arg[i]);
		i++;
	}
	return (ar[i] - arg[i]);
}

void	swap(char **str, char **strr)
{
	char	*a;

	a = *str;
	*str = *strr;
	*strr = a;
}

int	main(int argc, char **argv)
{
	int	j;
	int	i;

	j = 1;
	if (argc <= 1)
		return (0);
	while (argv[j + 1])
	{
		if (cmp(argv[j], argv[j + 1]) > 0)
		{
			swap(&argv[j], &argv[j + 1]);
			j = 1;
		}
		else if (cmp(argv[j], argv[j + 1]) <= 0)
			j++;
	}
	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i] != '\0')
			write (1, &argv[j][i++], 1);
		write (1, "\n", 1);
		j++;
	}
}
