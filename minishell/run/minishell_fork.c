/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/25 19:54:44 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

int	io_dup(t_token *start, int std_in, int std_out, int status)
{
	while (start && !status && start->type != PIPE)
	{
		if (start->type == REDIRECTION)
		{
			if (ft_strncmp(start->value, ">", 2) == 0)
				dup_capsule(std_out, 1, start, &status);
			else if (ft_strncmp(start->value, "<", 2) == 0)
			{
				if (start->next->fd == -1)
					dup_capsule(std_in, 3, start, &status);
				else
				{
					dup_capsule(std_in, -1, start, &status);
					start->next->fd = -1;
				}
			}
			else if (ft_strncmp(start->value, ">>", 3) == 0)
				dup_capsule(std_out, 2, start, &status);
		}
		start = start->next;
	}
	return (status);
}

static void	ft_execve(t_data *minishell, char **cmd, t_token *start)
{
	int	status;

	status = 0;
	status = io_dup (start, 0, 1, status);
	if (!status)
	{
		execve(cmd[0], cmd, minishell->env);
		write (2, cmd[0], ft_strlen(cmd[0]));
		write (2, ": command not found\n", 21);
		split_free(cmd);
		ft_pid_free(minishell, NULL, 0);
		exit_free(minishell, 127);
	}
	else
	{
		split_free(cmd);
		ft_pid_free(minishell, NULL, 0);
		exit_free(minishell, 1);
	}
}

void	solo_fork(t_data *minishell)
{
	char	**cmd;

	cmd = NULL;
	child_start();
	ft_malloc_pid(minishell, 1);
	minishell->pid[0] = fork();
	if (minishell->pid[0] == 0)
	{
		cmd = make_execve_cmd(minishell->token);
		if (!cmd[0])
		{
			io_dup (minishell->token, 0, 1, 0);
			split_free(cmd);
			ft_pid_free(minishell, NULL, 0);
			exit_free(minishell, 127);
		}
		ft_execve(minishell, cmd, minishell->token);
	}
	signal (SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

static void	multi_fork_run(int **fd, int i, t_token *start, t_data *minishell)
{
	char	**cmd;

	pipe_dup(fd, i);
	token_fd_close(start, 2);
	cmd = make_execve_cmd(start);
	if (!cmd[0])
	{
		io_dup (start, 0, 1, 0);
		ft_pid_free(minishell, NULL, 0);
		split_free(cmd);
	}
	else if (pipe_builtin_check(cmd[0]))
	{
		pipe_builtin_run(minishell, cmd, start);
		ft_pid_free(minishell, NULL, 0);
		split_free(cmd);
		exit_free(minishell, minishell->exit_code);
	}
	else
		ft_execve(minishell, cmd, start);
	exit_free(minishell, -1);
}

void	multi_fork(t_data *minishell, int cmd_size, int i)
{
	t_token	*start;
	int		**fd;

	fd = fd_init();
	child_start();
	ft_malloc_pid(minishell, cmd_size);
	start = minishell->token;
	while (start && minishell->pid[i] != -2)
	{
		pipe_open_close(fd, i, cmd_size);
		minishell->pid[i] = fork();
		if (minishell->pid[i] == 0)
			multi_fork_run(fd, i, start, minishell);
		token_fd_close(start, 0);
		start = find_start(start);
		i++;
	}
	all_fd_close(fd);
	signal (SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
