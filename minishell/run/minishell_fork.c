/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/11 04:15:04 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

void	solo_fork(t_data *minishell)
{
	char **cmd;

	cmd = make_execve_cmd(minishell->token);
	minishell->pid = fork();
	if (minishell->pid == 0)
	{
		printf("solo\n");
		io_dup (minishell->token, 0, 1);
		execve(cmd[0], cmd, minishell->env);
		printf ("%s: command not found\n", cmd[0]);
		split_free(cmd);
		exit_free(minishell, errno);
	}
}

void fd_close(int **fd)
{
	if (fd[0][0] != -1)
		close (fd[0][0]);
	if (fd[0][1] != -1)
		close (fd[0][1]);
	if (fd[1][0] != -1)
		close (fd[1][0]);
	if (fd[1][1] != -1)
		close (fd[1][1]);
	free(fd[0]);
	free(fd[1]);
	free(fd);
}
void	multi_fork(t_data *minishell, int cmd_size, int i)
{
	t_token *temp;
	char **cmd;
	int **fd;

	fd = fd_init();
	temp = minishell->token;
	while (temp)
	{
		minishell->pid = fork();
		pipe_open_close(fd, i);
		if (minishell->pid == 0)
		{
			cmd = make_execve_cmd(temp);
			pipe_dup(fd, i, cmd_size - 2);
			io_dup (temp, 0, 1);
			execve(cmd[0], cmd, minishell->env);
			printf ("%s: command not found\n", cmd[0]);
			split_free(cmd);
			fd_close(fd);
			exit_free(minishell, errno);
		}
		temp = find_start(temp);
		i++;
	}
	fd_close(fd);
}
