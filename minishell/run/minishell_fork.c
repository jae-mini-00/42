/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/13 22:48:02 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

void	solo_fork(t_data *minishell)
{
	char **cmd;

	minishell->pid = fork();
	if (minishell->pid == 0)
	{
		cmd = make_execve_cmd(minishell->token);
		io_dup (minishell->token, 0, 1);
		execve(cmd[0], cmd, minishell->env);
		printf ("%s: command not found\n", cmd[0]);
		split_free(cmd);
		exit_free(minishell, errno);
	}
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
		pipe_open_close(fd, i, cmd_size);
		minishell->pid = fork();
		if (minishell->pid == 0)
		{
			cmd = make_execve_cmd(temp);
			pipe_dup(fd, i);
			io_dup (temp, 0, 1);
			execve(cmd[0], cmd, minishell->env);
			printf ("%s: command not found\n", cmd[0]);
			split_free(cmd);
			exit_free(minishell, errno);
		}
		temp = find_start(temp);
		i++;
	}
	all_fd_close(fd);
}
