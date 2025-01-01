/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 21:48:30 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/27 17:41:48 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	len(char *a)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	temp = a;
	while (a[i] != '\0')
	{
		j = i + 1;
		while (temp[j] != '\0')
		{
			if (temp[j] == a[i])
				return (0);
			j++;
		}
		if (a[i] == '+' || a[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b_len;
	long	nb;

	nb = nbr;
	b_len = len(base);
	if (b_len == 0)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= b_len)
		ft_putnbr_base(nb / b_len, base);
	write(1, &base[nb % b_len], 1);
}
