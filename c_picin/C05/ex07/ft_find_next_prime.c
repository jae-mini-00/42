/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:32:37 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/25 20:02:01 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	next(int i, int a)
{
	while (i != a)
	{
		if (i % a == 0)
		{
			i++;
			a = 2;
		}
		a++;
	}
	return (i);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	a;

	i = 2;
	a = 2;
	if (nb < 2)
		return (2);
	while (nb != i)
	{
		if (nb % i == 0)
		{
			i = nb + 1;
			return (next(i, a));
		}
		i++;
	}
	return (i);
}
