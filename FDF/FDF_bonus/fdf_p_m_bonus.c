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

void	fdf_plus(t_content *c_data)
{
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_scale (c_data, &c_data->m_data, c_data->file, \
					c_data->m_data.scale + 1);
	make_image (c_data, &c_data->m_data);
	pos_free (c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}

void	fdf_minus(t_content *c_data)
{
	mlx_destroy_image(c_data->mlx, c_data->img);
	fdf_init_scale (c_data, &c_data->m_data, c_data->file, \
					c_data->m_data.scale - 1);
	make_image (c_data, &c_data->m_data);
	pos_free (c_data->m_data.p_data);
	mlx_put_image_to_window (c_data->mlx, c_data->win, c_data->img, 0, 0);
}
