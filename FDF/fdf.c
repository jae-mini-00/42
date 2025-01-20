/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:27:26 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/14 21:06:07 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void  make_pixel(t_content *c_data, t_map *m_data)
{
	t_pos	*now;
	float	x;
	float	y;


	now = m_data->p_data;
	while(now)
	{
		x = (now->x - now->y) * 0.866;
		y = (now->x + now->y) * 0.5 - now->z;
		//	my_mlx_pixel_put(c_data, 500 + (now->x * m_data->scale), 200 + (now->y * m_data->scale), c_data->color);
			my_mlx_pixel_put(c_data, 800 + x * m_data->scale , 400 + y * m_data->scale, c_data->color);
		now = now->next;
	}
}
//	my_mlx_pixel_put(c_data, 500 + (now->x * m_data->scale), 200 + (now->y * m_data->scale), i);

int	main(int ac, char **av)
{
	t_content	c_data;
	t_map	m_data;

	fdf_file_check(av[1], ac, &m_data);
	fdf_init(&c_data, &m_data, av[1]);
  
	make_pixel(&c_data, &m_data);
	mlx_put_image_to_window(c_data.mlx, c_data.win, c_data.img, 0, 0);
	
	mlx_key_hook(c_data.win, key_hook, &c_data);
	mlx_hook(c_data.win, 17, 0, x_hook, &c_data);
	
	mlx_loop(c_data.mlx);
  
	return (0);
}
