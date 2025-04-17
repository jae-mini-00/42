/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/17 23:51:05 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static void	fd_close(int *fd)
{
	if (fd && fd[0] != -1)
	{
		close(fd[0]);
		fd[0] = -1;
	}
}

void	all_fd_close(int **fd)
{
	if (fd)
	{
		if (fd[0][0] != -1)
			close (fd[0][0]);
		if (fd[0][1] != -1)
			close (fd[0][1]);
		if (fd[1][0] != -1)
			close (fd[1][0]);
		if (fd[1][1] != -1)
			close (fd[1][1]);
		free(fd[1]);
		free(fd[0]);
		free(fd);
	}
}

int	**fd_init(void)
{
	int	**fd;

	fd = (int **)malloc(sizeof(int *) * 2);
	if (!fd)
		return (NULL);
	fd[0] = (int *)malloc(sizeof(int ) * 2);
	if (!fd[0])
		return (NULL);
	fd[1] = (int *)malloc(sizeof(int ) * 2);
	if (!fd[1])
		return (NULL);
	fd[0][0] = -1;
	fd[0][1] = -1;
	fd[1][0] = -1;
	fd[1][1] = -1;
	return (fd);
}

void	pipe_dup(int **fd, int i)
{
	if (i != 0)
	{
		if (fd[0][1] == -1)
		{
			if (fd[0][0] != -1)
				dup2(fd[0][0], 0);
			if (fd[1][1] != -1)
				dup2(fd[1][1], 1);
		}
		else if (fd[1][1] == -1)
		{
			if (fd[1][0] != -1)
				dup2(fd[1][0], 0);
			if (fd[0][1] != -1)
				dup2(fd[0][1], 1);
		}
	}
	else
		dup2(fd[0][1], 1);
	all_fd_close(fd);
}

void	pipe_open_close(int **fd, int i, int cmd_size)
{
	int	curr;

	curr = i % 2;
	if (i != 0)
	{
		if (curr == 1) //전 파이프가 0배열에 있음 -> [0][0]은 살리고 [0][1] close 
		{
			fd_close(&fd[1][0]);
			fd_close(&fd[0][1]);
		}
		else // 전 파이프가 1배열에 있음 -> [1][0]은 살리고 [1][1] close
		{
			fd_close(&fd[0][0]);
			fd_close(&fd[1][1]);
		}
	}
	if (cmd_size - 1 != i)
		pipe(fd[curr]);
}
