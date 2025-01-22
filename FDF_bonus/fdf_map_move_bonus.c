/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p_m_bounus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:31:31 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/22 20:31:34 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_right(t_content *c_data)
{
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_right (c_data, &c_data->m_data, c_data->file, 50);
	make_image (c_data, &c_data->m_data);
	pos_free (c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}

void	fdf_left(t_content *c_data)
{
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_left (c_data, &c_data->m_data, c_data->file, 50);
	make_image (c_data, &c_data->m_data);
	pos_free (c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}

void	fdf_up(t_content *c_data)
{
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_up (c_data, &c_data->m_data, c_data->file, 50);
	make_image (c_data, &c_data->m_data);
	pos_free (c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}

void	fdf_down(t_content *c_data)
{
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_down (c_data, &c_data->m_data, c_data->file, 50);
	make_image (c_data, &c_data->m_data);
	pos_free (c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}
