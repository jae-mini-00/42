/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:01:39 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/29 19:13:24 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "./scene.h"

static t_bool	file_name_check(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (!file[i--] && i > 3)
		if (file[i--] == 't')
			if (file[i--] == 'r')
				if (file[i--] == '.')
					return (TRUE);
	return (FALSE);
}

t_bool	map_init(t_scene *scene, char *file)
{
	int	fd;

	if (file_name_check(file))
    {
		fd = open(file, O_RDONLY);
		scene = scene_init(fd);
    }
	else
		return (FALSE);
}