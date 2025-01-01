/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:11:20 by jaejo             #+#    #+#             */
/*   Updated: 2024/08/30 12:10:56 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *c)
{
	unsigned int	id;

	id = 0;
	while (c[id] != '\0')
		id++;
	return (id);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = len(dest);
	s_len = len(src);
	i = 0;
	while (src[i] != '\0' && d_len + i + 1 < size)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	if (d_len >= size)
		return (size + s_len);
	else
		return (d_len + s_len);
}
