/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:10:21 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/21 18:10:23 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_line(t_pos *data, t_content *c_data)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	c_data->xinc = c_data->d_x / c_data->step;
	c_data->yinc = c_data->d_y / c_data->step;
	x = data->x;
	y = data->y;
	while ((float)i <= c_data->step)
	{
		if (x > 0 && x <= 1920 && y > 0 && y <= 1080)
			my_mlx_pixel_put(c_data, x, y, c_data->color);
		x = x + c_data->xinc;
		y = y + c_data->yinc;
		i++;
	}
}

void	make_image_line(t_pos *data, t_pos *next_data, t_content *c_data)
{
	c_data->d_x = next_data->x - data->x;
	c_data->d_y = next_data->y - data->y;
	if (c_data->d_x < 0)
		c_data->abs_dx = c_data->d_x * -1;
	else
		c_data->abs_dx = c_data->d_x;
	if (c_data->d_y < 0)
		c_data->abs_dy = c_data->d_y * -1;
	else
		c_data->abs_dy = c_data->d_y;
	if (c_data->abs_dx > c_data->abs_dy)
		c_data->step = c_data->abs_dx;
	else
		c_data->step = c_data->abs_dy;
	make_line(data, c_data);
}
