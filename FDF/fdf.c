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

#include <stdio.h>
#include "fdf.h"

int create_trgb(int t, int r, int g, int b)
{
    return ((t & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

int	x_hook(t_content *c_data)
{
	mlx_destroy_display(c_data->mlx);
	//mlx_destroy_image(c_data->mlx, c_data->win);
	mlx_destroy_window(c_data->mlx, c_data->win);
	free(c_data->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_content *c_data)
{
	if(keycode == key_esc)
		x_hook(c_data);	
	return (0);
}

int mouse_hook(int button, int x, int y, t_content *c_data)
{
    // 마우스 버튼 코드에 따라 다른 행동을 취함
    if (button == 1) { // 왼쪽 버튼 클릭
        printf("왼쪽 버튼 클릭: x = %d, y = %d\n", x, y);
    } else if (button == 2) { // 오른쪽 버튼 클릭
        printf("오른쪽 버튼 클릭: x = %d, y = %d\n", x, y);
    } else if (button == 3) { // 가운데 버튼 클릭
        printf("가운데 버튼 클릭: x = %d, y = %d\n", x, y);
    } else if (button == 4) { // 휠 위로 스크롤
        printf("휠 위로 스크롤: x = %d, y = %d\n", x, y);
    } else if (button == 5) { // 휠 아래로 스크롤
        printf("휠 아래로 스크롤: x = %d, y = %d\n", x, y);
    }
	(void)c_data;
    return (0);
}

int main(int ac, char **av)
{
	t_content	c_data;
	t_map	m_data;

	if (ac != 2)
		return (0);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4))
		return (0);
	c_data.mlx = mlx_init();
	c_data.win = mlx_new_window (c_data.mlx, 500, 500, "fdf");
	
	m_data.color = create_trgb(255, 255, 255, 255);
	mlx_pixel_put (c_data.mlx, c_data.win, 0, 0, m_data.color);
	
	mlx_key_hook(c_data.win, key_hook, &c_data);
	mlx_hook(c_data.win, 17, 0, x_hook, &c_data);
	mlx_mouse_hook(c_data.win, mouse_hook, &c_data);
	
	mlx_loop(c_data.mlx);
	return (0);
}
