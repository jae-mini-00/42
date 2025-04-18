/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/18 18:22:35 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

void	io_dup(t_token *start, int std_in, int std_out)
{
	int	fd;

	while (start && start->type != PIPE)
	{
		if (start->type == REDIRECTION)
		{
			if (ft_strncmp(start->value, ">", 2) == 0)
				dup_capsule(fd, std_out, 1, start);
			else if (ft_strncmp(start->value, "<", 2) == 0)
			{
				if (start->next->fd == -1)
					fd = open(start->next->value, O_RDONLY, 0644);
				else
				{
					fd = start->next->fd;
					start->next->fd = -1;
				}
				dup_capsule(fd, std_in, -1, start);
			}
			else if (ft_strncmp(start->value, ">>", 3) == 0)
				dup_capsule(fd, std_out, 2, start);
		}
		start = start->next;
	}
}

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
			io_dup (minishell->token, 0, 1);
			split_free(cmd);
			exit_free(minishell, -1);
		}
		ft_execve(minishell, cmd, minishell->token);
	}
}

static void	multi_fork_run(int **fd, int i, t_token *start, t_data *minishell)
{
	char	**cmd;

	pipe_dup(fd, i);
	token_fd_close(start, 2);
	cmd = make_execve_cmd(start);
	if (!cmd[0])
	{
		io_dup (start, 0, 1);
		split_free(cmd);
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
	start = minishell->token;
	while (start)
	{
		pipe_open_close(fd, i, cmd_size);
		minishell->pid = fork();
		if (minishell->pid == 0)
			multi_fork_run(fd, i, start, minishell);
		token_fd_close(start, 0);
		start = find_start(start);
		i++;
	}
	all_fd_close(fd);
}
