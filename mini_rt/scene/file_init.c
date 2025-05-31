/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:01:39 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/31 15:59:38 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

static t_bool	file_name_check(char *file)
{
	int	i;
	int	fd;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	i = ft_strlen(file);
	if (!file[i--] && i > 3)
		if (file[i--] == 't')
			if (file[i--] == 'r')
				if (file[i--] == '.')
				{
					if (file_data_check(fd))
					{
						printf("성공\n");
						return (TRUE);
					}
					else
					{
						write(2, "Error :file data err\n", 22);
						return (FALSE);
					}
				}
	close(fd);
	write(2, "Error :Invalid file extension: expected .rt.\n", 46);
	return (FALSE);
}

void	file_init(t_scene *scene, int ac, char *file)
{
	int	fd;

	(void)scene;
	(void)fd;
	if (ac == 2)
	{
		if (file_name_check(file))
    	{
			return ;
			// fd = open(file, O_RDONLY);
			// scene = scene_init(fd);
	    }
		return ;
	}
	write(2, "Error :2 arguments required.\n", 30);
}