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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int main(int ac, char **av)
{
	t_content	c_data;
	t_map	m_data;

	fdf_file_check(av[1], ac, &m_data);
	c_data.mlx = mlx_init();
	c_data.win = mlx_new_window (c_data.mlx, 500, 500, "fdf");
	
	m_data.color = create_trgb(255, 255, 255, 255);
	mlx_pixel_put (c_data.mlx, c_data.win, 0, 0, m_data.color);
	
	mlx_key_hook(c_data.win, key_hook, &c_data);
	mlx_hook(c_data.win, 17, 0, x_hook, &c_data);
	
	mlx_loop(c_data.mlx);
	return (0);
}
