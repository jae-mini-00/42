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

int main(int ac, char **av)
{
	//int	fd;
	//char	*str;

	if (ac != 2)
		return (0);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4))
		return (0);
	/*fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0)*/
	void *mlx = mlx_init();
	void *win = mlx_new_window (mlx, 1000, 1000, "fdf");
	mlx_loop(mlx);
	(void)win;
}
