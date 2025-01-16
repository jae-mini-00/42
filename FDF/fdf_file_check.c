/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:20:49 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/16 19:20:51 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_data_check(char *data)
{
	int	i;

	i = 0;
	while (data[i] && data[i] >= '0' && data[i] <= '9')
		i++;
	if (!data[i])
		return ;
	//ft_perror("Data is not number", 22);
}

static int	width_len(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
			map_data_check(data[i]);
		i++;
	}
	ft_split_free(data);
	return (i);
}

static void	ft_map_size(int fd, t_map *m_data)
{
	int		width;
	//int		height;
	char	*str;
	char	**data;

	str = get_next_line(fd);
	if (!str)
		ft_perror("gnl get NULL", 9);
	//height = 1;
	data = ft_split(str, ' ');
	if (!data)
		ft_perror("split error", 128);
	free(str);
	width = width_len(data);
	m_data->map_width = width;
	while (width)
	{
		str = get_next_line(fd);
		if (!str)
			return ;
		data = ft_split(str, ' ');
		width = width_len(data);
		if (m_data->map_width != width)
			ft_perror("map data error", 8);
	}
}

static void  fdf_file_data_check(char *file, t_map *m_data)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror("file open error", 2);
	ft_map_size(fd, m_data);
	close(fd);
}

void	fdf_file_check(char *file, int ac, t_map *m_data)
{
	char	**file_name;
	int		i;

	i = 0;
	if (ac != 2)
		ft_perror ("Invalid number of arguments", 22);
	file_name = ft_split(file, '.');
	if (!file_name)
		ft_perror("split error", 128);
	while (file_name[i])
		i++;
	if (ft_strncmp(file_name[i - 1], "fdf", 4) == 0)
	{
		ft_split_free(file_name);
		fdf_file_data_check(file, m_data);
		return ;
	}
	ft_split_free(file_name);
	ft_perror("Not .fdf", 9);
}
