/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/18 02:05:36 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static void	ft_execve(t_data *minishell, char **cmd, t_token *start)
{
	signal(SIGINT, SIG_DFL);
	io_dup (start, 0, 1);
	execve(cmd[0], cmd, minishell->env);
	printf ("%s: command not found\n", cmd[0]);
	split_free(cmd);
	exit_free(minishell, 127);
}

void	solo_fork(t_data *minishell)
{
	char	**cmd;

	cmd = NULL;
	minishell->pid = fork();
	if (minishell->pid == 0)
	{
		cmd = make_execve_cmd(minishell->token);
		if (!cmd[0])
		{
			split_free(cmd);
			exit_free(minishell, -1);
		}
		ft_execve(minishell, cmd, minishell->token);
	}
}

void	multi_fork(t_data *minishell, int cmd_size, int i)
{
	t_token	*temp;
	char	**cmd;
	int		**fd;

	fd = fd_init();
	temp = minishell->token;
	while (temp)
	{
		pipe_open_close(fd, i, cmd_size);
		minishell->pid = fork();
		if (minishell->pid == 0)
		{
			pipe_dup(fd, i);
			token_fd_close(temp, 2);
			cmd = make_execve_cmd(temp);
			if (!cmd[0])
				split_free(cmd);
			else
				ft_execve(minishell, cmd, temp);
			exit_free(minishell, -1);
		}
		token_fd_close(temp, 0);
		temp = find_start(temp);
		i++;
	}
	all_fd_close(fd);
}
