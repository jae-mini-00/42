/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:16:39 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/17 23:16:41 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pos_color(char *hex)
{
	int	color;
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	color = 0;
	while (*hex && hex[i] == '0' && hex[i + 1] == 'x')
		i += 2;
	if (!hex[i + 1])
		return (0);
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			temp = hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			temp = hex[i] - 'A' + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			temp = hex[i] - 'a' + 10;
		else
			return (0);
		color = color * 16 + temp;
		i++;
	}
	return (color);
}

t_pos	*pos_create(int i, int j, char *data)
{
	t_pos	*new;
	char	*color;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
		return (0);
	new->x = i;
	new->y = j;
	new->z = ft_atoi(data);
	color = ft_strchr(data, ',');
	if (color)
		new->color = pos_color(color + 1);
	else
		new->color = 0;
	new->new = NULL;
	new->next = NULL;
	return (new);
}

void	pos_add_back(t_pos *data, t_pos *back)
{
	t_pos	*now;

	now = data;
	while (now->next)
		now = now->next;
	now->next = back;
}

t_pos	*fdf_pos_init(t_pos *data, int fd, int x, int y)
{
	char	*str;
	char	**s_data;

	str = get_next_line(fd);
	s_data = ft_split(str, ' ');
	data = pos_create(0, 0, s_data[0]);
	while (1)
	{
		while (s_data[x])
		{
			data->new = pos_create(x, y, s_data[x]);
			pos_add_back(data, data->new);
			x++;
		}
		ft_split_free(s_data);
		free(str);
		x = 0;
		y++;
		str = get_next_line(fd);
		if (!str)
			break ;
		s_data = ft_split(str, ' ');
	}
	return (data);
}
