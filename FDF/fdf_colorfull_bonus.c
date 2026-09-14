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

void	fdf_init_colorfull(t_content *c_data, t_map *m_data, char *file, int i)
{
	int	fd;
	int	x;
	int	y;

	x = 1;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_perror("open err", errno);
	if (i == 0)
		c_data->color = create_trgb(255, 255, 255, 255);
	c_data->img = mlx_new_image(c_data->mlx, 1920, 1080);
	c_data->img_addr = mlx_get_data_addr(c_data->img, &c_data->bpp, \
											&c_data->width, &c_data->endian);
	m_data->p_data = fdf_pos_init(m_data->p_data, fd, x, y);
	close (fd);
}

void	fdf_colorfull_make(t_content *c_data, t_map *m_data)
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

void	fdf_colorfull(t_content *c_data)
{
	static int	i = 0;

	i += 1;
	if (i == 8)
		i = 0;
	if (i == 1)
		c_data->color = create_trgb(255, 255, 0, 0);
	else if (i == 2)
		c_data->color = create_trgb(255, 255, 165, 0);
	else if (i == 3)
		c_data->color = create_trgb(255, 255, 255, 0);
	else if (i == 4)
		c_data->color = create_trgb(255, 0, 255, 0);
	else if (i == 5)
		c_data->color = create_trgb(255, 0, 0, 255);
	else if (i == 6)
		c_data->color = create_trgb(255, 0, 0, 128);
	else if (i == 7)
		c_data->color = create_trgb(255, 238, 130, 238);
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_colorfull (c_data, &c_data->m_data, c_data->file, i);
	fdf_colorfull_make (c_data, &c_data->m_data);
	pos_free(c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}
