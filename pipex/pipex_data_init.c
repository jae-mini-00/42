/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_data_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:42:58 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/10 18:43:00 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_full_path(char **data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data[i])
	{
		temp = data[i];
		data[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
	return (data);
}

char	**ft_path_split(char **envp)
{
	int		i;
	char	*path;
	char	**path_split;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			path_split = ft_split(path, ':');
		}
		i++;
	}
	free(path);
	path_split = ft_full_path(path_split);
	return (path_split);
}

void	pipexdata_init(t_pipexdata *data, int ac, char **av, char **envp)
{
	data->in_file = open(av[1], O_RDONLY);
	if (data->in_file == -1)
		ft_perror("file_open_err", errno);
	data->out_file = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->out_file == -1)
		ft_perror("file_open_err", errno);
	data->path_split = ft_path_split(envp);
	data->cmd = cmd_init(data->cmd, ac, av, data->path_split);
}
