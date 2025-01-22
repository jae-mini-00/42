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

void	fdf_init_left(t_content *c_data, t_map *m_data, char *file, int scale)
{
	int	fd;
	int	x;
	int	y;

	x = 1;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_perror("open err", errno);
	c_data->color = create_trgb(255, 255, 255, 255);
	c_data->img = mlx_new_image(c_data->mlx, 1920, 1080);
	c_data->img_addr = mlx_get_data_addr(c_data->img, &c_data->bpp, \
											&c_data->width, &c_data->endian);
	if (m_data->x_offset > scale)
		m_data->x_offset -= scale;
	else
		m_data->x_offset = 800;
	m_data->y_offset = 400;
	m_data->scale = m_data->scale;
	m_data->p_data = fdf_pos_init(m_data->p_data, fd, x, y);
	close (fd);
}

void	fdf_init_right(t_content *c_data, t_map *m_data, char *file, int scale)
{
	int	fd;
	int	x;
	int	y;

	x = 1;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_perror("open err", errno);
	c_data->color = create_trgb(255, 255, 255, 255);
	c_data->img = mlx_new_image(c_data->mlx, 1920, 1080);
	c_data->img_addr = mlx_get_data_addr(c_data->img, &c_data->bpp, \
											&c_data->width, &c_data->endian);
	if (m_data->x_offset + scale < 1920)
		m_data->x_offset += scale;
	else
		m_data->x_offset = 800;
	m_data->y_offset = 400;
	m_data->scale = m_data->scale;
	m_data->p_data = fdf_pos_init(m_data->p_data, fd, x, y);
	close (fd);
}

void	fdf_init_up(t_content *c_data, t_map *m_data, char *file, int scale)
{
	int	fd;
	int	x;
	int	y;

	x = 1;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_perror("open err", errno);
	c_data->color = create_trgb(255, 255, 255, 255);
	c_data->img = mlx_new_image(c_data->mlx, 1920, 1080);
	c_data->img_addr = mlx_get_data_addr(c_data->img, &c_data->bpp, \
											&c_data->width, &c_data->endian);
	if (m_data->y_offset > scale)
		m_data->y_offset -= scale;
	else
		m_data->y_offset = 400;
	m_data->x_offset = 800;
	m_data->scale = m_data->scale;
	m_data->p_data = fdf_pos_init(m_data->p_data, fd, x, y);
	close (fd);
}

void	fdf_init_down(t_content *c_data, t_map *m_data, char *file, int scale)
{
	int	fd;
	int	x;
	int	y;

	x = 1;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		ft_perror("open err", errno);
	c_data->color = create_trgb(255, 255, 255, 255);
	c_data->img = mlx_new_image(c_data->mlx, 1920, 1080);
	c_data->img_addr = mlx_get_data_addr(c_data->img, &c_data->bpp, \
											&c_data->width, &c_data->endian);
	if (m_data->y_offset + scale < 1080)
		m_data->y_offset += scale;
	else
		m_data->y_offset = 400;
	m_data->x_offset = 800;
	m_data->scale = m_data->scale;
	m_data->p_data = fdf_pos_init(m_data->p_data, fd, x, y);
	close (fd);
}
