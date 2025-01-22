/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:38:01 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/16 15:38:03 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	x_hook(t_content *c_data)
{
	if (c_data->img)
		mlx_destroy_image(c_data->mlx, c_data->img);
	mlx_destroy_window(c_data->mlx, c_data->win);
	mlx_destroy_display(c_data->mlx);
	free(c_data->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_content *c_data)
{
	//printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		x_hook (c_data);
	else if (keycode == KEY_PLUS)
		fdf_plus (c_data);
	else if (keycode == KEY_MINUS)
		fdf_minus (c_data);
	else if (keycode == KEY_LEFT)
		fdf_left (c_data);
	else if (keycode == KEY_RIGHT)
		fdf_right (c_data);
	else if (keycode == KEY_UP)
		fdf_up (c_data);
	else if (keycode == KEY_DOWN)
		fdf_down (c_data);
	return (0);
}
