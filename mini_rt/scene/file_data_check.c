/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_data_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:29:19 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/30 23:14:26 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

static t_bool	object_data_check(char **data)
{
	// sp, cy, pl 인지 확인 하고 아니면 false 반환 맞으면 백터값 및  r g b 값 확인
	split_free(data);
	return (TRUE);
}

static t_bool	utils_data_check(char **data)
{
	// C, L, A 인지 확인 하고 아니면 false 반환 맞으면 백터값 및  r g b 값 확인
	split_free(data);
	return (TRUE);	
}

char	**minirt_data(int fd)
{
	char	*temp;
	char	*one_line;
	char	*all_line;
	char	**data;

	temp = NULL;
	one_line = get_next_line(fd);
	all_line = ft_strjoin(one_line, "\0");
	while (one_line)
	{
		free(one_line);
		one_line = get_next_line(fd);
		if (!one_line)
			break ;
		temp = all_line;
		all_line = ft_strjoin(all_line, one_line);
		free(temp);
	}
	data = ft_split(all_line, '\n');
	free(all_line);
	return (data);
}

t_bool	file_data_check(int fd)
{
	int		i;
	char	**file_data;
	char	**object_data;
	
	i = -1;
	object_data = NULL;
	file_data = minirt_data(fd);
	while (file_data[++i])
	{
		object_data = ft_split(file_data[i], ' ');
		if (!object_data)
			continue ;
		else if (object_data_check(object_data))
			continue ;
		else if (utils_data_check(object_data))
			continue ;
		else
		{
			split_free(file_data);
			split_free(object_data);
			return (FALSE);
		}
	}
	split_free(file_data);
	return (TRUE);
}
