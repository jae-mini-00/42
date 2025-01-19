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

void	fdf_init(t_content *c_data, t_map *m_data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY)
	if (fd < 1)
		ft_perror("open err", errno);
	c_data->mlx = mlx_init();
	c_data->win = mlx_new_window (c_data->mlx, 1920, 1080, "fdf");
	c_data->color = create_trgb(255, 255, 255, 255);
	c_data->img = mlx_new_image(c_data->mlx, 1920, 1080);
	c_data->img_addr = mlx_get_data_addr(c_data->img, &c_data->bpp, \
											&c_data->width, &c_data->endian);
	m_data->x_offset = 500;
	m_data->y_offset = 200;
	m_data->scale = 50;
	fdf_pos_init(m_data->p_data, fd);
	close (fd);
}