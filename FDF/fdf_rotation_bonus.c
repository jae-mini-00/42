/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_different_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:42:15 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/22 23:42:17 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init_rotation(t_content *c_data, t_map *m_data, char *file)
{
	int	fd;
	int	x;
	int	y;

	x = 1;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_perror("open err", errno);
	if (c_data->color == -1)
		c_data->color = create_trgb(255, 255, 255, 255);
	c_data->img = mlx_new_image(c_data->mlx, 1920, 1080);
	c_data->img_addr = mlx_get_data_addr(c_data->img, &c_data->bpp, \
											&c_data->width, &c_data->endian);
	m_data->p_data = fdf_pos_init(m_data->p_data, fd, x, y);
	close (fd);
}

void	fdf_rotation_make(t_content *c_data, t_map *m_data, float s, float c)
{
	t_pos	*now;
	float	x;
	float	y;

	now = m_data->p_data;
	while (now)
	{
		x = now->x - m_data->map_width / 2;
		y = now->y - m_data->map_height / 2;
		now->x = (x * c) - (y * s);
		now->y = (x * s) + (y * c);
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

void	fdf_rotation(t_content *c_data)
{
	static double	angle = 0;
	double			radian;
	double			a_sin;
	double			a_cos;

	angle += 10;
	if (angle >= 370)
		angle = 0;
	radian = angle * M_PI / 180.0;
	a_sin = sin(radian);
	a_cos = cos(radian);
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_rotation (c_data, &c_data->m_data, c_data->file);
	fdf_rotation_make (c_data, &c_data->m_data, (float)a_sin, (float)a_cos);
	pos_free(c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}
