/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:43:47 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/27 22:14:16 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	len(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] <= 32 || base[i] == 127 \
				|| base[i] == 43 || base[i] == 45)
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	check(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_check(char *str, int *s_i)
{
	int	flag;
	int	i;

	i = 0;
	flag = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	*s_i = i;
	return (flag);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b_len;
	int	i;
	int	nb;
	int	nb2;
	int	s_check;

	i = 0;
	nb = 0;
	b_len = len(base);
	if (b_len >= 2)
	{
		s_check = ft_atoi_check(str, &i);
		nb2 = check(str[i], base);
		while (nb2 != -1)
		{
			nb = (nb * b_len) + nb2;
			i++;
			nb2 = check(str[i], base);
		}
		return (nb * s_check);
	}
	return (0);
}
