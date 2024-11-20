/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 04:20:40 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/29 21:27:39 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	total(int size, char **strs, char *sep)
{
	int	strs_len;
	int	sep_len;
	int	i;

	i = 0;
	strs_len = 0;
	sep_len = len(sep);
	if (size == 1)
		return (len(strs[0]) + 1);
	while (i + 1 < size)
	{
		strs_len += len(strs[i]);
		strs_len += sep_len;
		i++;
	}
	strs_len += len(strs[i]);
	return (strs_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = len(dest);
	while (src[i] != 0)
	{
		dest[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		t_len;
	int		i;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof (char) * 1);
		str[0] = 0;
		return (str);
	}
	t_len = total(size, strs, sep);
	str = (char *)malloc(sizeof (char) * t_len + 1);
	*str = '\0';
	i = 0;
	while (i + 1 < size)
	{
		str = ft_strcat(str, *(strs + i));
		str = ft_strcat(str, sep);
		i++;
	}
	str = ft_strcat(str, *(strs + i));
	return (str);
}
