/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/11 04:03:56 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

// void	fd_free(int **fd)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (j != 2)
// 	{
// 		if (fd[j][i] != -1)
// 			close(fd[j][i]);
// 		i++;
// 		if (i == 2)
// 		{
// 			i = 0;
// 			j++;
// 		}
// 	}
// 	while (--j < 0)
// 	{
// 		free(fd[j][0]);
// 		free(fd[j][1]);
// 	}
// 	free(fd);
// }
int	**fd_init(void)
{
	int	**fd;

	fd = (int **)malloc(sizeof(int *) * 2);
	if(!fd)
		return (NULL);
	fd[0] = (int *)malloc(sizeof(int ) * 2);
	if(!fd[0])
		return (NULL);
	fd[1] = (int *)malloc(sizeof(int ) * 2);
	if(!fd[1])
		return (NULL);
	fd[0][0] = -1;
	fd[0][1] = -1;
	fd[1][0] = -1;
	fd[1][1] = -1;
	return (fd);
}
void pipe_dup(int **fd, int i, int is_last)
{
	int curr;
	int prev;
	int j;

	j = 0;
	curr = i % 2;
	prev = (i + 1) % 2;
	if (i == 0)
		dup2(fd[curr][1], 1);
	else if (is_last == i)
		dup2(fd[prev][0], 0);
	else  // 중간 명령
	{
		dup2(fd[prev][0], 0);       // STDIN ← 이전 파이프 read
		dup2(fd[curr][1], 1);       // STDOUT → 현재 파이프 write
	}
	while (j < 2)
	{
		if (fd[j][0] != -1) close(fd[j][0]);
		if (fd[j][1] != -1) close(fd[j][1]);
		fd[j][0] = fd[j][1] = -1;
		j++;
	}
}
void pipe_open_close(int **fd, int i)
{
	int curr = i % 2;

	// 이전 파이프 close
	if (fd[curr][0] != -1) close(fd[curr][0]);
	if (fd[curr][1] != -1) close(fd[curr][1]);

	// 새 파이프 생성
	pipe(fd[curr]);
}
