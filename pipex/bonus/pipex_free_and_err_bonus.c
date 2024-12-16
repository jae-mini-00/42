/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free_and_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:28:21 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/13 18:28:22 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_perror(char *err, int num)
{
	errno = num;
	perror(err);
	exit(num);
}

void	ft_split_free(char **split_data)
{
	int	i;

	i = 0;
	while (split_data[i])
	{
		free(split_data[i]);
		i++;
	}
	free(split_data);
}

void	ft_fd_free(int **fd, int fd_size)
{
	int	i;

	i = 0;
	while (i < fd_size - 1)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	pipex_all_free(t_bonusdata *data)
{
	t_cmdlist	*temp;
	t_cmdlist	*now;

	now = data->cmd;
	ft_split_free(data->path_split);
	ft_fd_free(data->fd, data->cmd_size);
	while (now)
	{
		temp = now->next;
		ft_split_free(now->av);
		free(now);
		now = temp;
	}
}
