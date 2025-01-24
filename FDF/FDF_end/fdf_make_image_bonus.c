/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:58:32 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/21 22:58:34 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_pixel(t_content *c_data, t_map *m_data)
{
	t_pos	*now;

	now = m_data->p_data;
	while (now)
	{
		if (now->x > 0 && now->x < 1920 && now->y > 0 && now->y < 1080)
			my_mlx_pixel_put(c_data, now->x, now->y, c_data->color);
		now = now->next;
	}
}

void	make_width_line(t_content *c_data, t_map *m_data)
{
	t_pos	*now;
	int		i;
	int		j;

	i = 0;
	j = 0;
	now = m_data->p_data;
	while (j++ < m_data->map_height)
	{
		while (i < m_data->map_width - 1)
		{
			make_image_line(now, now->next, c_data);
			now = now->next;
			i++;
		}
		now = now->next;
		i = 0;
	}
}

void	make_height_line(t_content *c_data, t_map *m_data)
{
	t_pos	*now;
	int		i;
	int		j;

	i = 0;
	j = 0;
	now = m_data->p_data;
	while (j++ < m_data->map_height - 1)
	{
		while (i < m_data->map_width)
		{
			now->new = next_height_pos(now, m_data->map_width);
			make_image_line(now, now->new, c_data);
			now = now->next;
			i++;
		}
		i = 0;
	}
}

void	make_image(t_content *c_data, t_map *m_data)
{
	t_pos	*now;
	float	x;
	float	y;

	now = m_data->p_data;
	while (now)
	{
		now->x = now->x - m_data->map_width / 2;
		now->y = now->y - m_data->map_height / 2;
		x = ((now->x - now->y) * 0.866) * m_data->scale + m_data->x_offset;
		y = ((now->x + now->y) * 0.5 - now->z) * m_data->scale;
		y += m_data->y_offset;
		now->x = x;
		now->y = y;
		now = now->next;
	}
	make_pixel(c_data, m_data);
	make_width_line(c_data, m_data);
	make_height_line(c_data, m_data);
}
