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

void	make_line(t_pos *data, float d_x, float d_y, float step, t_content *c_data)
{
	float	xinc;
	float	yinc;
	float	x;
	float	y;
	int		i;

	i = 0;
	xinc = d_x / step;
    yinc = d_y / step;
	x = data->x;
	y = data->y;
	while ((float)i <= step)
	{
		if (x > 0 && x <= 1920 && y > 0 && y <= 1080)
			my_mlx_pixel_put(c_data, x, y, c_data->color);
		x = x + xinc;
		y = y + yinc;
		i++;
	}
}

void	make_image_line(t_pos *data, t_pos *next_data, t_content *c_data)
{
	float	d_x;
	float	d_y;
	float	step;
	float abs_dx;
    float abs_dy;

	d_x = next_data->x - data->x;
	d_y = next_data->y - data->y;
	abs_dx = d_x < 0 ? -d_x : d_x;
	abs_dy = d_y < 0 ? -d_y : d_y;
	if (abs_dx > abs_dy)
		step = abs_dx;
	else
		step = abs_dy;
	make_line(data, d_x, d_y, step, c_data);
}
